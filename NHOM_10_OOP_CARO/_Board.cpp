#pragma once
#include "_Board.h"
#include <time.h>
#pragma comment(lib, "Winmm.lib")
int _Board::getSize() { return _size; }
int _Board::getLeft() { return _left; }
int _Board::getTop() { return _top; }
int _Board::getXAt(int i, int j) {
	return _pArr[i][j].getX();
}
int _Board::getYAt(int i, int j) {
	return _pArr[i][j].getY();
}
_Board::_Board(int pSize, int pX, int pY) {
	_size = pSize;
	_left = pX;
	_top = pY;
	int count = 0;
	_pArr = new _Point * [pSize];
	for (int i = 0; i < pSize; i++)
		_pArr[i] = new _Point[pSize];
}
_Board::~_Board() {
	for (int i = 0; i < _size; i++) delete[] _pArr[i];
	delete[] _pArr;
}

void _Board::resetData() {
	if (_size == 0) return; // Phải gọi constructor trước khi resetData
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			_pArr[i][j].setX(4 * j + _left + 2); // Trùng với hoành độ màn hình bàn cờ
			_pArr[i][j].setY(2 * i + _top + 1); // Trùng với tung độ màn hình bàn cờ
			_pArr[i][j].setCheck(0);
		}
	}
}
void _Board::drawBoard() {
	if (_pArr == NULL) return; // phải gọi constructor trước
	//kẻ khung
	_Common::txtColor(113);
	printf("%c", 218);
	for (int i = 0; i < 118; i++)
		if ((i != 4 * _size + 2 + _left) && (i != 4 * _size + 22 + _left))
			printf("%c", 196);
		else printf("%c", 194);
	printf("%c", 191);
	for (int i = 1; i < 29; i++)
	{
		_Common::gotoXY(0, i);
		printf("%c", 179);
		_Common::gotoXY(4 * _size + 3 + _left, i);
		printf("%c", 179);
		_Common::gotoXY(4 * _size + 23 + _left, i);
		printf("%c", 179);
		_Common::gotoXY(119, i);
		printf("%c", 179);
	}
	printf("%c", 192);
	for (int i = 0; i < 118; i++)
		if ((i != 4 * _size + 2 + _left) && (i != 4 * _size + 22 + _left))
			printf("%c", 196);
		else printf("%c", 193);
	printf("%c", 217);
	//kẻ ngang ô game
	_Common::gotoXY(4 * _size + 3 + _left, 12);
	printf("%c", 195);
	for (int i = 0; i < 19; i++)
		printf("%c", 196);
	printf("%c", 180);
	_Common::gotoXY(4 * _size + 3 + _left, 17);
	printf("%c", 195);
	for (int i = 0; i < 19; i++)
		printf("%c", 196);
	printf("%c", 180);
	//Kẻ phân cách smallmenu
	_Common::gotoXY(4 * _size + 23 + _left, 15);
	printf("%c", 195);
	for (int i = 0; i < 39; i++)
		printf("%c", 196);
	printf("%c", 180);
	//kẻ trên
	_Common::gotoXY(_left, _top);
	printf("%c", 218);
	for (int i = 0; i < 4 * _size - 1; i++)
	{
		if (i % 4 == 3)
			printf("%c", 194);
		else
			printf("%c", 196);
	}

	printf("%c", 191);
	//kẻ dọc
	for (int j = 0; j <= _size; j++)
	{

		for (int i = 1; i < 2 * _size; i++)
		{
			_Common::gotoXY(4 * j + _left, i + _top);
			printf("%c", 179);
		}
	}
	//kẻ ngang
	for (int j = 1; j < _size; j++)
	{
		_Common::gotoXY(_left, _top + 2 * j);
		for (int i = 0; i <= 4 * _size; i++)
		{
			if (i == 0)
				printf("%c", 195);
			else if (i == 4 * _size)
				printf("%c", 180);
			else if (i % 4 == 0)
				printf("%c", 197);
			else
				printf("%c", 196);
		}
	}



	//kẻ dưới
	_Common::gotoXY(_left, _top + 2 * _size);
	printf("%c", 192);
	for (int i = 0; i < 4 * _size - 1; i++)
	{
		if (i % 4 == 3)
			printf("%c", 193);
		else
			printf("%c", 196);
	}
	printf("%c", 217);

	// các thông tin
	_Common::gotoXY(4 * _size + 25 + _left, 3);
	printf("PLAYER 1     WIN :%d\tLOSE :%d", 0.0, 0.0);
	_Common::gotoXY(4 * _size + 25 + _left, 6);
	printf("PLAYER 2     WIN :%d\tLOSE :%d", 0.0, 0.0);
	_Common::printXO(4 * _size + 12, _top+19, 1);
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 121);
	_Common::printXO(4 * _size + 12, _top + 2, 0);
}

