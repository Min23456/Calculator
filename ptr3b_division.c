#include <stdio.h>

/* ---- [A] 네가 ptr3 에서 만든 것. 그대로 가져왔다 ---- */
int divide_new(double a, double b, double *out)
{
    if (b == 0) {
        return 0;          /* 실패 */
    }
    *out = a / b;
    return 1;              /* 성공 */
}

/* ---- [B] 네가 main.c 에 쓴 것 ----
   리턴 타입이 double 이고, 성공하면 결과값을 리턴한다.
   이게 왜 문제인지 아래에서 직접 보게 된다.              */
double divide_mixed(double a, double b, double *out)
{
    if (b == 0) {
        printf("Error");
        return 0;
    }
    *out = a / b;
    return *out;
}

int main(void)
{
    double result;
    double ret;
    int ok;

    /* ========================================================
       실험 1 · [B] 버전의 문제
       ======================================================== */
    printf("=== divide_mixed (main.c 버전) ===\n");

    ret = divide_mixed(0, 5, &result);        /* 0 / 5 = 0. 성공이다 */
    printf("0/5 -> return=%.1lf  result=%.1lf   (성공)\n", ret, result);

    ret = divide_mixed(8, 0, &result);        /* 0 으로 나누기. 실패다 */
    printf("\n8/0 -> return=%.1lf                (실패)\n", ret);

    printf("\n★ 둘 다 리턴값이 0 이다.\n");
    printf("  리턴값만 보고 성공인지 실패인지 구분할 방법이 없다.\n");
    printf("  '결과값'과 '성공여부'를 한 숫자에 억지로 섞은 탓이다.\n");
    printf("  3단계에서 출구를 두 개로 나눈 이유가 바로 이것이다.\n\n");

    /* ========================================================
       실험 2 · [A] 버전을 제대로 쓰기
       ======================================================== */
    printf("=== divide_new (ptr3 버전) ===\n");

    /* ★ 처음에는 이렇게 풀어 써라. 익숙해지면 줄인다. */
    ok = divide_new(0, 5, &result);
    if (ok == 1) {
        printf("0/5 -> OK, result = %.1lf\n", result);
    } else {
        printf("0/5 -> Cannot divide by zero\n");
    }

    ok = divide_new(8, 0, &result);
    if (ok == 1) {
        printf("8/0 -> OK, result = %.1lf\n", result);
    } else {
        printf("8/0 -> Cannot divide by zero\n");
    }

    printf("\n★ 결과가 0 이어도 성공은 성공으로, 실패는 실패로 나온다.\n");
    printf("  출구가 두 개라서 섞이지 않는다.\n\n");

    /* ========================================================
       실험 3 · 줄여 쓰는 법 (실험 2 와 완전히 같다)
       ======================================================== */
    printf("=== 같은 것, 줄여 쓴 버전 ===\n");

    if (divide_new(9, 3, &result)) {
        printf("9/3 -> OK, result = %.1lf\n", result);
    } else {
        printf("9/3 -> Cannot divide by zero\n");
    }

    /* if 괄호 안이 1 이면 참, 0 이면 거짓.
       divide_new 가 1 이나 0 을 리턴하니 그대로 조건이 된다.
       ok 변수를 안 거치는 것뿐이고 동작은 똑같다.            */

    return 0;
}