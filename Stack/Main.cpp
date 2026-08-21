#include "Stack.h"
#include <iostream>
#include <random>
#include <stack>

int main()
{
	// 경험치를 저장하는 스택.
	Stack<float> expStack;
	
	// 난수 생성 엔진 준비.
	std::random_device randomDevice;
	std::mt19937 generator(randomDevice());

	// 난수 생성.
	std::uniform_real_distribution<float> expDistribution(100.0f, 200.0f);

	// 스택에 값 추가.
	for (int ix = 0; ix < 10; ++ix)
	{
		// 경험치에 사용할 난수 생성.
		float exp = expDistribution(generator);

		// 생성된 값 출력.
		std::cout << (ix + 1) << "번째 경험치: " << exp << "\n";

		// 스택에 추가.
		expStack.Push(exp);
	}

	// 스택에 저장된 값 출력.
	float expValue = 0.0f;
	while (expStack.Pop(expValue))
	{
		std::cout << "경험치 : " << expValue << "\n";
	}

}