#include "Node.cpp"

#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<MapCoord> MapCoords;

	int size_row;
	int size_column;
	cout << "맵의 크기(가로 X 세로)를 입력해 주세요" << endl;
	//맵 최소 크기 예외 처리 해주기-------------------------------------------------------------------
	cout << "가로 - ";
	cin >> size_row;

	cout << "세로 - ";
	cin >> size_column;




	//int** MapPos_Arr = new int*[size_row];
	//for (int i = 0; i < size_row; i++) {
	//	MapPos_Arr[i] = new int[size_column];
	//}
	//

	//맵 출력 
	//맵의 공백 부분은 ◇
	//맵의 테두리는 ♤

	for (int i = 0; i < size_row + 2; i++) {
		cout << "♤";
	}

	cout << endl;

	for (int j = 0; j < size_column; j++) {
		cout << "♤";
		for (int i = 0; i < size_row; i++) {
			/*cout << "◇";*/
			MapCoords.push_back(MapCoord(i, j, ));
		}
		cout << "♤";

		cout << endl;

	}

	for (int i = 0; i < size_row + 2; i++) {
		cout << "♤";
	}

}