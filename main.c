#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct Customer {
	char CName[10];
	char OName[10];
	char Model[10];
	char CNum[10];
	int T;
	struct Customer *link;
} Customer;

void Start(int* mode) {
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t::������ ���� �մ� ���� �ý���::\n\n\n\n");
	printf("\t\t\t\t\t1. �մ� ���� ���\n\n\n");
	printf("\t\t\t\t\t2. �մ� ���� ����\n\n\n");
	printf("\t\t\t\t\t3. �մ� ���\n\n\n");
	scanf("%d", mode);
}
int Choice() {
	int c = 0;
	c = _getch();
	return c;
}
void Regist(Customer* c) {
	char cName[10];
	char oName[10];
	char model[10];
	char cNum[10];
	int t;
	system("cls");
	printf("\n\n\n\n\n\n\t\t\t\t\t   �Ƿ��� �̸�\n\n\t\t\t\t\t   ");
	scanf("%s", cName);
	printf("\n\t\t\t\t\t   ������ ����\n\n\t\t\t\t\t   ");
	scanf("%s", oName);
	printf("\n\t\t\t\t\t   ������ȣ\n\n\t\t\t\t\t   ");
	scanf("%s", cNum);
	printf("\n\t\t\t\t\t   ����\n\n\t\t\t\t\t   ");
	scanf("%s", model);
	printf("\n\t\t\t\t\t   ���� ����ð�\n\n\t\t\t\t\t   ");
	scanf("%d", &t);
	printf("\n\t\t\t\t\t   ����Ϸ�");

	Customer* present = malloc(sizeof(Customer));
	present = c;

	for (int i = 0; ; i++) {
		if (present->link != NULL) {
			present = present->link;
		}
		else {
			Customer* temp = malloc(sizeof(Customer));
			strcpy(temp->CName, cName);
			strcpy(temp->OName, oName);
			strcpy(temp->CNum, cNum);
			strcpy(temp->Model, model);
			temp->T = t;

			temp->link = NULL;
			present->link = temp;
			break;
		}
	}

	present = NULL;
	free(present);
}
void Delete(Customer* c) {
	char cNum[10];
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t�۾��� �Ϸ�� ������ ������ȣ �Է�\n\n\t\t\t\t\t     ");
	scanf("%s", cNum);

	Customer* previous = malloc(sizeof(Customer));
	Customer* present = malloc(sizeof(Customer));
	previous = c;
	present = c->link;

	while (1) {
		if (!strcmp(present->CNum, cNum)) {
			if (present->link == NULL)
				previous->link = NULL;
			else
				previous->link = present->link;
			printf("\n\n\t\t\t\t\t     ���� �Ϸ�");
			break;
		}
		else {
			if (present->link == NULL) {
				printf("\n\n\t\t\t\t    ��ϵ��� ���� ������ȣ�Դϴ�");
				break;
			}
			previous = present;
			present = present->link;
		}
	}

	previous = NULL;
	present = NULL;
	free(previous);
	free(present);
}
void Show(Customer* c) {
	system("cls");
	
	int size = 0, max = -1, min = 10000;
	int list[10];
	Customer* present = malloc(sizeof(Customer));
	present = c;

	printf("\n\n\n\n\n\n\t\t\t   <���� ����ð�>       <������ȣ>       <�̸�>\n");

	while (1){
		if (present->link != NULL) {
			size++;
			present = present->link;
		}
		else {
			break;
		}
	}

	for (int i = 0; i < size; i++) {
		present = c;
		while (1) {
			if (present->link != NULL) {
				present = present->link;
				if (present->T<min && present->T>max)
					min = present->T;
			}
			else {
				break;
			}
		}

		list[i] = min;

		max = min;
		min = 10000;
	}

	for (int i = 0; i < size; i++) {
		present = c;
		while (1) {
			if (present->link != NULL) {
				present = present->link;
				if (list[i] == present->T)
					break;
			}
			else {
				break;
			}
		}
		if (present->T >= 1000)
			printf("\n\t\t\t\t%d:%d             %s        %s \n", present->T / 100, present->T % 100, present->CNum, present->CName);
		else
			printf("\n\t\t\t\t0%d:%d             %s        %s \n", present->T / 100, present->T % 100, present->CNum, present->CName);
	}

	present = NULL;
	free(present);
}
int main() {
	system("mode con cols=100 lines=50");
	int Mode, C;
	Customer *head = malloc(sizeof(Customer));
	head->link = NULL;

	while (1) {
	Home:
		Start(&Mode);
		if (Mode == 1) {
			Regist(head);
			while (1) {
				C = 0;
				if (Choice() == 13)
					goto Home;
			}
		}
		else if (Mode == 2) {
			Delete(head);
			while (1) {
				C = 0;
				if (Choice() == 13)
					goto Home;
			}
		}
		else if (Mode == 3) {
			Show(head);
			while (1) {
				C = 0;
				if (Choice() == 13)
					goto Home;
			}
		}
		break;
	}
}