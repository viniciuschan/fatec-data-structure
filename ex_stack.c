#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Stack {
    int ra;
    char name[30];
    struct Stack *next;
} cell;

cell *newElement() {
    cell *new;

    new = (cell*)malloc(sizeof(cell));
    if(new == NULL) {
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

void insert(cell **top) {
    cell *new;

    new = newElement();
    if(new == NULL) {
        puts("Element could not be allocated");
    } else {
        new->next = *top;
        *top = new;
    }
}

void list(cell *top) {
    if(top == NULL) {
        puts("Stack is empty");
    } else {
        do {
            printf("\nName: %s \t RA: %d", top->name, top->ra);
            top = top->next;
        } while(top != NULL);
    }
}

void destroy(cell **top) {
    cell *aux;
    if (*top == NULL) {
        puts("Stack is empty");
    } else {
        aux = (*top)->next;
        free(*top);
        *top = aux;
    }
}

void clear(cell **top) {
    while(*top != NULL) {
        destroy(&*top);
    }
}

int main() {
    cell *top = NULL;
    char op;

    do {
        printf("\n\nOperations:\n\tI - Insert\n\tL - List\n\tD - Delete item\n\tC - Clear stack\n\tE - Exit\n");

        op = toupper(getchar());
        switch (op) {
            case 'I':
                insert(&top);
                break;
            case 'L':
                list(top);
                break;
            case 'D':
                destroy(&top);
                break;
            case 'C':
                clear(&top);
                break;
            case 'E':
                exit(0);
            default:
                puts("Invalid option");
                break;
        }
    } while(op != 'E');
    return 0;
}
