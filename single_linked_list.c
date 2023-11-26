#include<stdio.h>
#include <stdlib.h>
int choice;
struct node
{
    int data;
    struct node *next;
};
struct node* start=NULL;

struct node* create_node(int data)
{
	struct node *t=(struct node*)malloc(sizeof(struct node));
	t->data=data;
	t->next= NULL;
	return t;
}
void create_new_list()
{
	start=NULL;
	int item,size;
	struct node *tail=NULL,*n;
	printf("\n Enter How many nodes you want:");
	scanf("%d",&size);
    for(int i=1;i<=size;i++)
    {
    	printf("\n Enter data for node %d:",i);
    	scanf("%d",&item);
    	n=create_node(item);
    	if(start==NULL)
    	{
    		start=n;
    		tail=n;
		}
    	
        tail->next=n;
        tail=n;
    	
	}
	

	
}
void insert_at_start()
{
	int item;
	printf("\n enter the node data:");
	scanf("%d",&item);
	struct node *n=create_node(item);
	if(start==NULL)
	{
		start=n;
		
	}
	else
	{
		n->next=start;
		start=n;
	}
	
}
void insert_at_end()
{
		int item;
	printf("\n enter the node data:");
	scanf("%d",&item);
	struct node *n=create_node(item);
	if(start==NULL)
	{
		start=n;
	}
	
	else{
		struct node *temp;
		temp=start;
		while(temp->next!=NULL)
		{
			temp=temp->next;
			
		}
		temp->next=n;
		
	}

	
}
void deletee()
{
	int key;
	struct node *temp=start;
	struct node *prev;
	printf("\n enter the node you want to delete:");
	scanf("%d",&key);
	
	if(temp!=NULL && key==temp->data)
	{
		start=temp->next;
		free(temp);
		printf("\n start node deleted");
		return;
	}
	while(temp!=NULL && temp->data!=key)
	{
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL)
	{
		printf("\n Node with value %d not found",key);
		return;
	}
	prev->next=temp->next;
	free(temp);
	printf("Node with vaue %d deleted",key);
}
void show()
{
	if(start==NULL)
	{
		printf("\n sorry linked list is empty");
		
	}else
	{
		struct node*temp;
		temp=start;
		printf("\n\n");
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->next;
		}
	}
}
void insert_at_any_position()
{
	int item,data,flag=0;
	printf("Enter the node after you want to insert the new node:");
	scanf("%d",&item);
	struct node* temp,*n;
	temp=start;
	while(temp->data!=item)
	{
		temp=temp->next;
		flag=1;
		
		
	}
	if(temp->data!=item)
	{
		printf("\n sorry node not found ");
		return;
		
	}else
	{
		
      	printf("\n Enter the new node:");
		scanf("%d",&data);
		n=create_node(data);
		n->next=temp->next;
		temp->next=n;
	
}   
	
	
}
void count()
{
	int count=0;
	if(start==NULL)
	{
		printf("\n list is empty");
		
	}
	struct node *temp=start;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	printf("\n %d nodes in list",count);
}
void search()
{
	int key;
	struct node *temp=start;
	if (start==NULL)
	{
		printf("\n list is empty");
		return;
	}
	printf("\n enter the node you want to search");
	scanf("%d",&key);
	while(temp!=NULL)
	{
		if(temp->data==key)
		{
			printf("\n node with value %d is present",key);
			break;
			
		}
	    
		temp=temp->next;
	}
	if(temp==NULL)
	{
		printf("\n Node with value %d is not present",key);
	}

	
}
int menu()
{
	printf("\n Enter 1 to Create new List");
	printf("\n Enter 2 to insert at start");
	printf("\n Enter 3 to insert at end");
	printf("\n Enter 4 to insert at any position");
	printf("\n Enter 5 to delete any node");
	printf("\n Enter 6 to Display");
	printf("\n Enter 7 to count nodes");
	printf("\n Enter 8 to search");
	printf("\n Enter 9 to exit:  ");
	scanf("%d",&choice);
	return choice;
	
}
int main()
{
	do{
		switch(menu())
		{
			case 1:create_new_list();
			break;
			case 2:insert_at_start();
			break;
			case 3:insert_at_end();
			break;
			case 4:insert_at_any_position();
			break;
			case 5: deletee();
			break;
			case 6:show();
			break;
			case 7:count();
			break;
			case 8:search();
			break;
			default:printf("\n Enter the valid case");
			break;
		}
	}while(choice !=9);
	return 0;
}




