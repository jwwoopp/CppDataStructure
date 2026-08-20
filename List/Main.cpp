#include <iostream>
#include "List.h"
#include <string>

int main()
{
	// 캐릭터 리스트.
	List<std::string> characterList;
	characterList.PushBack("Warrior");
	characterList.PushBack("Knight");
	characterList.PushBack("Archer");

	// 복사 생성.
	List<std::string> copiedList(characterList);
	copiedList[0] = "BlackKnight";

	// 이동 생성.
	List<std::string> copiedList2(std::move(copiedList));

	// 범위-기반 루프로 출력.
	for (const auto& value : characterList)
	{
		std::cout << value << "\n";
	}
}