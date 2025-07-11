#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char song[100];
	struct node*next;
};

struct node*head=NULL;
struct node*createnode(char song[])
{
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	strcpy(newnode->song,song);
	newnode->next=NULL;
	return newnode;
}


void beg(char song[])
{
	struct node * newnode=createnode(song);
	newnode->next=head;
	head=newnode;
	printf("%s added to the playlist",song);
}

void display()
{
	if(head==NULL)
	{
		printf("\n no song to play..");
		return;
	}
	struct node*temp=head;
	if(temp!=NULL)
	{
		printf("%s->",temp->song);
		temp=temp->next;
	}
	printf("NULL");
}

int main() {
	int choice;
	char songname[100];

	while (1) {
		printf("\n--- Playlist Menu ---\n");
		printf("1. Add a Song\n");
		printf("2. Display Playlist\n");
		printf("3. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		getchar();
		if (choice == 1) {
			printf("Enter song name (can have spaces): ");
			fgets(songname, sizeof(songname), stdin);
			songname[strcspn(songname, "\n")] = '\0';
			beg(songname);
		}
		else if (choice == 2) {
			display();
		}
		else if (choice == 3) {
			printf("Exiting...\n");
			break;
		}
		else {
			printf("Invalid choice! Try again.\n");
		}
	}

	return 0;
}
