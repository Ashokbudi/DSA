/*          ---DOCUMENTATION---
    NAME: BUDI ASHOK KUMAR
    DATE: 71-05-2025
    DESCRIPTION: APC - ARTBITARY PRECISION CALCULATOR IS A PROJECT TO HANDLE ARITHMETIC OPERTIONS FOR LARGER DATA.
*/
#include "apc.h"
int main(int argc,char* argv[])
{
    Dlist* head1= NULL;
    Dlist* tail1= NULL;
    Dlist* head2= NULL;
    Dlist* tail2= NULL;
    Dlist* headR= NULL;
    Dlist* tailR= NULL;
    if(argc==4)
    {
        if(read_and_validate_args(argv)!=SUCCESS)  //for validating arguments
        {
            //printf("Enter valid arguments\n");
            return 0;
        }
        if(store_operands_to_list(argv[1],argv[3],&head1,&tail1,&head2,&tail2)!=SUCCESS)    //to store operands in the linked list
        {
            printf("list not copied Successfully\n");
            return 0;
        }
        char op_type = argv[2][0];
        switch(op_type)
        {
            case '+':
                    addition(&head1,&tail1,&head2,&tail2,&headR,&tailR,argv);       //for performing addition operatio 
                    break;
            case '-':
                    substraction(&head1,&tail1,&head2,&tail2,&headR,&tailR,argv);   //for performing substraction operation
                    break;
            case 'x':
                    multiplication(&head1,&tail1,&head2,&tail2,&headR,&tailR,argv); //for performing multiplication operation
                    break;
            case '/':
                    divison(&head1,&tail1,&head2,&tail2,&headR,&tailR,argv);    //for performing division operation
                    break;
            default:
                    printf("Enter valid arguments\n");
                    return 0;
        }
    }
    else{
        printf("Enter valid no of arguments\n");
        return 0;
    }


}