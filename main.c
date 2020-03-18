#include <stdio.h>
#include <stdlib.h>

int computePrefix(char *input, int left)
{
    int i = 0, flag = 0, front, behind;
    int operatorSum = 0; // !(0 - 9)
    int operandSum = 0;  // 0 - 9

    //printf("%d %s\n\n", left, input+left);

    if(input[left] >= 48 && input[left] <= 57) return atoi(input + left);  //遞迴結束，回傳數字

    else
    {
        for(i = left; ; i++)  //i = 字串尾
        {
            if(input[i] >= 48 && input[i] <= 57)
            {
                if(flag == 0)
                    operandSum++;
                flag = 1;
            }
            else if(input[i] == ' ') flag = 0;
            else operatorSum++;

            if(operandSum == operatorSum && flag == 0)
                break;
        }

        front = computePrefix(input, left + 2);
        behind = computePrefix(input, i + 1);

        if(input[left] == '+') return front + behind;  //遞迴結束，回傳運算結果
        if(input[left] == '*') return front * behind;
    }
}

int main()
{
    int n;
    printf("輸入陣列長度: ");
    scanf("%d",&n);
    printf("請輸入陣列: ");
    char array[n+1];
    scanf(" %[0-9+* ]",array);
    //char array[]= {"+ 31 * 2 + 750 + 99 + 1 1234"};
    //char array[]= {"+ + 2120 * 3 5 50"};
    //n = 28;
    //n = 17;
    array[n] = '\0';

    printf("輸入了: %s\n",array);

    printf("答案為: %d\n",computePrefix(array, 0));
    system("pause");
    return 0;
}
