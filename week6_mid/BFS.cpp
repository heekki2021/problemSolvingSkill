#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7; // ������ ���� 7��
int c[8];//checked��� �ǹ̷ν� �湮�� �Ͽ��ٴ� �ǹ�
vector<int> a[8]; //1���� 7���� index�� ó���Ҽ� �ֵ��� �ϱ����ؼ� 8����ŭ�� ���� �Ҵ�

void bfs(int start) {
	queue<int> q;     // queue ���� ����
	q.push(start);  // ��� ù ���� �������
	c[start] = true; //queue�� �� ���� �湮 ó��
	while (!q.empty()) {    //queue�� empty�� �ɶ����� �ݺ�
		int wut = q.front();   //wut�̶�� ������ ť���� ���� ������ ���� �Ҵ�
		q.pop();   //���� ������ ���� ����
		printf("%d", wut);   //���� ������ ���� �Ҵ��� wut�� ��� 
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