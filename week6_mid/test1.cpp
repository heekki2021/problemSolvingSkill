#include <iostream>

using namespace std;

int main()
{
    int width, height;

    cout << "가로 길이를 입력하세요: ";
    cin >> width;

    cout << "세로 길이를 입력하세요: ";
    cin >> height;

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
            cout << "◇";
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