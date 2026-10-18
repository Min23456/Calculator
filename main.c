#include <stdio.h>

double add(double a, double b) { return a + b; }
double sub(double a, double b) { return a - b; }
double muti(double a, double b) { return a * b; }
double divide(double a, double b) { return a / b; }

int main() {
    char op;
    double first_num, next_num;
    double total;

    printf("Calculator in C.\n");
    printf("Enter an equation (e.g., 5 + 3) or 'q' to quit: ");
    
    int parsed = scanf("%lf %c %lf", &first_num, &op, &next_num);

    if (parsed < 1) {
        char quit_check;
        if (scanf(" %c", &quit_check) == 1 && (quit_check == 'q' || quit_check == 'Q')) {
            return 0;
        }
        printf("Invalid starting input.\n");
        return 1;
    }

    if (parsed == 1) {
        char quit_check;
        if (scanf(" %c", &quit_check) == 1 && (quit_check == 'q' || quit_check == 'Q')) {
            return 0;
        }
        printf("Invalid input format.\n");
        return 1;
    }

    if (parsed != 3) {
        printf("Invalid input format.\n");
        return 1;
    }

    if (op == '+') {
        total = add(first_num, next_num);
    } else if (op == '-') {
        total = sub(first_num, next_num);
    } else if (op == '*') {
        total = muti(first_num, next_num);
    } else if (op == '/') {
        if (next_num == 0) {
            printf("Error: Division by zero!\n");
            return 1;
        }
        total = divide(first_num, next_num);
    } else {
        printf("Wrong Operator '%c'!\n", op);
        return 1;
    }

    while (1) {
        // --- FIXED LINE PEAKING LOGIC ---
        // Look at the very next character waiting in the buffer.
        // We bypass any trailing blank spaces to see if an actual newline is next.
        char check = getchar();
        while (check == ' ' || check == '\t') {
            check = getchar();
        }

        // If the user hit 'Enter' (\n), they are done typing their chain!
        if (check == '\n' || check == EOF) {
            printf("\nCurrent Total: %.4lf\n", total);
            printf("Enter operator and next number (e.g., * 2), or 'q' to quit: \n");
        } else {
            // If they typed more operations, put the character back for scanf to read
            ungetc(check, stdin);
        }

        if (scanf(" %c", &op) != 1) {
            printf("Invalid operator input.\n");
            break;
        }

        if (op == 'q' || op == 'Q') {
            break;
        }

        if (scanf("%lf", &next_num) != 1) {
            printf("Invalid number format.\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (op == '+') {
            total = add(total, next_num);
        } else if (op == '-') {
            total = sub(total, next_num);
        } else if (op == '*') {
            total = muti(total, next_num);
        } else if (op == '/') {
            if (next_num == 0) {
                printf("Error: Division by zero!\n");
                continue;
            }
            total = divide(total, next_num);
        } else {
            printf("Wrong Operator '%c', please try again!\n", op);
        }
    }

    printf("\nFinal Answer = %.4lf\n", total);
    return 0;
}









/**double add(double a, double b) { return a + b; }
double sub(double a, double b) { return a - b; }
double muti(double a, double b) { return a * b; }
double divide(double a, double b) { return a / b; }

int main() {
    char op;
    double first_num, next_num;
    double total;

    printf("Calculator in C.\n");
    printf("Enter an equation (e.g., 5 + 3) or 'q' to quit: ");
    

    int parsed = scanf("%lf %c %lf", &first_num, &op, &next_num);


    if (parsed < 1) {
       
        char quit_check;
        if (scanf(" %c", &quit_check) == 1 && (quit_check == 'q' || quit_check == 'Q')) {
            return 0;
        }
        printf("Invalid starting input.\n");
        return 1;
    }

   
    if (parsed == 1) {
        char quit_check;
        if (scanf(" %c", &quit_check) == 1 && (quit_check == 'q' || quit_check == 'Q')) {
            return 0;
        }
        printf("Invalid input format.\n");
        return 1;
    }

    if (parsed != 3) {
        printf("Invalid input format.\n");
        return 1;
    }

    if (op == '+') {
        total = add(first_num, next_num);
    } else if (op == '-') {
        total = sub(first_num, next_num);
    } else if (op == '*') {
        total = muti(first_num, next_num);
    } else if (op == '/') {
        if (next_num == 0) {
            printf("Error: Division by zero!\n");
            return 1;
        }
        total = divide(first_num, next_num);
    } else {
        printf("Wrong Operator '%c'!\n", op);
        return 1;
    }

    while (1) {
        printf("\nCurrent Total: %.4lf\n", total);
        printf("Enter operator and next number (e.g., * 2), or 'q' to quit: \n");

        if (scanf(" %c", &op) != 1) {
            printf("Invalid operator input.\n");
            break;
        }

        if (op == 'q' || op == 'Q') {
            break;
        }

        if (scanf("%lf", &next_num) != 1) {
            printf("Invalid number format.\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (op == '+') {
            total = add(total, next_num);
        } else if (op == '-') {
            total = sub(total, next_num);
        } else if (op == '*') {
            total = muti(total, next_num);
        } else if (op == '/') {
            if (next_num == 0) {
                printf("Error: Division by zero!\n");
                continue;
            }
            total = divide(total, next_num);
        } else {
            printf("Wrong Operator '%c', please try again!\n", op);
        }
    }

    printf("\nFinal Answer = %.4lf\n", total);
    return 0;
} **/

    
        













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


















// kept this if we need it (previous)

/** #include <stdio.h>

double add(double a, double b){
    return a + b;
}

double muti(double a, double b){
    return a * b;
}

double divide(double a, double b, double *out)
{
    if (b == 0) {
        printf("Error");
        return 0;
    }
    *out = a / b;
    return *out;
   
}

double sub(double a, double b){
    return a - b;
}
// 991.015317519




int main(){

    char op;
    char stop;
    double result;
    double num;
    double a;
    double b;



    printf("Calculator in C.\n");
    do {

    printf("Please enter a Calculation. (2 numbers + Vaild Operator), (e.g. 2 + 7)\n");
    // scanf(" %lf %c %lf", &a, &op, &b);

    scanf("%lf", &result);

    while (scanf("%c", &op) == 1) {

    if(op == '\n'){
        break;
    }

    if(op == '+'){
        scanf("%lf", &num);
        result = add(result, num);
    } else if (op == '-'){
        scanf("%lf", &num);
        result = sub(result, num);
        printf("answer = %.4lf", result);
    } else if (op == '*'){
        scanf("%lf", &num);
        result = muti(result, num);
        printf("answer = %.4lf", result);
    } else if (op == '/'){
        scanf("%lf", &num);
        //result = divide(result, num);
        divide(result, num, &result);
        if (b==0) {
             printf("Error");
        };
      

    
        



    } else {
        printf("Wrong Operator, please try again!");
    }
    

    }
    // printf("%.4lf", result);
    

    printf("\nWould you like to continue? (If you would like to stop, press q, if you would like to move on, please press on any key other then q.)");
    scanf(" %c" , &stop );


    } while (stop != 'q'); 

    return 0;
}**/










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




