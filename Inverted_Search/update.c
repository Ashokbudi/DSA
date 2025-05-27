#include "Inverted.h"
#include<string.h>
#include<stdlib.h>
int delete_node(Slist** head,char* file_name)
{
    Slist* temp = *head;
    Slist* prev = NULL;
    while(temp!=NULL)
    {
        if(strcmp(temp->file_name,file_name)==0)
        {
            if(prev==NULL)
            {
                *head = temp->link;
                free(temp);
                return 0;
            }
            prev->link = temp->link;
            free(temp);
            return 0;
        }
        prev = temp;
        temp = temp->link;
    }
    return 1;
}
Status update_database(Table* table,Slist** head,int* real)
{
    printf("Enter the file you want to upload: ");
    char file[15];
    getchar();
    scanf("%s",file);
        if(strstr(file,".txt")==NULL)
        {
            printf("%s is not an valid argument\n",file);
            *real=1;
            return FAILURE;
        }
        //printf(".txt success\n");
        //printf("%s\n",file);
        FILE* fptr = fopen(file,"r");
        if(fptr==NULL)
        {
            printf("ERROR: No file name %s\n",file);
            *real = 1;
            return FAILURE;
        }
       // printf("file opened success\n");
        char ch1;
        ch1 = fgetc(fptr);
        char ch2;
        fseek(fptr,-2,SEEK_END);
        ch2 = fgetc(fptr);
        rewind(fptr);
        if(ch1=='#' && ch2 == '#')
        {
            while(fscanf(fptr,"%c",&ch1)!=EOF)
            {
                char ind[3];
                for(int i=0;i<3;i++)
                {
                    ind[i] = '\0';
                }
                fscanf(fptr,"%[^;];",ind);
                int i = 0;
                int index=0;
                while(ind[i])
                {
                    index = index*10+(ind[i] - 48);
                    i++;
                }
                char word[20];
                fscanf(fptr,"%[^;];",word);
                char file_cnt[3];
                for(int i=0;i<3;i++)
                {
                    file_cnt[i] = '\0';
                }
                fscanf(fptr,"%[^;];",file_cnt);
                i = 0;
                int file_count=0;
                while(file_cnt[i])
                {
                    file_count = file_count*10+(file_cnt[i] - 48);
                    i++;
                }
                for(int i=0;i<file_count;i++)
                {
                    char file_name[20];
                    fscanf(fptr,"%[^;];",file_name);
                    char word_cnt[3];
                    for(int i=0;i<3;i++)
                    {
                        word_cnt[i] = '\0';
                    }
                    fscanf(fptr,"%[^;];",word_cnt);
                    int i = 0;
                    int word_count=0;
                    while(word_cnt[i])
                    {
                        word_count = word_count*10+(word_cnt[i] - 48);
                        i++;
                    }
                    if(table[index].main_link == NULL)
                    {
                        Main* new = (Main*)malloc(sizeof(Main));
                        Sub* sub_new = (Sub*)malloc(sizeof(Sub));
                        table[index].main_link = new;
                        new->file_count = file_count;
                        new->main_link = NULL;
                        new->sub_link = sub_new;
                        strcpy(new->word,word);
                        sub_new->word_count=word_count;
                        sub_new->sub_link = NULL;
                        strcpy(sub_new->file_name,file_name);
                    }
                    else
                    {
                        Main* main = table[index].main_link;
                        Main* prev = NULL;
                        int flag = 0;
                        while(main!=NULL)
                        {
                            if(strcmp(main->word,word)==0)
                            {
                                Sub* sub_node_link = (Sub*)malloc(sizeof(Sub));
                                sub_node_link->word_count = word_count;
                                strcpy(sub_node_link->file_name,file_name);
                                Sub* sub_nlink = main->sub_link;
                                Sub* prev = NULL;
                                while(sub_nlink!=NULL)
                                {
                                    prev = sub_nlink;
                                    sub_nlink = sub_nlink->sub_link;
                                }
                                if(prev == NULL)
                                {
                                    main->sub_link = sub_node_link;
                                }
                                else{
                                prev->sub_link = sub_node_link;
                                }
                                flag = 1;
                                break;

                            }
                            prev = main;
                            main=main->main_link;
                        }
                        if(flag==0)
                        {
                            Main* new = (Main*)malloc(sizeof(Main));
                            prev->main_link = new;
                            Sub* sub_new = (Sub*)malloc(sizeof(Sub));
                            new->file_count = file_count;
                            new->main_link = NULL;
                            new->sub_link = sub_new;
                            strcpy(new->word,word);
                            sub_new->word_count=word_count;
                            sub_new->sub_link = NULL;
                            strcpy(sub_new->file_name,file_name);
                        }

                    }
                }
                fseek(fptr,2,SEEK_CUR);
            }
        }
        else{
            printf("ERROR: thats not a valid file\n");
            *real =1;
            return FAILURE;
        }
        //return SUCCESS;
        Slist* temp = *head;
        while(temp!=NULL)
        {
            for(int i=0;i<27;i++)
            {
                if(table[i].main_link == NULL)
                {
                    continue;
                }
                Main* main = table[i].main_link;
                int main_flag = 0;
                while(main!=NULL)
                {
                    Sub* sub = main->sub_link;
                    int flag =0;
                    while(sub!=NULL)
                    {
                        
                        if(strcmp(sub->file_name,temp->file_name)==0)
                        {
                            delete_node(head,temp->file_name);
                            temp = *head;
                        }
                        sub = sub->sub_link;
                    }
                    main = main->main_link;
                }
            }
            temp = temp->link;
        }
        printf("\033[0;34mSUCCESS: Update Successfully done\033[0m\n");
    
}