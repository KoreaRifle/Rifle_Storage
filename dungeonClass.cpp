#include "dungeonClass.h"
#include "MainMenu.h"

dungeonClass::dungeonClass()
{
	srand(time(NULL));
	dropItemSetting();
}


dungeonClass::~dungeonClass()
{
}

int dungeonClass::dungeonMain(int inventorySize, int maxInventorySize)
{
	exit = 0;
	system("cls");
	setMonster();
	_inventorySize = inventorySize;
	_maxInventorySize = maxInventorySize;
	// 진입 시 _ITEM 값이 들어있을 경우 모든 값 삭제
	if (_ITEM.size() > 0) _ITEM.erase(_ITEM.begin(), _ITEM.end());

	while (exit != 1)
	{
		if (_inventorySize == _maxInventorySize) cout << "※ 인벤토리가 가득 차 있는 상태입니다." << endl;
		userInterface();
		cout << endl;
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
				exit = 1;
			break;
			default:
				cout << "잘못된 번호를 입력하셨습니다. 다시 입력해주세요." << endl;
			continue;
		}
		Sleep(500);
		system("cls");
	}
	return _money;
}

void dungeonClass::enterDungeon(int dungeonNum, char dungeonName[32])
{
	bool exit = 0;
	_userAttackPoint = 0;
	system("cls");
	cout << dungeonName << " 던전에 입장하셨습니다." << endl;
	int callMonsterNum = rand() % 3 + 1; // 1 ~ 3
	int callBossMonsterNum = rand() % 10 + 1; // 1 ~ 30

	if (callMonsterNum == callBossMonsterNum) callMonsterNum = 99;

	// 문제 발생
	for (_vMonster = _monster.begin(); _vMonster != _monster.end(); ++_vMonster)
	{
		if (dungeonNum != _vMonster->dl) continue;
		if (callMonsterNum != _vMonster->callNum) continue;

		if (callMonsterNum != 99) cout << "몬스터가 등장하였습니다." << endl;
		else cout << "☆★☆★☆★☆★☆★ 보스 몬스터가 출현하였습니다!!!! ☆★☆★☆★☆★☆★" << endl;
		cout << endl;
		Sleep(100);

		// 인터페이스 작용
		while (_vMonster->hp > 0 && _hp > 0) // 몬스터의 피가 0이상이거나 플레이어의 캐릭터의 피가 0 이상일때 반복
		{
			if (_inventorySize == _maxInventorySize) cout << "※ 인벤토리가 가득 차 있는 상태입니다." << endl;
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
			userInterface();
			cout << "========== MONSTER INFO ==========" << endl;
			cout << "몬스터이름 : " << _vMonster->name << endl;
			cout << "HP : " << _vMonster->hp << endl;

			_vMonster->monsterAttackPoint = rand() % 20 + _vMonster->pwr; // 몬스터 공격력 난수 발생

			int interfaceSelect;
			cout << "플레이어의 턴입니다." << endl;
			cout << "1.공격하기 \t 2.가방 \t 3.도망치기\t 4.(비전투상태)되돌아가기" << endl;
			cin >> interfaceSelect;

			switch (interfaceSelect)
			{
				case 1:
					attackPoint(_mindmg); // 유저 턴의 공격 데미지 확인
					monsterAttack(_vMonster->monsterAttackPoint); // 몬스터 턴의 공격 데미지 확인
				break;
				case 2:
				break;
				case 3:
					if (runNum != randomNum)
					{
						cout << "도망가지 못했습니다." << endl;
						monsterAttack(_vMonster->monsterAttackPoint);
					}
					else
					{
						cout << "무사히 도망쳤습니다." << endl;
						_vMonster->hp = _vMonster->max_hp;
						exit = 1;
					}
				break;
				case 4:
					if (_vMonster->hp == _vMonster->max_hp)
					{
						exit = 1;
						break;
					}
					else
					{
						cout << "현재 전투상태입니다. 되돌아갈 수 없습니다." << endl;
						Sleep(300);
						continue;
					}
				break;
				default:
					cout << "잘못된 번호를 입력하셨습니다. 다시 입력해주세요." << endl;
					system("cls");
				continue;
			}
			// 유저 공격력이 1이상일때
			if (_userAttackPoint != 0)
			{
				_vMonster->hp = _vMonster->hp - _userAttackPoint;
				cout << "플레이어가 " << _userAttackPoint << "만큼 데미지를 주었습니다." << endl;
			}

			Sleep(300);
			system("cls");
			// 3번 혹은 4번을 입력했을 때 루프 탈출구
			if (interfaceSelect == 3 || interfaceSelect == 4)
			{
				// 3번 혹은 4번에서 exit의 값이 1일때 루프 탈출
				if (exit == 1) break;
			}
		}
		if (_vMonster->hp <= 0)
		{
			if (_hp > 0)
			{
				int bootySelect = rand() % 4; // 전리품 획득 분기
				int moneyTemp;
				cout << "몬스터가 죽었습니다." << endl;
				cout << "[SYSTEM] 경험치 " << _vMonster->exp << " 획득!" << endl;
				_exp = _exp + _vMonster->exp;

				if (bootySelect == 0) cout << "몬스터에게서 아무 전리품도 획득하지 못했습니다." << endl;
				else if (bootySelect == 1) // 돈만 먹었을 때
				{
					int randomMoneyNum = rand() % _vMonster->money;
					moneyTemp = _vMonster->money - randomMoneyNum;
					_money = _money + moneyTemp;
					cout << "골드 " << moneyTemp << "G 획득!" << endl;
				}
				else if (bootySelect == 2) // 아이템만 먹었을 때
				{
					cout << "[SYSTEM] 아이템 획득!" << endl;
					//dungeon_il.dropItemList(_vMonster->dl, _vMonster->callNum);
					dropItemList(_vMonster->dl, _vMonster->callNum);
				}
				else // 돈, 아이템 모두 먹었을 때
				{
					cout << "[SYSTEM] 골드/아이템 획득" << endl;
					int randomMoneyNum = rand() % _vMonster->money;
					moneyTemp = _vMonster->money - randomMoneyNum;
					_money = _money + moneyTemp;
					cout << "골드 " << moneyTemp << "G 획득!" << endl;
					//dungeon_il.dropItemList(_vMonster->dl, _vMonster->callNum);
					dropItemList(_vMonster->dl, _vMonster->callNum);
				}

				_vMonster->hp = _vMonster->max_hp; // 몬스터 피 이전 상태로 롤백
				Sleep(300);
				levelUp();
			}
			else if (_hp <= 0)
			{
				playerDead();
			}
		}
		if (_hp <= 0)
		{
			playerDead();
		}
		break;
	}
}

