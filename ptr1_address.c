#include <stdio.h>

int main(){
    
    double total = 4.0;

    double *p;

    printf("total = %.2lf\n", total);
    printf("address of total = %p\n", (void *)&total);
    

    printf("Type a number to be the total.\n");
    scanf("%lf", &total);
    printf("Total = %lf", total);

    p = &total;

    printf("Address of p =%p\n",(void *)p);
    printf("Value of p from the address =%.2lf", *p);

    *p = 99.5;
    printf("Total =%0.2lf", total);



    return 0;

}