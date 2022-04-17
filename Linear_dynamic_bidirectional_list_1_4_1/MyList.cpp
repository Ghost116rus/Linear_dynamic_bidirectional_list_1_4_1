#include "MyList.h"

using namespace My_List;

MyList* My_List::create()
{
	{
		MyList* Temp = new MyList();
		Temp->count = 0;
		Temp->pHead = nullptr;

		return Temp;
	}

}

void My_List::show(Node* pHead, std::string message, const std::function<Node* (Node*)>& fcn)
{
	Node* start = pHead;
	int number = 1;

	do
	{
		std::cout << number++ << "-ый элемент " << message << start->data << std::endl;
		start = fcn(start);
	} while (start != pHead);

}

Node* My_List::find(const MyList* list, int find_data, const std::function<Node* (Node*)>& fcn)
{
	Node* current = list->pHead;

	for (size_t i = 0; i < list->count; i++)
	{
		if (current->data == find_data)
		{
			return current;
		}
		current = fcn(current);
	}

	return nullptr;
}

void My_List::pushfront(MyList* list, int data)
{
	Node* tempH = list->pHead;


	list->pHead = new Node();
	list->pHead->data = data; list->count++;
	
	if (tempH)
	{
		list->pHead->pNext = tempH;
		list->pHead->pPrevious = tempH->pPrevious;

		tempH->pPrevious->pNext = list->pHead;
		tempH->pPrevious = list->pHead;
	}
	else
	{
		list->pHead->pNext = list->pHead;
		list->pHead->pPrevious = list->pHead;
	}
}

void My_List::add(MyList* list, int data, bool before, int find_data, const std::function<Node* (Node*)>& fcn)
{
	if (list->count ==0)
	{
		return My_List::pushfront(list, data);
	}

	Node* current = My_List::find(list, find_data, fcn);

	if (current)
	{
		if (before)
		{
			current = current->pPrevious;
		}

		Node* temp = new Node();
		temp->data = data;

		temp->pNext = current->pNext;
		temp->pPrevious = current;
		current->pNext->pPrevious = temp;
		current->pNext = temp;

		std::cout << "Добавление выполено успешно\n";
	}
	else
	{
		std::cout << "Не удалось найти элемент списка с заданными данными\n";
	}
}

void My_List::remove(MyList* list, int find_data, const std::function<Node* (Node*)>& fcn)
{
	Node* current = find(list, find_data, fcn);

	if (current)
	{
		current->pNext->pPrevious = current->pPrevious;
		current->pPrevious->pNext = current->pNext;

		delete current;

		std::cout << "Удаление произошло успешно\n";
	}
	else
	{
		std::cout << "Не удалось найти элемент списка с заданными данными\n";
	}
}



