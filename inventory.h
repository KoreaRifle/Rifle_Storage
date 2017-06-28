#pragma once
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <vector>
#include "itemList.h"
#include "stdafx.h"

using namespace std;

class inventory :public itemList
{
private:
	// 캐릭터 정보 저장 관련 변수
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
	// 인벤토리 저장 관련 변수
	vector<INVENTORY> _inventory;
	vector<INVENTORY>::iterator _vinven;
	int _maxInventorySize = 10;
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
private:
	// 외부 아이템 정보 관련 변수
	vector<_tagITEM> _ITEM;
	vector<_tagITEM>::iterator _vITEM;
private:
	// 아이템 장착 관련 변수
	bool left_weaponEquip;
	bool right_weaponEquip;
	bool headEquip;
	bool bodyEquip;
	bool left_armEquip;
	bool right_armEquip;
	bool bootsEquip;
	bool necklaceEquip;
	bool left_ringEquip;
	bool right_ringEquip;
	vector<INVENTORY> vector_left_weaponEquip;
public:
	void charactorStatus(int roleNum, char name[32], int level, int max_hp, int add_max_hp, int hp, int max_mp, int add_max_mp, int mp, int pwr, int add_pwr, int mindmg, int dex, int add_dex, int intel, int add_intel, int exp, int totalExp, int money);
	void moneyInfo(int money);
	int itemInfoSave(vector<_tagITEM> _ITEM);
	int itemInfoSave(vector<INVENTORY> _INVEN);
	int maxInventorySizeReturn(void);
	int inventoryView(void);
	void inventoryDetailView(void);
	int inventoryItemSell(void);
	void itemInit(void);
public:
	void itemEquip(int equipNumber, int equipItemNumber);
	inventory();
	~inventory();
};

