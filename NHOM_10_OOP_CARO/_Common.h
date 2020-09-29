#pragma once
#include<Windows.h>
#include<conio.h>
class _Common {
public:
	static void fixConsoleWindow();
	static void gotoXY(int, int);
	static void txtColor(int);
	static void Nocursortype(bool a);
	static void setFontSize(int FontSize);
	static void printCaro(int px, int py);
	static void printWin(int px, int py, int n);
	static void printXO(int px, int py, int n);
};
