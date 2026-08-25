#pragma once

#include "Node.h"
#include <iostream>

// 이진 탐색 트리 클래스.
template<typename T>
class BinarySearchTree
{
public:
	BinarySearchTree()
	{
	}

	~BinarySearchTree()
	{
		// 루트 노드를 삭제하면, 재귀적으로 하위 노드도 제거.
		//SafeDelete(root);
		delete root;
		root = nullptr;
	}

	// 트리가 비었는지 확인하는 함수.
	bool IsEmpty() const { return root == nullptr; }

	// 노드 추가 함수.
	// 중복 허용 하지 않음.
	// 루트가 비어 있으면 루트에 추가.
	// 작으면 왼쪽 하위 노드에 추가.
	// 크면 오른쪽 하위 노드에 추가.
	bool Insert(const T& data)
	{
		// 루트가 비었으면 루트에 추가.
		if (!root)
		{
			root = new Node<T>(data);
			return true;
		}

		// 삽입할 노드의 위치 검색을 위해 루트부터 시작.
		Node<T>* current = root;

		while (true)
		{
			// 추가하려는 데이터가 현재 노드보다 작은 경우.
			if (data < current->data)
			{
				// 왼쪽 하위 트리에 추가.
				// 왼쪽 자손 노드가 비었으면 이 위치에 추가.
				if (!current->left)
				{
					current->left = new Node<T>(data);
					return true;
				}

				// 비어있지 않으면 하위 트리로 계속 진행.
				current = current->left;
			}

			// 추가하려는 데이터가 현재 노드보다 큰 경우.
			else if (current->data < data)
			{
				// 오른쪽 하위 트리에 추가.
				// 오른쪽 자손 노드가 비었으면 이 위치에 추가.
				if (!current->right)
				{
					current->right = new Node<T>(data);
					return true;
				}

				// 비어있지 않으면 하위 트리로 계속 진행.
				current = current->right;
			}
			// 같은 경우라면 중복을 허용하지 않기 때문에 삽입 실패.
			else
			{
				return false;
			}
		}
	}

	// 최솟값 반환 함수.
	bool Minimum(T& outValue) const
	{
		// 트리가 비었으면 값 얻기 실패.
		if (!root)
		{
			return false;
		}

		// 최솟값을 갖는 노드 검색.
		outValue = FindMinimum(root)->data;
		return true;
	}

	// 최댓값 반환 함수.
	bool Maximum(T& outValue) const
	{
		// 트리가 비었으면 검색 실패.
		if (!root)
		{
			return false;
		}

		// 루트부터 검색 시작.
		const Node<T>* current = root;

		// 가장 오른쪽 끝까지 이동.
		while (current->right)
		{
			current = current->right;
		}

		// 가장 오른쪽 끝에 위치한 노드 값 반환.
		outValue = current->data;
		return true;
	}

	// 검색 함수.
	bool Find(const T& data) const
	{
		// 루트 노드부터 검색 시작.
		const Node<T>* current = root;

		while (current)
		{
			// 현재 노드의 데이터가 검색하려는 데이터보다 작으면,
			// 오른쪽 하위 트리로 검색 이어감.
			if (current->data < data)
			{
				current = current->right;
			}

			// 현재 노드의 데이터가 검색 데이터보다 크면,
			// 왼쪽 하위 트리로 검색 이어감.
			else if (data < current->data)
			{
				current = current->left;
			}

			// 검색 성공.
			else
			{
				return true;
			}
		}

		// 노드를 모두 찾아봤는데 여기까지 왔으면 검색 실패.
		return false;
	}

private:
	// 최솟값 노드 검색 함수.
	Node<T>* FindMinimum(Node<T>* node) const
	{
		Node<T>* current = node;

		while (current->left)
		{
			current = current->left;
		}

		return current;
	}

private:
	// 루트 노드.
	Node<T>* root = nullptr;
};