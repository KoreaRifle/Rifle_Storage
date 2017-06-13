#include "userStats.h"
#include "MainMenu.h"

dungeonClass dg;

userStats::userStats()
{
}


userStats::~userStats()
{
}

void userStats::charactorStatus(int roleNum, char name[32], int level, int max_hp, int hp, int max_mp, int mp, int pwr, int dex, int intel, int exp, int totalExp, int money)
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
			cout << "1.���� ������\t 2.�ǵ��ư���" << endl;
			cin >> backButton;
			switch (backButton)
			{
				case 1:
					system("cls");
					pageNum++;
				break;
				case 2:
					cout << "���� ȭ������ �ǵ��ư��ϴ�." << endl;
					backNum = 0;
					Sleep(500);
				break;
				default:
					cout << "�߸��� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
					Sleep(500);
				continue;
			}
		}

		else if (pageNum > 1 && pageNum != totalPageNum)
		{
			cout << "1.���� ������\t 2.���� ������\t 3.�ǵ��ư���" << endl;
			cin >> backButton;
			switch (backButton)
			{
				case 1:
					system("cls");
					pageNum++;
				break;
				case 2:
					cout << "���� �������� ���ư��ϴ�." << endl;
					pageNum--;
				break;
				case 3:
					cout << "���� ȭ������ �ǵ��ư��ϴ�." << endl;
					backNum = 0;
					Sleep(500);
				break;
				default:
					cout << "�߸��� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
					Sleep(500);
				continue;
			}
		}

		else if (pageNum > 1 && pageNum == totalPageNum)
		{
			cout << "1.���� ������\t 2.�ǵ��ư���" << endl;
			cin >> backButton;
			switch (backButton)
			{
				case 1:
					cout << "���� �������� ���ư��ϴ�." << endl;
					pageNum--;
				break;
				case 2:
					cout << "���� ȭ������ �ǵ��ư��ϴ�." << endl;
					backNum = 0;
					Sleep(500);
				break;
				default:
					cout << "�߸��� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
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
		cout << "========== ĳ���� ���� (" << pageNum << " / " << totalPageNum << ") ==========" << endl;
		cout << "���� : " << _roleName << endl;
		cout << "�г��� : " << _name << endl;
		cout << "���� : " << _level << endl;
		cout << "����ġ : " << _exp << " / " << _totalExp << endl;
		cout << "����� : " << _hp << " / " << _max_hp << endl;
		cout << "���� : " << _mp << " / " << _max_mp << endl;
		cout << "�� : " << _pwr << endl;
		cout << "��ø : " << _dex << endl;
		cout << "���� : " << _intel << endl;
	}
	else if (pageNum == 2)
	{
		cout << "========== ĳ���� ���� (" << pageNum << " / " << totalPageNum << ") ==========" << endl;
		cout << "�����ݾ� : " << _money << " G" << endl;
	}
	else if (pageNum == 3)
	{
		cout << "========== ĳ���� ���� (" << pageNum << " / " << totalPageNum << ") ==========" << endl;
		cout << "�̱��� ���� -> ������� �� ��Ʈ���� ��¿���" << endl;
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