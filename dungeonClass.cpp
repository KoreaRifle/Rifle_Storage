#include "dungeonClass.h"
#include "MainMenu.h"

MainMenu dungeon_mm;
userStats dungeon_us;
itemList dungeon_il;

dungeonClass::dungeonClass()
{
	srand(time(NULL));
}


dungeonClass::~dungeonClass()
{
}

void dungeonClass::dungeonMain(void)
{
	system("cls");
	setMonster();
	while (true)
	{
		userInterface();
		cout << endl;
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
				dungeon_mm.charactorStatus(1, _roleNum, _name, _level, _max_hp, _add_max_hp, _hp, _max_mp, _add_max_mp, _mp, _pwr, _add_pwr, _mindmg, _dex, _add_dex, _intel, _add_intel, _exp, _totalExp, _money);
				/*for (_vinven = _inventory.begin(); _vinven != _inventory.end(); ++_vinven)
				{
					dungeon_mm.itemInfoSave(_vinven->division, _vinven->kind, _vinven->role, _vinven->itemName, _vinven->point, _vinven->req_level, _vinven->req_pwr, _vinven->req_dex, _vinven->req_intel, _vinven->hpOption, _vinven->mpOption, _vinven->pwrOption, _vinven->dexOption, _vinven->intelOption, _vinven->price);
				}*/
				dungeon_mm.startMenu();
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
	int callMonsterNum = rand() % 3 + 1; // 1 ~ 3
	int callBossMonsterNum = rand() % 10 + 1; // 1 ~ 30

	if (callMonsterNum == callBossMonsterNum) callMonsterNum = 99;

	for (_vMonster = _monster.begin(); _vMonster != _monster.end(); ++_vMonster)
	{
		if (dungeonNum != _vMonster->dl) continue;
		if (callMonsterNum != _vMonster->callNum) continue;

		if(callMonsterNum != 99) cout << "���Ͱ� �����Ͽ����ϴ�." << endl;
		else cout << "�١ڡ١ڡ١ڡ١ڡ١� ���� ���Ͱ� �����Ͽ����ϴ�!!!! �١ڡ١ڡ١ڡ١ڡ١�" << endl;
		cout << endl;
		Sleep(100);

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
			// system("cls");
			userInterface();
			cout << "========== MONSTER INFO ==========" << endl;
			cout << "�����̸� : " << _vMonster->name << endl;
			cout << "HP : " << _vMonster->hp << endl;

			_vMonster->monsterAttackPoint = rand() % 20 + _vMonster->pwr; // ���� ���ݷ� ���� �߻�

			int interfaceSelect;
			cout << "�÷��̾��� ���Դϴ�." << endl;
			cout << "1.�����ϱ� \t 2.���� \t 3.����ġ��\t 4.(����������)�ǵ��ư���" << endl;
			cin >> interfaceSelect;

			switch (interfaceSelect)
			{
				case 1:
					attackPoint(_mindmg); // ���� ���� ���� ������ Ȯ��
				break;
				case 2:
				break;
				case 3:
					if (runNum != randomNum)
					{
						cout << "�������� ���߽��ϴ�." << endl;
						break;
					}
					else
					{
						cout << "������ �����ƽ��ϴ�." << endl;
						_vMonster->hp = _vMonster->max_hp;
						dungeonMain();
					}
				case 4:
					if (_vMonster->hp == _vMonster->max_hp) dungeonMain();
					else
					{
						cout << "���� ���������Դϴ�. �ǵ��ư� �� �����ϴ�." << endl;
						Sleep(300);
						continue;
					}
				break;
				default:
					cout << "�߸��� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
					system("cls");
				continue;
			}
			monsterAttack(_vMonster->monsterAttackPoint); // ���� ���� ���� ������ Ȯ��
			if (_userAttackPoint != 0)
			{
				_vMonster->hp = _vMonster->hp - _userAttackPoint;
				cout << "�÷��̾ " << _userAttackPoint << "��ŭ �������� �־����ϴ�." << endl;
			}
			
			Sleep(300);
			system("cls");
			continue;
		}
		if (_vMonster->hp <= 0)
		{
			if (_hp > 0)
			{
				int bootySelect = rand() % 4; // ����ǰ ȹ�� �б�
				int moneyTemp;
				cout << "���Ͱ� �׾����ϴ�." << endl;
				cout << "����ġ " << _vMonster->exp << " ȹ��!" << endl;
				_exp = _exp + _vMonster->exp;

				if (bootySelect == 0) cout << "���Ϳ��Լ� �ƹ� ����ǰ�� ȹ������ ���߽��ϴ�." << endl;
				else if (bootySelect == 1) // ���� �Ծ��� ��
				{
					int randomMoneyNum = rand() % _vMonster->money;
					moneyTemp = _vMonster->money - randomMoneyNum;
					_money = _money + moneyTemp;
					cout << "��� " << moneyTemp << "G ȹ��!" << endl;
				}
				else if (bootySelect == 2) // �����۸� �Ծ��� ��
				{
					cout << "[TEST] �����۸� ȹ��" << endl;
					dungeon_il.dropItemList(_vMonster->dl, _vMonster->callNum);
				}
				else // ��, ������ ��� �Ծ��� ��
				{
					cout << "[TEST] ���/������ ȹ��" << endl;
					int randomMoneyNum = rand() % _vMonster->money;
					moneyTemp = _vMonster->money - randomMoneyNum;
					_money = _money + moneyTemp;
					cout << "��� " << moneyTemp << "G ȹ��!" << endl;
					dungeon_il.dropItemList(_vMonster->dl, _vMonster->callNum);
				}

				_vMonster->hp = _vMonster->max_hp; // ���� �� ���� ���·� �ѹ�
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
	}
}

void dungeonClass::charactorStatus(int roleNum, char name[32], int level, int max_hp, int add_max_hp, int hp, int max_mp, int add_max_mp, int mp, int pwr, int add_pwr, int mindmg, int dex, int add_dex, int intel, int add_intel, int exp, int totalExp, int money)
{
	_roleNum = roleNum;
	if (_roleNum == 1) strncpy_s(_roleName, "����", 32);
	else if (_roleNum == 2) strncpy_s(_roleName, "������", 32);
	else if (_roleNum == 3) strncpy_s(_roleName, "����", 32);
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
	dungeon_mm.itemInfoSave(1, div, kind, role, itemName, point, req_level, req_pwr, req_dex, req_intel, hpOption, mpOption, pwrOption, dexOption, intelOption, price);
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
		// �������� ���
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
		// ������ ���
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
		Sleep(2000);
	}
	else _exp = _exp;
	dungeonMain();
}

void dungeonClass::attackPoint(int mindmg)
{
	_userAttackPoint = rand() % _pwr + mindmg + 1; // ���ݷ� ���� ����(�ּ� ���ݷ� 1�̻�) --> ĳ���� ��(����) + �ּҵ�����
	int dodgeCheck;

	// ȸ�Ǵ� ��� ���͵鿡 ���� ���� Ȯ���� �����Ǿ�� ��
	// ȸ��Ȯ�� ���� ����
	_playerDodgePoint = ((rand() % _dex + 1) % 10) + ((rand() % _dex + 1) / 10);

	// �÷��̾� ȸ�� Ȯ�� ���
	if (_playerDodgePoint >= _monsterDodgePoint)
	{
		dodgeCheck = rand() % 2;
		if (dodgeCheck == 1)
		{
			_vMonster->monsterAttackPoint = 0;
			cout << "������ ������ ȸ���Ͽ����ϴ�." << endl;
		}
	}
	else
	{
		dodgeCheck = rand() % _vMonster->dex - _playerDodgePoint + 1;
		if (dodgeCheck == 1)
		{
			_vMonster->monsterAttackPoint = 0;
			cout << "������ ������ ȸ���Ͽ����ϴ�." << endl;
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
		cout << "���� ���Դϴ�." << endl;
		_hp = _hp - _vMonster->monsterAttackPoint;

		cout << "���Ͱ� " << _vMonster->monsterAttackPoint << "��ŭ �������� �־����ϴ�." << endl;
	}

	// ������ ȸ�� Ȯ�� ���
	if (_monsterDodgePoint >= _playerDodgePoint)
	{
		dodgeCheck = rand() % 2;
		if (dodgeCheck == 1)
		{
			_userAttackPoint = 0;
			cout << "�÷��̾��� ������ ȸ���Ͽ����ϴ�." << endl;
		}
	}
	else
	{
		dodgeCheck = rand() % _playerDodgePoint - _vMonster->dex + 1;
		if (dodgeCheck == 1)
		{
			_userAttackPoint = 0;
			cout << "�÷��̾��� ������ ȸ���Ͽ����ϴ�." << endl;
		}
	}
	Sleep(300);
}

void dungeonClass::userInterface(void)
{
	cout << "========== " << _name << " ==========" << endl;
	cout << "���� : " << _level << endl;
	cout << "����ġ : " << _exp << " / " << _totalExp << endl;
	cout << "========== HP / MP / GOLD ==========" << endl;
	cout << "����� : " << _hp << " / " << _max_hp << endl;
	cout << "���� : " << _mp << " / " << _max_mp << endl;
	cout << "�����ݾ� : " << _money << " G" << endl;
	cout << endl;
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
	_mp = _max_mp;
	_vMonster->hp = _vMonster->max_hp;
	cout << "�ױ� �� ����ġ : " << tempExp << " / ���� ����ġ : " << _exp << endl;
	dungeonMain();
}

void dungeonClass::setMonster(void)
{
	tagMONSTERSTATS d1_monster1;
	d1_monster1.dl = DUNGEON1;
	d1_monster1.callNum = 1;
	strncpy_s(d1_monster1.name, "����1", 32);
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
	strncpy_s(d1_monster2.name, "����2", 32);
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
	strncpy_s(d1_monster3.name, "����3", 32);
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
	strncpy_s(d1_monster4_special.name, "��������1", 32);
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
	strncpy_s(d2_monster1.name, "����4", 32);
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
	strncpy_s(d2_monster2.name, "����5", 32);
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
	strncpy_s(d2_monster3.name, "����6", 32);
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
	strncpy_s(d2_monster4_special.name, "��������2", 32);
	d2_monster4_special.max_hp = 400;
	d2_monster4_special.hp = 400;
	d2_monster4_special.pwr = 30;
	d2_monster4_special.dex = 20;
	d2_monster4_special.exp = 50;
	d2_monster4_special.money = 900;
	d2_monster4_special.monsterPwr = 30;
	_monster.push_back(d2_monster4_special);
}
