#include <stdio.h>
#include <string.h>
/*
접근법
먼저 n에 입력한 횟수만큼 문자열을 입력한다.
그 문자열이 저장된 배열과 배열의 길이를 함수로 보냅니다.
보내진 함수는 그룹 단어일 때 1로 반환하여
sum에 저장이 되고 만약 그룹 단어가 아닐 시에는 0이 반환되어 sum에 0이 더해지는 것이다.
*/
int select(char a[], int len);
int main(void)
{
    int n, i, sum = 0;
    char arr[100];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%s", arr);
        sum += select(arr, strlen(arr));
    }

    printf("%d", sum);
    return 0;
}

int select(char a[], int len)
{
    int i, j;
    int key = 0;

    for (i = 0; i < len; i++)
    {
        for (j = 0; j < len; j++)
        {
            if (a[i] == a[j])
            {
                key = j - i;

                if (key > 1)
                    if (a[j - 1] != a[j])
                        return 0;
            }
        }
    }
    return 1;
}