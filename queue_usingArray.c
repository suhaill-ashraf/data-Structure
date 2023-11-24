#include <stdio.h>

#define MAX_SIZE 100 //maximum size of queue

int queue[MAX_SIZE];
int last_index = -1;
int choice = 0;

// Function prototypes
void enqueue();
void dequeue();
void show();
int menu();

int main() {
    do {
        switch (menu()) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                show();
                break;
            case 4:
                break;
            default:
                printf("\nEnter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

void enqueue() {
    if (last_index == MAX_SIZE - 1) {
        printf("\nSorry, the queue is full.\n");
        return;
    }

    int item;
    printf("Enter the item: ");
    scanf("%d", &item);
    last_index++;
    queue[last_index] = item;
}

void dequeue() {
    if (last_index < 0) {
        printf("\nSorry, the queue is empty.\n");
        return;
    }

    int item = queue[0];
    for (int i = 0; i < last_index; i++) {
        queue[i] = queue[i + 1];
    }
    printf("\nDeleted element is %d\n", item);
    last_index--;
}

void show() {
    if (last_index < 0) {
        printf("\nSorry, the queue is empty.\n");
        return;
    }

    printf("\nQueue elements are:\n");
    for (int i = 0; i <= last_index; i++) {
        printf("%d\n", queue[i]);
    }
}

int menu() {
    printf("\n\n********* Choose an option **********\n");
    printf("Enter 1 to enqueue\n");
    printf("Enter 2 to dequeue\n");
    printf("Enter 3 to display\n");
    printf("Enter 4 to exit\n");
    scanf("%d", &choice);
    return choice;
}
