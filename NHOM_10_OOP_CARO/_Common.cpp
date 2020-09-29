#include "_Common.h"
#include <iostream>
using namespace std;
void _Common::gotoXY(int pX, int pY) {
	COORD coord;
	coord.X = pX;
	coord.Y = pY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void _Common::fixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);

}

void _Common::Nocursortype(bool a)
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = a;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void _Common::txtColor(int x) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}

void _Common::setFontSize(int FontSize)
{
	CONSOLE_FONT_INFOEX info = { 0 };
	info.cbSize = sizeof(info);
	info.dwFontSize.Y = FontSize;
	info.FontWeight = FW_NORMAL;
	wcscpy_s(info.FaceName, L"Lucida Console");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
}

void _Common::printCaro(int px, int py)
{
	_Common::txtColor(10);
	_Common::gotoXY(px, py);
	printf("%c", 218);
	for (int i = 0; i < 81; i++)
	{
		printf("%c", 196);
	}
	printf("%c", 191);
	_Common::gotoXY(px, py + 1);	cout << (char)179 << "     ooo     ooo    oooo      ooo           ooo     ooo    o   o      ooooo      " << (char)179;
	_Common::txtColor(11);
	_Common::gotoXY(px, py + 2);	cout << (char)179 << "    o   o   o   o   o   o   o    o         o   o   o   o   oo oo      o          " << (char)179;
	_Common::txtColor(12);
	_Common::gotoXY(px, py + 3);	cout << (char)179 << "    o       o   o   o   o   o    o         o       o   o   o o o      o          " << (char)179;
	_Common::txtColor(13);
	_Common::gotoXY(px, py + 4);	cout << (char)179 << "    o       ooooo   oooo    o    o         o       ooooo   o o o      ooo        " << (char)179;
	_Common::txtColor(12);
	_Common::gotoXY(px, py + 5);	cout << (char)179 << "    o       o   o   o o     o    o         o  oo   o   o   o   o      o          " << (char)179;
	_Common::txtColor(11);
	_Common::gotoXY(px, py + 6);	cout << (char)179 << "    o   o   o   o   o  o    o    o         o       o   o   o   o      o          " << (char)179;
	_Common::txtColor(10);
	_Common::gotoXY(px, py + 7);	cout << (char)179 << "     ooo    o   o   o   o    ooo            ooo    o   o   o   o      oooooo     " << (char)179;
	_Common::gotoXY(px, py + 8);
	printf("%c", 192);
	for (int i = 0; i < 81; i++)
	{
		printf("%c", 196);
	}
	printf("%c", 217);
	_Common::txtColor(112);
}

