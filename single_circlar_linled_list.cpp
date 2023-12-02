#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int choice;
struct node *start = NULL;

struct node *create_node(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    return n;
}

void create_list()

{
	start=NULL;
    struct node *temp = start;
    int size;
    int item;
    printf("\n Enter the number of nodes you want:");
    scanf("%d", &size);
    for (int i = 1; i <= size; i++)
    {
        printf("\n Enter data for node %d:", i);
        scanf("%d", &item);
        struct node *n = create_node(item);

        if (start == NULL)
        {
            start = n;
            n->next = start;
            temp = start;
        }
        else
        {
            n->next = start;
            temp->next = n;
            temp = n;
        }
    }
}

void insert_at_start()
{
    struct node *n, *temp = start;
    int item;
    printf("\n Enter the node data:");
    scanf("%d", &item);
    n = create_node(item);
    while (temp->next != start)
    {
        temp = temp->next;
    }
    n->next = start;
    temp->next = n;
    start = n;
}

void insert_at_end()
{
    int item;
    struct node *temp = start;
    printf("\nEnter node data");
    scanf("%d", &item);

    struct node *n = create_node(item);
    if (start == NULL)
    {
        n->next = start;
        start = n;
    }
    else
    {
        while (temp->next != start)
        {
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
    }
}
void deletee()
{
    struct node *temp = start, *t, *prev = NULL;
    int key;
    if (start == NULL)
    {
        printf("\n Sorry list is empty");
        return;
    }
    printf("\n Enter the node you want to delete:");
    scanf("%d", &key);

    // Check if the node to be deleted is the first node
    if (start != NULL && start->data == key)
    {
        while (temp->next != start)
        {
            temp = temp->next;
        }
        t = start;
        temp->next = start->next;
        start = start->next;
        free(t);
    }
    else
    {
        // Find the node to be deleted
        while (temp->next != start && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }

        // Node to be deleted found
        if (temp->data == key)
        {
            // If the node is not the last node
            if (temp->next != start)
            {
                prev->next = temp->next;
                free(temp);
            }
            // If the node is the last node
            else
            {
                prev->next = start;
                free(temp);
            }
        }
        else
        {
            printf("\n Node with key %d not found.", key);
        }
    }
}
void count()
{
    
	int count=1;
	struct node *temp=start;
	if(start==NULL)
	{
		printf("\n Sorry list is empty");
		return;
	}

	while(temp->next!=start)
	{
		count++;
		temp=temp->next;
	}
	printf("\n number of nodes in list are:%d",count);
}


void show()
{
    struct node *temp = start;
    if (start == NULL)
    {
        printf("\n Sorry list is empty");
        return;
    }
    do
    {
        printf("\n %d", temp->data);
        temp = temp->next;
    } while (temp != start);
}

int menu()
{
    printf("\n Enter 1 to create list:");
    printf("\n Enter 2 to insert at start:");
    printf("\n Enter 3 to insert at end:");
    printf("\n Enter 4 to delete any node:");
    printf("\n Enter 5 to count nodes:");
    printf("\n Enter 6 to display:");
    printf("\n Enter 7 to Exit:");
    scanf("%d", &choice);
    return choice;
}


int main()
{
    do
    {
        switch (menu())
        {
        case 1:
            create_list();
            break;
        case 2:
            insert_at_start();
            break;
        case 3:
            insert_at_end();
            break;
        case 4:
            deletee();
            break;
        case 5:
            count();
            break;
        case 6:show();
            break;
        default:
            printf("\n please choose the valid option");
            break;
        }
    } while (choice != 7);
    return 0;
}
