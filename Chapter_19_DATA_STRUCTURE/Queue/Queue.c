#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


typedef struct node {
	int data;
	struct node* link;
}NODE;

//cac ung dung
void add_at_end(NODE** head)
{
	while ( *head == NULL)
	{
		*head = (NODE**)malloc(sizeof(NODE*));
		(* head)->link = NULL;
		//Nhap data for head
		printf("Nhap data cho node 1: ");
		scanf("%d", &((*head)->data));
	}
	//nhap gia tri data
	int data;
	printf("Enter value to add: ");
	scanf("%d", &data);
	//khai bao node insert
	NODE* temp = (NODE *)malloc(sizeof(NODE));
	temp->link = NULL;
	temp->data = data;
	//tao ptr
	NODE* ptr = *head;
	while (ptr->link != NULL)
	{
		ptr = ptr->link;
	}
	//Noi node
	ptr->link = temp;
	
}

void add_beg(NODE** ptr)
{
	//nhap gia tri data
	int data;
	printf("Enter value to add: ");
	scanf("%d", &data);
	//khai bao node insert
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	temp->link = NULL;
	temp->data = data;

	//noi node
	temp->link = *ptr;
	*ptr = temp;
}


void add_at_pos(NODE** head)
{
	//nhap gia tri data
	int data;
	printf("Enter value to add: ");
	scanf("%d", &data);
	//khai bao node insert
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	temp->link = NULL;
	temp->data = data;

	//locate to link
	int pos;
	printf("location to add: ");
	scanf("%d", &pos);

	//move ptr
	NODE* ptr = NULL;
	ptr = *head;
	pos--;

	while (pos!=0)
	{
		ptr = ptr->link;
		pos--;
	}

	//insert node
	temp->link = ptr->link;
	ptr->link = temp;
}



void del_at_pos(NODE** head)
{
	//locate to link
	int pos;
	printf("location to delete: ");
	scanf("%d", &pos);

	//move ptr
	NODE* current = NULL;
	current = *head;

	NODE* previous = NULL;
	previous = *head;
	if (pos == 0)
	{
		*head = current->link;
		free(current);
		current = NULL;
	}
	else
	{
		while (pos != 0)
		{
			previous = current;
			current = current->link;
			pos--;
		}
		previous->link = current->link;
		free(current);
		current = NULL;
	}
}

void del_beg(NODE** head)
{
	if (*head == NULL)
	{
		printf("List is already empty");
	}
	else
	{
		NODE* temp = *head;
		*head = (* head)->link;
		free(temp);
	}
}

void del_at_end(NODE** head)
{
	if (*head == NULL)
	{
		printf("List is already empty!");
	}
	else if ((*head)->link == NULL)
	{
		free(head);
		head = NULL;
	}
	else
	{
		NODE* ptr = *head;
		NODE* previous = *head;

		while (ptr->link != NULL)
		{
			previous = ptr;
			ptr = ptr->link;
		}
		previous->link = NULL;
		free(ptr);
		ptr = NULL;
	}

}

void del_all(NODE** head)
{
	if (*head == NULL)
	{
		printf("List is already empty!");
	}
	else if ((*head)->link == NULL)
	{
		free(head);
		head = NULL;
	}
	else
	{
		NODE* ptr = *head;
		NODE* previous = *head;
		while (ptr->link != NULL)
		{
			previous = ptr;
			ptr = ptr->link;
			free(previous);
			previous = NULL;
		}
		free(ptr);
		ptr = NULL;
		*head = NULL;
	}
}

