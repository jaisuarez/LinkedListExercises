#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
    int data;                   // Node data
    struct node *previousPtr;   // Address to the previous node
    struct node *nextPtr;       // Address to the next node
};

struct node *firstNode;     // Address to the first node of the linked list
struct node *lastNode;      // Address to the last node of the linked list

// Creates a linked list with the specified number of nodes
void createDoubleLinkedList(int numberOfNodes);

// Returns the node that holds the largest data
int getNodeWithMaximumValue(struct node *startingNode);

// Displays the double linked list
void displayDoubleLinkedList();

int main()
{
    int numberOfNodes;

    // Initialize the first and last node of the double linked list
    firstNode = NULL;
    lastNode = NULL;

    printf("Input the number of nodes : ");
    scanf("%d", &numberOfNodes);

    createDoubleLinkedList(numberOfNodes);
    displayDoubleLinkedList();

    printf("\nThe maximum value in the linked list : %d\n", getNodeWithMaximumValue(firstNode));

    return 0;
}

void createDoubleLinkedList(int numberOfNodes)
{
    int nodeCtr;
    int nodeData;
    struct node *newNode;

    // The number of nodes must be a positive non-zero number
    if (numberOfNodes >= 1)
    {
        // Allocate memory to the first node of the double linked list
        firstNode = (struct node *)malloc(sizeof(struct node));

        // Continue if memory was successfully allocated
        // Otherwise, do not continue
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

            // Loop until the complete number of nodes are created
            for (nodeCtr = 2; nodeCtr <= numberOfNodes; nodeCtr++)
            {
                // Allocate memory for a new node
                newNode = (struct node *)malloc(sizeof(struct node));

                // Continue if memory was successfully allocated.
                // Otherwise, return.
                if (newNode != NULL)
                {
                    printf("Input data for node %d : ", nodeCtr);
                    scanf("%d", &nodeData);

                    // Initialize the new node
                    newNode->data = nodeData;
                    newNode->previousPtr = NULL;
                    newNode->nextPtr = NULL;

                    // Link the new node to the double linked list
                    newNode->previousPtr = lastNode;
                    lastNode->nextPtr = newNode;

                    // Update the last node
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

int getNodeWithMaximumValue(struct node *startingNode)
{
    // Return if the starting node is null
    if (startingNode == NULL)
    {
        printf("Invalid Input\n");

        return INT_MIN;
    }

    // Assume that the starting node has the maximum value
    int maximumValue = startingNode->data;
    struct node *currentNode = startingNode;

    // Loop until all the nodes in the double linked list is traversed
    while (currentNode != NULL)
    {
        // If the current node has a larger value than the assigned maximum value,
        // save the larger value as the new maximum value
        if (currentNode->data > maximumValue)
        {
            maximumValue = currentNode->data;
        }

        // Go to the next node
        currentNode = currentNode->nextPtr;
    }

    return maximumValue;
}

void displayDoubleLinkedList()
{
    struct node *currentNode;
    int nodeCtr = 1;

    // Verify that the double linked list is not empty
    if (firstNode == NULL)
    {
        printf("No data found in the list yet.");
    }
    else
    {
        // Copy the address of the first node
        currentNode = firstNode;

        printf("\n\nData entered in the list are : \n");

        // Loop until all the nodes in the double linked list is traversed
        while (currentNode != NULL)
        {
            printf("node %d : %d\n", nodeCtr, currentNode->data);
            nodeCtr++;

            // Go to the next node
            currentNode = currentNode->nextPtr;
        }
    }
}