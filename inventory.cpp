#include "inventory.h"
#include "MainMenu.h"
#include "userStats.h"

inventory::inventory()
{
}


inventory::~inventory()
{
}

void inventory::charactorStatus(int roleNum, char name[32], int level, int max_hp, int add_max_hp, int hp, int max_mp, int add_max_mp, int mp, int pwr, int add_pwr, int mindmg, int dex, int add_dex, int intel, int add_intel, int exp, int totalExp, int money)
{
	//MainMenu *inven_mm;
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

void inventory::moneyInfo(int money)
{
	_money = money;
}

int inventory::itemInfoSave(vector<_tagITEM> _ITEM)
{
	int num = 0;
	if (_inventory.size() != _maxInventorySize) // �κ��丮�� �ִ� 10�������� ������ ���� ����
	{
		INVENTORY userInven;

		for (_vITEM = _ITEM.begin(); _vITEM != _ITEM.end(); ++_vITEM)
		{
			userInven.division = ITEMDIVISION(_vITEM->ti_division);
			userInven.kind = ITEMKIND(_vITEM->ti_kind);
			userInven.role = ITEMROLE(_vITEM->ti_itemRole);
			strncpy_s(userInven.itemName, _vITEM->ti_itemName, 32);
			userInven.point = _vITEM->ti_point;
			userInven.req_level = _vITEM->ti_req_level;
			userInven.req_pwr = _vITEM->ti_req_pwr;
			userInven.req_dex = _vITEM->ti_req_dex;
			userInven.req_intel = _vITEM->ti_req_intel;
			userInven.hpOption = _vITEM->ti_hpOption;
			userInven.mpOption = _vITEM->ti_mpOption;
			userInven.pwrOption = _vITEM->ti_pwrOption;
			userInven.dexOption = _vITEM->ti_dexOption;
			userInven.intelOption = _vITEM->ti_intelOption;
			userInven.price = _vITEM->ti_price;
			userInven.itemNum = _inventory.size() + 1;
			_inventory.push_back(userInven);
			num++;
		}
	}
	else // �κ��丮�� 10�� �̻��� ������ ���� �� ���� ���� �߻�
	{
		cout << "���� ������ �����մϴ�." << endl;
		Sleep(1000);
	}
	return _inventory.size();
}

int inventory::maxInventorySizeReturn(void)
{
	return _maxInventorySize;
}

int inventory::inventoryView(void)
{
	bool exit = 0;
	int inventorySelectNum;
	int sellPrice = _money;
	while (exit != 1)
	{
		if (_inventory.size() == 0)
		{
			system("cls");
			cout << "�κ��丮 ���� �������� �������� �ʽ��ϴ�." << endl;
			Sleep(1000);
			break;
		}
		system("cls");
		cout << "========== �κ��丮 â ==========" << endl;
		for (_vinven = _inventory.begin(); _vinven != _inventory.end(); ++_vinven)
		{
			if (_vinven->itemNum == 0) continue;
			cout << "[" << _vinven->itemNum << "] ";
			cout << _vinven->itemName;
			cout << endl;
		}
		cout << endl;
		cout << "========== �κ��丮 UI ==========" << endl;
		cout << "1.�󼼺���\t 2.�������Ǹ�\t 3.�ǵ��ư���" << endl;
		cin >> inventorySelectNum;
		switch (inventorySelectNum)
		{
			case 1:
				inventoryDetailView();
			break;
			case 2:
				sellPrice = inventoryItemSell();
			break;
			case 3:
				exit = 1;
			break;
			default:
				cout << "�߸��� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
			break;
		}
	}
	return sellPrice;
}

void inventory::inventoryDetailView(void)
{
	bool exit = 0;
	int detailSelectView;
	for (_vinven = _inventory.begin(); _vinven != _inventory.end(); ++_vinven)
	{
		itemInit();
		if (_vinven->itemNum == 0) continue;
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
	}
	while (exit != 1)
	{
		cout << endl;
		cout << "========== ������ �󼼺��� UI ==========" << endl;
		cout << "1.������ ����\t 2.�ǵ��ư���" << endl;
		cin >> detailSelectView;
		switch (detailSelectView)
		{
			case 1:
			break;
			case 2:
				exit = 1;
			break;
			default:
				cout << "�߸��� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
			continue;
		}
	}
}

int inventory::inventoryItemSell(void)
{
	bool exit = 0;
	int outputline = 1;
	int itemSellMenuSelect;
	int sellItemNum;
	int tempNum = 0;
	while (exit != 1)
	{
		for (_vinven = _inventory.begin(); _vinven != _inventory.end(); ++_vinven)
		{
			if (outputline < 4)
			{
				cout << "[" << _vinven->itemNum << "]" << _vinven->itemName << " ";
				outputline++;
			}
			else
			{
				cout << endl;
				cout << "[" << _vinven->itemNum << "]" << _vinven->itemName << " ";
				outputline = 1;
			}
			cout << endl;
		}
		cout << "========== ������ �Ǹ� ==========" << endl;
		cout << "1.�������Ǹ�\t 2.�ǵ��ư���" << endl;
		cin >> itemSellMenuSelect;
		switch (itemSellMenuSelect)
		{
			case 1:
				cout << "�Ǹ��� ������ ��ȣ�� �Է��ϼ���." << endl;
				cin >> sellItemNum;
				if (sellItemNum <= _inventory.size() + 1)
				{
					for (_vinven = _inventory.begin(); _vinven != _inventory.end(); ++_vinven)
					{
						if (_vinven->itemNum == _inventory.at(sellItemNum - 1).itemNum)
						{
							cout << _vinven->itemNum << "�� " << _vinven->itemName << "�� ���õǾ����ϴ�." << endl;
							// ������ �� ����(���������� 2���� 1 ����)��ŭ ���������ݿ��� ����
							_money = _money + (_vinven->price) / 2;
						}
						break;
					}
					_inventory.erase(_inventory.begin() + sellItemNum - 1);
					// ������ �����͸� �������� itemNum �� -1�� ����
					if (_inventory.size() == 0) _itemNum = 1; // ������ ���� �� �κ��丮 ����� 0�� ���
					if (_inventory.size() != sellItemNum - 1)
					{
						for (_vinven = _inventory.begin() + sellItemNum - 1; _vinven != _inventory.end(); ++_vinven)
						{
							_vinven->itemNum = _vinven->itemNum - 1;
						}
					}
					tempNum = 0;
				}
				else
				{
					cout << "������ ��ȣ�� �������� �ʽ��ϴ�." << endl;
				}
			break;
			case 2:
				exit = 1;
			break;
			default:
				cout << "�߸��� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
			continue;
		}
	}
	return _money;
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