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
    double TAX2;
    double TAX3;
    double subtt;
    double subtS;
    double subtT;
    double subttS;
    double subttT;
    double subtte;
    double subttee;
    double toonies;
    double TR;
    double loonies;
    double LR;
    double Quarters;
    double QR;
    double Dimes;
    double DQ;
    double Nickels;
    double NR;
    double Pennies;
    double PR;
    double TTAX;
// Tax 1 = Patty, Tax 2 = Sally, & Tax 3 = Tommy
// subtS = Sally, subtT = Tommy
// subttS = Sally, subttT = Tommy
    

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


// -------------------------------
// PATTY:

    subt = small * numbershirts;
    TAX1 = subt * TAX;
    subtt = TAX1 + subt;
// -------------------------------
// SALLY:
    subtS = med * numbershirtssal;
    TAX2 = subtS * TAX;
    subttS = TAX2 + subtS;
// -------------------------------
// TOMMY:

    subtT = large * numbershirtstom;
    TAX3 = subtT * TAX;
    subttT = TAX3 + subtT;
// -------------------------------
// SUBTOTAL OF EVERYTHING (WITHOUT TAX):

    subtte = subt + subtS + subtT;
// -------------------------------
// TOTAL OF EVERYTHING (+TAX):

    subttee = subtt + subttS + subttT;
// -------------------------------
// TAX OF EVERYHING:

    TTAX = TAX1 + TAX2 + TAX3;
// -------------------------------
// COINS:




// -------------------------------
// WHAT SHIRTS THEY ARE BUYING (PATTY, TOMMY, & SALLY);
    printf("\nPatty's Shirt Size is: %c \n", patSize);
    printf("Number of shirts Patty is buying: %d\n", numbershirts);

     printf("\nTommy's Shirt Size is: %c \n", tomSize);
    printf("Number of shirts Tommy is buying: %d\n", numbershirtstom);

    printf("\nSally's Shirt Size is: %c \n", salSize);
    printf("Number of shirts Sally is buying: %d\n", numbershirtssal);
    printf(" ");
// -------------------------------
// CHART FOR PATTY, TOMMY, & SALLY:

    printf("\n Customer Size Price Qty Sub-Total     Tax  Total\n");
    printf("\n-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty %c %lf %d ", patSize, small, numbershirts, subt, subtt);
    printf("Sally %c %lf %d", salSize, med, numbershirtssal, subtS, subttS);
    printf("Tommy %c %lf %d", tomSize, large, numbershirtstom, subtT, subtT);
    printf("\n-------- ---- ----- --- ---------- ---------- -----------\n");
    printf("%lf %lf %lf", subtte, TTAX, subttee);
// ----------------------------------------------------------------------------

// WIP, add the Customer Size Price Qty Sub-Total Tax Total, (patty, sally & tommy)


    printf("\nDaily retail sales represented by coins\n");
    printf("\n==============================\n");

    printf("\nSales EXCLUDING tax (Sub-tax)\n");
    printf("\nCoin     Qty     Balance\n");
    printf("\n-------     ---     ---------\n");
    printf("Toonies ");
// ----------------------------------------------------------------------------
// WIP, put the coin, qty & balance here



    printf("\nSales INCLUDING tax\n");

// WIP, put the coin, qty & balance here

    printf("\nSub-total: $%.4lf", subt);
    printf("\nTaxes: $%.4lf", TAX1);
    printf("\nTotal (Sub-total + taxes): $%.4lf", subtt); 
    scanf("%d", &numbershirts);


    return 0;


}