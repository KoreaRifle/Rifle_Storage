#include "itemList.h"
#include "MainMenu.h"

MainMenu il_mm;

itemList::itemList()
{
	storeItemSetting();
}

itemList::~itemList()
{
}

void itemList::storeItemList(int kindNum)
{
	system("cls");
	// 1:무기, 2:방어구, 3.악세사리
	switch (kindNum)
	{
		case 1:
			for (_vitem = _item.begin(); _vitem != _item.end(); ++_vitem)
			{
				itemInit();
				if (_vitem->division != STOREITEM) continue;
				if (_vitem->kind != WEAPON) continue;
				cout << "구매번호 : " << _vitem->itemNum << endl;
				cout << "아이템명 : " << _vitem->itemName << endl;
				cout << "구입가능직업 : ";
				if (_vitem->role == WARRIORITEM) cout << "전사" << endl;
				else if (_vitem->role == WIZARDITEM) cout << "마법사" << endl;
				else if (_vitem->role == ELFITEM) cout << "엘프" << endl;
				cout << "공격력 : " << _vitem->point << endl;
				if (_vitem->pwrOption != 0) cout << "옵션(힘) : " << _vitem->pwrOption << endl;
				if (_vitem->dexOption != 0) cout << "옵션(민첩) : " << _vitem->dexOption << endl;
				if (_vitem->intelOption != 0) cout << "옵션(지능) : " << _vitem->intelOption << endl;
				cout << "가격 : " << _vitem->price << endl;
				cout << endl;
				itemNum++;
			}
			purchaseMenu(itemNum);
		break;
		case 2:
		break;
		case 3:
		break;
	}
	
}

void itemList::purchaseMenu(int itemNum)
{
	int purchaseNum;
	int purchaseMenuSelect;
	cout << "========== ITEM UI ==========" << endl;
	cout << "1.구매\t 2.되돌아가기" << endl;
	cin >> purchaseMenuSelect;
	
	switch (purchaseMenuSelect)
	{
		case 1:
			cout << "구매 아이템 번호를 입력하세요." << endl;
			cin >> purchaseNum;
			if (purchaseNum == _vitem->itemNum)
			{
				cout << "구매번호 : " << _vitem->itemNum << endl;
				cout << "아이템명 : " << _vitem->itemName << endl;
				cout << "해당 아이템을 구매했습니다." << endl;
			}
		break;
		case 2:
			il_mm.charactorStatus(1, _roleNum, _name, _level, _max_hp, _add_max_hp, _hp, _max_mp, _add_max_mp, _mp, _pwr, _add_pwr, _mindmg, _dex, _add_dex, _intel, _add_intel, _exp, _totalExp, _money);
			il_mm.startMenu();
		break;
	}
}

void itemList::itemInit(void)
{
	if (_vitem->point <= 0) _vitem->point = 0;
	if (_vitem->pwrOption <= 0) _vitem->pwrOption = 0;
	if (_vitem->dexOption <= 0) _vitem->dexOption = 0;
	if (_vitem->intelOption <= 0) _vitem->intelOption = 0;
	if (_vitem->price <= 0) _vitem->price = 0;
	if (_vitem->req_level <= 0) _vitem->req_level = 1;
	if (_vitem->req_pwr <= 0) _vitem->req_pwr = 0;
	if (_vitem->req_dex <= 0) _vitem->req_dex = 0;
	if (_vitem->req_intel <= 0) _vitem->req_intel = 0;
}

void itemList::charactorStatus(int roleNum, char name[32], int level, int max_hp, int add_max_hp, int hp, int max_mp, int add_max_mp, int mp, int pwr, int add_pwr, int mindmg, int dex, int add_dex, int intel, int add_intel, int exp, int totalExp, int money)
{
	_roleNum = roleNum;
	if (_roleNum == 1) strncpy_s(_roleName, "전사", 32);
	else if (_roleNum == 2) strncpy_s(_roleName, "마법사", 32);
	else if (_roleNum == 3) strncpy_s(_roleName, "엘프", 32);
	strncpy_s(_name, name, 32);
	_level = level;
	_max_hp = max_hp;
	_add_max_hp = add_max_hp;
	_hp = hp;
	_max_mp = max_mp;
	_add_max_mp = add_max_mp;
	_mp = mp;
	_pwr = pwr;
	_add_pwr = add_pwr;
	_mindmg = mindmg;
	_dex = dex;
	_add_dex = add_dex;
	_intel = intel;
	_add_intel = add_intel;
	_exp = exp;
	_totalExp = totalExp;
	_money = money;
}


void itemList::storeItemSetting(void)
{
	ITEM storeItem1;
	storeItem1.division = STOREITEM;
	storeItem1.kind = WEAPON;
	storeItem1.role = WARRIORITEM;
	strncpy_s(storeItem1.itemName, "숏쇼드", 32);
	storeItem1.req_level = 1;
	storeItem1.req_pwr = 3;
	storeItem1.req_dex = 1;
	storeItem1.req_intel = 0;
	storeItem1.point = 5;
	storeItem1.pwrOption = 1;
	storeItem1.price = 500;
	storeItem1.itemNum = 1;
	_item.push_back(storeItem1);

	ITEM storeItem2;
	storeItem2.division = STOREITEM;
	storeItem2.kind = WEAPON;
	storeItem2.role = WARRIORITEM;
	strncpy_s(storeItem2.itemName, "날이 서 있는 브로드소드", 32);
	storeItem2.req_level = 2;
	storeItem2.req_pwr = 8;
	storeItem2.req_dex = 5;
	storeItem2.req_intel = 0;
	storeItem2.point = 15;
	storeItem2.pwrOption = 3;
	storeItem2.dexOption = 1;
	storeItem2.price = 1200;
	storeItem2.itemNum = storeItem1.itemNum + 1;
	_item.push_back(storeItem2);
}
