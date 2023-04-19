#include <iostream>
#include <vector>


using namespace std;

int main()
{
    int width, height;

    cout << "가로 길이를 입력하세요: ";
    cin >> width;

    cout << "세로 길이를 입력하세요: ";
    cin >> height;


    vector<pair<int, int>> map;


    // 상단 테두리 출력
    for (int i = 0; i < width + 2; i++)
    {
        cout << "♤";
    }
    cout << endl;

    // 격자맵 출력
    for (int i = 0; i < height; i++)
    {
        cout << "♤";
        for (int j = 0; j < width; j++)
        {
            //cout << "◇";
            map.push_back(make_pair(i,j));
         /*   map[i][j].*/



        }
        cout << "♤" << endl;
    }

    // 하단 테두리 출력
    for (int i = 0; i < width + 2; i++)
    {
        cout << "♤";
    }
    cout << endl;

    return 0;
}