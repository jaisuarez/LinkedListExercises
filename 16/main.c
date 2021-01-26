#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;                   // Node data
    struct node *previousPtr;   // Address to the previous node
    struct node *nextPtr;       // Address to the next node
};

struct node *firstNode;     // Points to the first node of the double linked list
struct node *lastNode;      // Points to the last node of the double linked list

// Generates a double linked list with specified number of nodes
void createDoubleLinkedList(int numberOfNodes);

// Deletes the first node of the double linked list
void deleteFirstNode();

// Displays the double linked list
void displayDoubleLinkedList();

int main()
{
    int numberOfNodes;

    // Initialize the variable for the first and last node of the double linked list
    firstNode = NULL;
    lastNode = NULL;

    printf("Input the number of nodes (3 or more) : ");
    scanf("%d", &numberOfNodes);

    createDoubleLinkedList(numberOfNodes);

    printf("\nData entered in the list are : \n");
    displayDoubleLinkedList();

    deleteFirstNode();

    printf("\nAfter deletion the new list are : \n");
    displayDoubleLinkedList();

    return 0;
}

void createDoubleLinkedList(int numberOfNodes)
{
    int nodeCtr;
    int nodeData;
    struct node *newNode;

    if(numberOfNodes >= 1)
    {
        firstNode = (struct node *)malloc(sizeof(struct node));

        if(firstNode != NULL)
        {
            printf("Input data for node 1 : ");
            scanf("%d", &nodeData);

            // Initialize the first node
            firstNode->data = nodeData;
            firstNode->previousPtr = NULL;
            firstNode->nextPtr = NULL;

            // Set the last node to be the same with the first node as its initial value
            lastNode = firstNode;

            // Loop until all the nodes are generated
            for (nodeCtr = 2; nodeCtr <= numberOfNodes; nodeCtr++)
            {
                // Allocate memory to the new node
                newNode = (struct node *)malloc(sizeof(struct node));

                // Proceed if memory allocation is successful
                if (newNode != NULL)
                {
                    printf("Input data for node %d : ", nodeCtr);
                    scanf("%d", &nodeData);

                    // Initialize new node
                    newNode->data = nodeData;
                    newNode->previousPtr = NULL;
                    newNode->nextPtr = NULL;

                    // Link the new node with the last node of the double linked list
                    newNode->previousPtr = lastNode;
                    lastNode->nextPtr = newNode;

                    // Assign the new node as the last node
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

void deleteFirstNode()
{
    struct node *nodeToRemove;

    // Do not proceed if double linked list is empty
    if (firstNode == NULL)
    {
        printf("Delete is not possible. No data in the list.\n");
    }
    else
    {
        // Set the first node of the double linked list to be removed
        nodeToRemove = firstNode;

        // Set the 2nd node of the list as the new first node
        firstNode = firstNode->nextPtr;

        // Unlink the former first node and free memory
        firstNode->previousPtr = NULL;
        free(nodeToRemove);
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
        currentNode = firstNode;

        while (currentNode != NULL)
        {
            // Display data of current node
            printf("node %d : %d\n", nodeCtr, currentNode->data);
            nodeCtr++;

            // Proceed to next node
            currentNode = currentNode->nextPtr;
        }
    }
}