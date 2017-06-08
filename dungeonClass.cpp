#include "dungeonClass.h"

dungeonClass::dungeonClass()
{
	srand(time(NULL));
	setMonster();
	while (true)
	{
		int dungeonSelect;
		cout << "어느 던전을 탐험하시겠습니까?" << endl;
		cout << "1.야남 거리 \t 2.버려진 구공방 \t 3.구 시가지 \t 4.금단의 숲" << endl;
		cin >> dungeonSelect;

		
		switch (dungeonSelect)
		{
			case 1:
				strncpy_s(_dungeonName, "야남 거리", 32);
				enterDungeon(TEMP1, _dungeonName);
			break;
			case 2:
				strncpy_s(_dungeonName, "버려진 구공방", 32);
				enterDungeon(TEMP2, _dungeonName);
			break;
			case 3:
				strncpy_s(_dungeonName, "구 시가지", 32);
				enterDungeon(TEMP3, _dungeonName);
			break;
			case 4:
				strncpy_s(_dungeonName, "금단의 숲", 32);
				enterDungeon(TEMP4, _dungeonName);
			break;
			default:
				cout << "잘못된 번호를 입력하셨습니다. 다시 입력해주세요." << endl;
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
	cout << dungeonName << " 던전에 입장하셨습니다." << endl;
	int callMonsterNum = rand() % 3 + 1;
	for (_vMonster = _monster.begin(); _vMonster != _monster.end(); ++_vMonster)
	{
		if (dungeonNum != _vMonster->dl) continue;
		if (callMonsterNum != _vMonster->callNum) continue;

		// 인터페이스 작용
		while (_vMonster->hp > 0)
		{
			system("cls");
			cout << "몬스터가 등장하였습니다." << endl;
			cout << "몬스터이름 : " << _vMonster->name << endl;
			cout << "HP : " << _vMonster->hp << endl;

			int interfaceSelect;
			cout << "1.공격하기 \t 2.가방 \t 3.도망치기" << endl;
			cin >> interfaceSelect;

			switch (interfaceSelect)
			{
			case 1:
				cout << "플레이어가 공격하여 " << _vMonster->name << "의 HP가 30 감소하였습니다." << endl;
				_vMonster->hp = _vMonster->hp - 30;
				break;
			case 2:
				break;
			case 3:
				break;
			default:
				cout << "잘못된 번호를 입력하셨습니다. 다시 입력해주세요." << endl;
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
	strncpy_s(monster1.name, "몬스터1", 32);
	monster1.hp = 50;
	monster1.pwr = 1;
	monster1.dex = 1;
	monster1.exp = 1;
	monster1.money = 100;
	_monster.push_back(monster1);

	tagMONSTERSTATS monster2;
	monster2.dl = TEMP1;
	monster2.callNum = 2;
	strncpy_s(monster2.name, "몬스터2", 32);
	monster2.hp = 60;
	monster2.pwr = 2;
	monster2.dex = 2;
	monster2.exp = 2;
	monster2.money = 200;
	_monster.push_back(monster2);

	tagMONSTERSTATS monster3;
	monster3.dl = TEMP1;
	monster3.callNum = 3;
	strncpy_s(monster3.name, "몬스터3", 32);
	monster3.hp = 70;
	monster3.pwr = 3;
	monster3.dex = 3;
	monster3.exp = 3;
	monster3.money = 300;
	_monster.push_back(monster3);

	tagMONSTERSTATS monster4;
	monster4.dl = TEMP2;
	monster4.callNum = 1;
	strncpy_s(monster4.name, "몬스터4", 32);
	monster4.hp = 70;
	monster4.pwr = 3;
	monster4.dex = 3;
	monster4.exp = 3;
	monster4.money = 300;
	_monster.push_back(monster4);
}