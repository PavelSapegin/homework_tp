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
void delete(list **start, int val);
void menu();
void free_list(list **start);

int run_tests();
