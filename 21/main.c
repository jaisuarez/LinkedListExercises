#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;                   // Node data
    struct node *nextPtr;       // Address to the next pointer
};

struct node *firstNode;         // Address to the first node of the
                                // Circular Linked List

// Generate a circular linked list with the specified number of nodes
void createCircularLinkedList(int numberOfNodes);

// Display contents of the circular linked list
void displayCircularLinkedList();

int main()
{
    int numberOfNodes;

    // Initialize first node of the circular linked list
    firstNode = NULL;

    printf("Input the number of nodes : ");
    scanf("%d", &numberOfNodes);

    createCircularLinkedList(numberOfNodes);

    displayCircularLinkedList();

    return 0;
}

void createCircularLinkedList(int numberOfNodes)
{
    int nodeCtr;
    int nodeData;
    struct node *previousPtr;
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

        // Set the previous pointer
        previousPtr = firstNode;

        // Loop until the total number of nodes are created
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
            previousPtr->nextPtr = newNode;

            // Update the previous node
            previousPtr = newNode;
        }

        // Link the last node to the first node to complete
        // the circular linked list
        previousPtr->nextPtr = firstNode;
    }
}

void displayCircularLinkedList()
{
    struct node *currentNode;
    int nodeCtr = 1;

    // Check if the circular linked list is not empty
    if (firstNode == NULL)
    {
        printf("No data found in the List yet.");
    }
    else
    {
        // Set the first node as the current node
        currentNode = firstNode;

        printf("\n\nData entered in the List are : \n");

        // Loop all the nodes in the circular linked list is traversed
        do
        {
            printf("Data %d = %d\n", nodeCtr, currentNode->data);

            currentNode = currentNode->nextPtr;
            nodeCtr++;
        } while (currentNode != firstNode);
    }
}