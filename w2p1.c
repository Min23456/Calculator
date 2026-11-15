#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';
    double small;
    double med;
    double large;
    double subt; 
    double TAX1;
    double subtt;

    int numbershirts = 8;
    
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

    printf("\n Patty's shopping cart...\n ");
    printf("\nContains: %d Shirts", numbershirts);

    printf("\nSub-total: $%.4lf", subt);
    printf("\nTaxes: $%.4lf", TAX1);
    printf("\nTotal (Sub-total + taxes): $%.4lf", subtt); 
    scanf("%d", &numbershirts);


    return 0;


}




#include<stdio.h>

int main (void)
{
  const double TAX_RATE = 0.13;
    const char patSizeS = 'S';
    const char patSizeM = 'M';
    const char patSizeL = 'L';
    const int toonie = 200;
    const int loonie = 100;
    const int quarter = 25;
    const int dime = 10;
    const int nickel = 5;
    const int penny = 1;

  int numberofShirtsS, numberofShirtsM, numberofShirtsL, taxS, taxM, taxL, subTotalS, subTotalM, subTotalL, totalS, totalM, totalL, subTotalBig, taxBig, totalBig;
  int coinCountT, coinCountL, coinCountQ, coinCountD, coinCountN, coinCountP, balance;
  double shirtPriceS, shirtPriceM, shirtPriceL;

  printf ("Set Shirt Prices\n"
          "================\n");
  printf ("Enter the price for a SMALL shirt: $");
  scanf ("%lf", &shirtPriceS);
  printf ("Enter the price for a MEDIUM shirt: $");
  scanf ("%lf", &shirtPriceM);
  printf ("Enter the price for a LARGE shirt: $");
  scanf ("%lf", &shirtPriceL);
  putchar ('\n');

  printf ("Shirt Store Price List\n"
          "======================\n");
  printf ("SMALL  : $%.2lf\n", shirtPriceS);
  printf ("MEDIUM : $%.2lf\n", shirtPriceM);
  printf ("LARGE  : $%.2lf\n", shirtPriceL);
  putchar ('\n');
  

  printf ("Patty's shirt size is '%c'\n"
          "Number of shirts Patty is buying: ", patSizeS);
  scanf ("%d", &numberofShirtsS);
  putchar ('\n');
  
    
  printf ("Tommy's shirt size is '%c'\n"
          "Number of shirts Tommy is buying: ", patSizeL);
  scanf ("%d", &numberofShirtsL);
  putchar ('\n');
    
    
  printf ("Sally's shirt size is '%c'\n"
          "Number of shirts Sally is buying: ", patSizeM);
  scanf ("%d", &numberofShirtsM);
  putchar ('\n');
    
  
  //calculations
  subTotalS = (int)(((shirtPriceS * numberofShirtsS) + 0.005) * 100);
  taxS = (int)((subTotalS * TAX_RATE) + 0.5);
  totalS = subTotalS + taxS;
    
    subTotalM= (int)(((shirtPriceM * numberofShirtsM) + 0.005) * 100);
    taxM = (int)((subTotalM * TAX_RATE) + 0.5);
    totalM = subTotalM + taxM;
    
    subTotalL = (int)(((shirtPriceL * numberofShirtsL) + 0.005) * 100);
    taxL = (int)((subTotalL * TAX_RATE) + 0.5);
    totalL = subTotalL + taxL;
    
    subTotalBig = subTotalS + subTotalM + subTotalL;
    taxBig = taxS + taxM + taxL;
    totalBig = totalS + totalM + totalL;
    
   
    printf("Customer Size Price Qty Sub-Total       Tax     Total\n"
           "-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSizeS, shirtPriceS, numberofShirtsS, subTotalS/100.0000, taxS/100.0000, totalS/100.0000);
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSizeM, shirtPriceM, numberofShirtsM, subTotalM/100.0000, taxM/100.0000, totalM/100.0000);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSizeL, shirtPriceL, numberofShirtsL, subTotalL/100.0000, taxL/100.0000, totalL/100.0000);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %9.4lf %9.4lf\n\n",subTotalBig/100.0000, taxBig/100.0000, totalBig/100.0000);
    

  // coins excluding taxes
  printf("Daily retail sales represented by coins\n"
         "=======================================\n\n");
    printf("Sales EXCLUDING tax\n"
           "Coin     Qty   Balance\n"
           "-------- --- ---------\n");
    printf("%22.4lf\n",subTotalBig/100.0000);
    
    //calculations for the coins
    balance = (int)(subTotalBig + 0.005) ;
        coinCountT = balance / toonie;
        balance = balance % toonie;
    
    printf("Toonies  %3d %9.4lf\n",  coinCountT, balance/100.0000);
    balance = (int)(balance + 0.005);
        coinCountL = balance / loonie;
        balance = balance % loonie;
    
    printf("Loonies  %3d %9.4lf\n",  coinCountL, balance/100.0000);
    balance = (int)(balance + 0.005);
        coinCountQ = balance / quarter;
        balance = balance % quarter;
    
    printf("Quarters %3d %9.4lf\n",  coinCountQ, balance/100.0000);
    
    balance = (int)(balance + 0.005);
        coinCountD = balance / dime;
        balance = balance % dime;
    
    printf("Dimes    %3d %9.4lf\n",  coinCountD, balance/100.0000);
    
    balance = (int)(balance + 0.005);
        coinCountN = balance / nickel;
        balance = balance % nickel;
    
    printf("Nickels  %3d %9.4lf\n",  coinCountN, balance/100.0000);
    
    balance = (int)(balance + 0.005);
        coinCountP = balance / penny;
        balance = balance % penny;
    printf("Pennies  %3d %9.4lf\n\n",  coinCountP, balance/100.0000);
    
    
   //average without taxes
    printf("Average cost/shirt: $%5.4lf\n\n",((((double)subTotalBig / (numberofShirtsS + numberofShirtsM + numberofShirtsL)) / 100.0)));
    
    
    //coins including taxes
      printf("Sales INCLUDING tax\n"
             "Coin     Qty   Balance\n"
             "-------- --- ---------\n");
      printf("%22.4lf\n",totalBig/100.0000);
      
      //calculations for the coins
      balance = (int)(totalBig + 0.005) ;
          coinCountT = balance / toonie;
          balance = balance % toonie;
      
      printf("Toonies  %3d %9.4lf\n",  coinCountT, balance/100.0000);
      balance = (int)(balance + 0.005);
          coinCountL = balance / loonie;
          balance = balance % loonie;
      
      printf("Loonies  %3d %9.4lf\n",  coinCountL, balance/100.0000);
      balance = (int)(balance + 0.005);
          coinCountQ = balance / quarter;
          balance = balance % quarter;
      
      printf("Quarters %3d %9.4lf\n",  coinCountQ, balance/100.0000);
      
      balance = (int)(balance + 0.005);
          coinCountD = balance / dime;
          balance = balance % dime;
      
      printf("Dimes    %3d %9.4lf\n",  coinCountD, balance/100.0000);
      
      balance = (int)(balance + 0.005);
          coinCountN = balance / nickel;
          balance = balance % nickel;
      
      printf("Nickels  %3d %9.4lf\n",  coinCountN, balance/100.0000);
      
      balance = (int)(balance + 0.005);
          coinCountP = balance / penny;
          balance = balance % penny;
      printf("Pennies  %3d %9.4lf\n\n",  coinCountP, balance/100.0000);
      
      //average with taxes
    printf("Average cost/shirt: $%5.4lf\n\n",((((double)totalBig / (numberofShirtsS + numberofShirtsM + numberofShirtsL)) / 100.0)));
    
    

    

  return 0;
}
