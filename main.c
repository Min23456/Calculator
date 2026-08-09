#include <stdio.h>

double add(double a, double b){
    return a + b;
}

double muti(double a, double b){
    return a * b;
}

double divide(double a, double b){
    if (b == 0) {
        printf("Error");
        return 0;
    }
    return a / b;
}

double sub(double a, double b){
    return a - b;
}





int main(){
    double a, b;
    char op;
    char stop;
    double result;
    

    printf("Calculator in C.\n");
    do {

    printf("Please enter a Calculation. (2 numbers + Vaild Operator), (e.g. 2 + 7)\n");
    scanf(" %lf %c %lf", &a, &op, &b);

    if(op == '+'){
        result = add(a, b);
    } else if (op == '-'){
        result = sub(a, b);
    } else if (op == '*'){
        result = muti(a, b);
    } else if (op == '/'){
        result = divide(a, b);
    } else {
        printf("Wrong Operator, please try again!");
    }
    
    printf("%.0lf %c %.0lf = %.0lf \n", a, op, b, result);
    printf("Would you like to continue? (If you would like to stop, press q, if you would like to move on, please press on any key other then q.)");
    scanf(" %c" , &stop );
    } while (stop != 'q'); 


}










/** void hello(void){
    printf("Hello!\n");
}

int add(int a, int b){
    return a + b;
}





int getSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum = sum + arr[i];
    }
    return sum;
}


int getMax(int arr[], int size) {

    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}




double getAverage(int arr[], int size){

    return (double)getSum(arr, size) / size;

    
    // int sum = 0;

   // for (int i = 0; i < size; i++){
     //   sum = sum + arr[i];
   // }
   //return sum / size;
}


int main(){
    hello();


    int a = 1;
    int b = 2;

    printf("%d + %d = %d", a, b, add( a,  b));

    printf("\n===== scores =====\n");
    int scores[5] = {90, 85, 70, 100, 60};

    printf("sum:     %d\n",   getSum(scores, 5));


    printf("average: %.2f\n", getAverage(scores, 5));
    printf("max:     %d\n",   getMax(scores, 5));





    return 0;
}**/




