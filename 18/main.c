#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;                       // Node data
    struct node *previousPtr;       // Address of the previous node
    struct node *nextPtr;           // Address of the next node
};

struct node *firstNode; // Address of the first node of the double linked list
struct node *lastNode;  // Address of the last node of the double linked list

// Generates a double linked list with the specified number of nodes
void createDoubleLinkedList(int numberOfNodes);

// Deletes the first node of the double linked list
void deleteFirstNode();

// Deletes the last node of the double linked list
void deleteLastNode();

// Deletes the specified node of the double linked list
void deleteSpecifiedNode(int nodePosition);

// Displays the double linked list
void displayDoubleLinkedList();

int main()
{
    int numberOfNodes;      // Holds the number of nodes to create for the
                            // double linked list
    int nodePosition;       // Holds the position of the node to be deleted

    // Initialize the first and last node of the double linked list
    firstNode = NULL;
    lastNode = NULL;

    printf("Input the number of nodes (3 or more): ");
    scanf("%d", &numberOfNodes);

    // Generate the double linked list with the specified number of nodes
    createDoubleLinkedList(numberOfNodes);

    printf("\nData entered in the list are :\n");
    displayDoubleLinkedList();

    printf("\nInput the position (1 to %d) to delete a node : ", numberOfNodes);
    scanf("%d", &nodePosition);

    // Check if the node position is valid. Do not process deletion if it is
    // invalid.
    if (nodePosition < 1 || nodePosition > numberOfNodes)
    {
        printf("\nInvalid position.\n");
    }
    else
    {
        deleteSpecifiedNode(nodePosition);
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
        firstNode = (struct node *) malloc(sizeof(struct node));

        // Proceed with double linked list generation if memory allocation
        // for the first node is successful
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

void deleteSpecifiedNode(int nodePosition)
{
    struct node *currentNode;
    int nodeCtr;

    // Initialize the current node
    currentNode = firstNode;

    // Loop until the node in the specified position is found
    for(nodeCtr = 1; nodeCtr < nodePosition && currentNode != NULL; nodeCtr++)
    {
        currentNode = currentNode->nextPtr;
    }

    if (nodePosition == 1)
    {
        deleteFirstNode();
    }
    else if (currentNode == lastNode)
    {
        deleteLastNode();
    }
    else if (currentNode != NULL)
    {
        // Unlink the node to be deleted from the double linked list
        currentNode->previousPtr->nextPtr = currentNode->nextPtr;
        currentNode->nextPtr->previousPtr = currentNode->previousPtr;

        // Free memory allocation for the unlinked node
        free(currentNode);
    }
    else
    {
        printf("The given position is invalid.\n");
    }
}

void deleteFirstNode()
{
    struct node *nodeToDelete;

    if (firstNode == NULL)
    {
        printf("Delete is not possible. No data in the list.\n");
    }
    else
    {
        // Set the node to delete
        nodeToDelete = firstNode;

        // Unlink the current first node from the double linked list
        firstNode = firstNode->nextPtr;
        firstNode->previousPtr = NULL;

        // Free memory allocation for the unlinked node
        free(nodeToDelete);
    }
}

void deleteLastNode()
{
    struct node *nodeToDelete;

    if (lastNode == NULL)
    {
        printf("Delete is not possible. No data in the list. \n");
    }
    else
    {
        // Set the node to delete
        nodeToDelete = lastNode;

        // Unlink the current last node from the double linked list
        lastNode = lastNode->previousPtr;
        lastNode->nextPtr = NULL;

        // Free memory allocation for the unlinked node
        free(nodeToDelete);
    }
}

void displayDoubleLinkedList()
{
    struct node *currentNode;
    int nodeCtr = 1;

    if (firstNode == NULL)
    {
        printf("No data found in the list yet.");
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