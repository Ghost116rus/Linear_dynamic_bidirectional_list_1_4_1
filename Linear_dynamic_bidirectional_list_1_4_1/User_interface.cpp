#include "user_interface.h"


int getValue(int condition, const char* string)
{
	while (true)													// цикл продолжается до тех пор, пока пользователь не введет корректное значение
	{
		int a;
		std::cin >> a;

		if (std::cin.fail())										// если предыдущее извлечение оказалось неудачным,
		{
			std::cout << "Ошибка! Пожалуйста, повторите ввод! \n";
			std::cin.clear();										// то возвращаем cin в 'обычный' режим работы
			std::cin.ignore(32767, '\n');							// и удаляем значения предыдущего ввода из входного буфера
			std::cout << string;
		}
		else // если всё хорошо и выполнятся условия, то возвращаем a
		{
			switch (condition)
			{
			case Natural_number:
				if (a > 0) { return a; }

				std::cout << "Вы должны ввести натуральное число\n";
				std::cin.ignore(32767, '\n');						// и удаляем значения предыдущего ввода из входного буфера
				continue;

			case O_Or_1:												// На будущее

				if ((a == 0) || (a == 1)) { return a; }

				std::cout << "Вы должны ввести либо 0, либо 1\n";
				std::cin.ignore(32767, '\n');						// и удаляем значения предыдущего ввода из входного буфера
				continue;

			case Menu_Commands:

				if (((int)a > 0) && ((int)a < 8)) { return a; }

				std::cout << "У меню всего 7 функций! Повторите ввод: ";
				std::cin.ignore(32767, '\n');						// и удаляем значения предыдущего ввода из входного буфера
				continue;

			default:
				return a;
			}

		}

	}
}

void show_main_menu()
{
	std::cout << "  Функционал программы:\n"
		<< "1. Инициализация списка\n"
		<< "2. Добавление нового элемента\n"
		<< "3. Удаление элемента списка\n"
		<< "4. Показать содержимое списка\n"
		<< "5. Показать главное меню\n"
		<< "6. Вывести автора программы\n"
		<< "\n7. Завершение работы\n\n";
}

void write_author()
{
	std::cout << "Работу выполнил Калеев Д.А., группа 4211\n";
}

int aboutDirection()
{
	std::cout << "Вы хотите искать данные в прямом или обратном направлении? 0 - в прямом, 1 - в обратном направлении\nВведите: ";
	int left = getValue(O_Or_1, "Вы хотите искать данные в прямом или обратном направлении? 0 - в прямом, 1 - в обратном направлении\n Введите: ");

	return left;
}

My_List::Node* my_search(My_List::MyList* list, int& find_data, int& left)
{
	My_List::Node* current;

	left = aboutDirection();

	if (left)
	{
		current = My_List::find(list, find_data, [](My_List::Node* current)
			{
				return current->pPrevious;
			}
		);
	}
	else
	{
		current = My_List::find(list, find_data, [](My_List::Node* current)
			{
				return current->pNext;
			}
		);
	}
	
	return current;
}

void add_element(My_List::MyList* list, My_List::Node* current, int& temp_data, int& left)
{
	std::cout << "Введите элемент, от которого мы будем отталкиваться: ";
	int find_data = getValue(Natural_number, "Введите элемент, от которого мы будем отталкиваться: ");
	current = my_search(list, find_data, left);

	if (current)
	{
		std::cout << "Вы хотите вставить данные до заданного элемента или после? 0 - до, 1 - после\nВведите: ";
		int before = getValue(O_Or_1, "Вы хотите вставить данные до заданного элемента или после? 0 - до, 1 - после\nВведите: ");

		My_List::add(list, temp_data, before, current);
	}
	else
	{
		std::cout << "Добавление невозможно, т.к элемент с такими данными не найден\n";
	}


}

void delete_element(My_List::MyList* list, My_List::Node* current, int& find_data, int& left)
{
	std::cout << "Введите данные, которые хотели бы удалить: ";
	find_data = getValue(1, "Введите данные: ");

	current = my_search(list, find_data, left);

	if (current)
	{
		My_List::remove(list, current);
	}
	else
	{
		std::cout << "Удаление невозможно, т.к элемент с такими данными не найден\n";
	}

}


void menu(My_List::MyList* list)
{
	int user_choice = 0;
	bool complete_init = false;

	show_main_menu();


	while ((!complete_init) && (user_choice != Exit))
	{
		std::cout << "Выберите команду: ";
		user_choice = getValue(Menu_Commands, "Выберите команду: ");

		if (user_choice == Init)
		{
			list = My_List::create(); std::cout << "Cписок инициализирован.\n";
			complete_init = true;
		}

		else if (user_choice != Exit)
		{
			std::cout << "Невозможно выполнить операцию, т.к список не инициализирован\n";
		}

	}


	while (user_choice != Exit)
	{
		int temp_data = -1;
		int left = -1;
		My_List::Node* current = nullptr;

		switch (user_choice)
		{
		case Add_new_element:

			std::cout << "Введите, данные которые хотите добавить: ";
			temp_data = getValue(1, "Введите данные: ");

			if (!(list->count))
			{
				My_List::pushfront(list, temp_data);
			}
			else
			{
				add_element(list, current, temp_data, left);
			}
			break;

		case Delete_element:

			if (!(list->count))
			{
				std::cout << "Список пустой!\n";
			}
			else
			{
				delete_element(list, current, temp_data, left);
			}
			break;

		case Show_list:


			if (!(list->count))
			{
				std::cout << "Список пустой!\n"; break;
			}

			left = aboutDirection();

			if (left)
			{
				My_List::show(list->pHead->pPrevious, "Проход списка в обратном направлении", [](My_List::Node* current)
					{
						return current->pPrevious;
					}
				);
			}
			else
			{
				My_List::show(list->pHead, "Проход списка в прямом направлении", [](My_List::Node* current)
					{
						return current->pNext;
					}
				);
			}
			break;

		case Show_main_menu:

			std::cout << "\n\n";
			show_main_menu();
			break;

		case Write_author:

			write_author();
			break;

		default:
			break;
		}
		std::cout << "\nВыберите команду: ";
		user_choice = getValue(Menu_Commands, "Выберите команду: ");
	}
	if (list)
	{
		My_List::clean_memory(list);
	}

	std::cout << "Завершение работы\n";
}