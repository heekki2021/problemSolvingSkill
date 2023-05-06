#include "Node.h"
#include "BFS.h"
#include <iostream>
#include <vector>
using namespace std;

void mapmaking(vector<vector<MapCoord>>& mapCoords, int size_row, int size_column);
//vector<MapCoord> reconstructPath(MapCoord Enemy, MapCoord Player, vector<vector<pair<int, int>>>& prev);

struct Point {
	int x;
	int y;
};

int main() {

	vector<vector<MapCoord>> mapCoords;
	std::cout << "\033[31m��\033[0m" << std::endl;
	std::cout << "\033[93m��\033[0m" << std::endl;
	std::cout << "\033[32m��\033[0m" << std::endl;
	std::cout << "\033[90m��\033[0m" << std::endl;



	int size_row;
	int size_column;
	//int wallCount;

	int EnemyX;
	int EnemyY;

	int PlayerX;
	int PlayerY;

	int WallX;
	int WallY;

	char input;

	vector<Point> walls;
	bool moreWall = true;


	cout << "���� ũ��(���� X ����)�� �Է��� �ּ���" << endl;
	//�� �ּ� ũ�� ���� ó�� ���ֱ�-------------------------------------------------------------------
	cout << "���� - ";
	cin >> size_row;

	cout << "���� - ";
	cin >> size_column;


	//mapCoords.resize(size_row, vector<MapCoord>(size_column));
	mapCoords.resize(size_column+2, vector<MapCoord>(size_row+2, MapCoord(0, 0, MapCoord::NodeStatus::EMPTY)));



	//�� ��� 
	//���� ���� �κ��� ��
	//���� �׵θ��� ��

	for (int i = 0; i < size_row + 2; i++) {
		
		mapCoords[0][i] = MapCoord(0,i, MapCoord::NodeStatus::Wall);
		mapCoords[0][i].printCoordIcon(mapCoords[0][i].getStatus());

	}

	cout << endl;

	for (int j = 0; j < size_column; j++) {

		mapCoords[j][0] = MapCoord(j, 0, MapCoord::NodeStatus::Wall);
		mapCoords[j][0].printCoordIcon(mapCoords[j][0].getStatus());
		for (int i = 0; i < size_row; i++) {

			mapCoords[j][i] = MapCoord(j, i, MapCoord::NodeStatus::EMPTY);
			mapCoords[j][i].printCoordIcon(mapCoords[j][i].getStatus());


		}

		mapCoords[j][size_row + 1] = MapCoord(j, size_row + 1, MapCoord::NodeStatus::Wall);
		mapCoords[j][size_row + 1].printCoordIcon(mapCoords[j][size_row + 1].getStatus());
		cout << endl;


	}

	for (int i = 0; i < size_row + 2; i++) {
		//cout << "��";
		mapCoords[size_column + 1][i] = MapCoord(size_column + 1, i, MapCoord::NodeStatus::Wall);
		mapCoords[size_column + 1][i].printCoordIcon(mapCoords[size_column + 1][i].getStatus());
	}



	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;


	cout << size_row << 'X' << size_column << "ũ���� ���� �����Ͽ����ϴ�." << endl;
	//cout << size_row << "x" << size_column << " ũ���� ���� �����Ͽ����ϴ�." << endl;

	
	cout << "Enemy ��ġ ��ġ" << endl;
	cout << "Enemy X ��ǥ - ";
	cin >> EnemyX;
	EnemyX -= 1;

	cout << "Enemy y ��ǥ - ";
	cin >> EnemyY;
	EnemyY -= 1;
	

	mapCoords[EnemyY][EnemyX].setStatus(MapCoord::NodeStatus::ENEMY);
	mapmaking(mapCoords, size_row, size_column);

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;


	cout << "Player ��ġ ��ġ" << endl;
	cout << "PlayerX ��ǥ - ";

	cin >> PlayerX;
	PlayerX -= 1;

	cout << "PlayerY ��ǥ - ";
	cin >> PlayerY;
	PlayerY -= 1;

	if ((PlayerX != EnemyX) && (PlayerY != EnemyY)) {
		mapCoords[PlayerY][PlayerX].setStatus(MapCoord::NodeStatus::PLAYER);
		mapmaking(mapCoords, size_row, size_column);
	}
	else
	{
		cout << "����ó���� �Ǿ����� ������ ���� PLAYER�� ��ǥ�� ENEMY�� ��ġ�� �ʰ� �ٽ� �����Ͽ� �ּ���";
		cin >> PlayerX;
		PlayerX -= 1;

		cin >> PlayerY;
		PlayerY -= 1;

		mapCoords[PlayerY][PlayerX].setStatus(MapCoord::NodeStatus::PLAYER);
		mapmaking(mapCoords, size_row, size_column);
	}



	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;


	cout << "�� �� Wall�� �����ϰڽ��ϴ�." << endl;

	while (moreWall)
	{

		cout << "Wall ��ġ ��ġ" << endl;

		cout << "WallX - ";
		cin >> WallX;
		cout << "WallY - ";
		cin >> WallY;

		Point p = { WallX, WallY };
		walls.push_back(p);

		mapCoords[p.y - 1][p.x - 1].setStatus(MapCoord::NodeStatus::Wall);
		mapmaking(mapCoords, size_row, size_column);


		cout << endl;
		cout << endl;

		cout << "��� ���� ����Ͻðڽ��ϱ�? (Y/N)" << endl;

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���� ���ڸ� �����մϴ�.
		input = cin.get();

		if (input == 'y' || input == 'Y') {
			cout << "----------- ���� Wall ��ġ -----------"<< endl;
		}
		else if (input == 'n' || input == 'N') {
			cout << "--------- ���� Wall ��ġ ���� ---------" << endl;
			moreWall = false;
		}

	}

	//------------------------------------------------------------------------------------------
	

	
}



void mapmaking(vector<vector<MapCoord>>& mapCoords, int size_row, int size_column)
{


	for (int i = 0; i < size_row + 2; i++) {
		//cout << "��";
		//mapCoords[0][i] = MapCoord(0, i, MapCoord::NodeStatus::Wall);
		mapCoords[0][i].printCoordIcon(mapCoords[0][i].getStatus());

	}

	cout << endl;

	for (int j = 0; j < size_column; j++) {
		//cout << "��";
		//mapCoords[j][0] = MapCoord(j, 0, MapCoord::NodeStatus::Wall);
		mapCoords[j][0].printCoordIcon(mapCoords[j][0].getStatus());
		for (int i = 0; i < size_row; i++) {
			/*cout << "��";*/
			//mapCoords[j][i] = MapCoord(j, i, MapCoord::NodeStatus::EMPTY);
			mapCoords[j][i].printCoordIcon(mapCoords[j][i].getStatus());


		}
		//mapCoords[j][size_row + 1] = MapCoord(j, size_row + 1, MapCoord::NodeStatus::Wall);
		mapCoords[j][size_row + 1].printCoordIcon(mapCoords[j][size_row + 1].getStatus());
		cout << endl;


	}

	for (int i = 0; i < size_row + 2; i++) {
		//cout << "��";
		//mapCoords[size_column + 1][i] = MapCoord(size_column + 1, i, MapCoord::NodeStatus::Wall);
		mapCoords[size_column + 1][i].printCoordIcon(mapCoords[size_column + 1][i].getStatus());
	}

}

