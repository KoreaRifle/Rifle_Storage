#pragma once
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <vector>
#include "userStats.h"
#include "dungeonClass.h"
#include "innClass.h"
#include "itemList.h"
#include "inventory.h"

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
	char name[32]; // 32자 이상 입력하면 뻑남... 해결방안 필요
	int level;
	int max_hp;
	int add_max_hp;
	int hp;
	int max_mp;
	int add_max_mp;
	int mp;
	int pwr;
	int add_pwr;
	int mindmg;
	int dex;
	int add_dex;
	int intel;
	int add_intel;
	int exp;
	int totalExp;
	int money;
};

class MainMenu
{
private:
	int _charactorSelect;
	char _charName[32];
	int inGameMenuSelect;
	vector<tagCharactorStats> _role;
	vector<tagCharactorStats>::iterator _vriter;
	vector<INVENTORY> _inventory;
	vector<INVENTORY>::iterator _vinven;
	userStats us;
	dungeonClass dg;
	innClass inn;
	itemList il;
	inventory inven;
public:
	void mainStart(void);
	void setUp(int charactorSelect, char _charName[32]);
	void output(int charNumber);
	void charactorStatus(int viewPoint, int roleNum, char name[32], int level, int max_hp, int add_max_hp, int hp, int max_mp, int add_max_mp, int mp, int pwr, int add_pwr, int mindmg, int dex, int add_dex, int intel, int add_intel, int exp, int totalExp, int money);
	void moneyInfo(int money);
	void itemInfoSave(int selectView, ITEMDIVISION div, ITEMKIND kind, ITEMROLE role, char itemName[32], int point, int req_level, int req_pwr, int req_dex, int req_intel, int hpOption, int mpOption, int pwrOption, int dexOption, int intelOption, int price);
	void startMenu(void);
	void dungeonSelect(void);
	void store(void);
	void init(void);
	MainMenu();
	~MainMenu();
};
