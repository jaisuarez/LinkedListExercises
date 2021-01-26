#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;                       // Node
    struct node *previousPtr;       // Address to the previus node
    struct node *nextPtr;           // Address to the next node
};

struct node *firstNode;     // Address to the first node of the double linked list
struct node *lastNode;      // Address to the last node of the double linked list

// Generates a double linked list with the indicated number of nodes
void createDoubleLinkedList(int numberOfNodes);

// Deletes the node in the specified position
void deleteNodeFromDoubleLinkedList(int nodePosition);

// Displays the node in the double linked list
void displayDoubleLinkedList();

int main()
{
    int numberOfNodes;
    int nodePosition;

    // Initialize the first and last node of the double linked list
    firstNode = NULL;
    lastNode = NULL;

    printf("Input the number of nodes (3 or more) : ");
    scanf("%d", &numberOfNodes);

    createDoubleLinkedList(numberOfNodes);

    printf("\nData entered in the list are :\n");
    displayDoubleLinkedList();

    printf("Input the position (2 to %d) to delete a node : ", numberOfNodes - 1);
    scanf("%d", &nodePosition);

    // Validate if node position is valid. If invalid, do not continue
    // with deletion
    if (nodePosition <= 1 || nodePosition >= numberOfNodes)
    {
        printf("\nInvalid position.\n");
    }
    else
    {
        deleteNodeFromDoubleLinkedList(nodePosition);

        printf("\nAfter deletion the new list are :\n");
        displayDoubleLinkedList();
    }

    return 0;
}

void createDoubleLinkedList(int numberOfNodes)
{
    int nodeCtr;
    int nodeData;
    struct node *newNode;

    // Generate a double linked list if the indicated number of node is a
    // positive non-zero number
    if (numberOfNodes >= 1)
    {
        // Allocate memory for the first node of the double linked list
        firstNode = (struct node *)malloc(sizeof(struct node));

        // Proceed with double linked list generation if memory allocation for the
        // first node is successful
        if (firstNode != NULL)
        {
            printf("Input data for node 1 : ");
            scanf("%d", &nodeData);

            // Initialize first node
            firstNode->data = nodeData;
            firstNode->previousPtr = NULL;
            firstNode->nextPtr = NULL;

            // Initialize last node
            lastNode = firstNode;

            // Loop until the number of nodes for the double linked
            // list is generated
            for (nodeCtr = 2; nodeCtr <= numberOfNodes; nodeCtr++)
            {
                // Allocate memory for a new node
                newNode = (struct node *)malloc(sizeof(struct node));

                // Proceed if memory allocation of new node is successful
                if (newNode != NULL)
                {
                    printf("Input data for node %d : ", nodeCtr);
                    scanf("%d", &nodeData);

                    // Initialize new node
                    newNode->data = nodeData;
                    newNode->previousPtr = NULL;
                    newNode->nextPtr = NULL;

                    // Link the new node to the nodes in the double linked list
                    newNode->previousPtr = lastNode;
                    lastNode->nextPtr = newNode;

                    // Update the last node of the double linked list
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

void deleteNodeFromDoubleLinkedList(int nodePosition)
{
    struct node *currentNode;
    int nodeCtr;

    // Initialize the current node
    currentNode = firstNode;

    // Loop until the node in the specified position is found
    for (nodeCtr = 1; nodeCtr < nodePosition && currentNode != NULL; nodeCtr++)
    {
        currentNode = currentNode->nextPtr;
    }

    if (currentNode != NULL)
    {
        // Unlink the node to be deleted from the double linked list
        currentNode->previousPtr->nextPtr = currentNode->nextPtr;
        currentNode->nextPtr->previousPtr = currentNode->previousPtr;

        // Free memory allocation for the unlinked node
        free(currentNode);
    }
    else
    {
        printf("The given position is invalid!\n");
    }
}

void displayDoubleLinkedList()
{
    struct node *currentNode;
    int nodeCtr = 1;

    if (firstNode == NULL)
    {
        printf("No data found in the List yet.");
    }
    else
    {
        // Initialize current node
        currentNode = firstNode;

        // Loop through all the nodes in the double linked list
        while (currentNode != NULL)
        {
            printf("node %d : %d\n", nodeCtr, currentNode->data);

            nodeCtr++;

            // Traverse to the next node
            currentNode = currentNode->nextPtr;
        }
    }
}