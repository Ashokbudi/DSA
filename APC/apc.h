#ifndef APC_H
#define APC_H
#include<stdio.h>
#include "check.h"
typedef struct doubleLL
{
    int data;
    struct doubleLL* prev;
    struct doubleLL* next;
}Dlist;
Status read_and_validate_args(char* argv[]);
Status store_operands_to_list(char* str,char* str1,Dlist** head1,Dlist** tail1,Dlist** head2,Dlist** tail2);
void addition(Dlist** head1,Dlist** tail1,Dlist** head2,Dlist** tail2,Dlist** headR,Dlist** tailR,char* argv[]);
void substraction(Dlist** head1,Dlist** tail1,Dlist** head2,Dlist** tail2,Dlist** headR,Dlist** tailR,char* argv[]);
void multiplication(Dlist** head1,Dlist** tail1,Dlist** head2,Dlist** tail2,Dlist** headR,Dlist** tailR,char* argv[]);
void divison(Dlist** head1,Dlist** tail1,Dlist** head2,Dlist** tail2,Dlist** headR,Dlist** tailR,char* argv[]);
#endif
