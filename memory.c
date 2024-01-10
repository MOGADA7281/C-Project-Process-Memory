#include <stdio.h>





void memory_print(void *start_addr, void *end_addr) {
    // Cast the start and end addresses to unsigned char pointers
    unsigned char *str = (unsigned char *)start_addr;
    unsigned char *ed = (unsigned char *)end_addr;

    // Main loop to iterate through memory
    do {
        // Print the current memory address in hexadecimal format
        printf("0x%lx: ", (unsigned long)str);

        int i = 0;
        while (i < 16) {
            // Check if we are still within the valid memory range
            if (str + i <= ed) {
                // Print the current byte in hexadecimal format
                printf("%02X ", str[i]);

                // Add an extra space after the 8th byte for formatting
                if (i == 7) {
                    printf(" ");
                }
                i++;
            } else {
                // If we are outside the valid memory range, print spaces
                while (i < 16) {
                    printf("   ");
                    if (i == 7) {
                        printf(" ");
                    }
                    i++;
                }
            }

            int j = 0; // Counter for printing printable characters
            while (j < 16 ){
            if(str + j <= ed) {
                // Print the current byte as a character if printable, otherwise print '.'
                unsigned char byte = str[j];
               if (byte >= 32 ){
               if(byte <= 126) {
                    printf("%c", byte);
                } else {
                    printf(".");
                }
                j++;
            }
        }
    }

            printf("\n"); // Move to the next line
            str += 16;    // Move to the next block of 16 bytes
        }
    } while (str < ed); // Continue until the end address is reached
}


void print_stack() {
    // Define a local variable to get the top of the call stack
    int local_variable = 0;

    // Calculate the start (top) of the call stack
    void *start_addr = &local_variable;

    // Calculate the end (bottom) of the call stack using environ[0]
    void *end_addr = (void *)environ[0];

    // Call memory_print to print the call stack
    memory_print(start_addr, end_addr);
}
