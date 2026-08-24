#pragma once

#include "Node.h"

template<typename T>
class BinaryTree
{
public:
	// 생성자 / 소멸자.
	BinaryTree(const T& data)
		: root(new Node<T>(data))
	{
	}

	~BinaryTree()
	{
		// 루트 노드 제거.
		// 루트 노드를 제거하면, 자손 노드들도 재귀적으로 제거.
		delete root;
		root = nullptr;
	}

	// 왼쪽 자손 추가 함수.
	bool AddLeftChild(const T& parentData, const T& childData)
	{
		// 검색 함수를 활용해 부모 노드 찾기.
		Node<T>* parent = Find(parentData);

		// 왼쪽 하위 노드에 추가 처리.
		return AddLeftChildToNode(parent, childData);
	}

	// 오른쪽 자손 추가 함수.
	bool AddRightChild(const T& parentData, const T& childData)
	{
		// 검색 함수를 활용해 부모 노드 찾기.
		Node<T>* parent = Find(parentData);

		// 오른쪽 하위 노드에 추가 처리.
		return AddRightChildToNode(parent, childData);
	}

	// 데이터를 기반으로 노드를 검색하는 함수.
	Node<T>* Find(const T& data)
	{
		// 검색 재귀 함수 호출.
		return FindRecursive(root, data);
	}

	// 노드 삭제 함수.
	bool Remove(const T& data)
	{
		// 삭제할 노드 검색.
		Node<T>* target = Find(data);

		// 못 찾았으면 삭제 실패.
		if (!target)
		{
			return false;
		}

		// 루트 노드는 제거 안함.
		if (target == root)
		{
			return false;
		}

		// 제거 처리.

		// 부모의 자손 정보 정리.
		Node<T>* parent = target->parent;

		// 삭제하려는 노드가 부모 기준 왼쪽 자손인 경우.
		if (parent->left == target)
		{
			parent->left = nullptr;
		}
		// 삭제하려는 노드가 부모 기준 오른쪽 자손인 경우.
		else if (parent->right == target)
		{
			parent->right = nullptr;
		}
		else
		{
			return false;
		}

		// 노드 제거 처리.
		delete target;
		target = nullptr;

		return true;
	}

private:
	// 특정 노드의 왼쪽 자손 노드 추가 함수.
	bool AddLeftChildToNode(Node<T>* parent, const T& childData)
	{
		// 전달 받은 부모 노드가 null이면 자손 추가 실패.
		if (!parent)
		{
			return false;
		}

		// 선택 사항: 이미 왼쪽 자손이 있으면 추가 실패.
		// 이미 왼쪽 자손이 있는 경우에 데이터를 갱신하는 것으로 구현도 가능.
		if (parent->left)
		{
			return false;
		}

		// 노드 생성 후 부모/자손 관계 설정.
		Node<T>* child = new Node<T>(childData);
		child->parent = parent;
		parent->left = child;

		return true;
	}

	// 특정 노드의 오른쪽 자손 노드 추가 함수.
	bool AddRightChildToNode(Node<T>* parent, const T& childData)
	{
		// 전달 받은 부모 노드가 null이면 자손 추가 실패.
		if (!parent)
		{
			return false;
		}

		// 선택 사항: 이미 오른쪽 자손이 있으면 추가 실패.
		// 이미 오른쪽 자손이 있는 경우에 데이터를 갱신하는 것으로 구현도 가능.
		if (parent->right)
		{
			return false;
		}

		// 노드 생성 후 부모/자손 관계 설정.
		Node<T>* child = new Node<T>(childData);
		child->parent = parent;
		parent->right = child;

		return true;
	}

	// 검색 재귀 함수.
	Node<T>* FindRecursive(Node<T>* node, const T& data)
	{
		// 종료 조건.
		if (!node)
		{
			return nullptr;
		}

		// 현재 노드를 검사.
		if (node->data == data)
		{
			return node;
		}

		// 왼쪽 서브 트리 검색.
		Node<T>* result = FindRecursive(node->left, data);

		// 검색 결과 확인.
		if (result)
		{
			return result;
		}

		// 오른쪽 서브 트리 검색.
		return FindRecursive(node->right, data);
	}

private:
	// 루트 노드.
	Node<T>* root = nullptr;
};