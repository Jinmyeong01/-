//���� ��� ���� �ڷγ� Ȯ�� ���� ���α׷� yaho
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>             //���� ��ȯ
#include <string.h>           //���ڿ��˻� �Լ� ��� ����
#include "heder.h"            //���� �ҽ� ����(�Լ�)

struct covid19
{
    int deathcount;
};  
   
struct covid19 seoul = { 19 };
struct covid19 gyeonggi = { 21 };

  
int main(void)
{
    char region[1024];
    char select[1024];               //����ڼ� Ȯ�� ������ ���� ���� select

    FILE* fp = fopen("announcement.txt", "r");      //announcement ������ �б� ���� ����
    char buffer[1000] = { 0, };

    fread(buffer, 1, 1000, fp);        //��ü�б�
    printf("%s", buffer);

    fclose(fp);

    printf("Ȯ���� ���̸� �� ������ �Է��ϼ���: ");
    gets(region);
    tolower(region);       //seoul�� gyeonggi�� �Է��Ҷ� �빮�ڸ� ��� �Է��� ��� ���

    if (strcmp("seoul", region) == 0)
    {
        int mayseoul[5][7] =           //������ 5�� �� �ڷγ� Ȯ���� ��
        {
           {812, 1113, 2522, 3856, 5411, 6821, 8229},
           {6278, 8211, 10765, 13214, 17442, 18652, 22365},
           {15242, 28512, 31468, 42350, 46578, 48180, 64222},
           {52278, 65872, 72451, 78632, 85147, 86245, 103564},
           {83214, 103675, 165870, 0, 0, 0, 0}
        };            //5�� �޷¿� ���� ���� ���� 2���� �迭�� ����(���߿� for������ Ȯ���� ���� ���ϱ�)

        //�������� 5�� ���Ϻ� Ȯ���ڼ� ���� 2�����迭�� ������ ���� ���
        printf("\n\n\n                            5�� ���Ϻ� Ȯ���� ��                 (����:��)\n");
        printf("         ��         ��        ȭ        ��        ��         ��        ��         \n");
        printf("1����    %d       %d      %d      %d       %d       %d     %d         \n", mayseoul[0][0], mayseoul[0][1], mayseoul[0][2], mayseoul[0][3], mayseoul[0][4], mayseoul[0][5], mayseoul[0][6]);
        printf("2����    %d      %d      %d     %d     %d      %d     %d         \n", mayseoul[1][0], mayseoul[1][1], mayseoul[1][2], mayseoul[1][3], mayseoul[1][4], mayseoul[1][5], mayseoul[1][6]);
        printf("3����    %d     %d     %d     %d     %d      %d     %d         \n", mayseoul[2][0], mayseoul[2][1], mayseoul[2][2], mayseoul[2][3], mayseoul[2][4], mayseoul[2][5], mayseoul[2][6]);
        printf("4����    %d     %d     %d     %d     %d      %d     %d         \n", mayseoul[3][0], mayseoul[3][1], mayseoul[3][2], mayseoul[3][3], mayseoul[3][4], mayseoul[3][5], mayseoul[3][6]);
        printf("5����    %d     %d    %d       %d         %d          %d         %d         \n\n", mayseoul[4][0], mayseoul[4][1], mayseoul[4][2], mayseoul[4][3], mayseoul[4][4], mayseoul[4][5], mayseoul[4][6]);

        printf("5���� 1���� �Ͽ��Ϻ��� 5���� ȭ���ϱ��� �Դϴ�.\n\n");

        printf("������ Ȯ���ڼ� ���� ���̴� ������ �����ϴ�.\n");

        //������������ �� �������� ������ �ٲ𶧸��� Ȯ���ڼ� ���� �߼��� Ȯ���ϱ� ���� �Լ�
        int differenceseoul[5][6] = { 0 };                     //������ ������ ���������� Ȯ���� �� ���̸� 2���� �迭�� ����
        increase(differenceseoul, mayseoul);            //�Լ� ���

        //�迭 �����ͷ� �� ������ �� Ȯ���� ������
        printf("\n�� ������ �� Ȯ���� �������� ������ �����ϴ�.\n");
        int a[5] = { 7417, 16087, 48980, 51286, 82656 };
        int(*pa)[5];
        pa = &a;
        for (int x = 0; x < 5; x++)
            printf("\n%d���� �� ������ : %d��\n", x + 1, (*pa)[x]);


        //���� �������� �ڷγ��� ���� ����ڼ� Ȯ��
        printf("\n5�� �Ѵ޵��� ���￡�� �ڷγ��� ���� ����� ���� Ȯ���ϰ� �����ø� yes�� �Է��ϼ���.\n");
        printf("���� ���� �����ø� no�� �Է��ϼ���.\n");
        gets(select);
        tolower(select);
        if (strcmp("yes", select) == 0)
            printf("5�� �Ѵ޵��� ���￡�� �ڷγ��� ���� ����� ����� ���� %d���Դϴ�.\n", seoul.deathcount);
        else if (strcmp("no", select) == 0)
        {
            printf("�˰ڽ��ϴ�.\n");
        }



    }
    else if (strcmp("gyeonggi", region) == 0)
    {
        int maygyeonggi[5][7] =           //��⵵�� 5�� �� �ڷγ� Ȯ���� ��
        {
           {547, 845, 916, 1248, 1430, 1511, 2113},
           {1421, 2163, 3278, 6457, 8130, 9239, 12469},
           {7685, 8751, 12456, 15874, 18956, 20322, 23978},
           {18969, 19985, 26547, 27453, 29168, 45874, 52179},
           {43587, 85472, 113698, 0, 0, 0, 0}
        };            //5�� �޷¿� ���� ���� ���� 2���� �迭�� ����(���߿� for������ Ȯ���� ���� ���ϱ�)

        //������� 5�� ���Ϻ� Ȯ���ڼ� ���� 2�����迭�� ������ ���� ���
        printf("\n\n\n                               5�� ���Ϻ� Ȯ���� ��                 (����:��)\n");
        printf("         ��          ��       ȭ         ��       ��         ��        ��         \n");
        printf("1����    %d        %d       %d       %d     %d       %d      %d         \n", maygyeonggi[0][0], maygyeonggi[0][1], maygyeonggi[0][2], maygyeonggi[0][3], maygyeonggi[0][4], maygyeonggi[0][5], maygyeonggi[0][6]);
        printf("2����    %d       %d     %d       %d     %d       %d     %d         \n", maygyeonggi[1][0], maygyeonggi[1][1], maygyeonggi[1][2], maygyeonggi[1][3], maygyeonggi[1][4], maygyeonggi[1][5], maygyeonggi[1][6]);
        printf("3����    %d       %d     %d     %d     %d     %d     %d         \n", maygyeonggi[2][0], maygyeonggi[2][1], maygyeonggi[2][2], maygyeonggi[2][3], maygyeonggi[2][4], maygyeonggi[2][5], maygyeonggi[2][6]);
        printf("4����    %d     %d     %d     %d     %d     %d     %d         \n", maygyeonggi[3][0], maygyeonggi[3][1], maygyeonggi[3][2], maygyeonggi[3][3], maygyeonggi[3][4], maygyeonggi[3][5], maygyeonggi[3][6]);
        printf("5����    %d     %d     %d      %d         %d         %d         %d         \n", maygyeonggi[4][0], maygyeonggi[4][1], maygyeonggi[4][2], maygyeonggi[4][3], maygyeonggi[4][4], maygyeonggi[4][5], maygyeonggi[4][6]);

        printf("5���� 1���� �Ͽ��Ϻ��� 5���� ȭ���ϱ��� �Դϴ�.");

        printf("������ Ȯ���ڼ� ���� ���̴� ������ �����ϴ�.\n");

        //����������� �� �������� ������ �ٲ𶧸��� Ȯ���ڼ� ���� �߼��� Ȯ���ϱ� ���� �Լ�
        int differencegyeonggi[5][6] = { 0 };
        increase(differencegyeonggi, maygyeonggi);

        //�迭 �����ͷ� �� ������ �� Ȯ���� ������
        printf("\n�� ������ �� Ȯ���� �������� ������ �����ϴ�.\n");
        int b[5] = { 1566, 11048, 16293, 33210, 70111 };
        int(*pb)[5];
        pb = &b;
        for (int y = 0; y < 5; y++)
            printf("\n%d���� �� ������ : %d��\n", y + 1, (*pb)[y]);

        //��⵵ �������� �ڷγ��� ���� ����ڼ� Ȯ��
        printf("\n5�� �Ѵ޵��� ��⵵ �������� �ڷγ��� ���� ����� ���� Ȯ���ϰ� �����ø� yes�� �Է��ϼ���.\n");
        printf("���� ���� �����ø� no�� �Է��ϼ���.\n");
        gets(select);
        tolower(select);
        if (strcmp("yes", select) == 0)
            printf("5�� �Ѵ޵��� ��� �������� �ڷγ��� ���� ����� ����� ���� %d���Դϴ�.", seoul.deathcount);
        else if (strcmp("no", select) == 0)
            printf("�˰ڽ��ϴ�.");

    }
    else
        printf("�߸� �Է� �ϼ̽��ϴ�.");


    return 0;
}