#include "itemList.h"
#include "MainMenu.h"
#include "inventory.h"

MainMenu il_mm;
inventory il_inven;

itemList::itemList()
{
	dropItemSetting();
	storeItemSetting();
}

itemList::~itemList()
{
}

void itemList::storeItemList(int kindNum)
{
	system("cls");
	// 1:무기, 2:방어구, 3:악세사리, 4:포션 5:가방
	switch (kindNum)
	{
		case 1:
			for (_vstoreItem = _storeItem.begin(); _vstoreItem != _storeItem.end(); ++_vstoreItem)
			{
				itemInit(1);
				if (_vstoreItem->division != ITEMDIVISION::STOREITEM) continue;
				if (_vstoreItem->kind != ITEMKIND(kindNum - 1)) continue;
				cout << "구매번호 : " << _vstoreItem->itemNum << endl;
				cout << "아이템명 : " << _vstoreItem->itemName << endl;
				cout << "구입가능직업 : ";
				if (_vstoreItem->role == ITEMROLE::WARRIOR) cout << "전사" << endl;
				else if (_vstoreItem->role == ITEMROLE::WIZARD) cout << "마법사" << endl;
				else if (_vstoreItem->role == ITEMROLE::ELF) cout << "엘프" << endl;
				cout << "공격력 : " << _vstoreItem->point << endl;
				if (_vstoreItem->pwrOption != 0) cout << "옵션(힘) : " << _vstoreItem->pwrOption << endl;
				if (_vstoreItem->dexOption != 0) cout << "옵션(민첩) : " << _vstoreItem->dexOption << endl;
				if (_vstoreItem->intelOption != 0) cout << "옵션(지능) : " << _vstoreItem->intelOption << endl;
				cout << "가격 : " << _vstoreItem->price << endl;
				cout << endl;
			}
		break;
		case 2:
			for (_vstoreItem = _storeItem.begin(); _vstoreItem != _storeItem.end(); ++_vstoreItem)
			{
				itemInit(1);
				if (_vstoreItem->division != ITEMDIVISION::STOREITEM) continue;
				if (_vstoreItem->kind != ITEMKIND(kindNum - 1)) continue;
				cout << "구매번호 : " << _vstoreItem->itemNum << endl;
				cout << "아이템명 : " << _vstoreItem->itemName << endl;
				cout << "구입가능직업 : ";
				if (_vstoreItem->role == ITEMROLE::WARRIOR) cout << "전사" << endl;
				else if (_vstoreItem->role == ITEMROLE::WIZARD) cout << "마법사" << endl;
				else if (_vstoreItem->role == ITEMROLE::ELF) cout << "엘프" << endl;
				cout << "방어력 : " << _vstoreItem->point << endl;
				if (_vstoreItem->pwrOption != 0) cout << "옵션(힘) : " << _vstoreItem->pwrOption << endl;
				if (_vstoreItem->dexOption != 0) cout << "옵션(민첩) : " << _vstoreItem->dexOption << endl;
				if (_vstoreItem->intelOption != 0) cout << "옵션(지능) : " << _vstoreItem->intelOption << endl;
				cout << "가격 : " << _vstoreItem->price << endl;
				cout << endl;
			}
		break;
		case 3:
		break;
		case 4:
		break;
	}
	purchaseMenu(kindNum);
}

