#include "userStats.h"
#include "MainMenu.h"

dungeonClass dg;

userStats::userStats()
{
}


userStats::~userStats()
{
}

void userStats::charactorStatus(int roleNum, char name[32], int max_hp, int hp, int max_mp, int mp, int pwr, int dex, int intel)
{
	_roleNum = roleNum;
	if (_roleNum == 1) strncpy_s(_roleName, "����", 32);
	else if (_roleNum == 2) strncpy_s(_roleName, "������", 32);
	else if (_roleNum == 3) strncpy_s(_roleName, "����", 32);
	strncpy(_name, name, 32);
	_max_hp = max_hp;
	_hp = hp;
	_max_mp = max_mp;
	_mp = mp;
	_pwr = pwr;
	_dex = dex;
	_intel = intel;
}

void userStats::userInfo(void)
{
	while (true)
	{
		system("cls");
		cout << "========== ĳ���� ���� ==========" << endl;
		cout << "���� : " << _roleName << endl;
		cout << "�г��� : " << _name << endl;
		cout << "����� : " << _hp << " / " << _max_hp << endl;
		cout << "���� : " << _mp << " / " << _max_mp << endl;
		cout << "�� : " << _pwr << endl;
		cout << "��ø : " << _dex << endl;
		cout << "���� : " << _intel << endl;
		cout << "========== INFO MENU ==========" << endl;
		cout << "1.�ǵ��ư���" << endl;
		int backButton;
		cin >> backButton;
		switch (backButton)
		{
			case 1:
				cout << "���� ȭ������ �ǵ��ư��ϴ�." << endl;
				Sleep(500);
			break;
			default:
				cout << "�߸��� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
				Sleep(500);
			continue;
		}
		break;
	}
}

void userStats::userInterface(void)
{
	// �ڲ� ������ ���� ���´�... ������ �𸣰ڴ�...
	cout << "�г��� : " << _name << endl;
	cout << "����� : " << _hp << endl;
	cout << "���� : " << _mp << endl;
}