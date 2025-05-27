#include "Inverted.h"
#include<string.h>
#include<stdlib.h>
Status read_and_validate_arguments(char* argv[],int argc,Slist** head)
{
    //printf("%d\n",argc);
    int flag = 0;
    for(int i=1;i<argc;i++)
    {
        if(strstr(argv[i],".txt")==NULL)
        {
            printf("%s is not an valid argument\n",argv[i]);
            flag++;
            continue;
        }
        //printf(".txt success\n");
        FILE* fptr = fopen(argv[i],"r");
        if(fptr==NULL)
        {
            printf("ERROR: No file name %s\n",argv[i]);
            flag++;
            continue;
        }
       // printf("file opened success\n");
        fseek(fptr,0,SEEK_END);
        unsigned long int set = ftell(fptr);
        if(set==0)
        {
            printf("File opened but there is no data in %s\n",argv[i]);
            flag++;
            continue;
        }
        //printf("empty\n");
        printf("\033[0;31mFILE NAME\033[0m: %s is a valid FILE\n",argv[i]);
        if(*head==NULL)
        {
            Slist* new = (Slist*)malloc(sizeof(Slist));
            new->link = NULL;
            strcpy(new->file_name,argv[i]);
            *head = new;
        }
        else{
                Slist* temp = *head;
                Slist* prev = NULL;
                int flag1=0;
                while(temp!=NULL)
                {
                    if(strcmp(temp->file_name,argv[i])==0)
                    {
                        printf("the file %s is a duplicate file\n",argv[i]);
                        flag1=1;
                        break;
                    }
                    prev = temp;
                    temp=temp->link;
                }
                if(flag1==1)
                {
                    flag++;
                   continue;
                }
                Slist* new = (Slist*)malloc(sizeof(Slist));
                new->link = NULL;
                strcpy(new->file_name,argv[i]);
                prev->link = new;
            }


    }
    if(flag == argc-1)
    {
        printf("\033[0;31mERROR: No files are valid files\n\033[0m");
        return FAILURE;
    }
    return SUCCESS;
}