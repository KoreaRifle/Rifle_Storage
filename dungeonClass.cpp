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
				if (_level >= 2)
				{
					strncpy_s(_dungeonName, "버려진 구공방", 32);
					enterDungeon(DUNGEON2, _dungeonName);
				}
				else cout << "입장 레벨 제한 : 최소 레벨 2 이상" << endl;
			break;
			case 3:
				if (_level >= 3)
				{
					strncpy_s(_dungeonName, "구 시가지", 32);
					enterDungeon(DUNGEON3, _dungeonName);
				}
				else cout << "입장 레벨 제한 : 최소 레벨 3 이상" << endl;
			break;
			case 4:
				if (_level >= 4)
				{
					strncpy_s(_dungeonName, "금단의 숲", 32);
					enterDungeon(DUNGEON4, _dungeonName);
				}
				else cout << "입장 레벨 제한 : 최소 레벨 4 이상" << endl;
			break;
			case 5:
				mm.charactorStatus(1, _roleNum, _name, _level, _max_hp, _hp, _max_mp, _mp, _pwr, _dex, _intel, _exp, _totalExp);
				mm.startMenu();
			break;
			default:
			cout << "잘못된 번호를 입력하셨습니다. 다시 입력해주세요." << endl;
			continue;
		}
		Sleep(500);
		system("cls");
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

		cout << "몬스터가 등장하였습니다." << endl;

		// 인터페이스 작용
		while (_vMonster->hp > 0 && _hp > 0) // 몬스터의 피가 0이상이거나 플레이어의 캐릭터의 피가 0 이상일때 반복
		{
			// 도망치는 확률 변수 계산
			int runNum; // 도망칠 수 있는 확률 범위 변수
			int randomNum; // 도망칠 수 있는 확률 비교 변수
			// monsterPwr 가 플레이어의 level보다 클 때
			if (_vMonster->monsterPwr > _level)
			{
				runNum = rand() % (_vMonster->monsterPwr - _level);
				randomNum = rand() % (_vMonster->monsterPwr - _level);
			}
			// monsterPwr 가 플레이어의 level보다 작거나 같을 때
			else if (_vMonster->monsterPwr <= _level)
			{
				runNum = rand() % 2;
				randomNum = rand() % 2;
			}
			system("cls");
			userInterface();
			cout << endl;
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
					if (runNum != randomNum)
					{
						cout << "도망가지 못했습니다." << endl;
						// cout << "runNum / randomNum : " << runNum << " / " << randomNum << endl;
						Sleep(1000);
						break;
					}
					else
					{
						cout << "무사히 도망쳤습니다." << endl;
						// cout << "runNum / randomNum : " << runNum << " / " << randomNum << endl;
						Sleep(1000);
						_vMonster->hp = _vMonster->max_hp;
						dungeonMain();
					}
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
		if (_vMonster->hp <= 0)
		{
			if (_hp > 0)
			{
				cout << "몬스터가 죽었습니다." << endl;
				cout << "경험치 " << _vMonster->exp << " 획득!" << endl;
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
	if (_roleNum == 1) strncpy_s(_roleName, "전사", 32);
	else if (_roleNum == 2) strncpy_s(_roleName, "마법사", 32);
	else if (_roleNum == 3) strncpy_s(_roleName, "엘프", 32);
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
		// 전사일 경우
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
		cout << "직업 : " << _roleName << endl;
		cout << "닉네임 : " << _name << endl;
		cout << "레벨 : " << _level << endl;
		cout << "경험치 : " << _exp << " / " << _totalExp << endl;
		cout << "생명력 : " << _hp << " / " << _max_hp << endl;
		cout << "마나 : " << _mp << " / " << _max_mp << endl;
		cout << "힘 : " << _pwr << endl;
		cout << "민첩 : " << _dex << endl;
		cout << "지능 : " << _intel << endl;
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
	cout << "몬스터 턴입니다." << endl;
	_hp = _hp - monsterAttackPoint;
	cout << "몬스터가 " << monsterAttackPoint << "만큼 데미지를 주었습니다." << endl;
}

void dungeonClass::userInterface(void)
{
	cout << "========== " << _name << " ==========" << endl;
	//cout << "레벨 : " <<  << endl;
	cout << "생명력 : " << _hp << " / " << _max_hp << endl;
	cout << "마나 : " << _mp << " / " << _max_mp << endl;
}

// 플레이어가 죽었을 때
void dungeonClass::playerDead(void)
{
	cout << "YOU DIED" << endl;
	cout << "당신은 죽었습니다. 경험치 10%를 잃었습니다." << endl;

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
	cout << "죽기 전 경험치 : " << tempExp << " / 현재 경험치 : " << _exp << endl;
}

void dungeonClass::setMonster(void)
{
	tagMONSTERSTATS d1_monster1;
	d1_monster1.dl = DUNGEON1;
	d1_monster1.callNum = 1;
	strncpy_s(d1_monster1.name, "몬스터1", 32);
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
	strncpy_s(d1_monster2.name, "몬스터2", 32);
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
	strncpy_s(d1_monster3.name, "몬스터3", 32);
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
	strncpy_s(d2_monster1.name, "몬스터4", 32);
	d2_monster1.max_hp = 80;
	d2_monster1.hp = 80;
	d2_monster1.pwr = 4;
	d2_monster1.dex = 4;
	d2_monster1.exp = 4;
	d2_monster1.money = 300;
	d2_monster1.monsterPwr = 10;
	_monster.push_back(d2_monster1);
}