#include "HashTable.h"
#include <cstdint>
#include <iostream>

HashTable::HashTable()
{
}

HashTable::~HashTable()
{
}

bool HashTable::Add(const std::string& key, const std::string& value)
{
	// 버킷 인덱스 구하기.
	int bucketIndex = GenerateBucketIndex(key);

	// 데이터를 저장할 2차 자료구조.
	Entry* current = table[bucketIndex];

	// 중복된 키가 이미 존재하는지 확인.
	// 현재 해시테이블에서는 중복 키를 허용하지 않음.
	while (current != nullptr)
	{
		// 키 비교.
		if (current->key == key)
		{
			// 중복된 키가 있으면 데이터 추가 실패.
			return false;
		}

		// 다음 데이터 확인.
		current = current->next;
	}

	// 새로운 항목을 생성해서 연결 리스트 처음에 추가.
	// 처음에 추가하는 이유는 추가 연산이 빠르기 때문.
	Entry* newEntry = new Entry(key, value);
	newEntry->next = table[bucketIndex];

	// 첫 번째 데이터의 주소 업데이트.
	table[bucketIndex] = newEntry;

	// 저장 수 업데이트.
	++count;
	return true;
}

bool HashTable::Delete(const std::string& key)
{
	// 저장된 위치 확인(해시함수 활용).
	int bucketIndex = GenerateBucketIndex(key);

	Entry* current = table[bucketIndex];
	Entry* trail = nullptr;

	// 삭제할 키 검색.
	while (current)
	{
		if (current->key == key)
		{
			break;
		}

		trail = current;
		current = current->next;
	}

	// 삭제할 키를 찾지 못한 경우.
	if (!current)
	{
		// 삭제 실패.
		return false;
	}

	// #1. 첫 번째 항목(head)을 삭제하는 경우.
	// -> 그 다음 위치를 테이블의 첫 번째 주소로 업데이트.

	if (!trail /* || current == table[bucketIndex] */)
	{
		// 첫 번째 노드의 주소를 원래 노드의 다음 노드 주소로 설정.
		table[bucketIndex] = current->next;
	}

	// #2. 중간 항목을 삭제하는 경우.
	// -> 이전 노드와 그 다음 노드를 연결.

	else
	{
		trail->next = current->next;

	}

	// 삭제할 노드 제거 처리.
	delete current;
	current = nullptr;
	
	// 데이터 수 감소 처리.
	--count;
	return true;
}

bool HashTable::Find(const std::string& key, std::string& outValue) const
{
	// 버킷 인덱스 가져오기.
	int bucketIndex = GenerateBucketIndex(key);
	const Entry* current = table[bucketIndex];

	// 키 검색.
	while (current)
	{
		// 같은 키를 찾으면 출력 및 반환.
		if (current->key == key)
		{
			outValue = current->value;
			return true;
		}

		// 아직 못 찾았으면 다음 데이터 검색.
		current = current->next;
	}
	// 모두 찾았는데 키를 못 찾았으면 실패.
	return false;
}

bool HashTable::Contains(const std::string& key) const
{
	std::string value;
	return Find(key, value);
}

void HashTable::Clear()
{
	// 모든 버킷을 순회하면서 초기화 진행.
	for (int ix = 0; ix < bucketCount; ++ix)
	{
		// 제거할 버킷에 접근.
		Entry* current = table[ix];
	
		// 버킷을 순회하면서 제거 진행.
		while (current)
		{
			// 제거를 위해 임시 저장.
			Entry* deleteEntry = current;
			current = current->next;

			delete deleteEntry;
			deleteEntry = nullptr;
		}

		// 버킷 null로 초기화.
		table[ix] = nullptr;
	}

	// 저장된 데이터 수 초기화.
	count = 0;
}

void HashTable::Print() const
{
	// 버킷 순회.
	for (int ix = 0; ix < bucketCount; ++ix)
	{
		// 2차 자료구조인 버킷(링크드리스트)에 접근.
		const Entry* current = table[ix];

		// 연결 리스트에 저장된 데이터가 없으면 건너뛰기.
		if (!current)
		{
			continue;
		}
	
		// 버킷 인덱스 출력.
		std::cout << "[" << ix << "] ";

		// 연결 리스트 순회하면서 출력.
		while (current)
		{
			std::cout << "(" << current->key << "," << current->value << ")";

			// 출력 후 다음 인덱스로 넘어감.
			current = current->next;

			// 다음 인덱스가 있으면 -> 출력.
			if (current)
			{
				std::cout << " -> ";
			}
		}

		// 개행 출력.
		std::cout << "\n";
	}
}

bool HashTable::IsEmpty() const
{
	return count == 0;
}

int HashTable::Count() const
{
	return count;
}

int HashTable::GenerateBucketIndex(const std::string& key) const
{
	// 해시 값 저장 변수.
	uint32_t hashValue = 0;

	// 문자열의 각 문자를 활용해 해시 값 생성.
	for (char character : key)
	{
		hashValue = hashValue * 31 + static_cast<uint32_t>(character);
	}

	// 생성한 해시 값을 버킷 인덱스로 변환.
	return hashValue % bucketCount;
}
