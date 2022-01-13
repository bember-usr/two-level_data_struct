#pragma once
#include <stdio.h>
#include <iostream>
#include <clocale>
#include <string.h>

typedef struct s_list_out//нагруженное множество предложений
{
	int key;
	struct s_list_out* next;
	struct s_list_out* prev;
	struct s_list_ins* p_data;
}t_list_out;
typedef struct s_list_ins//двусвязный список слов начинаем ввод с него
{
	char* data;
	struct s_list_ins* next;
	struct s_list_ins* prev;

}t_list_ins;


#pragma region mn
void menu_mn();//menu mnojestva
t_list_out* ft_init_mn(); //инициализация корня множества
t_list_out* ft_next_list_mn(t_list_out* p_list_mn); // переместить указатель на следующий элемент
t_list_out* ft_prev_list_mn(t_list_out* p_list_mn); //переместить указатель на предыдущий элемент
t_list_out* delete_root_mn(t_list_out* root); //удаляет корень списка
t_list_out* ft_free_mn(t_list_out* list_mn); //удаляет весь список
t_list_out* ft_add_el_mn(t_list_out* list_mn); //добавление элемента последовательно
t_list_out* add_new_el_mn(t_list_out* list, t_list_out* p_list); //добавление элемента в любое место куда указывает указатель
void ft_is_clean_mn(t_list_out* list_mn); // проверка на существование множества
t_list_out* ft_delete_el_mn(t_list_out** list, t_list_out* p_list); //удалить выбранный элемент множества
void ft_print_all(t_list_out* list_mn, t_list_out* p_list_mn); // напечатать полностью структуру
t_list_out* ft_del_num(int n, t_list_out* list_mn, t_list_out** p);//удаление выбранного элемента из множества
#pragma endregion
#pragma region dvsp
void menu_dv_sp(); //меню двусвязного списка
t_list_ins* ft_init_dvsp(char* data); // инициализация корня двусвязного списка
t_list_ins* delete_root_dvsp(t_list_ins* root); // удаление корня двусвязного списка
t_list_ins* ft_del_one_dvsp(t_list_ins** list, t_list_ins* p_list, int); //удаление выбранного элемента двусвязного списка
char* convert_data_dvsp(char data[]);//преобразование [] в указатель(malloc)
t_list_ins* ft_add_root_dvsp(t_list_ins* list_dvsp, char* data); //добавление корня двусвязного списка
t_list_ins* ft_add_el_dvsp(t_list_ins* list_dvsp, char* data); // добавление нового элемента последовательно
t_list_ins* ft_add_new_el_dvsp(t_list_ins* list, t_list_ins* p_list, char* data); // добавление нового элемента в место куда указывает указатель
void ft_print_dvsp(t_list_ins* list_dvsp, t_list_ins* p_list_dvsp); //печать двусвязного списка
void ft_print_back_dvsp(t_list_ins* list_dvsp, t_list_ins* p_list_dvsp); // печать обратного двусвязного списка
t_list_ins* main2(t_list_out*, t_list_out*); //выполнение команд двусвязного списка
#pragma endregion

void ft_free(t_list_out* list_mn, t_list_ins* list_dvsp); //если сломался malloc
