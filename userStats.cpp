#include "userStats.h"
#include "MainMenu.h"

MainMenu *us_mm;
dungeonClass *dg;

userStats::userStats()
{
}


userStats::~userStats()
{
}

void userStats::charactorStatus(int roleNum, char name[32], int level, int max_hp, int add_max_hp, int hp, int max_mp, int add_max_mp, int mp, int pwr, int add_pwr, int mindmg, int dex, int add_dex, int intel, int add_intel, int exp, int totalExp, int money)
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

void userStats::moneyInfo(int money)
{
	_money = money;
}

void userStats::userInfo(void)
{
	int pageNum = 1;
	int totalPageNum = 3;
	bool backNum = 1;
	while (backNum == 1)
	{
		system("cls");
		userInfo_pageNum(pageNum, totalPageNum);

		cout << "========== INFO MENU ==========" << endl;
		int backButton;
		if (pageNum == 1)
		{
			cout << "1.다음 페이지\t 2.되돌아가기" << endl;
			cin >> backButton;
			switch (backButton)
			{
				case 1:
					system("cls");
					pageNum++;
				break;
				case 2:
					cout << "이전 화면으로 되돌아갑니다." << endl;
					backNum = 0;
					Sleep(500);
				break;
				default:
					cout << "잘못된 번호를 입력하셨습니다. 다시 입력해주세요." << endl;
					Sleep(500);
				continue;
			}
		}

		else if (pageNum > 1 && pageNum != totalPageNum)
		{
			cout << "1.다음 페이지\t 2.이전 페이지\t 3.되돌아가기" << endl;
			cin >> backButton;
			switch (backButton)
			{
				case 1:
					system("cls");
					pageNum++;
				break;
				case 2:
					cout << "이전 페이지로 돌아갑니다." << endl;
					pageNum--;
				break;
				case 3:
					cout << "이전 화면으로 되돌아갑니다." << endl;
					backNum = 0;
					Sleep(500);
				break;
				default:
					cout << "잘못된 번호를 입력하셨습니다. 다시 입력해주세요." << endl;
					Sleep(500);
				continue;
			}
		}

		else if (pageNum > 1 && pageNum == totalPageNum)
		{
			cout << "1.이전 페이지\t 2.되돌아가기" << endl;
			cin >> backButton;
			switch (backButton)
			{
				case 1:
					cout << "이전 페이지로 돌아갑니다." << endl;
					pageNum--;
				break;
				case 2:
					cout << "이전 화면으로 되돌아갑니다." << endl;
					backNum = 0;
					Sleep(500);
				break;
				default:
					cout << "잘못된 번호를 입력하셨습니다. 다시 입력해주세요." << endl;
					Sleep(500);
				continue;
			}
		}
	}
}

void userStats::userInfo_pageNum(int pageNum, int totalPageNum)
{
	if (pageNum == 1)
	{
		cout << "========== 캐릭터 정보 (" << pageNum << " / " << totalPageNum << ") ==========" << endl;
		cout << "직업 : " << _roleName << endl;
		cout << "닉네임 : " << _name << endl;
		cout << "레벨 : " << _level << endl;
		cout << "경험치 : " << _exp << " / " << _totalExp << endl;
		cout << "생명력 : " << _hp << " / " << _max_hp << " + " << _add_max_hp << endl;
		cout << "마나 : " << _mp << " / " << _max_mp << " + " << _add_max_mp << endl;
		cout << "힘 : " << _pwr << " + " << _add_pwr << endl;
		cout << "민첩 : " << _dex << " + " << _add_dex << endl;
		cout << "지능 : " << _intel << " + " << _add_intel << endl;
	}
	else if (pageNum == 2)
	{
		cout << "========== 캐릭터 정보 (" << pageNum << " / " << totalPageNum << ") ==========" << endl;
		cout << "소지금액 : " << _money << " G" << endl;
	}
	else if (pageNum == 3)
	{
		cout << "========== 캐릭터 정보 (" << pageNum << " / " << totalPageNum << ") ==========" << endl;
		cout << "미구현 상태 -> 착용장비 및 세트정보 출력예정" << endl;
	}
}

void userStats::levelUp(int exp)
{
	if (_exp + exp >= _totalExp)
	{
		_level++;
		_exp = _exp - _totalExp;
		_totalExp = _totalExp * 2;
	}
	else
	{
		_exp = _exp + exp;
	}
}

void userStats::itemInfoSave(ITEMDIVISION div, ITEMKIND kind, ITEMROLE role, char itemName[32], int point, int req_level, int req_pwr, int req_dex, int req_intel, int hpOption, int mpOption, int pwrOption, int dexOption, int intelOption, int price)
{
	//us_mm->itemInfoSave(1, div, kind, role, itemName, point, req_level, req_pwr, req_dex, req_intel, hpOption, mpOption, pwrOption, dexOption, intelOption, price);
}
