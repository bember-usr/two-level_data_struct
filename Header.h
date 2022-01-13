#pragma once
#include <stdio.h>
#include <iostream>
#include <clocale>
#include <string.h>

typedef struct s_list_out//����������� ��������� �����������
{
	int key;
	struct s_list_out* next;
	struct s_list_out* prev;
	struct s_list_ins* p_data;
}t_list_out;
typedef struct s_list_ins//���������� ������ ���� �������� ���� � ����
{
	char* data;
	struct s_list_ins* next;
	struct s_list_ins* prev;

}t_list_ins;


#pragma region mn
void menu_mn();//menu mnojestva
t_list_out* ft_init_mn(); //������������� ����� ���������
t_list_out* ft_next_list_mn(t_list_out* p_list_mn); // ����������� ��������� �� ��������� �������
t_list_out* ft_prev_list_mn(t_list_out* p_list_mn); //����������� ��������� �� ���������� �������
t_list_out* delete_root_mn(t_list_out* root); //������� ������ ������
t_list_out* ft_free_mn(t_list_out* list_mn); //������� ���� ������
t_list_out* ft_add_el_mn(t_list_out* list_mn); //���������� �������� ���������������
t_list_out* add_new_el_mn(t_list_out* list, t_list_out* p_list); //���������� �������� � ����� ����� ���� ��������� ���������
void ft_is_clean_mn(t_list_out* list_mn); // �������� �� ������������� ���������
t_list_out* ft_delete_el_mn(t_list_out** list, t_list_out* p_list); //������� ��������� ������� ���������
void ft_print_all(t_list_out* list_mn, t_list_out* p_list_mn); // ���������� ��������� ���������
t_list_out* ft_del_num(int n, t_list_out* list_mn, t_list_out** p);//�������� ���������� �������� �� ���������
#pragma endregion
#pragma region dvsp
void menu_dv_sp(); //���� ����������� ������
t_list_ins* ft_init_dvsp(char* data); // ������������� ����� ����������� ������
t_list_ins* delete_root_dvsp(t_list_ins* root); // �������� ����� ����������� ������
t_list_ins* ft_del_one_dvsp(t_list_ins** list, t_list_ins* p_list, int); //�������� ���������� �������� ����������� ������
char* convert_data_dvsp(char data[]);//�������������� [] � ���������(malloc)
t_list_ins* ft_add_root_dvsp(t_list_ins* list_dvsp, char* data); //���������� ����� ����������� ������
t_list_ins* ft_add_el_dvsp(t_list_ins* list_dvsp, char* data); // ���������� ������ �������� ���������������
t_list_ins* ft_add_new_el_dvsp(t_list_ins* list, t_list_ins* p_list, char* data); // ���������� ������ �������� � ����� ���� ��������� ���������
void ft_print_dvsp(t_list_ins* list_dvsp, t_list_ins* p_list_dvsp); //������ ����������� ������
void ft_print_back_dvsp(t_list_ins* list_dvsp, t_list_ins* p_list_dvsp); // ������ ��������� ����������� ������
t_list_ins* main2(t_list_out*, t_list_out*); //���������� ������ ����������� ������
#pragma endregion

void ft_free(t_list_out* list_mn, t_list_ins* list_dvsp); //���� �������� malloc
