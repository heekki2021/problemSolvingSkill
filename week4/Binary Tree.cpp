#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* right;
	Node* left;
	Node* up;
	Node* down;
	//Node** child;

	//Node() {
	//	child = new Node * [4];
	//	for (int i = 0; i < 4; ++i) {
	//		child[i] = nullptr;
	//	}
	//}

	//~Node() {
	//	delete[] child;
	//}
};

class Tree {
private:
	Node* root;

public:
	// 게터 함수
	Node* getRoot() const {
		return root;
	}

	// 세터 함수
	void setRoot(Node* newRoot) {
		root = newRoot;
	}

	Node* makeNode(Node* right, Node* left, Node* up, Node* down, int data) {
		Node* node = new Node();
		node->data = data;
		node->right = right;
		node->left = left;
		node->up = up;
		node->down = down;
		return node;
	}

};

