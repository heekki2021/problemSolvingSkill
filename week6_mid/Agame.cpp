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
	std::cout << "\033[31m□\033[0m" << std::endl;
	std::cout << "\033[93m□\033[0m" << std::endl;
	std::cout << "\033[32m□\033[0m" << std::endl;
	std::cout << "\033[90m□\033[0m" << std::endl;



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


	cout << "맵의 크기(가로 X 세로)를 입력해 주세요" << endl;
	//맵 최소 크기 예외 처리 해주기-------------------------------------------------------------------
	cout << "가로 - ";
	cin >> size_row;

	cout << "세로 - ";
	cin >> size_column;


	//mapCoords.resize(size_row, vector<MapCoord>(size_column));
	mapCoords.resize(size_column+2, vector<MapCoord>(size_row+2, MapCoord(0, 0, MapCoord::NodeStatus::EMPTY)));



	//맵 출력 
	//맵의 공백 부분은 ◇
	//맵의 테두리는 ♤

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
		//cout << "♤";
		mapCoords[size_column + 1][i] = MapCoord(size_column + 1, i, MapCoord::NodeStatus::Wall);
		mapCoords[size_column + 1][i].printCoordIcon(mapCoords[size_column + 1][i].getStatus());
	}



	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;


	cout << size_row << 'X' << size_column << "크기의 맵을 생성하였습니다." << endl;
	//cout << size_row << "x" << size_column << " 크기의 맵을 생성하였습니다." << endl;

	
	cout << "Enemy 위치 배치" << endl;
	cout << "Enemy X 좌표 - ";
	cin >> EnemyX;
	EnemyX -= 1;

	cout << "Enemy y 좌표 - ";
	cin >> EnemyY;
	EnemyY -= 1;
	

	mapCoords[EnemyY][EnemyX].setStatus(MapCoord::NodeStatus::ENEMY);
	mapmaking(mapCoords, size_row, size_column);

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;


	cout << "Player 위치 배치" << endl;
	cout << "PlayerX 좌표 - ";

	cin >> PlayerX;
	PlayerX -= 1;

	cout << "PlayerY 좌표 - ";
	cin >> PlayerY;
	PlayerY -= 1;

	if ((PlayerX != EnemyX) && (PlayerY != EnemyY)) {
		mapCoords[PlayerY][PlayerX].setStatus(MapCoord::NodeStatus::PLAYER);
		mapmaking(mapCoords, size_row, size_column);
	}
	else
	{
		cout << "예외처리가 되어있지 않으니 제발 PLAYER의 좌표가 ENEMY와 겹치지 않게 다시 설정하여 주세요";
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


	cout << "맵 상에 Wall을 생성하겠습니다." << endl;

	while (moreWall)
	{

		cout << "Wall 위치 배치" << endl;

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

		cout << "계속 맵을 출력하시겠습니까? (Y/N)" << endl;

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 개행 문자를 무시합니다.
		input = cin.get();

		if (input == 'y' || input == 'Y') {
			cout << "----------- 다음 Wall 배치 -----------"<< endl;
		}
		else if (input == 'n' || input == 'N') {
			cout << "--------- 다음 Wall 배치 종료 ---------" << endl;
			moreWall = false;
		}

	}

	//------------------------------------------------------------------------------------------
	

	
}



void mapmaking(vector<vector<MapCoord>>& mapCoords, int size_row, int size_column)
{


	for (int i = 0; i < size_row + 2; i++) {
		//cout << "♤";
		//mapCoords[0][i] = MapCoord(0, i, MapCoord::NodeStatus::Wall);
		mapCoords[0][i].printCoordIcon(mapCoords[0][i].getStatus());

	}

	cout << endl;

	for (int j = 0; j < size_column; j++) {
		//cout << "♤";
		//mapCoords[j][0] = MapCoord(j, 0, MapCoord::NodeStatus::Wall);
		mapCoords[j][0].printCoordIcon(mapCoords[j][0].getStatus());
		for (int i = 0; i < size_row; i++) {
			/*cout << "◇";*/
			//mapCoords[j][i] = MapCoord(j, i, MapCoord::NodeStatus::EMPTY);
			mapCoords[j][i].printCoordIcon(mapCoords[j][i].getStatus());


		}
		//mapCoords[j][size_row + 1] = MapCoord(j, size_row + 1, MapCoord::NodeStatus::Wall);
		mapCoords[j][size_row + 1].printCoordIcon(mapCoords[j][size_row + 1].getStatus());
		cout << endl;


	}

	for (int i = 0; i < size_row + 2; i++) {
		//cout << "♤";
		//mapCoords[size_column + 1][i] = MapCoord(size_column + 1, i, MapCoord::NodeStatus::Wall);
		mapCoords[size_column + 1][i].printCoordIcon(mapCoords[size_column + 1][i].getStatus());
	}

}

