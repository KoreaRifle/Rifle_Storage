#pragma once
#include <iostream>
#include <time.h>
#include <Windows.h>
#include "itemList.h"

using namespace std;

class inventory:public itemList
{
private:
	vector<INVENTORY> _inventory;
	vector<INVENTORY>::iterator _vinven;
	int itemNum = 1;
public:
	void itemInfoSave(ITEMDIVISION div, ITEMKIND kind, ITEMROLE role, char itemName[32], int point, int req_level, int req_pwr, int req_dex, int req_intel, int hpOption, int mpOption, int pwrOption, int dexOption, int intelOption, int price);
	void inventoryView(void);
	inventory();
	~inventory();
};

