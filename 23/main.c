#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;                   // Node data
    struct node *nextPtr;       // Address to the next node
};

struct node *firstNode;     // Address to the first node of the circular linked list

// Create a circular linked list with the specified number of nodes
void createCircularLinkedList(int numberOfNodes);

// Insert a node at the end of the circular linked list
void insertNodeAtLastPosition(int nodeData);

// Displays the circular linked list
void displayCircularLinkedList();

int main()
{
    int numberOfNodes;
    int nodeData;

    // Initialize the first node of the circular linked list
    firstNode = NULL;

    printf("Input the number of nodes : ");
    scanf("%d", &numberOfNodes);

    createCircularLinkedList(numberOfNodes);

    printf("\nData entered in the list are :\n");
    displayCircularLinkedList();

    printf("Input the data to be inserted : ");
    scanf("%d", &nodeData);

    insertNodeAtLastPosition(nodeData);

    printf("\nAfter insertion the new list are :\n ");
    displayCircularLinkedList();

    return 0;
}

void createCircularLinkedList(int numberOfNodes)
{
    int nodeCtr;
    int nodeData;
    struct node *previousPtr;
    struct node *newNode;

    // Verify that the number of node is a positive non-zero number
    if (numberOfNodes >= 1)
    {
        // Allocate memory to the first node of the circular linked list
        firstNode = (struct node *)malloc(sizeof(struct node));

        printf("Input data for node 1 : ");
        scanf("%d", &nodeData);

        // Initialize first node
        firstNode->data = nodeData;
        firstNode->nextPtr = NULL;

        // Initialize previous pointer address
        previousPtr = firstNode;

        // Loop until the total number of nodes are generated
        for (nodeCtr = 2; nodeCtr <= numberOfNodes; nodeCtr++)
        {
            // Allocate memory to the new node
            newNode = (struct node *)malloc(sizeof(struct node));

            printf("Input data for node %d : ", nodeCtr);
            scanf("%d", &nodeData);

            // Initialize new node
            newNode->data = nodeData;
            newNode->nextPtr = NULL;

            // Link the new node to the existing circular linked list
            previousPtr->nextPtr = newNode;

            // Update the previous pointer
            previousPtr = newNode;
        }

        // Connect the last of the node to the first node to make
        // it a circular linked list
        previousPtr->nextPtr = firstNode;
    }
}

void insertNodeAtLastPosition(int nodeData)
{
    struct node *newNode;
    struct node *currentNode;

    // Allocate memory to the new node
    newNode = (struct node *)malloc(sizeof(struct node));

    // Initialize new node
    newNode->data = nodeData;
    newNode->nextPtr = NULL;

    // Initialize current node
    currentNode = firstNode;

    // Loop until the last node in the circular list is found
    while (currentNode->nextPtr != firstNode)
    {
        currentNode = currentNode->nextPtr;
    }

    // Link the new node after the last node of the circular linked list
    currentNode->nextPtr = newNode;

    // Link the new node to the first node of the circular linked list
    newNode->nextPtr = firstNode;
}

void displayCircularLinkedList()
{
    struct node *currentNode;
    int nodeCtr = 1;

    // Verify that the circular linked list is not empty
    if (firstNode == NULL)
    {
        printf("No data found in the list yet.");
    }
    else
    {
        currentNode = firstNode;

        // Loop until all the nodes of the circular linked list are traversed
        do
        {
            printf("Data %d = %d\n", nodeCtr, currentNode->data);

            // Go to the next node
            currentNode = currentNode->nextPtr;
            nodeCtr++;
        } while (currentNode != firstNode);
    }
}