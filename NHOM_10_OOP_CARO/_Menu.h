#pragma once
#include<iostream>
#include"_Common.h"
#include<conio.h>
#include"_Game.h"
#define max_value  5
#define small_menu 3
#define pX 40
#define pY 20
using namespace std;
int MainMenuWithSelection();
void processMenu();
int smallMenuWithSelection(int px, int py);
void Play();
void About();
