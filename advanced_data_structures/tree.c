#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createNode(value)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct node *insertLeft(struct node *root, int value)
{
    root->left = createNode(value);
    return root->left;
}
struct node *insertRight(struct node *root, int value)
{
    root->right = createNode(value);
    return root->right;
}
int main()
{
    struct node *root = createNode(1);
    insertLeft(root, 2);
    insertRight(root, 3);

    printf("The elements of tree are %d %d %d", root->data, root->left->data, root->right->data);
}