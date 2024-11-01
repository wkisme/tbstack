#include <stdio.h>
#include <unistd.h>

void func_c() {
    printf("In func_c\n");
    sleep(100);  // Keep the process running, allowing enough time to attach with ptrace
}

void func_b() {
    printf("In func_b\n");
    func_c();
}

void func_a() {
    printf("In func_a\n");
    func_b();
}

int main() {
    printf("Starting target program\n");
    func_a();
    printf("Program completed\n");
    return 0;
}

