#include "inventory.h"
#include "MainMenu.h"

MainMenu inven_mm;
//inventoryInfoSave mm_invenInfo;

inventory::inventory()
{
	
}


inventory::~inventory()
{
}

void inventory::itemInfoSave(int enter, ITEMDIVISION div, ITEMKIND kind, ITEMROLE role, char itemName[32], int point, int req_level, int req_pwr, int req_dex, int req_intel, int hpOption, int mpOption, int pwrOption, int dexOption, int intelOption, int price)
{
	cout << "[TEST] 템 정보 저장 중..." << endl;
	INVENTORY userInven;
	userInven.itemNum = itemNum;
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
	cout << "[TEST] 템 정보 저장 완료" << endl;
	itemNum++;
	cout << "itemNum 값 증가 : " << itemNum -1 << " -> " << itemNum << endl;
	inventoryView();
	for (_vinven = _inventory.begin(); _vinven != _inventory.end(); ++_vinven)
	{
		inven_mm.itemInfoSave(_vinven->division, _vinven->kind, _vinven->role, _vinven->itemName, _vinven->point, _vinven->req_level, _vinven->req_pwr, _vinven->req_dex, _vinven->req_intel, _vinven->hpOption, _vinven->mpOption, _vinven->pwrOption, _vinven->dexOption, _vinven->intelOption, _vinven->price);
	}

	if (enter == 1) inventoryView();
}

void inventory::inventoryView(void)
{
	cout << "[TEST] 인벤토리 진입" << endl;
	for (_vinven = _inventory.begin(); _vinven != _inventory.end(); ++_vinven)
	{
		//cout << "[" << _vinven->itemNum << "] ";
		cout << "[for문] 시작" << endl;
		cout << "[" << _vinven->itemNum << "] ";
		cout << _vinven->itemName << endl;
	}
}