int _Board::checkBoard(int pX, int pY, bool pTurn) {
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY && _pArr[i][j].getCheck() == 0)
			{
				if (pTurn)
				{
					PlaySoundA("tic", NULL, SND_ASYNC);
					_pArr[i][j].setCheck(-1);
				}// Nếu lượt hiện hành là true: c = -1
				else
				{
					PlaySoundA("tic", NULL, SND_ASYNC);
					_pArr[i][j].setCheck(1);
				}// Nếu lượt hiện hành là false: c = 1
				return _pArr[i][j].getCheck();
			}
		}
	}
	return 0;
}
//int xchandau1, ychandau1, xchandau2, ychandau2;
int _Board::ngang()
{
	int ychandau1, ychandau2;
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].getCheck() == -1)
			{
				ychandau1 = j - 1;
				ychandau2 = j + 5;
				if ((ychandau1 >= 0) && (ychandau2 - _size <= 0))
					if ((_pArr[i][j + 1].getCheck() == -1 &&
						_pArr[i][j + 2].getCheck() == -1 &&
						_pArr[i][j + 3].getCheck() == -1 &&
						_pArr[i][j + 4].getCheck() == -1) &&
						(_pArr[i][ychandau1].getCheck() != 1 || _pArr[i][ychandau2].getCheck() != 1))
						return -1;
				if (ychandau1 < 0)
					if ((_pArr[i][j + 1].getCheck() == -1 &&
						_pArr[i][j + 2].getCheck() == -1 &&
						_pArr[i][j + 3].getCheck() == -1 &&
						_pArr[i][j + 4].getCheck() == -1))
						return -1;
				if (ychandau2 == _size + 1)
					if ((_pArr[i][j + 1].getCheck() == -1 &&
						_pArr[i][j + 2].getCheck() == -1 &&
						_pArr[i][j + 3].getCheck() == -1 &&
						_pArr[i][j + 4].getCheck() == -1))
						return -1;
			}
		}
	}
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].getCheck() == 1)
			{
				ychandau1 = j - 1;
				ychandau2 = j + 5;
				if ((ychandau1 >= 0) && (ychandau2 - _size <= 0))
					if ((_pArr[i][j + 1].getCheck() == 1 &&
						_pArr[i][j + 2].getCheck() == 1 &&
						_pArr[i][j + 3].getCheck() == 1 &&
						_pArr[i][j + 4].getCheck() == 1) &&
						(_pArr[i][ychandau1].getCheck() != -1 || _pArr[i][ychandau2].getCheck() != -1))
						return 1;
				if (ychandau1 < 0)
					if ((_pArr[i][j + 1].getCheck() == 1 &&
						_pArr[i][j + 2].getCheck() == 1 &&
						_pArr[i][j + 3].getCheck() == 1 &&
						_pArr[i][j + 4].getCheck() == 1))
						return 1;
				if (ychandau2 == _size + 1)
					if ((_pArr[i][j + 1].getCheck() == 1 &&
						_pArr[i][j + 2].getCheck() == 1 &&
						_pArr[i][j + 3].getCheck() == 1 &&
						_pArr[i][j + 4].getCheck() == 1))
						return 1;
			}
		}
	}

	return 0;
}

int _Board::doc()
{
	int xchandau1, xchandau2;
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].getCheck() == -1)
			{
				xchandau1 = i - 1;
				xchandau2 = i + 5;
				if ((xchandau1 >= 0) && (xchandau2 - _size <= 0))
					if ((_pArr[i + 1][j].getCheck() == -1 &&
						_pArr[i + 2][j].getCheck() == -1 &&
						_pArr[i + 3][j].getCheck() == -1 &&
						_pArr[i + 4][j].getCheck() == -1) &&
						(_pArr[xchandau1][j].getCheck() != 1 || _pArr[xchandau2][j].getCheck() != 1))
						return -1;
				if (xchandau1 < 0)
					if ((_pArr[i + 1][j].getCheck() == -1 &&
						_pArr[i + 2][j].getCheck() == -1 &&
						_pArr[i + 3][j].getCheck() == -1 &&
						_pArr[i + 4][j].getCheck() == -1))
						return -1;
				if (xchandau2 == _size + 1)
					if ((_pArr[i + 1][j].getCheck() == -1 &&
						_pArr[i + 2][j].getCheck() == -1 &&
						_pArr[i + 3][j].getCheck() == -1 &&
						_pArr[i + 4][j].getCheck() == -1))
						return -1;
			}
		}
	}
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].getCheck() == 1)
			{
				xchandau1 = i - 1;
				xchandau2 = i + 5;
				if ((xchandau1 >= 0) && (xchandau2 - _size <= 0))
					if ((_pArr[i + 1][j].getCheck() == 1 &&
						_pArr[i + 2][j].getCheck() == 1 &&
						_pArr[i + 3][j].getCheck() == 1 &&
						_pArr[i + 4][j].getCheck() == 1) &&
						(_pArr[xchandau1][j].getCheck() != -1 || _pArr[xchandau2][j].getCheck() != -1))
						return 1;
				if (xchandau1 < 0)
					if ((_pArr[i + 1][j].getCheck() == 1 &&
						_pArr[i + 2][j].getCheck() == 1 &&
						_pArr[i + 3][j].getCheck() == 1 &&
						_pArr[i + 4][j].getCheck() == 1))
						return 1;
				if (xchandau2 == _size + 1)
					if ((_pArr[i + 1][j].getCheck() == 1 &&
						_pArr[i + 2][j].getCheck() == 1 &&
						_pArr[i + 3][j].getCheck() == 1 &&
						_pArr[i + 4][j].getCheck() == 1))
						return 1;
			}
		}
	}
	return 0;
}

