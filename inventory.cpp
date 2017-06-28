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

void inventory::moneyInfo(int money)
{
	_money = money;
}

int inventory::itemInfoSave(vector<_tagITEM> _ITEM)
{
	if (_inventory.size() != _maxInventorySize) // 인벤토리에 최대 10개까지의 아이템 저장 가능
	{
		INVENTORY userInven;

		for (_vITEM = _ITEM.begin(); _vITEM != _ITEM.end(); ++_vITEM)
		{
			userInven.division = ITEMDIVISION(_vITEM->ti_division);
			userInven.kind = ITEMKIND(_vITEM->ti_kind);
			userInven.role = ITEMROLE(_vITEM->ti_itemRole);
			strncpy_s(userInven.itemName, _vITEM->ti_itemName, 32);
			userInven.point = _vITEM->ti_point;
			userInven.req_level = _vITEM->ti_req_level;
			userInven.req_pwr = _vITEM->ti_req_pwr;
			userInven.req_dex = _vITEM->ti_req_dex;
			userInven.req_intel = _vITEM->ti_req_intel;
			userInven.hpOption = _vITEM->ti_hpOption;
			userInven.mpOption = _vITEM->ti_mpOption;
			userInven.pwrOption = _vITEM->ti_pwrOption;
			userInven.dexOption = _vITEM->ti_dexOption;
			userInven.intelOption = _vITEM->ti_intelOption;
			userInven.price = _vITEM->ti_price;
			userInven.itemNum = _inventory.size() + 1;
			_inventory.push_back(userInven);
		}
	}
	else // 인벤토리에 10개 이상의 아이템 저장 시 공간 부족 발생
	{
		cout << "가방 공간이 부족합니다." << endl;
		Sleep(1000);
	}
	return _inventory.size();
}

int inventory::itemInfoSave(vector<INVENTORY> _INVEN)
{
	if (_inventory.size() != _maxInventorySize) // 인벤토리에 최대 10개까지의 아이템 저장 가능
	{
		INVENTORY userInven;

		for (_vinven = _INVEN.begin(); _vinven != _INVEN.end(); ++_vinven)
		{
			userInven.division = ITEMDIVISION(_vinven->division);
			userInven.kind = ITEMKIND(_vinven->kind);
			userInven.role = ITEMROLE(_vinven->role);
			strncpy_s(userInven.itemName, _vinven->itemName, 32);
			userInven.point = _vinven->point;
			userInven.req_level = _vinven->req_level;
			userInven.req_pwr = _vinven->req_pwr;
			userInven.req_dex = _vinven->req_dex;
			userInven.req_intel = _vinven->req_intel;
			userInven.hpOption = _vinven->hpOption;
			userInven.mpOption = _vinven->mpOption;
			userInven.pwrOption = _vinven->pwrOption;
			userInven.dexOption = _vinven->dexOption;
			userInven.intelOption = _vinven->intelOption;
			userInven.price = _vinven->price;
			userInven.itemNum = _inventory.size() + 1;
			_inventory.push_back(userInven);
		}
	}
	else // 인벤토리에 10개 이상의 아이템 저장 시 공간 부족 발생
	{
		cout << "가방 공간이 부족합니다." << endl;
		Sleep(1000);
	}
	return _inventory.size();
}

