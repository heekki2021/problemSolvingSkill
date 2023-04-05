//#include <iostream>
//#include <queue>
//#include <vector>
//#include <random>
//
//using namespace std;
//
//const int N = 6;
//char map[N][N];
//
//struct Pos {
//    int x, y;
//};
//
//int bfs(Pos start, Pos end) {
//    const int dx[4] = { 0, 0, 1, -1 };
//    const int dy[4] = { 1, -1, 0, 0 };
//
//    queue<Pos> q;
//    vector<vector<int>> dist(N, vector<int>(N, -1));
//
//    q.push(start);
//    dist[start.x][start.y] = 0;
//
//    while (!q.empty()) {
//        Pos cur = q.front(); q.pop();
//
//        if (cur.x == end.x && cur.y == end.y) {
//            return dist[cur.x][cur.y];
//        }
//
//        for (int dir = 0; dir < 4; dir++) {
//            int nx = cur.x + dx[dir];
//            int ny = cur.y + dy[dir];
//
//            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
//            if (map[nx][ny] == '#') continue;
//            if (dist[nx][ny] != -1) continue;
//
//            dist[nx][ny] = dist[cur.x][cur.y] + 1;
//            q.push({ nx, ny });
//        }
//    }
//
//    return -1;
//}
//
//int main() {
//    // ���� ���� �ʱ�ȭ
//    random_device rd;
//    mt19937 gen(rd());
//    uniform_int_distribution<int> dis(0, N - 1);
//
//    // �� �ʱ�ȭ
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            map[i][j] = '.';
//        }
//    }
//
//    // ���� �÷��̾� ���� ��ġ
//    Pos player = { dis(gen), dis(gen) };
//    Pos enemy = { dis(gen), dis(gen) };
//    while (player.x == enemy.x && player.y == enemy.y) {
//        enemy = { dis(gen), dis(gen) };
//    }
//    map[player.x][player.y] = 'P';
//    map[enemy.x][enemy.y] = 'E';
//
//    // �ִ� �Ÿ� ���
//    int dist = bfs(enemy, player);
//
//    // �ִ� �Ÿ� ���
//    cout << "Shortest Distance: " << dist << endl;
//
//    // �� ���
//    cout << endl;
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            cout << map[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    return 0;
//}
#include <iostream>
#include <vector>
using namespace std;

const int N = 7; // �ٵ����� ũ��
char map[N][N]; // �ٵ���

int main() {
    // �ٵ��� �ʱ�ȭ
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 || i == N - 1 || j == 0 || j == N - 1) {
                map[i][j] = '*'; // �׵θ����� '*'�� ǥ��
            }
            else {
                map[i][j] = '.'; // �������� '.'�� ǥ��
            }
        }
    }

    // �ٵ��� ���
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}