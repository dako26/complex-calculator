/*Created by Daniel*/
#include "complex.h"

#define ASSIGN_COMPLEX(choice, complexVar) \
    do { \
        if (choice == 'A') { \
            complexVar = &A; \
        } else if (choice == 'B') { \
            complexVar = &B; \
        } else if (choice == 'C') { \
            complexVar = &C; \
        } else if (choice == 'D') { \
            complexVar = &D; \
        } else if (choice == 'E') { \
            complexVar = &E; \
        } else if (choice == 'F') { \
            complexVar = &F; \
        } \
    } while(0)

int main() {


    complex A = {0, 0};
    complex B = {0, 0};
    complex C = {0, 0};
    complex D = {0, 0};
    complex E = {0, 0};
    complex F = {0, 0};
    int i = 0;
    double a, b;
    char choice1, choice2;
    char *user_line_input = malloc(INITIAL_BUFFER_SIZE * sizeof(char));
    if (user_line_input == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return 1;
    }
    size_t buffer_size = INITIAL_BUFFER_SIZE;
    char *user_func_input = malloc(INITIAL_BUFFER_SIZE * sizeof(char));
    if (user_func_input == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        free(user_line_input);
        return 1;
    }
    function_entry func_array[] = {
            {(comp_func_ptr) read_comp,      "initialize val",             "read_comp"},
            {(comp_func_ptr) print_comp,     "print complex",              "print_comp"},
            {(comp_func_ptr) add_comp,       "Addition",                   "add_comp"},
            {(comp_func_ptr) sub_comp,       "Subtraction",                "sub_comp"},
            {(comp_func_ptr) mult_comp_real, "Multiplication (Real)",      "mult_comp_real"},
            {(comp_func_ptr) mult_comp_img,  "Multiplication (Imaginary)", "mult_comp_img"},
            {(comp_func_ptr) mult_comp_comp, "Multiplication (Complex)",   "mult_comp_comp"},
            {(comp_func_ptr) abs_comp,       "Absolute Value",             "abs_comp"}
    };
    printf("\nHello to complex calculator\n");
    printf("We have eight operations that our calculator can perform.\n");
    printf("when entering imaginary number please enter without i\n");
    printf("1)read_comp - this function initializes several complex variables (A, B, C, D, E, F)\n");
    printf("To use read_comp use this format: read_comp complex-variable,real-number,imaginary-number(without i).\n");
    printf("for example: read_comp A, 5.1, 6.23\n");
    printf("2)print_comp - This function is used to print a complex number\n");
    printf("To use print_comp use this format: print_comp complex-variable. \n");
    printf("for example: print_comp A\n");
    printf("3)add_comp - This function performs addition between two complex numbers and print the result\n");
    printf("To use add_comp use this format: add_comp complex-variable , complex-variable. \n");
    printf("for example: add_comp A, B\n");
    printf("4)sub_comp - This function performs subtraction between two complex numbers and print the result\n");
    printf("To use sub_comp use this format: sub_comp first-complex-variable , second-complex-variable. \n");
    printf("for example: sub_comp A, B\n");
    printf("5)mult_comp_real - This function performs multiplication between a complex number and a real number.\n");
    printf("To use mult_comp_real use this format: mult_comp_real complex-variable , Real-number.\n");
    printf("for example: mult_comp_real A, 3.55\n");
    printf("6)mult_comp_img - This function performs multiplication between a complex number and a imaginary number represented as a real number.\n");
    printf("To use mult_comp_img use this format: mult_comp_img complex-variable , imaginary-number(without i).\n");
    printf("for example: mult_comp_img A, 3.55\n");
    printf("7)mult_comp_comp - his function performs multiplication between two complex numbers. \n");
    printf("To use mult_comp_comp use this format: mult_comp_comp complex-variable ,complex-variable.\n");
    printf("for example: mult_comp_comp A, B\n");
    printf("8)abs_comp - This function calculates the absolute value (magnitude) of a complex number\n");
    printf("To use abs_comp use this format: abs_comp complex-variable. \n");
    printf("for example: abs_comp A, B\n");
    printf("To stop the program enter exit\n");
    while (FOREVER) {
        fgets(user_line_input, buffer_size, stdin);
        sscanf(user_line_input,"%s",user_func_input);
        size_t length = strlen(user_func_input);
        memmove(user_line_input, user_line_input + length, strlen(user_line_input) - length + 1);
        char *input = removeSpaces(user_line_input);
        printf(input);
        for (i = 0; i < 8; i++) {
            if ((strcmp(user_func_input, func_array[i].func_name)) == 0)
                break;
            if ((((strcmp(user_func_input, "exit")) == 0)))
                exit(0);
        }
        switch (i) {
            case 0 : {
            }
            case 1:
            case 7: {

            }
            case 2:
            case 3:
            case 6: {

            }
            case 4:
            case 5: {

            }
            default: {
                printf("Undefined command name.\n");
                continue;
            }
        }
        free(input);
        free(user_func_input);
    }

    return 1;
}