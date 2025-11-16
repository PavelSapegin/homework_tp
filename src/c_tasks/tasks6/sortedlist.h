#pragma once
#include <stdio.h>
#include <stdlib.h>


typedef struct list
{
    int data;
    struct list *next;
} list;



void print(list ** start);
void append(list **start, int new_val);
void delet(list **start, int val);
void spaces();
void menu();


int run_tests();

