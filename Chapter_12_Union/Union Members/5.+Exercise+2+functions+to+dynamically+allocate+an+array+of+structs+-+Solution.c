#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//Made by Vlad. Budnitski.
//AlphaTech - Programming Course.

// Write 2 functions that allocate dynamically an array of employees
// and reading inputs for each of the elements from the user:
//		- The First function gets the size of the array, allocates memory, and
//		  returns the array.
//		- The Second function gets the size of the array, and allocates the 
//		  memory dynamically by updating it by "pointer" (function of void type)

typedef struct employee {
	char name[10];
	float age;
	int id;
}Employee;

// Solution Function #1
Employee* createEmployeesArray(int totalElements)
{
	Employee* employeesArr;
	int i;
	employeesArr = (Employee*)malloc(sizeof(Employee) * totalElements);
	for (i = 0; i < totalElements; i++)
	{
		printf("Enter a name for Employee #%d: ", i + 1);
		scanf("%s", &employeesArr[i].name); // &(employeeArr+i)->name
		printf("Enter the age for Employee #%d: ", i + 1);
		scanf("%f", &employeesArr[i].age);
		printf("Enter the id for Employee #%d: ", i + 1);
		scanf("%d", &employeesArr[i].id);
	}
	return employeesArr;
}

// Solution Function #2
void createEmployeesArray2(Employee **empPtr, int totalElements)
{
	Employee* employeesArr;
	int i;
	employeesArr = (Employee*)malloc(sizeof(Employee) * totalElements);
	for (i = 0; i < totalElements; i++)
	{
		printf("Enter a name for Employee #%d: ", i + 1);
		scanf("%s", &employeesArr[i].name); // &(employeeArr+i)->name
		printf("Enter the age for Employee #%d: ", i + 1);
		scanf("%f", &employeesArr[i].age);
		printf("Enter the id for Employee #%d: ", i + 1);
		scanf("%d", &employeesArr[i].id);
	}
	*empPtr = employeesArr;
}

int main()
{
	Employee* ptrArr;
	createEmployeesArray2(&ptrArr, 5);
}

