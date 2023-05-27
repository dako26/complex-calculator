/*
 * header file that contains the declaration of various functions and structures related to complex numbers.
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define FOREVER 1
#define INITIAL_BUFFER_SIZE 100
#define NUM_FUNCTIONS 8
/*
 * Represents a complex number with real and imaginary parts.
 */
typedef struct {
    double real;
    double imag;
} complex;
/*
 * Defines a function pointer type comp_func_ptr that takes two complex number pointers as arguments and returns void.
 */
typedef void (*comp_func_ptr)(complex*, complex*);
/*
 * Represents an entry for a complex number function.
 * Contains a function pointer func_ptr, a name for the function name, and the function name as a string func_name.
 */

typedef struct {
    comp_func_ptr func_ptr;
    char* name;
    char* func_name;
} function_entry;

/*
 * Reads the real and imaginary parts of a complex number from the arguments and assigns them to the given number.
 */
void read_comp(complex *number, double real, double imag);
/*
 * Prints the real and imaginary parts of a complex number.
 */
void print_comp(complex *number);
/*
 * Adds two complex numbers number1 and number2 and returns the result as a new complex number.
 */
complex * add_comp(complex *number1, complex *number2);
/*
 * Subtracts number2 from number1 and returns the result as a new complex number.
 */
complex * sub_comp(complex *number1, complex *number2);
/*
 * Multiplies a complex number number1 by a real number number2 and returns the result as a new complex number.
 */
complex * mult_comp_real(complex *number1, double number2);
/*
 * Multiplies a complex number number1 by an imaginary number represented as a real number number2 and returns the result as a new complex number.
 */
complex * mult_comp_img(complex *number1, double number2);
/*
 * Multiplies two complex numbers number1 and number2 and returns the result as a new complex number.
 */
complex * mult_comp_comp(complex *number1, complex *number2);
/*
 * Calculates the absolute value (magnitude) of a complex number.
 */
double abs_comp(complex *number1);
/*
 * Removes spaces from a given string str and returns the modified strin
 */
char *removeSpaces(char *str);
/*
 * Frees the memory allocated for the result of complex number operations.
 */
void free_result();
