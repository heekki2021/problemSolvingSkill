#include <iostream>

using namespace std;

int main()
{
    int width, height;

    cout << "���� ���̸� �Է��ϼ���: ";
    cin >> width;

    cout << "���� ���̸� �Է��ϼ���: ";
    cin >> height;

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
            cout << "��";
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