#include "dungeonClass.h"
#include "MainMenu.h"

MainMenu mm;
userStats us;

dungeonClass::dungeonClass()
{
	srand(time(NULL));
}


dungeonClass::~dungeonClass()
{
}

void dungeonClass::dungeonMain(void)
{
	setMonster();
	while (true)
	{
		int dungeonSelect;
		cout << "��� ������ Ž���Ͻðڽ��ϱ�?" << endl;
		cout << "1.�߳� �Ÿ� \t 2.������ ������ \t 3.�� �ð��� \t 4.�ݴ��� �� \t 5.�ǵ��ư���" << endl;
		cin >> dungeonSelect;


		switch (dungeonSelect)
		{
			case 1:
				strncpy_s(_dungeonName, "�߳� �Ÿ�", 32);
				enterDungeon(DUNGEON1, _dungeonName);
			break;
			case 2:
				if (_level >= 2)
				{
					strncpy_s(_dungeonName, "������ ������", 32);
					enterDungeon(DUNGEON2, _dungeonName);
				}
				else cout << "���� ���� ���� : �ּ� ���� 2 �̻�" << endl;
			break;
			case 3:
				if (_level >= 3)
				{
					strncpy_s(_dungeonName, "�� �ð���", 32);
					enterDungeon(DUNGEON3, _dungeonName);
				}
				else cout << "���� ���� ���� : �ּ� ���� 3 �̻�" << endl;
			break;
			case 4:
				if (_level >= 4)
				{
					strncpy_s(_dungeonName, "�ݴ��� ��", 32);
					enterDungeon(DUNGEON4, _dungeonName);
				}
				else cout << "���� ���� ���� : �ּ� ���� 4 �̻�" << endl;
			break;
			case 5:
				mm.charactorStatus(1, _roleNum, _name, _level, _max_hp, _hp, _max_mp, _mp, _pwr, _dex, _intel, _exp, _totalExp);
				mm.startMenu();
			break;
			default:
			cout << "�߸��� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
			continue;
		}
		Sleep(500);
		system("cls");
	}
}

void dungeonClass::enterDungeon(int dungeonNum, char dungeonName[32])
{
	system("cls");
	cout << dungeonName << " ������ �����ϼ̽��ϴ�." << endl;
	int callMonsterNum = rand() % 3 + 1;
	for (_vMonster = _monster.begin(); _vMonster != _monster.end(); ++_vMonster)
	{
		if (dungeonNum != _vMonster->dl) continue;
		if (callMonsterNum != _vMonster->callNum) continue;

		cout << "���Ͱ� �����Ͽ����ϴ�." << endl;

		// �������̽� �ۿ�
		while (_vMonster->hp > 0 && _hp > 0) // ������ �ǰ� 0�̻��̰ų� �÷��̾��� ĳ������ �ǰ� 0 �̻��϶� �ݺ�
		{
			// ����ġ�� Ȯ�� ���� ���
			int runNum; // ����ĥ �� �ִ� Ȯ�� ���� ����
			int randomNum; // ����ĥ �� �ִ� Ȯ�� �� ����
			// monsterPwr �� �÷��̾��� level���� Ŭ ��
			if (_vMonster->monsterPwr > _level)
			{
				runNum = rand() % (_vMonster->monsterPwr - _level);
				randomNum = rand() % (_vMonster->monsterPwr - _level);
			}
			// monsterPwr �� �÷��̾��� level���� �۰ų� ���� ��
			else if (_vMonster->monsterPwr <= _level)
			{
				runNum = rand() % 2;
				randomNum = rand() % 2;
			}
			system("cls");
			userInterface();
			cout << endl;
			cout << "�����̸� : " << _vMonster->name << endl;
			cout << "HP : " << _vMonster->hp << endl;

			int interfaceSelect;
			cout << "�÷��̾��� ���Դϴ�." << endl;
			cout << "1.�����ϱ� \t 2.���� \t 3.����ġ��" << endl;
			cin >> interfaceSelect;

			switch (interfaceSelect)
			{
				case 1:
					attackPoint(); // ���� ���� ���� ������ Ȯ��
				break;
				case 2:
				break;
				case 3:
					if (runNum != randomNum)
					{
						cout << "�������� ���߽��ϴ�." << endl;
						// cout << "runNum / randomNum : " << runNum << " / " << randomNum << endl;
						Sleep(1000);
						break;
					}
					else
					{
						cout << "������ �����ƽ��ϴ�." << endl;
						// cout << "runNum / randomNum : " << runNum << " / " << randomNum << endl;
						Sleep(1000);
						_vMonster->hp = _vMonster->max_hp;
						dungeonMain();
					}
				default:
					cout << "�߸��� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
					system("cls");
				continue;
			}
			monsterAttack(); // ���� ���� ���� ������ Ȯ��
			Sleep(500);
			system("cls");
			continue;
		}
		if (_vMonster->hp <= 0)
		{
			if (_hp > 0)
			{
				cout << "���Ͱ� �׾����ϴ�." << endl;
				cout << "����ġ " << _vMonster->exp << " ȹ��!" << endl;
				_exp = _exp + _vMonster->exp;
				_vMonster->hp = _vMonster->max_hp;
				Sleep(100);
			}
			else
				continue;
		}
		if (_hp <= 0)
		{
			playerDead();
			Sleep(1000);
		}
	}
}

