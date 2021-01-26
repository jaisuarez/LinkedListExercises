#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;                   // Node
    struct node *nextPtr;       // Address to the next node
};

struct node *firstNode;     // Address of the first node of the
                            // circular linked list

// Create a circular linked list with the specified number of nodes
void createCircularLinkedList(int numberOfNodes);

// Delete the last node of the circular linked list
void deleteLastNode();

// Display circular linked list
void displayCircularLinkedList();

int main()
{
    int numberOfNodes;

    // Initialize first node of the circular linked list
    firstNode = NULL;

    printf("Input the number of nodes : ");
    scanf("%d", &numberOfNodes);

    createCircularLinkedList(numberOfNodes);

    printf("\nData entered in the list are :\n");
    displayCircularLinkedList();

    deleteLastNode();

    printf("\nAfter deletion the new list are :\n");
    displayCircularLinkedList();

    return 0;
}

void createCircularLinkedList(int numberOfNodes)
{
    int nodeCtr;
    int nodeData;
    struct node *currentNode;
    struct node *newNode;

    // Verify that the specified number of node is a positive
    // non-zero number
    if (numberOfNodes >= 1)
    {
        // Allocate memory to the first node of the circular linked list
        firstNode = (struct node *)malloc(sizeof(struct node));

        printf("Input data for node 1 : ");
        scanf("%d", &nodeData);

        // Initialize first node
        firstNode->data = nodeData;
        firstNode->nextPtr = NULL;

        // Initialize the current node
        currentNode = firstNode;

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

            // Link the new node to the circular linked list
            currentNode->nextPtr = newNode;

            // Point to the new node
            currentNode = newNode;
        }

        // Link the generated last node to the first node to
        // complete the circular linked list
        currentNode->nextPtr = firstNode;
    }
}

void deleteLastNode()
{
    struct node *nodeToDelete;
    struct node *newLastNode;

    // Temporarily set the first node as the node to delete
    nodeToDelete = firstNode;

    // Find the last node of the circular linked list
    while (nodeToDelete->nextPtr != firstNode)
    {
        // The currently set node-to-delete is not the last
        // node so nominate it to be the possible
        // new last node
        newLastNode = nodeToDelete;

        // Traverse to the next node
        nodeToDelete = nodeToDelete->nextPtr;
    }

    // Unlink the existing last node from the circular linked list
    newLastNode->nextPtr = firstNode;

    printf("\nThe deleted node is : %d", nodeToDelete->data);

    // Free memory allocation
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
        // Initialize the first node as the current node
        currentNode = firstNode;

        // Loop until all the nodes are traversed
        do
        {
            printf("Data %d = %d\n", nodeCtr, currentNode->data);

            // Traversed to the next node
            currentNode = currentNode->nextPtr;
            nodeCtr++;
        } while (currentNode != firstNode);
    }
}