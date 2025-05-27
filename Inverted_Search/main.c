/*          ---DOCUMENTATION---
    NAME: B. ASHOK KUMAR
    DATE: 17-05-2025
    DESCRIPTION: INVERTED SEARCH IS A PROJECT IMPLEMENTED FOR REDUCING TIME COMPLEXITY FOR SERCHING ALGORITHM. 
                ITS JUST A BASIC TYPE OF INVERTED SEARCH PROJECT.                    
*/
#include "Inverted.h"
void create_HT(Table *HT)       //Creating hash table 
{
    for(int i=0;i<27;i++)
    {
        HT[i].key = i;
        HT[i].main_link = NULL;
    }
}
int main(int argc,char* argv[])
{
    Slist* head = NULL;
    Table table[27];
    create_HT(table);
    if(argc != 1)
    {
        if(read_and_validate_arguments(argv,argc,&head)==FAILURE)   //for reading and validating arguments
        {
            //printf("Enter valid arguments\n");
            return 0;
        }
        int i=1;
        int create = 0;
        int update =0;
        while(i)
        {
            printf("1. Create Database\n2. Search Database\n3. Display Database\n4. Update Database\n5. Save Database\nSelect your choice --->");
            int opt;
            scanf("%d",&opt);
            switch(opt)
            {
                case 1:
                        if(create==0)
                        {
                            create_database(head,table);            //for creating data base
                            create = 1;
                        }
                        else{
                            printf("\033[0;31mERROR: you cant create a data base again\033[0m\n");
                        }
                        break;
                case 2:
                        search_database(table);         //for search a word in data base
                        break;
                case 3:
                        display_database(table);        //to display the contents in the data base
                        break;
                case 4:
                        if(create==0 && update ==0)
                        {
                            int real=0;
                            update_database(table,&head,&real);         //to update database with the file that user entered
                            if(real==0)
                            {
                                update = 1;
                            }
                        }
                        else{
                            printf("\033[0;31mERROR: You have already Updated. You cant Re-Update DataBase\033[0m\n");
                        }
                        break;
                case 5:
                        save_database(table);       //save the data base to the file
                        break;
                default:
                        printf("Enter valid option\n");
            }
            char ch;
            getchar();
            printf("You want to continue (Y|N): ");
            scanf("%c",&ch);
            if(ch=='N' || ch == 'n')
            {
                i=0;
            }
        }
    }
    else{
        printf("ERROR: Enter valid number of arguments\n");
    }
}