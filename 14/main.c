#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;                       // Node data
    struct node *previousPtr;       // Pointer to the previous node
    struct node *nextPtr;           // Pointer to the next node
};

struct node *firstNode;             // First node of the double linked list
struct node *lastNode;              // Last node of the double linked list

// Create double linked list with the specified number of nodes
void createDoubleLinkList(int numberOfNodes);

// Inserts a new node at the beginning of the double linked list
void insertNodeAtBeginning(int nodeData);

// Inserts a new node at the end of the double linked list
void insertNodeAtEnd(int nodeData);

// Inserts a new node at a specified position of the double linked list
void insertNodeAtPosition(int nodeData, int nodePosition);

// Displays the double linked list
void displayDoubleLinkList();

int main()
{
    int numberOfNodes;              // Number of nodes for the double link list
    int nodeData;                   // Data to save to the node
    int nodePosition;               // Position of the node in the double link list

    // Initializes the first and last node of the double link list
    firstNode = NULL;
    lastNode = NULL;

    printf("Input the number of nodes : ");
    scanf("%d", &numberOfNodes);

    createDoubleLinkList(numberOfNodes);

    printf("\nData entered in the list are :\n");
    displayDoubleLinkList();

    printf("Input the position (1 to %d) to insert a new node : ", numberOfNodes + 1);
    scanf("%d", &nodePosition);

    printf("Input data for the position %d : ", nodePosition);
    scanf("%d", &nodeData);

    insertNodeAtPosition(nodeData, nodePosition);

    printf("\nAfter insertion the new list are :\n");
    displayDoubleLinkList();

    return 0;
}

void createDoubleLinkList(int numberOfNodes)
{
    int nodeCtr;
    int nodeData;
    struct node *newNode;

    // Proceed if the specified number of node is a positive number
    if (numberOfNodes >= 1)
    {
        // Allocate memory to the first node of the double linked list
        firstNode = (struct node *)malloc(sizeof(struct node));

        // Proceed with the generation of the double linked list
        // if memory allocation is successful
        if (firstNode != NULL)
        {
            printf("Input data for node 1 : ");
            scanf("%d", &nodeData);

            // Initialize value of the first node
            firstNode->data = nodeData;
            firstNode->previousPtr = NULL;
            firstNode->nextPtr = NULL;

            // Indicate that the first node is the current last node of the
            // newly created double linked list
            lastNode = firstNode;

            // Loop until all the specified nodes are generated
            for (nodeCtr = 2; nodeCtr <= numberOfNodes; nodeCtr++)
            {
                // Allocate memory for a new role
                newNode = (struct node *)malloc(sizeof(struct node));

                // Initialize and append the new node if memory allocation
                // was successful
                if (newNode != NULL)
                {
                    printf("Input data for node %d : ", nodeCtr);
                    scanf("%d", &nodeData);

                    // Initialize new node
                    newNode->data = nodeData;
                    newNode->previousPtr = NULL;
                    newNode->nextPtr = NULL;

                    // Link the new node to the last node of the double linked list
                    newNode->previousPtr = lastNode;
                    lastNode->nextPtr = newNode;

                    // Assign the new node as the last node of the double linked list
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

void insertNodeAtPosition(int nodeData, int nodePosition)
{
    int nodeCtr;
    struct node *newNode;
    struct node *currentNode;

    // Do not continue if the double linked list is empty
    if (lastNode == NULL)
    {
        printf("No data found in the list!\n");
    }
    else
    {
        // Set the first node as the current node
        currentNode = firstNode;

        // Loop until the last node of the double linked list is reached
        nodeCtr = 1;
        while (nodeCtr < nodePosition - 1 && currentNode != NULL)
        {
            currentNode = currentNode->nextPtr;

            // Keep track of the total number of traversed nodes
            nodeCtr++;
        }

        // Insert the node at the indicated position in the double linked list
        if(nodePosition == 1)
        {
            insertNodeAtBeginning(nodeData);
        }
        else if (currentNode == lastNode)
        {
            insertNodeAtEnd(nodeData);
        }
        else if (currentNode != NULL)
        {
            // Allocate memory to the new node
            newNode = (struct node *)malloc(sizeof(struct node));

            // Initialize the new node
            newNode->data = nodeData;

            // Insert the new node to be positioned between the current node
            // and (current node + 1) in the double linked list
            newNode->nextPtr = currentNode->nextPtr;
            newNode->previousPtr = currentNode;

            if(currentNode->nextPtr != NULL)
            {
                currentNode->nextPtr->previousPtr = newNode;
            }

            currentNode->nextPtr = newNode;
        }
        else
        {
            printf("The position you entered is invalid. \n");
        }
    }
}

void insertNodeAtBeginning(int nodeData)
{
    struct node *newNode;

    if (firstNode == NULL)
    {
        printf("No data found in the list!\n");
    }
    else
    {
        // Allocate memory for a new node
        newNode = (struct node *)malloc(sizeof(struct node));

        if (newNode != NULL)
        {
            // Initialize new node
            newNode->data = nodeData;
            newNode->previousPtr = NULL;
            newNode->nextPtr = NULL;

            // Link the new node to the first node
            newNode->nextPtr = firstNode;
            firstNode->previousPtr = newNode;

            // Set the new node as the first node
            firstNode = newNode;
        }
        else
        {
            printf("Memory was not allocated");
        }
    }
}

void insertNodeAtEnd(int nodeData)
{
    struct node *newNode;

    // Do not proceed if the list is empty
    if (lastNode == NULL)
    {
        printf("No data found in the list!\n");
    }
    else
    {
        // Allocate memory for the new node
        newNode = (struct node *)malloc((sizeof(struct node)));

        if (newNode != NULL)
        {
            // Initialize new node
            newNode->data = nodeData;
            newNode->nextPtr = NULL;
            newNode->previousPtr = NULL;

            // Link the new node to the last node
            newNode->previousPtr = lastNode;
            lastNode->nextPtr = newNode;

            // Set the new node as the last node
            lastNode = newNode;
        }
        else
        {
            printf("Memory was not allocated");
        }
    }
}

void displayDoubleLinkList()
{
    struct node *currentNode;
    int nodeCtr = 1;

    // Do not proceed if the double linked list is empty
    if(firstNode == NULL)
    {
        printf("No data found in the list yet.");
    }
    else
    {
        // Set the first node as the current node
        currentNode = firstNode;

        // Loop until all the last node is reached
        while (currentNode != NULL)
        {
            printf("node %d : %d\n", nodeCtr, currentNode->data);
            nodeCtr++;

            // Go to the next node
            currentNode = currentNode->nextPtr;
        }
    }
}