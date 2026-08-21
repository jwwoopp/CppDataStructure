#include "HashTable.h"
#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	HashTable table;

	// 키-값 데이터 추가.
	table.Add("Monapark", "010-0000-0000");

	// 중복 키 추가 확인.
	if (table.Add("Monapark", "010-3333-3333"))
	{
		std::cout << "이미 같은 키가 저장돼 있음.\n";
	}

	table.Add("Yoon", "010-0000-0000");
	table.Add("Baker", "010-0000-0000");
	table.Add("Kevin", "010-0000-0000");

	// 출력.
	std::cout << "\n전체 데이터\n";
	table.Print();

	// 검색.
	std::string number;
	if (table.Find("Monapark", number))
	{
		std::cout << "\n 검색 결과 : Monapark, " << number << "\n";
	}

	// 삭제.
	if (table.Delete("Baker"))
	{
		std::cout << "Baker 항목 삭제";
	}

	// 출력
	std::cout << "\n삭제 후 데이터\n";
	table.Print();

}