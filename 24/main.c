#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;                   // Node data
    struct node *nextPtr;       // Address to the next node
};

struct node *firstNode;     // Address to the first node of the circular
                            // linked list

// Create a circular linked list with the specified number of node
void createCircularLinkedList(int numberOfNodes);

// Insert a node at the beginning of the circular linked list
void insertNodeAtBeginning(int nodeData);

// Insert node at a specified position in the circular linked list
void insertNodeAtPosition(int nodeData, int nodePosition);

// Display the circular linked list
void displayCircularLinkedList();

int main()
{
    int numberOfNodes;
    int nodeData;
    int a;
    int nodePosition;

    // Initialize first node of the circular linked list
    firstNode = NULL;

    printf("Input the number of nodes : ");
    scanf("%d", &numberOfNodes);

    createCircularLinkedList(numberOfNodes);

    printf("\nData entered in the list are :\n");
    displayCircularLinkedList();

    printf("Input the position to insert a new node : ");
    scanf("%d", &nodePosition);

    printf("Input data for the position %d : ", nodePosition);
    scanf("%d", &nodeData);

    insertNodeAtPosition(nodeData, nodePosition);

    printf("\nAfter insertion the new list are :\n");
    displayCircularLinkedList();

    return 0;
}

void createCircularLinkedList(int numberOfNodes)
{
    int nodeCtr;
    int nodeData;
    struct node *previousNode;
    struct node *newNode;

    // Verify that the number of nodes is a positive non-zero number
    if (numberOfNodes >= 1)
    {
        // Allocate memory to the first node
        firstNode = (struct node *)malloc(sizeof(struct node));

        printf("Input data for node 1 : ");
        scanf("%d", &nodeData);

        // Initialize first node
        firstNode->data = nodeData;
        firstNode->nextPtr = NULL;

        // Initialize previous node
        previousNode = firstNode;

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
            previousNode->nextPtr = newNode;

            // Update the previous node
            previousNode = newNode;
        }

        // Link the recently assigned previous node to the first node to complete
        // the circular linked list
        previousNode->nextPtr = firstNode;
    }
}

void insertNodeAtBeginning(int nodeData)
{
    struct node *newNode;
    struct node *currentNode;

    // Verify that the circular linked list is not empty
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

        // Link the new node to the existing circular linked list
        newNode->nextPtr = firstNode;

        // Initialize the current node for the loop
        currentNode = firstNode;

        // Loop until the last node of the circular linked list is found
        while (currentNode->nextPtr != firstNode)
        {
            currentNode = currentNode->nextPtr;
        }

        // Link the current last node of the circular linked list
        // to the new node
        currentNode->nextPtr = newNode;

        // Assign the new node as the first node of the circular linked list
        firstNode = newNode;
    }
}

void insertNodeAtPosition(int nodeData, int nodePosition)
{
    struct node *newNode;
    struct node *currentNode;
    int nodeCtr;

    // Verify that the circular linked list is not empty
    if (firstNode == NULL)
    {
        printf("No data found in the list yet.");
    }
    else if (nodePosition == 1)
    {
        insertNodeAtBeginning(nodeData);
    }
    else
    {
        // Allocate memory to the new node
        newNode = (struct node *)malloc(sizeof(struct node));

        // Initialize new node
        newNode->data = nodeData;
        newNode->nextPtr = NULL;

        // Initialize first node as the current node
        currentNode = firstNode;

        for (nodeCtr = 2; nodeCtr <= nodePosition - 1; nodeCtr++)
        {
            currentNode = currentNode->nextPtr;
        }

        // Link the new node to the circular linked list
        newNode->nextPtr = currentNode->nextPtr;
        currentNode->nextPtr = newNode;
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
        // Initialize the current node
        currentNode = firstNode;

        // Loop until all nodes of the circular linked list are traversed
        do
        {
            printf("Data %d = %d\n", nodeCtr, currentNode->data);

            // Go to the next node
            currentNode = currentNode->nextPtr;
            nodeCtr++;
        } while (currentNode != firstNode);
    }
}
