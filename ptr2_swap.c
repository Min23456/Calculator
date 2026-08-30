#include <stdio.h>

void swap1(double a, double b){
    double temp = a;
    a = b; 
    b = temp;
    printf("In function swap1, a = %.0lf, and b = %.0lf\n", a , b);
}

void swap2(double *a, double *b){
    double temp = *a;
    *a = *b; 
    *b = temp;
}




int main(){

    double x = 1, y = 2;

    printf("Start, x = %.0lf, and y = %.0lf\n", x , y );

    swap1(x, y);
    printf("After swap1, x = %.0lf, and y = %.0lf\n", x , y );
    swap2(&x, &y);
    printf("After swap2, x = %.0lf, and y = %.0lf\n", x , y );

    return 0;
}