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
	// 1:����, 2:��, 3.�Ǽ��縮, 4.����
	switch (kindNum)
	{
		case 1:
			for (_vitem = _item.begin(); _vitem != _item.end(); ++_vitem)
			{
				itemInit(1);
				if (_vitem->division != STOREITEM) continue;
				if (_vitem->kind != kindNum - 1) continue;
				cout << "���Ź�ȣ : " << _vitem->itemNum << endl;
				cout << "�����۸� : " << _vitem->itemName << endl;
				cout << "���԰������� : ";
				if (_vitem->role == WARRIORITEM) cout << "����" << endl;
				else if (_vitem->role == WIZARDITEM) cout << "������" << endl;
				else if (_vitem->role == ELFITEM) cout << "����" << endl;
				cout << "���ݷ� : " << _vitem->point << endl;
				if (_vitem->pwrOption != 0) cout << "�ɼ�(��) : " << _vitem->pwrOption << endl;
				if (_vitem->dexOption != 0) cout << "�ɼ�(��ø) : " << _vitem->dexOption << endl;
				if (_vitem->intelOption != 0) cout << "�ɼ�(����) : " << _vitem->intelOption << endl;
				cout << "���� : " << _vitem->price << endl;
				cout << endl;
			}
		break;
		case 2:
			for (_vitem = _item.begin(); _vitem != _item.end(); ++_vitem)
			{
				itemInit(1);
				if (_vitem->division != STOREITEM) continue;
				if (_vitem->kind != kindNum - 1) continue;
				cout << "���Ź�ȣ : " << _vitem->itemNum << endl;
				cout << "�����۸� : " << _vitem->itemName << endl;
				cout << "���԰������� : ";
				if (_vitem->role == WARRIORITEM) cout << "����" << endl;
				else if (_vitem->role == WIZARDITEM) cout << "������" << endl;
				else if (_vitem->role == ELFITEM) cout << "����" << endl;
				cout << "���ݷ� : " << _vitem->point << endl;
				if (_vitem->pwrOption != 0) cout << "�ɼ�(��) : " << _vitem->pwrOption << endl;
				if (_vitem->dexOption != 0) cout << "�ɼ�(��ø) : " << _vitem->dexOption << endl;
				if (_vitem->intelOption != 0) cout << "�ɼ�(����) : " << _vitem->intelOption << endl;
				cout << "���� : " << _vitem->price << endl;
				cout << endl;
			}
		break;
		case 3:
		break;
		case 4:
		break;
	}
	purchaseMenu(kindNum);
}

void itemList::purchaseMenu(int kindNum)
{
	while (true)
	{
		int purchaseNum;
		int purchaseMenuSelect;
		int equipSelect;
		cout << "========== ITEM UI ==========" << endl;
		cout << "1.����\t 2.�ǵ��ư���" << endl;
		cin >> purchaseMenuSelect;

		switch (purchaseMenuSelect)
		{
			case 1:
				cout << "���� ������ ��ȣ�� �Է��ϼ���." << endl;
				cin >> purchaseNum;
				for (_vitem = _item.begin(); _vitem != _item.end(); ++_vitem)
				{
					if (purchaseNum == _vitem->itemNum)
					{
						if (_vitem->kind != kindNum - 1) continue;
						if (_money >= _vitem->price)
						{
							system("cls");
							_money = _money - _vitem->price;
							if (_vitem->division != STOREITEM) continue;
							if (_vitem->kind != kindNum - 1) continue;
							cout << "���Ź�ȣ : " << _vitem->itemNum << endl;
							cout << "�����۸� : " << _vitem->itemName << endl;
							cout << "���밡������ : ";
							if (_vitem->role == WARRIORITEM) cout << "����" << endl;
							else if (_vitem->role == WIZARDITEM) cout << "������" << endl;
							else if (_vitem->role == ELFITEM) cout << "����" << endl;
							cout << "���ݷ� : " << _vitem->point << endl;
							if (_vitem->pwrOption != 0) cout << "�ɼ�(��) : " << _vitem->pwrOption << endl;
							if (_vitem->dexOption != 0) cout << "�ɼ�(��ø) : " << _vitem->dexOption << endl;
							if (_vitem->intelOption != 0) cout << "�ɼ�(����) : " << _vitem->intelOption << endl;
							cout << "���� : " << _vitem->price << endl;
							cout << "�ش� �������� �����Ͻðڽ��ϱ�? (��:1 / �ƴϿ�:2)" << endl;
							cin >> equipSelect;
							switch (equipSelect)
							{
								case 1:
									il_mm.charactorStatus(1, _roleNum, _name, _level, _max_hp, _add_max_hp, _hp, _max_mp, _add_max_mp, _mp, _pwr, _add_pwr, _mindmg, _dex, _add_dex, _intel, _add_intel, _exp, _totalExp, _money);
									inventorySaveTemp(_vitem->kind, _vitem->role, _vitem->itemName, _vitem->req_level, _vitem->req_pwr, _vitem->req_dex, _vitem->req_intel, _vitem->point, _vitem->pwrOption, _vitem->dexOption, _vitem->intelOption, _vitem->price);
									il_mm.store();
								break;
								case 2:
									il_mm.charactorStatus(1, _roleNum, _name, _level, _max_hp, _add_max_hp, _hp, _max_mp, _add_max_mp, _mp, _pwr, _add_pwr, _mindmg, _dex, _add_dex, _intel, _add_intel, _exp, _totalExp, _money);
									inventorySaveTemp(_vitem->kind, _vitem->role, _vitem->itemName, _vitem->req_level, _vitem->req_pwr, _vitem->req_dex, _vitem->req_intel, _vitem->point, _vitem->pwrOption, _vitem->dexOption, _vitem->intelOption, _vitem->price);
									il_mm.store();
								break;
								default:
									cout << "�߸��� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
									system("cls");
								continue;
							}
						}						
						else
						{
							cout << "�����ݾ��� �����մϴ�." << endl;
							cout << "������ �ݾ� : " << _vitem->price - _money << " G" << endl;
						}
					}
				}
			break;
			case 2:
				il_mm.charactorStatus(1, _roleNum, _name, _level, _max_hp, _add_max_hp, _hp, _max_mp, _add_max_mp, _mp, _pwr, _add_pwr, _mindmg, _dex, _add_dex, _intel, _add_intel, _exp, _totalExp, _money);
				il_mm.store();
			break;
			default:
				cout << "�߸��� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
			break;
		}
	}
}

