#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAX_LINE_LENGTH 1024

int main() {
	//������ �б� ���� ����
	FILE* file1 = fopen("input.txt", "r");
	if (file1 == NULL) {
		printf("������ ���� ���Ͽ����ϴ�\n");
		return 1;
	}

	char line[MAX_LINE_LENGTH];

	//������ �� ���� �о�ͼ� ����ϱ�
	while (fgets(line, sizeof(line), file1)) {
		printf("%s", line);
	}

	fclose(file1);
	return 0;
}

