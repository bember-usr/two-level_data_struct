#include "Header.h"

#pragma region dv
void ft_print_dvsp(t_list_ins* list_dvsp, t_list_ins* p_list_dvsp)
{
	t_list_ins* p;

	p = list_dvsp;
	while (p->next != NULL)
	{
		if (p == p_list_dvsp)
			printf("\x1b[32m*.- %s -.* --> \x1b[0m", p->data);
		else
			printf("\x1b[31m*.- %s -.* --> \x1b[0m", p->data);
		p = p->next;
	}
	if (p == p_list_dvsp)
		printf("\x1b[32m*.- %s -.* \x1b[0m", p->data);
	else
		printf("\x1b[31m*.- %s -.* \x1b[0m", p->data);
}
void ft_print_back_dvsp(t_list_ins* list_dvsp, t_list_ins* p_list_dvsp)
{
	t_list_ins* p;

	p = list_dvsp;
	while (p->next != NULL)
		p = p->next;
	while (p->prev != NULL)
	{
		if (p == p_list_dvsp)
			printf("\x1b[32m*.- %s -.* --> \x1b[0m", p->data);
		else
			printf("\x1b[31m*.- %s -.* --> \x1b[0m", p->data);
		p = p->prev;
	}
	if (p == p_list_dvsp)
		printf("\x1b[32m*.- %s -.* \x1b[0m", p->data);
	else
		printf("\x1b[31m*.- %s -.* \x1b[0m", p->data);
	std::cout << std::endl;
}
t_list_ins* ft_init_dvsp(char* data)
{
	t_list_ins* first;

	first = (t_list_ins*)malloc(sizeof(t_list_ins));
	first->data = data;
	first->prev = first->next = NULL;
	return (first);
}
t_list_ins* delete_root_dvsp(t_list_ins* root)
{
	t_list_ins* temp;

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
t_list_ins* ft_del_one_dvsp(t_list_ins** list, t_list_ins* p_list, int prev)
{
	t_list_ins* pp_list;
	t_list_ins* prev_el;
	t_list_ins* next_el;

	pp_list = *list;
	if (p_list == pp_list)
	{
		*list = delete_root_dvsp(p_list);
		p_list = *list;
	}
	else
	{
		while (pp_list != p_list)//pp_list = p_list->prev || p_list->next
			pp_list = pp_list->next;
		prev_el = pp_list->prev;
		next_el = pp_list->next;
		if (prev_el != NULL)
			prev_el->next = next_el;
		if (next_el != NULL)
			next_el->prev = prev_el;
		free(pp_list);
	}
	return (p_list);
}
char* convert_data_dvsp(char data[])
{
	char* new_data;
	int i = 0;

	while (*(data + i) != '\0')
		i++;
	new_data = (char*)malloc(i * sizeof(char));
	for (int j = 0; j < i; j++)
		*(new_data + j) = *(data + j);
	*(new_data + i) = '\0';
	return (new_data);
}
t_list_ins* ft_add_root_dvsp(t_list_ins* list_dvsp, char* data)
{
	t_list_ins* new_el;

	new_el = NULL;
	new_el = (t_list_ins*)malloc(sizeof(t_list_ins));
	new_el->prev = NULL;
	new_el->data = data;
	new_el->next = list_dvsp;
	list_dvsp->prev = new_el;

	return (new_el);
}
t_list_ins* ft_add_el_dvsp(t_list_ins* list_dvsp, char* data)
{
	t_list_ins* new_el;
	t_list_ins* p;

	p = list_dvsp;
	if (p == NULL)
		return (ft_add_root_dvsp(list_dvsp, data));
	new_el = (t_list_ins*)malloc(sizeof(t_list_ins));
	while (p->next != NULL)
		p = p->next;
	p->next = new_el;
	new_el->prev = p;
	new_el->data = data;
	new_el->next = NULL;

	return (list_dvsp);
}
t_list_ins* ft_add_new_el_dvsp(t_list_ins* list, t_list_ins* p_list, char* data)
{
	t_list_ins* new_el;
	t_list_ins* p;
	t_list_ins* p_next;
	t_list_ins* p_prev;

	new_el = (t_list_ins*)malloc(sizeof(t_list_ins));
	p = list;

	if (p_list == NULL)
		return(ft_add_root_dvsp(list, data));
	while (p != p_list)
		p = p->next;
	if (p->next != NULL)
		p_next = p->next;
	else
		p_next = NULL;
	p->next = new_el;
	new_el->next = p_next;
	new_el->prev = p_list;
	new_el->data = data;
	if (p_next != NULL)
		p_next->prev = new_el;
	return (list);
}
#pragma endregion