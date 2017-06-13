#include "MainMenu.h"

MainMenu::MainMenu()
{
}


MainMenu::~MainMenu()
{
}

void MainMenu::mainStart()
{
	while (true)
	{
		cout << "========== 캐릭터 선택 ==========" << endl;
		cout << "1.전사\t 2.마법사\t 3.엘프" << endl;
		cout << "캐릭터를 선택하세요." << endl;
		cin >> _charactorSelect;

		switch (_charactorSelect)
		{
			case 1:
				cout << "캐릭터 닉네임을 입력하세요(최대 14자)" << endl;
				cin >> _charName;
				setUp(WARRIOR, _charName);
			break;
			case 2:
				cout << "캐릭터 닉네임을 입력하세요(최대 14자)" << endl;
				cin >> _charName;
				setUp(WIZARD, _charName);
			break;
			case 3:
				cout << "캐릭터 닉네임을 입력하세요(최대 14자)" << endl;
				cin >> _charName;
				setUp(ELF, _charName);
			break;
			default:
				cout << "잘못된 번호를 입력했습니다. 다시 입력해주세요." << endl;
				system("cls");
			continue;
		}
		break;
	}

	system("cls");
	output(_charactorSelect);

	startMenu();
}

void MainMenu::output(int charNumber)
{
	for (_vriter = _role.begin(); _vriter != _role.end(); ++_vriter)
	{
		if (_vriter->roleCharactor != charNumber) continue;
		
		_vriter->exp = 0;
		_vriter->totalExp = 100;

		cout << "이름 : " << _vriter->name << endl;
		cout << "총경험치 : " << _vriter->totalExp << endl;
		cout << "HP : " << _vriter->max_hp << endl;
		cout << "MP : " << _vriter->max_mp << endl;
		cout << "힘 : " << _vriter->pwr << endl;
		cout << "민첩 : " << _vriter->dex << endl;
		cout << "지능 : " << _vriter->intel << endl;
		us.charactorStatus(_vriter->roleCharactor, _vriter->name, _vriter->level, _vriter->max_hp, _vriter->hp, _vriter->max_mp, _vriter->mp, _vriter->pwr, _vriter->dex, _vriter->intel, _vriter->exp, _vriter->totalExp);
		dg.charactorStatus(_vriter->roleCharactor, _vriter->name, _vriter->level, _vriter->max_hp, _vriter->hp, _vriter->max_mp, _vriter->mp, _vriter->pwr, _vriter->dex, _vriter->intel, _vriter->exp, _vriter->totalExp);
	}
}

void MainMenu::charactorStatus(int viewPoint, int roleNum, char name[32], int level, int max_hp, int hp, int max_mp, int mp, int pwr, int dex, int intel, int exp, int totalExp)
{
	// 이 함수를 계속 호출하면 호출한만큼 _role 의 저장갯수가 증가하여 반복증가되어 출력됨...
	// 한번만 출력되도록 바꿔야 함
	tagCharactorStats USER;
	USER.roleCharactor = ROLE(roleNum);
	strncpy_s(USER.name, name, 32);
	USER.level = level;
	USER.max_hp = max_hp;
	USER.hp = hp;
	USER.max_mp = max_mp;
	USER.mp = mp;
	USER.pwr = pwr;
	USER.dex = dex;
	USER.intel = intel;
	USER.exp = exp;
	USER.totalExp = totalExp;
	_role.push_back(USER);
	for (_vriter = _role.begin(); _vriter != _role.end(); ++_vriter)
	{
		if (_vriter->roleCharactor != roleNum) continue;

		if (viewPoint == 0)
		{
			cout << "이름 : " << _vriter->name << endl;
			cout << "경험치 : " << _vriter->exp << " / " << _vriter->totalExp << endl;
			cout << "HP : " << _vriter->hp << " / " << _vriter->max_hp << endl;
			cout << "MP : " << _vriter->mp << " / " << _vriter->max_mp << endl;
			cout << "힘 : " << _vriter->pwr << endl;
			cout << "민첩 : " << _vriter->dex << endl;
			cout << "지능 : " << _vriter->intel << endl;
			us.charactorStatus(_vriter->roleCharactor, _vriter->name, _vriter->level, _vriter->max_hp, _vriter->hp, _vriter->max_mp, _vriter->mp, _vriter->pwr, _vriter->dex, _vriter->intel, _vriter->exp, _vriter->totalExp);
			dg.charactorStatus(_vriter->roleCharactor, _vriter->name, _vriter->level, _vriter->max_hp, _vriter->hp, _vriter->max_mp, _vriter->mp, _vriter->pwr, _vriter->dex, _vriter->intel, _vriter->exp, _vriter->totalExp);
		}
		else if (viewPoint == 1)
		{
			us.charactorStatus(_vriter->roleCharactor, _vriter->name, _vriter->level, _vriter->max_hp, _vriter->hp, _vriter->max_mp, _vriter->mp, _vriter->pwr, _vriter->dex, _vriter->intel, _vriter->exp, _vriter->totalExp);
			dg.charactorStatus(_vriter->roleCharactor, _vriter->name, _vriter->level, _vriter->max_hp, _vriter->hp, _vriter->max_mp, _vriter->mp, _vriter->pwr, _vriter->dex, _vriter->intel, _vriter->exp, _vriter->totalExp);
		}
	}
	Sleep(500);
}

