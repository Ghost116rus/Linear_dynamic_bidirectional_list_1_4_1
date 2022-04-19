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

	Node* create();

	bool empty(Node* head);

	void show(Node* pHead, std::string message, const std::function<Node* (Node*)>& fcn);

	Node* find(Node* pHead, int find_data, const std::function<Node* (Node*)>& fcn);

	//void pushfront(MyList* list, int data);

	void add(Node* current, int data, bool before);

	void remove(Node* current);

	void clean_memory(Node* list);
}