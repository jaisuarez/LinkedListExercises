#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;               // Data of the node
    struct node *nextPtr;   // Address of the next node
};

struct node *startNode;

// Function to create the list
static void createNodeList(int totalNodes);

// Function to display the list
static void displayList();

int main()
{
    int numberOfNodes;

    printf("Input the number of nodes : ");
    scanf("%d", &numberOfNodes);

    createNodeList(numberOfNodes);

    printf("\nData entered in the list : \n");
    displayList();

    return 0;
}

static void createNodeList(int totalNodes)
{
    struct node *newNode;
    struct node *nodeBuffer;
    int nodeData;
    int nodeCounter;

    // Allocate memory for starting node
    startNode = (struct node *)malloc(sizeof(struct node));

    // Exit if no memory has been allocated
    if (startNode == NULL)
    {
        printf("Memory can not be allocated.");
    }
    else
    {
        printf("Input data for node 1 : ");
        scanf("%d", &nodeData);

        // Save user input to the data element of the node
        startNode->data     = nodeData;
        // Initialize the pointer to the next node to null
        startNode->nextPtr  = NULL;

        nodeBuffer = startNode;

        // Use a loop to generate the succeeding nodes
        for(nodeCounter = 2; nodeCounter <= totalNodes; nodeCounter++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            // Exit, if new node cannot be allocated
            if(newNode == NULL)
            {
                printf("Memory can not be allocated. ");
                break;
            }
            else
            {
                printf("Input data for node %d : ", nodeCounter);
                scanf("%d", &nodeData);

                newNode->data = nodeData;
                newNode->nextPtr = NULL;

                // Links the previous node to the current node
                nodeBuffer->nextPtr = newNode;
                // Copies the address of the current node
                nodeBuffer = nodeBuffer->nextPtr;
            }
        }
    }
}

static void displayList()
{
    struct node *nodeBuffer;

    nodeBuffer = startNode;

    // Exit if list is empty
    if(nodeBuffer == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        // Check if the current node is empty
        while(nodeBuffer != NULL)
        {
            // Print the data of the current node
            printf("Data = %d\n", nodeBuffer->data);

            // Go to the next node
            nodeBuffer = nodeBuffer->nextPtr;
        }
    }
}