void itemList::dropItemList(int dungeonNum, int callNum)
{
	cout << "dropItemList 함수 진입" << endl;
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
				cout << "_d1DropItem.size() : " << _d1DropItem.size() - _d1BossDropItem.size() << endl;
				cout << "_vdropItem->itemNum : " << _vdropItem->itemNum << endl;
				cout << "_d1DropItemChoice : " << _d1DropItemChoice << endl;
				cout << "================================" << endl;
				Sleep(1000);
				if (_vdropItem->itemNum == _d1DropItemChoice)
				{
					cout << "[TEST] 드랍 아이템 INVENTORY로 저장 중..." << endl;
					itemInfoSave(_vdropItem->division, _vdropItem->kind, _vdropItem->role, _vdropItem->itemName, _vdropItem->req_level, _vdropItem->req_pwr, _vdropItem->req_dex, _vdropItem->req_intel, _vdropItem->hpOption, _vdropItem->mpOption, _vdropItem->point, _vdropItem->pwrOption, _vdropItem->dexOption, _vdropItem->intelOption, _vdropItem->price);
				}
			}
			else if (MONSTERNUM(callNum) == MONSTERNUM::BOSS)
			{
				cout << "_d1BossDropItem.size() : " << _d1BossDropItem.size() << endl;
				cout << "_vdropItem->itemNum : " << _vdropItem->itemNum << endl;
				cout << "_d1BossDropItemChoice : " << _d1BossDropItemChoice << endl;
				cout << "================================" << endl;
				Sleep(1000);
				if (_vdropItem->itemNum == _d1BossDropItemChoice)
				{
					cout << "[TEST] BOSS 드랍 아이템 INVENTORY로 저장 중..." << endl;
					itemInfoSave(_vdropItem->division, _vdropItem->kind, _vdropItem->role, _vdropItem->itemName, _vdropItem->req_level, _vdropItem->req_pwr, _vdropItem->req_dex, _vdropItem->req_intel, _vdropItem->hpOption, _vdropItem->mpOption, _vdropItem->point, _vdropItem->pwrOption, _vdropItem->dexOption, _vdropItem->intelOption, _vdropItem->price);
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
				cout << "_dropItem.size() : " << _d2DropItem.size() - _d2BossDropItem.size() << endl;
				cout << "_d2DropItemChoice : " << _d2DropItemChoice << endl;
				cout << "================================" << endl;
				Sleep(1000);
				if (_vdropItem->itemNum == _d2DropItemChoice)
				{
					cout << "[TEST] 드랍 아이템 INVENTORY로 저장 중..." << endl;
					itemInfoSave(_vdropItem->division, _vdropItem->kind, _vdropItem->role, _vdropItem->itemName, _vdropItem->req_level, _vdropItem->req_pwr, _vdropItem->req_dex, _vdropItem->req_intel, _vdropItem->hpOption, _vdropItem->mpOption, _vdropItem->point, _vdropItem->pwrOption, _vdropItem->dexOption, _vdropItem->intelOption, _vdropItem->price);
				}
			}
			else
			{
				cout << "_dropItem.size() : " << _d2BossDropItem.size() << endl;
				cout << "_d2BossDropItemChoice : " << _d2BossDropItemChoice << endl;
				cout << "================================" << endl;
				Sleep(1000);
				if (_vdropItem->itemNum == _d2BossDropItemChoice)
				{
					cout << "[TEST] BOSS 드랍 아이템 INVENTORY로 저장 중..." << endl;
					itemInfoSave(_vdropItem->division, _vdropItem->kind, _vdropItem->role, _vdropItem->itemName, _vdropItem->req_level, _vdropItem->req_pwr, _vdropItem->req_dex, _vdropItem->req_intel, _vdropItem->hpOption, _vdropItem->mpOption, _vdropItem->point, _vdropItem->pwrOption, _vdropItem->dexOption, _vdropItem->intelOption, _vdropItem->price);
				}
			}
		}
	}
}