void _Common::printWin(int px, int py, int n)
{
	//XOA 
	_Common::gotoXY(px - 1, py - 1);
	cout << "                                                          ";
	_Common::gotoXY(px - 1, py);
	cout << "                                                          ";
	_Common::gotoXY(px - 1, py + 1); 
	cout << "                                                          ";
	_Common::gotoXY(px - 1, py + 2);
	cout << "                                                          ";
	_Common::gotoXY(px - 1, py + 3); 
	cout << "                                                          ";
	_Common::gotoXY(px - 1, py + 4);
	cout << "                                                          ";
	_Common::gotoXY(px - 1, py + 5);
	cout << "                                                          ";
	_Common::gotoXY(px - 1, py + 6);
	cout << "                                                          ";
	_Common::gotoXY(px - 1, py + 7);
	cout << "                                                          ";
	//Ke khung
	_Common::gotoXY(px - 2, py - 1);
	printf("%c", 218);
	for (int i = 0; i < 58; i++)
		printf("%c", 196);
	printf("%c", 191);
	//Ke gach duoi
	_Common::gotoXY(px - 2, py + 8);
	printf("%c", 192);
	for (int i = 0; i < 58; i++)
	{
		printf("%c", 196);
	}
	printf("%c", 217);
	//ke 2 ben
	for (int i = 1; i < 9; i++)
	{
		_Common::gotoXY(px - 2, py - 1 + i);
		printf("%c", 179);
		_Common::gotoXY(px + 57, py - 1 + i);
		printf("%c", 179);
	}

	if (n == 0)
	{
		_Common::gotoXY(px, py);
		cout << "oooo    oooo  oooo              ooooo  oooo  ooo    ooo";
		_Common::gotoXY(px, py + 1);
		cout << " oooo  oooo    oooo    ooooo   ooooo   oooo  ooooo  ooo";
		_Common::gotoXY(px, py + 2);
		cout << "  oooooooo      oooo  ooooooo ooooo    oooo  oooooooooo";
		_Common::gotoXY(px, py + 3);
		cout << "  oooooooo       oooooooo oooooooo     oooo  ooo oooooo";
		_Common::gotoXY(px, py + 4);
		cout << " oooo  oooo       oooooo   oooooo      oooo  ooo  ooooo";
		_Common::gotoXY(px, py + 5);
		cout << "oooo    oooo       oooo     oooo       oooo  ooo    ooo";
		_Common::gotoXY(px + 15, py + 7);
		cout << " Press Y to continue ";
		do {
			Sleep(400);
			_Common::gotoXY(px, py);
			cout << "oooo    oooo  oooo              ooooo  oooo  ooo    ooo";
			_Common::gotoXY(px, py + 1);
			cout << " oooo  oooo    oooo    ooooo   ooooo   oooo  ooooo  ooo";
			_Common::gotoXY(px, py + 2);
			cout << "  oooooooo      oooo  ooooooo ooooo    oooo  oooooooooo";
			_Common::gotoXY(px, py + 3);
			cout << "  oooooooo       oooooooo oooooooo     oooo  ooo oooooo";
			_Common::gotoXY(px, py + 4);
			cout << " oooo  oooo       oooooo   oooooo      oooo  ooo  ooooo";
			_Common::gotoXY(px, py + 5);
			cout << "oooo    oooo       oooo     oooo       oooo  ooo    ooo";
			_Common::gotoXY(px - 1, py);
			Sleep(400);
			cout << "                                                          ";
			_Common::gotoXY(px - 1, py + 1);
			cout << "                                                          ";
			_Common::gotoXY(px - 1, py + 2);
			cout << "                                                          ";
			_Common::gotoXY(px - 1, py + 3);
			cout << "                                                          ";
			_Common::gotoXY(px - 1, py + 4);
			cout << "                                                          ";
			_Common::gotoXY(px - 1, py + 5);
			cout << "                                                          ";
			_Common::gotoXY(px - 1, py + 6);
			cout << "                                                          ";
		
		} while (!_kbhit());
	}
	if (n == 1)
	{
		_Common::gotoXY(px, py);
		cout << " ooooooooo     ooooo           ooooo  oooo  oooo   oooo";
		_Common::gotoXY(px, py + 1);
		cout << "ooooooooooo     ooooo   ooo   ooooo   oooo  ooooo  oooo";
		_Common::gotoXY(px, py + 2);
		cout << "oooo   oooo      ooooo ooooo ooooo    oooo  oooooo oooo";
		_Common::gotoXY(px, py + 3);
		cout << "oooo   oooo       ooooooooooooooo     oooo  oooo oooooo";
		_Common::gotoXY(px, py + 4);
		cout << "ooooooooooo        ooooo ooooooo      oooo  oooo  ooooo";
		_Common::gotoXY(px, py + 5);
		cout << " ooooooooo          oooo   oooo       oooo  oooo   oooo";
		_Common::gotoXY(px + 15, py + 7);
		cout << " Press Y to continue ";
		do {
			Sleep(400);
			_Common::gotoXY(px, py);
			cout << " ooooooooo     ooooo           ooooo  oooo  oooo   oooo";
			_Common::gotoXY(px, py + 1);
			cout << "ooooooooooo     ooooo   ooo   ooooo   oooo  ooooo  oooo";
			_Common::gotoXY(px, py + 2);
			cout << "oooo   oooo      ooooo ooooo ooooo    oooo  oooooo oooo";
			_Common::gotoXY(px, py + 3);
			cout << "oooo   oooo       ooooooooooooooo     oooo  oooo oooooo";
			_Common::gotoXY(px, py + 4);
			cout << "ooooooooooo        ooooo ooooooo      oooo  oooo  ooooo";
			_Common::gotoXY(px, py + 5);
			cout << " ooooooooo          oooo   oooo       oooo  oooo   oooo";
			_Common::gotoXY(px + 15, py + 7);
			_Common::gotoXY(px - 1, py);
			Sleep(400);
			cout << "                                                          ";
			_Common::gotoXY(px - 1, py + 1);
			cout << "                                                          ";
			_Common::gotoXY(px - 1, py + 2);
			cout << "                                                          ";
			_Common::gotoXY(px - 1, py + 3);
			cout << "                                                          ";
			_Common::gotoXY(px - 1, py + 4);
			cout << "                                                          ";
			_Common::gotoXY(px - 1, py + 5);
			cout << "                                                          ";
			_Common::gotoXY(px - 1, py + 6);
			cout << "                                                          ";
		} while (!_kbhit());
	}
}


void _Common::printXO(int px, int py, int n)
{
	if (n == 0)
	{
		_Common::gotoXY(px, py);
		cout << "oooo    oooo";
		_Common::gotoXY(px, py + 1);
		cout << " oooo  oooo";
		_Common::gotoXY(px, py + 2);
		cout << "  oooooooo";
		_Common::gotoXY(px, py + 3);
		cout << "  oooooooo";
		_Common::gotoXY(px, py + 4);
		cout << " oooo  oooo";
		_Common::gotoXY(px, py + 5);
		cout << "oooo    oooo";
	}
	if (n == 1)
	{
		_Common::gotoXY(px, py);
		cout << " ooooooooo";
		_Common::gotoXY(px, py + 1);
		cout << "ooooooooooo";
		_Common::gotoXY(px, py + 2);
		cout << "oooo   oooo";
		_Common::gotoXY(px, py + 3);
		cout << "oooo   oooo";
		_Common::gotoXY(px, py + 4);
		cout << "ooooooooooo";
		_Common::gotoXY(px, py + 5);
		cout << " ooooooooo";
	}
}

/*_Common::gotoXY(px, py);
		cout << "oooo    oooo  oooo              ooooo  oooo  ooo    ooo";
		cout << " oooo  oooo    oooo    ooooo   ooooo   oooo  ooooo  ooo";
		cout << "  oooooooo      oooo  ooooooo ooooo    oooo  oooooooooo";
		cout << "  oooooooo       oooooooo oooooooo     oooo  ooo oooooo";
		cout << " oooo  oooo       oooooo   oooooo      oooo  ooo  ooooo";
		cout << "oooo    oooo       oooo     oooo       oooo  ooo    ooo";
		cout << " Press Y to continue ";*/

		/*_Common::gotoXY(px, py);
				cout << " ooooooooo   ooooo           ooooo  oooo  oooo   oooo";
				cout << "ooooooooooo   ooooo   ooo   ooooo   oooo  ooooo  oooo";
				cout << "oooo   oooo    ooooo ooooo ooooo    oooo  oooooo oooo";
				cout << "oooo   oooo     ooooooooooooooo     oooo  oooo oooooo";
				cout << "ooooooooooo      ooooo ooooooo      oooo  oooo  ooooo";
				cout << " ooooooooo        oooo   oooo       oooo  oooo   oooo";*/