int _Board::xientren()
{
	for (int i = 0; i < _size-4; i++)
	{
		for (int j = 0;  (j < _size - 4) && (j >= 4); j++) {
			if (_pArr[i][j].getCheck() == -1)
				if ((_pArr[i + 1][j - 1].getCheck() == -1 &&
					_pArr[i + 2][j - 2].getCheck() == -1 &&
					_pArr[i + 3][j - 3].getCheck() == -1 &&
					_pArr[i + 4][j - 4].getCheck() == -1))
						return -1;
				}
				
	}
	for (int i = 0; i < _size-4; i++) {
		for (int j = 0; (j < _size-4)&&(j>=4); j++) {
			if (_pArr[i][j].getCheck() == 1)
				if ((_pArr[i + 1][j - 1].getCheck() == 1 &&
					_pArr[i + 2][j - 2].getCheck() == 1 &&
					_pArr[i + 3][j - 3].getCheck() == 1 &&
					_pArr[i + 4][j - 4].getCheck() == 1))
						return 1;
				}
	}
	return 0;
}
bool _Board::isDraw()
{
	int count = 0;
	for (int i = 0; i < _size; i++)
		for (int j = 0; j < _size; j++)
			if (_pArr[i][j].getCheck() != 0)
				count++;
	if (count == _size * _size)
		return true;
	return false;
}
int _Board::xienduoi()
{
	int xchandau1, xchandau2, ychandau1, ychandau2;
	for (int i = 0; i < _size-4; i++)
	{
		for (int j = 0; j < _size-4; j++) {
			if (_pArr[i][j].getCheck() == -1)
				if ((_pArr[i + 1][j + 1].getCheck() == -1 &&
					_pArr[i + 2][j + 2].getCheck() == -1 &&
					_pArr[i + 3][j + 3].getCheck() == -1 &&
					_pArr[i + 4][j + 4].getCheck() == -1))
						return -1;
				}
	}
	for (int i = 0; i < _size-4; i++) {
		for (int j = 0; j < _size - 4; j++) {
			if (_pArr[i][j].getCheck() == 1) {
				if ((_pArr[i + 1][j + 1].getCheck() == 1 &&
					_pArr[i + 2][j + 2].getCheck() == 1 &&
					_pArr[i + 3][j + 3].getCheck() == 1 &&
					_pArr[i + 4][j + 4].getCheck() == 1))
					return 1;
			}
		}
	}
	return 0;
}
int _Board::testBoard() {
	if (ngang() == 1)
		return 1;
	if (ngang() == -1)
		return -1;
	if (doc() == 1)
		return 1;
	if (doc() == -1)
		return -1;
	if (xientren() == -1)
		return -1;
	if (xientren() == 1)
		return 1;
	if (xienduoi() == -1)
		return -1;
	if (xienduoi() == 1)
		return 1;
	if (isDraw())
		return 0;
	return 2;
}

_Point* _Board::getElement(int i, int j)
{
	return &_pArr[i][j];
}

void _Board::setSize(int n)
{
	_size = n;
}

int _Board::randomCheckBoard(int pX, int pY, bool pTurn) {
	int dong = 0, cot = 0;
	srand(time(NULL));
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY && _pArr[i][j].getCheck() == 0)
			{

				HANDLE hConsoleColor;
				hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
				PlaySoundA("tic", NULL, SND_ASYNC);
				_pArr[i][j].setCheck(-1);
				SetConsoleTextAttribute(hConsoleColor, 121);
				printf("X");
				if (testBoard() == -1)
				{
					return _pArr[i][j].getCheck();
				}
				do {
					dong = rand() % _size;
					cot = rand() % _size;
				} while (_pArr[dong][cot].getCheck() != 0);
				PlaySoundA("tic", NULL, SND_ASYNC);
				_pArr[dong][cot].setCheck(1);
				_Common::gotoXY(_pArr[dong][cot].getX(), _pArr[dong][cot].getY());
				SetConsoleTextAttribute(hConsoleColor, 124);
				printf("O");
				_Common::gotoXY(pX, pY);
				return _pArr[i][j].getCheck();
			}// Nếu lượt hiện hành là true: c = -1
		}
	}
	return 0;
}
