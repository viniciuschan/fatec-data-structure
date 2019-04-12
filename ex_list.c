#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


typedef struct List {
    char name[50];
    struct List *next;
} cell;

cell *newElement();
void insert(cell **head, cell **tail);
void list(cell *head);
void destroy(cell **head, cell **tail);
void clear_list(cell **head, cell **tail);

int main() {
    int op;
    cell *head = NULL, *tail = NULL;

    do {
        printf("MENU:\n(1) Insert\n(2) List\n(3) Delete\n(4) Clear list\n(5) Exit\n");
        scanf("%d", &op);

        switch(op) {
            case 1:
                insert(&head, &tail);
                break;
            case 2:
                list(head);
                break;
            case 3:
                destroy(&head, &tail);
                break;
            case 4:
                clear_list(&head, &tail);
                break;
            default:
                puts("Invalid option");
                break;
        }
    } while (op != 5);
}

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
        (*tail) = (*head) = new;
    } else {
        printf("\n(1) Insert top,\n(2) Insert last, \n(3) Insert middle\n");
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
                list(*head);
                puts("Choose the name you want to insert in the next: ");
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
            printf("\n%s\n", aux->name);
            aux = aux->next;
        }
        puts("----- TAIL -----\n");

    }
}

void destroy(cell **head, cell **tail) {
    char name[50];
    cell *aux = NULL, *temp = NULL;

    if (*head == NULL) {
        puts("Empty list");
    } else {
        list(*head);
        puts("\nType the item to delete: ");
        scanf("%s", name);

        if(strcmp((*head)->name, name) == 0) {
            temp = (*head)->next;
            free(*head);
            (*head) = temp;
        } else {
            aux = (*head);

            while(aux->next != NULL) {
                if(strcmp(aux->next->name, name) == 0) {
                    temp = aux;
                    break;
                }
                aux = aux->next;
            }

            if(temp != NULL) {
                if (temp->next == (*tail)) {
                    (*tail) = temp;
                }
                aux = temp->next->next;
                free(temp->next);
                temp->next = aux;
            } else {
            puts("\nInvalid option");
            }
        }
    }
}

void clear_list(cell **head, cell **tail) {
    cell *aux = NULL;

    if (*head == NULL) {
        puts("Empty list!");
    }

    while((*head) != NULL) {
        aux = (*head);
        free(*head);
        (*head) = aux->next;
    }
    free(*tail);
}
