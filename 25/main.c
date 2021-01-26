#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;                   // Node data
    struct node *nextPtr;       // Address to the next node
};

struct node *firstNode;     // Address to the first node of the
                            // circular linked list

// Create circular linked list with the specified number of nodes
void createCircularLinkedList(int numberOfNodes);

// Delete the first node of the circular linked list
void deleteFirstNodeofCircularLinkedList();

// Display the circular linked list
void displayCircularLinkedList();

int main()
{
    int numberOfNodes;

    // Initialize first node of the circular linked list
    firstNode = NULL;

    printf("Input the number of nodes : ");
    scanf("%d", &numberOfNodes);

    createCircularLinkedList(numberOfNodes);

    printf("\nData entered in the list are : \n");
    displayCircularLinkedList();

    deleteFirstNodeofCircularLinkedList();

    printf("\nAfter deletion the new list is :\n");
    displayCircularLinkedList();

    return 0;
}

void createCircularLinkedList(int numberOfNodes)
{
    int nodeCtr;
    int nodeData;
    struct node *previousNode;
    struct node *newNode;

    // Create circular linked list if the number of nodes is a
    // non-zero positive number
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

        // Loop until all the nodes are generated
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

        // Link the last node to the first node to complete the
        // circular linked list
        previousNode->nextPtr = firstNode;
    }
}

void deleteFirstNodeofCircularLinkedList()
{
    struct node *currentNode;
    struct node *nodeToDelete;

    // Initialize the current node
    currentNode = firstNode;

    // Loop until the last node of the circular linked list is
    // found
    while (currentNode->nextPtr != firstNode)
    {
        currentNode = currentNode->nextPtr;
    }

    // Set the add of the node to delete
    nodeToDelete = firstNode;

    // Update the newly assigned first node
    firstNode = firstNode->nextPtr;

    printf("\nThe deleted node is %d", nodeToDelete->data);

    // Point to the last node to the new first node
    currentNode->nextPtr = firstNode;

    // Free the memory of the unlinked node
    free(nodeToDelete);
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

        // Loop until all the nodes in the circular linked list
        // are displayed
        do
        {
            printf("Data %d = %d\n", nodeCtr, currentNode->data);

            // Go to the next node
            currentNode = currentNode->nextPtr;
            nodeCtr++;
        } while (currentNode != firstNode);
    }
}