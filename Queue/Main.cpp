#include "Queue.h"
#include <iostream>
#include <queue>

int main()
{
	std::queue<int> testQueue;
	// testQueue.push();
	// testQueue.emplace();
	// int retValue = testQueue.front();
	// testQueue.pop();

	// 큐의 크기.
	const int count = 5;

	// 큐 객체 생성.
	Queue<int, count> queue;

	// 큐에 데이터 추가.
	for (int ix = 0; ix < count + 1; ++ix)
	{
		if (!queue.Enqueue(ix + 1))
		{
			std::cout << "큐에 저장 실패\n";
		}
	}

	// 큐에 저장된 데이터 출력.
	queue.Print();

	// 맨 앞에 데이터 읽기.
	int firstValue = 0;
	if (queue.Front(firstValue))
	{
		std::cout << "첫 번째 데이터: " << firstValue <<  "\n";
	}

	// 데이터 출력.
	int outValue = 0;
	if (queue.Dequeue(outValue))
	{
		std::cout << "출력된 데이터: " << outValue << "\n";
	}

	queue.Print();

}

