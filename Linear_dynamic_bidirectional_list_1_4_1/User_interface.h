#pragma once
#include <iostream>
#include "MyList.h"

enum Options
{
	Init = 1,
	Add_new_element = 2,
	Delete_element = 3,
	Show_list = 4,
	Show_main_menu = 5,
	Write_author = 6,
	Exit = 7,

	Natural_number = 14,
	O_Or_1 = 15,
	Menu_Commands = 16
};

/* Функция со мной ещё со 2 - ого семестра, когда об объектной обработки исключений ничего не было известно  */
int getValue(int condition, const char* string);

/*  Вывод главного меню  */
void show_main_menu();

/*  Вывод информации об авторе  */
void write_author();

int aboutDirection();

void add_element(My_List::MyList* list, My_List::Node* current, int& temp_data, int& left);

void delete_element(My_List::MyList* list, My_List::Node* current, int& find_data, int& left);


/*  основная программная реализация интерфейса  */
void menu(My_List::MyList* list);