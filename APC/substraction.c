#include "apc.h"
#include<stdlib.h>
#include<string.h>
int sub_insert_first(Dlist **head, Dlist **tail, int data)
{
    if(*head == NULL)
    {
        Dlist* temp = (Dlist*)malloc(sizeof(Dlist));
        temp->data = data;
        temp->prev = NULL;
        temp->next = NULL;
        *head = temp;
        *tail = temp;
        return SUCCESS;
    }
    else
    {
        Dlist* temp = (Dlist*)malloc(sizeof(Dlist));
        temp->data = data;
        temp->prev = NULL;
        temp->next = NULL;
        temp->next = *head;
        (*head)->prev = temp;
        *head = temp;
        return SUCCESS;
    }
    return FAILURE;
    
}
void print_substraction_list(Dlist *head)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%d", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
	    }
    }
    printf("\n");
}
void sub_addition(Dlist** head1,Dlist** tail1,Dlist** head2,Dlist** tail2,Dlist** headR,Dlist** tailR,char* argv[])
{
        char ch = argv[1][0];
        char ch1 = argv[3][0];
        if(ch=='-')
        {
            printf("-");
        }    
        Dlist* temp = *tail1;
        Dlist* temp2 = *tail2;
        int carry=0,data;
        while(temp != NULL || temp2 != NULL)
        {
            int num1=0,num2=0;
            data=0;
            if(temp!=NULL)
            {
                num1 = temp->data;
            }
            if(temp2!=NULL)
            {
                num2 = temp2->data;
            }
            int sum = num1 + num2 + carry;
            carry = sum/10;
            data = sum%10;
            sub_insert_first(headR,tailR,data);
            if(temp!=NULL)
            {
                temp=temp->prev;
            }
            if(temp2!=NULL)
            {
                temp2=temp2->prev;
            }
        }
        if(carry>0)
        {
            sub_insert_first(headR,tailR,carry);
        }
        print_substraction_list(*headR);
}


