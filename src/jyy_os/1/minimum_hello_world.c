#include <sys/syscall.h>

int main () {
  syscall(SYS_exit, 42);
}
