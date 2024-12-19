#define _CRT_SECURE_NO_WARNINGS
#ifndef _LIST_H
#define _LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
struct listitem {
	//int k;
	char name[80];
	struct listitem* next;
};

typedef struct listitem* node_t;

node_t createnode(char* newword, char k);
int main()
{
	int g = 10, zh = 0;
	node_t head;
	char f[80], enter[2] = { '\n' }, nol[2] = { '0' }, o [13] = "Milk Burenka";
	node_t h[40];

	setlocale(LC_CTYPE, "RUS");
	char z[10][80] = { "Milk Burenka", "Juice Dobriy", "Juice Moyia Semia", "Beer Stariy Melnik", "Candy Romaska", "Candy Umka", "Candy Moskvicka", "Dobriy Cola", "Kazinak Rossia", "Eggs" };

	for (int i = 0; i < 10; i++)
		h[i] = NULL;
	for (int i = 0; i < 10; i++)
		h[i] = (node_t)malloc(sizeof(struct listitem));
	for (int i = 0; i < 10; i++)
		strcpy(h[i]->name, z[i]);
	for (int i = 0; i < 10; i++)
	{
		if (i == 9)
			h[i]->next = NULL;
		else
			h[i]->next = h[i + 1];
	}
	int l = 0;
	do {
		printf("|%40s         |\n", h[l]);
		l++;
	} while (h[l]->next != NULL);

	for (;;)
	{
		printf("¬ведите 0, если хотите завершить программу\n");
		printf("¬ведите название товара (англ):\n");
		fgets(f, 80, stdin);
		char* find1 = strstr(f, enter);
		int position = find1 - f;
		f[position] = '\0';
		char* find2 = strstr(f, nol);
		if (!find2)
		{
			h[g] = (node_t)malloc(sizeof(struct listitem));
			strcpy(h[g]->name, f);
			h[g - 1]->next = h[g];
			h[g]->next = NULL;
			g++;
		}
		else
			break;
	}
	l = 0;
	do {
		printf("|%40s         |\n", h[l]);
		l++;
	} while (h[l - 1]->next != NULL);
	//l = 0;
	//int y;
	//do {
	//	char* find3 = strstr(h[l], o);
	//	if (find3)
	//	{
	//		zh++;
	//		if (zh > 2)
	//		{
	//			//for (int p = l; (h[l - 1]->next != NULL); p++)
	//			//{
	//			//	strcpy(h[p]->name, h[l]->name);
	//			//	h[p]->next = h[l]->next;
	//			//	y = l - 1;
	//			//}
	//			//if (h [l]->next != NULL)
	//			//if (h[l] != NULL)
	//			//{
	//				h[l] = h[l]->next;
	//				free(h[l]);
	//			//}
	//			//h[y] = NULL;
	//		}
	//	}
	//	l++;
	//} while (h[l - 1]->next != NULL);
	//printf("\n\n\n");
	//do {
	//	printf("|%40s         |\n", h[l]);
	//	l++;
	//} while (h[l - 1]->next != NULL);
	//head = h[1];
}
#endif
//          Milk Burenka