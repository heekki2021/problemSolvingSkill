#include "Node.cpp"

#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<MapCoord> MapCoords;

	int size_row;
	int size_column;
	cout << "���� ũ��(���� X ����)�� �Է��� �ּ���" << endl;
	//�� �ּ� ũ�� ���� ó�� ���ֱ�-------------------------------------------------------------------
	cout << "���� - ";
	cin >> size_row;

	cout << "���� - ";
	cin >> size_column;




	//int** MapPos_Arr = new int*[size_row];
	//for (int i = 0; i < size_row; i++) {
	//	MapPos_Arr[i] = new int[size_column];
	//}
	//

	//�� ��� 
	//���� ���� �κ��� ��
	//���� �׵θ��� ��

	for (int i = 0; i < size_row + 2; i++) {
		cout << "��";
	}

	cout << endl;

	for (int j = 0; j < size_column; j++) {
		cout << "��";
		for (int i = 0; i < size_row; i++) {
			/*cout << "��";*/
			MapCoords.push_back(MapCoord(i, j, ));
		}
		cout << "��";

		cout << endl;

	}

	for (int i = 0; i < size_row + 2; i++) {
		cout << "��";
	}

}