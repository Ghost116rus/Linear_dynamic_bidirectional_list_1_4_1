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

	/// <summary>
	/// Функция создания нашего спсика
	/// </summary>
	/// <returns>Возвращает заголовочный элемент нашего списка</returns>
	Node* create();

	/// <summary>
	/// Фунцкция определения пустого списка
	/// </summary>
	/// <param name="head">получает указатель на заголовочный элемент</param>
	/// <returns>Возвращает истину или ложь в зависимости от реальности</returns>
	bool empty(Node* head);

	/// <summary>
	/// Метод вывода на экран содержимого списка
	/// </summary>
	/// <param name="pHead">Получает указатель на голову</param>
	/// <param name="message">Получает сообщение</param>
	/// <param name="fcn">Получает лямбда-функцию, отвечающую за проход списка (прямой/обратный)</param>
	void show(Node* pHead, std::string message, const std::function<Node* (Node*)>& fcn);

	/// <summary>
	/// Метод поиска
	/// </summary>
	/// <param name="pHead">Получает указатель на голову</param>
	/// <param name="find_data">Искомые данные</param>
	/// <param name="fcn">Получает лямбда-функцию, отвечающую за проход списка (прямой/обратный)</param>
	/// <returns>Возвращает указатель на элемент списка, в котором хранятся искомые данные</returns>
	Node* find(Node* pHead, int find_data, const std::function<Node* (Node*)>& fcn);

	/// <summary>
	/// Метод добавления нового элемента
	/// </summary>
	/// <param name="current">Получает указатель на элемент списка до/после которого нужно добавить данные</param>
	/// <param name="data">Вставляемые данные</param>
	/// <param name="before">Отвечает за вставку до/после</param>
	void add(Node* current, int data, bool before);

	/// <summary>
	/// Удаляет получаемый элемент списка
	/// </summary>
	/// <param name="current">Получаемый элемент списка</param>
	void remove(Node* current);

	/// <summary>
	/// Очистка памяти, для завершения
	/// </summary>
	/// <param name="list">Указатель на сам список</param>
	void clean_memory(Node* list);
}