#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int piecesnum();
int piecesresult(int num);
int Combination(int head, int tail);


int piecesnum()
{
    int piecenum = 0;

    printf("피자가 몇 조각입니까? : ");
    scanf("%d", &piecenum);

    return piecenum;
}


int main()
{
    int pNum = piecesnum();
    int result = piecesresult(pNum);
    printf("\n피자를 %d가지 방법으로 나눌 수 있습니다.", result);
    return 0;
}


int piecesresult(int pieceNum)
{
    int sum = 0;
    int Number = pieceNum / 2;

    for (int i = 0; i <= Number; i++)
    {
        int head = pieceNum - i;
        sum += Combination(head, i);
    }

    return sum;
}


int Combination(int ivalue1, int ivalue2)
{
    int result = 0;
    int up = 1;
    int down = 1;

    for (int i = 0; i < ivalue2; i++)
    {
        up *= (ivalue1 - i);
        down *= (ivalue2 - i);
    }
    result = up / down;

    return result;
}