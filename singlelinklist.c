#include <stdio.h>
#include <stdlib.h>


struct Node {
    int info;
    struct Node* link;
};


struct Node* getnode() {
    return (struct Node*)malloc(sizeof(struct Node));
}


struct Node* insert_front(int item, struct Node* first) {
    struct Node* temp = getnode();
    temp->info = item;
    temp->link = first;
    return temp;
}


struct Node* insert_rear(int item, struct Node* first) {
    struct Node *temp, *cur;
    temp = getnode();
    temp->info = item;
    temp->link = NULL;
    if (first == NULL) {
        return temp;
    }
    cur = first;
    while (cur->link != NULL) {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}

struct Node* delete_front(struct Node* first) {
    struct Node* temp;
    if (first == NULL) {
        printf("List empty\n");
        return NULL;
    }
    temp = first;
    first = first->link;
    free(temp);
    return first;
}


struct Node* delete_rear(struct Node* first) {
    struct Node *temp, *prev, *cur;
    if (first == NULL) {
        printf("List empty\n");
        return NULL;
    }
    temp = first;
    prev = NULL;
    cur = first;
    while (cur->link != NULL) {
        prev = cur;
        cur = cur->link;
    }
    if (prev != NULL) {
        prev->link = NULL;
        free(cur);
    } else {
        free(first);
        first = NULL;
    }
    return first;
}


void display(struct Node* first) {
    struct Node* temp;
    if (first == NULL) {
        printf("List empty\n");
        return;
    }
    printf("The contents of the list are: ");
    temp = first;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    struct Node* first = NULL;


    first = insert_front(10, first);
    first = insert_front(5, first);
    first = insert_rear(20, first);
    display(first);

    first = delete_front(first);
    display(first);

    first = delete_rear(first);
    display(first);

    return 0;
}
