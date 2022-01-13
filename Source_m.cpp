#include "Header.h"

#pragma region mn
t_list_out* ft_del_num(int n, t_list_out* list_mn, t_list_out** p)
{
	t_list_out* p_list_mn;
	int fl = 0;

	p_list_mn = list_mn;
	for (int i = 1; i < n; i++)
	{
		p_list_mn = p_list_mn->next;
		if (p_list_mn == NULL)
		{
			std::cout << "\nТакого элемента не существует\n" << std::endl;
			fl = 1;
			break;
		}
	}
	if (p_list_mn == *p)
		*p = p_list_mn->prev;
	if (!fl)
	{
		p_list_mn = ft_delete_el_mn(&list_mn, p_list_mn);
		std::cout << "\nЭлемент удалён\n" << std::endl;
	}
	return (list_mn);
}
void ft_print_all(t_list_out* list_mn, t_list_out* p_list_mn)
{
	t_list_out* pp_list;
	t_list_ins* p;
	int i = 0;

	pp_list = list_mn;
	while (pp_list != NULL)
	{
		if (pp_list == p_list_mn)
		{
			p = pp_list->p_data;
			if (pp_list->key == -1)
				printf("\r\x1b[32m key\t");
			else
				printf("\r\x1b[32m  %d\t", pp_list->key);
			while (p)
			{
				printf("*-  %s -*", p->data);
				if (p->next != NULL)
					std::cout << " --> ";
				p = p->next;
			}
			printf(" \x1b[0m");

		}
		else
		{
			p = pp_list->p_data;
			if (pp_list->key == -1)
				printf("\r\x1b[31m key\t");
			printf("\r\x1b[31m  %d\t", pp_list->key);
			while (p)
			{
				printf("*-  %s -*", p->data);
				if (p->next != NULL)
					std::cout << " --> ";
				p = p->next;
			}
			printf(" \x1b[0m");
		}
		i++;
		printf("\n");
		pp_list = pp_list->next;
	}
	printf("\n\n");
}
void ft_free(t_list_out* list_mn, t_list_ins* list_dvsp) //если сломался malloc
{
	t_list_out* p_mn;

	while (list_dvsp)
		delete_root_dvsp(list_dvsp);
	p_mn = list_mn;
	while (p_mn)
	{
		while (p_mn->p_data)
			delete_root_dvsp(p_mn->p_data);
		delete_root_mn(p_mn);
	}
	exit(-1);
}
t_list_out* ft_init_mn()
{
	t_list_out* first;

	first = NULL;
	first = (t_list_out*)malloc(sizeof(t_list_out));
	first->p_data = NULL;
	first->prev = first->next = NULL;
	return (first);
}
t_list_out* ft_next_list_mn(t_list_out* p_list_mn)
{
	if (p_list_mn != NULL)
		if (p_list_mn->next != NULL)
			return (p_list_mn->next);
		else
			std::cout << "\nНевозможно переместить указатель.\n" << std::endl;
	return (p_list_mn);
}
t_list_out* ft_prev_list_mn(t_list_out* p_list_mn)
{
	if (p_list_mn != NULL)
		if (p_list_mn->prev != NULL)
			return (p_list_mn->prev);
		else
			std::cout << "\nНевозможно переместить указатель.\n" << std::endl;
	return (p_list_mn);

}
t_list_out* delete_root_mn(t_list_out* root)
{
	t_list_out* temp;

	if (root->next == NULL)
	{
		free(root);
		return (NULL);
	}
	temp = root->next;
	temp->prev = NULL;
	free(root);
	return (temp);
}
t_list_out* ft_free_mn(t_list_out* list_mn)
{
	if (list_mn != NULL)
		while (list_mn->next)
			delete_root_mn(list_mn);
	std::cout << "\nМножество чисто\n" << std::endl;
	return (list_mn);
}
t_list_out* ft_add_el_mn(t_list_out* list_mn)
{
	t_list_out* new_el;
	t_list_out* p;

	p = list_mn;
	new_el = (t_list_out*)malloc(sizeof(t_list_out));
	while (p->next != NULL)
		p = p->next;
	p->next = new_el;
	new_el->p_data = NULL;
	new_el->prev = p;
	new_el->next = NULL;

	return (list_mn);
}
t_list_out* add_new_el_mn(t_list_out* list, t_list_out* p_list)
{
	t_list_out* new_el;
	t_list_out* p;
	t_list_out* p_next;
	t_list_out* p_prev;

	new_el = (t_list_out*)malloc(sizeof(t_list_out));
	p = list;

	while (p != p_list)
		p = p->next;
	p_next = p->next; //NULL
	p->next = new_el;
	new_el->next = NULL;
	new_el->prev = p_list;
	if (p_next != NULL)
		p_next->prev = new_el;
	return (list);
}
void ft_is_clean_mn(t_list_out* list_mn)
{
	t_list_out* p;
	p = list_mn;

	while (p)
	{
		if (p->p_data != NULL)
		{
			std::cout << "\nМножество не пусто.\n" << std::endl;
			return;
		}
		p = p->next;
	}
	std::cout << "\nМножество пусто.\n" << std::endl;
}
t_list_out* ft_delete_el_mn(t_list_out** list, t_list_out* p_list)
{
	t_list_out* pp_list;
	t_list_out* prev_el;
	t_list_out* next_el;

	pp_list = *list;
	if (p_list == pp_list)
	{
		*list = delete_root_mn(p_list);
		p_list = *list;
	}
	else
	{
		while (pp_list != p_list)
			pp_list = pp_list->next;
		prev_el = pp_list->prev;
		next_el = pp_list->next;
		if (prev_el != NULL)
			prev_el->next = next_el;
		if (next_el != NULL)
			next_el->prev = prev_el;
		free(p_list);
		if (next_el == NULL)
			p_list = prev_el;
		else
			p_list = next_el;
	}
	return (p_list);
}
#pragma endregion
