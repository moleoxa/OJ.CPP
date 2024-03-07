#include <stdio.h>
#include <ctype.h>
#define MAX 10086

int main(void) {
    int x;
    scanf("%d", &x);
    printf("10 * int = %d", 10 * x);

    puts(""); // 自带换行效果

    double y;
    scanf("%lf", &y);
    printf("double = %06.2f\n", y);

    /*  %-AB.CD => %06.1f
        A: 0填充
        B: 最小字段长度限制（小数点占一位）
        C: 精度（最小位数，浮点默认6位小数）
        D: 数据格式
        -：左对齐（默认右对齐，空白填充在左）
    */


    char c;
    while ((c = getchar()) != EOF) {
        putchar(c);
    }

    char str[] = "ABC\0";
    printf("\"%s\"\n", str);
    char name[20];
    scanf("%s", name);
    tolower('A');


    return 0;
}