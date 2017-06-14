#pragma once
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <vector>

using namespace std;

enum ITEMDIVISION
{
	DROPITEM,
	STOREITEM,
	ITEMDIVISIONEND
};

enum ITEMKIND
{
	WEAPON,
	ARMOR,
	ACC,
	ITEMKINDEND
};

enum ITEMROLE
{
	WARRIORITEM,
	WIZARDITEM,
	ELFITEM,
	ITEMROLEEND
};

struct ITEM
{
	ITEMDIVISION division;
	ITEMKIND kind;
	ITEMROLE role;
	int itemNum;
	char itemName[32];
	int point; // 공격 혹은 방어 점수
	int req_level; // 요구 레벨
	int req_pwr;
	int req_dex;
	int req_intel;
	int hpOption;
	int mpOption;
	int pwrOption;
	int dexOption;
	int intelOption;
	int price;
};

class itemList
{
private:
	vector<ITEM> _item;
	vector<ITEM>::iterator _vitem;
	int itemNum = 1;
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
public:
	void storeItemList(int kindNum);
	void purchaseMenu(int itemNum);
	void itemInit(void);
	void charactorStatus(int roleNum, char name[32], int level, int max_hp, int add_max_hp, int hp, int max_mp, int add_max_mp, int mp, int pwr, int add_pwr, int mindmg, int dex, int add_dex, int intel, int add_intel, int exp, int totalExp, int money);
	void storeItemSetting(void);
	itemList();
	~itemList();
};

