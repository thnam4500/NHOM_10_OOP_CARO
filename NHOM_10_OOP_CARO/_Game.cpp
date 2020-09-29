#include "_Game.h"
#include "_Menu.h"
#include <time.h>
_Game::_Game(int pSize, int pLeft, int pTop) {
	_b = new _Board(pSize, pLeft, pTop);
	_loop = _turn = true;
	_command = -1; // Gán lượt và phím mặc định
	_x = pLeft; _y = pTop;
	game = 0;
	winX = 0;
	winO = 0;
	draw = 0;
	count = 0;
	PlayerOrMachine = 0;
}
_Game::~_Game() { delete _b; }
int _Game::getCommand() { return _command; }
bool _Game::isContinue() { return _loop; }
char _Game::waitKeyBoard() {
	_command = toupper(_getch());
	return _command;
}
char _Game::askContinue() {
	_Common::gotoXY(0, _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) + 4);
	return waitKeyBoard();
}
void _Game::startGame() {
	system("cls");
	_b->resetData(); // Khởi tạo dữ liệu gốc
	_b->drawBoard(); // Vẽ màn hình game
	_x = _b->getXAt(0, 0);
	_y = _b->getYAt(0, 0);
	_Common::gotoXY(4 * _b->getSize() + 25 + LEFT, 3);
	printf("PLAYER 1     WIN :%d\tLOSE :%d", winX, game - winX - draw);
	_Common::gotoXY(4 * _b->getSize() + 25 + LEFT, 6);
	printf("PLAYER 2     WIN :%d\tLOSE :%d", winO, game - winO - draw);
	_Common::gotoXY(4 * _b->getSize() + 10+ LEFT, 14);
	cout << "GAME "<<game+1;
	_Common::gotoXY((*_b->getElement(0, 0)).getX(), (*_b->getElement(0, 0)).getY());// di chuyển vào ô đầu
	_Common::Nocursortype(true);
}
void _Game::exitGame() {
	system("cls");
	//Có thể lưu game trước khi exit
	_loop = false;
}

bool _Game::processCheckBoard() {
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (_b->checkBoard(_x, _y, _turn)) {
	case -1:
		SetConsoleTextAttribute(hConsoleColor, 121);
		printf("X");
		SetConsoleTextAttribute(hConsoleColor, 124);
		_Common::printXO(4 * _b->getSize() + 12, _b->getTop()+19, 1);
		SetConsoleTextAttribute(hConsoleColor, 112);
		_Common::printXO(4 * _b->getSize() + 12, _b->getTop() + 2, 0);
		break;
	case 1:
		SetConsoleTextAttribute(hConsoleColor, 124);
		printf("O");
		SetConsoleTextAttribute(hConsoleColor, 112);
		_Common::printXO(4 * _b->getSize() + 12, _b->getTop() + 19, 1);
		SetConsoleTextAttribute(hConsoleColor, 121);
		_Common::printXO(4 * _b->getSize() + 12, _b->getTop()+2, 0);
		break;
	case 0: return false; // Khi đánh vào ô đã đánh rồi
	}
	return true;
}
int _Game::processFinish() {
	// Nhảy tới vị trí thích hợp để in chuỗi thắng/thua/hòa
	_Common::gotoXY(0, _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) + 2);
	int pWhoWin = _b->testBoard();
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (pWhoWin) {
	case -1:
		SetConsoleTextAttribute(hConsoleColor, 121);
		_Common::Nocursortype(false);
		PlaySoundA("win", NULL, SND_ASYNC);
		_Common::printWin(30, 10, 0);
		winX++;
		game++;
		break;
	case 1:
		SetConsoleTextAttribute(hConsoleColor, 124);
		_Common::Nocursortype(false);
		_Common::gotoXY(60, 20);
		PlaySoundA("win", NULL, SND_ASYNC);
		_Common::printWin(30, 10, 1);
		winO++;
		game++;
		break;
	case 0:
		system("cls");
		printf("Nguoi choi X da hoa nguoi choi O\n", false, true);
		draw++;
		game++;
		break;
	case 2:
		if(PlayerOrMachine==0)
			_turn = !_turn; // Đổi lượt nếu không có gì xảy ra
	}
	_Common::gotoXY(_x, _y);// Trả về vị trí hiện hành của con trỏ màn hình bàn cờ
	return pWhoWin;
}
void _Game::moveRight() {
	if (_x < _b->getXAt(_b->getSize() - 1, _b->getSize() - 1)) {
		_x += 4;
		_Common::gotoXY(_x, _y);
	}
}
void _Game::moveLeft() {
	if (_x > _b->getXAt(0, 0)) {
		_x -= 4;
		_Common::gotoXY(_x, _y);
	}
}
void _Game::moveDown() {
	if (_y < _b->getYAt(_b->getSize() - 1, _b->getSize() - 1)) {
		_y += 2;
		_Common::gotoXY(_x, _y);
	}
}
void _Game::moveUp() {
	if (_y > _b->getYAt(0, 0)) {
		_y -= 2;
		_Common::gotoXY(_x, _y);
	}
}
void _Game::save()
{
	for (int i = 0; i < small_menu; i++)
	{
		_Common::gotoXY(4 * BOARD_SIZE + pX, pY + 2 * i);
		printf("                 ");
	}
	_Common::gotoXY(4 * BOARD_SIZE + pX, pY);
	string name;
	cout << "Save file as: ";
	ofstream savename("save.txt", ios::app);
	getline(cin, name);
	savename << name << endl;
	savename.close();
	ofstream file(name, ios::ate);
	if (file)
	{
		file << _b->getSize() << endl;
		for (int i = 0; i < _b->getSize(); i++)
		{
			for (int j = 0; j < _b->getSize(); j++)
				file << (*_b->getElement(i, j)).getCheck() << " ";
			file << endl;
		}
		file << winO << endl;
		file << winX << endl;
		file << game << endl;
		file << draw << endl;
		file << _loop << endl;
		file << _turn << endl;
		file << _command << endl;
		file << _x << endl;
		file << _y << endl;
		file << PlayerOrMachine << endl;
	}
}

