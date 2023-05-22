/* Created by Daniel */
#include "complex.h"
void read_comp(complex *number,double real,double img){
    number->img=img;
    number->real=real;
}
void print_comp(complex *number){
    printf("%.2f + %.2fi",number->real,number->img);
}
complex add_comp(complex *number1,complex *number2){
    complex result;
    result.real=number1->real + number2->real;
    result.img=number1->img + number2->img;
    return result;
}
complex sub_comp(complex *number1,complex *number2){
    complex result;
    result.real=number1->real - number2->real;
    result.img=number1->img - number2->img;
    return result;
}