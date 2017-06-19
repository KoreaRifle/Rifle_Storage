#include "inventory.h"
#include "MainMenu.h"

MainMenu inven_mm;

inventory::inventory()
{
}


inventory::~inventory()
{
}

void inventory::charactorStatus(int roleNum, char name[32], int level, int max_hp, int add_max_hp, int hp, int max_mp, int add_max_mp, int mp, int pwr, int add_pwr, int mindmg, int dex, int add_dex, int intel, int add_intel, int exp, int totalExp, int money)
{
	_roleNum = roleNum;
	if (_roleNum == 1) strncpy_s(_roleName, "����", 32);
	else if (_roleNum == 2) strncpy_s(_roleName, "������", 32);
	else if (_roleNum == 3) strncpy_s(_roleName, "����", 32);
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
	else if (viewPoint == 1)
	{
		inven_mm.itemInfoSave(0, div, kind, role, itemName, point, req_level, req_pwr, req_dex, req_intel, hpOption, mpOption, pwrOption, dexOption, intelOption, price);
	}
}

void inventory::inventoryView(void)
{
	int inventorySelectNum;
	cout << "========== �κ��丮 â ==========" << endl;
	for (_vinven = _inventory.begin(); _vinven != _inventory.end(); ++_vinven)
	{
		cout << "[" << _vinven->itemNum << "] ";
		cout << _vinven->itemName << endl;
	}
	while (true)
	{
		cout << "========== �κ��丮 UI ==========" << endl;
		cout << "1.�󼼺���\t 2.�������Ǹ�\t 3.�ǵ��ư���" << endl;
		cin >> inventorySelectNum;
		switch (inventorySelectNum)
		{
			case 1:
				inventoryDetailView();
			break;
			case 2:
			break;
			case 3:
				inven_mm.charactorStatus(1, _roleNum, _name, _level, _max_hp, _add_max_hp, _hp, _max_mp, _add_max_mp, _mp, _pwr, _add_pwr, _mindmg, _dex, _add_dex, _intel, _add_intel, _exp, _totalExp, _money);
				for (_vinven = _inventory.begin(); _vinven != _inventory.end(); ++_vinven)
				{
					cout << "for��" << endl;
					cout << "[" << _vinven->itemNum << "] ";
					cout << _vinven->itemName << endl;
					itemInfoSave(1, _vinven->division, _vinven->kind, _vinven->role, _vinven->itemName, _vinven->point, _vinven->req_level, _vinven->req_pwr, _vinven->req_dex, _vinven->req_intel, _vinven->hpOption, _vinven->mpOption, _vinven->pwrOption, _vinven->dexOption, _vinven->intelOption, _vinven->price);
				}
				inven_mm.startMenu();
			break;
			default:
				cout << "�߸��� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
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
		cout << "[" << _vinven->itemNum << "] ";
		cout << _vinven->itemName << endl;
		if (_vinven->role == ITEMROLE::WARRIOR) cout << "[��������] ";
		else if (_vinven->role == ITEMROLE::WIZARD) cout << "[����������] ";
		else if (_vinven->role == ITEMROLE::ELF) cout << "[���� ����] ";
		else if (_vinven->role == ITEMROLE::ALL) cout << "[�������] ";
		if (_vinven->kind == ITEMKIND::WEAPON) cout << "[����] ���ݷ� : " << _vinven->point << "\t";
		else if (_vinven->kind == ITEMKIND::ARMOR) cout << "[��] ���� : " << _vinven->point << "\t";
		else if (_vinven->kind == ITEMKIND::ACC) cout << "[�Ǽ��縮] ���� : " << _vinven->point << "\t";
		else if (_vinven->kind == ITEMKIND::POTION) cout << "[����] ȸ���� : " << _vinven->point << "\t";
		
		cout << endl;
	}
	while (true)
	{
		cout << "========== ������ �󼼺��� UI ==========" << endl;
		cout << "1.������ ����\t 2.�ǵ��ư���" << endl;
		cin >> detailSelectView;
		switch (detailSelectView)
		{
			case 1:
			break;
			case 2:
				inventoryView();
			break;
			default:
				cout << "�߸��� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
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