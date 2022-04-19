#pragma once
#include <iostream>
#include <functional>



namespace My_List
{
	struct Node
	{
		int data = 0;
		Node* pNext = this;
		Node* pPrevious = this;
	};

	struct MyList
	{
		int count;
		Node* pHead;
	};

	MyList* create();

	void show(Node* pHead, std::string message, const std::function<Node* (Node*)>& fcn);

	Node* find(const MyList* list, int find_data, const std::function<Node* (Node*)>& fcn);

	void pushfront(MyList* list, int data);

	void add(MyList* list, int data, bool before, Node* current);

	void remove(MyList* list, Node* current);

	void clean_memory(MyList* list);
}