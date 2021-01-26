#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;               // Data of the node
    struct node *nextPtr;   // Address of the next node
};

struct node *startNode;

// Function to create the list
void createNodeList(int numberOfNodes);

// Function to reverse the list in reverse
void reverseNodeList();

// Function to display the list
void displayNodeList();

int main()
{
    int numberOfNodes;

    printf("Input the number of nodes : ");
    scanf("%d", &numberOfNodes);

    createNodeList(numberOfNodes);

    printf("\nData entered in the list are : \n");
    displayNodeList();

    printf("\nThe list in reverse are : \n");
    reverseNodeList();
    displayNodeList();

    return 0;
}

void createNodeList(int numberOfNodes)
{
    struct node *newNode;
    struct node *tempNode;
    int userInput;
    int nodeId;

    startNode = (struct node *)malloc(sizeof(struct node));

    // Check whether the startNode is NULL and if so no
    // memory allocation
    if(startNode == NULL)
    {
        printf("Memory can not be allocated");
    }
    else
    {
        printf("Input data for node 1 : ");
        scanf("%d", &userInput);

        startNode->data = userInput;
        startNode->nextPtr = NULL;

        tempNode = startNode;

        // Creates (numberOfNodes - 1) nodes and adds to linked list
        for(nodeId = 2; nodeId <= numberOfNodes; nodeId++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            if(newNode == NULL)
            {
                printf("Memory can not be allocated.");
                break;
            }
            else
            {
                printf("Input data for node %d : ", nodeId);
                scanf("%d", &userInput);

                newNode->data = userInput;
                newNode->nextPtr = NULL;

                // Links previous node to the newNode
                tempNode->nextPtr = newNode;
                tempNode = tempNode->nextPtr;
            }
        }
    }
}

void reverseNodeList()
{
    struct node *previousNode;
    struct node *currentNode;

    if(startNode != NULL)
    {
        previousNode = startNode;

        currentNode = startNode->nextPtr;
        startNode = startNode->nextPtr;

        // Convert the first node as last
        previousNode->nextPtr = NULL;

        while(startNode != NULL)
        {
            startNode = startNode->nextPtr;
            currentNode->nextPtr = previousNode;

            previousNode = currentNode;
            currentNode = startNode;
        }

        // Convert the last node as head
        startNode = previousNode;
    }
}

void displayNodeList()
{
    struct node *tempNode;

    if(startNode == NULL)
    {
        printf("No data found in the list.");
    }
    else
    {
        tempNode = startNode;

        while(tempNode != NULL)
        {
            printf("Data = %d\n", tempNode->data);
            tempNode = tempNode->nextPtr;
        }
    }
}