#include "heder.h"
void increase(int difference[5][6], int month[5][7])                            //반환형이 없는 함수(각 주차별로 요일이 바뀔때마다 확진자수 증감 추세를 확인하기 위한 함수)
{
    for (int i = 0; i < 5; i++)
    {
        printf("\n%d주차 확진 증가 추이\n", i + 1);
        for (int j = 0; j < 6; j++)
        {
            difference[i][j] = month[i][j + 1] - month[i][j];
            printf("%d번째 차이 = %d\n", j + 1, difference[i][j]);
        }
    }
}
