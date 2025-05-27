#include "apc.h"
#include<stdlib.h>
#include<string.h>
int dl_delete_list(Dlist **head, Dlist **tail)
{
    if(*head == NULL)
    {
        return FAILURE;
    }
    Dlist* temp = NULL;
    while(*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
int dl_mul_insert_first(Dlist **head, Dlist **tail, int data)
{
    //printf("inserting\n");
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
void addition_mul(Dlist** head1,Dlist** tail1,Dlist** head2,Dlist** tail2,Dlist** headR,Dlist** tailR)
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
        dl_mul_insert_first(headR,tailR,data);
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
        dl_mul_insert_first(headR,tailR,carry);
    }
}
void print_mul_list(Dlist *head)
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
void multiplication(Dlist** head1,Dlist** tail1,Dlist** head2,Dlist** tail2,Dlist** headR,Dlist** tailR,char* argv[])
{
    Dlist* temp1 = *tail1;
    Dlist* temp2 = *tail2;
    Dlist* backup_head=NULL;
    Dlist* backup_tail=NULL;
    Dlist* Head = NULL;
    Dlist* Tail = NULL;
    char ch = argv[1][0];
    char ch1 = argv[3][0];
    int carry=0;
    int count=0;
    while(temp2 != NULL)
    {
        int data = 0;
        carry=0;
        temp1 = *tail1;
        for(int i=0;i<count;i++)
        {
            dl_mul_insert_first(&Head,&Tail,0);
        }
        while(temp1 != NULL)
        {
            int num1 = temp1->data;
            int num2 = temp2->data;
            int mul = num1 * num2 + carry;
            carry = mul / 10;
            data = mul % 10;
            
            if(count==0)
            {
                //printf("%d\n",data);
                dl_mul_insert_first(headR,tailR,data);
            }
            else
            {
                dl_mul_insert_first(&Head,&Tail,data);
            }
            temp1 = temp1->prev;
        }
        if(carry>0)
        {
            if(count==0)
            {
                dl_mul_insert_first(headR,tailR,carry);
            }
            else{
                dl_mul_insert_first(&Head,&Tail,carry);
            }
        }
        if(count != 0)
        {
            addition_mul(headR,tailR,&Head,&Tail,&backup_head,&backup_tail);
            dl_delete_list(headR,tailR);
            dl_delete_list(&Head,&Tail);
            *headR = backup_head;
            *tailR = backup_tail;
            backup_head = NULL;
            backup_tail = NULL;
        }
        count++;
        temp2=temp2->prev;
        //printf("HII\n");
    }
    if(ch=='-' && ch1=='-')
    {

    }
    else if(ch=='-' || ch1=='-')
    {
        printf("-");
    }
    print_mul_list(*headR);

}