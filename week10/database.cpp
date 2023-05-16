#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {

	std::locale::global(std::locale("ko_KR.utf8"));

	std::ifstream file1("input.txt");
	
	if (!file1) {
		std::cout << "파일을 열 수 없습니다." << std::endl;
		return 1;
	}

	std::string formatStr, dataStr;

	//두 줄 읽기
	std::getline(file1, formatStr);
	std::getline(file1, dataStr);

	file1.close();

	std::cout << "Format string: " << formatStr << std::endl;
	std::cout << "Data string: " << dataStr << std::endl;

	
	
}