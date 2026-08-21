#pragma once

#include <string>

// 해시테이블.
class HashTable
{
private:
	// 키와 값, 그리고 다음 항목의 주소를 저장하는 클래스.
	struct Entry
	{
		Entry(const std::string& key, const std::string& value) 
			: key(key), value(value), next(nullptr)
		{
		};

		std::string key;
		std::string value;
		Entry* next = nullptr;
	};

public:
	// 생성자/소멸자.
	HashTable();
	~HashTable();

	// 복사/이동 생성자.


	// 복사/이동 대입연산자.


	// 데이터(키와 값) 추가 함수.
	bool Add(const std::string& key, const std::string& value);

	// 키로 검색해서 데이터를 제거하는 함수.
	bool Delete(const std::string& key);

	// 키를 활용해서 검색하는 함수.
	bool Find(const std::string& key, std::string & outValue) const;

	// 키가 저장되어 있는지 확인하는 함수.
	bool Contains(const std::string& key) const;

	// 모든 데이터 제거 함수.
	void Clear();

	// 저장된 데이터 출력 함수.
	void Print() const;

	// 비어 있는지 확인하는 함수.
	bool IsEmpty() const;

	// 저장된 데이터의 수 반환 함수.
	int Count() const;

private:
	// 키를 해시 값으로 변환해서 버킷 인덱스를 계산하는 함수.
	int GenerateBucketIndex(const std::string& key) const;

private:
	// 소수(Prime Number)로 하는 게 좋고,
	// 가능하면 큰 수를 하는게 좋음.
	static const int bucketCount = 19;

	// 각 버킷에 연결된 첫 번째 Entry 주소.
	Entry* table[bucketCount] = {};

	// 저장된 키와 값의 수.
	int count = 0;

};

