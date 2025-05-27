#include "Inverted.h"
#include<string.h>
void search_database(Table* table)
{
    char word[20];
    printf("Enter the word that you want to search: ");
    getchar();
    scanf("%s",word);
    int number = 0;
            if(word[0]>='A' && word[0]<='Z')
            {
                word[0] = word[0] + 32;
            }
            else if(word[0] >= '0' && word[0]<='9')
            {
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
    int flag = 0;
        Main* main = table[index].main_link;
        while(main!=NULL)
        {
            if(strcmp(main->word,word)==0)
            {
                printf("%d    %s    %d    ",index,main->word,main->file_count);
                int count = main->file_count;
                Sub* sub = main->sub_link;
                for(int i=0;i<count;i++)
                {
                    printf("%s    %d    ",sub->file_name,sub->word_count);
                    flag = 1;
                    sub = sub->sub_link;
                }
                printf("\n");
                break;
            }
            main = main->main_link;
        }
        if(flag==0)
        {
            printf("\nNOTE: Word not in the database\n\n");
        }
}