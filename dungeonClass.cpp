#include "dungeonClass.h"

dungeonClass::dungeonClass()
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
				enterDungeon(TEMP1, _dungeonName);
			break;
			case 2:
				strncpy_s(_dungeonName, "������ ������", 32);
				enterDungeon(TEMP2, _dungeonName);
			break;
			case 3:
				strncpy_s(_dungeonName, "�� �ð���", 32);
				enterDungeon(TEMP3, _dungeonName);
			break;
			case 4:
				strncpy_s(_dungeonName, "�ݴ��� ��", 32);
				enterDungeon(TEMP4, _dungeonName);
			break;
			default:
				cout << "�߸��� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
			continue;
		}
	}
}


dungeonClass::~dungeonClass()
{
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
			cout << "���Ͱ� �����Ͽ����ϴ�." << endl;
			cout << "�����̸� : " << _vMonster->name << endl;
			cout << "HP : " << _vMonster->hp << endl;

			int interfaceSelect;
			cout << "1.�����ϱ� \t 2.���� \t 3.����ġ��" << endl;
			cin >> interfaceSelect;

			switch (interfaceSelect)
			{
			case 1:
				cout << "�÷��̾ �����Ͽ� " << _vMonster->name << "�� HP�� 30 �����Ͽ����ϴ�." << endl;
				_vMonster->hp = _vMonster->hp - 30;
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
	tagMONSTERSTATS monster1;
	monster1.dl = TEMP1;
	monster1.callNum = 1;
	strncpy_s(monster1.name, "����1", 32);
	monster1.hp = 50;
	monster1.pwr = 1;
	monster1.dex = 1;
	monster1.exp = 1;
	monster1.money = 100;
	_monster.push_back(monster1);

	tagMONSTERSTATS monster2;
	monster2.dl = TEMP1;
	monster2.callNum = 2;
	strncpy_s(monster2.name, "����2", 32);
	monster2.hp = 60;
	monster2.pwr = 2;
	monster2.dex = 2;
	monster2.exp = 2;
	monster2.money = 200;
	_monster.push_back(monster2);

	tagMONSTERSTATS monster3;
	monster3.dl = TEMP1;
	monster3.callNum = 3;
	strncpy_s(monster3.name, "����3", 32);
	monster3.hp = 70;
	monster3.pwr = 3;
	monster3.dex = 3;
	monster3.exp = 3;
	monster3.money = 300;
	_monster.push_back(monster3);

	tagMONSTERSTATS monster4;
	monster4.dl = TEMP2;
	monster4.callNum = 1;
	strncpy_s(monster4.name, "����4", 32);
	monster4.hp = 70;
	monster4.pwr = 3;
	monster4.dex = 3;
	monster4.exp = 3;
	monster4.money = 300;
	_monster.push_back(monster4);
}