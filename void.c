#include "heder.h"
void increase(int difference[5][6], int month[5][7])                            //��ȯ���� ���� �Լ�(�� �������� ������ �ٲ𶧸��� Ȯ���ڼ� ���� �߼��� Ȯ���ϱ� ���� �Լ�)
{
    for (int i = 0; i < 5; i++)
    {
        printf("\n%d���� Ȯ�� ���� ����\n", i + 1);
        for (int j = 0; j < 6; j++)
        {
            difference[i][j] = month[i][j + 1] - month[i][j];
            printf("%d��° ���� = %d\n", j + 1, difference[i][j]);
        }
    }
}
