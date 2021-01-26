#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;                       // Node data
    struct node *previousPtr;       // Pointer to the previous node
    struct node *nextPtr;           // Pointer to the next node
};

struct node *firstNode;     // Holds the address of the first node of the double linked list
struct node *lastNode;      // Holds the address of the last node of the double linked list

// Generates a double linked list with the specified number of nodes
void createDoubleLinkList(int numberOfNodes);

// Deletes the last node of the double linked list
void deleteLastNodeOfDoubleLinkList();

// Displays the contents of the double linked list
void displayDoubleLinkedList();

int main()
{
    int numberOfNodes;

    // Initializes the first and last node of the double linked list
    firstNode = NULL;
    lastNode = NULL;

    printf("Input the number of nodes (3 or more) : ");
    scanf("%d", &numberOfNodes);

    createDoubleLinkList(numberOfNodes);

    printf("\nData entered in the list are : \n");
    displayDoubleLinkedList();

    deleteLastNodeOfDoubleLinkList();

    printf("\nAfter deletion the new list are :\n");
    displayDoubleLinkedList();

    return 0;
}

void createDoubleLinkList(int numberOfNodes)
{
    int nodeCtr;
    int nodeData;
    struct node *newNode;

    // Proceed if the number of nodes for the double linked list is a positive number
    if (numberOfNodes >= 1)
    {
        // Allocate memory for the first node
        firstNode = (struct node *)malloc(sizeof(struct node));

        // Create the first node if memory was successfully allocated
        if (firstNode != NULL)
        {
            printf("Input data for node 1 : ");
            scanf("%d", &nodeData);

            // Initialize first node
            firstNode->data = nodeData;
            firstNode->previousPtr = NULL;
            firstNode->nextPtr = NULL;

            // Copy the address of the first node as the last node of the double linked list
            lastNode = firstNode;

            // Loop until all the nodes are generated
            for (nodeCtr = 2; nodeCtr <= numberOfNodes; nodeCtr++)
            {
                // Allocate memory to the new node
                newNode = (struct node *)malloc(sizeof(struct node));

                // Create new node if memory allocation was successful
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
                    lastNode = newNode;
                }
                else
                {
                    printf("Memory can not be allocated.");
                }
            }
        }
        else
        {
            printf("Memory can not be allocated.");
        }
    }
}

void deleteLastNodeOfDoubleLinkList()
{
    struct node *nodeToDelete;

    // Do not proceed if double linked list is empty
    if (lastNode == NULL)
    {
        printf("Delete is not possible. No data in the list.\n");
    }
    else
    {
        // Assign the last node as the node to delete
        nodeToDelete = lastNode;

        // Unlink the last node from the double link list for deletion
        lastNode = lastNode->previousPtr;
        lastNode->nextPtr = NULL;

        // Remove memory allocation of node
        free(nodeToDelete);
    }
}

void displayDoubleLinkedList()
{
    struct node *currentNode;
    int nodeCtr = 1;

    // Do not proceed if double linked list is empty
    if (firstNode == NULL)
    {
        printf("No data found in the list yet.");
    }
    else
    {
        // Assign the first node of the double linked list as the current node
        currentNode = firstNode;

        // Loop until the current node reaches the last node
        while (currentNode != NULL)
        {
            printf("node %d : %d\n", nodeCtr, currentNode->data);
            nodeCtr++;

            // Go to the next node
            currentNode = currentNode->nextPtr;
        }
    }
}
