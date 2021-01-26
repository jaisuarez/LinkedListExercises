#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;                   // Data of the node
    struct node *nextPtr;       // Address of the node
};

struct node *firstNode;

void createNodeList(int numberOfNodes);

void insertNodeAtMiddle(int data, int position);

void displayNodeList();

int main()
{
    int numberOfNodes;
    int newData;
    int nodePosition;

    printf("Input the number of nodes (3 or more) : ");
    scanf("%d", &numberOfNodes);

    createNodeList(numberOfNodes);

    printf("\nData entered in the list are : \n");
    displayNodeList();

    printf("\nInput data to insert in the middle of the list : ");
    scanf("%d", &newData);

    printf("Input the position to insert new node : ");
    scanf("%d", &nodePosition);

    if(nodePosition <= 1 || nodePosition >= numberOfNodes)
    {
        printf("\nInsertion can not be possible in that position.\n");
    }
    else if(nodePosition > 1 && nodePosition < numberOfNodes)
    {
        insertNodeAtMiddle(newData, nodePosition);
        printf("\nInsertion completed successfully.\n");
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

    if (firstNode == NULL)
    {
        printf("Memory can not be allocated.");
    }
    else
    {
        printf("Input data for node 1 :");
        scanf("%d", &nodeData);

        firstNode->data = nodeData;
        firstNode->nextPtr = NULL;

        tempNode = firstNode;

        for(nodeCtr = 2; nodeCtr <= numberOfNodes; nodeCtr++)
        {
            newNode = (struct node *)malloc((sizeof(struct node)));

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

void insertNodeAtMiddle(int data, int position)
{
    int nodePosition;
    struct node *newNode;
    struct node *tempNode;

    newNode = (struct node *)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Memory can not be allocated");
    }
    else
    {
        newNode->data = data;
        newNode->nextPtr = NULL;

        tempNode = firstNode;

        for(nodePosition = 2; nodePosition <= position - 1; nodePosition++)
        {
            tempNode = tempNode->nextPtr;

            if(tempNode == NULL)
                break;
        }

        if(tempNode != NULL)
        {
            newNode->nextPtr = tempNode->nextPtr;
            tempNode->nextPtr = newNode;
        }
        else
        {
            printf("Insert is not possible to the given position.\n");
        }
    }
}

void displayNodeList()
{
    struct node *tempNode;

    if(firstNode == NULL)
    {
        printf("No data found in the empty list.");
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
