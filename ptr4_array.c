#include <stdio.h>

double sum_all(double *nums, int count) {

    double total = 0;
    for (int i = 0; i < count; i++) {
        total = total + nums[i];
    }
    return total;
}

void double_all(double *nums, int count) {
    for (int i = 0; i < count; i++) {
        nums[i] = nums[i] * 2;
    }
}


int main(){

    int counting = 5;
    double nums[5] = {4, 3, 6, 5, 7};

    printf("nums     = %p\n",(void *)nums);
    printf("&nums[0] = %p\n",(void *)&nums[0]);
    printf("&nums[1] = %p\n",(void *)&nums[1]);
    

    printf("SUM: %.2lf\n", sum_all(nums, 5));

    double_all(nums, 5);


    for (int i = 0; i < counting; i++) {

        printf ("Double array: %.0lf\n", nums[i] );
    }
    



     
    
      

    return 0;
}

