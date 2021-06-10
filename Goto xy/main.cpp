#include <iostream>
#include <cstdio>
#include <Windows.h>

using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO cursorInfo;
    GetConsoleScreenBufferInfo(hConsole, &cursorInfo);

    int xCoord = cursorInfo.dwCursorPosition.X;
    int yCoord = cursorInfo.dwCursorPosition.Y;

    for (int i = 0; i < 10; i++) {
        gotoxy(xCoord, yCoord);
        cout << i << "%" << endl;
        Sleep(1000);
    }


    system("pause");
    return 0;
}