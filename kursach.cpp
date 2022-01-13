#include "Header.h"

void menu_mn()
{
	printf("+----------------------------------------+\n\n");
	printf("\
\x1b[34m1)начать работу с множеством\n\
\r2)очистить множество\n\
\r3)проверить множество на пустоту\n\
\r4)удалить элемент множества\n\
\r5)взять элемент множества\n\
\r6)добавить элемент в множество\n\
\r7)нагрузить выбранный элемент множества\n\
\r8)проверить принадлежность элемента к множеству\n\
\r9)распечатать множество целиком\n\
\r10)закончить работу с множеством\n\n");
	printf("+----------------------------------------+\n\n\x1b[0m");
}

int main()
{
#pragma region data
	setlocale(LC_ALL, "rus");
	int n_mn; //количество элементов множества
	int key; //ключ множества
	char* data; //считываемые данные
	char first_data[255]; //считываемые данные
	t_list_out* list_mn = NULL; //указатель на корень множества
	t_list_out* p_list_mn = NULL; //рабочий указатель множества
	int k; //пункт меню
	int flag_mn = 0;//1 - разрешение на выполнение остальных команд
	while (1)
	{
		menu_mn();
		std::cout << "Выберите пункт меню: ";
		std::cin >> k;
		if (k == 1)
			flag_mn = 1;
		if (flag_mn != 1)//проверка на начало работы программы
		{
			std::cout << "\nНе начата работа с множеством!\n" << std::endl;
			continue;
		}
		switch (k)
		{
		case 1://done
		{
			system("CLS");
			std::cout << "\nНачата работа с программой!\n" << std::endl;
			break;
		}
		case 2://done
		{
			system("CLS");
			if (list_mn == NULL)
			{
				std::cout << "\nМножество пусто. Создайте его\n" << std::endl;
				continue;
			}
			list_mn = ft_free_mn(list_mn); //очистить список
			p_list_mn = list_mn;
			break;
		}
		case 3://done
		{
			system("CLS");
			ft_is_clean_mn(list_mn);//проверка на пустоту
			break;
		}
		case 4: //done
		{
			system("CLS");
			if (list_mn == NULL)
			{
				std::cout << "\nМножество пусто. Создайте его\n" << std::endl;
				continue;
			}
			int n;

			std::cout << "Введите номер удаляемого элемента: ";
			std::cin >> n;
			list_mn = ft_del_num(n, list_mn, &p_list_mn);//удаление выбранного элемента
			break;
		}
		case 5://взять элемент 
		{
			system("CLS");
			if (list_mn == NULL)
			{
				std::cout << "\nМножество пусто. Создайте его\n" << std::endl;
				continue;
			}
			t_list_out* p;
			t_list_ins* p_dv;
			p = list_mn;
			int num;
			int fl = 0;
			std::cout << "Введите номер элемента, который вы хотите взять:";
			std::cin >> num;

			for (int i = 0; i < num; i++)
			{
				if (p == NULL)
				{
					fl = 1;
					break;
				}
				p = p->next;
			}
			if (fl || num <= 0)
			{
				std::cout << "\nТакого элемента не существует\n" << std::endl;
				break;
			}
			p = list_mn;
			for (int i = 1; i < num; i++)
				p = p->next;
			p_dv = p->p_data;
			std::cout << "\nДанные взятого элемента: " << std::endl;
			while (p_dv)
			{
				std::cout << "* " << p_dv->data << " *";
				if (p_dv->next != NULL)
					std::cout << " --> ";
				p_dv = p_dv->next;
			}
			if (p_list_mn == p)
				p_list_mn = p->prev;
			ft_delete_el_mn(&list_mn, p);
			std::cout << std::endl;
#pragma region first_code
			//t_list_ins* p_dv;

			//p_dv = p_list_mn->p_data;
			//std::cout << "\nДанные взятого элемента: " << std::endl;
			//while (p_dv)
			//{
			//	std::cout << "* " << p_dv->data << " * --> ";
			//	p_dv = p_dv->next;
			//}
			//p_list_mn = ft_delete_el_mn(&list_mn, p_list_mn);
			//std::cout << std::endl;
#pragma endregion
			break;
		}
		case 6://добавление элемента
		{
			system("CLS");
			if (list_mn == NULL)
			{
				list_mn = ft_init_mn();
				if (list_mn == NULL)//проверка на выделение памяти
					ft_free(list_mn, NULL);
				p_list_mn = list_mn;
			}
			else
			{
				list_mn = add_new_el_mn(list_mn, p_list_mn);//добавили новый элемент
				if (list_mn == NULL)//проверка на выделение памяти
					ft_free(list_mn, NULL);
				p_list_mn = p_list_mn->next;
			}
			t_list_out* p = NULL;
			t_list_ins* p_dvsp;
			int ret = 1;
			int fl = 0;

			p = list_mn;
			while (p != p_list_mn)
				p = p->next;
			int p_d = 0;
			int p_l_d = 0;
			while (ret)
			{
				p_dvsp = main2(list_mn, p_list_mn);
				p->p_data = p_dvsp;
				if (list_mn->next == NULL)
				{
					p_list_mn->p_data = p_dvsp;
					break;
				}
				t_list_out *pp_list_mn = list_mn;
				t_list_ins* pp_list_dvsp;

				while (pp_list_mn->next != NULL)
				{
					pp_list_dvsp = pp_list_mn->p_data;
					p->p_data = p_dvsp;
					p_d = 0;
					p_l_d = 0;
					fl = 0;
					while (pp_list_dvsp || p->p_data)
					{
						if (p->p_data)
						{
							if (pp_list_dvsp)
							if (!strcmp(pp_list_dvsp->data, p->p_data->data))
								fl++;
							{
								p->p_data = p->p_data->next;
								p_d++;
							}
						}
						if (pp_list_dvsp)
						{
							pp_list_dvsp = pp_list_dvsp->next;
							p_l_d++;
						}
					}
					if (fl == p_d && fl == p_l_d)
						break;
					pp_list_mn = pp_list_mn->next;
				}
				if (fl == p_d && fl == p_l_d)
				{
					std::cout << "\nТакое множество существует\n" << std::endl;
					while (p_dvsp)
						p_dvsp = delete_root_dvsp(p_dvsp);
				}
				else
				{
					ret = 0;
					p_list_mn->p_data = p_dvsp;
				}
			}
			std::cout << "\nЭлемент добавлен\n" << std::endl;
			break;
		}
		case 7://искать элемент и нагружать любой
		{
			int key;

			system("CLS");
			if (list_mn == NULL)
			{
				std::cout << "\nМножество пусто. Создайте его\n" << std::endl;
				continue;
			}
			//std::cout << "Введите ключ для нагрузки элемента(цифру или число): ";
			//std::cin >> key;
			//p_list_mn->key = key;
#pragma region first если можно нагрузить любой элемент множества
			t_list_out* p;
			int num;
			int fl = 0;
			p = list_mn;
			std::cout << "Введите номер элемента, который хотите нагрузить: " << std::endl;
			std::cin >> num;
			for (int i = 0; i < num; i++)
			{
				if (p == NULL)
				{
					fl = 1;
					break;
				}
				p = p->next;
			}
			if (fl || num <= 0)
			{
				std::cout << "\nТакого элемента не существует\n" << std::endl;
				break;
			}
			p = list_mn;
			for (int i = 1; i < num; i++)
				p = p->next;
			std::cout << "Введите ключ для нагрузки элемента(цифру или число): ";
			std::cin >> key;
			p->key = key;

#pragma endregion
			break;
		}
		case 8: // проверить принадлежность множеству
		{
			system("CLS");
			if (list_mn == NULL)
			{
				std::cout << "\nМножество пусто. Создайте его\n" << std::endl;
				continue;
			}
			char* data = NULL;
			char first[255];
			t_list_ins* list_dv = NULL;
			int n_dv = 0;
			
			std::cout << "Введите количество элементов: ";
			std::cin >> n_dv;
			std::cout << "Введите данные нового элемента: ";
			std::cin >> first_data; // \0
			data = convert_data_dvsp(first_data);
			list_dv = ft_init_dvsp(data);
			if (list_dv == NULL)
				ft_free(list_mn, list_dv);
			std::cout << std::endl;
			for (int i = 1; i < n_dv; i++)
			{
				std::cout << "Введите данные нового элемента: ";
				std::cin >> first_data; // \0
				data = convert_data_dvsp(first_data);
				if (data == NULL)
					ft_free(list_mn, NULL);
				list_dv = ft_add_el_dvsp(list_dv, data);
				if (list_dv == NULL)
					ft_free(list_mn, list_dv);
			}
			t_list_ins* p = NULL;
			int ret = 1;
			int fl = 0;
			int p_d = 0;
			int p_l_d = 0;
			t_list_out* pp_list_mn = list_mn;
			t_list_ins* pp_list_dvsp = NULL;

			while (pp_list_mn)
			{
				p_d = 0;
				p_l_d = 0;
				fl = 0;
				p = list_dv;
				pp_list_dvsp = pp_list_mn->p_data;
				while (pp_list_dvsp || p)
				{
					if (p)
					{
						if (pp_list_dvsp)
							if (!strcmp(pp_list_dvsp->data, p->data))
								fl++;
						{
							p = p->next;
							p_d++;
						}
					}
					if (pp_list_dvsp)
					{
						pp_list_dvsp = pp_list_dvsp->next;
						p_l_d++;
					}
				}
				if (fl == p_d && fl == p_l_d)
					break;
				pp_list_mn = pp_list_mn->next;
			}
			if (fl == p_d && fl == p_l_d)
				std::cout << "\nТакое множество существует\n" << std::endl;
			else
				std::cout << "\nТакого элемента нет в множестве\n" << std::endl;
			while (list_dv)
				list_dv = delete_root_dvsp(list_dv);
			break;
		}
		case 9://done
		{
			system("CLS");
			if (list_mn == NULL)
			{
				std::cout << "\nМножество пусто. Создайте его\n" << std::endl;
				continue;
			}
			ft_print_all(list_mn, p_list_mn);//печать множества
			break;
		}
		case 10://done
		{
			system("CLS");
			int a;

			while (list_mn)
				list_mn = delete_root_mn(list_mn);
			std::cout << "\nСтруктура уничтожена\n" << std::endl;

			std::cout << "\nХотите завершить работу прогрaммы?\n \r0-нет 1-да: ";
			std::cin >> a;
			if (a == 1)
				return (0);
			flag_mn = 0;//сохранение изменений, продолжить работу
			std::cout << "\nЧтобы продолжить работу с множеством, выберите пункт меню \"начать работу\"\n" << std::endl;
			break;
		}
		default://done
		{
			std::cout << "Выберите пункт из предоставленных выше." << std::endl;
			break;
		}
		}

	}
}