void createLinkedList(NODE** head) {
	NODE* temp;
	NODE* current;
	int i;

	// Tạo node đầu tiên và gán cho head
	if ((*head) == NULL)
	{
		*head = (NODE*)malloc(sizeof(NODE));
		(*head)->data = 1;
		(*head)->link = NULL;


		// Gán current bằng head để duyệt danh sách
		current = *head;

		// Tạo 4 node tiếp theo và liên kết chúng
		for (i = 2; i <= 5; i++) {
			temp = (NODE*)malloc(sizeof(NODE));
			temp->data = i;
			temp->link = NULL;

			// Liên kết node hiện tại với node mới tạo
			current->link = temp;

			// Di chuyển con trỏ current tới node mới
			current = current->link;
		}
	}
	else
	{
		current = *head;
		while (current->link != NULL)
		{
			current = current->link;
		}
		// Tạo 4 node tiếp theo và liên kết chúng
		for (i = 1; i <= 5; i++) {
			temp = (NODE*)malloc(sizeof(NODE));
			temp->data = i;
			temp->link = NULL;

			// Liên kết node hiện tại với node mới tạo
			current->link = temp;

			// Di chuyển con trỏ current tới node mới
			current = current->link;
		}

	}
}
void swapNodes(NODE** head, int position1, int position2) {
	if (*head == NULL || position1 == position2) {
		return;
	}

	// Tìm node và vị trí của node 1
	NODE* prev1 = NULL;
	NODE* curr1 = *head;
	int count1 = 0;
	while (curr1 != NULL && count1 < position1) {
		prev1 = curr1;
		curr1 = curr1->link;
		count1++;
	}

	// Tìm node và vị trí của node 2
	NODE* prev2 = NULL;
	NODE* curr2 = *head;
	int count2 = 0;
	while (curr2 != NULL && count2 < position2) {
		prev2 = curr2;
		curr2 = curr2->link;
		count2++;
	}

	// Kiểm tra xem cả hai vị trí có tồn tại trong danh sách
	if (curr1 == NULL || curr2 == NULL) {
		return;
	}

	// Nếu node 1 không phải là node đầu tiên, cập nhật con trỏ của node trước nó
	if (prev1 != NULL) {
		prev1->link = curr2;
	}
	else {
		*head = curr2;
	}

	// Nếu node 2 không phải là node đầu tiên, cập nhật con trỏ của node trước nó
	if (prev2 != NULL) {
		prev2->link = curr1;
	}
	else {
		*head = curr1;
	}

	// Hoán đổi con trỏ giữa hai node
	NODE* temp = curr1->link;
	curr1->link = curr2->link;
	curr2->link = temp;
}

void print_data(NODE* head)
{
	if (head == NULL)
	{
		printf("Linked list is empty");
	}

	NODE* ptr = head;
	while (ptr != NULL)
	{
		printf("%d -->", ptr->data);
		ptr = ptr->link;
	}
	
}

void thanks()
{
	printf("Good bye");
}

int main()
{
	NODE* head = NULL;
	//pointer to function add
	void(*add[3])(NODE**);
	add[0] = add_at_end;
	add[1] = add_beg;
	add[2] = add_at_pos;
	//pointer to function delete
	void(*del[4])(NODE**);
	del[0] = del_at_end;
	del[1] = del_beg;
	del[2] = del_at_pos;
	del[3] = del_all;
	//tam biet
	atexit(thanks);

	int choice;
	while (1)

	{
		printf("\n---------------\n");
		printf("Add             1\n");
		printf("Printf data     2\n");
		printf("Delete data     3\n");
		printf("Creat list      4\n");
		printf("SwapNode        5\n");
		printf("Exit            0\n");
		printf("-----------------\n");
		printf("Please choice: ");
		scanf("%d", &choice);
		system("cls");
		

		switch (choice)
		{
		case 1:
		{
			int choice1 = -1;
			while (choice1 != 0)
			{
				printf("\n---------------\n");
				printf("add at end      1\n");
				printf("add beg         2\n");
				printf("add at pos      3\n");
				printf("exit            0\n");
				printf("\n---------------\n");
				printf("Please choice: ");
				scanf("%d", &choice1);
				if (choice1 != 0)
				{
					add[choice1 - 1](&head);
				}
				system("cls");
			}
			break;
		}
		case 2:
			print_data(head);
			break;
		case 3:
		{
			int choice1 = -1;
			while (choice1 != 0)
			{
				printf("\n---------------\n");
				printf("del at end      1\n");
				printf("del beg         2\n");
				printf("del at pos      3\n");
				printf("del all         4\n");
				printf("exit            0\n");
				printf("\n---------------\n");
				printf("Please choice: ");
				scanf("%d", &choice1);
				if (choice1 != 0)
				{
					del[choice1 - 1](&head);
				}
				system("cls");
			}
				
			break;
		}
		case 4:
			createLinkedList(&head);
			break;
		case 5:
		{
			int pos1, pos2;
			printf("Enter value pos1 and pos2: ");
			scanf("%d %d", &pos1, &pos2);
			swapNodes(&head, pos1, pos2);
			break;
		}
		case 0:
			exit(EXIT_SUCCESS);
		}
		

	}

}