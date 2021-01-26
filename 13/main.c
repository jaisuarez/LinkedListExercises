#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;                           // Node data
    struct node *previousPtr;           // Pointer to the previous node address
    struct node *nextPtr;               // Pointer to the next node address
};

struct node *firstNode;         // First node of the double linked list
struct node *lastNode;          // Last node of the double linked list

// Generates a double link list with the indicated number of nodes
void createDoubleLinkList(int numberOfNodes);

// Insert a new node at the end of the double link list
void insertAtEndOfDoubleLinkList(int nodeDate);

// Display the double linked list
void displayDoubleLinkList();

int main()
{
    int numberOfNodes;
    int nodeData;

    // Initialize the first and last node pointers
    firstNode = NULL;
    lastNode = NULL;

    printf("Input the number of nodes : ");
    scanf("%d", &numberOfNodes);

    // Generate the double linked list
    createDoubleLinkList(numberOfNodes);

    printf("\nData entered in the list are :\n");
    displayDoubleLinkList();

    printf("Input data for the last node : ");
    scanf("%d", &nodeData);

    // Insert a new node at the end of the double linked list
    insertAtEndOfDoubleLinkList(nodeData);

    printf("\nAfter insertion the new list are :\n");
    displayDoubleLinkList();

    return 0;
}

void createDoubleLinkList(int numberOfNodes)
{
    int nodeCtr;                // Node counter
    int nodeData;               // Node data for the new node
    struct node *newData;       // Pointer for a new node that will be added
                                // to the list

    if (numberOfNodes >= 1)
    {
        // Allocate memory to the first node of the double linked list
        firstNode = (struct node *)malloc(sizeof(struct node));

        // Continue if memory was successfully allocated
        if (firstNode != NULL)
        {
            printf("Input data for node 1 : ");
            scanf("%d", &nodeData);

            // Initialize for node
            firstNode->data = nodeData;
            firstNode->previousPtr = NULL;
            firstNode->nextPtr = NULL;

            // Point the last node of the double linked list to the first node
            lastNode = firstNode;

            // Loop until all the nodes are generated
            for (nodeCtr = 2; nodeCtr <= numberOfNodes; nodeCtr++)
            {
                // Allocate memory to the new node
                newData = (struct node *)malloc(sizeof(struct node));

                // Continue if memory was successfully allocated
                if(newData != NULL)
                {
                    printf("Input data for node %d : ", nodeCtr);
                    scanf("%d", &nodeData);

                    // Initialize new node
                    newData->data = nodeData;
                    newData->previousPtr = NULL;
                    newData->nextPtr = NULL;

                    // Link the new node with the last node of the
                    // double linked list
                    newData->previousPtr = lastNode;
                    lastNode->nextPtr = newData;

                    // Assign the new node as the last node of the list
                    lastNode = newData;
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

void insertAtEndOfDoubleLinkList(int nodeData)
{
    struct node *newNode;

    // Do not proceed if double linked list is empty
    if (lastNode == NULL)
    {
        printf("No data found in the list!\n");
    }
    else
    {
        // Allocate memory to the new node
        newNode = (struct node *)malloc(sizeof(struct node));

        // Initialize new node
        newNode->data = nodeData;
        newNode->nextPtr = NULL;
        newNode->previousPtr = NULL;

        // Link the new node to the last node of the double linked list
        newNode->previousPtr = lastNode;
        lastNode->nextPtr = newNode;

        // Set the new node as the end node of the double linked list
        lastNode = newNode;
    }
}

void displayDoubleLinkList()
{
    struct node *currentNode;
    int nodeCtr = 1;

    // Do not continue if double linked list is empty
    if (firstNode == NULL)
    {
        printf("No data found in the list yet.");
    }
    else
    {
        // Set the first node of the double linked list as the current node
        currentNode = firstNode;

        // Loop until the current node reaches the last node of the
        // double linked list
        while (currentNode != NULL)
        {
            printf("node %d : %d \n", nodeCtr, currentNode->data);
            nodeCtr++;

            // Load the next node in the double linked list
            currentNode = currentNode->nextPtr;
        }
    }
}
