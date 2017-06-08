#pragma once
#include <iostream>
#include<time.h>
#include<Windows.h>

using namespace std;

class userStats
{
private:
	char _name[32];
	int _roleNum;
	char _roleName[32];
	int _hp;
	int _mp;
	int _pwr;
	int _dex;
	int _intel;
public:
	void charactorStatus(int roleNum, char name[32], int hp, int mp, int pwr, int dex, int intel);
	void testViewChar(void);
	userStats();
	~userStats();
};

