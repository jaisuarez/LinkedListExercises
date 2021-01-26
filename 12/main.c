#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;                   // Node data
    struct node *prevPtr;       // Pointer to the previous node in the list
    struct node *nextPtr;       // Pointer to the next node in the list
};

struct node *firstNode;         // Pointer to the first node
struct node *lastNode;          // Pointer to the last node

// Generate double link list with specified number of nodes
void createDoubleLinkList(int numberOfNodes);

// Insert a node at the beginning of the double link list
void insertNodeAtBeginningOfList(int nodeData);

// Display double link list
void displayDoubleLinkList();

int main()
{
    int numberOfNodes;
    int nodeData;

    firstNode = NULL;
    lastNode = NULL;

    printf("Input the number of nodes : ");
    scanf("%d", &numberOfNodes);

    createDoubleLinkList(numberOfNodes);

    printf("\nData entered in the list are : \n");
    displayDoubleLinkList();

    printf("Input data for the first node : ");
    scanf("%d", &nodeData);

    printf("\nAfter insertion the new list is :\n");
    insertNodeAtBeginningOfList(nodeData);
    displayDoubleLinkList();

    return 0;
}

void createDoubleLinkList(int numberOfNodes)
{
    int nodeCtr;
    int nodeData;
    struct node *newNode;

    // The number of node to generate must be a positive number
    if (numberOfNodes >= 1)
    {
        // Allocate memory to the first node
        firstNode = (struct node *)malloc(sizeof(struct node));

        // Only proceed if memory allocation is successful
        if (firstNode != NULL)
        {
            // Request input from user for node data
            printf("Input data for node 1 : ");
            scanf("%d", &nodeData);

            // Initialize node
            firstNode->data = nodeData;
            firstNode->prevPtr = NULL;
            firstNode->nextPtr = NULL;

            // Point the supposed last node to the address of the first node
            lastNode = firstNode;

            // Loop until all nodes are generated
            for (nodeCtr = 2; nodeCtr <= numberOfNodes; nodeCtr++)
            {
                // Allocate memory for a new node
                newNode = (struct node *)malloc(sizeof(struct node));

                // Proceed if memory allocation was successful
                if (newNode != NULL)
                {
                    // Request node data from user
                    printf("Input data for node %d : ", nodeCtr);
                    scanf("%d", &nodeData);

                    // Initialize new node
                    newNode->data = nodeData;
                    newNode->prevPtr = NULL;
                    newNode->nextPtr = NULL;

                    // Link the new node and the last node of the list
                    newNode->prevPtr = lastNode;
                    lastNode->nextPtr = newNode;

                    // Set the new node as the last node of the list
                    lastNode = newNode;
                }
                else
                {
                    printf("Memory can not be allocated.");
                    break;
                }
            }
        }
        else
        {
            printf("Memory can not be allocated.");
        }
    }
}

void insertNodeAtBeginningOfList(int nodeData)
{
    struct node *newNode;

    // Do not proceed if node list is empty
    if (firstNode == NULL)
    {
        printf("No data found in the list!\n");
    }
    else
    {
        // Allocate memory to the new node
        newNode = (struct node *)malloc(sizeof(struct node));

        // Initialize new node
        newNode->data = nodeData;
        newNode->nextPtr = NULL;
        newNode->prevPtr = NULL;

        // Link the new node and the current first node of the list
        newNode->nextPtr = firstNode;
        firstNode->prevPtr = newNode;

        // Set the new node as the list's first node
        firstNode = newNode;
    }
}

void displayDoubleLinkList()
{
    struct node *currentNode;
    int nodeCtr = 1;

    // Verify that the list is not empty
    if (firstNode == NULL)
    {
        printf("No data found in the list yet.");
    }
    else
    {
        // Set the list's first node as the current node
        currentNode = firstNode;

        // Loop until the last node of the list is reached
        while (currentNode != NULL)
        {
            // Print the data of the current node
            printf("node %d : %d\n", nodeCtr, currentNode->data);
            nodeCtr++;

            // Go to the next node
            currentNode = currentNode->nextPtr;
        }
    }
}