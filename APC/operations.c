#include "apc.h"
#include<string.h>
#include<stdlib.h>
Status read_and_validate_args(char* argv[])
{
    int flag =0;
    if(argv[1][0]=='-')
    {
        flag = 1;
    }
    if (flag ==0)
    {
        int i=0;
        while(argv[1][i])
        {
            if(argv[1][i]>='0' && argv[1][i] <= '9')
            {
                i++;
            }
            else
            {
                printf("ERROR: Enter valid arguments\n");
                return FAILURE;
            }
        }
    }
    else
    {
        int i=1;
        while(argv[1][i])
        {
            if(argv[1][i]>='0' && argv[1][i] <= '9')
            {
                i++;
            }
            else
            {
                printf("ERROR: Enter valid arguments\n");
                return FAILURE;
            }
        }
    }
    flag =0;
    if(argv[3][0]=='-')
    {
        flag = 1;
    }
    if (flag ==0)
    {
        int i=0;
        while(argv[3][i])
        {
            if(argv[3][i]>='0' && argv[3][i] <= '9')
            {
                i++;
            }
            else
            {
                printf("ERROR: Enter valid arguments\n");
                return FAILURE;
            }
        }
    }
    else
    {
        int i=1;
        while(argv[3][i])
        {
            if(argv[3][i]>='0' && argv[3][i] <= '9')
            {
                i++;
            }
            else
            {
                printf("ERROR: Enter valid arguments\n");
                return FAILURE;
            }
        }
    }
    return SUCCESS;
}
Status store_operands_to_list(char* str,char* str1,Dlist** head1,Dlist** tail1,Dlist** head2,Dlist** tail2)
{
    int flag =0;
    if(str[0]=='-')
    {
        flag = 1;
    }
    if(flag==0)
    {
        int i=0;
        while(str[i])
        {
            int num = str[i] - 48;
            Dlist* new = (Dlist*)malloc(sizeof(Dlist));
            new->data = num;
            new->next = NULL;
            new->prev = NULL;
            if(*head1==NULL)
            {
                *head1 = new;
                *tail1 = new;
                i++;
            }
            else{
                (*tail1)->next = new;
                new->prev = *tail1;
                *tail1 = new;
                i++;
            }
        }
    }
    else
    {
        int i=1;
        while(str[i])
        {
            int num = str[i] - 48;
            Dlist* new = (Dlist*)malloc(sizeof(Dlist));
            new->data = num;
            new->next = NULL;
            new->prev = NULL;
            if(*head1==NULL)
            {
                *head1 = new;
                *tail1 = new;
                i++;
            }
            else{
                (*tail1)->next = new;
                new->prev = *tail1;
                *tail1 = new;
                i++;
            }
        }
    }
    flag = 0;
    if(str1[0]=='-')
    {
        flag = 1;
    }
    if(flag==0)
    {
        int i=0;
        while(str1[i])
        {
            int num = str1[i] - 48;
            Dlist* new = (Dlist*)malloc(sizeof(Dlist));
            new->data = num;
            new->next = NULL;
            new->prev = NULL;
            if(*head2==NULL)
            {
                *head2 = new;
                *tail2 = new;
                i++;
            }
            else{
            (*tail2)->next = new;
            new->prev = *tail2;
            *tail2 = new;
            i++;
            }
        }
    }
    else
    {
        
        int i=1;
        while(str1[i])
        {
            int num = str1[i] - 48;
            Dlist* new = (Dlist*)malloc(sizeof(Dlist));
            new->data = num;
            new->next = NULL;
            new->prev = NULL;
            if(*head2==NULL)
            {
                *head2 = new;
                *tail2 = new;
                i++;
            }
            else{
            (*tail2)->next = new;
            new->prev = *tail2;
            *tail2 = new;
            i++;
            }
        }
    }
    return SUCCESS;
}