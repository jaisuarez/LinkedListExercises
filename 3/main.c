#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;                       // Data of the node
    struct node *nextPtr;           // Address of the next node
};

struct node *firstNode;

// Function to generate the node list
void createNodeList(int numberOfNodes);

// Function to count the total nodes in the list
int countTotalNodes();

// Function to print the node list
void displayNodeList();

int main()
{
    int userInput;
    int totalNodes;

    printf("Input the number of nodes : ");
    scanf("%d", &userInput);

    createNodeList(userInput);

    printf("\nData entered in the list are : \n");
    displayNodeList();

    totalNodes = countTotalNodes();
    printf("\nTotal number of nodes = %d\n", totalNodes);

    return 0;
}

void createNodeList(int numberOfNodes)
{
    struct node *newNode;
    struct node *tempNode;
    int userInput;
    int nodeId;

    firstNode = (struct node *)malloc(sizeof(struct node));

    // Check if the firstNode memory has been allocated
    if(firstNode == NULL)
    {
        printf("Memory can not be allocated.");
    }
    else
    {
        printf("Input data for node 1 : ");
        scanf("%d", &userInput);

        firstNode->data = userInput;
        firstNode->nextPtr = NULL;

        tempNode = firstNode;

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

                tempNode->nextPtr = newNode;
                tempNode = tempNode->nextPtr;
            }
        }
    }
}

int countTotalNodes()
{
    int totalNodes = 0;
    struct node *tempNode;

    tempNode = firstNode;

    while (tempNode != NULL)
    {
        totalNodes++;
        tempNode = tempNode->nextPtr;
    }

    return totalNodes;
}

void displayNodeList()
{
    struct node *tempNode;

    if (firstNode == NULL)
    {
        printf("No data found in the list.");
    }
    else
    {
        tempNode = firstNode;

        while (tempNode != NULL)
        {
            printf("Data = %d\n", tempNode->data);
            tempNode = tempNode->nextPtr;
        }
    }
}
