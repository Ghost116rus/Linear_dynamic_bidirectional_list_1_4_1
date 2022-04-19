#include "MyList.h"

using namespace My_List;

MyList* My_List::create()
{
	MyList* Temp = new MyList();
	Temp->count = 0;
	Temp->pHead = nullptr;

	return Temp;
	
}

void My_List::show(Node* pHead, std::string message, const std::function<Node* (Node*)>& fcn)
{
	Node* start = pHead;
	int number = 1;
	do
	{
		std::cout << number++ << "-ый элемент" << message + " " << start->data << std::endl;
		start = fcn(start);
	} while (start != pHead);
}

Node* My_List::find(const MyList* list, int find_data, const std::function<Node* (Node*)>& fcn)
{
	Node* current = list->pHead;
	do
	{
		if (current->data == find_data)
		{
			return current;
		}
		current = fcn(current);
	} while (current != list->pHead);

	std::cout << "Не удалось найти элемент с заданными данными\n";
	return nullptr;
}

void My_List::pushfront(MyList* list, int data)
{
	Node* tempH = nullptr;

	if (list->count)
	{
		tempH = list->pHead;
	}

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

void My_List::add(MyList* list, int data, bool before, Node* current)
{
	if (list->count == 0)
	{
		return pushfront(list, data);
	}

	if (!before)
	{
		if (current == list->pHead)
		{
			return pushfront(list, data);
		}

		current = current->pPrevious;
	}

	Node* temp = new Node();
	temp->data = data;

	temp->pNext = current->pNext;
	temp->pPrevious = current;
	current->pNext->pPrevious = temp;
	current->pNext = temp;

	list->count++;

	std::cout << "Добавление выполено успешно\n";

}


void My_List::remove(MyList* list, Node* current)
{
	if (current == list->pHead) { list->pHead = current->pNext; }

	current->pNext->pPrevious = current->pPrevious;
	current->pPrevious->pNext = current->pNext;

	delete current; list->count--;

	std::cout << "Удаление произошло успешно\n";
}

void My_List::clean_memory(MyList* list)
{
	Node* current = list->pHead->pNext;

	while (list->count)
	{
		remove(list, list->pHead);
		list->pHead = current;
		current = current->pNext;
	}
	delete list;
}



