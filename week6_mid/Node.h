#pragma once

#include <iostream>
#include <queue>
#include <vector>
#include "Node.cpp"

using namespace std;

// 이동 가능한 방향을 저장하는 벡터
extern vector<MapCoord> directions;

// 좌표와 배열의 크기를 받아 유효한 좌표인지 확인하는 함수
bool isValid(int x, int y, int size_row, int size_column, const vector<vector<MapCoord::NodeStatus>>& a);

// BFS 알고리즘을 이용해 적과 플레이어 사이의 최단 거리를 구하는 함수
void bfs(MapCoord Enemy, MapCoord Player, int size_row, int size_column);