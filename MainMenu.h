#pragma once
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <vector>
#include "userStats.h"
#include "dungeonClass.h"

using namespace std;

enum ROLE
{
	WARRIOR = 1,
	WIZARD,
	ELF,
	ROLEEND
};

struct tagCharactorStats
{
	ROLE roleCharactor; // 캐릭터직업
	char name[32];
	int max_hp;
	int hp;
	int max_mp;
	int mp;
	int pwr;
	int dex;
	int intel;
	int totalExp = 100;
};


class MainMenu
{
private:
	int _charactorSelect;
	char _charName[32];
	vector<tagCharactorStats> _role;
	vector<tagCharactorStats>::iterator _vriter;
	userStats us;
	dungeonClass dg;
public:
	void mainStart(void);
	void setUp(int charactorSelect, char _charName[32]);
	void output(int charNumber);
	void startMenu(void);
	void dungeonSelect(void);
	MainMenu();
	~MainMenu();
};
