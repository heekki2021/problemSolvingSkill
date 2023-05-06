#pragma once 

#include <iostream>
#include <queue>
#include <vector>
#include "Node.cpp"

using namespace std;



vector<MapCoord> directions = { MapCoord(-1, 0), MapCoord(1, 0), MapCoord(0, -1), MapCoord(0, 1) };

bool isValid(int x, int y, int size_row, int size_column, const vector<vector<MapCoord::NodeStatus>>& a) {
	return (x >= 0 && y >= 0 && x < size_row && y < size_column && a[x][y] == MapCoord::NodeStatus::EMPTY);
}



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


