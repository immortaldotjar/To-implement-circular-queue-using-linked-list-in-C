#include <stdio.h>
#include <stdlib.h>

//Creating new node
struct Node {
    int data;
    struct Node* next;
};

//Structure for crcular queue with front and rear pointers
struct Queue {
    struct Node *front, *rear;
};

//Creating new circular queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

//For inserting element in circular queue
void Insert(struct Queue* q) 
{
    int value;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Heap overflow!\n");
        return;
    }
    
    printf("Enter the value :");
    scanf("%d",&value);
    newNode->data = value;
    newNode->next = NULL;
    
    if (q->rear == NULL) 
    {
        q->front = q->rear = newNode;
        newNode->next = q->front; // Circular link
    } 
    else 
    {
        newNode->next = q->front; // Circular link
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

//for deleting the element from circular queue
void Delete(struct Queue* q) 
{
    if (q->front == NULL) {
        printf("Queue underflow!\n");
        return;
    }
    struct Node* temp = q->front;
    int deletedValue = temp->data;
    
    printf("Deleted element : %d\n",deletedValue);
    if (q->front == q->rear) 
    {
        q->front = q->rear = NULL;
    } 
    else 
    {
        q->front = q->front->next;

        // Maintain circular link
        q->rear->next = q->front; 
    }
    
    //for freeing up the memory
    free(temp);
}

//For displaying the elements of queue
void Display(struct Queue* q) 
{
    if (q->front == NULL) 
    {
        printf("Queue is empty!\n");
        return;
    }
    struct Node* temp = q->front;

    printf("Circular Queue elements:\n");
    printf("[ ");
    do
    {
        printf("%d,", temp->data);
        temp = temp->next;
    } while (temp != q->front);

    printf(" ]\n");
}

int main() 
{
    struct Queue* cqueue = createQueue();
    
    int ch;
    char op;

    //infinite loop
    while (1) 
    {
        printf("\nDo you want to enter the menu? [Y/n]): ");
        scanf(" %c",&op); 

        //checking condition for YES
        if (op == 'Y' || op == 'y') 
        {
            printf("Menu:\n1. Insert an element\n2. Delete an element\n3. Display the Circular Queue\n4. Exit\nChoose an option: ");
            scanf("%d", &ch);
            
            //cases
            switch(ch) 
            {
                case 1:
                    Insert(cqueue);
                    break;
                case 2:
                    Delete(cqueue);
                    break;
                case 3:
                    Display(cqueue);
                    break;
                case 4:
                    exit(0);
                default:
                    printf("Entered wrong choice!\n");
                    break;
            }
        } 
        else 
        {
            printf("Exiting...\n");
            break;
        }
    }

    return 0;
}
