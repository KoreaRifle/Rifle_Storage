#include "innClass.h"

MainMenu mm;

innClass::innClass()
{
}

innClass::~innClass()
{
}

void innClass::innMenu()
{
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
						break;
						default:
							cout << "�߸��� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
						continue;
					}
				}
			break;
			case 2:
				mm.charactorStatus(1, _roleNum, _name, _level, _max_hp, _hp, _max_mp, _mp, _pwr, _dex, _intel, _exp, _totalExp, _money);
				mm.startMenu();
				break;
			default:
				cout << "�߸��� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
			continue;
		}
		break;
	}
}

void innClass::charactorStatus(int roleNum, char name[32], int level, int max_hp, int hp, int max_mp, int mp, int pwr, int dex, int intel, int exp, int totalExp, int money)
{
	_roleNum = roleNum;
	if (_roleNum == 1) strncpy_s(_roleName, "����", 32);
	else if (_roleNum == 2) strncpy_s(_roleName, "������", 32);
	else if (_roleNum == 3) strncpy_s(_roleName, "����", 32);
	strncpy_s(_name, name, 32);
	_level = level;
	_max_hp = max_hp;
	_hp = hp;
	_max_mp = max_mp;
	_mp = mp;
	_pwr = pwr;
	_dex = dex;
	_intel = intel;
	_exp = exp;
	_totalExp = totalExp;
	_money = money;
}