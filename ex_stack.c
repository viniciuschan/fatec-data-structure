#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct Stack {
    int ra;
    char name[30];
    struct Stack *next;
} cell;

cell *create_element();
void insert(cell **head);
void list(cell *head);
void destroy(cell **head);
void clear_stack(cell **head);

int main() {
    cell *head = NULL;
    char op;

    do {
        printf("\n\nOperations:\n\tI - Insert\n\tL - List\n\tD - Delete item\n\tC - Clear stack\n\tE - Exit\n");

        op = toupper(getchar());
        switch (op) {
            case 'I':
                insert(&head);
                break;
            case 'L':
                list(head);
                break;
            case 'D':
                destroy(&head);
                break;
            case 'C':
                clear_stack(&head);
                break;
            case 'E':
                exit(0);
            default:
                puts("Invalid option, to exit press 'E'");
                break;
        }
    } while (op != 'E');

    return 0;
}


cell *create_element() {
    cell *new;

    new = (cell*)malloc(sizeof(cell));
    if (new == NULL) {
        puts("Element could not be allocated");
    } else {
        puts("Type the R.A. code");
        scanf("%d", &new->ra);
        puts("Type the name");
        fflush(stdin);
        scanf("%s", new->name);
    }
    return new;
}

void insert(cell **head) {
    cell *new;

    new = create_element();
    if (new == NULL) {
        puts("Element could not be allocated");
    } else {
        new->next = *head;
        *head = new;
    }
}

void list(cell *head) {
    if (head == NULL) {
        puts("Stack is empty");
    } else {
        do {
            printf("\nName: %s \t RA: %d", head->name, head->ra);
            head = head->next;
        } while(head != NULL);
    }
}

void destroy(cell **head) {
    cell *aux;
    if (*head == NULL) {
        puts("Stack is empty");
    } else {
        aux = (*head)->next;
        free(*head);
        *head = aux;
    }
}

void clear_stack(cell **head) {
    while (*head != NULL) {
        destroy(&*head);
    }
}
