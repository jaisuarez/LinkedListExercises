#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;                           // Data of the node
    struct node *nextPtr;               // Address of the next node
};

struct node *firstNode;

void createNodeList(int numberOfNodes);

void nodeToDelete(int nodePosition);

void displayNodeList();

int main()
{
    int numberOfNodes;
    int num;
    int nodePosition;

    printf("Input the number of nodes : ");
    scanf("%d", &numberOfNodes);

    createNodeList(numberOfNodes);

    printf("\nData entered in the list are : \n");
    displayNodeList();

    printf("\nInput the position of node to delete : ");
    scanf("%d", &nodePosition);

    if(nodePosition <= 1 || nodePosition >= numberOfNodes)
    {
        printf("\nDeletion can not be possible from that position.\n");
    }

    if(nodePosition > 1 && nodePosition < numberOfNodes)
    {
        nodeToDelete(nodePosition);
        printf("\nDeletion completed successfully.\n");
    }

    printf("\nThe new list are : \n");
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

void nodeToDelete(int nodePosition)
{
    int nodeCtr;
    struct node *nodeToDelete;
    struct node *previousNode;

    if(firstNode == NULL)
    {
        printf("There are no nodes in the list.");
    }
    else
    {
        nodeToDelete = firstNode;
        previousNode = firstNode;

        for(nodeCtr = 2; nodeCtr <= nodePosition; nodeCtr++)
        {
            previousNode = nodeToDelete;
            nodeToDelete = nodeToDelete->nextPtr;

            if(nodeToDelete == NULL)
                break;
        }

        if(nodeToDelete != NULL)
        {
            if(nodeToDelete == firstNode)
            {
                firstNode = firstNode->nextPtr;
            }

            previousNode->nextPtr = nodeToDelete->nextPtr;
            nodeToDelete->nextPtr = NULL;

            free(nodeToDelete);
        }
        else
        {
            printf("Deletion can not be possible from that position.");
        }
    }
}

void displayNodeList()
{
    struct node *tempNode;

    if(firstNode == NULL)
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