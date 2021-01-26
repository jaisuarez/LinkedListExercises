#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;                   // Node data
    struct node *nextPtr;       // Address to the next node
};

struct node *firstNode;         // Address to the first node of the circular linked list

// Create circular linked list with specified number of nodes
void createCircularLinkedList(int numberOfNodes);

// Insert a node at the beginning of the circular linked list
void insertNodeAtBeginning(int nodeData);

// Display data of the circular linked list
void displayCircularLinkedList();

int main()
{
    int numberOfNodes;
    int nodeData;

    // Initialize first node of the circular linked list
    firstNode = NULL;

    printf("Input the number of nodes : ");
    scanf("%d", &numberOfNodes);

    createCircularLinkedList(numberOfNodes);

    printf("\nData entered in the list are :\n");
    displayCircularLinkedList();

    printf("Input data to be inserted at the beginning : ");
    scanf("%d", &nodeData);
    insertNodeAtBeginning(nodeData);

    printf("\nAfter insertion the new list are : \n");
    displayCircularLinkedList();

    return 0;
}

void createCircularLinkedList(int numberOfNodes)
{
    int nodeCtr;
    int nodeData;
    struct node *previousNode;
    struct node *newNode;

    // Generate a circular linked list if the provided number of nodes
    // is a positive non-zero number
    if (numberOfNodes >= 1)
    {
        // Allocate memory for the first node
        firstNode = (struct node *)malloc(sizeof(struct node));

        printf("Input data for node 1 : ");
        scanf("%d", &nodeData);

        // Initialize first node
        firstNode->data = nodeData;
        firstNode->nextPtr = NULL;

        // Initialize previous node
        previousNode = firstNode;

        // Loop until the number of nodes are created
        for (nodeCtr = 2; nodeCtr <= numberOfNodes; nodeCtr++)
        {
            // Allocate memory for the new node
            newNode = (struct node *)malloc(sizeof(struct node));

            printf("Input data for node %d : ", nodeCtr);
            scanf("%d", &nodeData);

            // Initialize new nodes
            newNode->data = nodeData;
            newNode->nextPtr = NULL;

            // Link new node to the circular linked list
            previousNode->nextPtr = newNode;

            // Update the previous node
            previousNode = newNode;
        }

        // Link the last node to the first node to make it circular
        previousNode->nextPtr = firstNode;
    }
}

void insertNodeAtBeginning(int nodeData)
{
    struct node *newNode;
    struct node *currentNode;

    // Verify that the list is not empty
    if (firstNode == NULL)
    {
        printf("No data found in the list yet.");
    }
    else
    {
        // Allocate memory to the new node
        newNode = (struct node *)malloc(sizeof(struct node));

        // Initialize new node
        newNode->data = nodeData;
        newNode->nextPtr = NULL;

        // Link new node to the circular linked list
        newNode->nextPtr = firstNode;

        // Initialize current node
        currentNode = firstNode;

        // Find the node that points to the first node
        while (currentNode->nextPtr != firstNode)
        {
            currentNode = currentNode->nextPtr;
        }

        // Link the last node to point to the new node
        currentNode->nextPtr = newNode;

        // Set the new node as the first node of the circular linked list
        firstNode = newNode;
    }
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
        // Set the first node as the current node
        currentNode = firstNode;

        // Loop until all the nodes in the circular linked list is traversed
        do
        {
            printf("Data %d = %d\n", nodeCtr, currentNode->data);

            // Go to the next node
            currentNode = currentNode->nextPtr;
            nodeCtr++;
        } while (currentNode != firstNode);
    }
}