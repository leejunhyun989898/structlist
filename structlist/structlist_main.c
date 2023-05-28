#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
} element;

typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

void error(char* message)
{
    fprintf(stderr, "%s\n", message);
}

ListNode* insert_first(ListNode* head, element value)
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

ListNode* search_list(ListNode* head, element x)
{
    ListNode* p = head;
    while (p != NULL) {
        if (strcmp(p->data.name, x.name) == 0)
            return p;
        p = p->link;
    }
    return NULL;
}

ListNode* delete_node(ListNode* head, element x)
{
    ListNode* p = head;
    ListNode* prev = NULL;

    while (p != NULL) {
        if (strcmp(p->data.name, x.name) == 0) {
            if (prev == NULL) { // Deleting the first node
                head = p->link;
            }
            else {
                prev->link = p->link;
            }
            free(p);
            return head;
        }

        prev = p;
        p = p->link;
    }

    return head; // If the node is not found, return the original head
}

void print_list(ListNode* head)
{
    for (ListNode* p = head; p != NULL; p = p->link)
        printf("%s->", p->data.name);
    printf("NULL\n");
}

void print_deleted_fruits(ListNode* deleted_head)
{
    printf("Deleted fruits: ");
    for (ListNode* p = deleted_head; p != NULL; p = p->link)
        printf("%s -> ", p->data.name);
    printf("NULL\n");
}

int main(void)
{
    ListNode* head = NULL;
    ListNode* deleted_head = NULL; // Head of the list to store deleted fruits
    element data;
    int s = 0;
    strcpy_s(data.name, sizeof(data.name), "Peach");
    head = insert_first(head, data);
    strcpy_s(data.name, sizeof(data.name), "Banana");
    head = insert_first(head, data);
    strcpy_s(data.name, sizeof(data.name), "Raspberry");
    head = insert_first(head, data);
    strcpy_s(data.name, sizeof(data.name), "Guava");
    head = insert_first(head, data);
    strcpy_s(data.name, sizeof(data.name), "Plum");
    head = insert_first(head, data);
    strcpy_s(data.name, sizeof(data.name), "Cherry");
    head = insert_first(head, data);
    strcpy_s(data.name, sizeof(data.name), "Grape");
    head = insert_first(head, data);
    strcpy_s(data.name, sizeof(data.name), "Apple");
    head = insert_first(head, data);
    strcpy_s(data.name, sizeof(data.name), "Orange");
    head = insert_first(head, data);
    strcpy_s(data.name, sizeof(data.name), "Mango");
    head = insert_first(head, data);

    while (1)
    {
        printf("\n= = = = Menu = = = =\n");
        printf("\n1. Insert fruit\n2. Delete fruit\n3. Print list\n4. Print deleted fruits\n5. Exit\n");
        printf("\nSelect Menu = ");
        scanf_s("%d", &s);

        if (s == 1) {
            printf("\nFruit to add: ");
            scanf_s("%s", data.name, sizeof(data.name));

            if (search_list(head, data) != NULL) {
                printf("%s is already in the list.\n", data.name);
            }
            else {
                printf("Added %s to the list.\n", data.name);
                head = insert_first(head, data);
            }
        }
        else if (s == 2) {
            printf("\nFruit to delete: ");
            scanf_s("%s", data.name, sizeof(data.name));

            ListNode* found = search_list(head, data);
            if (found != NULL) {
                printf("Deleted %s from the list.\n", data.name);

                // Add the deleted fruit to the deleted list
                deleted_head = insert_first(deleted_head, data);
                print_deleted_fruits(deleted_head); // Print the updated deleted fruits list

                head = delete_node(head, data);
            }
            else {
                printf("Fruit is not found.\n");
            }
        }
        else if (s == 3) {
            print_list(head);
        }
        else if (s == 4) {
            print_deleted_fruits(deleted_head);
        }
        else if (s == 5) {
            printf("Exit the program.\n");
            break;
        }
        else {
            printf("Invalid input. Please try again.\n");
        }
    }

    // Free the memory allocated for the deleted list

    return 0;
}
