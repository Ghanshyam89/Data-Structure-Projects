// Lab-17: WAP to perform all Operations on a Linked List
// Developed by: Ghanshyam Prajapati.
// Date: 01/12/2020.

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void Insertatbegin(int);
void Insertatposition(int, int);
void Insertatlast(int);

void Deletefrombegin();
void Deletefromposition(int);
void Deletefromlast();

void Reverse();

void Display();

struct node
{
    int data;
    struct node *next;
};

struct node *Head, *currptr;

static int count = 0;

int main()
{
    char choice;
    int data, position;
    while(1)
    {
        printf("\n ------------------------------------------------------------");
        printf("\n|                 Linked List Implementation                 |");
        printf("\n ------------------------------------------------------------\n\n");
        
        printf(" Press any Key to Continue... ");
        getch();

        printf("\n\n --X--X--X--X--X-- Operation on Linked List --X--X--X--X--X--");
        printf("\n|                                                            |");
        printf("\nX    1. Insert Data at the begining of the List              X");
        printf("\n|    2. Insert Data at the Specific position in the List     |");
        printf("\nX    3. Insert Data at the End of the List                   X");
        printf("\n|    4. Delete Data from the begining of the List            |");
        printf("\nX    5. Delete Data from the Specific position in the List   X");
        printf("\n|    6. Delete Data from the end of the List                 |");
        printf("\nX    7. Reverse the List                                     X");
        printf("\n|    8. Display                                              |");
        printf("\nX    9. Exit                                                 X");
        printf("\n|                                                            |");
        printf("\n --X--X--X--X--X--X--X--X--X---X--X--X--X--X--X--X--X--X--X--");

        printf("\n\n Enter Your Choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1: 
                printf("\n Enter the Element: ");
                scanf("%d", &data);
                Insertatbegin(data);
                break;
            case 2:
                printf("\n At which position you want to place the Element: ");
                scanf("%d", &position);
                printf("\n Enter the Element: ");
                scanf("%d", &data);
                Insertatposition(position, data);
                break;
            case 3:
                printf("\n Enter the Element: ");
                scanf("%d", &data);
                Insertatlast(data);
                break;
            case 4:
                Deletefrombegin();
                break;
            case 5:
                printf("\n From which position you want to Delete the Element: ");
                scanf("%d", &position);
                Deletefromposition(position);
                break;
            case 6:
                Deletefromlast();
                break;
            case 7:
                Reverse();
                break;
            case 8:
                Display();
                break;
            case 9:
                printf("\n ------------------------------------------------------------");
                printf("\n|              Linked List Implementation Ended!             |");
                printf("\n ------------------------------------------------------------\n\n");
                exit(0);
                break;
            default:
                printf("\n ------------------------------------------------------------");
                printf("\n|                       Invalid Choice!                      |");
                printf("\n ------------------------------------------------------------\n\n");
        }
    }
    return 0;
}

void Reverse()
{
    struct node * prevptr = NULL, *currptr = Head, *nextptr = NULL;
    if(Head == NULL)
    {
        printf("\n ------------------------------------------------------------");
        printf("\n|                       List is Empty!                       |");
        printf("\n ------------------------------------------------------------\n");
    }
    else
    {
        while(currptr != NULL)
        {
            nextptr = currptr -> next;
            currptr -> next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }
        Head = prevptr;
        printf("\n ------------------------------------------------------------");
        printf("\n|                  List has been Reversed!                   |");
        printf("\n ------------------------------------------------------------\n");
    }
    // free(prevptr);
    free(currptr);
    free(nextptr);
}

void Insertatbegin(int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = data;
    
    if(Head == NULL)
    {
        newNode -> next = NULL;
        Head = newNode;
        count++;
        printf("\n ------------------------------------------------------------");
        printf("\n|               Element Successfully Inserted!               |");
        printf("\n ------------------------------------------------------------\n");
    }
    else
    {
        newNode -> next = Head;
        Head = newNode;
        count++;
        printf("\n ------------------------------------------------------------");
        printf("\n|               Element Successfully Inserted!               |");
        printf("\n ------------------------------------------------------------\n");
    }
}