void dungeonClass::charactorStatus(int roleNum, char name[32], int level, int max_hp, int add_max_hp, int hp, int max_mp, int add_max_mp, int mp, int pwr, int add_pwr, int mindmg, int dex, int add_dex, int intel, int add_intel, int exp, int totalExp, int money)
{
	_roleNum = roleNum;
	if (_roleNum == 1) strncpy_s(_roleName, "전사", 32);
	else if (_roleNum == 2) strncpy_s(_roleName, "마법사", 32);
	else if (_roleNum == 3) strncpy_s(_roleName, "엘프", 32);
	strncpy_s(_name, name, 32);
	_level = level;
	_max_hp = max_hp;
	_add_max_hp = add_max_hp;
	_hp = hp;
	_max_mp = max_mp;
	_add_max_mp = add_max_mp;
	_mp = mp;
	_pwr = pwr;
	_add_pwr = add_pwr;
	_mindmg = mindmg;
	_dex = dex;
	_add_dex = add_dex;
	_intel = intel;
	_add_intel = add_intel;
	_exp = exp;
	_totalExp = totalExp;
	_money = money;
}

void dungeonClass::itemInfoSave(ITEMDIVISION div, ITEMKIND kind, ITEMROLE role, char itemName[32], int point, int req_level, int req_pwr, int req_dex, int req_intel, int hpOption, int mpOption, int pwrOption, int dexOption, int intelOption, int price)
{
	if (_ITEM.size() < (_maxInventorySize -_inventorySize))
	{
		_tagITEM dungeonItem;
		dungeonItem.ti_division = (int)div;
		dungeonItem.ti_kind = (int)kind;
		dungeonItem.ti_itemRole = (int)role;
		strncpy_s(dungeonItem.ti_itemName, itemName, 32);
		dungeonItem.ti_point = point;
		dungeonItem.ti_req_level = req_level;
		dungeonItem.ti_req_pwr = req_pwr;
		dungeonItem.ti_req_dex = req_dex;
		dungeonItem.ti_req_intel = req_intel;
		dungeonItem.ti_hpOption = hpOption;
		dungeonItem.ti_mpOption = mpOption;
		dungeonItem.ti_pwrOption = pwrOption;
		dungeonItem.ti_dexOption = dexOption;
		dungeonItem.ti_intelOption = intelOption;
		dungeonItem.ti_price = price;
		_ITEM.push_back(dungeonItem);
	}
	else cout << "인벤토리가 가득 찼습니다." << endl;
}

