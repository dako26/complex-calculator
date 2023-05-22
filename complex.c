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
complex mult_comp_real(complex *number1,double number2){
    complex result;
    result.img=number1->img*number2;
    result.real=number1->real*number2;
    return result;
}
complex mult_comp_img(complex *number1,double number2){
    complex result;
    result.img=number1->real*number2;
    result.real=number1->img*number2*-1;
    return result;
}
complex mult_comp_comp(complex *number1,complex *number2){
    complex result;
    result.real=((number1->real*number2->real)-(number1->img*number2->img));
    result.img=((number1->real*number2->img)+(number1->img*number2->real));
    return result;
}
double abs_comp(complex *number1){
    return sqrt(pow(number1->real,2)+ pow(number1->img,2));
}
void stop(){
    exit;
}