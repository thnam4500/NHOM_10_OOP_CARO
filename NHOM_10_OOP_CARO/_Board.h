#pragma once
#include"_Point.h"
#include"_Common.h"
#include<iostream>
class _Board {
private:
	int _size;
	int _left, _top;
	_Point** _pArr;
	int count;
public:
	_Board(int, int, int);
	~_Board();
	int getSize();
	int getLeft();
	int getTop();
	int getXAt(int, int);
	int getYAt(int, int);
	void resetData();
	void drawBoard();
	int checkBoard(int pX, int pY, bool pTurn);
	int testBoard();
	int ngang();
	int doc();
	int xientren();
	int xienduoi();
	bool isDraw();
	_Point* getElement(int, int);
	void setSize(int);
	int randomCheckBoard(int pX, int pY, bool pTurn);
};

