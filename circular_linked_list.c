#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List{
    char name[50];
    struct list *next;
} list;

list *create_list();
void insert(list **head, list **tail);
void list_items(list *head);
void destroy(list **head, list **tail);
void clear_list(list **head, list **tail);

int main() {
    int op = 0;
    list *head = NULL;
    list *tail = NULL;
    do{
        printf(
            "\n1 - insert"
            "\n2 - list items"
            "\n3 - delete item"
            "\n4 - clear list"
            "\n0 - EXIT"
        );
        puts("Choose an option: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                insert(&head, &tail);
                break;
            case 2:
                list_items(head);
                break;
            case 3:
                destroy(&head, &tail);
                break;
            case 4:
                clear_list(&head, &tail);
                break;
            case 0:
                exit(0);
            default:
                puts("Invalid option");
                break;
        }
    } while (op != 0);
}

list *create_list() {
    list *new_list = (list*) malloc(sizeof(list));

    if (new_list != NULL) {
        puts("Insert your name: ");
        scanf("%s", new_list->name);
        new_list->next = NULL;
    }
    return new_list;
}

void insert(list **head, list **tail) {
    int op = 0;
    char name[50];
    list *new_list = NULL;
    list *temp = NULL;
    list *reference = NULL;

    new_list = create_list();
    if (new_list == NULL) {
        puts("No list allocated");
        return;
    }

    if ((*tail) == NULL) {
        (*tail) = (*head) = new_list;
        (*tail)->next = (*head);
    } else {
        list *temp = (*head);
        list *aux = NULL;
        int result = 0;

        if (strcmp(new_list->name, (*head)->name) <= 0) {
            aux = (*head);
            (*head) = new_list;
            new_list->next = aux;
            (*tail)->next = (*head);
        } else {
            do {
                result = strcmp(new_list->name, temp->next->name);

                if (result <= 0) {
                    aux = temp->next;
                    temp->next = new_list;
                    new_list->next = aux;
                    break;
                } else if (temp->next == (*head)) {
                    (*tail)->next = new_list;
                    (*tail) = new_list;
                    new_list->next = (*head);
                    break;
                }
                temp = temp->next;
            } while (temp != (*head));
        }
    }
}

void list_items(list* head) {
    list *temp = head;
    do{
        printf(" %s ", temp->name);
        temp = temp->next;
    } while (temp != head);
}

void destroy(list **head, list **tail) {
    char name[50];
    list *temp = NULL;
    list *reference = NULL;

    list_items((*head));
    puts("Choose a name to delete");
    scanf("%s", name);

    if (strcmp((*head)->name, name) == 0) {
        reference = (*head)->next;
        free((*head));
        (*head) = reference;
    } else {
        temp = (*head);

        do {
            if (strcmp(temp->next->name, name) == 0) {
                reference = temp;
                break;
            }
            temp = temp->next;
        } while (temp->next != (*head));

        if (reference != NULL) {

            if (reference->next == (*tail)) {
                (*tail) = reference;
            }

            temp = reference->next->next;
            free(reference->next);
            reference->next = temp;
        } else {
            puts("Invalid option");
        }
    }
}

void clear_list(list **head, list **tail) {
    list *temp = NULL;
    list *initial = (*head);
    do {
        temp = (*head)->next;
        free((*head));
        (*head) = temp;
    } while (temp != initial);
    *head = NULL;
}
