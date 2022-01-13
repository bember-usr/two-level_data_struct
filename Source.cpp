#include "Header.h"

void menu_dv_sp() // начинаем с него ввод данных
{
		setlocale(LC_ALL, "rus");
	printf("\
\r\x1b[35m1 начать работу со списком\n\
\r2 сделать список пустым\n\
\r3 проверка пуст список или нет\n\
\r4 установить указатель списка в начало списка\n\
\r5 установить указатель списка в конец списка\n\
\r6 проверка указатель в начале списка\n\
\r7 проверка указатель в конце спискa\n\
\r8 передвинуть указатель списка вперед\n\
\r9 передвинуть указатель списка назад\n\
\r10 показать значение элемента списка до указателя\n\
\r11 показать значение списка после указателя\n\
\r12 удалить элемент списка до указателя\n\
\r13 удалить элемент списка после указателя\n\
\r14 взять элемент списка до указателя\n\
\r15 взять элемент списка после указателя\n\
\r16 изменить значение элемента списка до указателя\n\
\r17 изменить значение элемента списка после указателя\n\
\r18 добавить элемент до указателя\n\
\r19 добавить элемент после указателя\n\
\r20 распечатать список\n\
\r21 распечатать список в обратном порядке\n\
\r22 закончить работу со списком\n\n");
	printf("+----------------------------------------+\n\n\x1b[0m");
}

