#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "MYLIB.H"
void add_at_end(D_NODE** head)
{
    if (*head == NULL)
    {
        *head = (D_NODE*)malloc(sizeof(D_NODE));
        (*head)->prev = NULL;
        (*head)->next = NULL;
        printf("Please enter value of ID: ");
        scanf("%d", &((*head)->ID));
        printf("Please enter value of name: ");
        scanf("%s", (*head)->name);
        printf("Please enter value of mark: ");
        scanf("%d", &((*head)->mark));
    }
    else
    {
        D_NODE* ptr = *head;
        D_NODE* temp = (D_NODE*)malloc(sizeof(D_NODE));
        temp->prev = NULL;
        temp->next = NULL;
        printf("Please enter value of ID: ");
        scanf("%d", &(temp->ID));
        printf("Please enter value of name: ");
        scanf("%s", temp->name);
        printf("Please enter value of mark: ");
        scanf("%d", &(temp->mark));

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;
    }
}

void add_beg(D_NODE** head)
{
    D_NODE* temp = (D_NODE*)malloc(sizeof(D_NODE));
    temp->prev = NULL;
    temp->next = NULL;
    printf("Please enter value of ID: ");
    scanf("%d", &(temp->ID));
    printf("Please enter value of name: ");
    scanf("%s", (temp->name));
    printf("Please enter value of mark: ");
    scanf("%d", &(temp->mark));

    if (*head != NULL)
    {
        (*head)->prev = temp;
    }
    temp->next = *head;
    *head = temp;
}

void add_at_pos(D_NODE** head)
{
    D_NODE* temp = (D_NODE*)malloc(sizeof(D_NODE));
    D_NODE* ptr1 = *head;
    D_NODE* ptr2 = *head;
    int pos;
    printf("Enter location to insert: ");
    scanf("%d", &pos);

    printf("Please enter value of ID: ");
    scanf("%d", &(temp->ID));
    printf("Please enter value of name: ");
    scanf("%s", (temp->name));
    printf("Please enter value of mark: ");
    scanf("%d", &(temp->mark));

    while (pos != 1)
    {
        ptr1 = ptr1->next;
        pos--;
    }

    ptr2 = ptr1->next;
    ptr1->next = temp;
    temp->prev = ptr1;
    temp->next = ptr2;
    if (ptr2 != NULL)
    {
        ptr2->prev = temp;
    }
}

void del_beg(D_NODE** head)
{
    if (*head == NULL)
    {
        printf("List is already empty\n");
        return;
    }

    D_NODE* temp = *head;
    *head = (*head)->next;
    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }
    free(temp);
}

void del_at_end(D_NODE** head)
{
    if (*head == NULL)
    {
        printf("List is already empty\n");
        return;
    }

    D_NODE* ptr = *head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    if (ptr->prev != NULL)
    {
        ptr->prev->next = NULL;
    }
    else
    {
        *head = NULL;
    }
    free(ptr);
}

void del_at_pos(D_NODE** head, int pos)
{
    if (*head == NULL)
    {
        printf("List is already empty\n");
        return;
    }

    if (pos == 1)
    {
        del_beg(head);
        return;
    }

    D_NODE* ptr = *head;
    int count = 1;
    while (count < pos && ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }

    if (ptr == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    if (ptr->next != NULL)
    {
        ptr->next->prev = ptr->prev;
    }
    ptr->prev->next = ptr->next;
    free(ptr);
}

void print_data(D_NODE* head)
{
    D_NODE* ptr = head;
    int count = 1;

    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }

    printf("NO\tID\t\tNAME\t\tMARKS\n");
    while (ptr != NULL)
    {
        printf("%d\t%d\t\t%s\t\t%d\n", count, ptr->ID, ptr->name, ptr->mark);
        ptr = ptr->next;
        count++;
    }
}

