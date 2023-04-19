#include <iostream>

using namespace std;

class MapCoord {
public:
    enum class NodeStatus {
        ENEMY,
        EMPTY,
        Wall,
        PLAYER,
        VISITED,
        PATH
    };

    //MapCoord() : x_(0), y_(0), status_(NodeStatus::EMPTY) {}


    MapCoord(int x, int y, NodeStatus status = NodeStatus::EMPTY)
        : x_(x), y_(y), status_(status) {}

    // ��ǥ�� ���� getter�� setter
    int getX() const { return x_; }
    int getY() const { return y_; }
    void setX(int x) { x_ = x; }
    void setY(int y) { y_ = y; }

    // ���¿� ���� getter�� setter
    NodeStatus getStatus() const { return status_; }
    void setStatus(NodeStatus status) { status_ = status; }

    void printCoordIcon(NodeStatus s) {
        switch (s) {
        case NodeStatus::EMPTY:
            cout << "\033[93m��\033[0m";
            break; 
        case NodeStatus::ENEMY:

            cout << "\033[31m��\033[0m";
            break;

        case NodeStatus::PLAYER:

            cout << "\033[32m��\033[0m";
            break;
        
        case NodeStatus::Wall:

            cout << "\033[90m��\033[0m";
            break;
        //default:
        //    // ��� case�� ��ġ���� �ʴ� ��� ������ �ڵ�
        //    break;
        }
    }

private:
    int x_;
    int y_;
    NodeStatus status_;
};


