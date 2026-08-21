#pragma once

#include <iostream>

// 덱 클래스 템플릿.
template<typename T, int capacity = 50>
class Deque
{
public:

	// 초기화 함수.
	void Clear()
	{
		front = 0;
		rear = 0;
	}

	// 덱의 뒤에 데이터 추가(큐의 Enqueue와 동일).
	bool AddRear(const T& value)
	{
		// 가득찼으면 실패.
		if (IsFull())
		{
			return false;
		}

		// rear를 다음 위치로 옮기고 데이터 추가.
		rear = (rear + 1) % bufferSize;
		data[rear] = value;

		// 성공 반환.
		return true;
	}

	// 덱의 앞에서 데이터 추가(큐에는 없던 동작).
	bool AddFront(const T& value)
	{
		// 가득찼으면 실패.
		if (IsFull())
		{
			return false;
		}

		// front는 가장 앞의 데이터의 이전 위치를 가리킴.
		// 데이터 저장 후 front 업데이트.
		data[front] = value;
		front = (front - 1 + bufferSize) % bufferSize;

		return true;
	}

	// 덱의 앞에서 데이터 제거하는 함수(큐의 Dequeue).
	bool DeleteFront(T& outValue)
	{
		// 비었으면 실패.
		if (IsEmpty())
		{
			return false;
		}

		// front를 업데이트 한 후에 데이터 출력.
		front = (front + 1) % bufferSize;

		outValue = data[front];
		data[front] = T();

		return true;
	}

	// 덱의 뒤에서 데이터 제거하는 함수(원래는 없는 동작).
	bool DeleteRear(T& outValue)
	{
		// 비었으면 실패.
		if (IsEmpty())
		{
			return false;
		}

		// 데이터를 출력한 뒤에 rear 업데이트.
		outValue = data[rear];
		data[rear] = T();

		rear = (rear - 1 + bufferSize) % bufferSize;

		return true;
	}

	// 앞쪽 데이터를 제거하지 않고 반환하는 함수(큐의 GetFront와 동일).
	bool GetFront(T& outValue) const
	{
		// 비었으면 실패.
		if (IsEmpty())
		{
			return false;
		}

		// 출력에 필요한 인덱스 계산.
		int firstIndex = (front + 1) % bufferSize;
		outValue = data[firstIndex];

		return true;
	}

	// 뒤쪽 데이터를 제거하지 않고 반환하는 함수(큐에 없는 동작).
	bool GetRear(T& outValue) const
	{
		// 비었으면 실패.
		if (IsEmpty())
		{
			return false;
		}

		// rear는 마지막 데이터의 위치를 가리키기 때문에 바로 출력.
		outValue = data[rear];
		return true;
	}

	// 앞부터 뒤까지 모든 데이터를 출력하는 함수.
	void Print() const
	{
		std::cout << "덱 내용:";

		// 첫 번째 인덱스.
		int index = (front + 1) % bufferSize;

		// 마지막 인덱스(유효한 데이터 다음 위치).
		int endIndex = (rear + 1) % bufferSize;

		while (index != endIndex)
		{
			std::cout << " " << data[index];
			// 인덱스 업데이트.
			index = (index + 1) % bufferSize;
		}

		// 개행 출력.
		std::cout << "\n";
	}

	// 비었는지 확인하는 함수.
	bool IsEmpty() const { return front == rear; }

	// 가득찼는지 확인하는 함수.
	bool IsFull() const { return (rear + 1) % bufferSize == front; }

	// 저장 용량 반환 함수.
	int Capacity() const { return capacity; }

	// 저장된 데이터 수 반환 함수.
	int Count() const
	{
		return (rear - front + bufferSize) % bufferSize;
	}

private:
	// 덱 버퍼 크기.
	static constexpr int bufferSize = capacity + 1;

	// 첫 번째 데이터 바로 이전 위치.
	int front = 0;

	// 마지막 데이터가 저장된 위치.
	int rear = 0;

	// 데이터 배열.
	T data[bufferSize] = {};
};