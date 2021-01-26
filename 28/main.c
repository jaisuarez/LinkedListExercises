#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;                   // Node data
    struct node *nextPtr;       // Address to the next node
};

struct node *firstNode;     // Address to the first node of the circular linked list
struct node *lastNode;      // Address to the last node of the circular linked list

// Create circular linked list based on the specified number of nodes
void createCircularLinkedList(int numberOfNodes);

// Find node in the circular linked list
int findNodePosition(int nodeData, int numberOfNodes);

// Display circular linked list
void displayCircularLinkedList();

int main()
{
    int numberOfNodes;
    int nodeDataToFind;
    int nodePosition;

    // Initialize first and last node of the circular linked list
    firstNode = NULL;
    lastNode = NULL;

    printf("Input the number of nodes : ");
    scanf("%d", &numberOfNodes);

    createCircularLinkedList(numberOfNodes);
    displayCircularLinkedList();

    printf("Input the element you want to find : ");
    scanf("%d", &nodeDataToFind);

    nodePosition = findNodePosition(nodeDataToFind, numberOfNodes);

    if (nodePosition < numberOfNodes)
    {
        printf("Element found at node %d\n\n", nodePosition);
    }
    else
    {
        printf("This element does not exist in the list.\n\n");
    }

    return 0;
}

void createCircularLinkedList(int numberOfNodes)
{
    int nodeCtr;
    int nodeData;
    struct node *currentNode;
    struct node *newNode;

    // Verify that the specified number of nodes is a positive non-zero number
    if (numberOfNodes >= 1)
    {
        // Allocate memory of the first node
        firstNode = (struct node *)malloc(sizeof(struct node));

        printf("Input data for node 1 : ");
        scanf("%d", &nodeData);

        // Initialize first node
        firstNode->data = nodeData;
        firstNode->nextPtr = NULL;

        // Initialize current node to point to the first node's address
        currentNode = firstNode;

        // Loop until the specified number of nodes are generated
        for (nodeCtr = 2; nodeCtr <= numberOfNodes; nodeCtr++)
        {
            // Allocate memory for the new node
            newNode = (struct node *)malloc(sizeof(struct node));

            printf("Input data for node %d : ", nodeCtr);
            scanf("%d", &nodeData);

            // Initialize new node
            newNode->data = nodeData;
            newNode->nextPtr = NULL;

            // Link the new node to the circular linked list
            currentNode->nextPtr = newNode;

            // Set the new node as the current node
            currentNode = newNode;
        }

        // Link the last node created to the first node to complete
        // the circular linked list
        currentNode->nextPtr = firstNode;
    }
}

int findNodePosition(int nodeData, int numberOfNodes)
{
    int nodeCtr = 1;

    // Set the last node's address to be the same as the first node
    lastNode = firstNode;

    // Loop until the data is found or all the nodes are traversed
    while (lastNode->nextPtr != NULL)
    {
        if (lastNode->data == nodeData)
        {
            // Node data is found, return
            break;
        }
        else
        {
            // Track the number of nodes that are traversed
            nodeCtr++;
        }

        // Go to the next node
        lastNode = lastNode->nextPtr;

        // All nodes are traversed so exit
        if (nodeCtr == numberOfNodes + 1)
        {
            break;
        }
    }

    return nodeCtr;
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
        // Set the initial node to be traversed
        currentNode = firstNode;

        printf("\n\nData entered in the list are :\n");

        // Loop until the last node of the circular linked list is reached
        do
        {
            printf("Data %d = %d\n", nodeCtr, currentNode->data);

            // Traversed to the next node
            currentNode = currentNode->nextPtr;

            // Track the number of nodes that were traversed
            nodeCtr++;
        } while (currentNode != firstNode);
    }
}