vector<_tagITEM> dungeonClass::itemInfoReturn(void)
{
	return _ITEM;
}

void dungeonClass::levelUp(void)
{
	if (_exp >= _totalExp)
	{
		Sleep(300);
		system("cls");
		cout << "LEVEL UP!" << endl;
		_exp = _exp - _totalExp;
		if (_level <= 10) _totalExp = _totalExp + 50;
		else if (_level > 10) _totalExp = _totalExp * 2;
		
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
		// 마법사일 경우
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
		// 엘프일 경우
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
		Sleep(1000);
	}
	else _exp = _exp;
}

void dungeonClass::attackPoint(int mindmg)
{
	_userAttackPoint = rand() % _pwr + mindmg + 1; // 공격력 변수 생성(최소 공격력 1이상) --> 캐릭터 힘(난수) + 최소데미지
	int dodgeCheck;

	// 회피는 모든 몬스터들에 대한 공격 확률이 조정되어야 함
	// 회피확률 변수 생성
	_playerDodgePoint = ((rand() % _dex + 1) % 10) + ((rand() % _dex + 1) / 10);

	// 플레이어 회피 확률 계산
	if (_playerDodgePoint >= _monsterDodgePoint)
	{
		dodgeCheck = rand() % 2;
		if (dodgeCheck == 1)
		{
			_vMonster->monsterAttackPoint = 0;
			cout << "몬스터의 공격을 회피하였습니다." << endl;
		}
	}
	else
	{
		dodgeCheck = rand() % _vMonster->dex - _playerDodgePoint + 1;
		if (dodgeCheck == 1)
		{
			_vMonster->monsterAttackPoint = 0;
			cout << "몬스터의 공격을 회피하였습니다." << endl;
		}
	}
	Sleep(300);
}

void dungeonClass::monsterAttack(int monsterAttackPoint)
{
	_monsterDodgePoint = ((rand() % _vMonster->dex + 1) % 10) + ((rand() % _vMonster->dex + 1) / 10);
	int dodgeCheck;

	if (_vMonster->monsterAttackPoint != 0)
	{
		cout << "몬스터 턴입니다." << endl;
		_hp = _hp - _vMonster->monsterAttackPoint;
		cout << "몬스터가 " << _vMonster->monsterAttackPoint << "만큼 데미지를 주었습니다." << endl;
	}

	// 몬스터의 회피 확률 계산
	if (_monsterDodgePoint >= _playerDodgePoint)
	{
		dodgeCheck = rand() % 2;
		if (dodgeCheck == 1)
		{
			_userAttackPoint = 0;
			cout << "플레이어의 공격을 회피하였습니다." << endl;
		}
	}
	else
	{
		dodgeCheck = rand() % _playerDodgePoint - _vMonster->dex + 1;
		if (dodgeCheck == 1)
		{
			_userAttackPoint = 0;
			cout << "플레이어의 공격을 회피하였습니다." << endl;
		}
	}
	Sleep(300);
}

void dungeonClass::userInterface(void)
{
	cout << "========== " << _name << " ==========" << endl;
	cout << "레벨 : " << _level << endl;
	cout << "경험치 : " << _exp << " / " << _totalExp << endl;
	cout << "========== HP / MP / GOLD / INVEN ==========" << endl;
	cout << "생명력 : " << _hp << " / " << _max_hp << endl;
	cout << "마나 : " << _mp << " / " << _max_mp << endl;
	cout << "보유금액 : " << _money << " G" << endl;
	cout << "인벤토리 : " << _inventorySize + _ITEM.size() << " / " << _maxInventorySize << endl;
	cout << endl;
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
	_mp = _max_mp;
	_vMonster->hp = _vMonster->max_hp;
	cout << "죽기 전 경험치 : " << tempExp << " / 현재 경험치 : " << _exp << endl;
}

