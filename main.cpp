#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <ctime>
#include "windows.h"

using namespace std;


void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}


void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void thanh_sang(int x, int y, int w, int h, int b_color, string nd)
{
	textcolor(b_color);
	for (int iy = y + 1; iy <= y + h - 1; iy++)
	{
		for (int ix = x + 1; ix <= x + w - 1; ix++)
		{
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	gotoXY(x + 1, y + 1);
	cout << nd;
}

void menu(){
    cout << "Press Enter to enter";

    int x = 10;
    int y = 2;
    int a = 1;
    thanh_sang(10,2,20,2,75,"      New Game");
    thanh_sang(10,5,20,2,75,"     Load Game");
    thanh_sang(10,8,20,2,75,"     High Score");
    thanh_sang(10,11,20,2,75,"      Setting");
    thanh_sang(10,14,20,2,75,"        Help");
    thanh_sang(10,2,20,2,60,"      New Game");
    while (1){
        if (_kbhit()){
            switch (_getch()){
        case 's':
            switch (a){
            case 1: thanh_sang(10,2,20,2,75,"      New Game");
                    thanh_sang(10,5,20,2,60,"     Load Game");
                    a++;
                    break;
            case 2: thanh_sang(10,5,20,2,75,"     Load Game");
                    thanh_sang(10,8,20,2,60,"     High Score");
                    a++;
                    break;
            case 3: thanh_sang(10,8,20,2,75,"     High Score");
                    thanh_sang(10,11,20,2,60,"      Setting");
                    a++;
                    break;
            case 4: thanh_sang(10,11,20,2,75,"      Setting");
                    thanh_sang(10,14,20,2,60,"        Help");
                    a++;
                    break;
            case 5: thanh_sang(10,14,20,2,75,"        Help");
                    thanh_sang(10,2,20,2,60,"      New Game");
                    a = 1;
                    break;
            };
            break;
        case 'w':
            switch (a){
            case 1: thanh_sang(10,2,20,2,75,"      New Game");
                    thanh_sang(10,14,20,2,60,"        Help");
                    a = 5;
                    break;
            case 2: thanh_sang(10,2,20,2,60,"      New Game");
                    thanh_sang(10,5,20,2,75,"     Load Game");
                    a--;
                    break;
            case 3: thanh_sang(10,5,20,2,60,"     Load Game");
                    thanh_sang(10,8,20,2,75,"     High Score");
                    a--;
                    break;
            case 4: thanh_sang(10,8,20,2,60,"     High Score");
                    thanh_sang(10,11,20,2,75,"      Setting");
                    a--;
                    break;
            case 5: thanh_sang(10,11,20,2,60,"      Setting");
                    thanh_sang(10,14,20,2,75,"        Help");
                    a--;
                    break;
            };
            break;
        case '\r':
            switch (a){
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                break;
            }
        }


    }

}
}

int main()
{
    menu();


    textcolor(1);
        return 0;
}
