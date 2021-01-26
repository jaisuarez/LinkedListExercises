#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;                       // Node data
    struct node *previousPtr;       // Address to the previous node
    struct node *nextPtr;           // Address to the next node
};

struct node *firstNode;         // Always points to the first node of the double link list
struct node *lastNode;          // Always points to the last node of the double link list

// Creates a double linked list with the specified number of nodes
void createDoubleLinkedList(int numberOfNodes);

// Insert new node at the middle of the double linked list
void insertNodeAtMiddle(int nodeData, int nodePosition);

// Display double linked list
void displayDoubleLinkList();

int main()
{
    int numberOfNodes;              // Number of nodes to create
    int nodePosition;               // Position to insert the new node to
    int nodeData;                   // The new node's data

    // Initialize first and last node of the double linked list
    firstNode = NULL;
    lastNode = NULL;

    printf("Input the number of nodes (3 or more) : ");
    scanf("%d", &numberOfNodes);

    createDoubleLinkedList(numberOfNodes);

    printf("\nData entered in the list are : \n");
    displayDoubleLinkList();

    printf("Input the position (2 to %d) to insert a new node : ", numberOfNodes - 1);
    scanf("%d", &nodePosition);

    // Do not proceed if node position is invalid
    if (nodePosition <= 1 || nodePosition >= numberOfNodes)
    {
        printf("\nInvalid node position.\n");
    }
    else
    {
        printf("Input data for the position %d : ", nodePosition);
        scanf("%d", &nodeData);

        insertNodeAtMiddle(nodeData, nodePosition);

        printf("\nAfter insertion the new list is :\n");
        displayDoubleLinkList();
    }

    return 0;
}

void createDoubleLinkedList(int numberOfNodes)
{
    int nodeCtr;
    int nodeData;
    struct node *newNode;

    if (numberOfNodes >= 1)
    {
        // Allocate memory to the first node of the double linked list
        firstNode = (struct node *)malloc(sizeof(struct node));

        // Do not generate double linked list if memory allocation failed
        if (firstNode != NULL)
        {
            printf("Input data for node 1 : ");
            scanf("%d", &nodeData);

            // Initialize first node
            firstNode->data = nodeData;
            firstNode->previousPtr = NULL;
            firstNode->nextPtr = NULL;

            // Set the last node to same position as the first node
            lastNode = firstNode;

            for (nodeCtr = 2; nodeCtr <= numberOfNodes; nodeCtr++)
            {
                // Allocate memory to the new node
                newNode = (struct node *)malloc(sizeof(struct node));

                // Do not append new node to the double linked list if memory allocation
                // failed
                if (newNode != NULL)
                {
                    printf("Input data for node %d : ", nodeCtr);
                    scanf("%d", &nodeData);

                    // Initialize new node
                    newNode->data = nodeData;
                    newNode->previousPtr = NULL;
                    newNode->nextPtr = NULL;

                    // Link the new node with the last node of the double linked list
                    newNode->previousPtr = lastNode;
                    lastNode->nextPtr = newNode;

                    // Set the new node as the last node of the double linked list
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

void insertNodeAtMiddle(int nodeData, int nodePosition)
{
    int nodeCtr;
    struct node *newNode;
    struct node *currentNode;

    // Do not proceed if double linked list is empty
    if (lastNode == NULL)
    {
        printf("No data found in the list!\n");
    }
    else
    {
        // Set the first node of the double linked list as the current node
        currentNode = firstNode;

        nodeCtr = 1;

        // Traverse to the indicated node position
        while (nodeCtr < nodePosition - 1 && currentNode != NULL)
        {
            // Go to the next node
            currentNode = currentNode->nextPtr;

            // Keep track of the node position being traversed
            nodeCtr++;
        }

        // Do not proceed if current node is invalid
        if (currentNode != NULL)
        {
            // Allocate memory to the new node
            newNode = (struct node *)malloc(sizeof(struct node));

            if (newNode == NULL)
            {
                printf("Could not allocate memory\n");
            }
            else
            {
                // Initialize new node
                newNode->data = nodeData;
                newNode->nextPtr = NULL;
                newNode->previousPtr = NULL;

                // Link the new node to the nodes surrounding the specified
                // position in the double linked list
                newNode->nextPtr = currentNode->nextPtr;
                newNode->previousPtr = currentNode;

                if (currentNode->nextPtr != NULL)
                {
                    currentNode->nextPtr->previousPtr = newNode;
                }

                currentNode->nextPtr = newNode;
            }
        }
        else
        {
            printf("The position you entered is invalid.\n");
        }
    }
}

void displayDoubleLinkList()
{
    struct node *currentNode;
    int nodeCtr = 1;

    // Do not proceed if memory allocation failed
    if (firstNode == NULL)
    {
        printf("No data found in the list yet.");
    }
    else
    {
        currentNode = firstNode;

        while (currentNode != NULL)
        {
            printf("node %d : %d\n", nodeCtr, currentNode->data);
            nodeCtr++;

            // Traverse to the next node
            currentNode = currentNode->nextPtr;
        }
    }
}

