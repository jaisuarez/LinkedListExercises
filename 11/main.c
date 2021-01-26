#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;                   // Data of the node
    struct node *prevPtr;       // Points to the previous node
    struct node *nextPtr;       // Points to the next node
};

struct node *firstNode;     // Points to the first node of the list
struct node *lastNode;      // Points to the last node of the list

// Generates the doubly linked list with the
// specified number of nodes
void createDoublyLinkedList(int numberOfNodes);

// Displays all the nodes of the doubly linked list
void displayDoublyLinkedList();

int main()
{
    int numberOfNodes;

    // Initializes the pointers to first and last node of the list
    firstNode = NULL;
    lastNode = NULL;

    printf("Input the number of nodes in the list : ");
    scanf("%d", &numberOfNodes);

    // Generate the double linked list
    createDoublyLinkedList(numberOfNodes);

    // Display the data in the double linked list
    displayDoublyLinkedList();

    return 0;
}

void createDoublyLinkedList(int numberOfNodes)
{
    int nodeCtr;
    int nodeData;

    // Pointer to a new node
    struct node *newNode;

    if(numberOfNodes >= 1)
    {
        firstNode = (struct node *)malloc(sizeof(struct node));

        // Memory must be successfully allocated to add the node to the list
        if(firstNode != NULL)
        {
            // Request node data from user for the first node
            printf("Input data for node 1 : ");
            scanf("%d", &nodeData);

            // Initialize value of the first node
            firstNode->data = nodeData;
            firstNode->prevPtr = NULL;
            firstNode->nextPtr = NULL;

            // Point the first and the last node to the same address
            lastNode = firstNode;

            // Loop until all the nodes are generated and added to the list
            for (nodeCtr = 2; nodeCtr <= numberOfNodes; nodeCtr++)
            {
                // Allocate memory to the new node
                newNode = (struct node *)malloc(sizeof(struct node));

                // The new can only be added to the list if memory
                // was successfully allocated
                if(newNode != NULL)
                {
                    // Ask user input for the data of the new node
                    printf("Input data for node %d : ", nodeCtr);
                    scanf("%d", &nodeData);

                    // Initialize node
                    newNode->data = nodeData;
                    newNode->nextPtr = NULL;
                    newNode->prevPtr = NULL;

                    // Link the previous node to the new node
                    newNode->prevPtr = lastNode;
                    lastNode->nextPtr = newNode;

                    // Assign the new node as the last node in the list
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

void displayDoublyLinkedList()
{
    struct node *currentNode;
    int nodeCtr = 0;

    if (lastNode == NULL)
    {
        printf("No data found in the list yet.");
    }
    else
    {
        // Point to the last node of the list
        currentNode = lastNode;

        printf("\nData in reverse order are :\n");

        // Loop until all the nodes are displayed
        while (currentNode != NULL)
        {
            // Display node data
            printf("Data in node %d : %d\n", nodeCtr + 1, currentNode->data);
            nodeCtr++;

            // Load previous node
            currentNode = currentNode->prevPtr;
        }
    }
}
