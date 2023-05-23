/* Created by Daniel */
#include "complex.h"

void read_comp(complex *number, double real, double imag) {
    number->imag = imag;
    number->real = real;
}

void print_comp(complex *number) {
    if (number->imag >= 0)
        printf("%.2f + %.2fi", number->real, number->imag);
    else
        (printf("%.2f%.2fi", number->real, number->imag));
}

complex add_comp(complex *number1, complex *number2) {
    complex result;
    result.real = number1->real + number2->real;
    result.imag = number1->imag + number2->imag;
    return result;
}

complex sub_comp(complex *number1, complex *number2) {
    complex result;
    result.real = number1->real - number2->real;
    result.imag = number1->imag - number2->imag;
    return result;
}

complex mult_comp_real(complex *number1, double number2) {
    complex result;
    result.imag = number1->imag * number2;
    result.real = number1->real * number2;
    return result;
}

complex mult_comp_img(complex *number1, double number2) {
    complex result;
    result.imag = number1->real * number2;
    result.real = number1->imag * number2 * -1;
    return result;
}

complex mult_comp_comp(complex *number1, complex *number2) {
    complex result;
    result.real = ((number1->real * number2->real) - (number1->imag * number2->imag));
    result.imag = ((number1->real * number2->imag) + (number1->imag * number2->real));
    return result;
}

double abs_comp(complex *number1) {
    return sqrt(pow(number1->real, 2) + pow(number1->imag, 2));
}