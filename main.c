#include <stdio.h>
#include <stdlib.h>

int howManyDigit(char *array)
{
    int n=0;
    for (int i=0;!((*(array+i) == ' ')||(*(array+i) == '\0'));i++) n++;
    return n;
}

int calculate(char a, int b, int c)
{
    printf("calculate: %c %d %d\n",a,b,c);
    if (a == '+') return b + c;
    else return b * c;
}

int computePrefix(char *array)
{
    int a = howManyDigit((array+2));
    int b = howManyDigit((array+3+a));
    if (*(array+3+a+b) == '\0') return calculate(*array, atoi(array+2), atoi(array+3));  //遞迴終點
    return calculate(*(array), atoi(array+2), computePrefix(array+3+a));
}

int main()
{
    int n;
    printf("輸入陣列長度: ");
    scanf("%d",&n);
    printf("請輸入陣列: ");
    char array[n];
    scanf(" %[0-9+* ]",array);
    //char array[]= {"+ 31 * 2 + 750 + 99 + 1 1234"};
    //n = 28;
    array[n] = '\0';

    printf("輸入了: %s\n",array);
    printf("答案為: %d\n",computePrefix(array));
    system("pause");
    return 0;
}
