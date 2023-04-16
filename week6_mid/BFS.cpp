#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7; // 원소의 개수 7개
int c[8];//checked라는 의미로써 방문을 하였다는 의미
vector<int> a[8]; //1부터 7까지 index를 처리할수 있도록 하기위해서 8개만큼의 공간 할당

void bfs(int start) {
	queue<int> q;     // queue 공간 생성
	q.push(start);  // 노드 첫 값을 집어넣음
	c[start] = true; //queue에 들어간 값은 방문 처리
	while (!q.empty()) {    //queue가 empty가 될때까지 반복
		int wut = q.front();   //wut이라는 변수에 큐에서 가장 앞쪽의 값을 할당
		q.pop();   //가장 앞쪽의 값을 삭제
		printf("%d", wut);   //가장 앞쪽의 값을 할당한 wut을 출력 
		for (int i = 0; i < a[wut].size(); i++) {
			int y = a[wut][i];
			if (!c[y]) {
				q.push(y);
				c[y] = true;
			}
		}
	}
}

int main(void) { 


	a[1].push_back(2);
	a[2].push_back(1);

	a[1].push_back(3);
	a[3].push_back(1);

	a[2].push_back(3);
	a[3].push_back(2);

	a[2].push_back(4);
	a[4].push_back(2);

	a[2].push_back(5);
	a[5].push_back(2);

	a[3].push_back(6);
	a[6].push_back(3);

	a[6].push_back(7);
	a[7].push_back(6);

	bfs(1);

	return 0;



}