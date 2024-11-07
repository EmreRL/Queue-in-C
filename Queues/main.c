#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int age;
	char name[50];
	char surname[50];
	struct node* next;
};

struct Queue{
	struct node* front;
	struct node* rear;
};

struct Queue* queue;

void initializeQueue() {
    queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
}

void getValue(struct node* temp){
	printf("Please enter the age: ");
    scanf(" %d", &temp->age);
    printf("Please enter the name: ");
    scanf(" %s", temp->name);
    printf("Please enter the surname: ");
    scanf(" %s", temp->surname);
}

void enqueue(struct node* temp){
	temp = (struct node*)malloc(sizeof(struct node));
	if(queue->front != NULL){
		queue->rear->next = temp;
		queue->rear = temp;
		temp->next = NULL;
	}else{
		queue->front = temp;
		queue->rear = temp;
		temp->next = NULL;
	}
	getValue(temp);
}

void dequeue(struct node* temp){
	temp = queue->front;
	if(queue->front != queue->rear){
		queue->front = queue->front->next;
	}else{
		queue->front = NULL;
		queue->rear = NULL;
	}
	free(temp);
}

void listValues(int *val, struct node* temp) {
    int count = 1;
	temp = queue->front;
   while(1){
		
		printf("\n(%d) Age: %d",count, temp->age);
		printf("\n(%d) Name: %s",count, temp->name);
		printf("\n(%d) Surname: %s",count, temp->surname);
		printf("\n************************\n");
		
		temp = temp->next;
		count++;
		if(temp == '\0'){
			break;
		}
	}
}

int main(int argc, char *argv[]) {
	initializeQueue();	
	int count = 0, option = 0;
    struct node* start;
    while (1) {
        printf("(1) Enqueue\n(2) List Queue\n(3) Dequeue\n(4) Exit\n");
        scanf("%d", &option);
        if (option == 1) {
            count++;
            system("cls");
            enqueue(start);
            system("cls");
            printf("***Added to the Queue !***\n");
        }
        if (option == 2) {
            if (count == 0) {
                system("cls");
                printf("***No values added yet.***\n");
            }
            if (count != 0) {
            	system("cls");
                listValues(&count, start);
                printf("\n***Listed the Values !***\n\n");
            }
        }
        if (option == 3) {
            if (count == 0) {
                system("cls");
                printf("***No values added yet.***\n");
            }
            if (count != 0) {
                dequeue(start);
                count--;
                system("cls");
                printf("***Removed Successfully !***\n");
            }
        }
        if (option == 4) {
            break;
        }
    }
}
