#include <stdio.h>

int main() {
  while (1) {
      asm volatile("rdrand %rax");
  }
}
