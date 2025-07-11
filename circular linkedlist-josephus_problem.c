//josephus_problem
#include <stdio.h>
#include <stdlib.h>
// create node .
struct Node {
	int data;
	struct Node* next;
};
// first create circular linked list of N players.
struct Node* createCircle(int n) {
	struct Node *head = NULL, *temp = NULL, *last = NULL;
	for (int i = 1; i <= n; i++) {
		temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = i;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
		} else {
			last->next = temp;
		}
		last = temp;
	}
	last->next = head;
	return head;
}
// Eliminate K-th player
int getWinner(struct Node* head, int k) {
	struct Node *ptr = head, *prev = NULL;
	while (ptr->next != ptr) {
		for (int i = 1; i < k; i++) {
			prev = ptr;
			ptr = ptr->next;
		}
		// Remove the K-th player
		printf("Player %d is eliminated.\n", ptr->data);
		prev->next = ptr->next;
		free(ptr);
		ptr = prev->next;
	}
	int winner = ptr->data;
	free(ptr);
	return winner;
}
int main() {
	int n, k;
	printf("Enter number of players (N): ");
	scanf("%d", &n);
	printf("Enter step count (K): ");
	scanf("%d", &k);
	struct Node* circle = createCircle(n);  
	int winner = getWinner(circle, k);      
	printf("\nThe winner is: Player %d\n", winner);
	return 0;
}
