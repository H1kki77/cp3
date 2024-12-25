
#ifndef FUNCS_H
#define FUNCS_H

#include <stdio.h>
#include <stdbool.h>
#include <conio.h>


static int get_root() {
    int k=0;
    do {
        printf("Enter root (k) number:\n");
        scanf("%d", &k);
        fflush(stdin);

        if(k==0) {
            printf("There is no root number, try one more time\n");
        }
    }while (k==0);
    return k;
}

static double get_root_base(int k) {

    double x=0;
    bool validInput=false;
    do {
        printf("Enter root base (x) number:\n");
        if (scanf("%lf", &x) !=1 ) {
            printf("Invalid input for (x):\n");
            fflush(stdin);
            continue;
        }
        fflush(stdin);

        if (k>0 && k%2==0 && x<0) {
            printf("Incorrect input, the value must be positive\n");
        }
        else if (k<0 && k%2==0 && x<=0) {
            printf("Incorrect input, the value must be positive\n");
        }
        else if (k<0 && k%2!=0 && x==0) {
            printf("Incorrect input, the value must be positive\n");
        }
        else  {
            validInput=true;
        }
    }while (!validInput);
    return x;
}

static double get_precision() {
    double epsilon=0;
    char precision=0;
    bool validInput=false;
    do {
    printf("Choose type of precision for output:\n");
    printf("1 for Decimal places\n");
    printf("2 for Real number\n");
    printf("3 for Exponential form\n");


        precision=getch();
        fflush(stdin);

        switch (precision) {
            case 49: {
                int decimal = 0;
                printf("Please, enter the number of decimal places:\n");
                if (scanf("%d", &decimal) != 1 || decimal <=0) {
                    printf("Invalid input for decimal places:\n");
                   fflush(stdin);
                    continue;
                }
                fflush(stdin);

                epsilon = pow(10, -decimal);
                printf("The precision is %e\n", epsilon);
                validInput = true;
                break;
            }
        case 50: {
                printf("Please, choose precision as a real number:\n");
                if (scanf("%lf", &epsilon)!=1 || epsilon<=0) {
                    printf("Invalid input for real numbers:\n");
                    fflush(stdin);
                    continue;
                }
                fflush(stdin);

                printf("The precision is %e\n", epsilon);
                validInput=true;
                break;
            }
        case 51: {
                printf("Please, choose precision as an exponential number:\n");
                if (scanf("%lf", &epsilon)!=1 || epsilon<=0) {
                    printf("Invalid input for exponential number:\n");
                    fflush(stdin);
                    continue;
                }
                fflush(stdin);

                printf("The precision is %e\n", epsilon);
                validInput=true;
                break;
            }
        default:
        printf("Incorrect input, please choose a precision as a number from 1 to 3:\n");
        break;
        }
    }while (!validInput || precision<49 || precision>51);
    return epsilon;
}

#endif //FUNCS_H
