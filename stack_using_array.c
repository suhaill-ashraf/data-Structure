#include <stdio.h>

int stack[100];
int top;
int option = 0;

void push() {
    int item;
    printf("\nEnter the element you want to insert: ");
    scanf("%d", &item);
    top = top + 1;
    stack[top] = item;
}

void pop() {
    if (top < 0) {
        printf("Sorry, the stack is empty.\n");
        return;
    } else {
        int temp = stack[top];
        printf("\nDeleted element is: %d\n", temp);
        top = top - 1;
    }
}

void show() {
    if (top < 0) {
        printf("Sorry, the stack is empty.\n");
        return;
    } else {
        printf("\nStack elements are:\n");
        for (int i = 0; i <= top; i++) {
            printf("%d\n", stack[i]);
        }
    }
}

int choice() {
    printf("\nEnter 1 to push");
    printf("\nEnter 2 to pop");
    printf("\nEnter 3 to display");
    printf("\nEnter 4 to exit\n");
    scanf("%d", &option);
    return option;
}

int main() {
    top = -1;
    do {
        switch (choice()) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                show();
                break;
            case 4:
                break;
            default:
                printf("\nInvalid choice. Enter a valid choice.\n");
                break;
        }
    } while (option != 4);

    return 0;
}
