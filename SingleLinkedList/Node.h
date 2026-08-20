#pragma once

// 전방 선언.
template<typename T>
class LinkedList;

// 연결 리스트에서 사용할 노드 클래스.

template<typename T>
class Node
{
	// 연결 리스트에서만 접근 가능하도록 friend 선언.
	friend class LinkedList<T>;

private:
	// 특정 클래스에서만 접근 가능하도록 생성자 접근 막음.
	Node(const T& data)
		: data(data), next(nullptr)
	{
	}

private:
	// 데이터 필드.
	T data;

	// 링크 필드(다음 노드를 가리키는 포인터).
	Node<T>* next = nullptr;

};