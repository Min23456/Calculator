#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';
    const char tomSize = 'L';
    const char salSize = 'M';
    double small;
    double med;
    double large;
    double subt; 
    double TAX1;
    double subtt;

    int numbershirtssal = 4;
    int numbershirtstom = 3;
    int numbershirts = 6;
    
    printf("Set Shirt Prices\n");
    printf("===============\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &small);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &med);
    printf("Enter price for a LARGE shirt: $");
    scanf("%lf", &large);

    printf("\nShirt Store Price List\n");
    printf("===============\n"); 
    printf("SMALL : $%.4lf\n", small);
    printf("MEDIUM :$%.4lf\n", med);
    printf("LARGE : $%.4lf\n", large);

    subt = small * numbershirts;

    TAX1 = subt * TAX;

    subtt = TAX1 + subt;

    printf("\nPatty's Shirt Size is: %c \n", patSize);
    printf("Number of shirts Patty is buying: %d\n", numbershirts);

     printf("\nTommy's Shirt Size is: %c \n", tomSize);
    printf("Number of shirts Tommy is buying: %d\n", numbershirtstom);

     printf("\nSally's Shirt Size is: %c \n", salSize);
    printf("Number of shirts Sally is buying: %d\n", numbershirtssal);

    printf("\n Customer Size Price Qty Sub-Total     Tax  Total\n");
    printf("\n-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty %c %lf %d ", patSize, small, numbershirts, subt, subtt);

// WIP, add the Customer Size Price Qty Sub-Total Tax Total, (patty, sally & tommy)

    printf("\n Patty's shopping cart...\n ");
    printf("\nContains: %d Shirts", numbershirts);

    printf("\nDaily retail sales represented by coins\n");
    printf("\n==============================\n");
    printf("\nSales EXCLUDING tax\n");

// WIP, put the coin, qty & balance here



    printf("\nSales INCLUDING tax\n");

// WIP, put the coin, qty & balance here

    printf("\nSub-total: $%.4lf", subt);
    printf("\nTaxes: $%.4lf", TAX1);
    printf("\nTotal (Sub-total + taxes): $%.4lf", subtt); 
    scanf("%d", &numbershirts);


    return 0;


}