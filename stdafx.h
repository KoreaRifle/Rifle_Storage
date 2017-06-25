// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//
#include <vector>

#pragma once

struct _tagITEM
{
	int ti_division;
	int ti_kind;
	int ti_itemRole;
	int ti_itemNum;
	char ti_itemName[32];
	int ti_point;
	int ti_req_level;
	int ti_req_pwr;
	int ti_req_dex;
	int ti_req_intel;
	int ti_hpOption;
	int ti_mpOption;
	int ti_pwrOption;
	int ti_dexOption;
	int ti_intelOption;
	int ti_price;
};


// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
