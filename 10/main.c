#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;                       // Data of the node
    struct node *nextPtr;           // Address of the next node
};

struct node firstNode;              // First node of the node list
struct node *currentNode;           // Points to the address of the
                                    // current node in the list

int findNode(int nodeData);

int main()
{
    int numberOfNodes;          // Number of nodes to create
    int nodeCtr;                // Node counter for traversing node list
    int nodeData;               // Node data element
    int nodePosition;           // Node position in the list

    // Initialize the next node pointer to be null
    firstNode.nextPtr = NULL;

    // Load the address of the first node
    currentNode = &firstNode;

    // Ask user for the number of nodes to generate
    printf("Input the number of nodes : ");
    scanf("%d", &numberOfNodes);

    // Loop until the indicated number of nodes in the list is created
    for (nodeCtr = 0; nodeCtr < numberOfNodes; nodeCtr++)
    {
        // Allocate memory to the next node
        currentNode->nextPtr = (struct node *)malloc(sizeof(struct node));

        // Ask user input for node data element
        printf("Input data for node %d : ", nodeCtr + 1);
        scanf("%d", &currentNode->data);

        // Traverse to the next node
        currentNode = currentNode->nextPtr;
    }

    // Initialize the last pointer to be NULL
    currentNode->nextPtr = NULL;

    printf("\nData entered in the list are :\n");

    // Point to the first node
    currentNode = &firstNode;

    // Loop through all the nodes in the list
    while (currentNode->nextPtr != NULL)
    {
        // Print node data
        printf("Data = %d\n", currentNode->data);

        // Traverse to the next node
        currentNode = currentNode->nextPtr;
    }

    // Ask user for the input data to be searched
    printf("Input the element to be searched : ");
    scanf("%d", &nodeData);

    // Get the node position of the node data to be searched
    nodePosition = findNode(nodeData);

    // Verify that the node position is valid
    if(nodePosition <= numberOfNodes)
    {
        printf("Element found at node %d \n\n", nodePosition);
    }
    else
    {
        printf("This element does not exist in linked list. \n\n");
    }
    return 0;
}

int findNode(int nodeData)
{
    int nodePosition = 1;

    currentNode = &firstNode;

    // Loop until the node data is found
    while(currentNode->nextPtr != NULL)
    {
        if (currentNode->data == nodeData)
        {
            // Node data is found, exit loop.
            break;
        }
        else
        {
            // Increase node position
            nodePosition++;
        }

        // Traverse to the next node
        currentNode = currentNode->nextPtr;
    }

    return nodePosition;
}