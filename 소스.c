//서울 경기 지역 코로나 확진 추이 프로그램 연습용
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void increase(int(*difference)[6], int(*month)[7])                            //반환형이 없는 함수(각 주차별로 요일이 바뀔때마다 확진자수 증감 추세를 확인하기 위한 함수)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d주차 확진 증가 추이\n", i + 1);
        for (int j = 0; j < 6; j++)
        {
            difference[i][j] = month[i][j + 1] - month[i][j];
            printf("%d번째 차이 = %d\n", j + 1, difference[i][j]);
        }
    }
}


struct covid19
{
    int deathcount;
};

struct covid19 seoul = { 19 };
struct covid19 gyeonggi = { 21 };


int main(void)
{
    printf("서울, 경기 지역 코로나 확진 추이 프로그램을 시작합니다.\n");
    printf("진행 순서는 '지역선택', '5월 내 확진자 수 확인', '확진자수 증감 추세 확인', '사망자수 확인' 입니다.\n");

    char region[1024];
    char select[1024];               //사망자수 확인 선택을 위한 변수 select


    printf("확진자 추이를 볼 수 있는 지역은 'seoul'과 'gyeonggi'가 있습니다.\n");

    printf("확진자 추이를 볼 지역을 입력하세요(소문자로 입력하세요): ");
    gets(region);
    tolower(region);       //seoul과 gyeonggi를 입력할때 대문자를 하나 섞어서 입력한 경우 대비

    if (strcmp("seoul", region) == 0)
    {
        int mayseoul[5][7] =           //서울의 5월 내 코로나 확진자 수
        {
           {812, 1113, 2522, 3856, 5411, 6821, 8229},
           {6278, 8211, 10765, 13214, 17442, 18652, 22365},
           {15242, 28512, 31468, 42350, 46578, 48180, 64222},
           {52278, 65872, 72451, 78632, 85147, 86245, 103564},
           {83214, 103675, 165870, 0, 0, 0, 0}
        };            //5월 달력에 들어가는 값을 위해 2차원 배열로 정의(나중에 for문으로 확진자 차이 구하기)

        //서울지역 5월 요일별 확진자수 위의 2차원배열로 정의한 것을 출력
        printf("                 5월 요일별 확진자 수                 (단위:명)\n");
        printf("         일         월        화        수        목         금        토         \n");
        printf("1주차    %d       %d      %d      %d       %d       %d     %d         \n", mayseoul[0][0], mayseoul[0][1], mayseoul[0][2], mayseoul[0][3], mayseoul[0][4], mayseoul[0][5], mayseoul[0][6]);
        printf("2주차    %d      %d      %d     %d     %d      %d     %d         \n", mayseoul[1][0], mayseoul[1][1], mayseoul[1][2], mayseoul[1][3], mayseoul[1][4], mayseoul[1][5], mayseoul[1][6]);
        printf("3주차    %d     %d     %d     %d     %d      %d     %d         \n", mayseoul[2][0], mayseoul[2][1], mayseoul[2][2], mayseoul[2][3], mayseoul[2][4], mayseoul[2][5], mayseoul[2][6]);
        printf("4주차    %d     %d     %d     %d     %d      %d     %d         \n", mayseoul[3][0], mayseoul[3][1], mayseoul[3][2], mayseoul[3][3], mayseoul[3][4], mayseoul[3][5], mayseoul[3][6]);
        printf("5주차    %d     %d    %d       %d         %d          %d         %d         \n\n", mayseoul[4][0], mayseoul[4][1], mayseoul[4][2], mayseoul[4][3], mayseoul[4][4], mayseoul[4][5], mayseoul[4][6]);

        printf("5월은 1주차 일요일부터 5주차 화요일까지 입니다.\n\n");

        //경기지역에서 각 주차별로 요일이 바뀔때마다 확진자수 증감 추세를 확인하기 위한 함수
        int differenceseoul[5][6] = { 0 };                     //각주차 요일이 지날때마다 확진자 수 차이를 2차원 배열로 정의
        increase(differenceseoul, mayseoul);            //함수 사용


        //서울 지역에서 코로나로 인한 사망자수 확인
        printf("\n5월 한달동안 서울에서 코로나로 인한 사망자 수를 확인하고 싶으시면 yes를 입력하세요.\n");
        printf("보고 싶지 않으시면 no를 입력하세요.\n");
        gets(select);
        tolower(select);
        if (strcmp("yes", select) == 0)
            printf("5월 한달동안 서울에서 코로나로 인해 사망한 사람의 수는 %d명입니다.\n", seoul.deathcount);
        else if (strcmp("no", select) == 0)
        {
            printf("알겠습니다.\n");
        }



    }
    else if (strcmp("gyeonggi", region) == 0)
    {
        int maygyeonggi[5][7] =           //경기도의 5월 내 코로나 확진자 수
        {
           {547, 845, 916, 1248, 1430, 1511, 2113},
           {1421, 2163, 3278, 6457, 8130, 9239, 12469},
           {7685, 8751, 12456, 15874, 18956, 20322, 23978},
           {18969, 19985, 26547, 27453, 29168, 45874, 52179},
           {43587, 85472, 113698, 0, 0, 0, 0}
        };            //5월 달력에 들어가는 값을 위해 2차원 배열로 정의(나중에 for문으로 확진자 차이 구하기)

        //경기지역 5월 요일별 확진자수 위의 2차원배열로 정의한 것을 출력
        printf("                 5월 요일별 확진자 수                 \n");
        printf("         일          월       화         수       목         금        토         \n");
        printf("1주차    %d        %d       %d       %d     %d       %d      %d         \n", maygyeonggi[0][0], maygyeonggi[0][1], maygyeonggi[0][2], maygyeonggi[0][3], maygyeonggi[0][4], maygyeonggi[0][5], maygyeonggi[0][6]);
        printf("2주차    %d       %d     %d       %d     %d       %d     %d         \n", maygyeonggi[1][0], maygyeonggi[1][1], maygyeonggi[1][2], maygyeonggi[1][3], maygyeonggi[1][4], maygyeonggi[1][5], maygyeonggi[1][6]);
        printf("3주차    %d       %d     %d     %d     %d     %d     %d         \n", maygyeonggi[2][0], maygyeonggi[2][1], maygyeonggi[2][2], maygyeonggi[2][3], maygyeonggi[2][4], maygyeonggi[2][5], maygyeonggi[2][6]);
        printf("4주차    %d     %d     %d     %d     %d     %d     %d         \n", maygyeonggi[3][0], maygyeonggi[3][1], maygyeonggi[3][2], maygyeonggi[3][3], maygyeonggi[3][4], maygyeonggi[3][5], maygyeonggi[3][6]);
        printf("5주차    %d     %d     %d      %d         %d         %d         %d         \n", maygyeonggi[4][0], maygyeonggi[4][1], maygyeonggi[4][2], maygyeonggi[4][3], maygyeonggi[4][4], maygyeonggi[4][5], maygyeonggi[4][6]);

        printf("5월은 1주차 일요일부터 5주차 화요일까지 입니다.\n");

        //경기지역에서 각 주차별로 요일이 바뀔때마다 확진자수 증감 추세를 확인하기 위한 함수
        int differencegyeonggi[5][6] = { 0 };
        increase(differencegyeonggi, maygyeonggi);


        //경기도 지역에서 코로나로 인한 사망자수 확인
        printf("5월 한달동안 경기도 지역에서 코로나로 인한 사망자 수를 확인하고 싶으시면 yes를 입력하세요.\n");
        printf("보고 싶지 않으시면 no를 입력하세요.\n");
        gets(select);
        tolower(select);
        if (strcmp("yes", select) == 0)
            printf("5월 한달동안 경기 지역에서 코로나로 인해 사망한 사람의 수는 %d명입니다.", seoul.deathcount);
        else if (strcmp("no", select) == 0)
            printf("알겠습니다.");

    }
    else
        printf("잘못 입력 하셨습니다.");


    return 0;
}