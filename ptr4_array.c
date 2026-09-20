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
        nums 
    }
}


int main(){

    double nums[5] = {4, 3, 6, 5, 7};

    printf("nums     = %p\n",(void *)nums);
    printf("&nums[0] = %p\n",(void *)&nums[0]);
    printf("&nums[1] = %p\n",(void *)&nums[1]);

    printf("SUM: %.2lf\n", sum_all(nums, 5));

    double_all(nums, 5);
    return 0;
}

