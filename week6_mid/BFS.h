#pragma once

#include <iostream>
#include <queue>
#include <vector>
#include "Node.cpp"

using namespace std;

extern vector<MapCoord> directions;

bool isValid(int x, int y, int size_row, int size_column, const vector<vector<MapCoord::NodeStatus>>& a);

void bfs(MapCoord Enemy, MapCoord Player, int size_row, int size_column);