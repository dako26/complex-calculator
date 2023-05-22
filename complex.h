/*Created by Daniel*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct {
    double real;
    double img;
} complex;
void read_comp(complex *number,double real,double img);
void print_comp(complex *number);
complex add_comp(complex *number1,complex *number2);
complex sub_comp(complex *number1,complex *number2);
complex mult_comp_real(complex *number1,double number2);
complex mult_comp_img(complex *number1,double number2);
complex mult_comp_comp(complex *number1,complex *number2);
double abs_comp(complex *number1);
void stop();




