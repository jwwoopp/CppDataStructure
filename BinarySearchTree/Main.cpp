#include "BinarySearchTree.h"
#include <iostream>

int main()
{
	// 데이터 집합.
	const int data[] = { 5, 1, 3, 2, 4, 7, 9, 6, 8, 10 };

	// 트리 생성 및 데이터 삽입.
	BinarySearchTree<int> tree;

	const int count = sizeof(data) / sizeof(data[0]);
	for (int ix = 0; ix < count; ++ix)
	{
		tree.Insert(data[ix]);
	}

	int minValue = 0;
	if (tree.Minimum(minValue))
	{
		std::cout << "트리의 최솟값: " << minValue << "\n";
	}

	int maxValue = 0;
	if (tree.Maximum(maxValue))
	{
		std::cout << "트리의 최댓값: " << maxValue << "\n";
	}

	// 검색.
	if (tree.Find(11))
	{
		std::cout << "11 검색 성공.\n";
	}
	else
	{
		std::cout << "11 검색 실패.\n";
	}

	// 순회.
	tree.InorderTraverse();

	// 삭제.
	if (tree.Remove(7))
	{
		std::cout << "7 제거 성공\n";
	}
	else
	{
		std::cout << "제거 실패.\n";
	}

	std::cout << "삭제 후 순회\n";
	tree.InorderTraverse();
}