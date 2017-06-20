#include "inventory.h"
#include "MainMenu.h"

inventory::inventory()
{
	_inventory.resize(10);
}


inventory::~inventory()
{
}

void inventory::charactorStatus(int roleNum, char name[32], int level, int max_hp, int add_max_hp, int hp, int max_mp, int add_max_mp, int mp, int pwr, int add_pwr, int mindmg, int dex, int add_dex, int intel, int add_intel, int exp, int totalExp, int money)
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

void inventory::itemInfoSave(int viewPoint, ITEMDIVISION div, ITEMKIND kind, ITEMROLE role, char itemName[32], int point, int req_level, int req_pwr, int req_dex, int req_intel, int hpOption, int mpOption, int pwrOption, int dexOption, int intelOption, int price)
{
	if (viewPoint == 0)
	{
		INVENTORY userInven;
		userInven.itemNum = _itemNum;
		userInven.division = div;
		userInven.kind = kind;
		userInven.role = role;
		strncpy_s(userInven.itemName, itemName, 32);
		userInven.point = point;
		userInven.req_level = req_level;
		userInven.req_pwr = req_pwr;
		userInven.req_dex = req_dex;
		userInven.req_intel = req_intel;
		userInven.hpOption = hpOption;
		userInven.mpOption = mpOption;
		userInven.pwrOption = pwrOption;
		userInven.dexOption = dexOption;
		userInven.intelOption = intelOption;
		userInven.price = price;
		_inventory.push_back(userInven);
		_itemNum++;
	}
}

void inventory::inventoryView(void)
{
	bool exit = 0;
	int inventorySelectNum;
	cout << "========== 인벤토리 창 ==========" << endl;
	for (_vinven = _inventory.begin(); _vinven != _inventory.end(); ++_vinven)
	{
		if (_vinven->itemNum == 0) continue;
		cout << "[" << _vinven->itemNum << "] ";
		cout << _vinven->itemName << endl;
	}
	while (exit != 1)
	{
		cout << "========== 인벤토리 UI ==========" << endl;
		cout << "1.상세보기\t 2.아이템판매\t 3.되돌아가기" << endl;
		cin >> inventorySelectNum;
		switch (inventorySelectNum)
		{
			case 1:
				inventoryDetailView();
			break;
			case 2:
			break;
			case 3:
				exit = 1;
			break;
			default:
				cout << "잘못된 번호를 입력하셨습니다. 다시 입력해주세요." << endl;
			break;
		}
	}
}

void inventory::inventoryDetailView(void)
{
	int detailSelectView;
	for (_vinven = _inventory.begin(); _vinven != _inventory.end(); ++_vinven)
	{
		itemInit();
		if (_vinven->itemNum == 0) continue;
		cout << "[" << _vinven->itemNum << "] ";
		cout << _vinven->itemName << endl;
		if (_vinven->role == ITEMROLE::WARRIOR) cout << "[전사전용] ";
		else if (_vinven->role == ITEMROLE::WIZARD) cout << "[마법사전용] ";
		else if (_vinven->role == ITEMROLE::ELF) cout << "[엘프 전용] ";
		else if (_vinven->role == ITEMROLE::ALL) cout << "[모든직업] ";
		if (_vinven->kind == ITEMKIND::WEAPON) cout << "[무기] 공격력 : " << _vinven->point << "\t";
		else if (_vinven->kind == ITEMKIND::ARMOR) cout << "[방어구] 방어력 : " << _vinven->point << "\t";
		else if (_vinven->kind == ITEMKIND::ACC) cout << "[악세사리] 방어력 : " << _vinven->point << "\t";
		else if (_vinven->kind == ITEMKIND::POTION) cout << "[포션] 회복력 : " << _vinven->point << "\t";
		
		cout << endl;
	}
	while (true)
	{
		cout << "========== 아이템 상세보기 UI ==========" << endl;
		cout << "1.아이템 장착\t 2.되돌아가기" << endl;
		cin >> detailSelectView;
		switch (detailSelectView)
		{
			case 1:
			break;
			case 2:
				inventoryView();
			break;
			default:
				cout << "잘못된 번호를 입력하셨습니다. 다시 입력해주세요." << endl;
			continue;
		}
	}
}

void inventory::itemInit(void)
{
	if (_vinven->point <= 0) _vinven->point = 0;
	if (_vinven->hpOption <= 0) _vinven->hpOption = 0;
	if (_vinven->mpOption <= 0) _vinven->mpOption = 0;
	if (_vinven->pwrOption <= 0) _vinven->pwrOption = 0;
	if (_vinven->dexOption <= 0) _vinven->dexOption = 0;
	if (_vinven->intelOption <= 0) _vinven->intelOption = 0;
	if (_vinven->price <= 0) _vinven->price = 0;
	if (_vinven->req_level <= 0) _vinven->req_level = 1;
	if (_vinven->req_pwr <= 0) _vinven->req_pwr = 0;
	if (_vinven->req_dex <= 0) _vinven->req_dex = 0;
	if (_vinven->req_intel <= 0) _vinven->req_intel = 0;
}