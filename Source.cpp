#include "Header.h"

void menu_dv_sp() // �������� � ���� ���� ������
{
		setlocale(LC_ALL, "rus");
	printf("\
\r\x1b[35m1 ������ ������ �� �������\n\
\r2 ������� ������ ������\n\
\r3 �������� ���� ������ ��� ���\n\
\r4 ���������� ��������� ������ � ������ ������\n\
\r5 ���������� ��������� ������ � ����� ������\n\
\r6 �������� ��������� � ������ ������\n\
\r7 �������� ��������� � ����� �����a\n\
\r8 ����������� ��������� ������ ������\n\
\r9 ����������� ��������� ������ �����\n\
\r10 �������� �������� �������� ������ �� ���������\n\
\r11 �������� �������� ������ ����� ���������\n\
\r12 ������� ������� ������ �� ���������\n\
\r13 ������� ������� ������ ����� ���������\n\
\r14 ����� ������� ������ �� ���������\n\
\r15 ����� ������� ������ ����� ���������\n\
\r16 �������� �������� �������� ������ �� ���������\n\
\r17 �������� �������� �������� ������ ����� ���������\n\
\r18 �������� ������� �� ���������\n\
\r19 �������� ������� ����� ���������\n\
\r20 ����������� ������\n\
\r21 ����������� ������ � �������� �������\n\
\r22 ��������� ������ �� �������\n\n");
	printf("+----------------------------------------+\n\n\x1b[0m");
}

