#include "apc.h"
#include<stdlib.h>
#include<string.h>
int dl_sub_add_insert_first(Dlist **head, Dlist **tail, int data)
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
void print_sub_add_list(Dlist *head)
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
		    /* Printing the list */
		    //printf("%d", head -> data);

		    /* Travering in forward direction */
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
void add_substraction(Dlist** head1,Dlist** tail1,Dlist** head2,Dlist** tail2,Dlist** headR,Dlist** tailR,char* argv[])
{
    Dlist* temp = *tail1;
    Dlist* temp2 = *tail2;
    int carry=0,data;
    char ch = argv[1][0];
    char ch1 = argv[3][0];
    int len1 = strlen(argv[1]);
    int len2 = strlen(argv[3]);
    if(ch == '-')
    {
        len1 = len1-1;
    }
    if(ch1=='-')
    {
        len2 = len2 -1;
    }
    int max = 0;
    if(len2 > len1 && ch1 == '-')
    {
        printf("-");
        max = 1;
    }
    else if(len2 > len1 && ch=='-')
    {
        max = 1;
    }
    else if(len1 > len2 && ch=='-')
    {
        printf("-");
        max = 0;
    }
    else if(len1 > len2 && ch1=='-' )
    {
        printf("-");
        max =0;
    }
    else
    {
        if(ch=='-')
        {
            int i=1;
            int j = 0;
            while(argv[1][i])
            {
                if(argv[1][i] < argv[3][j] && ch1=='-')
                {
                    printf("-");
                    max = 1;
                    break;
                }
                else if(argv[1][i] < argv[3][j] &&ch=='-')
                {
                    max = 1;
                    break;
                }
                else if(argv[1][i] > argv[3][j] && ch=='-')
                {
                    printf("-");
                    max = 0;
                }
                else if(argv[1][i] > argv[3][j] && ch1=='-')
                {
                    max = 1;
                }
                i++;
                j++;
            }
        }
        else
        {
            int i=0;
            int j = 1;
            while(argv[3][j])
            {
                if(argv[1][i] < argv[3][j] && ch1=='-')
                {
                    printf("-");
                    max = 1;
                    break;
                }
                else if(argv[1][i] < argv[3][j] &&ch=='-')
                {
                    max = 1;
                    break;
                }
                else if(argv[1][i] > argv[3][j] && ch=='-')
                {
                    printf("-");
                    max = 0;
                }
                else if(argv[1][i] > argv[3][j] && ch1=='-')
                {
                    max = 0;
                    break;
                }
                i++;
                j++;
            }
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
            dl_sub_add_insert_first(headR,tailR,data);
            if(temp!=NULL)
            {
                temp=temp->prev;
            }
            if(temp2!=NULL)
            {
                temp2=temp2->prev;
            }
        }
        print_sub_add_list(*headR);
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
            dl_sub_add_insert_first(headR,tailR,data);
            if(temp!=NULL)
            {
                temp=temp->prev;
            }
            if(temp2!=NULL)
            {
                temp2=temp2->prev;
            }
        }
        print_sub_add_list(*headR);
    }
}
int dl_insert_first(Dlist **head, Dlist **tail, int data)
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
void print_list(Dlist *head)
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
int check_symbol(char* argv[])
{
    char ch = argv[1][0];
    char ch1 = argv[3][0];
    if(ch=='-' && ch1=='-')
    {
        printf("-");
        return 0;
    }
    if(ch=='-' || ch1=='-')
    {
        return 1;
    }
    return 0;
}
void addition(Dlist** head1,Dlist** tail1,Dlist** head2,Dlist** tail2,Dlist** headR,Dlist** tailR,char* argv[])
{
    int res = check_symbol(argv);
    if(res==0)
    {
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
            dl_insert_first(headR,tailR,data);
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
            dl_insert_first(headR,tailR,carry);
        }
        print_list(*headR);
    }
    else
    {
        add_substraction(head1,tail1,head2,tail2,headR,tailR,argv);
    }
}

