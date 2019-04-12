#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct Queue {
    int ra;
    char name[50];
    struct Queue *next;
} cell;

cell *create_element();
void insert(cell **head, cell **tail);
void list(cell *head);
void destroy(cell **head);
void clear_queue(cell **head);

int main() {
    cell *head = NULL, *tail;
    char op;

    do {
        printf("\n\nOperations:\n\tI - Insert\n\tL - List\n\tD - Delete item\n\tC - Clear queue\n\tE - Exit\n");

        op = toupper(getchar());
        switch (op) {
            case 'I':
                insert(&head, &tail);
                break;
            case 'L':
                list(head);
                break;
            case 'D':
                destroy(&head);
                break;
            case 'C':
                clear_queue(&head);
                break;
            case 'E':
                exit(0);
            default:
                puts("Invalid option");
        }
    } while (op != 'E');

    return 0;
}

cell *create_element() {
    cell *new;

    new = (cell*)malloc(sizeof(cell));
    if (new == NULL){
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

void insert(cell **head, cell **tail) {
    cell *new;

    new = create_element();
    if (new == NULL){
        puts("Element could not be allocated");
    } else {
        new->next = NULL;
        if (*head == NULL) {
            *head = new;
            *tail = new;
        } else {
            (*tail)->next = new;
            *tail = new;
        }
    }
}

void list(cell *head) {
    if (head == NULL) {
        puts("Empty queue");
    } else {
        do {
            printf("\nName: %s\tR.A. code: %d", head->name, head->ra);
            head = head->next;
        } while (head != NULL);
    }
}

void destroy(cell **head) {
    cell *aux;

    if (*head == NULL) {
        puts("Empty queue");
    } else {
        aux = (*head)->next;
        free(*head);
        *head = aux;
    }
}

void clear_queue(cell **head) {
    while (*head != NULL) {
        destroy(&*head);
    }
}
