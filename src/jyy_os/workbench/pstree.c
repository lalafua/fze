#include <errno.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <ctype.h>
#include <dirent.h>
#include <stdlib.h>

typedef struct proc_info {
    pid_t pid;
    pid_t ppid;
    pid_t tgid;
    char *name;
}proc_info;

#define MAX_PROCS 65535


int is_pid_dir(const char *dirname);
int get_pid_info(proc_info *list[], int max_proc);
int read_status(pid_t pid, pid_t tgid,proc_info *info);

int main(int argc, char *argv[]) {
    static int show_pids = 0;
    static int numeric_sort = 0;
    static int version = 0;
    static proc_info *proc_list[MAX_PROCS] = {NULL};

    for (int i = 0; i < argc; i++) {
        assert(argv[i]);
        if (strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "--show-pids") == 0){
            show_pids = 1;
        }
        else if (strcmp(argv[i], "-n") == 0 || strcmp(argv[i], "--numeric-sort") == 0){
            numeric_sort = 1;
        }
        else if (strcmp(argv[i], "-V") == 0 || strcmp(argv[i], "--version") == 0){
            version = 1;
        }
    }
    assert(!argv[argc]);

    int proc_count = get_pid_info(proc_list, MAX_PROCS);
    for(int i=0; i<proc_count; i++){
        printf("Tgid: %d\tPid: %d \n", proc_list[i]->tgid, proc_list[i]->pid);
    }


    return 0;
}

int is_pid_dir(const char *dirname){
    for(int i = 0; dirname[i] != '\0'; i++){
        if(!isdigit(dirname[i])){
            return 0;
        }
    }
    return 1;
}

int get_pid_info(proc_info *list[], int max_proc){
    const char *path = "/proc";
    DIR *proc_dir = opendir(path);
    if(proc_dir == NULL){
        fprintf(stderr, "failed to open directory %s.", path);
        return -1;
    }

    struct dirent *tgid_entry;
    errno = 0;
    int proc_count = 0;

    while((tgid_entry = readdir(proc_dir)) != NULL && proc_count < max_proc){
        if(tgid_entry->d_type == DT_DIR && is_pid_dir(tgid_entry->d_name)){
            char task_path[256];
            pid_t tgid = atoi(tgid_entry->d_name);
            snprintf(task_path, sizeof(task_path),"/proc/%d/task", tgid);

            DIR *task_dir = opendir(task_path);
            struct dirent *pid_entry;

            while((pid_entry = readdir(task_dir)) != NULL && proc_count < max_proc){
                if(pid_entry->d_type == DT_DIR && is_pid_dir(pid_entry->d_name)){
                    pid_t pid = atoi(pid_entry->d_name);

                    proc_info *new_proc = (proc_info*)malloc(sizeof(proc_info));

                    if(read_status(tgid, pid, new_proc) == 0){
                        list[proc_count] = new_proc;
                        proc_count++;
                    }

                    else{
                        free(new_proc);
                    }
                }
            }
        }
    }

    if(errno != 0 && tgid_entry == NULL){
        fprintf(stderr, "readdir failed.");
        closedir(proc_dir);
        for(int i=0; i<proc_count; i++){
            free(list[i]->name);
            free(list[i]);
            list[i] = NULL;
        }
        return -1;
    }

    closedir(proc_dir);
    return proc_count;
}

int read_status(pid_t tgid, pid_t pid, proc_info *info){
    FILE *fp = NULL;
    char path[256];
    char line[256];

    snprintf(path, sizeof(path),"/proc/%d/task/%d/status", tgid, pid);
    fp = fopen(path, "r");
    if(!fp){
        return -1;
    }

    info->pid = pid;
    info->name = NULL;
    info->ppid = -1;
    info->tgid = -1;

    while(fgets(line, sizeof(line), fp)){
        if(strncmp(line, "Name:", 5) == 0){
            char *name = line+5;
            while(*name && isspace(*name)){
                name++;
            }
            char *newline = strchr(name, '\n');
            if(newline){
                *newline = '\0';
            }
            info->name = strdup(name);
            if(info->name == NULL){
                fclose(fp);
                return -1;
            }
        }
        else if(strncmp(line, "PPid:", 5) == 0){
            sscanf(line, "PPid:\t%d", &info->ppid);
        }
        else if(strncmp(line, "Tgid:", 5) == 0){
            sscanf(line, "Tgid:\t%d", &info->tgid);
        }
    }
    
    fclose(fp);
    return 0;
}

int print_pstree(proc_info *proc_list[], int proc_count, int level, int tgid,int show_pids){
    for(int i=0; i<proc_count; i++){
        if(proc_list[i] != NULL)
    }
}

int freeup(proc_info *proc_list[], int proc_count){

}