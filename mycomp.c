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
    complexFunctions[0] = (ComplexFunction) read_comp;
    complexFunctions[1] = (ComplexFunction) print_comp;
    complexFunctions[2] = (ComplexFunction) add_comp;
    complexFunctions[3] = (ComplexFunction) sub_comp;
    complexFunctions[4] = (ComplexFunction) mult_comp_real;
    complexFunctions[5] = (ComplexFunction) mult_comp_img;
    complexFunctions[6] = (ComplexFunction) mult_comp_comp;
    complexFunctions[7] = (ComplexFunction) abs_comp;
    double a, b;
    char choice1, choice2;
    printf("\nHello to complex calculator\n");
    printf("We have eight operations that our calculator can perform.\n");
    printf("when entering imaginary number please enter without i\n");
    printf("1)read_comp - this function initializes several complex variables (A, B, C, D, E, F)\n");
    printf("To use read_comp use this format: read_comp complex-variable,real-number,imaginary-number(without i). for example: read_comp A, 5.1, 6.23\n ");
    printf("2)print_comp - This function is used to print a complex number\n");
    printf("To use print_comp use this format: print_comp complex-variable. for example: print_comp A\n ");
    printf("3)add_comp - This function performs addition between two complex numbers and print the result\n");
    printf("To use add_comp use this format: add_comp complex-variable , complex-variable. for example: add_comp A, B\n ");
    printf("4)sub_comp - This function performs subtraction between two complex numbers and print the result\n");
    printf("To use sub_comp use this format: sub_comp first-complex-variable , second-complex-variable. for example: sub_comp A, B\n ");
    printf("5)mult_comp_real - This function performs multiplication between a complex number and a real number.\n");
    printf("To use mult_comp_real use this format: mult_comp_real complex-variable , Real-number. for example: mult_comp_real A, 3.55\n ");
    printf("6)mult_comp_img - This function performs multiplication between a complex number and a imaginary number represented as a real number.  \n ");
    printf("To use mult_comp_img use this format: mult_comp_img complex-variable , imaginary-number(without i). for example: mult_comp_img A, 3.55\n ");
    printf("7)mult_comp_comp - his function performs multiplication between two complex numbers. \n");
    printf("To use mult_comp_comp use this format: mult_comp_comp complex-variable ,complex-variable. for example: mult_comp_comp A, B\n ");
    printf("8)abs_comp - This function calculates the absolute value (magnitude) of a complex number\n");
    printf("To use abs_comp use this format: abs_comp complex-variable. for example: abs_comp A, B\n ");
    printf("To stop the program enter exit\n");


    return 1;
}

