#include <iostream>
#include <vector>


using namespace std;

int main()
{
    int width, height;

    cout << "���� ���̸� �Է��ϼ���: ";
    cin >> width;

    cout << "���� ���̸� �Է��ϼ���: ";
    cin >> height;


    vector<pair<int, int>> map;


    // ��� �׵θ� ���
    for (int i = 0; i < width + 2; i++)
    {
        cout << "��";
    }
    cout << endl;

    // ���ڸ� ���
    for (int i = 0; i < height; i++)
    {
        cout << "��";
        for (int j = 0; j < width; j++)
        {
            //cout << "��";
            map.push_back(make_pair(i,j));
         /*   map[i][j].*/



        }
        cout << "��" << endl;
    }

    // �ϴ� �׵θ� ���
    for (int i = 0; i < width + 2; i++)
    {
        cout << "��";
    }
    cout << endl;

    return 0;
}