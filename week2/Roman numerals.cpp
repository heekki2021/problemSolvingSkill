#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <conio.h>
#include <windows.h>
#include <thread>
#include <atomic>

std::string intToRoman(int num) {
    std::vector<std::pair<int, std::string>> roman = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"},
    };

    std::string result;
    for (auto& pair : roman) {
        while (num >= pair.first) {
            result += pair.second;
            num -= pair.first;
        }
    }

    return result;
}

std::atomic<bool> exit_program(false);

void check_for_esc() {
    while (!exit_program) {
        if (_kbhit() && _getch() == 27) { // 27 is the ASCII value of the ESC key
            exit_program = true;
        }
        Sleep(100);
    }
}

int main() {
    std::thread esc_thread(check_for_esc);
    std::string input;

    while (!exit_program) {
        std::cout << "������ �Է��ϼ��� (1-3999, �����Ϸ��� ESC�� ��������): ";
        std::getline(std::cin, input);

        if (exit_program) {
            break;
        }

        std::stringstream ss(input);
        int number;
        if (ss >> number) {
            if (number >= 1 && number <= 3999) {
                std::string roman = intToRoman(number);
                std::cout << "�θ� ����: " << roman << std::endl;
            }
            else {
                std::cout << "��ȿ�� ������ ������ �Է����ּ���." << std::endl;
            }
        }
        else {
            std::cout << "�߸��� �Է��Դϴ�. ������ �Է����ּ���." << std::endl;
        }
    }

    esc_thread.join();
    return 0;
}