// C program to to implement binary tree

#include <stdio.h>
#include <stdlib.h>

// Define a structure for tree nodes
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function for inserting a node in a binary tree
void insert(Node** root, int data)
{
    Node* newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    // Level order traversal to find the appropriate place
    // for insertion
    Node* temp;
    Node* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = *root;

    while (front != rear) {
        temp = queue[++front];

        //  Insert new node as the left child
        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        }
        // if left child is not missing push it to the queue
        else {
            queue[++rear] = temp->left;
        }
        // Insert new node as the right child
        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        }
        // if right child is not missing push it to the
        // queue
        else {
            queue[++rear] = temp->right;
        }
    }
}

// function to perform inorder traversal in a binary tree
void inorderTraversal(Node* root)
{
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}


void preOrder(struct Node* node) {
    if (node == NULL)
        return;

    // Visit the current node first
    printf("%d ", node->data);

    // Traverse the left subtree
    preOrder(node->left);

    // Traverse the right subtree
    preOrder(node->right);
}

void postOrder(struct Node *node)
{
    if (node == NULL)
        return;

    // First we traverse left subtree
    postOrder(node->left);

    // After visiting left, traverse right subtree
    postOrder(node->right);

    // now we visit node
    printf("%d ", node->data);
}

int main()
{
    Node* root = NULL;

    // Inserting nodes
    // insert(&root, 20);
    // insert(&root, 30);
    // insert(&root, 40);
    // insert(&root, 50);
    // insert(&root, 60);
    // insert(&root, 70);
    // insert(&root, 80);
    int N;
    scanf("%d", &N);
    int arr[N];

    for (int  i = 0; i < N; i++){
        scanf("%d", &arr[i]);
        insert(&root, arr[i]);
    }

    //Preorder traversal
    printf("PRE ");
    preOrder(root);
    printf("\n");
    // Inorder traversal
    printf("IN ");
    inorderTraversal(root);
    printf("\n");
    // Postorder ttraversal
    printf("POST ");
    postOrder(root);

    return 0;
}
