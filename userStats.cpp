#include "userStats.h"
#include "MainMenu.h"

userStats::userStats()
{
	
}


userStats::~userStats()
{
}

void userStats::charactorStatus(int roleNum, char name[32], int hp, int mp, int pwr, int dex, int intel)
{
	_roleNum = roleNum;
	if (_roleNum == 1) strncpy(_roleName, "����", 32);
	else if (_roleNum == 2) strncpy(_roleName, "������", 32);
	else if (_roleNum == 3) strncpy(_roleName, "����", 32);
	strncpy(_name, name, 32);
	_hp = hp;
	_mp = mp;
	_pwr = pwr;
	_dex = dex;
	_intel = intel;
}

void userStats::testViewChar(void)
{
	cout << "���� : " << _roleName << endl;
	cout << "�г��� : " << _name << endl;
	cout << "HP : " << _hp << endl;
	cout << "MP : " << _mp << endl;
	cout << "PWR : " << _pwr << endl;
	cout << "DEX : " << _dex << endl;
	cout << "INTEL : " << _intel << endl;
}