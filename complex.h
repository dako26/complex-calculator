/*Created by Daniel*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define FOREVER 1
#define INITIAL_BUFFER_SIZE 100
typedef struct {
    double real;
    double imag;
} complex;

typedef void (*comp_func_ptr)(complex*, complex*); // Function pointer type

typedef struct {
    comp_func_ptr func_ptr;
    char* name;
    char* func_name
} function_entry;

void read_comp(complex *number, double real, double imag);

void print_comp(complex *number);

complex add_comp(complex *number1, complex *number2);

complex sub_comp(complex *number1, complex *number2);

complex mult_comp_real(complex *number1, double number2);

complex mult_comp_img(complex *number1, double number2);

complex mult_comp_comp(complex *number1, complex *number2);

double abs_comp(complex *number1);

char *removeSpaces(char *str);

