#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;                   // Node data
    struct node *nextPtr;       // Address to the next node
};

struct node *firstNode;     // Address to the first node of the circular linked list

// Create circular linked list with the specified number of nodes
void createCircularLinkedList(int numberOfNodes);

// Delete node from a specified position
void deleteNodeFromSpecifiedPosition(int nodePosition);

// Display circular linked list
void displayCircularLinkedList();

int main()
{
    int numberOfNodes;
    int nodePosition;

    // Initialize first node
    firstNode = NULL;

    printf("Input the number of nodes : ");
    scanf("%d", &numberOfNodes);

    createCircularLinkedList(numberOfNodes);

    printf("\nData entered in the list are :\n");
    displayCircularLinkedList();

    printf("\nInput the position to delete the node : ");
    scanf("%d", &nodePosition);

    deleteNodeFromSpecifiedPosition(nodePosition);

    printf("\nAfter deletion the new list are :\n");
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

        // Loop until all the nodes are created
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
            previousNode = newNode;
        }

        // Link the last node to the first node to complete circular linked list
        previousNode->nextPtr = firstNode;
    }
}

void deleteNodeFromSpecifiedPosition(int nodePosition)
{
    struct node *currentNode;
    struct node *previousNode;
    int nodeToDelete;
    int nodeCtr = 1;

    // Initialize node to delete
    nodeToDelete = nodePosition;

    // Initialize current node
    currentNode = firstNode;

    // Find the node that is to be deleted
    while (nodeCtr != nodeToDelete)
    {
        previousNode = currentNode;
        currentNode = currentNode->nextPtr;
        nodeCtr++;
    }

    // Unlink the current node that is to be deleted
    previousNode->nextPtr = currentNode->nextPtr;

    printf("\nThe deleted node is : %d", currentNode->data);

    // Free memory of the unlinked node
    free(currentNode);
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
        // Initialize current node
        currentNode = firstNode;

        // Loop until all the nodes are traversed
        do
        {
            printf("Data %d = %d\n", nodeCtr, currentNode->data);

            // Go to the next node
            currentNode = currentNode->nextPtr;
            nodeCtr++;
        } while (currentNode != firstNode);
    }
}