t_list_ins* main2(t_list_out* list_mn, t_list_out* p_list_mn)
{
#pragma region all

	int flag_dvsp = 0;//проверка начата ли работа со структурой
	int k; //switch
	t_list_ins* list_dvsp = NULL; //указатель на корень двусвязного списка
	t_list_ins* p_list_dvsp = NULL; //рабочий указатель двусвязного списка
	int n_dvsp; // количество элементов двусвязного списка

	while (1)
	{
		menu_dv_sp();
		std::cout << "\nВыберите пункт меню: ";
		std::cin >> k;
		if (k == 1)
			flag_dvsp = 1;
		if (flag_dvsp != 1)
		{
			std::cout << "Не начата работа со списком!" << std::endl;
			continue;
		}
		switch (k)
		{
		case 1:
		{
			system("CLS");
			std::cout << "\nНачата работа со списком. Разрешено выполнение коменд.\n" << std::endl;
			break;
		}
		case 2:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\nСписок пуст. Создайте список\n" << std::endl;
				continue;
			}
			while (list_dvsp)
				list_dvsp = delete_root_dvsp(list_dvsp);
			list_dvsp = NULL;
			std::cout << "\nСписок пуст\n" << std::endl;
			break;
		}
		case 3:
		{
			system("CLS");
			if (list_dvsp == NULL)
				std::cout << "\nСписок пуст. Создайте список\n" << std::endl;
			else
				std::cout << "\nСписок не пуст\n" << std::endl;
			break;
		}
		case 4:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\nСписок пуст. Создайте список\n" << std::endl;
				continue;
			}
			p_list_dvsp = list_dvsp;
			std::cout << "\nУказатель в начале списка\n" << std::endl;
			break;
		}
		case 5:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\nСписок пуст. Создайте список\n" << std::endl;
				continue;
			}
			t_list_ins* p;
			p = list_dvsp;
			while (p->next != NULL)
				p = p->next;
			p_list_dvsp = p;
			std::cout << "\nУказатель в конце списка\n" << std::endl;
			break;
		}
		case 6:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\nСписок пуст. Создайте список\n" << std::endl;
				continue;
			}
			if (p_list_dvsp == list_dvsp)
				std::cout << "\nУказатель в начале списка\n" << std::endl;
			else
				std::cout << "\nУказатель не в начале списка\n" << std::endl;
			break;
		}
		case 7:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\nСписок пуст. Создайте список\n" << std::endl;
				continue;
			}
			t_list_ins* p;
			p = list_dvsp;
			while (p->next != NULL)
				p = p->next;
			if (p_list_dvsp == p)
				std::cout << "\nУказатель в конце списка\n" << std::endl;
			else
				std::cout << "\nУказатель не в конце списка\n" << std::endl;
			break;
		}
		case 8:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\nСписок пуст. Создайте список\n" << std::endl;
				continue;
			}
			if (p_list_dvsp->next != NULL)
			{
				p_list_dvsp = p_list_dvsp->next;
				std::cout << "\nУказатель смещён вперёд\n" << std::endl;
			}
			else
				std::cout << "\nНевозможно передвинуть указатель вперёд\n" << std::endl;
			break;
		}
		case 9:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\nСписок пуст. Создайте список\n" << std::endl;
				continue;
			}
			if (p_list_dvsp->prev != NULL)
			{
				p_list_dvsp = p_list_dvsp->prev;
				std::cout << "\nУказатель смещён назад\n" << std::endl;
			}
			else
				std::cout << "\nНевозможно передвинуть указатель назад\n" << std::endl;
			break;
		}
		case 10:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\nСписок пуст. Создайте список\n" << std::endl;
				continue;
			}
			if (p_list_dvsp->prev != NULL)
				std::cout << std::endl << "Data is: " << p_list_dvsp->prev->data << std::endl;
			else
				std::cout << "\nНет элемента\n" << std::endl;
			break;
		}
		case 11:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\nСписок пуст. Создайте список\n" << std::endl;
				continue;
			}
			if (p_list_dvsp->next != NULL)
				std::cout << std::endl << "Data is: " << p_list_dvsp->next->data << std::endl;
			else
				std::cout << "\nНет элемента\n" << std::endl;
			break;
		}
		case 12:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\nСписок пуст. Создайте список\n" << std::endl;
				continue;
			}
			if (p_list_dvsp->prev == NULL)
			{
				std::cout << "\nНет элемента, который можно удалить\n" << std::endl;
				continue;
			}
			ft_del_one_dvsp(&list_dvsp, p_list_dvsp->prev, 1);
			std::cout << "\nЭлемент удалён\n" << std::endl;
			break;
		}
		case 13:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\nСписок пуст. Создайте список\n" << std::endl;
				continue;
			}
			if (p_list_dvsp->next == NULL)
			{
				std::cout << "\nНет элемента, который можно удалить\n" << std::endl;
				continue;
			}
			ft_del_one_dvsp(&list_dvsp, p_list_dvsp->next, 0);
			std::cout << "\nЭлемент удалён\n" << std::endl;
			break;
		}
		case 14:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\nСписок пуст. Создайте список\n" << std::endl;
				continue;
			}
			char* p;
			t_list_ins* p_next;
			t_list_ins* p_prev;

			if (!p_list_dvsp->prev)
			{
				std::cout << "\nНевозможно взять элемент\n" << std::endl;
				continue;
			}
			p = p_list_dvsp->prev->data;
			p_next = p_list_dvsp->next;
			p_prev = p_list_dvsp->prev;
			ft_del_one_dvsp(&list_dvsp, p_list_dvsp->prev, 1);
			std::cout << "\nДанные взятого элемента: " << std::endl;
			std::cout << p << std::endl;
			break;
		}
		case 15:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\nСписок пуст. Создайте список\n" << std::endl;
				continue;
			}
			char* p;
			t_list_ins* p_next;
			t_list_ins* p_prev;

			if (!p_list_dvsp->next)
			{
				std::cout << "\nНевозможно взять элемент\n" << std::endl;
				continue;
			}
			p = p_list_dvsp->next->data;
			p_next = p_list_dvsp->next;
			p_prev = p_list_dvsp->prev;
			ft_del_one_dvsp(&list_dvsp, p_list_dvsp->next, 0);
			std::cout << "\nДанные взятого элемента: " << std::endl;
			std::cout << p << std::endl;
			break;
		}
		case 16:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\nСписок пуст. Создайте список\n" << std::endl;
				continue;
			}
			if (list_dvsp == NULL || p_list_dvsp->prev == NULL)
			{
				std::cout << "\nНевозможно изменить данные\n" << std::endl;
				continue;
			}
			char first[255];
			char* data;
			t_list_ins* p;

			p = list_dvsp;
			while (p != p_list_dvsp)
				p = p->next;
			std::cout << "Введите новые данные без пробела: ";
			std::cin >> first;
			data = convert_data_dvsp(first);
			if (data == NULL)
				ft_free(list_mn, list_dvsp);
			p->prev->data = data;
			break;
		}
		case 17:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\nСписок пуст. Создайте список\n" << std::endl;
				continue;
			}
			if (list_dvsp == NULL || p_list_dvsp->next == NULL)
			{
				std::cout << "\nНевозможно изменить данные\n" << std::endl;
				continue;
			}
			char first[255];
			char* data;
			t_list_ins* p;

			p = list_dvsp;
			while (p != p_list_dvsp)
				p = p->next;
			std::cout << "Введите новые данные без пробела: ";
			std::cin >> first;
			data = convert_data_dvsp(first);
			if (data == NULL)
				ft_free(list_mn, list_dvsp);
			p->next->data = data;
			break;
		}
		case 18: //prev
		{
			system("CLS");
			char* data = NULL;
			char first_data[255];

			std::cout << "Введите данные нового элемента: ";
			std::cin >> first_data; // \0
			data = convert_data_dvsp(first_data);
			if (data == NULL)
				ft_free(list_mn, list_dvsp);
			if (list_dvsp == NULL)
			{
				list_dvsp = ft_init_dvsp(data);
				p_list_dvsp = list_dvsp;
				if (list_dvsp == NULL)	//malloc
					ft_free(list_mn, list_dvsp);
			}
			else
			{
				list_dvsp = ft_add_new_el_dvsp(list_dvsp, p_list_dvsp->prev, data);
				if (list_dvsp == NULL)	//malloc
					ft_free(list_mn, list_dvsp);

			}
			std::cout << "\nДобавлен элемент до указателя\n" << std::endl;
			break;
		}
		case 19:
		{
			system("CLS");
			char* data = NULL;
			char first_data[255];

			std::cout << "Введите данные нового элемента: ";
			std::cin >> first_data; // \0
			data = convert_data_dvsp(first_data);
			if (data == NULL)
				ft_free(list_mn, list_dvsp);
			if (list_dvsp == NULL)
			{
				list_dvsp = ft_init_dvsp(data);
				p_list_dvsp = list_dvsp;
				if (list_dvsp == NULL)	//malloc
					ft_free(list_mn, list_dvsp);
			}
			else
			{
				list_dvsp = ft_add_new_el_dvsp(list_dvsp, p_list_dvsp, data);
				if (list_dvsp == NULL)
					ft_free(list_mn, list_dvsp);

			}
			std::cout << "\nДобавлен элемент после указателя\n" << std::endl;
			break;
		}
		case 20: //done
		{
			system("CLS");
			if (!list_dvsp)
			{
				std::cout << "\nСписок пуст. Создайте список\n" << std::endl;
				continue;
			}
			ft_print_dvsp(list_dvsp, p_list_dvsp);
			std::cout << std::endl;
			ft_print_back_dvsp(list_dvsp, p_list_dvsp);
			std::cout << "\n";
			break;
		}
		case 21: //done
		{
			system("CLS");
			if (!list_dvsp)
			{
				std::cout << "\nСписок пуст. Создайте список\n" << std::endl;
				continue;
			}
			ft_print_back_dvsp(list_dvsp, p_list_dvsp);
			break;
		}
		case 22: //done
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\nСписок пуст. Добавьте данные в список\n" << std::endl;
				continue;
			}
			return (list_dvsp);
		}
		default:
		{
			std::cout << "\nВведите один из вышеперечисленных пунктов\n" << std::endl;
			break;
		}
		}
	}
}