void dungeonClass::setMonster(void)
{
	tagMONSTERSTATS d1_monster1;
	d1_monster1.dl = DUNGEON1;
	d1_monster1.callNum = 1;
	strncpy_s(d1_monster1.name, "몬스터1", 32);
	d1_monster1.max_hp = 30;
	d1_monster1.hp = 30;
	d1_monster1.pwr = 1;
	d1_monster1.dex = 1;
	d1_monster1.exp = 2;
	d1_monster1.money = 100;
	d1_monster1.monsterPwr = 1;
	_monster.push_back(d1_monster1);

	tagMONSTERSTATS d1_monster2;
	d1_monster2.dl = DUNGEON1;
	d1_monster2.callNum = 2;
	strncpy_s(d1_monster2.name, "몬스터2", 32);
	d1_monster2.max_hp = 40;
	d1_monster2.hp = 40;
	d1_monster2.pwr = 2;
	d1_monster2.dex = 2;
	d1_monster2.exp = 3;
	d1_monster2.money = 200;
	d1_monster2.monsterPwr = 3;
	_monster.push_back(d1_monster2);

	tagMONSTERSTATS d1_monster3;
	d1_monster3.dl = DUNGEON1;
	d1_monster3.callNum = 3;
	strncpy_s(d1_monster3.name, "몬스터3", 32);
	d1_monster3.max_hp = 50;
	d1_monster3.hp = 50;
	d1_monster3.pwr = 3;
	d1_monster3.dex = 3;
	d1_monster3.exp = 4;
	d1_monster3.money = 300;
	d1_monster3.monsterPwr = 5;
	_monster.push_back(d1_monster3);

	tagMONSTERSTATS d1_monster4_special;
	d1_monster4_special.dl = DUNGEON1;
	d1_monster4_special.callNum = 99;
	strncpy_s(d1_monster4_special.name, "보스몬스터1", 32);
	d1_monster4_special.max_hp = 200;
	d1_monster4_special.hp = 200;
	d1_monster4_special.pwr = 15;
	d1_monster4_special.dex = 10;
	d1_monster4_special.exp = 25;
	d1_monster4_special.money = 800;
	d1_monster4_special.monsterPwr = 15;
	_monster.push_back(d1_monster4_special);

	tagMONSTERSTATS d2_monster1;
	d2_monster1.dl = DUNGEON2;
	d2_monster1.callNum = 1;
	strncpy_s(d2_monster1.name, "몬스터4", 32);
	d2_monster1.max_hp = 100;
	d2_monster1.hp = 100;
	d2_monster1.pwr = 4;
	d2_monster1.dex = 4;
	d2_monster1.exp = 10;
	d2_monster1.money = 300;
	d2_monster1.monsterPwr = 10;
	_monster.push_back(d2_monster1);

	tagMONSTERSTATS d2_monster2;
	d2_monster2.dl = DUNGEON2;
	d2_monster2.callNum = 2;
	strncpy_s(d2_monster2.name, "몬스터5", 32);
	d2_monster2.max_hp = 130;
	d2_monster2.hp = 130;
	d2_monster2.pwr = 7;
	d2_monster2.dex = 5;
	d2_monster2.exp = 15;
	d2_monster2.money = 400;
	d2_monster2.monsterPwr = 13;
	_monster.push_back(d2_monster2);

	tagMONSTERSTATS d2_monster3;
	d2_monster3.dl = DUNGEON2;
	d2_monster3.callNum = 3;
	strncpy_s(d2_monster3.name, "몬스터6", 32);
	d2_monster3.max_hp = 150;
	d2_monster3.hp = 150;
	d2_monster3.pwr = 10;
	d2_monster3.dex = 7;
	d2_monster3.exp = 20;
	d2_monster3.money = 450;
	d2_monster3.monsterPwr = 15;
	_monster.push_back(d2_monster3);

	tagMONSTERSTATS d2_monster4_special;
	d2_monster4_special.dl = DUNGEON2;
	d2_monster4_special.callNum = 99;
	strncpy_s(d2_monster4_special.name, "보스몬스터2", 32);
	d2_monster4_special.max_hp = 400;
	d2_monster4_special.hp = 400;
	d2_monster4_special.pwr = 30;
	d2_monster4_special.dex = 20;
	d2_monster4_special.exp = 50;
	d2_monster4_special.money = 900;
	d2_monster4_special.monsterPwr = 30;
	_monster.push_back(d2_monster4_special);
}

