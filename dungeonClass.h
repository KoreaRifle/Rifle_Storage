#pragma once
#include<iostream>
#include<time.h>
#include<Windows.h>
#include<vector>
#include "stdafx.h"
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



class dungeonClass :public itemList
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
private:
	vector<ITEM> _dropItem;
	vector<ITEM> _d1DropItem;
	vector<ITEM> _d1BossDropItem;
	vector<ITEM> _d2DropItem;
	vector<ITEM> _d2BossDropItem;
	vector<ITEM>::iterator _vdropItem;
	int _d1BossItemArray[20];
	int _d2BossItemArray[20];
private:
	vector<_tagITEM> _ITEM;
	vector<_tagITEM>::iterator _vITEM;
	int _inventorySize;
	int _maxInventorySize;
public:
	int dungeonMain(int inventorySize, int maxInventorySize);
	void enterDungeon(int dungeonNum, char dungeonName[32]);
	void charactorStatus(int roleNum, char name[32], int level, int max_hp, int add_max_hp, int hp, int max_mp, int add_max_mp, int mp, int pwr, int add_pwr, int mindmg, int dex, int add_dex, int intel, int add_intel, int exp, int totalExp, int money);
	void itemInfoSave(ITEMDIVISION div, ITEMKIND kind, ITEMROLE role, char itemName[32], int point, int req_level, int req_pwr, int req_dex, int req_intel, int hpOption, int mpOption, int pwrOption, int dexOption, int intelOption, int price);
	vector<_tagITEM> itemInfoReturn(void);
	void levelUp(void);
	void monsterAttack(int monsterAttackPoint);
	void userInterface(void);
	void attackPoint(int mindmg);
	void playerDead(void);
public:
	void setMonster(void);
	void dropItemSetting(void);
	void dropItemList(int dungeonNum, int callNum);
	dungeonClass();
	~dungeonClass();
};