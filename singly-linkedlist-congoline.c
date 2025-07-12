//singly-linkedlist-congoline

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[100];
    struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;

struct node* createnode(char name[]) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    strcpy(newnode->name, name);
    newnode->next = NULL;
    return newnode;
}

void addToLine(char name[]) {
    struct node* newnode = createnode(name);
    if (head == NULL) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
    printf("'%s' joined the Congo line!\n", name);
}

void displayLine() {
    if (head == NULL) {
        printf("The Congo line is empty.\n");
        return;
    }
    struct node* temp = head;
    printf("Congo Line:\n");
    while (temp != NULL) {
        printf("%s -> ", temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;
    char person[100];

    while (1) {
        printf("\nCongo Line Menu\n");
        printf("1. Join Congo Line\n");
        printf("2. Show Congo Line\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        if (choice == 1) {
            printf("Enter name of the person: ");
            fgets(person, sizeof(person), stdin);
            person[strcspn(person, "\n")] = '\0'; 
            addToLine(person);
        }
        else if (choice == 2) {
            displayLine();
        }
        else if (choice == 3) {
            printf("Exiting the dance floor...\n");
            break;
        }
        else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
