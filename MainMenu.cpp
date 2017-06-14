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
		cout << "========== ĳ���� ���� ==========" << endl;
		cout << "1.����\t 2.������\t 3.����" << endl;
		cout << "ĳ���͸� �����ϼ���." << endl;
		cin >> _charactorSelect;
		system("cls");

		switch (_charactorSelect)
		{
			case 1:
				cout << "ĳ���� �г����� �Է��ϼ���(�ִ� ���� 31��, �ѱ� 15��)" << endl;
				cin >> _charName;
				setUp(WARRIOR, _charName);
			break;
			case 2:
				cout << "ĳ���� �г����� �Է��ϼ���(�ִ� ���� 31��, �ѱ� 15��)" << endl;
				cin >> _charName;
				setUp(WIZARD, _charName);
			break;
			case 3:
				cout << "ĳ���� �г����� �Է��ϼ���(�ִ� ���� 31��, �ѱ� 15��)" << endl;
				cin >> _charName;
				setUp(ELF, _charName);
			break;
			default:
				cout << "�߸��� ��ȣ�� �Է��߽��ϴ�. �ٽ� �Է����ּ���." << endl;
				system("cls");
			continue;
		}
		break;
	}

	system("cls");
	output(_charactorSelect);

	startMenu();
}

// ���� ĳ���� ���� �� �⺻ ���� ����
void MainMenu::output(int charNumber)
{
	for (_vriter = _role.begin(); _vriter != _role.end(); ++_vriter)
	{
		if (_vriter->roleCharactor != charNumber) continue;
		
		init();

		cout << "�̸� : " << _vriter->name << endl;
		cout << "�Ѱ���ġ : " << _vriter->totalExp << endl;
		cout << "HP : " << _vriter->max_hp << endl;
		cout << "MP : " << _vriter->max_mp << endl;
		cout << "�� : " << _vriter->pwr << endl;
		cout << "��ø : " << _vriter->dex << endl;
		cout << "���� : " << _vriter->intel << endl;
		cout << "�����ݾ� : " << _vriter->money << " G" << endl;
		us.charactorStatus(_vriter->roleCharactor, _vriter->name, _vriter->level, _vriter->max_hp, _vriter->add_max_hp, _vriter->hp, _vriter->max_mp, _vriter->add_max_mp, _vriter->mp, _vriter->pwr, _vriter->add_pwr, _vriter->mindmg, _vriter->dex, _vriter->add_dex, _vriter->intel, _vriter->add_intel, _vriter->exp, _vriter->totalExp, _vriter->money);
		dg.charactorStatus(_vriter->roleCharactor, _vriter->name, _vriter->level, _vriter->max_hp, _vriter->add_max_hp, _vriter->hp, _vriter->max_mp, _vriter->add_max_mp, _vriter->mp, _vriter->pwr, _vriter->add_pwr, _vriter->mindmg, _vriter->dex, _vriter->add_dex, _vriter->intel, _vriter->add_intel, _vriter->exp, _vriter->totalExp, _vriter->money);
		inn.charactorStatus(_vriter->roleCharactor, _vriter->name, _vriter->level, _vriter->max_hp, _vriter->add_max_hp, _vriter->hp, _vriter->max_mp, _vriter->add_max_mp, _vriter->mp, _vriter->pwr, _vriter->add_pwr, _vriter->mindmg, _vriter->dex, _vriter->add_dex, _vriter->intel, _vriter->add_intel, _vriter->exp, _vriter->totalExp, _vriter->money);
	}
}