int inventory::maxInventorySizeReturn(void)
{
	return _maxInventorySize;
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
		cout << "인벤토리 용량 (" << _inventory.size() << " / " << _maxInventorySize << ")" << endl;
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
		int equipItemNumber; // 아이템 장착할 번호 입력 변수
		cout << endl;
		cout << "========== 아이템 상세보기 UI ==========" << endl;
		cout << "1.아이템 장착\t 2.되돌아가기" << endl;
		cin >> detailSelectView;
		switch (detailSelectView)
		{
			case 1:
				cout << "장착할 아이템 번호를 입력하세요." << endl;
				cin >> equipItemNumber;
				itemEquip(1, equipItemNumber);
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
	int itemSellMenuSelect;
	int sellItemNum;
	int tempNum = 0;
	while (exit != 1)
	{
		for (_vinven = _inventory.begin(); _vinven != _inventory.end(); ++_vinven)
		{
			cout << "[" << _vinven->itemNum << "]" << _vinven->itemName << " " << endl;
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

void inventory::itemEquip(int equipNumber, int equipItemNumber)
{
	// equipNumber : 아이템 장착 부위 결정 변수
	// 1:좌측무기 2:우측무기 3:머리 4:갑옷 5:좌측팔 6:우측팔 7:신발 8:목걸이 9:좌측반지 10:우측반지
	// equipItemNumber : 인벤토리에서의 itemNum
	INVENTORY left_weaponInfo;
	switch (equipNumber)
	{
		case 1:
			if (left_weaponEquip == false) // 미장착 상태
			{
				left_weaponEquip = true;
				for (_vinven = _inventory.begin(); _vinven != _inventory.end(); ++_vinven)
				{
					if (_vinven->itemNum != equipItemNumber) continue;
					///////////////////////////////////////////////////////////////
					// 정보 더 추가시켜야함!!!
					strncpy_s(left_weaponInfo.itemName, _vinven->itemName, 32);
					left_weaponInfo.point = _vinven->point;
					left_weaponInfo.equipPart = 1; // 해당 무기 파츠번호 1번으로 조정
					cout << "저장된 아이템명 : " << left_weaponInfo.itemName << endl;
					vector_left_weaponEquip.push_back(left_weaponInfo);
					for (_vinven = _inventory.begin(); _vinven != _inventory.end(); ++_vinven)
					{
						if (_vinven->itemNum == _inventory.at(equipItemNumber - 1).itemNum)
						{
							cout << _vinven->itemNum << "번 " << _vinven->itemName << "이 선택되었습니다." << endl;
							break;
						}
					}
					_inventory.erase(_inventory.begin() + equipItemNumber - 1);
					// 삭제된 데이터를 기준으로 itemNum 값 -1씩 해줌
					if (_inventory.size() == 0) _itemNum = 1; // 데이터 삭제 후 인벤토리 사이즈가 0일 경우
					if (_inventory.size() > 0)
					{
						for (_vinven = _inventory.begin() + equipItemNumber - 1; _vinven != _inventory.end(); ++_vinven)
						{
							// 인벤토리 숫자 조정
							_vinven->itemNum = _vinven->itemNum - 1;
						}
						break;
					}
				}
			}
			else // 아이템 장착 상태
			{
				int changeEquipNumber;
				int exit = 0;
				for (_vinven = vector_left_weaponEquip.begin(); _vinven != vector_left_weaponEquip.end(); ++_vinven) cout << "현재 " << _vinven->itemName << "을 장착하고 있습니다." << endl;
				for (_vinven = _inventory.begin(); _vinven != _inventory.end(); ++_vinven)
				{
					if (_vinven->itemNum != equipItemNumber) continue;
					cout << _vinven->itemName << "으로 장착하시겠습니까? (1:예, 2:아니오)" << endl;
				}
				cin >> changeEquipNumber;
				while (true)
				{
					switch (changeEquipNumber)
					{
						case 1:
							// 이전 장착 장비는 삭제되고(인벤토리에 다시 추가됨), 해당 아이템이 장착됨
							itemInfoSave(vector_left_weaponEquip); // 인벤토리에 이전 장착 장비 저장
							vector_left_weaponEquip.erase(vector_left_weaponEquip.begin(), vector_left_weaponEquip.end()); // 이전 장착 아이템을 장착 벡터에서 삭제
							for (_vinven = _inventory.begin(); _vinven != _inventory.end(); ++_vinven)
							{
								if (_vinven->itemNum != equipItemNumber) continue;
								strncpy_s(left_weaponInfo.itemName, _vinven->itemName, 32);
								vector_left_weaponEquip.push_back(left_weaponInfo);
							}
							for (_vinven = vector_left_weaponEquip.begin(); _vinven != vector_left_weaponEquip.end(); ++_vinven) cout << _vinven->itemName << "을(를) 장착했습니다." << endl;
							// 장착한 아이템 인벤토리 리스트에서 삭제 수행
							_inventory.erase(_inventory.begin() + equipItemNumber - 1);
							// 삭제된 데이터를 기준으로 itemNum 값 -1씩 해줌
							if (_inventory.size() == 0) _itemNum = 1; // 데이터 삭제 후 인벤토리 사이즈가 0일 경우
							if (_inventory.size() > 0)
							{
								for (_vinven = _inventory.begin() + equipItemNumber - 1; _vinven != _inventory.end(); ++_vinven)
								{
									// 인벤토리 숫자 조정
									_vinven->itemNum = _vinven->itemNum - 1;
								}
								break;
							}
							Sleep(1000);
						break;
						default:
							cout << "잘못된 번호를 입력하셨습니다. 다시 입력해주세요." << endl;
						continue;
					}
					break;
				}
			}
		break;
		case 2:
		break;
	}
}