void dungeonClass::dropItemSetting(void)
{
	ITEM dropItem1_dungeon1;
	dropItem1_dungeon1.division = ITEMDIVISION::DROPITEM;
	dropItem1_dungeon1.kind = ITEMKIND::WEAPON;
	dropItem1_dungeon1.role = ITEMROLE::WARRIOR;
	dropItem1_dungeon1.dropDungeon = DROPDUNGEON::DUNGEON1;
	strncpy_s(dropItem1_dungeon1.itemName, "날카로운 직검", 32);
	dropItem1_dungeon1.req_level = 1;
	dropItem1_dungeon1.req_pwr = 5;
	dropItem1_dungeon1.req_dex = 4;
	dropItem1_dungeon1.req_intel = 1;
	dropItem1_dungeon1.point = 10;
	dropItem1_dungeon1.pwrOption = 5;
	dropItem1_dungeon1.dexOption = 2;
	dropItem1_dungeon1.price = 800;
	dropItem1_dungeon1.monsterNum = MONSTERNUM::MONSTER;
	dropItem1_dungeon1.itemNum = 1;
	_dropItem.push_back(dropItem1_dungeon1);
	_d1DropItem.push_back(dropItem1_dungeon1);

	ITEM dropItem2_dungeon1;
	dropItem2_dungeon1.division = ITEMDIVISION::DROPITEM;
	dropItem2_dungeon1.kind = ITEMKIND::WEAPON;
	dropItem2_dungeon1.role = ITEMROLE::WARRIOR;
	dropItem2_dungeon1.dropDungeon = DROPDUNGEON::DUNGEON1;
	strncpy_s(dropItem2_dungeon1.itemName, "거대한 브로드소드", 32);
	dropItem2_dungeon1.req_level = 2;
	dropItem2_dungeon1.req_pwr = 13;
	dropItem2_dungeon1.req_dex = 6;
	dropItem2_dungeon1.req_intel = 0;
	dropItem2_dungeon1.point = 25;
	dropItem2_dungeon1.pwrOption = 15;
	dropItem2_dungeon1.dexOption = 10;
	dropItem2_dungeon1.price = 3200;
	dropItem2_dungeon1.monsterNum = MONSTERNUM::MONSTER;
	dropItem2_dungeon1.itemNum = dropItem1_dungeon1.itemNum + 1;
	_dropItem.push_back(dropItem2_dungeon1);
	_d1DropItem.push_back(dropItem2_dungeon1);

	ITEM dropItem3_dungeon1;
	dropItem3_dungeon1.division = ITEMDIVISION::DROPITEM;
	dropItem3_dungeon1.kind = ITEMKIND::WEAPON;
	dropItem3_dungeon1.role = ITEMROLE::WARRIOR;
	dropItem3_dungeon1.dropDungeon = DROPDUNGEON::DUNGEON1;
	strncpy_s(dropItem3_dungeon1.itemName, "[RARE]모략가", 32);
	dropItem3_dungeon1.req_level = 2;
	dropItem3_dungeon1.req_pwr = 13;
	dropItem3_dungeon1.req_dex = 6;
	dropItem3_dungeon1.req_intel = 0;
	dropItem3_dungeon1.point = 25;
	dropItem3_dungeon1.pwrOption = 15;
	dropItem3_dungeon1.dexOption = 10;
	dropItem3_dungeon1.price = 3200;
	dropItem3_dungeon1.monsterNum = MONSTERNUM::BOSS;
	dropItem3_dungeon1.itemNum = dropItem2_dungeon1.itemNum + 1;
	_d1BossDropItem.push_back(dropItem3_dungeon1);
	_dropItem.push_back(dropItem3_dungeon1);
	_d1DropItem.push_back(dropItem3_dungeon1);

	ITEM dropItem4_dungeon1;
	dropItem4_dungeon1.division = ITEMDIVISION::DROPITEM;
	dropItem4_dungeon1.kind = ITEMKIND::WEAPON;
	dropItem4_dungeon1.role = ITEMROLE::WARRIOR;
	dropItem4_dungeon1.dropDungeon = DROPDUNGEON::DUNGEON1;
	strncpy_s(dropItem4_dungeon1.itemName, "테스트_노말템", 32);
	dropItem4_dungeon1.req_level = 2;
	dropItem4_dungeon1.req_pwr = 13;
	dropItem4_dungeon1.req_dex = 6;
	dropItem4_dungeon1.req_intel = 0;
	dropItem4_dungeon1.point = 25;
	dropItem4_dungeon1.pwrOption = 15;
	dropItem4_dungeon1.dexOption = 10;
	dropItem4_dungeon1.price = 3200;
	dropItem4_dungeon1.monsterNum = MONSTERNUM::MONSTER;
	dropItem4_dungeon1.itemNum = dropItem3_dungeon1.itemNum + 1;
	_dropItem.push_back(dropItem4_dungeon1);
	_d1DropItem.push_back(dropItem4_dungeon1);

	ITEM dropItem5_dungeon1;
	dropItem5_dungeon1.division = ITEMDIVISION::DROPITEM;
	dropItem5_dungeon1.kind = ITEMKIND::WEAPON;
	dropItem5_dungeon1.role = ITEMROLE::WARRIOR;
	dropItem5_dungeon1.dropDungeon = DROPDUNGEON::DUNGEON1;
	strncpy_s(dropItem5_dungeon1.itemName, "[RARE] 레어템", 32);
	dropItem5_dungeon1.req_level = 2;
	dropItem5_dungeon1.req_pwr = 13;
	dropItem5_dungeon1.req_dex = 6;
	dropItem5_dungeon1.req_intel = 0;
	dropItem5_dungeon1.point = 25;
	dropItem5_dungeon1.pwrOption = 15;
	dropItem5_dungeon1.dexOption = 10;
	dropItem5_dungeon1.price = 3200;
	dropItem5_dungeon1.monsterNum = MONSTERNUM::BOSS;
	dropItem5_dungeon1.itemNum = dropItem4_dungeon1.itemNum + 1;
	_d1BossDropItem.push_back(dropItem5_dungeon1);
	_dropItem.push_back(dropItem5_dungeon1);
	_d1DropItem.push_back(dropItem5_dungeon1);

	ITEM dropItem1_dungeon2;
	dropItem1_dungeon2.division = ITEMDIVISION::DROPITEM;
	dropItem1_dungeon2.kind = ITEMKIND::WEAPON;
	dropItem1_dungeon2.role = ITEMROLE::WARRIOR;
	dropItem1_dungeon2.dropDungeon = DROPDUNGEON::DUNGEON2;
	strncpy_s(dropItem1_dungeon2.itemName, "테스트아이템", 32);
	dropItem1_dungeon2.req_level = 2;
	dropItem1_dungeon2.req_pwr = 13;
	dropItem1_dungeon2.req_dex = 6;
	dropItem1_dungeon2.req_intel = 0;
	dropItem1_dungeon2.point = 25;
	dropItem1_dungeon2.pwrOption = 15;
	dropItem1_dungeon2.dexOption = 10;
	dropItem1_dungeon2.price = 3200;
	dropItem1_dungeon2.monsterNum = MONSTERNUM::MONSTER;
	dropItem1_dungeon2.itemNum = 1;
	_dropItem.push_back(dropItem1_dungeon2);
	_d2DropItem.push_back(dropItem1_dungeon2);

	// 보스 드랍 아이템 번호 배열에 저장
	int num = 0;
	for (_vdropItem = _d1BossDropItem.begin(); _vdropItem != _d1BossDropItem.end(); ++_vdropItem)
	{
		_d1BossItemArray[num] = _vdropItem->itemNum;
		num++;
	}

	num = 0;
	for (_vdropItem = _d2BossDropItem.begin(); _vdropItem != _d2BossDropItem.end(); ++_vdropItem)
	{
		_d2BossItemArray[num] = _vdropItem->itemNum;
		num++;
	}
}

