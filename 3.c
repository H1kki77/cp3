#include <stdio.h>
#include <math.h>
#include "funcs.h"
#include <conio.h>

int main() {

    double x=0, epsilon=0;
    char output=0;
    int k=0;
    do {
        printf("This program calculates the K-th root of X with accuracy that you will choose Exponential (E/e) or Standart (S/s):\n");
        k=get_root();

        x=get_root_base(k);

        epsilon=get_precision();

        double delta = 1.0, y=1.0;
        do {
            while (fabs(delta)>=epsilon) {
                if(k<0){
                    k=-k;
                    x=1.0/x;
                    delta=1.0/k*(x/pow(y,(double)k-1.0)-y);
                    y+=delta;
                }
                delta=1.0/k*(x/pow(y,k-1)-y);
                y+=delta;
            }
        }while (fabs(delta)>=epsilon);
        printf("Choose output form (1 for exponential or 2 for standart):\n");
        output=getch();
        if(output==49) {
            fflush(stdin);
            printf("y=%e\n",y);
        }else
            if(output==50) {
            bool validInput=false;
            unsigned n=0;
            do {
                printf("Choose precision from 1-15\n");
                if(scanf("%u",&n)!=1 || n<=0 || n>16) {
                    printf("Invalid input, choose correct integer number of precision");
                    fflush(stdin);
                } else {
                    validInput=true;
                }
            }while(!validInput);
            fflush(stdin);

            printf("y=%.*lf \n",(int)fabs(log10(epsilon)),y);
        }
        printf("Do you want to continue?(Y for YES/any key to EXIT):\n");
        fflush(stdin);
    }while (getch() == 'Y' || getch() == 'y');
    return 0;
}
