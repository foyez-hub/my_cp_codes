#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    int value;
    Queue* next;
    Queue* prev;
};
Queue* head = NULL;
Queue* tail = NULL;

Queue* createQueue(int value)
{
    Queue* temp = (Queue *)malloc(sizeof(Queue));
    temp->value = value;
    temp->next = temp->prev = NULL;
    return temp;
}

bool isEmpty()
{


}

int length()
{


}

int Front()
{
    return head->value;

}

void push(int value)
{
    Queue* node=createQueue(value);

    if(head==NULL){
            head=node;
    }

    if(tail==NULL){
        tail=node;
    }
    else{
       tail->next=node;
        node->prev=tail;
         tail=node;
    }

}

void pop()
{
    head->next->prev=NULL;
    head=head->next;

}

int main()
{
    // push(10);
    // push(12);
    // push(14);
    // push(11);
    push(9);
    push(14);
    pop();
    pop();
    push(120);
    printf("Front element: %d\n", Front());
    pop();
    pop();
    pop();
    pop();

    if(isEmpty())
        printf("Queue is Empty.\n");
    else
        printf("Queue is not empty.\n");


    printf("Length of the Queue is: %d\n", length());

    return 0;
}
