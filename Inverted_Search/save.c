#include "Inverted.h"
#include<stdio.h>
#include<string.h>
void save_database(Table* table)
{
    int i=1;
    char file[40];
    while(i)
    {
        printf("Enter the file that you want to save: ");
        getchar();
        scanf("%s",file);
        if(strstr(file,".txt")!=NULL)
        {
            i=0;
        }
        else{
            printf("Enter valid file name\n");
        }
    }
    FILE* fptr = fopen(file,"w");
    for(int i=0;i<27;i++)
    {
        if(table[i].main_link == NULL)
        {
            continue;
        }
        Main* main = table[i].main_link;
        while(main!=NULL)
        {
            fprintf(fptr,"#%d;%s;%d",i,main->word,main->file_count);
            int count = main->file_count;
            Sub* sub = main->sub_link;
            for(int i=0;i<count;i++)
            {
                fprintf(fptr,";%s;%d",sub->file_name,sub->word_count);
                sub = sub->sub_link;
            }
            main = main->main_link;
            char ch = '\n';
            fprintf(fptr,";#%c",ch);
        }
    }
    printf("\033[0;33mSUCCESS: Database saved successfully\033[0m\n");
}