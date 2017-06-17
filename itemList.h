#pragma once
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <vector>

using namespace std;

enum class ITEMDIVISION
{
	DROPITEM,
	STOREITEM,
	END
};

enum class ITEMKIND
{
	WEAPON,
	ARMOR,
	ACC,
	POTION,
	END
};

enum class ITEMROLE
{
	WARRIOR,
	WIZARD,
	ELF,
	ALL,
	END
};

enum class DROPDUNGEON
{
	DUNGEON1 = 1,
	DUNGEON2,
	DUNGEON3,
	DUNGEON4,
	END
};

enum class MONSTERNUM
{
	MONSTER = 1,
	BOSS = 4,
	END
};

struct ITEM
{
	ITEMDIVISION division;
	ITEMKIND kind;
	ITEMROLE role;
	DROPDUNGEON dropDungeon;
	MONSTERNUM monsterNum;
	int itemNum;
	char itemName[32];
	int point; // 공격 혹은 방어 점수
	int req_level; // 요구 레벨
	int req_pwr;
	int req_dex;
	int req_intel;
	int hpOption;
	int mpOption;
	int pwrOption;
	int dexOption;
	int intelOption;
	int price;
};

struct INVENTORY
{
	ITEMDIVISION division;
	ITEMKIND kind;
	ITEMROLE role;
	int itemNum;
	char itemName[32];
	int point;
	int req_level;
	int req_pwr;
	int req_dex;
	int req_intel;
	int hpOption;
	int mpOption;
	int pwrOption;
	int dexOption;
	int intelOption;
	int price;
};

class itemList
{
private:
	vector<ITEM> _storeItem;
	vector<ITEM>::iterator _vstoreItem;
	vector<ITEM> _dropItem;
	vector<ITEM>::iterator _vdropItem;
	vector<INVENTORY> _inventory;
	vector<INVENTORY>::iterator _vinven;
	int itemNum = 1;
	int _level;
	char _name[32];
	int _roleNum;
	char _roleName[32];
	int _max_hp;
	int _add_max_hp;
	int _hp;
	int _max_mp;
	int _add_max_mp;
	int _mp;
	int _pwr;
	int _add_pwr;
	int _mindmg;
	int _dex;
	int _add_dex;
	int _intel;
	int _add_intel;
	int _exp;
	int _totalExp;
	int _money;
public:
	void storeItemList(int kindNum);
	void dropItemList(int dungeonNum, int callNum);
	void purchaseMenu(int kindNum);
	void itemInit(int initNum);
	void charactorStatus(int roleNum, char name[32], int level, int max_hp, int add_max_hp, int hp, int max_mp, int add_max_mp, int mp, int pwr, int add_pwr, int mindmg, int dex, int add_dex, int intel, int add_intel, int exp, int totalExp, int money);
	void storeItemSetting(void);
	void dropItemSetting(void);
	void itemInfoSave(ITEMDIVISION div, ITEMKIND kind, ITEMROLE role, char itemName[32], int point, int req_level, int req_pwr, int req_dex, int req_intel, int hpOption, int mpOption, int pwrOption, int dexOption, int intelOption, int price);
	itemList();
	~itemList();
};

