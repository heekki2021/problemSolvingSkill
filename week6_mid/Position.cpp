#include <iostream>
#include <string>

using namespace std;



enum class Object {
	Player,
	Enemy,
	Wall,
	Ground
};

class Map_coord {

	Object thisObject = 

public:
	Map_coord(int coordX, int coordY) : coordX_(coordX), coordY_(coordY){}					

private:
	int coordX_;
	int coordY_;
};