int dl_sub_insert_first(Dlist **head, Dlist **tail, int data)
{
    if(*head == NULL)
    {
        Dlist* temp = (Dlist*)malloc(sizeof(Dlist));
        temp->data = data;
        temp->prev = NULL;
        temp->next = NULL;
        *head = temp;
        *tail = temp;
        return SUCCESS;
    }
    else
    {
        Dlist* temp = (Dlist*)malloc(sizeof(Dlist));
        temp->data = data;
        temp->prev = NULL;
        temp->next = NULL;
        temp->next = *head;
        (*head)->prev = temp;
        *head = temp;
        return SUCCESS;
    }
    return FAILURE;
    
}
void print_sub_list(Dlist *head)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    while (head->next!=NULL)		
	    {
                if(head->data!=0)
                {
                    break;
                }   
		    head = head -> next;
	    }
        while(head)
        {
           printf("%d", head -> data);
           head = head->next; 
        }
    }
    printf("\n");
}
int check_sub_symbol(char* argv[],int* temp)
{
    char ch = argv[1][0];
    char ch1 = argv[3][0];
    if(ch == '-' && ch1 =='-')
    {
        int len = strlen(argv[1])-1;
        int len1 = strlen(argv[3])-1;
        *temp = 1;
        return 0;
    }
    else if(ch=='-' || ch1=='-')
    {
        return 1;
    }
    return 0;
}
void substraction(Dlist** head1,Dlist** tail1,Dlist** head2,Dlist** tail2,Dlist** headR,Dlist** tailR,char* argv[])
{
    int check = 0;
    int res = check_sub_symbol(argv,&check);
    if(res ==0)
    {
        Dlist* temp = *tail1;
        Dlist* temp2 = *tail2;
        int carry=0,data;
        int len1 = strlen(argv[1]);
        int len2 = strlen(argv[3]);
        int max = 0;
        if(check == 1)
        {
            max = 0;
            len1 = len1-1;
            len2 = len2-1;
            if(len1 > len2)
            {
                max=0;
            }
            else if(len2 > len1)
            {
                max =1;
            }
            else
            {
                int i=1;
                while(argv[1][i])
                        {
                            if(argv[1][i] < argv[3][i])
                            {
                                max = 1;
                                break;
                            }
                            else if(argv[1][i] > argv[3][i])
                            {
                                break;
                            }
                            i++;
                        }
            }
            if(max == 0)
            {
                //printf("HII\n");
                while(temp != NULL || temp2 != NULL)
                {
                    int num1=0,num2=0;
                    data=0;
                    if(temp!=NULL)
                    {
                        num1 = temp->data;
                    }
                    if(temp2!=NULL)
                    {
                        num2 = temp2->data;
                    }
                    int sum = num1 + carry - num2;
                    if(sum < 0)
                    {
                        data = num1 + carry + 10 - num2;
                        //printf("data--->%d\n",data);
                        carry = -1;
                    }
                    else{
                        data = sum;
                        carry = 0;
                    }
                    dl_sub_insert_first(headR,tailR,data);
                    if(temp!=NULL)
                    {
                        temp=temp->prev;
                    }
                    if(temp2!=NULL)
                    {
                        temp2=temp2->prev;
                    }
                }
                printf("-");
                print_sub_list(*headR);
            }
            else
            {
                while(temp != NULL || temp2 != NULL)
                {
                    int num1=0,num2=0;
                    data=0;
                    if(temp!=NULL)
                    {
                        num1 = temp->data;
                    }
                    if(temp2!=NULL)
                    {
                        num2 = temp2->data;
                    }
                    int sum = num2 + carry - num1;
                    if(sum < 0)
                    {
                        data = num2 + carry + 10 - num1;
                        //printf("data--->%d\n",data);
                        carry = -1;
                    }
                    else{
                        data = sum;
                        carry = 0;
                    }
                    dl_sub_insert_first(headR,tailR,data);
                    if(temp!=NULL)
                    {
                        temp=temp->prev;
                    }
                    if(temp2!=NULL)
                    {
                        temp2=temp2->prev;
                    }
                }
                //printf("-");
                print_sub_list(*headR);
            }

        }
        else
        {
                    if(len2 > len1)
                    {
                        max = 1;
                    }
                    else if(len1 > len2)
                    {
                        max = 0;
                    }
                    else
                    {
                        int i=0;
                        while(argv[1][i])
                        {
                            if(argv[1][i] < argv[3][i])
                            {
                                max = 1;
                                break;
                            }
                            else if(argv[1][i] > argv[3][i])
                            {
                                break;
                            }
                            i++;
                        }
                    }
            if(max == 0)
            {
                //printf("HII\n");
                while(temp != NULL || temp2 != NULL)
                {
                    int num1=0,num2=0;
                    data=0;
                    if(temp!=NULL)
                    {
                        num1 = temp->data;
                    }
                    if(temp2!=NULL)
                    {
                        num2 = temp2->data;
                    }
                    int sum = num1 + carry - num2;
                    if(sum < 0)
                    {
                        data = num1 + carry + 10 - num2;
                        //printf("data--->%d\n",data);
                        carry = -1;
                    }
                    else{
                        data = sum;
                        carry = 0;
                    }
                    dl_sub_insert_first(headR,tailR,data);
                    if(temp!=NULL)
                    {
                        temp=temp->prev;
                    }
                    if(temp2!=NULL)
                    {
                        temp2=temp2->prev;
                    }
                }
                print_sub_list(*headR);
            }
            else
            {
                while(temp != NULL || temp2 != NULL)
                {
                    int num1=0,num2=0;
                    data=0;
                    if(temp!=NULL)
                    {
                        num1 = temp->data;
                    }
                    if(temp2!=NULL)
                    {
                        num2 = temp2->data;
                    }
                    int sum = num2 + carry - num1;
                    if(sum < 0)
                    {
                        data = num2 + carry + 10 - num1;
                        //printf("data--->%d\n",data);
                        carry = -1;
                    }
                    else{
                        data = sum;
                        carry = 0;
                    }
                    dl_sub_insert_first(headR,tailR,data);
                    if(temp!=NULL)
                    {
                        temp=temp->prev;
                    }
                    if(temp2!=NULL)
                    {
                        temp2=temp2->prev;
                    }
                }
                printf("-");
                print_sub_list(*headR);
            }
        }
    }
    else
    {
        sub_addition(head1,tail1,head2,tail2,headR,tailR,argv);
    }
}
