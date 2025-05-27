#include "Inverted.h"
void display_database(Table* table)
{
    printf("\033[0;33m\t\t\t---:: Database details ::---\n\033[0m");
    for(int i=0;i<27;i++)
    {
        if(table[i].main_link == NULL)
        {
            continue;
        }
        Main* main = table[i].main_link;
        while(main!=NULL)
        {
            printf("\033[0;31m%-2d    %-10s    %d    \033[0m",i,main->word,main->file_count);
            int count = main->file_count;
            Sub* sub = main->sub_link;
            for(int i=0;i<count;i++)
            {
                printf("\033[0;31m%-10s--> %d    \033[0m",sub->file_name,sub->word_count);
                sub = sub->sub_link;
            }
            main = main->main_link;
            printf("\n");
        }
    }
}