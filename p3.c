#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head, *temp, *newnode;

int main()
{
    int n, i;
    scanf("%d", &n);
    head = NULL;
    printf("Enter the inputs");
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;  // Initialize next pointer

        if (head == NULL)
        {
            head = newnode;
            temp = newnode; // Update temp to point to the first node
        }
        else
        {
            temp->next = newnode;
            temp = newnode; // Update temp to point to the new node
        }
    }

    struct node *prev, *curr, *next;
    prev = NULL;
    curr = head;
    next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
    temp = head;

    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            printf("%d ", temp->data);
        }
        temp = temp->next;
    }
    
    temp = head;  // Reset temp to the head for odd numbers

    while (temp != NULL)
    {
        if (temp->data % 2 != 0)
        {
            printf("%d ", temp->data);
        }
        temp = temp->next;
    }

    return 0;
}
