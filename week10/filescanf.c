#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	FILE* fp;

	fp = fopen("input.txt", "r");
	if (fp == NULL)
	{
		printf("파일이 열려있지 않습니다\n");
		return 0;
	}
	printf("파일이 열렸습니다.\n");
	fclose(fp);

	return 0;
}