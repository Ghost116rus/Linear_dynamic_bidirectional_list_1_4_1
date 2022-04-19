#include "MyList.h"

using namespace My_List;

Node* My_List::create()
{
	Node* Temp = new Node();
	Temp->pNext = Temp;
	Temp->pPrevious = Temp;

	return Temp;	
}

bool My_List::empty(Node* head)
{
	return head->pNext == head;
}

void My_List::show(Node* pHead, std::string message, const std::function<Node* (Node*)>& fcn)
{
	Node* start = fcn(pHead);
	int number = 1;
	while (start != pHead)
	{
		std::cout << number++ << "-ый элемент" << message + " " << start->data << std::endl;
		start = fcn(start);
	} 
}

Node* My_List::find(Node* pHead, int find_data, const std::function<Node* (Node*)>& fcn)
{
	Node* current = fcn(pHead);
	while (current != pHead)
	{
		if (current->data == find_data)
		{
			return current;
		}
		current = fcn(current);
	} 

	std::cout << "Не удалось найти элемент с заданными данными\n";
	return nullptr;
}

void My_List::add(Node* current, int data, bool before)
{
	if (!(before))
	{
		current->pPrevious;
	}

	Node* temp = new Node();
	temp->data = data;

	temp->pNext = current->pNext;
	temp->pPrevious = current;
	current->pNext->pPrevious = temp;
	current->pNext = temp;


	std::cout << "Добавление выполено успешно\n";

}


void My_List::remove(Node* current)
{
	if (empty(current)) { return; }

	current->pNext->pPrevious = current->pPrevious;
	current->pPrevious->pNext = current->pNext;

	delete current;

	std::cout << "Удаление произошло успешно\n";
}

void My_List::clean_memory(Node* list)
{
	Node* current = list->pNext;

	while (current != current->pNext)
	{
		list = current->pNext;
		remove(current);
		current = list;
	}
	delete list;
}



