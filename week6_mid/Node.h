#pragma once

#include <iostream>
#include <queue>
#include <vector>
#include "Node.cpp"

using namespace std;

// �̵� ������ ������ �����ϴ� ����
extern vector<MapCoord> directions;

// ��ǥ�� �迭�� ũ�⸦ �޾� ��ȿ�� ��ǥ���� Ȯ���ϴ� �Լ�
bool isValid(int x, int y, int size_row, int size_column, const vector<vector<MapCoord::NodeStatus>>& a);

// BFS �˰����� �̿��� ���� �÷��̾� ������ �ִ� �Ÿ��� ���ϴ� �Լ�
void bfs(MapCoord Enemy, MapCoord Player, int size_row, int size_column);