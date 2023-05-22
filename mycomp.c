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
    double a, b;
    char choice1, choice2;
    scanf("%lf", &a);
    scanf("%lf", &b);
    read_comp(&A, a, b);
    scanf("%lf", &a);
    scanf("%lf", &b);
    read_comp(&B, a, b);

    scanf(" %c", &choice1);
    scanf(" %c", &choice2);
    complex *num1 = NULL;
    complex *num2 = NULL;
    ASSIGN_COMPLEX(choice1,num1);
    ASSIGN_COMPLEX(choice2,num2);
    complex temp = add_comp(num1, num2);
    print_comp(&temp);
    temp = sub_comp(num1, num2);
    print_comp(&temp);



    return 1;
}


