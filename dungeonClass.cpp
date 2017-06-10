#include "dungeonClass.h"

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
		cout << "어느 던전을 탐험하시겠습니까?" << endl;
		cout << "1.야남 거리 \t 2.버려진 구공방 \t 3.구 시가지 \t 4.금단의 숲 \t 5.되돌아가기" << endl;
		cin >> dungeonSelect;


		switch (dungeonSelect)
		{
		case 1:
			strncpy_s(_dungeonName, "야남 거리", 32);
			enterDungeon(DUNGEON1, _dungeonName);
		break;
		case 2:
			strncpy_s(_dungeonName, "버려진 구공방", 32);
			enterDungeon(DUNGEON2, _dungeonName);
		break;
		case 3:
			strncpy_s(_dungeonName, "구 시가지", 32);
			enterDungeon(DUNGEON3, _dungeonName);
		break;
		case 4:
			strncpy_s(_dungeonName, "금단의 숲", 32);
			enterDungeon(DUNGEON4, _dungeonName);
		break;
		case 5:
			mm.startMenu();
		break;
		default:
			cout << "잘못된 번호를 입력하셨습니다. 다시 입력해주세요." << endl;
			continue;
		}
	}
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
		while (_vMonster->hp > 0 && _hp > 0) // 몬스터의 피가 0이상이거나 플레이어의 캐릭터의 피가 0 이상일때 반복
		{
			system("cls");
			userInterface();
			cout << endl;
			cout << "몬스터가 등장하였습니다." << endl;
			cout << "몬스터이름 : " << _vMonster->name << endl;
			cout << "HP : " << _vMonster->hp << endl;

			int interfaceSelect;
			cout << "플레이어의 턴입니다." << endl;
			cout << "1.공격하기 \t 2.가방 \t 3.도망치기" << endl;
			cin >> interfaceSelect;

			switch (interfaceSelect)
			{
				case 1:
					attackPoint(); // 유저 턴의 공격 데미지 확인
				break;
				case 2:
				break;
				case 3:
				break;
				default:
					cout << "잘못된 번호를 입력하셨습니다. 다시 입력해주세요." << endl;
					system("cls");
				continue;
			}
			monsterAttack(); // 몬스터 턴의 공격 데미지 확인
			Sleep(500);
			system("cls");
			continue;
		}
	}
}

void dungeonClass::setMonster(void)
{
	tagMONSTERSTATS d1_monster1;
	d1_monster1.dl = DUNGEON1;
	d1_monster1.callNum = 1;
	strncpy_s(d1_monster1.name, "몬스터1", 32);
	d1_monster1.hp = 50;
	d1_monster1.pwr = 1;
	d1_monster1.dex = 1;
	d1_monster1.exp = 1;
	d1_monster1.money = 100;
	_monster.push_back(d1_monster1);

	tagMONSTERSTATS d1_monster2;
	d1_monster2.dl = DUNGEON1;
	d1_monster2.callNum = 2;
	strncpy_s(d1_monster2.name, "몬스터2", 32);
	d1_monster2.hp = 60;
	d1_monster2.pwr = 2;
	d1_monster2.dex = 2;
	d1_monster2.exp = 2;
	d1_monster2.money = 200;
	_monster.push_back(d1_monster2);

	tagMONSTERSTATS d1_monster3;
	d1_monster3.dl = DUNGEON1;
	d1_monster3.callNum = 3;
	strncpy_s(d1_monster3.name, "몬스터3", 32);
	d1_monster3.hp = 70;
	d1_monster3.pwr = 3;
	d1_monster3.dex = 3;
	d1_monster3.exp = 3;
	d1_monster3.money = 300;
	_monster.push_back(d1_monster3);

	tagMONSTERSTATS d2_monster4;
	d2_monster4.dl = DUNGEON2;
	d2_monster4.callNum = 1;
	strncpy_s(d2_monster4.name, "몬스터4", 32);
	d2_monster4.hp = 70;
	d2_monster4.pwr = 3;
	d2_monster4.dex = 3;
	d2_monster4.exp = 3;
	d2_monster4.money = 300;
	_monster.push_back(d2_monster4);
}

void dungeonClass::charactorStatus(int roleNum, char name[32], int max_hp, int hp, int max_mp, int mp, int pwr, int dex, int intel, int totalExp)
{
	_roleNum = roleNum;
	if (_roleNum == 1) strncpy_s(_roleName, "전사", 32);
	else if (_roleNum == 2) strncpy_s(_roleName, "마법사", 32);
	else if (_roleNum == 3) strncpy_s(_roleName, "엘프", 32);
	strncpy_s(_name, name, 32);
	_max_hp = max_hp;
	_hp = hp;
	_max_mp = max_mp;
	_mp = mp;
	_pwr = pwr;
	_dex = dex;
	_intel = intel;
	_totalExp = totalExp;
}

void dungeonClass::attackPoint(void)
{
	int userAttackPoint = rand() % 20 + _pwr;
	_vMonster->hp = _vMonster->hp - userAttackPoint;
}

void dungeonClass::monsterAttack(void)
{
	int monsterAttackPoint = rand() % 20 + _pwr;
	cout << "몬스터 턴입니다." << endl;
	_hp = _hp - monsterAttackPoint;
	cout << "몬스터가 " << monsterAttackPoint << "만큼 데미지를 입혔습니다." << endl;
}

void dungeonClass::userInterface(void)
{
	cout << "========== " << _name << " ==========" << endl;
	cout << "생명력 : " << _hp << " / " << _max_hp << endl;
	cout << "마나 : " << _mp << " / " << _max_mp << endl;
}

