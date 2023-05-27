/*
 * Complex Number Calculator
 * Author: Daniel Koren
 * Date: 26/05/23
 */
#include "complex.h" /*Include the complex number header file*/
/*
 * Macro to assign a complex variable based on user choice
 */
#define ASSIGN_COMPLEX(choice, complexVar) \
    do { \
        switch (choice) { \
            case 'A': \
                complexVar = &A; \
                continue; \
            case 'B': \
                complexVar = &B; \
                continue; \
            case 'C': \
                complexVar = &C; \
                continue; \
            case 'D': \
                complexVar = &D; \
                continue; \
            case 'E': \
                complexVar = &E; \
                continue; \
            case 'F': \
                complexVar = &F; \
                continue; \
            default: \
                printf("Undefined complex variable.\n"); \
                continue; \
        } \
    } while(0)

int main() {
/*
 *     // Define complex variables A, B, C, D, E, F and initialize them to (0, 0)
 */

    complex A = {0, 0};
    complex B = {0, 0};
    complex C = {0, 0};
    complex D = {0, 0};
    complex E = {0, 0};
    complex F = {0, 0};
    /* Define an array of function entries for different complex operations */
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
    /* Declare other necessary variables*/
    complex *complex_choice1, *complex_choice2;
    complex *temp_complex;

    int i = 0;
    double double_choice1, double_choice2;
    char choice1, choice2;
    char *endptr;
    size_t length;
    char *user_line_input = malloc(INITIAL_BUFFER_SIZE * sizeof(char));
    char *input = malloc(INITIAL_BUFFER_SIZE * sizeof(char));
    size_t buffer_size = INITIAL_BUFFER_SIZE;
    char *user_func_input = malloc(INITIAL_BUFFER_SIZE * sizeof(char));
    /* Check if memory allocation for user inputs was successful */
    if (user_line_input == NULL || input == NULL || user_func_input == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return 1;
    }

    /*Print the instructions and available operations to the user*/
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

    /* Main loop to continuously accept user input and perform operations */
    while (FOREVER) {
        /* Read user input */
        if (fgets(user_line_input, buffer_size, stdin) == NULL)
            if (user_line_input[0] == ',') {
                printf("Illegal comma\n");
                continue;
            }
        /*  Extract the function name from user input*/
        sscanf(user_line_input, "%s", user_func_input);
        if (user_line_input[0] == '\0' || user_line_input[0] == '\n')
            continue;
        length = strlen(user_func_input);
        memmove(user_line_input, user_line_input + length, strlen(user_line_input) - length + 1);
        input = removeSpaces(user_line_input);
        input[strcspn(input, "\n")] = '\0';
        if ((((strcmp(user_func_input, "stop")) == 0))) {
            if (input[0] != '\0') {
                printf("Extraneous text after end of command\n");
                continue;
            }
            free(user_func_input);
            free(input);
            exit(0);
        }
        /* Find the corresponding function entry in the func_array*/
        for (i = 0; i < NUM_FUNCTIONS; i++) {
            if ((strcmp(user_func_input, func_array[i].func_name)) == 0)
                break;

        }
        /* Execute the function based on user input*/
        switch (i) {
            /* read_comp and checking if it's in the format */
            case 0 : {

                if (strlen(input) > 0) {
                    choice1 = input[0];
                    if (input[1] != ',') {
                        printf("missing comma\n");
                        continue;
                    }
                    memmove(input, input + 2, strlen(input));
                    if (choice1 != 'A' && choice1 != 'B' && choice1 != 'C' && choice1 != 'D' && choice1 != 'E' &&
                        choice1 != 'F') {
                        printf("Undefined complex variable.\n");
                        continue;
                    }
                    ASSIGN_COMPLEX(choice1, complex_choice1);


                } else {
                    printf("Missing parameter\n");
                    continue;
                }
                if (*user_line_input != '\0') {
                    if (isdigit((int) input[0])) {
                        double_choice1 = strtod(input, &endptr);
                        strcpy(input, endptr);
                        if (input[0] != ',') {
                            printf("missing comma\n");
                            continue;
                        }

                        memmove(input, input + 1, strlen(input));
                    } else if (input[0] == '-') {
                        if (isdigit((int) input[1])) {
                            double_choice1 = strtod(input, &endptr);
                        } else {
                            printf("wrong parameter\n");
                            continue;
                        }
                        strcpy(input, endptr);
                        if (input[0] != ',') {
                            printf("missing comma\n");
                            continue;
                        }

                        memmove(input, input + 1, strlen(input));
                    } else {
                        printf("Missing parameter\n");
                        continue;
                    }
                    if (*user_line_input != '\0') {
                        if (isdigit((int) input[0]))
                            double_choice2 = strtod(input, &endptr);
                        else if (input[0] == '-') {
                            if (isdigit((int) input[1])) {
                                double_choice2 = strtod(input, &endptr);
                            } else {
                                printf("Missing parameter\n");
                                continue;
                            }
                        } else {
                            printf("wrong parameter\n");
                            continue;
                        }
                    } else {
                        printf("Missing parameter\n");
                        continue;
                    }
                    if (endptr[0] != '\0') {
                        printf("Extraneous text after end of command\n");
                        continue;
                    }
                    read_comp(complex_choice1, double_choice1, double_choice2);
                    continue;
                }
                /* print_comp (1) and abs_comp (7) and checking if it's in the format */
                case 1:
                case 7:
                    if (strlen(input) > 0) {
                        choice1 = input[0];
                        if (choice1 != 'A' && choice1 != 'B' && choice1 != 'C' && choice1 != 'D' && choice1 != 'E' &&
                            choice1 != 'F') {
                            printf("Undefined complex variable.\n");
                            continue;
                        }
                        ASSIGN_COMPLEX(choice1, complex_choice1);
                        memmove(input, input + 1, strlen(input));
                    } else {
                        printf("Missing parameter\n");
                        continue;
                    }
                if (input[0] != '\0') {
                    printf("Extraneous text after end of command\n");
                    continue;
                }
                if (i == 1)
                    print_comp(complex_choice1);

                else
                    printf("%f\n", abs_comp(complex_choice1));
                continue;
                /* add_comp (2) , sub_comp (3), mult_comp_comp (6) and checking if it's in the format */
                case 2:
                case 3:
                case 6: {
                    if (strlen(input) > 0) {
                        choice1 = input[0];
                        if (input[2] == ',') {
                            printf("missing comma\n");
                            continue;
                        }
                        memmove(input, input + 2, strlen(input));
                        if (choice1 != 'A' && choice1 != 'B' && choice1 != 'C' && choice1 != 'D' && choice1 != 'E' &&
                            choice1 != 'F') {
                            printf("Undefined complex variable.\n");
                            continue;
                        }
                        ASSIGN_COMPLEX(choice1, complex_choice1);

                    } else {
                        printf("Missing parameter\n");
                        continue;
                    }
                    if (strlen(input) > 0) {
                        choice2 = input[0];
                        memmove(input, input + 1, strlen(input));
                        if (choice1 != 'A' && choice1 != 'B' && choice1 != 'C' && choice1 != 'D' && choice1 != 'E' &&
                            choice1 != 'F') {
                            printf("Undefined complex variable.\n");
                            continue;
                        }
                        ASSIGN_COMPLEX(choice2, complex_choice2);
                    } else {
                        printf("Missing parameter\n");
                        continue;
                    }
                    if (input[0] != '\0') {
                        printf("Extraneous text after end of command\n");
                        continue;
                    }
                    if (i == 2) {
                        temp_complex = add_comp(complex_choice1, complex_choice2);
                    } else if (i == 3) {
                        temp_complex = sub_comp(complex_choice1, complex_choice2);
                    } else {
                        temp_complex = mult_comp_comp(complex_choice1, complex_choice2);
                    }
                    print_comp(temp_complex);
                    free_result();
                    continue;
                }
                /* mult_comp_real (4) and mult_comp_img (5) and checking if it's in the format */
                case 4:
                case 5: {

                    if (strlen(input) > 0) {
                        choice1 = input[0];
                        if (input[1] != ',') {
                            printf("missing comma\n");
                            continue;
                        }
                        memmove(input, input + 2, strlen(input));
                        if (choice1 != 'A' && choice1 != 'B' && choice1 != 'C' && choice1 != 'D' && choice1 != 'E' &&
                            choice1 != 'F') {
                            printf("Undefined complex variable.\n");
                            continue;
                        }
                        ASSIGN_COMPLEX(choice1, complex_choice1);


                    } else {
                        printf("Missing parameter\n");
                        continue;
                    }
                    if (*user_line_input != '\0') {
                        if (isdigit((int) input[0])) {
                            double_choice1 = strtod(input, &endptr);
                            strcpy(input, endptr);

                        } else if (input[0] == '-') {
                            if (isdigit((int) input[1])) {
                                double_choice1 = strtod(input, &endptr);
                                strcpy(input, endptr);
                            } else {
                                printf("wrong parameter\n");
                                continue;
                            }

                        }
                    } else {
                        printf("Missing parameter\n");
                        continue;
                    }
                    if (input[0] != '\0') {
                        printf("Extraneous text after end of command\n");
                        continue;
                    }
                    if (i == 4)
                        temp_complex = mult_comp_real(complex_choice1, double_choice1);
                    else if (i == 5)
                        temp_complex = mult_comp_img(complex_choice1, double_choice1);
                    print_comp(temp_complex);
                    continue;
                    /*if command not found */
                    default: {
                        printf("Undefined command name.\n");
                        free_result();
                        continue;
                    }

                }

            }


        }


    }
    return 1;
}