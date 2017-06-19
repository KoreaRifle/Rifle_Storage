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
	cout << "========== 여관(INN) ==========" << endl;
	cout << "1.숙박(100G)\t 2.되돌아가기" << endl;
	cin >> innMenuSelect;
	while (true)
	{
		switch (innMenuSelect)
		{
			case 1:
				cout << "100G를 지불하고 숙박하시겠습니까? (예:1 / 아니오:2)" << endl;
				cin >> innSelect;
				while (true)
				{
					switch (innSelect)
					{
						case 1:
							if (_money >= 100)
							{
								system("cls");
								cout << "여관에서 하룻밤 숙박합니다..." << endl;
								cout << "모든 상처가 치료되었습니다." << endl;
								_money = _money - 100;
								cout << "현재 보유금액 : " << _money << endl;
								_hp = _max_hp;
								_mp = _max_mp;
								Sleep(500);
							}
							else cout << "보유금액이 부족합니다." << endl;
						break;
						case 2:
							cout << "이전 화면으로 되돌아갑니다." << endl;
						break;
						default:
							cout << "잘못된 번호를 입력하셨습니다. 다시 입력해주세요." << endl;
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
				cout << "잘못된 번호를 입력하셨습니다. 다시 입력해주세요." << endl;
			continue;
		}
	}
}

void innClass::charactorStatus(int roleNum, char name[32], int level, int max_hp, int add_max_hp, int hp, int max_mp, int add_max_mp, int mp, int pwr, int add_pwr, int mindmg, int dex, int add_dex, int intel, int add_intel, int exp, int totalExp, int money)
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

void innClass::itemInfoSave(ITEMDIVISION div, ITEMKIND kind, ITEMROLE role, char itemName[32], int point, int req_level, int req_pwr, int req_dex, int req_intel, int hpOption, int mpOption, int pwrOption, int dexOption, int intelOption, int price)
{
	inn_mm.itemInfoSave(1, div, kind, role, itemName, point, req_level, req_pwr, req_dex, req_intel, hpOption, mpOption, pwrOption, dexOption, intelOption, price);
}
