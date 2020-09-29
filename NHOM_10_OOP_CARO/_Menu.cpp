#pragma once
#include "_Menu.h"
#include<cstdlib>

_Game g(BOARD_SIZE, LEFT, TOP); // Sinh viên tự định nghĩa các hằng số
int smallMenuWithSelection(int px, int py)
{
	char menu[3][10] = { "CONTINUE","SAVE","EXIT" };
	int pointer = 0;
	while (1)
	{
		_Common::Nocursortype(false);
		for (int i = 0; i < 3; i++)
		{
			if (pointer == i)
			{
				_Common::txtColor(124);
				_Common::gotoXY(4 * BOARD_SIZE + pX, pY + 2 * i);
				printf("           ");
				_Common::gotoXY(4 * BOARD_SIZE + pX, pY + 2 * i);
				printf("%s", menu[i]);
			}
			else
			{
				_Common::txtColor(112);
				_Common::gotoXY(4 * BOARD_SIZE + pX, pY + 2 * i);
				printf("             ");
				_Common::gotoXY(4 * BOARD_SIZE + pX, pY + 2 * i);
				printf("%s", menu[i]);
			}
		}
		while (1)
		{
			if (_kbhit())
			{
				char key = _getch();
				if (key == 72 || key == 'w') {
					if (pointer > 0)
						--pointer;
					else
						pointer = small_menu - 1;
					break;
				}
				if (key == 80 || key == 's') {
					if (pointer < small_menu - 1)
						++pointer;
					else
						pointer = 0;
					break;
				}
				if (key == 13)
				{
					PlaySoundA("menu", NULL, SND_SYNC);
					switch (pointer)
					{
					case 0:
						return 0;
					case 1:
						return 1;
					case 2:
						return 2;
					}
				}
			}
		}
	}
}
int MainMenuWithSelection()
{
	_Common::txtColor(11);
	_Common::setFontSize(16);
	char menu[5][18] = { "PLAYER VS PLAYER","PLAYER VS MACHINE","LOAD GAME","ABOUT","EXIT" };
	int pointer = 0;
	while (1)
	{
		_Common::Nocursortype(false);
		for (int i = 0; i < max_value; i++)
			if (pointer == i)
			{
				_Common::txtColor(121);
				_Common::gotoXY(px, py + 2 * i);
				printf("                    ", menu[i]);
				_Common::gotoXY(px, py + 2 * i);
				_Common::txtColor(121);
				printf(">%s\n", menu[i]);
			}

			else {
				_Common::gotoXY(px, py + 2 * i);
				printf("                    ", menu[i]);
				_Common::txtColor(112);
				_Common::gotoXY(px, py + 2 * i);
				printf(" %s   \n", menu[i]);
			}
		while (1)
		{
			if (_kbhit()) {
				char key = _getch();
				if (key == 72 || key == 'w') {
					if (pointer > 0)
						--pointer;
					else
						pointer = max_value - 1;
					break;
				}
				if (key == 80 || key == 's') {
					if (pointer < max_value - 1)
						++pointer;
					else
						pointer = 0;
					break;
				}
				if (key == 13)
				{
					PlaySoundA("menu", NULL, SND_SYNC);
					switch (pointer)
					{
					case 0:
						return 0;
					case 1:
						system("cls");
						_Common::gotoXY(pX + 10, pY);
						return 1;
					case 2:
						system("cls");
						return 2;
					case 3:
						system("cls");
						return 3;
					case 4: return 4;

					}
				}
			}
		}
	}
}


void Play() {
	_Common::Nocursortype(true);
start:while (g.isContinue()) {
	g.waitKeyBoard();
	switch (g.getCommand()) {
	case 'A': case 'a': case 75:
		g.moveLeft();
		break;
	case 'W': case 'w': case 72:
		g.moveUp();
		break;
	case 'S': case's': case 80:
		g.moveDown();
		break;
	case 'D': case 77:
		g.moveRight();
		break;
	case 27:
		switch (smallMenuWithSelection(40, 20))
		{
		case 0:
			cin.clear();
			for (int i = 0; i < small_menu; i++)
			{
				_Common::gotoXY(4 * BOARD_SIZE + pX, pY + 2 * i);
				printf("           ");
			}
			_Common::Nocursortype(true);
			_Common::gotoXY(LEFT + 2, TOP + 1);
			goto start;
		case 1:
			g.save();
			cin.clear();
			for (int i = 0; i < small_menu; i++)
			{
				_Common::gotoXY(4 * BOARD_SIZE + pX, pY + 2 * i);
				printf("         ");
			}
			_Common::gotoXY(4 * BOARD_SIZE + pX, pY);
			cout << "SAVE SUCCESSFUL          ";
			_getch();
			system("cls");
			_Common::gotoXY(LEFT + 2, TOP + 1);	
			processMenu();
		case 2:
			cin.clear();
			system("cls");
			break;
		}
		processMenu();
		break;
	case 13:
		//Đánh dấu bàn cờ, sau đó kiểm tra và xử lý thắng/thua/hòa/tiếp tục
		if(g.getPlay()==0)
			if (g.processCheckBoard()) 
			{
				switch (g.processFinish()) {
				case -1: case 1: case 0:
					if (g.askContinue() != 'Y')
					{
						g.draw = 0;
						g.winO = 0;
						g.game = 0;
						g.winX = 0;
						PlaySoundA("menu", NULL, SND_SYNC);
						system("cls");
						processMenu();
					}
					else
					{
						PlaySoundA("menu", NULL, SND_SYNC);
						g.startGame();
					}
				}
			}
		if(g.getPlay()==1)
		{
				if (g.processCheckBoardRandom()) {
					switch (g.processFinish()) {
					case -1: case 1: case 0:
						if (g.askContinue() != 'Y')
						{
							g.draw = 0;
							g.winO = 0;
							g.game = 0;
							g.winX = 0;
							PlaySoundA("menu", NULL, SND_SYNC);
							system("cls");
							processMenu();
						}
						else
						{
							PlaySoundA("menu", NULL, SND_SYNC);
							g.startGame();
						}
					}
				}
			}
	}
}
}

void processMenu()
{
	PlaySoundA("background", NULL, SND_ASYNC);
	_Common::printCaro(20, 3);
	switch (MainMenuWithSelection())
	{
	case 0:
		g.startGame();
		g.setPlay(0);
		Play();
		break;
	case 1:
		g.startGame();
		g.setPlay(1);
		Play();
		break;
	case 2:
		_Common::Nocursortype(true);
		system("cls");
		g.load();
		Play();
		break;
	case 3:
		About();
		system("cls");
		processMenu();
	case 4:
		g.exitGame();
		break;
	}
}
void About()
{
	system("cls");
	cout << "Use WASD or arrows to move, enter to check\n";
	cout << "       Member     "<<endl;
	cout << "19127595 - NGUYEN MINH TRI"<<endl;
	cout << "19127481 - TRAN HOANG NAM"<<endl;
	cout << "19127472 - NGUYEN BA MINH"<<endl;
	cout << "19127337 - LE THAI PHUC BAO"<<endl;
	_getch();

}