void dungeonClass::dropItemList(int dungeonNum, int callNum)
{
	if (dungeonNum == 1)
	{
		int _d1DropItemChoice = rand() % (_d1DropItem.size() - _d1BossDropItem.size()) + 1;
		int _d1BossDropItemChoice = _d1BossItemArray[rand() % _d1BossDropItem.size()];
		for (_vdropItem = _d1DropItem.begin(); _vdropItem != _d1DropItem.end(); ++_vdropItem)
		{
			if (_vdropItem->dropDungeon != DROPDUNGEON(dungeonNum)) continue;
			if (MONSTERNUM(callNum) != MONSTERNUM::BOSS) // 획득범위가 보스 제외 모든 몬스터일때
			{
				// 드랍템 저장수만큼 난수 생성
				if (_vdropItem->itemNum == _d1DropItemChoice)
				{
					//cout << "[TEST] 드랍 아이템 INVENTORY로 저장 중..." << endl;
					itemInfoSave(_vdropItem->division, _vdropItem->kind, _vdropItem->role, _vdropItem->itemName, _vdropItem->req_level, _vdropItem->req_pwr, _vdropItem->req_dex, _vdropItem->req_intel, _vdropItem->hpOption, _vdropItem->mpOption, _vdropItem->point, _vdropItem->pwrOption, _vdropItem->dexOption, _vdropItem->intelOption, _vdropItem->price);
					break;
				}
			}
			else if (MONSTERNUM(callNum) == MONSTERNUM::BOSS)
			{
				if (_vdropItem->itemNum == _d1BossDropItemChoice)
				{
					//cout << "[TEST] BOSS 드랍 아이템 INVENTORY로 저장 중..." << endl;
					itemInfoSave(_vdropItem->division, _vdropItem->kind, _vdropItem->role, _vdropItem->itemName, _vdropItem->req_level, _vdropItem->req_pwr, _vdropItem->req_dex, _vdropItem->req_intel, _vdropItem->hpOption, _vdropItem->mpOption, _vdropItem->point, _vdropItem->pwrOption, _vdropItem->dexOption, _vdropItem->intelOption, _vdropItem->price);
					break;
				}
			}
		}
	}
	else if (dungeonNum == 2)
	{
		int _d2DropItemChoice = rand() % (_d2DropItem.size() - _d2BossDropItem.size()) + 1;
		int _d2BossDropItemChoice = _d2BossItemArray[rand() % _d2BossDropItem.size()];
		for (_vdropItem = _d2DropItem.begin(); _vdropItem != _d2DropItem.end(); ++_vdropItem)
		{
			if (_vdropItem->dropDungeon != DROPDUNGEON(dungeonNum)) continue;
			if (_vdropItem->monsterNum != MONSTERNUM::BOSS) // 획득범위가 보스 제외 모든 몬스터일때
			{
				// 드랍템 저장수만큼 난수 생성
				if (_vdropItem->itemNum == _d2DropItemChoice)
				{
					//cout << "[TEST] 드랍 아이템 INVENTORY로 저장 중..." << endl;
					itemInfoSave(_vdropItem->division, _vdropItem->kind, _vdropItem->role, _vdropItem->itemName, _vdropItem->req_level, _vdropItem->req_pwr, _vdropItem->req_dex, _vdropItem->req_intel, _vdropItem->hpOption, _vdropItem->mpOption, _vdropItem->point, _vdropItem->pwrOption, _vdropItem->dexOption, _vdropItem->intelOption, _vdropItem->price);
					break;
				}
			}
			else
			{
				if (_vdropItem->itemNum == _d2BossDropItemChoice)
				{
					//cout << "[TEST] BOSS 드랍 아이템 INVENTORY로 저장 중..." << endl;
					itemInfoSave(_vdropItem->division, _vdropItem->kind, _vdropItem->role, _vdropItem->itemName, _vdropItem->req_level, _vdropItem->req_pwr, _vdropItem->req_dex, _vdropItem->req_intel, _vdropItem->hpOption, _vdropItem->mpOption, _vdropItem->point, _vdropItem->pwrOption, _vdropItem->dexOption, _vdropItem->intelOption, _vdropItem->price);
					break;
				}
			}
		}
	}
}