void itemList::purchaseMenu(int kindNum)
{
	bool exit = 0;
	while (exit != 1)
	{
		int purchaseNum;
		int purchaseMenuSelect;
		int equipSelect;
		cout << "========== ITEM UI ==========" << endl;
		cout << "1.구매\t 2.되돌아가기" << endl;
		cin >> purchaseMenuSelect;

		switch (purchaseMenuSelect)
		{
			case 1:
				cout << "구매 아이템 번호를 입력하세요." << endl;
				cin >> purchaseNum;
				for (_vstoreItem = _storeItem.begin(); _vstoreItem != _storeItem.end(); ++_vstoreItem)
				{
					if (purchaseNum == _vstoreItem->itemNum)
					{
						if (_vstoreItem->kind != ITEMKIND(kindNum - 1)) continue;
						if (_money >= _vstoreItem->price)
						{
							system("cls");
							_money = _money - _vstoreItem->price;
							il_mm.charactorStatus(1, _roleNum, _name, _level, _max_hp, _add_max_hp, _hp, _max_mp, _add_max_mp, _mp, _pwr, _add_pwr, _mindmg, _dex, _add_dex, _intel, _add_intel, _exp, _totalExp, _money);
							if (_vstoreItem->division != ITEMDIVISION::STOREITEM) continue;
							if (_vstoreItem->kind != ITEMKIND(kindNum - 1)) continue;
							itemInfoSave(_vstoreItem->division, _vstoreItem->kind, _vstoreItem->role, _vstoreItem->itemName, _vstoreItem->req_level, _vstoreItem->req_pwr, _vstoreItem->req_dex, _vstoreItem->req_intel, _vstoreItem->hpOption, _vstoreItem->mpOption, _vstoreItem->point, _vstoreItem->pwrOption, _vstoreItem->dexOption, _vstoreItem->intelOption, _vstoreItem->price);
							while (true)
							{
								cout << "구매번호 : " << _vstoreItem->itemNum << endl;
								cout << "아이템명 : " << _vstoreItem->itemName << endl;
								cout << "착용가능직업 : ";
								if (_vstoreItem->role == ITEMROLE::WARRIOR) cout << "전사" << endl;
								else if (_vstoreItem->role == ITEMROLE::WIZARD) cout << "마법사" << endl;
								else if (_vstoreItem->role == ITEMROLE::ELF) cout << "엘프" << endl;
								cout << "공격력 : " << _vstoreItem->point << endl;
								if (_vstoreItem->pwrOption != 0) cout << "옵션(힘) : " << _vstoreItem->pwrOption << endl;
								if (_vstoreItem->dexOption != 0) cout << "옵션(민첩) : " << _vstoreItem->dexOption << endl;
								if (_vstoreItem->intelOption != 0) cout << "옵션(지능) : " << _vstoreItem->intelOption << endl;
								cout << "가격 : " << _vstoreItem->price << endl;
								cout << "======================================" << endl;
								cout << "해당 아이템을 장착하시겠습니까? (예:1 / 아니오:2)" << endl;
								cin >> equipSelect;
								switch (equipSelect)
								{
									case 1:
										// 미구현
										il_mm.store();
									break;
									case 2:
										il_mm.store();
									break;
									default:
										cout << "잘못된 번호를 입력하셨습니다. 다시 입력해주세요." << endl;
										system("cls");
									continue;
								}
							}
						}						
						else
						{
							cout << "보유금액이 부족합니다." << endl;
							cout << "부족한 금액 : " << _vstoreItem->price - _money << " G" << endl;
						}
					}
				}
			break;
			case 2:
				/*il_mm.charactorStatus(1, _roleNum, _name, _level, _max_hp, _add_max_hp, _hp, _max_mp, _add_max_mp, _mp, _pwr, _add_pwr, _mindmg, _dex, _add_dex, _intel, _add_intel, _exp, _totalExp, _money);
				il_mm.store();*/
				exit = 1;
			break;
			default:
				cout << "잘못된 번호를 입력하셨습니다. 다시 입력해주세요." << endl;
			continue;
		}
	}
}

void itemList::itemInit(int initNum)
{
	if (initNum == 1)
	{
		if (_vstoreItem->point <= 0) _vstoreItem->point = 0;
		if (_vstoreItem->hpOption <= 0) _vstoreItem->hpOption = 0;
		if (_vstoreItem->mpOption <= 0) _vstoreItem->mpOption = 0;
		if (_vstoreItem->pwrOption <= 0) _vstoreItem->pwrOption = 0;
		if (_vstoreItem->dexOption <= 0) _vstoreItem->dexOption = 0;
		if (_vstoreItem->intelOption <= 0) _vstoreItem->intelOption = 0;
		if (_vstoreItem->price <= 0) _vstoreItem->price = 0;
		if (_vstoreItem->req_level <= 0) _vstoreItem->req_level = 1;
		if (_vstoreItem->req_pwr <= 0) _vstoreItem->req_pwr = 0;
		if (_vstoreItem->req_dex <= 0) _vstoreItem->req_dex = 0;
		if (_vstoreItem->req_intel <= 0) _vstoreItem->req_intel = 0;
	}
	else if (initNum == 2)
	{
		if (_vinven->point <= 0) _vinven->point = 0;
		if (_vinven->hpOption <= 0) _vinven->hpOption = 0;
		if (_vinven->mpOption <= 0) _vinven->mpOption = 0;
		if (_vinven->pwrOption <= 0) _vinven->pwrOption = 0;
		if (_vinven->dexOption <= 0) _vinven->dexOption = 0;
		if (_vinven->intelOption <= 0) _vinven->intelOption = 0;
		if (_vinven->price <= 0) _vinven->price = 0;
		if (_vinven->req_level <= 0) _vinven->req_level = 1;
		if (_vinven->req_pwr <= 0) _vinven->req_pwr = 0;
		if (_vinven->req_dex <= 0) _vinven->req_dex = 0;
		if (_vinven->req_intel <= 0) _vinven->req_intel = 0;
	}
}

