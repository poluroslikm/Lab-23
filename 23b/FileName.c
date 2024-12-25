#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
typedef struct node {
	char name[80];
	struct node* next;
} node;

typedef struct linked_list 
{
	node* head;
} linked_list;

int add_front(linked_list* list, char* val);
int print_list(linked_list* list);
int deleate(linked_list* list, char* val);
node* find(node* start, char* val);
void delite_mega(linked_list* list);
node* mergeSort(node* head);


int main()
{
	int g = 10, zh = 0;
	linked_list chek;
	linked_list *chek_adress=&chek;
	char f[80], enter[2] = { '\n' }, nol[2] = { '0' };
	//node h[40];
	chek_adress->head = NULL;
	setlocale(LC_CTYPE, "RUS");
	char z[10][80] = { "Milk Burenka", "Juice Dobriy", "Juice Moyia Semia", "Beer Stariy Melnik", "Candy Romaska", "Candy Umka", "Candy Moskvicka", "Dobriy Cola", "Kazinak Rossia", "Eggs" };

	for (int i = 0; i < 10; i++)
		add_front(&chek,&z[i]);
	print_list(&chek);
	//deleate(&tasks, &z[9]);
	for (;;)
	{
		printf("Введите 0, если хотите завершить программу\n");
		printf("Введите название товара (англ):\n");
		fgets(f, 80, stdin);
		char* find1 = strstr(f, enter);
		int position = find1 - f;
		f[position] = '\0';
		char* find2 = strstr(f, nol);
		if (!find2)
		{
			add_front(&chek, &f);
		}
		else
			break;
	}
	puts("");
	print_list(&chek);
	//deleate(&tasks, "Milk Burenka");

	puts("");
	puts("--------------------------------------------------------");
	delite_mega(&chek);
	puts("Удаление строки, как первая, если она встречается более 2 раз");
	print_list(&chek);

	puts("");
	puts("--------------------------------------------------------");
	chek_adress->head = mergeSort(chek_adress->head);
	puts("Сортировка");
	print_list(&chek);
	










	//for (int i = 0; i < 11; i++)
	//	h[i] = (node)malloc(sizeof(struct listitem));
	//for (int i = 0; i < 11; i++)
	//	strcpy(h[i]->name, z[i]);
	//for (int i = 0; i < 11; i++)
	//{
	//	if (i == 10)
	//		h[i]->next = NULL;
	//	else
	//		h[i]->next = h[i + 1];
	//}
	//int l = 0;
	//do {
	//	printf("|%40s         |\n", h[l]);
	//	l++;
	//} while (h[l]->next != NULL);
	//for (;;)
	//{
	//	printf("Введите 0, если хотите завершить программу\n");
	//	printf("Введите название товара (англ):\n");
	//	fgets(f, 80, stdin);
	//	char* find1 = strstr(f, enter);
	//	int position = find1 - f;
	//	f[position] = '\0';
	//	char* find2 = strstr(f, nol);
	//	if (!find2)
	//	{
	//		h[g] = (node)malloc(sizeof(struct listitem));
	//		strcpy(h[g]->name, f);
	//		h[g - 1]->next = h[g];
	//		h[g]->next = NULL;
	//		g++;
	//	}
	//	else
	//		break;
	//}
	//do {
	//	printf("|%40s         |\n", h[l]);
	//	l++;
	//} while (h[l - 1]->next != NULL);
	//// func(o)
	//node ex = NULL, cur = head;
	//l = 0;
	//while ((cur != NULL) && (!strstr(cur->name, o)))
	//{
	//	ex = cur;
	//	cur = cur->next;
	//}
	//if (cur != NULL) //нашли, а не дошли до конца
	//{
	//	ex->next = cur->next;
	//}
	//
	////do {
	////	node ex = NULL, cur = head;
	////	l = 0;
	////	while ((cur != NULL) && (!strstr(cur->name, o)))
	////	{
	////		ex = cur;
	////		cur = cur->next;
	////	}
	////	if (cur != 0) //нашли, а не дошли до конца
	////	{
	////		ex->next = cur->next;
	////	}
	////} while (h[l - 1]->next != NULL);
	//zh++;
	////if (zh > 2)
	////{
	////	for (int p = l; (h[l - 1]->next != NULL); p++)
	////	{
	////		strcpy(h[p]->name, h[l]->name);
	////		h[p]->next = h[l]->next;
	////		y = l - 1;
	////	}
	////	if (h[l]->next != NULL)
	////		if (h[l] != NULL)
	////		{
	////			h[l] = h[l]->next;
	////			free(h[l]);
	////		}
	////	h[y] = NULL;
	////}
	//printf("\n\n\n");
	//do {
	//	printf("|%40s         |\n", h[l]);
	//	l++;
	//} while (h[l - 1]->next != NULL);
}

// Вставка в начало
int add_front(linked_list* list, char* val)
{
	node* new_node = (node*)malloc(sizeof(node));
	new_node->next = list->head;
	strcpy(new_node->name, val);
	list->head = new_node;
	//return list;
}

// Вывод
int print_list(linked_list* list)
{
	node* cur = list->head;
	while (cur)
	{
		printf("|%40s         |\n", cur->name);
		cur = cur->next;
	}
}

// Удаление
int deleate(linked_list* list, char* val)
{
	node* cur = list->head;
	node* ex = NULL;
	while (cur)
	{
		if (strcmp(cur->name, val) == 0)
		{
			if (ex)
			{
				ex->next = cur->next;
			}
			else
				list->head = cur->next;
			free(cur);
			return 1; // Удалили
		}
		ex = cur;
		cur = cur->next;
	}
	return 0; // Не нашли
}

// Возвращает узел, содержащий val
node* find(node* start, char* val)
{
	while (start)
	{
		if (strcmp(start->name, val) == 0)
			return start;
		else
			start = start->next;
	}
	return NULL;
}

//удаляется первый элемент если встречается 2 раза1917
void delite_mega(linked_list* list)
{
	char first[80];
	strcpy(first, list->head->name);
	node* begin_del = find(list->head->next, &first);
	if (!begin_del)
		return; // Первый не повторяется
	begin_del = begin_del->next; // Указывает на элем. ЗА вторым вхождением
	linked_list tmp;
	tmp.head = begin_del;
	while (deleate(&tmp, &first)) {}
}

//Сорировка
node* mergeSort(node* head) {
	if (!head || !head->next) return head;
	node* center = head;
	node* fast = head->next;
	node* res = NULL;
	node* temp = NULL;
	while (fast && fast->next) {
		center = center->next;
		fast = fast->next->next;
	}
	node* half1 = head;
	node* half2 = center->next;
	center->next = NULL;
	half1 = mergeSort(half1);
	half2 = mergeSort(half2);
	if (strcmp(half1->name, half2->name) <= 0) {
		res = half1;
		half1 = half1->next;
	}
	else {
		res = half2;
		half2 = half2->next;
	}
	temp = res;
	while (half1 && half2) {
		if (strcmp(half1->name, half2->name) <= 0) {
			temp->next = half1;
			half1 = half1->next;
		}
		else {
			temp->next = half2;
			half2 = half2->next;
		}
		temp = temp->next;
	}
	if (half1) temp->next = half1;
	else temp->next = half2;
	return res;
}