#pragma once
#include <iostream>
#include <time.h>
#include <Windows.h>
#include "itemList.h"

using namespace std;

class userStats
{
private:
	int _level;
	char _name[32];
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
private:
	vector<INVENTORY> _inventory;
	vector<INVENTORY>::iterator _vinven;
public:
	void charactorStatus(int roleNum, char name[32], int level, int max_hp, int add_max_hp, int hp, int max_mp, int add_max_mp, int mp, int pwr, int add_pwr, int mindmg, int dex, int add_dex, int intel, int add_intel, int exp, int totalExp, int money);
	void moneyInfo(int money);
	void userInfo(void);
	void userInfo_pageNum(int pageNum, int totalPageNum);
	void levelUp(int exp);
	void itemInfoSave(ITEMDIVISION div, ITEMKIND kind, ITEMROLE role, char itemName[32], int point, int req_level, int req_pwr, int req_dex, int req_intel, int hpOption, int mpOption, int pwrOption, int dexOption, int intelOption, int price);
	userStats();
	~userStats();
};