void _Game::load()
{
	string name;
	ifstream savename("save.txt", ios::in);
	int i;
	_Common::gotoXY(px, py - 2);
	cout << "List";
	for (i = 0; savename; i++)
	{
		getline(savename, name, '\n');
		_Common::gotoXY(px, py + 2 * i);
		cout << name;
	}
	savename.close();
	_Common::printCaro(20, 3);
	_Common::gotoXY(px, py + 5);
	cout << "Nhap ten file: ";
	getline(cin, name);
	ifstream file(name);
	if (file)
	{
		system("cls");
		startGame();
		int n;
		file >> n;
		_b->setSize(n);
		_Common::gotoXY(4 * _b->getSize() + 25 + LEFT, 3);
		printf("PLAYER 1     WIN :%d\tLOSE :%d", winX, game - winO);
		_Common::gotoXY(4 * _b->getSize() + 25 + LEFT, 6);
		printf("PLAYER 2     WIN :%d\tLOSE :%d", winO, game - winO);
		for (int i = 0; i < _b->getSize(); i++)
		{
			for (int j = 0; j < _b->getSize(); j++)
			{
				file >> n;
				(*_b->getElement(i, j)).setCheck(n);
				n = (*_b->getElement(i, j)).getCheck();
				if (n==-1)
				{
					_Common::gotoXY(_b->getXAt(i, j), _b->getYAt(i, j));
					_Common::txtColor(121);
					printf("X");
				}
				if (n == 1)
				{
					_Common::gotoXY(_b->getXAt(i, j), _b->getYAt(i, j));
					_Common::txtColor(124);
					printf("O");
				}
			}
		}
		file >> winO;
		file >> winX;
		file >> game;
		file >> draw;
		file >> _loop;
		file >> _turn;
		file >> _command;
		file >> _x;
		file >> _y;
		file >> PlayerOrMachine;
	}
	else {
		system("cls");
		cout << "Khong the load file";
		processMenu();
	}
}


bool _Game::processCheckBoardRandom()
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (_b->randomCheckBoard(_x, _y, _turn)) {
	case -1:
		break;
	case 0: return false; // Khi đánh vào ô đã đánh rồi
	}
	return true;
}
