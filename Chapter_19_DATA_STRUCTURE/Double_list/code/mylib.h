#pragma once
#ifndef MYLIB_H
#define MYLIB_H


typedef struct d_node
{
    struct d_node* prev;
    int ID;
    char name[10];
    int mark;
    struct d_node* next;
} D_NODE;

void add_at_end(D_NODE** head);
void add_beg(D_NODE** head);
void add_at_pos(D_NODE** head);
void del_beg(D_NODE** head);
void del_at_end(D_NODE** head);
void del_at_pos(D_NODE** head, int pos);
void print_data(D_NODE* head);
void swap_nodes(D_NODE** head, D_NODE* node1, D_NODE* node2);
void sort_name(D_NODE** head);
void display(D_NODE** head, D_NODE* ptr,int count);
void moveptr(D_NODE** head);
void take_data(D_NODE**head,FILE** fp);
void export_data(D_NODE** head, FILE** fp);
void export_data_as(D_NODE** head, FILE** fp);
void search_name(D_NODE** head);
void same_name(D_NODE** head);

void thanks();

#endif  /* MYLIB_H */