void itemList::charactorStatus(int roleNum, char name[32], int level, int max_hp, int add_max_hp, int hp, int max_mp, int add_max_mp, int mp, int pwr, int add_pwr, int mindmg, int dex, int add_dex, int intel, int add_intel, int exp, int totalExp, int money)
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


void itemList::itemInfoSave(ITEMDIVISION div, ITEMKIND kind, ITEMROLE role, char itemName[32], int point, int req_level, int req_pwr, int req_dex, int req_intel, int hpOption, int mpOption, int pwrOption, int dexOption, int intelOption, int price)
{
	il_mm.itemInfoSave(0, div, kind, role, itemName, point, req_level, req_pwr, req_dex, req_intel, hpOption, mpOption, pwrOption, dexOption, intelOption, price);
}

void itemList::storeItemSetting(void)
{
	ITEM storeItem_weapon1;
	storeItem_weapon1.division = ITEMDIVISION::STOREITEM;
	storeItem_weapon1.kind = ITEMKIND::WEAPON;
	storeItem_weapon1.role = ITEMROLE::WARRIOR;
	strncpy_s(storeItem_weapon1.itemName, "숏쇼드", 32);
	storeItem_weapon1.req_level = 1;
	storeItem_weapon1.req_pwr = 3;
	storeItem_weapon1.req_dex = 1;
	storeItem_weapon1.req_intel = 0;
	storeItem_weapon1.point = 5;
	storeItem_weapon1.pwrOption = 1;
	storeItem_weapon1.price = 500;
	storeItem_weapon1.itemNum = 1;
	_storeItem.push_back(storeItem_weapon1);

	ITEM storeItem_weapon2;
	storeItem_weapon2.division = ITEMDIVISION::STOREITEM;
	storeItem_weapon2.kind = ITEMKIND::WEAPON;
	storeItem_weapon2.role = ITEMROLE::WARRIOR;
	strncpy_s(storeItem_weapon2.itemName, "날이 서 있는 브로드소드", 32);
	storeItem_weapon2.req_level = 2;
	storeItem_weapon2.req_pwr = 8;
	storeItem_weapon2.req_dex = 5;
	storeItem_weapon2.req_intel = 0;
	storeItem_weapon2.point = 15;
	storeItem_weapon2.pwrOption = 3;
	storeItem_weapon2.dexOption = 1;
	storeItem_weapon2.price = 1200;
	storeItem_weapon2.itemNum = storeItem_weapon1.itemNum + 1;
	_storeItem.push_back(storeItem_weapon2);

	ITEM storeItem_armor1;
	storeItem_armor1.division = ITEMDIVISION::STOREITEM;
	storeItem_armor1.kind = ITEMKIND::ARMOR;
	storeItem_armor1.role = ITEMROLE::WARRIOR;
	strncpy_s(storeItem_armor1.itemName, "낡은 판금 갑옷", 32);
	storeItem_armor1.req_level = 1;
	storeItem_armor1.req_pwr = 3;
	storeItem_armor1.req_dex = 1;
	storeItem_armor1.req_intel = 0;
	storeItem_armor1.point = 5;
	storeItem_armor1.pwrOption = 1;
	storeItem_armor1.dexOption = 0;
	storeItem_armor1.price = 400;
	storeItem_armor1.itemNum = 1;
	_storeItem.push_back(storeItem_armor1);

	ITEM storeItem_armor2;
	storeItem_armor2.division = ITEMDIVISION::STOREITEM;
	storeItem_armor2.kind = ITEMKIND::ARMOR;
	storeItem_armor2.role = ITEMROLE::WARRIOR;
	strncpy_s(storeItem_armor2.itemName, "플레이트 아머", 32);
	storeItem_armor2.req_level = 2;
	storeItem_armor2.req_pwr = 8;
	storeItem_armor2.req_dex = 3;
	storeItem_armor2.req_intel = 0;
	storeItem_armor2.point = 12;
	storeItem_armor2.pwrOption = 3;
	storeItem_armor2.dexOption = 1;
	storeItem_armor2.price = 3000;
	storeItem_armor2.itemNum = storeItem_armor1.itemNum + 1;
	_storeItem.push_back(storeItem_armor2);
}

void itemList::dropItemSetting(void)
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
