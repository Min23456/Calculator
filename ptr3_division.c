#include <stdio.h>

double division_old(double a, double b){
    if (b == 0) {
        printf("Error");
        return a;
    }
    return a / b;
}

int divide_new(double a, double b, double *out) {
    if (b == 0) {
        return 0;
    }

    *out = a / b;
    return 1;
}


int main(){

    double total;
    double result;
    total = 8;
    total = division_old(total, 0);
    total = total + 5;
    printf("[Previous] 8/0+5 = %.2lf   <- It's incorrect, but it pretends to be correct.\n\n", total);

    divide_new(total, 0, &result);

    return 0;
}