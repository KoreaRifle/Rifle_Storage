#include "dungeonClass.h"

userStats us;

dungeonClass::dungeonClass()
{
}


dungeonClass::~dungeonClass()
{
}

void dungeonClass::dungeonMain(void)
{
	srand(time(NULL));
	setMonster();
	while (true)
	{
		int dungeonSelect;
		cout << "��� ������ Ž���Ͻðڽ��ϱ�?" << endl;
		cout << "1.�߳� �Ÿ� \t 2.������ ������ \t 3.�� �ð��� \t 4.�ݴ��� ��" << endl;
		cin >> dungeonSelect;


		switch (dungeonSelect)
		{
		case 1:
			strncpy_s(_dungeonName, "�߳� �Ÿ�", 32);
			enterDungeon(DUNGEON1, _dungeonName);
			break;
		case 2:
			strncpy_s(_dungeonName, "������ ������", 32);
			enterDungeon(DUNGEON2, _dungeonName);
			break;
		case 3:
			strncpy_s(_dungeonName, "�� �ð���", 32);
			enterDungeon(DUNGEON3, _dungeonName);
			break;
		case 4:
			strncpy_s(_dungeonName, "�ݴ��� ��", 32);
			enterDungeon(DUNGEON4, _dungeonName);
			break;
		default:
			cout << "�߸��� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
			continue;
		}
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

		// �������̽� �ۿ�
		while (_vMonster->hp > 0)
		{
			system("cls");
			// ���� �������̽� ���
			// userInterface ���� �� ������ �� ��µ�...
			userInterface();
			cout << "���Ͱ� �����Ͽ����ϴ�." << endl;
			cout << "�����̸� : " << _vMonster->name << endl;
			cout << "HP : " << _vMonster->hp << endl;

			int interfaceSelect;
			cout << "1.�����ϱ� \t 2.���� \t 3.����ġ��" << endl;
			cin >> interfaceSelect;

			switch (interfaceSelect)
			{
			case 1:
				cout << "[�ӽ�]�÷��̾ �����Ͽ� " << _vMonster->name << "�� HP�� 30 �����Ͽ����ϴ�." << endl;
				
				break;
			case 2:
				break;
			case 3:
				break;
			default:
				cout << "�߸��� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
				continue;
			}
		}
	}
}

void dungeonClass::setMonster(void)
{
	tagMONSTERSTATS d1_monster1;
	d1_monster1.dl = DUNGEON1;
	d1_monster1.callNum = 1;
	strncpy_s(d1_monster1.name, "����1", 32);
	d1_monster1.hp = 50;
	d1_monster1.pwr = 1;
	d1_monster1.dex = 1;
	d1_monster1.exp = 1;
	d1_monster1.money = 100;
	_monster.push_back(d1_monster1);

	tagMONSTERSTATS d1_monster2;
	d1_monster2.dl = DUNGEON1;
	d1_monster2.callNum = 2;
	strncpy_s(d1_monster2.name, "����2", 32);
	d1_monster2.hp = 60;
	d1_monster2.pwr = 2;
	d1_monster2.dex = 2;
	d1_monster2.exp = 2;
	d1_monster2.money = 200;
	_monster.push_back(d1_monster2);

	tagMONSTERSTATS d1_monster3;
	d1_monster3.dl = DUNGEON1;
	d1_monster3.callNum = 3;
	strncpy_s(d1_monster3.name, "����3", 32);
	d1_monster3.hp = 70;
	d1_monster3.pwr = 3;
	d1_monster3.dex = 3;
	d1_monster3.exp = 3;
	d1_monster3.money = 300;
	_monster.push_back(d1_monster3);

	tagMONSTERSTATS d2_monster4;
	d2_monster4.dl = DUNGEON2;
	d2_monster4.callNum = 1;
	strncpy_s(d2_monster4.name, "����4", 32);
	d2_monster4.hp = 70;
	d2_monster4.pwr = 3;
	d2_monster4.dex = 3;
	d2_monster4.exp = 3;
	d2_monster4.money = 300;
	_monster.push_back(d2_monster4);
}

void dungeonClass::charactorStatus(int roleNum, char name[32], int hp, int mp, int pwr, int dex, int intel)
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

void dungeonClass::userInterface(void)
{
	cout << "�г��� : " << _name << endl;
	cout << "����� : " << _hp << endl;
	cout << "���� : " << _mp << endl;
}

