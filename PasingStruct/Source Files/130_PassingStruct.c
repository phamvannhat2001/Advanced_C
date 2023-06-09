#include <stdio.h>
#include <string.h>

typedef struct employee {
    char name[10];
    int age;
    int id;
} Employee;

Employee* increaseAge(Employee emptr)
{
    Employee* ptr = &emptr;
    ptr->age += 1;
    return ptr;
}

void printEmployee(Employee* emptr)
{
    printf("Employee name: %s\n", emptr->name);
    printf("Employee age: %d\n", emptr->age);
    printf("Employee id: %d\n", emptr->id);
}

int main()
{
    Employee employee1 = { "Nhat", 22, 1 };
    Employee* ptr;
    printEmployee(&employee1);
    ptr = increaseAge(employee1);
    printEmployee(ptr);
    return 0;
}
