#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAX_LINE_LENGTH 1024

int main() {
	//파일을 읽기 모드로 열기
	FILE* file1 = fopen("input.txt", "r");
	if (file1 == NULL) {
		printf("파일을 열지 못하였습니다\n");
		return 1;
	}

	char line[MAX_LINE_LENGTH];

	//파일의 각 줄을 읽어와서 출력하기
	while (fgets(line, sizeof(line), file1)) {
		printf("%s", line);
	}

	fclose(file1);
	return 0;
}