void itemList::itemInit(int initNum)
{
	if (initNum == 1)
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
	else if (initNum == 2)
	{
		if (_vinven->point <= 0) _vinven->point = 0;
		if (_vinven->pwrOption <= 0) _vinven->pwrOption = 0;
		if (_vinven->dexOption <= 0) _vinven->dexOption = 0;
		if (_vinven->intelOption <= 0) _vinven->intelOption = 0;
		if (_vinven->price <= 0) _vinven->price = 0;
		if (_vinven->req_level <= 0) _vinven->req_level = 1;
		if (_vinven->req_pwr <= 0) _vinven->req_pwr = 0;
		if (_vinven->req_dex <= 0) _vinven->req_dex = 0;
		if (_vinven->req_intel <= 0) _vinven->req_intel = 0;
	}
}

void itemList::charactorStatus(int roleNum, char name[32], int level, int max_hp, int add_max_hp, int hp, int max_mp, int add_max_mp, int mp, int pwr, int add_pwr, int mindmg, int dex, int add_dex, int intel, int add_intel, int exp, int totalExp, int money)
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


void itemList::storeItemSetting(void)
{
	ITEM storeItem1;
	storeItem1.division = STOREITEM;
	storeItem1.kind = WEAPON;
	storeItem1.role = WARRIORITEM;
	strncpy_s(storeItem1.itemName, "�����", 32);
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
	strncpy_s(storeItem2.itemName, "���� �� �ִ� ��ε�ҵ�", 32);
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

	ITEM storeItem3;
	storeItem3.division = STOREITEM;
	storeItem3.kind = ARMOR;
	storeItem3.role = WARRIORITEM;
	strncpy_s(storeItem3.itemName, "���� �Ǳ� ����", 32);
	storeItem3.req_level = 1;
	storeItem3.req_pwr = 3;
	storeItem3.req_dex = 1;
	storeItem3.req_intel = 0;
	storeItem3.point = 5;
	storeItem3.pwrOption = 1;
	storeItem3.dexOption = 0;
	storeItem3.price = 400;
	storeItem3.itemNum = 1;
	_item.push_back(storeItem3);
}

void itemList::inventorySaveTemp(int kind, int role, char itemName[32], int req_level, int req_pwr, int req_dex, int req_intel, int point, int pwrOption, int dexOption, int intelOption, int price)
{
	INVENTORY inventory;
	inventory.division = STOREITEM;
	inventory.kind = ITEMKIND(kind);
	inventory.role = ITEMROLE(role);
	strncpy_s(inventory.itemName, itemName, 32);
	inventory.req_level = req_level;
	inventory.req_pwr = req_pwr;
	inventory.req_dex = req_dex;
	inventory.req_intel = req_intel;
	inventory.point = point;
	inventory.pwrOption = pwrOption;
	inventory.dexOption = dexOption;
	inventory.intelOption = intelOption;
	inventory.price = price;
	_inventory.push_back(inventory);
}

void itemList::inventoryViewTemp(void)
{
	//cout << "����" << endl;
	int itemNum = 1;
	for (_vinven = _inventory.begin(); _vinven != _inventory.end(); ++_vinven)
	{
		itemInit(2);
		cout << "���Ź�ȣ : " << itemNum << endl;
		cout << "�����۸� : " << _vinven->itemName << endl;
		cout << "���밡������ : ";
		if (_vinven->role == WARRIORITEM) cout << "����" << endl;
		else if (_vinven->role == WIZARDITEM) cout << "������" << endl;
		else if (_vinven->role == ELFITEM) cout << "����" << endl;
		cout << "���ݷ� : " << _vinven->point << endl;
		if (_vinven->pwrOption != 0) cout << "�ɼ�(��) : " << _vinven->pwrOption << endl;
		if (_vinven->dexOption != 0) cout << "�ɼ�(��ø) : " << _vinven->dexOption << endl;
		if (_vinven->intelOption != 0) cout << "�ɼ�(����) : " << _vinven->intelOption << endl;
		cout << "�������� ���� : " << _vinven->req_level << endl;
		cout << "�������� �� : " << _vinven->req_pwr << endl;
		cout << "�������� ��ø : " << _vinven->req_dex << endl;
		cout << "�������� ���� : " << _vinven->req_intel << endl;
		cout << "====================" << endl;
		itemNum++;
	}
}
