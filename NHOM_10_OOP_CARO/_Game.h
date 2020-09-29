#pragma once
#include"_Board.h"
#include<conio.h>
#include<string>
#include<fstream>
#define BOARD_SIZE 13
#define LEFT 4
#define TOP 1
static int px = 55;
static int py = 20;

class _Game {
	_Board* _b;// một bàn cờ
	bool _turn;// lượt chơi: true lượt người một & false lượt người thứ hai
	int _x, _y; // Tọa độ hiện hành của nháy chuột
	int _command; // phím gõ từ người dùng
	bool _loop; // Biến quyết định thoát game hay không
	int PlayerOrMachine;
public:
	int getPlay() { return PlayerOrMachine; }
	void setPlay(int n) { PlayerOrMachine = n; }
	int game;//TOng so game
	int winX;//X thang
	int winO;//O thang
	int draw;//Hoa
	int count;
	_Game(int pSize, int pLeft, int pTop);
	~_Game();
	int getCommand();
	bool isContinue();
	char waitKeyBoard(); // Hàm nhận phím từ người dùng
	char askContinue();
	void startGame(); // Hàm bắt đầu game
	void exitGame(); // Hàm thoát game
	int processFinish();
	bool processCheckBoard();
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	void save();
	void load();
	bool processCheckBoardRandom();
};