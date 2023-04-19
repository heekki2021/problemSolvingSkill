#include <iostream>
#include <queue>
#include <vector>
#include "Node.cpp"

using namespace std;


vector<MapCoord> directions = { MapCoord(-1, 0), MapCoord(1, 0), MapCoord(0, -1), MapCoord(0, 1) };

bool isValid(int x, int y, int size_row, int size_column, const vector<vector<MapCoord::NodeStatus>>& a) {
	return (x >= 0 && y >= 0 && x < size_row && y < size_column && a[x][y] == MapCoord::NodeStatus::EMPTY);
}



//void bfs(mapcoord enemy, mapcoord player, int size_row, int size_column, vector<vector<mapcoord::nodestatus>>& a, vector<vector<pair<int, int>>>& prev) {
//    
//    
//    vector<vector<bool>> visited;
//    visited.resize(size_row, vector<bool>(size_column, false));
//
//    queue<mapcoord> q;
//    q.push(enemy);
//    visited[enemy.getx()][enemy.gety()] = true;
//
//    while (!q.empty()) {
//        mapcoord currentnode = q.front();
//        q.pop();
//
//        if ((currentnode.getx() == player.getx()) && (currentnode.gety() == player.gety())) {
//            break;
//        }
//
//        for (const auto& direction : directions) {
//            int newx = currentnode.getx() + direction.getx();
//            int newy = currentnode.gety() + direction.gety();
//
//            if (isvalid(newx, newy, size_row, size_column, a) && !visited[newx][newy]) {
//                q.push(mapcoord(newx, newy));
//                visited[newx][newy] = true;
//                prev[newx][newy] = { currentnode.getx(), currentnode.gety() };
//            }
//        }
//    }
//}

void bfs(MapCoord Enemy, MapCoord Player, int size_row,int size_column) {
	


	vector<vector<MapCoord::NodeStatus>> a;
	a.resize(size_row, vector<MapCoord::NodeStatus>(size_column, MapCoord::NodeStatus::EMPTY)); //??
	vector<vector<bool>> visited;
	visited.resize(size_row, vector<bool>(size_column, false));


	queue<MapCoord> q;
	q.push(Enemy);
	visited[Enemy.getX()][Enemy.getY()] = true;

	while (!q.empty()) {
		MapCoord currentNode = q.front();
		q.pop();
		if ((currentNode.getX() == Player.getX()) && (currentNode.getY() == Player.getY())) {
			break;
		}

		for (const auto& direction : directions) {
			int newX = currentNode.getX() + direction.getX();
			int newY = currentNode.getY() + direction.getY();

			if (isValid(newX, newY, size_row, size_column, a) && !visited[newX][newY]) {
				q.push(MapCoord(newX, newY));
				visited[newX][newY] = true;

		}
		}
	}
}


//
//int number = 7; // 원소의 개수 7개
//int c[8];//checked라는 의미로써 방문을 하였다는 의미
//vector<int> a[8]; //1부터 7까지 index를 처리할수 있도록 하기위해서 8개만큼의 공간 할당
//
//void bfs(int start) {
//	queue<int> q;     // queue 공간 생성
//	q.push(start);  // 노드 첫 값을 집어넣음
//	c[start] = true; //queue에 들어간 값은 방문 처리
//	while (!q.empty()) {    //queue가 empty가 될때까지 반복
//		int wut = q.front();   //wut이라는 변수에 큐에서 가장 앞쪽의 값을 할당
//		q.pop();   //가장 앞쪽의 값을 삭제
//		printf("%d", wut);   //가장 앞쪽의 값을 할당한 wut을 출력 
//		for (int i = 0; i < a[wut].size(); i++) {
//			int y = a[wut][i];
//			if (!c[y]) {
//				q.push(y);
//				c[y] = true;
//			}
//		}
//	}
//}
//
//int main(void) { 
//
//
//	a[1].push_back(2);
//	a[2].push_back(1);
//
//	a[1].push_back(3);
//	a[3].push_back(1);
//
//	a[2].push_back(3);
//	a[3].push_back(2);
//
//	a[2].push_back(4);
//	a[4].push_back(2);
//
//	a[2].push_back(5);
//	a[5].push_back(2);
//
//	a[3].push_back(6);
//	a[6].push_back(3);
//
//	a[6].push_back(7);
//	a[7].push_back(6);
//
//	bfs(1);
//
//	return 0;
//
//
//
//}