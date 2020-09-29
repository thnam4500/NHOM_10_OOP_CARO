#pragma once
#include<iostream>
using namespace std;
class _Point {
	int _x, _y, _check;
public:
	_Point();
	_Point(int pX, int pY);
	bool setCheck(int pCheck);
	int getX();
	int getY();
	int getCheck();
	void setX(int pX);
	void setY(int pY);
};

