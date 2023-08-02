#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "MYLIB.H"


int main()
{
    FILE* fp = NULL;
    D_NODE* head = NULL;
    //take_data(&head,&fp);
    

    // Function pointers for add and delete operations
    void (*add[3])(D_NODE**);
    add[0] = add_at_end;
    add[1] = add_beg;
    add[2] = add_at_pos;

    // Function pointer for delete operation
    void (*del[2])(D_NODE**);
    del[0] = del_at_end;
    del[1] = del_beg;


    // Exit handler
    atexit(thanks);

    int choice;
    while (1)
    {
        
        printf("\n-----------------\n");
        printf("Add               1\n");
        printf("Print data        2\n");
        printf("Delete data       3\n");
        printf("Adjust            4\n");
        printf("Sort data         5\n");
        printf("Open data         6\n");
        printf("Save data         7\n");
        printf("Save as data      8\n");
        printf("Search name       9\n");
        printf("Count same name   10\n");
        printf("Exit              0\n");
        printf("-------------------\n");
        printf("Please choose an option: ");
        scanf("%d", &choice);
        system("cls");

        switch (choice)
        {
        case 1:
        {
            int addChoice = -1;
            while (addChoice != 0)
            {
                printf("\n-----------------\n");
                printf("Add at end        1\n");
                printf("Add at beginning  2\n");
                printf("Add at position   3\n");
                printf("Exit              0\n");
                printf("\n-----------------\n");
                printf("Please choose an option: ");
                scanf("%d", &addChoice);
                if (addChoice != 0)
                {
                    add[addChoice - 1](&head);
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
            int delChoice = -1;
            while (delChoice != 0)
            {
                printf("\n---------------------\n");
                printf("Delete at end         1\n");
                printf("Delete at beginning   2\n");
                printf("Exit                  0\n");
                printf("\n---------------------\n");
                printf("Please choose an option: ");
                scanf("%d", &delChoice);
                if (delChoice != 0)
                {
                    del[delChoice - 1](&head);
                }
                system("cls");
            }
            break;
        }
        case 4:
            moveptr(&head);
            system("cls");
            break;
        case 5:
            system("cls");
            sort_name(&head);
             break;
        case 6:
            take_data(&head, &fp);
            break;
        case 7:
            export_data(&head, &fp);
            break;
        case 8:
            export_data_as(&head, &fp);
            break;
        case 9:
            search_name(&head);
            break;
        case 10:
            same_name(&head);
            break;            
        case 0:
            exit(EXIT_SUCCESS);
            break;
        }
    }

    return 0;
}
