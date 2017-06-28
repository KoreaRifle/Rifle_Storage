#include "itemList.h"
#include "MainMenu.h"

MainMenu il_mm;

itemList::itemList()
{
	storeItemSetting();
}

itemList::~itemList()
{
}

int itemList::storeItemList(int kindNum, int inventorySize, int maxInventorySize)
{
	system("cls");
	_inventorySize = inventorySize;
	_maxInventorySize = maxInventorySize;
	// 1:무기, 2:방어구, 3:악세사리, 4:포션 5:가방
	switch (kindNum)
	{
		case 1:
			for (_vstoreItem = _storeItem.begin(); _vstoreItem != _storeItem.end(); ++_vstoreItem)
			{
				itemInit();
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
				itemInit();
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
	return _money;
}

vector<_tagITEM> itemList::itemInfoReturn(void)
{
	return _storeItemTemp;
}

void itemList::eraseItemInfo(void)
{
	if (_storeItemTemp.size() > 0) _storeItemTemp.erase(_storeItemTemp.begin(), _storeItemTemp.end());
}

void itemList::purchaseMenu(int kindNum)
{
	//if (_storeItemTemp.size() > 0) _storeItemTemp.erase(_storeItemTemp.begin(), _storeItemTemp.end());
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
										cout << "미구현 상태" << endl;
										exit = 1;
									break;
									case 2:
										exit = 1;
									break;
									default:
										cout << "잘못된 번호를 입력하셨습니다. 다시 입력해주세요." << endl;
										system("cls");
									continue;
								}
								break;
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
				exit = 1;
			break;
			default:
				cout << "잘못된 번호를 입력하셨습니다. 다시 입력해주세요." << endl;
			continue;
		}
	}
}

void itemList::moneyInfo(int money)
{
	_money = money;
}

void itemList::itemInit(void)
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

	if (_storeItemTemp.size() < (_maxInventorySize - _inventorySize))
	{
		_tagITEM storeItem;
		storeItem.ti_division = (int)div;
		storeItem.ti_kind = (int)kind;
		storeItem.ti_itemRole = (int)role;
		strncpy_s(storeItem.ti_itemName, itemName, 32);
		storeItem.ti_point = point;
		storeItem.ti_req_level = req_level;
		storeItem.ti_req_pwr = req_pwr;
		storeItem.ti_req_dex = req_dex;
		storeItem.ti_req_intel = req_intel;
		storeItem.ti_hpOption = hpOption;
		storeItem.ti_mpOption = mpOption;
		storeItem.ti_pwrOption = pwrOption;
		storeItem.ti_dexOption = dexOption;
		storeItem.ti_intelOption = intelOption;
		storeItem.ti_price = price;
		_storeItemTemp.push_back(storeItem);
	}
	else cout << "인벤토리가 가득 찼습니다." << endl;
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