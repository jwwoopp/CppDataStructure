#pragma once

#include "Node.h"
#include <algorithm>
#include <iostream>

// 트리 클래스 템플릿.
template<typename T>
class Tree
{
public:
	Tree(const T& data)
		: root(new Node<T>(data))
	{
	}
	~Tree()
	{
		// 루트 노드 제거(자손 노드는 Node 소멸자에서 재귀적으로 제거).
		delete root;
		root = nullptr;
	}

	// 부모를 지정해서 자손 노드를 추가하는 함수.
	bool AddChild(const T& parentData, const T& childData)
	{
		// 부모 노드 검색.
		Node<T>* parent = Find(parentData);

		// 확인.
		if (!parent)
		{
			return false;
		}

		// 자손 노드 추가 처리.
		AddChildToNode(parent, childData);
		return true;
	}
	// 노드 탐색 함수.
	Node<T>* Find(const T& data)
	{
		// 재귀적으로 탐색.
		return FindRecursive(root, data);
	}

	// 노드와 모든 자손을 삭제하는 함수.
	bool Remove(const T& data)
	{
		// 삭제하려는 데이터를 가지는 노드 검색.
		Node<T>* target = Find(data);

		// 삭제하려는 노드가 없으면 삭제 실패.
		if (!target)
		{
			return false;
		}

		// 루트 노드인 경우 제거 안함.
		if (target == root)
		{
			return false;
		}

		// 삭제 처리.
		Node<T>* parent = target->parent;
		std::vector<Node<T>*>& children = parent->children;

		// 삭제를 원하는 자손 노드 검색.
		// std::find는 실패했을 때 vector의 end() 이터레이터를 반환.
		auto result = std::find(children.begin(), children.end(), target);

		// 검색 결과 확인(성공 여부 확인).
		if (result == children.end())
		{
			return false;
		}

		// 부모의 자손 목록에서 제거.
		children.erase(result);

		// 자손 노드 제거 처리.
		delete target;
		target = nullptr;
		return true;
	}

	// 전위 순회(Preorrder).
	void PreorderTraverse() const
	{
		// 재귀적으로 하위 노드 방문.
		PreorderRecursive(root, 0);
	}

	// 후위 순회(Postorrder).
	void PostorderTraverse() const
	{
		// 재귀적으로 하위 노드 방문.
		PostorderRecursive(root, 0);
	}

private:

	// 전위 순회 재귀 함수.
	void PreorderRecursive(const Node<T>* node, int depth) const
	{
		// 종료 조건.
		if (!node)
		{
			return;
		}

		// 부모(현재) 노드를 먼저 처리.
		// 깊이를 보여주기 위해 빈칸 출력.
		for (int ix = 0; ix < depth; ++ix)
		{
			std::cout << "  ";
		}

		std::cout << node->data << "\n";

		// 순서대로 자손 노드 방문 처리.
		const int count = static_cast<int>(node->children.size());
		for (int ix = 0; ix < count; ++ix)
		{
			PreorderRecursive(node->children[ix], depth + 1);
		}

	};

	// 후위 순회 재귀 함수.
	void PostorderRecursive(const Node<T>* node, int depth) const
	{
		// 종료 조건.
		if (!node)
		{
			return;
		}

		// 순서대로 자손 노드 방문 처리.
		const int count = static_cast<int>(node->children.size());
		for (int ix = 0; ix < count; ++ix)
		{
			PostorderRecursive(node->children[ix], depth + 1);
		}

		// 자손을 모두 방문한 뒤에 부모(현재) 노드를 처리.
		// 깊이를 보여주기 위해 빈칸 출력.
		for (int ix = 0; ix < depth; ++ix)
		{
			std::cout << "  ";
		}

		std::cout << node->data << "\n";
	};

	// 재귀적으로 탐색하는 함수.
	// #1. 종료 조건을 잘 설정.
	// #2. 재귀 함수를 호출하면서 데이터 범위가 변경되어야 함.
	Node<T>* FindRecursive(Node<T>* node, const T& data)
	{
		if (!node)
		{
			return nullptr;
		}

		// 현재 노드의 데이터 확인.
		if (node->data == data)
		{
			// 탐색 성공.
			return node;
		}

		// 자손 노드를 순회하며 재귀적으로 탐색.
		const int count = node->GetChildrenCount();
		for (int ix = 0; ix < count; ++ix)
		{
			Node<T>* found = FindRecursive(node->GetChild(ix), data);

			// 검색 결과 확인.
			if (found)
			{
				return found;
			}
		}

		// 검색 실패.
		return nullptr;
	}

	// 자손 노드 추가 처리 함수.
	void AddChildToNode(Node<T>* parent, const T& childData)
	{
		// 자손 노드 생성.
		Node<T>* child = new Node<T>(childData);

		// 부모-자손 관계 설정.
		child->parent = parent;
		parent->children.emplace_back(child);
	}

private:
	// 루트 노드.
	Node<T>* root = nullptr;
};
