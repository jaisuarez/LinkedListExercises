#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;                       // Data of the node
    struct node *nextPtr;           // Address of the next node
};

struct node *firstNode;

void createNodeList(int numberOfNodes);

void deleteFirstNode();

void displayNodeList();

int main()
{
    int numberOfNodes;

    printf("Input the number of nodes : ");
    scanf("%d", &numberOfNodes);

    createNodeList(numberOfNodes);

    printf("\nData entered in the list are : \n");
    displayNodeList();

    deleteFirstNode();

    printf("\nData after deletion of first node : \n");
    displayNodeList();

    return 0;
}

void createNodeList(int numberOfNodes)
{
    struct node *newNode;
    struct node *tempNode;
    int nodeData;
    int nodeCtr;

    firstNode = (struct node *)malloc(sizeof(struct node));

    if(firstNode == NULL)
    {
        printf("Memory can not be allocated.");
    }
    else
    {
        printf("Input data for node 1 : ");
        scanf("%d", &nodeData);

        firstNode->data = nodeData;
        firstNode->nextPtr = NULL;

        tempNode = firstNode;

        for(nodeCtr = 2; nodeCtr <= numberOfNodes; nodeCtr++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            if(newNode == NULL)
            {
                printf("Memory can not be allocated.");
                break;
            }
            else
            {
                printf("Input data for node %d : ", nodeCtr);
                scanf("%d", &nodeData);

                newNode->data = nodeData;
                newNode->nextPtr = NULL;

                tempNode->nextPtr = newNode;
                tempNode = tempNode->nextPtr;
            }
        }
    }
}

void deleteFirstNode()
{
    struct node *tempPtr;

    if(firstNode == NULL)
    {
        printf("There are no node in the list.");
    }
    else
    {
        tempPtr = firstNode;

        firstNode = firstNode->nextPtr;

        printf("\nData of node 1 which is being deleted is : %d\n", tempPtr->data);

        free(tempPtr);
    }
}

void displayNodeList()
{
    struct node *tempPtr;

    if(firstNode == NULL)
    {
        printf("No data found in the list.");
    }
    else
    {
        tempPtr = firstNode;
        while (tempPtr != NULL)
        {
            printf("Data = %d\n", tempPtr->data);

            tempPtr = tempPtr->nextPtr;
        }
    }
}