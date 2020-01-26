#include<stdio.h>
#include<malloc.h>
#include"QuadraticProbing.h"
struct Record *HashTable[10];
struct Record *DummyItem;
//when we create array of structure automatically each of array index is assigned with Null
//as no memory is allocated to the Array of structure

void display()
{
	for (int i = 0; i < 10; i++)
	{
		if (HashTable[i] != NULL)
		{
			printf("\nFor %d\n", i);
			printf("Item Key : %d", HashTable[i]->key);
			printf("Item value : %d", HashTable[i]->value);
		}
		else
		{
			printf("\nRecord %d is empty", i);

		}
	}
}

void insert(int key, int value)
{
	struct Record *item = (struct Record*)malloc(sizeof(Record));
	item->key = key;
	item->value = value;
	int j = 0;
	int hashindex = HashFunction(key);
	int h1 = hashindex;
	while (HashTable[hashindex] != NULL && HashTable[hashindex]->key != -1)
	{
		j++;
		hashindex = (h1 + j*j)%10;
		
	}
	HashTable[hashindex] = item;

}
int HashFunction(int key)
{
	return key % 10;
}

int main()
{

	DummyItem = (struct Record*)malloc(sizeof(Record));
	DummyItem->key = -1;
	DummyItem->value = -1;
	int k = 0, v = 0;
	int ch = 0;
	char choice = '\0';

	do
	{
		printf("\nHash Table with Quadratic probing");
		printf("\n1.Insert");
		printf("\n2.Display");
		printf("\nEnter the 1/2 :");
		scanf_s("%d", &ch);

		switch (ch)
		{
		case 1:
			printf("Enter key:");
			scanf_s("%d", &k);
			printf("Enter value:");
			scanf_s("%d", &v);
			insert(k, v);
			break;
		case 2: display();
			break;
		default:
			break;
		}
		printf("\nContinue? y/n");
		scanf_s("%c", &choice, 1);
		scanf_s("%c", &choice, 1);



	} while (choice == 'y' || choice == 'Y');






	system("pause");
	return 0;
}