t_list_ins* main2(t_list_out* list_mn, t_list_out* p_list_mn)
{
#pragma region all

	int flag_dvsp = 0;//�������� ������ �� ������ �� ����������
	int k; //switch
	t_list_ins* list_dvsp = NULL; //��������� �� ������ ����������� ������
	t_list_ins* p_list_dvsp = NULL; //������� ��������� ����������� ������
	int n_dvsp; // ���������� ��������� ����������� ������

	while (1)
	{
		menu_dv_sp();
		std::cout << "\n�������� ����� ����: ";
		std::cin >> k;
		if (k == 1)
			flag_dvsp = 1;
		if (flag_dvsp != 1)
		{
			std::cout << "�� ������ ������ �� �������!" << std::endl;
			continue;
		}
		switch (k)
		{
		case 1:
		{
			system("CLS");
			std::cout << "\n������ ������ �� �������. ��������� ���������� ������.\n" << std::endl;
			break;
		}
		case 2:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\n������ ����. �������� ������\n" << std::endl;
				continue;
			}
			while (list_dvsp)
				list_dvsp = delete_root_dvsp(list_dvsp);
			list_dvsp = NULL;
			std::cout << "\n������ ����\n" << std::endl;
			break;
		}
		case 3:
		{
			system("CLS");
			if (list_dvsp == NULL)
				std::cout << "\n������ ����. �������� ������\n" << std::endl;
			else
				std::cout << "\n������ �� ����\n" << std::endl;
			break;
		}
		case 4:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\n������ ����. �������� ������\n" << std::endl;
				continue;
			}
			p_list_dvsp = list_dvsp;
			std::cout << "\n��������� � ������ ������\n" << std::endl;
			break;
		}
		case 5:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\n������ ����. �������� ������\n" << std::endl;
				continue;
			}
			t_list_ins* p;
			p = list_dvsp;
			while (p->next != NULL)
				p = p->next;
			p_list_dvsp = p;
			std::cout << "\n��������� � ����� ������\n" << std::endl;
			break;
		}
		case 6:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\n������ ����. �������� ������\n" << std::endl;
				continue;
			}
			if (p_list_dvsp == list_dvsp)
				std::cout << "\n��������� � ������ ������\n" << std::endl;
			else
				std::cout << "\n��������� �� � ������ ������\n" << std::endl;
			break;
		}
		case 7:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\n������ ����. �������� ������\n" << std::endl;
				continue;
			}
			t_list_ins* p;
			p = list_dvsp;
			while (p->next != NULL)
				p = p->next;
			if (p_list_dvsp == p)
				std::cout << "\n��������� � ����� ������\n" << std::endl;
			else
				std::cout << "\n��������� �� � ����� ������\n" << std::endl;
			break;
		}
		case 8:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\n������ ����. �������� ������\n" << std::endl;
				continue;
			}
			if (p_list_dvsp->next != NULL)
			{
				p_list_dvsp = p_list_dvsp->next;
				std::cout << "\n��������� ������ �����\n" << std::endl;
			}
			else
				std::cout << "\n���������� ����������� ��������� �����\n" << std::endl;
			break;
		}
		case 9:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\n������ ����. �������� ������\n" << std::endl;
				continue;
			}
			if (p_list_dvsp->prev != NULL)
			{
				p_list_dvsp = p_list_dvsp->prev;
				std::cout << "\n��������� ������ �����\n" << std::endl;
			}
			else
				std::cout << "\n���������� ����������� ��������� �����\n" << std::endl;
			break;
		}
		case 10:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\n������ ����. �������� ������\n" << std::endl;
				continue;
			}
			if (p_list_dvsp->prev != NULL)
				std::cout << std::endl << "Data is: " << p_list_dvsp->prev->data << std::endl;
			else
				std::cout << "\n��� ��������\n" << std::endl;
			break;
		}
		case 11:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\n������ ����. �������� ������\n" << std::endl;
				continue;
			}
			if (p_list_dvsp->next != NULL)
				std::cout << std::endl << "Data is: " << p_list_dvsp->next->data << std::endl;
			else
				std::cout << "\n��� ��������\n" << std::endl;
			break;
		}
		case 12:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\n������ ����. �������� ������\n" << std::endl;
				continue;
			}
			if (p_list_dvsp->prev == NULL)
			{
				std::cout << "\n��� ��������, ������� ����� �������\n" << std::endl;
				continue;
			}
			ft_del_one_dvsp(&list_dvsp, p_list_dvsp->prev, 1);
			std::cout << "\n������� �����\n" << std::endl;
			break;
		}
		case 13:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\n������ ����. �������� ������\n" << std::endl;
				continue;
			}
			if (p_list_dvsp->next == NULL)
			{
				std::cout << "\n��� ��������, ������� ����� �������\n" << std::endl;
				continue;
			}
			ft_del_one_dvsp(&list_dvsp, p_list_dvsp->next, 0);
			std::cout << "\n������� �����\n" << std::endl;
			break;
		}
		case 14:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\n������ ����. �������� ������\n" << std::endl;
				continue;
			}
			char* p;
			t_list_ins* p_next;
			t_list_ins* p_prev;

			if (!p_list_dvsp->prev)
			{
				std::cout << "\n���������� ����� �������\n" << std::endl;
				continue;
			}
			p = p_list_dvsp->prev->data;
			p_next = p_list_dvsp->next;
			p_prev = p_list_dvsp->prev;
			ft_del_one_dvsp(&list_dvsp, p_list_dvsp->prev, 1);
			std::cout << "\n������ ������� ��������: " << std::endl;
			std::cout << p << std::endl;
			break;
		}
		case 15:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\n������ ����. �������� ������\n" << std::endl;
				continue;
			}
			char* p;
			t_list_ins* p_next;
			t_list_ins* p_prev;

			if (!p_list_dvsp->next)
			{
				std::cout << "\n���������� ����� �������\n" << std::endl;
				continue;
			}
			p = p_list_dvsp->next->data;
			p_next = p_list_dvsp->next;
			p_prev = p_list_dvsp->prev;
			ft_del_one_dvsp(&list_dvsp, p_list_dvsp->next, 0);
			std::cout << "\n������ ������� ��������: " << std::endl;
			std::cout << p << std::endl;
			break;
		}
		case 16:
		{
			system("CLS");
			if (list_dvsp == NULL)
			{
				std::cout << "\n������ ����. �������� ������\n" << std::endl;
				continue;
			}
			if (list_dvsp == NULL || p_list_dvsp->prev == NULL)
			{
				std::cout << "\n���������� �������� ������\n" << std::endl;
				continue;
			}
			char first[255];
			char* data;
			t_list_ins* p;

			p = list_dvsp;
			while (p != p_list_dvsp)
				p = p->next;
			std::cout << "������� ����� ������ ��� �������: ";
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
				std::cout << "\n������ ����. �������� ������\n" << std::endl;
				continue;
			}
			if (list_dvsp == NULL || p_list_dvsp->next == NULL)
			{
				std::cout << "\n���������� �������� ������\n" << std::endl;
				continue;
			}
			char first[255];
			char* data;
			t_list_ins* p;

			p = list_dvsp;
			while (p != p_list_dvsp)
				p = p->next;
			std::cout << "������� ����� ������ ��� �������: ";
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

			std::cout << "������� ������ ������ ��������: ";
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
			std::cout << "\n�������� ������� �� ���������\n" << std::endl;
			break;
		}
		case 19:
		{
			system("CLS");
			char* data = NULL;
			char first_data[255];

			std::cout << "������� ������ ������ ��������: ";
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
			std::cout << "\n�������� ������� ����� ���������\n" << std::endl;
			break;
		}
		case 20: //done
		{
			system("CLS");
			if (!list_dvsp)
			{
				std::cout << "\n������ ����. �������� ������\n" << std::endl;
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
				std::cout << "\n������ ����. �������� ������\n" << std::endl;
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
				std::cout << "\n������ ����. �������� ������ � ������\n" << std::endl;
				continue;
			}
			return (list_dvsp);
		}
		default:
		{
			std::cout << "\n������� ���� �� ����������������� �������\n" << std::endl;
			break;
		}
		}
	}
}
