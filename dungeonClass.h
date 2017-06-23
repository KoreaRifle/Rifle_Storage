#pragma once
#include<iostream>
#include<time.h>
#include<Windows.h>
#include<vector>
#include "userStats.h"
#include "itemList.h"

using namespace std;

enum DUNGEONLIST
{
	DUNGEON1 = 1,
	DUNGEON2,
	DUNGEON3,
	DUNGEON4,
	LISTEND
};

struct tagMONSTERSTATS
{
	DUNGEONLIST dl;
	int callNum;
	char name[32];
	int max_hp;
	int hp;
	int pwr;
	int dex;
	int exp;
	int money;
	int monsterPwr;
	int monsterAttackPoint;
};

class dungeonClass
{
private:
	vector<tagMONSTERSTATS> _monster;
	vector<tagMONSTERSTATS>::iterator _vMonster;
	vector<INVENTORY> _inventory;
	vector<INVENTORY>::iterator _vinven;
	char _dungeonName[32];
	char _name[32];
	int _level;
	int _roleNum;
	char _roleName[32];
	int _max_hp;
	int _add_max_hp;
	int _hp;
	int _max_mp;
	int _add_max_mp;
	int _mp;
	int _pwr;
	int _add_pwr;
	int _mindmg;
	int _dex;
	int _add_dex;
	int _intel;
	int _add_intel;
	int _exp;
	int _totalExp;
	int _money;
	int _userAttackPoint = 0;
	int _playerDodgePoint;
	int _monsterDodgePoint;
private:
	bool exit = 0;
public:
	void dungeonMain(void);
	void enterDungeon(int dungeonNum, char dungeonName[32]);
	void setMonster(void);
	void charactorStatus(int roleNum, char name[32], int level, int max_hp, int add_max_hp, int hp, int max_mp, int add_max_mp, int mp, int pwr, int add_pwr, int mindmg, int dex, int add_dex, int intel, int add_intel, int exp, int totalExp, int money);
	void itemInfoSave(ITEMDIVISION div, ITEMKIND kind, ITEMROLE role, char itemName[32], int point, int req_level, int req_pwr, int req_dex, int req_intel, int hpOption, int mpOption, int pwrOption, int dexOption, int intelOption, int price);
	void levelUp(void);
	void monsterAttack(int monsterAttackPoint);
	void userInterface(void);
	void attackPoint(int mindmg);
	void playerDead(void);
	dungeonClass();
	~dungeonClass();
};