#include "Tree.h"
#include "Node.h"
#include <iostream>
#include <string>

int main() 
{
	// 트리 생성.
	Tree<std::string> tree("A");

	// 자손 노드 추가.
	tree.AddChild("A", "B");
	tree.AddChild("A", "C");
	tree.AddChild("A", "D");

	tree.AddChild("B", "E");
	tree.AddChild("B", "F");
	tree.AddChild("B", "G");

	tree.AddChild("C", "H");
	
	tree.AddChild("D", "I");
	tree.AddChild("D", "J");

	// 탐색(검색).
	Node<std::string>* result = tree.Find("J");
	if (result)
	{
		std::cout << "검색한 값: " << result->GetData() << "\n";

		// 부모가 있는 경우 정보 출력.
		if (result->GetParent())
		{
			std::cout << "부모 노드: " << result->GetParent()->GetData() << "\n";
		}
		else
		{
			std::cout << "검색 실패\n";
		}
	}

	// 삭제 전 순회.
	std::cout << "삭제 전 전위 순회\n";
	tree.PreorderTraverse();
	std::cout << "삭제 전 후위 순회\n";
	tree.PostorderTraverse();

	// 삭제 처리.
	if (tree.Remove("C"))
	{
		std::cout << "삭제 성공\n";
	}
	else
	{
		std::cout << "삭제 실패\n";
	}

	std::cout << "삭제 후 순회\n";
	tree.PreorderTraverse();
}