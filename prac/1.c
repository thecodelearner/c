#include <stdio.h>

void insertion (int a[10], int n);
void deletion (int a[10], int n);

void main()
{
	int a[10], n, i, ch;

	printf("Enter number of elements in the array\t:");
	scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; ++i)
    {
    	printf("a[%d] = ",i);
    	scanf("%d", &a[i]);
    }

    do
    {
    	printf("Menu\n");
    	printf("1. insertion\n");
    	printf("2. deletion\n");
    	printf("1 or 2 ?\t:");
    	scanf("%d", &ch);

    	switch(ch)
    	{
    		case 1: insertion(a, n);
    		break;
    		case 2: deletion(a, n);
    		break;
    	}
    } while (ch < 3);
}


void insertion(int a[10], int n)
{
	int i, elem, pos;

	printf("Enter element to insert\t:");
	scanf("%d", &elem);

	printf("Enter it's position\t:");
	scanf("%d", &pos);

	for (i = n - 1; i > pos - 1; i--)
	{
		a[i+1] = a[i];
	}

	a[i-1] = elem;
	n++;

	printf("Array elements are:\n");
	for (i = 0; i < n; ++i)
	{
		printf("a[%d] = %d\n", i, a[i]);
	}
}

void deletion(int a[10], int n)
{
	int del_elem, i, pos;

	printf("Enter position of element to be deleted\t:");
	scanf("%d", &pos);

	printf("Element to be deleted\t: %d", a[pos]);

	for (i = pos - 1; i < n; ++i)
	{
		a[i] = a[i+1];
	}
	n--;

	printf("Array elements are:\n");
	for (i = 0; i < n; ++i)
	{
		printf("a[%d] = %d\n", i, a[i]);
	}
}