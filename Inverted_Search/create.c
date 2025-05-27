#include "Inverted.h"
#include<stdlib.h>
#include<string.h>
int check_word(char* file_name,Sub* temp1,Sub** prev)
{
    while(temp1 != NULL)
    {
        if(strcmp(file_name,temp1->file_name)==0)
        {
            return 0;
        }
        *prev = temp1;
        temp1 = temp1->sub_link;
    }
    return 1;
}
void insert_into_hash_table(Table* table,int index,char* word,char* file_name)
{
                Main* new = (Main*)malloc(sizeof(Main));
                Sub* sub_new = (Sub*)malloc(sizeof(Sub));
                table[index].main_link = new;
                new->file_count = 1;
                new->main_link = NULL;
                new->sub_link = sub_new;
                strcpy(new->word,word);
                sub_new->word_count=1;
                sub_new->sub_link = NULL;
                strcpy(sub_new->file_name,file_name);
}
void create_database(Slist* head,Table* table)
{
    Slist* temp = head;
    //Table* tab = table;
    while(temp!=NULL)
    {
        char word[20];
        FILE* fptr = fopen(temp->file_name,"r");
        while(fscanf(fptr,"%s",word)!=EOF)
        {
            int number = 0;
            if(word[0]>='A' && word[0]<='Z')
            {
                word[0] = word[0] + 32;
            }
            else if(word[0] >= '0' && word[0]<='9')
            {
                number = 1;
            }
            else if(word[0]>='a' && word[0]<='z')
            {
                number = 0;
            }
            else{
                number = 1;
            }
            int index;
            if(number == 0)
            {
                index = word[0] % 97;
            }
            else{
                index = 26;
            }
            if(table[index].main_link==NULL)
            {
                insert_into_hash_table(table,index,word,temp->file_name);
            }
            else
            {
                Main* main = table[index].main_link;
                Main* prev = NULL;
                int flag =0;
                while(main != NULL)
                {
                    if(strcmp(main->word,word)==0)
                    {
                        Sub* sub = main->sub_link;
                        Sub* sub_prev = NULL;
                        int res = check_word(temp->file_name,sub,&sub_prev);
                        if(res == 0)
                        {
                            sub->word_count++;
                            flag = 1;
                            break;
                        }
                        else
                        {
                            Sub* new_sub = (Sub*)malloc(sizeof(Sub));
                            sub_prev->sub_link = new_sub;
                            strcpy(new_sub->file_name,temp->file_name);
                            new_sub->sub_link = NULL;
                            main->file_count++;
                            new_sub->word_count = 1;
                            flag = 1;
                            break;
                        }
                    }
                    prev = main;
                    main = main->main_link;
                }
                if(flag == 0)
                {
                    Main* main_node = (Main*)malloc(sizeof(Main));
                    prev->main_link = main_node;
                    Sub* sub_new = (Sub*)malloc(sizeof(Sub));
                    main_node->file_count = 1;
                    main_node->main_link = NULL;
                    main_node->sub_link = sub_new;
                    strcpy(main_node->word,word);
                    sub_new->word_count=1;
                    sub_new->sub_link = NULL;
                    strcpy(sub_new->file_name,temp->file_name);

                }
            }
        }
        printf("\033[0;33mINFO : Successfully created database for %s\n\033[0;m",temp->file_name);
        fclose(fptr);
        temp = temp->link;

    }
    printf("\033[0;32mSUCCESS: DataBase Created Successfully\033[0m\n");
}