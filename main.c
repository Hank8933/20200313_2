#include <stdio.h>
#include <stdlib.h>

int howManyDigit(char *array)
{
    int n=0;
    //printf("s:%s\n",array);
    for (int i=0;!((*(array+i) == ' ')||(*(array+i) == '\0'));i++) n++;
    return n;
}

int calculate(char a, int b, int c)
{
    printf("calculate: %c %d %d\n",a,b,c);
    if (a == '+') return b + c;
    else return b * c;
}

int charToInt(char *c, int digit)
{
    int a = (int)*c-48;
    int b = (int)*(c+1)-48;
    int d = (int)*(c+2)-48;
    switch (digit)
    {
    case 1:
        return a;
    case 2:
        return a*10 + b;
    case 3:
        return a*100 + b*10 + d;
    case 4:
        return a*1000 + b*100 + d*10 + (int)*(c+3)-48;
    }
}

int computePrefix(char *array)
{
    //printf("run\n");
    //printf("%s\n",array);
    int a = howManyDigit((array+2));
    int b = howManyDigit((array+3+a));

    if (*(array+3+a+b) == '\0') return calculate(*array, charToInt(array+2,a), charToInt(array+3+a,b));  //遞迴終點
    return calculate(*(array), charToInt(array+2,a), computePrefix(array+3+a));
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
