#include "inventory.h"
#include "MainMenu.h"
#include "userStats.h"

inventory::inventory()
{
}


inventory::~inventory()
{
}

void inventory::charactorStatus(int roleNum, char name[32], int level, int max_hp, int add_max_hp, int hp, int max_mp, int add_max_mp, int mp, int pwr, int add_pwr, int mindmg, int dex, int add_dex, int intel, int add_intel, int exp, int totalExp, int money)
{
	//MainMenu *inven_mm;
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
	//inven_mm->charactorStatus(0, roleNum, name, level, max_hp, add_max_hp, hp, max_mp, add_max_mp, mp, pwr, add_pwr, mindmg, dex, add_dex, intel, add_intel, exp, totalExp, money);
}

void inventory::moneyInfo(int money)
{
	_money = money;
}

void inventory::itemInfoSave(ITEMDIVISION div, ITEMKIND kind, ITEMROLE role, char itemName[32], int point, int req_level, int req_pwr, int req_dex, int req_intel, int hpOption, int mpOption, int pwrOption, int dexOption, int intelOption, int price)
{
	if (_inventory.size() != 10) // 인벤토리에 최대 10개까지의 아이템 저장 가능
	{
		INVENTORY userInven;
		
		if (_inventory.size() == 0)
		{
			userInven.itemNum = _itemNum;
			_itemNum++;
		}
		else
		{
			_itemNum = _inventory.size() + 1;
			userInven.itemNum = _itemNum;
		}
		userInven.division = div;
		userInven.kind = kind;
		userInven.role = role;
		strncpy_s(userInven.itemName, itemName, 32);
		userInven.point = point;
		userInven.req_level = req_level;
		userInven.req_pwr = req_pwr;
		userInven.req_dex = req_dex;
		userInven.req_intel = req_intel;
		userInven.hpOption = hpOption;
		userInven.mpOption = mpOption;
		userInven.pwrOption = pwrOption;
		userInven.dexOption = dexOption;
		userInven.intelOption = intelOption;
		userInven.price = price;
		_inventory.push_back(userInven);
	}
	else // 인벤토리에 10개 이상의 아이템 저장 시 공간 부족 발생
	{
		cout << "가방 공간이 부족합니다." << endl;
		Sleep(1000);
	}
}

int inventory::inventoryView(void)
{
	bool exit = 0;
	int inventorySelectNum;
	int sellPrice = _money;
	while (exit != 1)
	{
		if (_inventory.size() == 0)
		{
			system("cls");
			cout << "인벤토리 내에 아이템이 존재하지 않습니다." << endl;
			Sleep(1000);
			break;
		}
		system("cls");
		cout << "========== 인벤토리 창 ==========" << endl;
		for (_vinven = _inventory.begin(); _vinven != _inventory.end(); ++_vinven)
		{
			if (_vinven->itemNum == 0) continue;
			cout << "[" << _vinven->itemNum << "] ";
			cout << _vinven->itemName;
			cout << endl;
		}
		cout << endl;
		cout << "========== 인벤토리 UI ==========" << endl;
		cout << "1.상세보기\t 2.아이템판매\t 3.되돌아가기" << endl;
		cin >> inventorySelectNum;
		switch (inventorySelectNum)
		{
			case 1:
				inventoryDetailView();
			break;
			case 2:
				sellPrice = inventoryItemSell();
			break;
			case 3:
				exit = 1;
			break;
			default:
				cout << "잘못된 번호를 입력하셨습니다. 다시 입력해주세요." << endl;
			break;
		}
	}
	return sellPrice;
}

void inventory::inventoryDetailView(void)
{
	bool exit = 0;
	int detailSelectView;
	for (_vinven = _inventory.begin(); _vinven != _inventory.end(); ++_vinven)
	{
		itemInit();
		if (_vinven->itemNum == 0) continue;
		cout << "[" << _vinven->itemNum << "] ";
		cout << _vinven->itemName << endl;
		if (_vinven->role == ITEMROLE::WARRIOR) cout << "[전사전용] ";
		else if (_vinven->role == ITEMROLE::WIZARD) cout << "[마법사전용] ";
		else if (_vinven->role == ITEMROLE::ELF) cout << "[엘프 전용] ";
		else if (_vinven->role == ITEMROLE::ALL) cout << "[모든직업] ";
		if (_vinven->kind == ITEMKIND::WEAPON) cout << "[무기] 공격력 : " << _vinven->point << "\t";
		else if (_vinven->kind == ITEMKIND::ARMOR) cout << "[방어구] 방어력 : " << _vinven->point << "\t";
		else if (_vinven->kind == ITEMKIND::ACC) cout << "[악세사리] 방어력 : " << _vinven->point << "\t";
		else if (_vinven->kind == ITEMKIND::POTION) cout << "[포션] 회복력 : " << _vinven->point << "\t";
	}
	while (exit != 1)
	{
		cout << endl;
		cout << "========== 아이템 상세보기 UI ==========" << endl;
		cout << "1.아이템 장착\t 2.되돌아가기" << endl;
		cin >> detailSelectView;
		switch (detailSelectView)
		{
			case 1:
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

int inventory::inventoryItemSell(void)
{
	bool exit = 0;
	int outputline = 1;
	int itemSellMenuSelect;
	int sellItemNum;
	int tempNum = 0;
	while (exit != 1)
	{
		for (_vinven = _inventory.begin(); _vinven != _inventory.end(); ++_vinven)
		{
			if (outputline < 4)
			{
				cout << "[" << _vinven->itemNum << "]" << _vinven->itemName << " ";
				outputline++;
			}
			else
			{
				cout << endl;
				cout << "[" << _vinven->itemNum << "]" << _vinven->itemName << " ";
				outputline = 1;
			}
			cout << endl;
		}
		cout << "========== 아이템 판매 ==========" << endl;
		cout << "1.아이템판매\t 2.되돌아가기" << endl;
		cin >> itemSellMenuSelect;
		switch (itemSellMenuSelect)
		{
			case 1:
				cout << "판매할 아이템 번호를 입력하세요." << endl;
				cin >> sellItemNum;
				if (sellItemNum <= _inventory.size() + 1)
				{
					for (_vinven = _inventory.begin(); _vinven != _inventory.end(); ++_vinven)
					{
						if (_vinven->itemNum == _inventory.at(sellItemNum - 1).itemNum)
						{
							cout << _vinven->itemNum << "번 " << _vinven->itemName << "이 선택되었습니다." << endl;
							// 아이템 판 가격(본래가격의 2분의 1 가격)만큼 최종소지금에서 증가
							_money = _money + (_vinven->price) / 2;
						}
						break;
					}
					_inventory.erase(_inventory.begin() + sellItemNum - 1);
					// 삭제된 데이터를 기준으로 itemNum 값 -1씩 해줌
					if (_inventory.size() == 0) _itemNum = 1; // 데이터 삭제 후 인벤토리 사이즈가 0일 경우
					if (_inventory.size() != sellItemNum - 1)
					{
						for (_vinven = _inventory.begin() + sellItemNum - 1; _vinven != _inventory.end(); ++_vinven)
						{
							_vinven->itemNum = _vinven->itemNum - 1;
						}
					}
					tempNum = 0;
				}
				else
				{
					cout << "아이템 번호가 존재하지 않습니다." << endl;
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
	return _money;
}

void inventory::itemInit(void)
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