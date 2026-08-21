#include "LinkedList.h"
#include <iostream>

int main() 
{
	LinkedList<int> list;
	list.AddToHead(10);
	list.AddToHead(20);
	list.AddToHead(30);

	list.Insert(60);
	list.Insert(50);
	list.Insert(40);

	list.Print();
}