void swap_nodes(D_NODE** head, D_NODE* node1, D_NODE* node2)
{
    if ((node1 == NULL) || (node2 == NULL))
    {
        printf("Khong ton tai node\n");
    }
    // Kiểm tra xem node1 và node2 có liền kề không
    if ((node1->next == node2 && node2->prev == node1)||(node2->next==node1 && node1->prev==node2))
    {
        
        node1->next = node2->next;
        node2->prev = node1->prev;
        node2->next = node1;
        node1->prev = node2;

        // Kiểm tra xem node1 có là head không
        if (node2->prev==NULL)
        {
            *head = node2;
        }
        else
        {
            node2->prev->next = node2;
        }

        // Kiểm tra xem node2 có là tail không
        if (node1->next != NULL)
        {
            node1->next->prev = node1;
        }

        
    }
    else
    {
        // Điều chỉnh con trỏ prev và next của node1
        if (node1->prev != NULL)
        {
            node1->prev->next = node2;
        }
        else
        {
            *head = node2;
        }

        if (node1->next != NULL)
        {
            node1->next->prev = node2;
        }

        // Điều chỉnh con trỏ prev và next của node2
        if (node2->prev != NULL)
        {
            node2->prev->next = node1;
        }
        else
        {
            *head = node1;
        }

        if (node2->next != NULL)
        {
            node2->next->prev = node1;
        }

        // Điều chỉnh con trỏ prev và next của node1 và node2
        D_NODE* temp_prev = node1->prev;
        node1->prev = node2->prev;
        node2->prev = temp_prev;

        D_NODE* temp_next = node1->next;
        node1->next = node2->next;
        node2->next = temp_next;
    }
}





void display(D_NODE** head, D_NODE* ptr, int count)
{
    int choice = -1;

    while (choice != 0)
    {
        printf("----------------\n");
        printf("Update         1\n");
        printf("Delete         2\n");
        printf("Insert         3\n");
        printf("Quit           0\n");

        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("\n");
        system("cls");

        switch (choice)
        {
        case 1:
            printf("Please enter new values:\n");
            printf("ID: ");
            scanf("%d", &(ptr->ID));
            printf("Name: ");
            scanf("%s", ptr->name);
            printf("Mark: ");
            scanf("%d", &(ptr->mark));
            break;
        case 2:
        {
            del_at_pos(head, count);
            printf("Deleted!\n");
            break;
        }
        case 3:
        {
            D_NODE* temp = (D_NODE*)malloc(sizeof(D_NODE));
            D_NODE* ptr2 = ptr;
            printf("Please enter value of ID: ");
            scanf("%d", &(temp->ID));
            printf("Please enter value of name: ");
            scanf("%s", (temp->name));
            printf("Please enter value of mark: ");
            scanf("%d", &(temp->mark));
            ptr2 = ptr->next;
            ptr->next = temp;
            temp->prev = ptr;
            temp->next = ptr2;
            if (ptr2 != NULL)
            {
                ptr2->prev = temp;
            }
        }
        case 0:
            break;
        }
    }
}

void moveptr(D_NODE** head)
{
    print_data(*head);
    D_NODE* ptr = *head;
    int count = 1;
    char ch = '1';

    while (ch != '0')
    {
        printf("Choice 0 to out ");
        printf("\n");
        ch = _getch();
        

        if (ch == '-')
        {
            system("cls");
            if (ptr->prev != NULL)
            {
                ptr = ptr->prev;
                count--;
                printf("%d\t%d\t\t%s\t\t%d\n", count, ptr->ID, ptr->name, ptr->mark);
            }
        }

        if (ch == '+')
        {
            system("cls");
            if (ptr->next != NULL)
            {
                ptr = ptr->next;
                count++;
                printf("%d\t%d\t\t%s\t\t%d\n", count, ptr->ID, ptr->name, ptr->mark);
            }
        }

        if (ch == '1')
        {
            display(head, ptr, count);
        }
    }
}

void sort_name(D_NODE** head)
{
    if (*head == NULL)
    {
        printf("Empty data\n");
        return;
    }
    int choice = -1;
    printf("Sort to name               1\n");
    printf("Sort to mark               2\n");
    printf("Quit                       0\n");
    printf("Please choice type to sort :  ");
    scanf("%d", &choice);
    printf("\n");
    if (choice == 0)
    {
        system("cls");
        return;
    }

    int swapped;
    D_NODE* temp;
    D_NODE* ptr = NULL;
   
    
    
    do
    {
        swapped = 0;
        temp = *head;

        while (temp->next != ptr)
        {
            if (choice == 1)
            {
                if (strcmp(temp->name, temp->next->name) > 0)
                {
                    swap_nodes(head, temp, temp->next);
                    swapped = 1;
                }
                else
                {
                    temp = temp->next;
                }
            }

            if (choice == 2)
            {
                if (temp->mark < temp->next->mark)
                {
                    swap_nodes(head, temp, temp->next);
                    swapped = 1;
                }
                else
                {
                    temp = temp->next;
                }
            }
            
            
        }

        ptr = temp;
    } while (swapped);
    system("cls");
    printf("Sorted!\n");
}



void thanks()
{
    printf("Goodbye\n");
}
