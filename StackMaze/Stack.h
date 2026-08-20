#pragma once

// 스택 클래스 템플릿.
// 고정 크기 스택.
template<typename T>
class Stack
{
public:
	Stack()
		: count(0)
	{
	}

	// 스택 비우는 함수.
	void Clear()
	{
		count = 0;
	}

	// 스택 가장 위에 데이터 추가하는 함수.
	bool Push(const T& value)
	{
		// 가득찼으면 추가 실패.
		if (IsFull())
		{
			return false;
		}

		// 데이터 추가 처리.
		data[count] = value;
		++count;

		// 성공.
		return true;
	}

	// 스택 가장 위에 있는 데이터를 제거하는 함수.
	// 제거하면서 값도 함께 출력.
	bool Pop(T& outValue)
	{
		// 스택이 비었으면 실패.
		if (IsEmpty())
		{
			return false;
		}

		// 값 반환 및 제거 처리.
		--count;
		outValue = data[count];

		// 성공

		return true;
	}

	// 스택에 가장 위에 있는 데이터만 반환하는 함수.
	// 데이터 제거는 안함.
	bool Top(T& outValue) const
	{
		// 스택이 비었으면 실패.
		if (IsEmpty())
		{
			return false;
		}

		// 데이터 반환.
		outValue = data[count - 1];

		// 성공.
		return true;
	}

	// 저장된 데이터 수 반환 함수.
	int Count() const { return count; }

	// 스택이 비었는지 확인하는 함수.
	bool IsEmpty() const { return count == 0; }

	// 스택이 가득찼는지 확인하는 함수.
	bool IsFull() const { return count == maxCount; }

private:
	// 스택 크기.
	static const int maxCount = 100;

	// 스택 데이터를 저장할 정적 배열.
	T data[maxCount] = {};

	// 스택에 저장된 요소 수.
	int count = 0;
};
