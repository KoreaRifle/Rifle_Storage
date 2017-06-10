#include "userStats.h"
#include "MainMenu.h"

dungeonClass dg;

userStats::userStats()
{
}


userStats::~userStats()
{
}

void userStats::charactorStatus(int roleNum, char name[32], int max_hp, int hp, int max_mp, int mp, int pwr, int dex, int intel, int totalExp)
{
	_roleNum = roleNum;
	if (_roleNum == 1) strncpy_s(_roleName, "전사", 32);
	else if (_roleNum == 2) strncpy_s(_roleName, "마법사", 32);
	else if (_roleNum == 3) strncpy_s(_roleName, "엘프", 32);
	strncpy(_name, name, 32);
	_max_hp = max_hp;
	_hp = hp;
	_max_mp = max_mp;
	_mp = mp;
	_pwr = pwr;
	_dex = dex;
	_intel = intel;
	_totalExp = totalExp;
}

void userStats::userInfo(void)
{
	while (true)
	{
		system("cls");
		cout << "========== 캐릭터 정보 ==========" << endl;
		cout << "종족 : " << _roleName << endl;
		cout << "닉네임 : " << _name << endl;
		cout << "레벨 : " << _level << endl;
		cout << "생명력 : " << _hp << " / " << _max_hp << endl;
		cout << "마나 : " << _mp << " / " << _max_mp << endl;
		cout << "힘 : " << _pwr << endl;
		cout << "민첩 : " << _dex << endl;
		cout << "지능 : " << _intel << endl;
		cout << "========== INFO MENU ==========" << endl;
		cout << "1.되돌아가기" << endl;
		int backButton;
		cin >> backButton;
		switch (backButton)
		{
			case 1:
				cout << "이전 화면으로 되돌아갑니다." << endl;
				Sleep(500);
			break;
			default:
				cout << "잘못된 번호를 입력하셨습니다. 다시 입력해주세요." << endl;
				Sleep(500);
			continue;
		}
		break;
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