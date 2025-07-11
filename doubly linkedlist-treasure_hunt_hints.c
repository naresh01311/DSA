#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char hint[100];
	struct node* next;
	struct node* pre;
};

struct node* head = NULL;
struct node* tail = NULL;


struct node* createnode(char hint[]) {
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	strcpy(newnode->hint, hint);
	newnode->next = NULL;
	newnode->pre = NULL;
	return newnode;
}

void end(char hint[]) {
	struct node* newnode = createnode(hint);
	if (head == NULL) {
		head = tail = newnode;
	} else {
		tail->next = newnode;
		newnode->pre = tail;
		tail = newnode;
	}
	printf("Hint added: %s\n", hint);
}


void display() {
	if (head == NULL) {
		printf("\nNo hints available.\n");
		return;
	}

	struct node* temp = head;
	printf("\nTreasure Hunt Hints:\n");
	while (temp != NULL) {
		printf("%s -> ", temp->hint);
		temp = temp->next;
	}
	printf("NULL\n");
}

int main() {
	int choice;
	char hint[100];

	while (1) {
		printf("\nTreasure Hunt\n");
		printf("1. Add a hint\n");
		printf("2. Display hints\n");
		printf("3. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		getchar();

		if (choice == 1) {
			printf("Enter hint: ");
			fgets(hint, sizeof(hint), stdin);
			hint[strcspn(hint, "\n")] = '\0';
			end(hint);
		}
		else if (choice == 2) {
			display();
		}
		else if (choice == 3) {
			printf("Exiting... Good luck on your treasure hunt!\n");
			break;
		}
		else {
			printf("Invalid choice! Please try again.\n");
		}
	}

	return 0;
}
