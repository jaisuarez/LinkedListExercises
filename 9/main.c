#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;                           // Data of the node
    struct node *nextPtr;               // Address of the next node
};

struct node *firstNode;

// Generates node list
void createNodeList(int numberOfNodes);

// Deletes the last node in the node list
void deleteLastNode();

// Displays node list
void displayNodeList();

int main()
{
    // Number of nodes to create in the list
    int numberOfNodes;

    printf("Input the number of nodes : ");
    scanf("%d", &numberOfNodes);

    createNodeList(numberOfNodes);

    printf("\nData entered in the list are : \n");
    displayNodeList();

    deleteLastNode();

    printf("\nThe new list after deletion the last node are : \n");
    displayNodeList();

    return 0;
}

void createNodeList(int numberOfNodes)
{
    struct node *newNode;
    struct node *currentNode;
    int nodeData;
    int nodeCtr;

    firstNode = (struct node *)malloc(sizeof(struct node));

    // Generate a node list if memory was successfully allocated
    if (firstNode == NULL)
    {
        printf("Memory can not be allocated.");
    }
    else
    {
        printf("Input data for node 1 : ");
        scanf("%d", &nodeData);

        // Save input data to the node
        firstNode->data = nodeData;

        // Initialize pointer to the next node to NULL
        firstNode->nextPtr = NULL;

        // Copy the address of the first node
        currentNode = firstNode;

        // Loop until the specified number of nodes are generated
        for(nodeCtr = 2; nodeCtr <= numberOfNodes; nodeCtr++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            // Exit function if memory allocation failed.
            if(newNode == NULL)
            {
                printf("Memory can not be allocated.");
                break;
            }
            else
            {
                printf("Input data for node %d : ", nodeCtr);
                scanf("%d", &nodeData);

                // Save input data to the new node
                newNode->data = nodeData;
                // Initialize pointer to the next node to NULL
                newNode->nextPtr = NULL;

                // Append the new node to the last node of the list
                currentNode->nextPtr = newNode;
                // Set the new node as the current node
                currentNode = currentNode->nextPtr;
            }
        }
    }
}

void deleteLastNode()
{
    struct node *currentNode;
    struct node *previousNode;

    // Do not proceed if node list is empty
    if (firstNode == NULL)
    {
        printf("There is no element in the list.");
    }
    else
    {
        // Copy the address of the node list's first node
        currentNode = firstNode;
        previousNode = firstNode;

        // Loop as long as the succeeding not is still valid
        while (currentNode->nextPtr != NULL)
        {
            // Copy the address of the current node
            previousNode = currentNode;

            // Traverse to the next node
            currentNode = currentNode->nextPtr;
        }

        // If the last node is the first node, set it to NULL.
        // Otherwise, set the last node to NULL (which is the current node)
        if(currentNode == firstNode)
        {
            firstNode = NULL;
        }
        else
        {
            // Disconnect the link of second last node with last node
            previousNode->nextPtr = NULL;
        }

        // Delete the last node
        free(currentNode);
    }
}

void displayNodeList()
{
    struct node *currentNode;

    // Do not process if node list is empty
    if(firstNode == NULL)
    {
        printf("No data found in the empty list.");
    }
    else
    {
        // Copy the address of the first node
        currentNode = firstNode;

        // While the current node is not null
        while (currentNode != NULL)
        {
            // Print the data of the current node
            printf("Data = %d\n", currentNode->data);

            // Go to the next node
            currentNode = currentNode->nextPtr;
        }
    }
}