#include <stdio.h>

void hello(void){
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
}




