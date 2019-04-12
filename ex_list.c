#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


typedef struct List {
    char name[50];
    struct List *next;
} cell;

cell *newElement() {
    cell *new;

    new = (cell*)malloc(sizeof(cell));
    if (new == NULL) {
        puts("Element could not be allocated");
    } else {
        puts("Type your name: ");
        scanf("%s", new->name);
        new->next = NULL;
    }
    return new;
}

void insert(cell **head, cell **tail) {
    cell *new, *aux = NULL, *temp = NULL;
    char name[50];
    int op;
    
    new = newElement();
    if (new == NULL) {
        puts("List is empty");
    }
    if ((*tail) == NULL) {
        (*tail) = (*head) = NULL;
    } else {
        printf("\n(1) Insert top,\n(2) Insert middle, \n(3) Insert last\n");
        scanf("%d", &op);

    switch(op) {
        case 1:
            aux = (*head);
            (*head) = new;
            new->next = aux;
            break;
        case 2:
            (*tail)->next = new;
            (*tail) = new;
            break;
        case 3:
            puts("Choose the position to insert: ");
            scanf("%s", name);

            aux = (*head);

            while (aux != NULL) {
                if (strcmp(aux->name, name) == 0) {
                    temp = aux;
                    break;
                }
                aux = aux->next;
            }

            if (temp != NULL) {
                aux = temp->next;
                temp->next = new;
                new->next = aux;
            } else {
                puts("Invalid option");
            }
            break;
        }    
    }
}

void list(cell *head) {
    if(head == NULL) {
        puts("Empty list");
    } else {
        cell *aux = head;
        
        puts("\n----- HEAD -----");
        while (aux != NULL) {
            printf("%s", aux->name);
            aux = aux->next;
        }
        puts("----- TAIL -----\n");
    }
}

int main() {
    cell *head, *tail;

    // testing
    insert(&head, &tail);
    list(head);

    return 0;
}