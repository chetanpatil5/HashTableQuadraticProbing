#pragma once
#pragma once
#include<stdio.h>

typedef struct Record
{
	int key;
	int value;
}Record;

void insert(int key, int value);
int HashFunction(int key);