void dungeonClass::charactorStatus(int roleNum, char name[32], int level, int max_hp, int hp, int max_mp, int mp, int pwr, int dex, int intel, int exp, int totalExp)
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
}

void dungeonClass::levelUp(void)
{
	if (_totalExp <= _exp)
	{
		cout << "LEVEL UP!" << endl;
		_exp = _exp - _totalExp;
		_level++;
		// ������ ���
		if (_roleNum == 1)
		{
			_max_hp = _max_hp + 50;
			_hp = _max_hp;
			_max_mp = _max_mp + 20;
			_mp = _max_mp;
			_pwr = _pwr + 3;
			_dex = _dex + 2;
			_intel = _intel + 1;
		}
		else if (_roleNum == 2)
		{
			_max_hp = _max_hp + 30;
			_hp = _max_hp;
			_max_mp = _max_mp + 30;
			_mp = _max_mp;
			_pwr = _pwr + 2;
			_dex = _dex + 3;
			_intel = _intel + 2;
		}
		else if (_roleNum == 3)
		{
			_max_hp = _max_hp + 20;
			_hp = _max_hp;
			_max_mp = _max_mp + 50;
			_mp = _max_mp;
			_pwr = _pwr + 1;
			_dex = _dex + 2;
			_intel = _intel + 3;
		}
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
	else _exp = _exp;
}

void dungeonClass::attackPoint(void)
{
	int userAttackPoint = rand() % 20 + _pwr;
	_vMonster->hp = _vMonster->hp - userAttackPoint;
}

void dungeonClass::monsterAttack(void)
{
	int monsterAttackPoint = rand() % 20 + _pwr;
	cout << "���� ���Դϴ�." << endl;
	_hp = _hp - monsterAttackPoint;
	cout << "���Ͱ� " << monsterAttackPoint << "��ŭ �������� �־����ϴ�." << endl;
}

void dungeonClass::userInterface(void)
{
	cout << "========== " << _name << " ==========" << endl;
	//cout << "���� : " <<  << endl;
	cout << "����� : " << _hp << " / " << _max_hp << endl;
	cout << "���� : " << _mp << " / " << _max_mp << endl;
}

// �÷��̾ �׾��� ��
void dungeonClass::playerDead(void)
{
	cout << "YOU DIED" << endl;
	cout << "����� �׾����ϴ�. ����ġ 10%�� �Ҿ����ϴ�." << endl;

	int tempExp = _exp;
	if (_exp >= 10)
	{
		_exp = _exp - (_exp / 10);
	}
	else if (_exp < 10)
	{
		_exp = _exp - 1;
	}
	else if (_exp == 0 || _exp < 0)
	{
		_exp = 0;
	}
	_hp = _max_hp;
	cout << "�ױ� �� ����ġ : " << tempExp << " / ���� ����ġ : " << _exp << endl;
}

void dungeonClass::setMonster(void)
{
	tagMONSTERSTATS d1_monster1;
	d1_monster1.dl = DUNGEON1;
	d1_monster1.callNum = 1;
	strncpy_s(d1_monster1.name, "����1", 32);
	d1_monster1.max_hp = 50;
	d1_monster1.hp = 50;
	d1_monster1.pwr = 1;
	d1_monster1.dex = 1;
	d1_monster1.exp = 1;
	d1_monster1.money = 100;
	d1_monster1.monsterPwr = 1;
	_monster.push_back(d1_monster1);

	tagMONSTERSTATS d1_monster2;
	d1_monster2.dl = DUNGEON1;
	d1_monster2.callNum = 2;
	strncpy_s(d1_monster2.name, "����2", 32);
	d1_monster2.max_hp = 60;
	d1_monster2.hp = 60;
	d1_monster2.pwr = 2;
	d1_monster2.dex = 2;
	d1_monster2.exp = 2;
	d1_monster2.money = 200;
	d1_monster2.monsterPwr = 3;
	_monster.push_back(d1_monster2);

	tagMONSTERSTATS d1_monster3;
	d1_monster3.dl = DUNGEON1;
	d1_monster3.callNum = 3;
	strncpy_s(d1_monster3.name, "����3", 32);
	d1_monster3.max_hp = 70;
	d1_monster3.hp = 70;
	d1_monster3.pwr = 3;
	d1_monster3.dex = 3;
	d1_monster3.exp = 3;
	d1_monster3.money = 300;
	d1_monster3.monsterPwr = 5;
	_monster.push_back(d1_monster3);

	tagMONSTERSTATS d2_monster1;
	d2_monster1.dl = DUNGEON2;
	d2_monster1.callNum = 1;
	strncpy_s(d2_monster1.name, "����4", 32);
	d2_monster1.max_hp = 80;
	d2_monster1.hp = 80;
	d2_monster1.pwr = 4;
	d2_monster1.dex = 4;
	d2_monster1.exp = 4;
	d2_monster1.money = 300;
	d2_monster1.monsterPwr = 10;
	_monster.push_back(d2_monster1);
}