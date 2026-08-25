#pragma once

// 노드 삭제 함수.
template<typename T>
void SafeDelete(T*& t)
{
	if (t)
	{
		delete t;
		t = nullptr;
	}
}

// 이진 탐색 트리 클래스 전방 선언.
template<typename T>
class BinarySearchTree;

// 이진 탐색 트리의 노드 클래스.
template<typename T>
class Node
{
	// 이진 탐색 트리 클래스 friend 선언.
	friend class BinarySearchTree<T>;

public:
	// Getter.
	const T& GetData() const { return data; }

private:
	Node(const T& data)
		: data(data)
	{
	}

	~Node()
	{
		delete left;
		left = nullptr;

		delete right;
		right = nullptr;
		//SafeDelete(left);
		//SafeDelete(right);
	}

	// 복사 방지.
	Node(const Node& other) = delete;
	Node& operator=(const Node& other) = delete;

private:
	// 데이터 필드.
	T data;

	// 자손 노드.
	Node<T>* left = nullptr;
	Node<T>* right = nullptr;
};