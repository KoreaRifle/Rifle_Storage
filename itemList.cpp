#include "itemList.h"
#include "MainMenu.h"
#include "inventory.h"

MainMenu il_mm;
inventory il_inven;

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
	// 1:����, 2:��, 3:�Ǽ��縮, 4:���� 5:����
	switch (kindNum)
	{
		case 1:
			for (_vitem = _item.begin(); _vitem != _item.end(); ++_vitem)
			{
				itemInit(1);
				if (_vitem->division != ITEMDIVISION::STOREITEM) continue;
				if (_vitem->kind != ITEMKIND(kindNum - 1)) continue;
				cout << "���Ź�ȣ : " << _vitem->itemNum << endl;
				cout << "�����۸� : " << _vitem->itemName << endl;
				cout << "���԰������� : ";
				if (_vitem->role == ITEMROLE::WARRIOR) cout << "����" << endl;
				else if (_vitem->role == ITEMROLE::WIZARD) cout << "������" << endl;
				else if (_vitem->role == ITEMROLE::ELF) cout << "����" << endl;
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
				if (_vitem->division != ITEMDIVISION::STOREITEM) continue;
				if (_vitem->kind != ITEMKIND(kindNum - 1)) continue;
				cout << "���Ź�ȣ : " << _vitem->itemNum << endl;
				cout << "�����۸� : " << _vitem->itemName << endl;
				cout << "���԰������� : ";
				if (_vitem->role == ITEMROLE::WARRIOR) cout << "����" << endl;
				else if (_vitem->role == ITEMROLE::WIZARD) cout << "������" << endl;
				else if (_vitem->role == ITEMROLE::ELF) cout << "����" << endl;
				cout << "���� : " << _vitem->point << endl;
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
						if (_vitem->kind != ITEMKIND(kindNum - 1)) continue;
						if (_money >= _vitem->price)
						{
							system("cls");
							_money = _money - _vitem->price;
							il_mm.charactorStatus(1, _roleNum, _name, _level, _max_hp, _add_max_hp, _hp, _max_mp, _add_max_mp, _mp, _pwr, _add_pwr, _mindmg, _dex, _add_dex, _intel, _add_intel, _exp, _totalExp, _money);
							if (_vitem->division != ITEMDIVISION::STOREITEM) continue;
							if (_vitem->kind != ITEMKIND(kindNum - 1)) continue;
							itemInfoSave(_vitem->division, _vitem->kind, _vitem->role, _vitem->itemName, _vitem->req_level, _vitem->req_pwr, _vitem->req_dex, _vitem->req_intel, _vitem->hpOption, _vitem->mpOption, _vitem->point, _vitem->pwrOption, _vitem->dexOption, _vitem->intelOption, _vitem->price);
							cout << "���Ź�ȣ : " << _vitem->itemNum << endl;
							cout << "�����۸� : " << _vitem->itemName << endl;
							cout << "���밡������ : ";
							if (_vitem->role == ITEMROLE::WARRIOR) cout << "����" << endl;
							else if (_vitem->role == ITEMROLE::WIZARD) cout << "������" << endl;
							else if (_vitem->role == ITEMROLE::ELF) cout << "����" << endl;
							cout << "���ݷ� : " << _vitem->point << endl;
							if (_vitem->pwrOption != 0) cout << "�ɼ�(��) : " << _vitem->pwrOption << endl;
							if (_vitem->dexOption != 0) cout << "�ɼ�(��ø) : " << _vitem->dexOption << endl;
							if (_vitem->intelOption != 0) cout << "�ɼ�(����) : " << _vitem->intelOption << endl;
							cout << "���� : " << _vitem->price << endl;
							cout << "======================================" << endl;
							cout << "�ش� �������� �����Ͻðڽ��ϱ�? (��:1 / �ƴϿ�:2)" << endl;
							cin >> equipSelect;
							switch (equipSelect)
							{
								case 1:
									/*for (_vinven = _inventory.begin(); _vinven != _inventory.end(); ++_vinven)
									{
										il_mm.itemInfoSave(0, _vinven->division, _vinven->kind, _vinven->role, _vinven->itemName, _vinven->point, _vinven->req_level, _vinven->req_pwr, _vinven->req_dex, _vinven->req_intel, _vinven->hpOption, _vinven->mpOption, _vinven->pwrOption, _vinven->dexOption, _vinven->intelOption, _vinven->price);
									}*/
									il_mm.store();
								break;
								case 2:
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
		if (_vitem->hpOption <= 0) _vitem->hpOption = 0;
		if (_vitem->mpOption <= 0) _vitem->mpOption = 0;
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


void itemList::itemInfoSave(ITEMDIVISION div, ITEMKIND kind, ITEMROLE role, char itemName[32], int point, int req_level, int req_pwr, int req_dex, int req_intel, int hpOption, int mpOption, int pwrOption, int dexOption, int intelOption, int price)
{
	/*INVENTORY inventory;
	inventory.division = division;
	inventory.kind = kind;
	inventory.role = role;
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
	_inventory.push_back(inventory);*/
	//cout << "[itemList] itemInfoSave ���� ��" << endl;

	il_mm.itemInfoSave(0, div, kind, role, itemName, point, req_level, req_pwr, req_dex, req_intel, hpOption, mpOption, pwrOption, dexOption, intelOption, price);
}

void itemList::storeItemSetting(void)
{
	ITEM storeItem_weapon1;
	storeItem_weapon1.division = ITEMDIVISION::STOREITEM;
	storeItem_weapon1.kind = ITEMKIND::WEAPON;
	storeItem_weapon1.role = ITEMROLE::WARRIOR;
	strncpy_s(storeItem_weapon1.itemName, "�����", 32);
	storeItem_weapon1.req_level = 1;
	storeItem_weapon1.req_pwr = 3;
	storeItem_weapon1.req_dex = 1;
	storeItem_weapon1.req_intel = 0;
	storeItem_weapon1.point = 5;
	storeItem_weapon1.pwrOption = 1;
	storeItem_weapon1.price = 500;
	storeItem_weapon1.itemNum = 1;
	_item.push_back(storeItem_weapon1);

	ITEM storeItem_weapon2;
	storeItem_weapon2.division = ITEMDIVISION::STOREITEM;
	storeItem_weapon2.kind = ITEMKIND::WEAPON;
	storeItem_weapon2.role = ITEMROLE::WARRIOR;
	strncpy_s(storeItem_weapon2.itemName, "���� �� �ִ� ��ε�ҵ�", 32);
	storeItem_weapon2.req_level = 2;
	storeItem_weapon2.req_pwr = 8;
	storeItem_weapon2.req_dex = 5;
	storeItem_weapon2.req_intel = 0;
	storeItem_weapon2.point = 15;
	storeItem_weapon2.pwrOption = 3;
	storeItem_weapon2.dexOption = 1;
	storeItem_weapon2.price = 1200;
	storeItem_weapon2.itemNum = storeItem_weapon1.itemNum + 1;
	_item.push_back(storeItem_weapon2);

	ITEM storeItem_armor1;
	storeItem_armor1.division = ITEMDIVISION::STOREITEM;
	storeItem_armor1.kind = ITEMKIND::ARMOR;
	storeItem_armor1.role = ITEMROLE::WARRIOR;
	strncpy_s(storeItem_armor1.itemName, "���� �Ǳ� ����", 32);
	storeItem_armor1.req_level = 1;
	storeItem_armor1.req_pwr = 3;
	storeItem_armor1.req_dex = 1;
	storeItem_armor1.req_intel = 0;
	storeItem_armor1.point = 5;
	storeItem_armor1.pwrOption = 1;
	storeItem_armor1.dexOption = 0;
	storeItem_armor1.price = 400;
	storeItem_armor1.itemNum = 1;
	_item.push_back(storeItem_armor1);

	ITEM storeItem_armor2;
	storeItem_armor2.division = ITEMDIVISION::STOREITEM;
	storeItem_armor2.kind = ITEMKIND::ARMOR;
	storeItem_armor2.role = ITEMROLE::WARRIOR;
	strncpy_s(storeItem_armor2.itemName, "�÷���Ʈ �Ƹ�", 32);
	storeItem_armor2.req_level = 2;
	storeItem_armor2.req_pwr = 8;
	storeItem_armor2.req_dex = 3;
	storeItem_armor2.req_intel = 0;
	storeItem_armor2.point = 12;
	storeItem_armor2.pwrOption = 3;
	storeItem_armor2.dexOption = 1;
	storeItem_armor2.price = 3000;
	storeItem_armor2.itemNum = storeItem_armor1.itemNum + 1;
	_item.push_back(storeItem_armor2);
}
