#include<stdio.h>
#include<stdlib.h>
struct node 
{
  struct node *prev;
  int data;
  struct node *next;
  	
};
int choice;
struct node *start=NULL;
//function to create node dynamically
struct node* create_node(int item)
{
	struct node *n=(struct node*)malloc(sizeof(struct node));
	n->prev=NULL;
	n->data=item;
	n->next=NULL;
	return n;
	
}
void create_list()
{
    int size, item;
    start = NULL;
    struct node *n;
    struct node *temp = start;

    printf("\nEnter the size of the new list: ");
    scanf("%d", &size);

    for (int i = 1; i <= size; i++)
    {
        printf("\nEnter value for node %d: ", i);
        scanf("%d", &item);

        n = create_node(item);

        if (start == NULL)
        {
            // If the list is empty, make the new node the start
            start = n;
        }
        else
        {
            // Assign pointers for subsequent nodes
            n->prev = temp;
            temp->next = n;
        }

        temp = n;
    }
}

void insert_at_start()
{
	struct node *temp=start,*n;
	int item;
	printf("\n Enter the node data:");
	scanf("%d",&item);
	n=create_node(item);
	n->next=start;
	start=n;
	
	
	
}
void insert_at_end()
{
    int item;
    printf("\nEnter the node data: ");
    scanf("%d", &item);

    struct node *temp = start, *n;
    n = create_node(item);

    if (start == NULL)
    {
        start = n;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = n;
        n->prev = temp;
        n->next = NULL;
    }
}

void insert_at_any_position()
{
    if (start == NULL)
    {
        printf("\nSorry, the list is empty. First, you need to create a list.");
        return;
    }

    struct node *temp = start, *n, *next;
    int key, item;

    printf("\nEnter the node value after which you want to insert your new node: ");
    scanf("%d", &key);

    printf("Enter the node value: ");
    scanf("%d", &item);

    n = create_node(item);

    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("\nNode with the given key not found in the list.");
        return;
    }

    next = temp->next;
    n->next = next;

    if (next != NULL)
    {
        next->prev = n;
    }

    n->prev = temp;
    temp->next = n;
}
void deletee()
{
	int key;
	struct node *temp,*prev,*next;
	printf("\n Enter the node you want to delete:");
	scanf("%d",&key);
	if(start!=NULL && start->data==key)
	{
		temp=start;
		start=start->next;
		free(temp);
		return;
	}
	temp=start;
	while(temp->data!=key)
	{
		prev=temp;
		temp=temp->next;
		
	}
	if(temp->next==NULL)
	{
		prev->next=NULL;
		free(temp);
		return;
	}else
	{
	
	next=temp->next;
	prev->next=next;
	next->prev=prev;
}
	
}
void count()
{
	int count=0;
	if (start==NULL)
	{
		printf("\n Sorry the list is empty");
		return;
		
	}
	else
	{
		struct node *temp=start;
		while(temp!=NULL)
		{
			count++;
			temp=temp->next;
		}
		printf("\n the number of nodes in the list are %d",count);
	}
}
void search()
{
	if(start==NULL)
	{
		printf("\n Sorry the list is empty");
		return;
	}else
	
	 {
	 	struct node *temp=start;
	 	int key;
	 	printf("\n Enter the node you want to find:");
	 	scanf("%d",&key);
	 	while(temp!=NULL)
	 	{
	 		if(temp->data==key)
	 		{
	 		printf("\n yes the node with value %d is present in the list",key);
	 	    }   
	 		temp=temp->next;
	    }
	    if(temp==NULL)
	    {
	    	printf("\n the node with value %d is not present in the list",key);
		}
	    
	 }
}

void show()
{
	if(start==NULL)
	{
		printf("\n Sorry list is empty\n");
		
	}else
	{
		struct node *temp=start;
		while(temp!=NULL)
		{
			printf("\t %d",temp->data);
			temp=temp->next;
		}
	}
	

}

int menu()
{
	printf("\n Enter 1 to create new list");
	printf("\n Enter 2 to insert at start");
	printf("\n Enter 3 to insert at end");
	printf("\n Enter 4 to insert at any position");
	printf("\n Enter 5 to delete any node");
	printf("\n Enter 6 to count the number of nodes in list");
	printf("\n Enter 7 to search the particular node");
	printf("\n Enter 8 to display nodes");
	printf("\n Enter 9 to exit");
	scanf("%d",&choice);
	return choice;
	
}
int main()
{
	do{
		switch(menu())
		{
			case 1:create_list();
			break;
			case 2:insert_at_start();
			break;
			case 3:insert_at_end();
			break;
			case 4:insert_at_any_position();
			break;
			case 5:deletee();
			break;
			case 6:count();
			break;
			case 7:search();
			break;
			case 8:show();
			break;
			default: printf("\n Enter the valid option ");
			break;
		}
		
	}while(choice !=9);
}
