#include "innClass.h"
#include "MainMenu.h"

MainMenu inn_mm;

innClass::innClass()
{
}

innClass::~innClass()
{
}

void innClass::innMenu()
{
	system("cls");
	int innMenuSelect;
	int innSelect;
	cout << "========== ����(INN) ==========" << endl;
	cout << "1.����(100G)\t 2.�ǵ��ư���" << endl;
	cin >> innMenuSelect;
	while (true)
	{
		switch (innMenuSelect)
		{
			case 1:
				cout << "100G�� �����ϰ� �����Ͻðڽ��ϱ�? (��:1 / �ƴϿ�:2)" << endl;
				cin >> innSelect;
				while (true)
				{
					switch (innSelect)
					{
						case 1:
							if (_money >= 100)
							{
								system("cls");
								cout << "�������� �Ϸ�� �����մϴ�..." << endl;
								cout << "��� ��ó�� ġ��Ǿ����ϴ�." << endl;
								_money = _money - 100;
								cout << "���� �����ݾ� : " << _money << endl;
								_hp = _max_hp;
								_mp = _max_mp;
								Sleep(500);
							}
							else cout << "�����ݾ��� �����մϴ�." << endl;
						break;
						case 2:
							cout << "���� ȭ������ �ǵ��ư��ϴ�." << endl;
						break;
						default:
							cout << "�߸��� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
						continue;
					}
					innMenu();
					break;
				}
			break;
			case 2:
				inn_mm.charactorStatus(1, _roleNum, _name, _level, _max_hp, _add_max_hp, _hp, _max_mp, _add_max_mp, _mp, _pwr, _add_pwr, _mindmg, _dex, _add_dex, _intel, _add_intel, _exp, _totalExp, _money);
				inn_mm.startMenu();
				break;
			default:
				cout << "�߸��� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
			continue;
		}
	}
}

void innClass::charactorStatus(int roleNum, char name[32], int level, int max_hp, int add_max_hp, int hp, int max_mp, int add_max_mp, int mp, int pwr, int add_pwr, int mindmg, int dex, int add_dex, int intel, int add_intel, int exp, int totalExp, int money)
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

void innClass::itemInfoSave(ITEMDIVISION div, ITEMKIND kind, ITEMROLE role, char itemName[32], int point, int req_level, int req_pwr, int req_dex, int req_intel, int hpOption, int mpOption, int pwrOption, int dexOption, int intelOption, int price)
{
	inn_mm.itemInfoSave(1, div, kind, role, itemName, point, req_level, req_pwr, req_dex, req_intel, hpOption, mpOption, pwrOption, dexOption, intelOption, price);
}