void Insertatposition(int pos, int data)    //Insert Element at the specific Position
{
    struct node *prevptr = Head;
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> next = NULL;
    if(Head == NULL)
    {
        Head = newNode;
        count++;
        printf("\n ------------------------------------------------------------");
        printf("\n|               Element Successfully Inserted!               |");
        printf("\n ------------------------------------------------------------\n");
    }
    else if( pos > count + 1)
    {
            printf("\n ------------------------------------------------------------");
            printf("\n|       Position is greater than the Size of the List        |");
            printf("\n ------------------------------------------------------------\n");
            return;
    }
    else if(pos < 1)
    {
        printf("\n ------------------------------------------------------------");
        printf("\n|   Invalid Position! Please Enter valid Positive Integer    |");
        printf("\n ------------------------------------------------------------\n");
        return;
    }
    else if(pos == 1)
    {
        newNode -> next = Head;
        Head = newNode;
        count++;
        printf("\n ------------------------------------------------------------");
        printf("\n|               Element Successfully Inserted!               |");
        printf("\n ------------------------------------------------------------\n");
    }
    else
    {
        int i = 1;
        
        for( ; i < pos - 1; i++)
        {
            prevptr = prevptr -> next;
        }
        newNode -> next = prevptr -> next;
        prevptr -> next = newNode;
        count++;
        printf("\n ------------------------------------------------------------");
        printf("\n|               Element Successfully Inserted!               |");
        printf("\n ------------------------------------------------------------\n");
    }
    // free(prevptr);
}

void Insertatlast(int data)       //Inserting the Node at the last of the List
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> next = NULL;
    if(Head == NULL)
    {
        Head = newNode;
        count++;
        printf("\n ------------------------------------------------------------");
        printf("\n|               Element Successfully Inserted!               |");
        printf("\n ------------------------------------------------------------\n");
    }
    else
    {   
        currptr = Head;
        
        while(currptr -> next != NULL)
        {
            currptr = currptr -> next;
        }
        currptr -> next = newNode;
        count++;
        printf("\n ------------------------------------------------------------");
        printf("\n|               Element Successfully Inserted!               |");
        printf("\n ------------------------------------------------------------\n");

        // free(currptr);
    }
}

void Deletefrombegin()
{
    struct node *currptr = Head;
    if(currptr == NULL)
    {
        printf("\n ------------------------------------------------------------");
        printf("\n|                   List is Already Empty!                   |");
        printf("\n ------------------------------------------------------------\n");  
    }
    else
    {
        Head = Head -> next;
        free(currptr);
        count--;
        printf("\n ------------------------------------------------------------");
        printf("\n|               Element Successfully Deleted!                |");
        printf("\n ------------------------------------------------------------\n");
    }
}

void Deletefromposition(int pos)
{
    struct node *prevptr = NULL, *currptr = Head, *nextptr = NULL;
    if(currptr == NULL)
    {
        printf("\n ------------------------------------------------------------");
        printf("\n|                   List is Already Empty!                   |");
        printf("\n ------------------------------------------------------------\n");  
    }
    else if(pos < 1)
    {
        printf("\n ------------------------------------------------------------");
        printf("\n|   Invalid Position! Please Enter valid Positive Integer    |");
        printf("\n ------------------------------------------------------------\n");
        return;
    }
    else if(pos > count + 1)
    {   
        printf("\n ------------------------------------------------------------");
        printf("\n|                  Element Doesn\'t Exist!                   |");
        printf("\n ------------------------------------------------------------\n");          
    }
    else if(pos == 1)
    {
        free(currptr);
        free(prevptr);
        free(nextptr);
        Head = NULL;
        count--;
        printf("\n ------------------------------------------------------------");
        printf("\n|               Element Successfully Deleted!                |");
        printf("\n ------------------------------------------------------------\n");
    }
    else
    {
        int i = 1;
        
        nextptr = currptr -> next;
        for( ; i < pos - 1; i++)
        {
            currptr = currptr -> next;
            nextptr = nextptr -> next;
        }
        currptr -> next = nextptr -> next;
        free(nextptr);
        count--;
        printf("\n ------------------------------------------------------------");
        printf("\n|               Element Successfully Deleted!                |");
        printf("\n ------------------------------------------------------------\n");
    }
}

void Deletefromlast()           //Deleting the node from the last 
{
    struct node * prevptr;
    currptr = Head;
    prevptr = Head;
    if(currptr == NULL)
    {
        printf("\n ------------------------------------------------------------");
        printf("\n|                   List is Already Empty!                   |");
        printf("\n ------------------------------------------------------------\n");  
    }
    else{
        currptr = currptr -> next;
        while(currptr -> next != NULL)
        {
            currptr = currptr -> next;
            prevptr = prevptr -> next;
        }
        prevptr -> next = NULL;
        free(currptr);
        count--;
        printf("\n ------------------------------------------------------------");
        printf("\n|               Element Successfully Deleted!                |");
        printf("\n ------------------------------------------------------------\n");
    }
}

void Display()
{
    
    if(Head == NULL)
    {
        printf("\n ------------------------------------------------------------");
        printf("\n|                       List is Empty!                       |");
        printf("\n ------------------------------------------------------------\n");
    }
    else
    {
        currptr = Head;
        printf("\n ");
        while(currptr -> next != NULL)
        {
            printf("%d  ", currptr -> data);
            currptr = currptr -> next;
        }
        printf("%d\n", currptr -> data);
    }
}
