#pragma once
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <vector>
#include "itemList.h"

using namespace std;

class inventory:public itemList
{
private:
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
private:
	vector<INVENTORY> _inventory;
	vector<INVENTORY>::iterator _vinven;
	int _itemNum = 1;
	ITEMDIVISION _div;
	ITEMKIND _kind;
	ITEMROLE _role;
	char _itemName[32];
	int _point;
	int _req_level;
	int _req_pwr;
	int _req_dex;
	int _req_intel;
	int _hpOption;
	int _mpOption;
	int _pwrOption;
	int _dexOption;
	int _intelOption;
	int _price;
public:
	void charactorStatus(int roleNum, char name[32], int level, int max_hp, int add_max_hp, int hp, int max_mp, int add_max_mp, int mp, int pwr, int add_pwr, int mindmg, int dex, int add_dex, int intel, int add_intel, int exp, int totalExp, int money);
	void itemInfoSave(int viewPoint, ITEMDIVISION div, ITEMKIND kind, ITEMROLE role, char itemName[32], int point, int req_level, int req_pwr, int req_dex, int req_intel, int hpOption, int mpOption, int pwrOption, int dexOption, int intelOption, int price);
	void inventoryView(void);
	void inventoryDetailView(void);
	void itemInit(void);
	inventory();
	~inventory();
};

