#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	FILE* fp;

	fp = fopen("input.txt", "r");
	if (fp == NULL)
	{
		printf("������ �������� �ʽ��ϴ�\n");
		return 0;
	}
	printf("������ ���Ƚ��ϴ�.\n");
	fclose(fp);

	return 0;
}