void MainMenu::charactorStatus(int viewPoint, int roleNum, char name[32], int level, int max_hp, int add_max_hp, int hp, int max_mp, int add_max_mp, int mp, int pwr, int add_pwr, int mindmg, int dex, int add_dex, int intel, int add_intel, int exp, int totalExp, int money)
{
	tagCharactorStats USER;
	USER.roleCharactor = ROLE(roleNum);
	strncpy_s(USER.name, name, 32);
	USER.level = level;
	USER.max_hp = max_hp;
	USER.add_max_hp = add_max_hp;
	USER.hp = hp;
	USER.max_mp = max_mp;
	USER.add_max_mp = add_max_mp;
	USER.mp = mp;
	USER.pwr = pwr;
	USER.add_pwr = add_pwr;
	USER.mindmg = mindmg;
	USER.dex = dex;
	USER.add_dex = add_dex;
	USER.intel = intel;
	USER.add_intel = add_intel;
	USER.exp = exp;
	USER.totalExp = totalExp;
	USER.money = money;
	_role.push_back(USER);
	for (_vriter = _role.begin(); _vriter != _role.end(); ++_vriter)
	{
		if (_vriter->roleCharactor != roleNum) continue;

		// ĳ���� ���� ����� �ʿ��� ��� viewPoint�� 0 ����,
		// �ܼ��� ������ �ѱ� ��� viewPoint�� 1��
		if (viewPoint == 0)
		{
			cout << "�̸� : " << _vriter->name << endl;
			cout << "����ġ : " << _vriter->exp << " / " << _vriter->totalExp << endl;
			cout << "HP : " << _vriter->hp << " / " << _vriter->max_hp << endl;
			cout << "MP : " << _vriter->mp << " / " << _vriter->max_mp << endl;
			cout << "�� : " << _vriter->pwr << endl;
			cout << "��ø : " << _vriter->dex << endl;
			cout << "���� : " << _vriter->intel << endl;
			us.charactorStatus(_vriter->roleCharactor, _vriter->name, _vriter->level, _vriter->max_hp, _vriter->add_max_hp, _vriter->hp, _vriter->max_mp, _vriter->add_max_mp, _vriter->mp, _vriter->pwr, _vriter->add_pwr, _vriter->mindmg, _vriter->dex, _vriter->add_dex, _vriter->intel, _vriter->add_intel, _vriter->exp, _vriter->totalExp, _vriter->money);
			dg.charactorStatus(_vriter->roleCharactor, _vriter->name, _vriter->level, _vriter->max_hp, _vriter->add_max_hp, _vriter->hp, _vriter->max_mp, _vriter->add_max_mp, _vriter->mp, _vriter->pwr, _vriter->add_pwr, _vriter->mindmg, _vriter->dex, _vriter->add_dex, _vriter->intel, _vriter->add_intel, _vriter->exp, _vriter->totalExp, _vriter->money);
			inn.charactorStatus(_vriter->roleCharactor, _vriter->name, _vriter->level, _vriter->max_hp, _vriter->add_max_hp, _vriter->hp, _vriter->max_mp, _vriter->add_max_mp, _vriter->mp, _vriter->pwr, _vriter->add_pwr, _vriter->mindmg, _vriter->dex, _vriter->add_dex, _vriter->intel, _vriter->add_intel, _vriter->exp, _vriter->totalExp, _vriter->money);
			Sleep(3000);
		}
		else if (viewPoint == 1)
		{
			us.charactorStatus(_vriter->roleCharactor, _vriter->name, _vriter->level, _vriter->max_hp, _vriter->add_max_hp, _vriter->hp, _vriter->max_mp, _vriter->add_max_mp, _vriter->mp, _vriter->pwr, _vriter->add_pwr, _vriter->mindmg, _vriter->dex, _vriter->add_dex, _vriter->intel, _vriter->add_intel, _vriter->exp, _vriter->totalExp, _vriter->money);
			dg.charactorStatus(_vriter->roleCharactor, _vriter->name, _vriter->level, _vriter->max_hp, _vriter->add_max_hp, _vriter->hp, _vriter->max_mp, _vriter->add_max_mp, _vriter->mp, _vriter->pwr, _vriter->add_pwr, _vriter->mindmg, _vriter->dex, _vriter->add_dex, _vriter->intel, _vriter->add_intel, _vriter->exp, _vriter->totalExp, _vriter->money);
			inn.charactorStatus(_vriter->roleCharactor, _vriter->name, _vriter->level, _vriter->max_hp, _vriter->add_max_hp, _vriter->hp, _vriter->max_mp, _vriter->add_max_mp, _vriter->mp, _vriter->pwr, _vriter->add_pwr, _vriter->mindmg, _vriter->dex, _vriter->add_dex, _vriter->intel, _vriter->add_intel, _vriter->exp, _vriter->totalExp, _vriter->money);
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
		Sleep(100);
		system("cls");
		int inGameMenuSelect;
		cout << "========== IN GAME MENU ==========" << endl;
		cout << "1.����\t 2.����\t 3.����\t 4.ĳ������" << endl;
		cout << "�޴��� �����ϼ���." << endl;
		cin >> inGameMenuSelect;
		switch (inGameMenuSelect)
		{
			case 1:
				dungeonSelect();
			break;
			case 2:
				store();
			break;
			case 3:
				inn.innMenu();
			break;
			case 4:
				us.userInfo();
			break;
			default:
				cout << "�߸��� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
			continue;
		}
	}
}

void MainMenu::dungeonSelect(void)
{
	dg.dungeonMain();
}

void MainMenu::store(void)
{
	while (true)
	{
		int storeMenuSelect;
		cout << "========== STORE ==========" << endl;
		cout << "1.����\t 2.��\t 3.�Ǽ��縮" << endl;
		cin >> storeMenuSelect;

		switch (storeMenuSelect)
		{
			case 1:
				il.storeItemList(storeMenuSelect);
			break;
			case 2:
				il.storeItemList(storeMenuSelect);
			break;
			case 3:
				il.storeItemList(storeMenuSelect);
			break;
			default:
				cout << "�߸��� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
			continue;
		}
	}
}

void MainMenu::init(void)
{
	_vriter->exp = 0;
	_vriter->totalExp = 20;
	_vriter->money = 100;
	_vriter->mindmg = 0;
	_vriter->add_max_hp = 0;
	_vriter->add_max_mp = 0;
	_vriter->add_pwr = 0;
	_vriter->add_dex = 0;
	_vriter->add_intel = 0;
}

