#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;                       // Data of the node
    struct node *nextPtr;           // Address of the next node
};

struct node *firstNode;

void createNodeList(int numberOfNodes);

void insertAtBeginningOfNodeList(int data);

void displayNodeList();

int main()
{
    int numberOfNodes;
    int data;

    printf("Input the number of nodes : ");
    scanf("%d", &numberOfNodes);

    createNodeList(numberOfNodes);

    printf("\nData entered in the list are : \n");
    displayNodeList();

    printf("\nInput data to insert at the beginning of the list : ");
    scanf("%d", &data);

    insertAtBeginningOfNodeList(data);

    printf("\nData after inserted in the list are : \n");
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

void insertAtBeginningOfNodeList(int data)
{
    struct node *newNode;

    newNode = (struct node *)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Memory can not be allocated.");
    }
    else
    {
        newNode->data = data;
        newNode->nextPtr = firstNode;

        firstNode = newNode;
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