void MainMenu::setUp(int charactorSelect, char charName[32])
{
	if (charactorSelect == WARRIOR)
	{
		tagCharactorStats WARRIOR1;
		WARRIOR1.roleCharactor = WARRIOR;
		strncpy_s(WARRIOR1.name, 32, charName, 32);
		WARRIOR1.level = 1;
		WARRIOR1.max_hp = 200;
		WARRIOR1.hp = 200;
		WARRIOR1.max_mp = 50;
		WARRIOR1.mp = 50;
		WARRIOR1.pwr = 10;
		WARRIOR1.dex = 5;
		WARRIOR1.intel = 2;
		_role.push_back(WARRIOR1);
	}
	else if (charactorSelect == WIZARD)
	{
		tagCharactorStats WIZARD1;
		WIZARD1.roleCharactor = WIZARD;
		strncpy_s(WIZARD1.name, 32, charName, 32);
		WIZARD1.level = 1;
		WIZARD1.max_hp = 80;
		WIZARD1.hp = 80;
		WIZARD1.max_mp = 200;
		WIZARD1.mp = 200;
		WIZARD1.pwr = 2;
		WIZARD1.dex = 4;
		WIZARD1.intel = 10;
		_role.push_back(WIZARD1);
	}
	else if (charactorSelect == ELF)
	{
		tagCharactorStats ELF1;
		ELF1.roleCharactor = ELF;
		strncpy_s(ELF1.name, 32, charName, 32);
		ELF1.level = 1;
		ELF1.max_hp = 100;
		ELF1.hp = 100;
		ELF1.max_mp = 150;
		ELF1.mp = 150;
		ELF1.pwr = 2;
		ELF1.dex = 4;
		ELF1.intel = 10;
		_role.push_back(ELF1);
	}
}

void MainMenu::startMenu()
{
	while (true)
	{
		Sleep(1000);
		system("cls");
		int inGameMenuSelect;
		cout << "========== IN GAME MENU ==========" << endl;
		cout << "1.던전\t 2.상점\t 3.주점\t 4.캐릭정보" << endl;
		cout << "메뉴를 선택하세요." << endl;
		cin >> inGameMenuSelect;
		switch (inGameMenuSelect)
		{
			case 1:
				dungeonSelect();
			break;
			case 2:
			break;
			case 3:
			break;
			case 4:
				us.userInfo();
			break;
			default:
				cout << "잘못된 번호를 입력하셨습니다. 다시 입력해주세요." << endl;
			continue;
		}
	}
}

void MainMenu::dungeonSelect(void)
{
	dg.dungeonMain();
}

