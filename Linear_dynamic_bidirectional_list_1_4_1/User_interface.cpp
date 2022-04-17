#include "user_interface.h"


int getValue(int condition, const char* string)
{
	while (true)													// ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
	{
		int a;
		std::cin >> a;

		if (std::cin.fail())										// ���� ���������� ���������� ��������� ���������,
		{
			std::cout << "������! ����������, ��������� ����! \n";
			std::cin.clear();										// �� ���������� cin � '�������' ����� ������
			std::cin.ignore(32767, '\n');							// � ������� �������� ����������� ����� �� �������� ������
			std::cout << string;
		}
		else // ���� �� ������ � ���������� �������, �� ���������� a
		{
			switch (condition)
			{
			case Natural_number:
				if (a > 0) { return a; }

				std::cout << "�� ������ ������ ����������� �����\n";
				std::cin.ignore(32767, '\n');						// � ������� �������� ����������� ����� �� �������� ������
				continue;

			case O_Or_1:												// �� �������

				if ((a == 0) || (a == 1)) { return a; }

				std::cout << "�� ������ ������ ���� 0, ���� 1\n";
				std::cin.ignore(32767, '\n');						// � ������� �������� ����������� ����� �� �������� ������
				continue;

			case Menu_Commands:

				if (((int)a > 0) && ((int)a < 8)) { return a; }

				std::cout << "� ���� ����� 7 �������! ��������� ����: ";
				std::cin.ignore(32767, '\n');						// � ������� �������� ����������� ����� �� �������� ������
				continue;

			default:
				return a;
			}

		}

	}
}

void show_main_menu()
{
	std::cout << "  ���������� ���������:\n"
		<< "1. ������������� ������\n"
		<< "2. ���������� ������ ��������\n"
		<< "3. �������� �������� ������\n"
		<< "4. �������� ���������� ������\n"
		<< "5. �������� ������� ����\n"
		<< "6. ������� ������ ���������\n"
		<< "\n7. ���������� ������\n\n";
}

void write_author()
{
	std::cout << "������ �������� ������ �.�., ������ 4211\n";
}



void menu(My_List::MyList* list)
{
	int user_choice = 0;
	bool complete_init = false;

	show_main_menu();
	std::cout << "�������� �������: ";
	user_choice = getValue(Menu_Commands, "�������� �������: ");

	while (user_choice != Exit)
	{
		int temp_data;
		switch (user_choice)
		{

		case Init:

			if (!complete_init)
			{
				list = My_List::create(); std::cout << "C����� ���������������.\n";
				complete_init = true;
			}
			else
			{
				std::cout << "C����� ��� ���������������!\n";
			}
			break;

		case Add_new_element:

			if (complete_init)
			{

				std::cout << "�������, ������ ������� ������ ��������: ";
				temp_data = getValue(1, "������� ������: ");

				if (!(list->count))
				{
					My_List::pushfront(list, temp_data);
				}

				else
				{
					std::cout << "������� �������, �� �������� �� ����� �������������: ";
					int find_data = getValue(Natural_number, "������� �������, �� �������� �� ����� �������������: ");

					std::cout << "�� ������ �������� ������ �� ��������� �������� ��� �����? 0 - ��, 1 - �����\n�������: ";
					int before = getValue(O_Or_1, "�� ������ �������� ������ �� ��������� �������� ��� �����? 0 - ��, 1 - �����\n�������: ");

					std::cout << "�� ������ ������ ������ � ������ ��� �������� �����������? 0 - � ������, 1 - � �������� �����������\n�������: ";
					int left = getValue(O_Or_1, "�� ������ ������ ������ � ������ ��� �������� �����������? 0 - � ������, 1 - � �������� �����������\n �������: ");

					if (left)
					{
						My_List::add(list, temp_data, before, find_data, [](My_List::Node* current)
							{
								return current->pPrevious;
							}
						);
					}
					else
					{
						My_List::add(list, temp_data, before, find_data, [](My_List::Node* current)
							{
								return current->pNext;
							}
						);
					}

					
				}
			}
			else
			{
				std::cout << "���������� ��������� ��������, �.� ������ �� ���������������\n";
			}

			break;

		case Delete_element:

			if (complete_init)
			{
				if (!(list->count))
				{
					std::cout << "������ ������!\n";
				}
				else
				{
					std::cout << "������� ������, ������� ������ �� �������: ";
					temp_data = getValue(1, "������� ������: ");

					std::cout << "�� ������ ������ ������ � ������ ��� �������� �����������? 0 - � ������, 1 - � �������� �����������\n�������: ";
					int left = getValue(O_Or_1, "�� ������ ������ ������ � ������ ��� �������� �����������? 0 - � ������, 1 - � �������� �����������\n �������: ");

					if (left)
					{
						My_List::remove(list, temp_data, [](My_List::Node* current)
							{
								return current->pPrevious;
							}
						);
					}
					else
					{
						My_List::remove(list, temp_data, [](My_List::Node* current)
							{
								return current->pNext;
							}
						);
					}
				}

			}
			else
			{
				std::cout << "���������� ���-���� �������, �.� ������ �� ���������������!\n";
			}


			break;

		case Show_list:

			if (complete_init) 
			{
				std::cout << "�� ������ ������ ������ � ������ ��� �������� �����������? 0 - � ������, 1 - � �������� �����������\n�������: ";
				int left = getValue(O_Or_1, "�� ������ ������ ������ � ������ ��� �������� �����������? 0 - � ������, 1 - � �������� �����������\n�������: ");

				if (left)
				{
					My_List::show(list->pHead, "������ ������ � �������� �����������", [](My_List::Node* current)
						{
							return current->pPrevious;
						}
					);
				}
				else
				{
					My_List::show(list->pHead, "������ ������ � ������ �����������", [](My_List::Node* current)
						{
							return current->pNext;
						}
					);
				}
			}
			else { std::cout << "������ �� ���������������!\n"; }

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
		std::cout << "\n�������� �������: ";
		user_choice = getValue(Menu_Commands, "�������� �������: ");
	}

	My_List::clean_memory(list);
	std::cout << "���������� ������\n";
}