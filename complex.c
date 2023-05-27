/*
 * Implements the functions declared in complex.h for performing operations on complex numbers.
 */

#include "complex.h"

/*
 * Takes a complex number pointer number and assigns the real and imaginary parts provided as arguments.
 */
void read_comp(complex *number, double real, double imag) {
    number->imag = imag;
    number->real = real;
}
/*
 * Prints the real and imaginary parts of a complex number.
 */
void print_comp(complex *number) {
    if (number->imag >= 0)
        printf("%.2f + %.2fi\n", number->real, number->imag);
    else
        (printf("%.2f%.2fi\n", number->real, number->imag));
}
/*
 * Adds two complex numbers number1 and number2 and returns the result as a new complex number.
 */
complex * add_comp(complex *number1, complex *number2) {
    complex* result = malloc(sizeof(complex));
    result->real = number1->real + number2->real;
    result->imag = number1->imag + number2->imag;
    return result;
}
/*
 * Subtracts number2 from number1 and returns the result as a new complex number.
 */
complex * sub_comp(complex *number1, complex *number2) {
    complex* result = malloc(sizeof(complex));
    result->real = number1->real - number2->real;
    result->imag = number1->imag - number2->imag;
    return result;
}
/*
 * Multiplies a complex number number1 by a real number number2 and returns the result as a new complex number.
 */
complex * mult_comp_real(complex *number1, double number2) {
    complex *result= malloc(sizeof(complex));;
    result->imag = number1->imag * number2;
    result->real = number1->real * number2;
    return result;
}
/*
 * Multiplies a complex number number1 by an imaginary number represented as a real number number2 and returns the result as a new complex number.
 */
complex * mult_comp_img(complex *number1, double number2) {
    complex *result= malloc(sizeof(complex));;
    result->imag = number1->real * number2;
    result->real = number1->imag * number2 * -1;
    return result;
}
/*
 * Multiplies two complex numbers number1 and number2 and returns the result as a new complex number.
 */
complex * mult_comp_comp(complex *number1, complex *number2) {
    complex* result = malloc(sizeof(complex));
    result->real = ((number1->real * number2->real) - (number1->imag * number2->imag));
    result->imag = ((number1->real * number2->imag) + (number1->imag * number2->real));
    return result;
}
/*
 * Calculates the absolute value (magnitude) of a complex number.
 */
double abs_comp(complex *number1) {
    return sqrt(pow(number1->real, 2) + pow(number1->imag, 2));
}
/*
 * Removes spaces from a given string str and returns the modified strin
 */
char *removeSpaces(char *str) {
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++) {

        if (str[i] != ' ') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
    return str;
}
/*
 * Frees the memory allocated for the result of complex number operations.
 */
void free_result(){
    void *result;
    free(result);
}