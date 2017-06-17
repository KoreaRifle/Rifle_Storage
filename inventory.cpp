#include "inventory.h"
#include "MainMenu.h"

MainMenu inven_mm;

inventory::inventory()
{
}


inventory::~inventory()
{
}

void inventory::itemInfoSave(ITEMDIVISION div, ITEMKIND kind, ITEMROLE role, char itemName[32], int point, int req_level, int req_pwr, int req_dex, int req_intel, int hpOption, int mpOption, int pwrOption, int dexOption, int intelOption, int price)
{
	//cout << "[INVENTORY] 템 정보 저장 중..." << endl;
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
	itemNum++;
}

void inventory::inventoryView(void)
{
	cout << "[INVENTORY] 인벤토리 진입" << endl;
	for (_vinven = _inventory.begin(); _vinven != _inventory.end(); ++_vinven)
	{
		cout << "[" << _vinven->itemNum << "] ";
		cout << _vinven->itemName << endl;
	}
	Sleep(2000);
}
