#include <stdio.h>
#include <string.h>

extern char **environ;


void memory_print(void *start_addr, void *end_addr);

int f2(int a, int b) {
    int result = a - b; // Perform subtraction
    // Call the memory_print function to print the stack
    printf("Stacks in f2:\n");
    memory_print(&a, &result);
    return result;
}




int f1(char *str, int multiplier) {
    char local_str[strlen(str) + 1];
    strcpy(local_str, str);
    int f1_result = strlen(str) * multiplier;
    // Call the memory_print function to print the stack
    printf("Stack contents in f1:\n");
    memory_print(&str, &local_str);
    // Call the f2 function
    int f2_result = f2(f1_result, multiplier);
    return f2_result;
}

int main() {
    // Call the memory_print function to print the call stack
    printf(" stack contents in main:\n");
    memory_print(&main, &environ);
    // Call f1()
    char input[] = "Hello";
    int multiple = 2;
    int result = f1(input, multipler);

    printf("Result from f1: %d\n", result);
    return 0;
}
