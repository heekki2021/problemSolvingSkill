#include <iostream>

class MapCoord {
public:
    enum class NodeStatus {
        EMPTY,
        OBSTACLE,
        START,
        GOAL,
        VISITED,
        PATH
    };

    MapCoord(int x, int y, NodeStatus status = NodeStatus::EMPTY)
        : x_(x), y_(y), status_(status) {}

    // 좌표에 대한 getter와 setter
    int getX() const { return x_; }
    int getY() const { return y_; }
    void setX(int x) { x_ = x; }
    void setY(int y) { y_ = y; }

    // 상태에 대한 getter와 setter
    NodeStatus getStatus() const { return status_; }
    void setStatus(NodeStatus status) { status_ = status; }

private:
    int x_;
    int y_;
    NodeStatus status_;
};

//int main() {
//    Node node1(0, 0, Node::NodeStatus::START);
//    Node node2(1, 1, Node::NodeStatus::GOAL);
//
//    std::cout << "Node 1: (" << node1.getX() << ", " << node1.getY() << "), Status: " << static_cast<int>(node1.getStatus()) << std::endl;
//    std::cout << "Node 2: (" << node2.getX() << ", " << node2.getY() << "), Status: " << static_cast<int>(node2.getStatus()) << std::endl;
//
//    return 0;
//}