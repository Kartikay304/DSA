#include<stdio.h>   
#include<stdlib.h>  
typedef struct node  
{  
    int data;   
    struct node *next;  
}N;  
N *front;  
N *rear;   
void enqueue();  
void dequeue();  
void display();  
void main ()  
{  
    int choice;   
    while(1)   
    {     
        printf("\nMENU\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");  
        printf("\nEnter your choice::");  
        scanf("%d",& choice);  
        switch(choice)  
        {  
            case 1: enqueue(); break;  
            case 2: dequeue(); break;  
            case 3: display(); break;  
            case 4: exit(0);   break;
        }  
    }  
}  
void enqueue()  
{  
    N *ptr;  
    int item;   
      
    ptr = (N *) malloc (sizeof(N));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    else  
    {   
        printf("\nEnter value::");  
        scanf("%d",&item);  
        ptr -> data = item;  
        if(front == NULL)  
        {  
            front = ptr;  
            rear = ptr;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   
        {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        }  
    }  
}     
void dequeue ()  
{  
    N *ptr;  
    if(front == NULL)  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
    }  
    else   
    {  
        ptr = front;  
        front = front -> next;  
        free(ptr);  
    }  
}  
void display()  
{  
    N *ptr;  
    ptr = front;      
    if(front == NULL)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nprinting values .....\n");  
        while(ptr != NULL)   
        {  
            printf("%d ",ptr -> data);  
            ptr = ptr -> next;  
        }  
    }  
}  