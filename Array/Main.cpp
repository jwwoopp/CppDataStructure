#include <iostream>
#include <cstdint>
#include <cassert>
#include <vector>

// 배열 클래스.
template<typename T, size_t size>
class Array
{
public:

	// 배열 연산자 오버로딩.
	T& operator[](size_t index)
	{
		assert(index < size && "index should be less than size");
		return data[index];

	}

	const T& operator[](size_t index) const
	{
		assert(index < size && "index should be less than size");
		return data[index];
	}

	T* begin()
	{
		// 배열의 시작 주소 반환.
		return data;
	}

	T* end()
	{
		// 배열 마지막 인덱스의 다음 위치.
		return data + size;
	}

	T* Data() { return data; }
	const T* Data() const { return data; }
	size_t Length() const { return size; }

private:
	T data[size]{};
};

int main()
{
	// Array 객체 생성.
	Array<int, 5> intArray;
	std::fill(
		intArray.Data(),
		intArray.Data() + intArray.Length(),
		20
	);

	// 범위 기반 루프.
	for (const auto& value : intArray)
	{
		std::cout << value << "\n";
	}

	// intArray[0] = 10;
	// int intNumber = intArray[0];
	// const int& constNumber = intArray[0];

	// 정적 배열.
	const uint32_t size = 5;
	int array[size] = {};
	array[0] = 10;
	array[1] = 20;

	int number = array[0];

	// 동적 배열(힙에 해당되는 배열).
	uint32_t dSize = 10;
	int* dArray = new int[dSize] {};

	delete[] dArray;
	dArray = nullptr;

}