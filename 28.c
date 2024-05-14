// // Splay Tree

// #include<stdio.h>
// #include<stdlib.h>

// struct node
// {
//     int data;
//     struct node *left, *right;
// };
// struct node *root;

// right_rotation(T,x)
// {
//     y=x->left;
//     x->left=y->right;
//     y->right=x;
//     return y;
// }

// left_rotation(T,x)
// {
//     y=x->right;
//     x->right=y->left;
//     y->left=x;
//     return x;
// }

// insert(T,n)
// {
//     temp=root;
//     y=NULL;
//     while(temp!=NULL)
//     {
//         y=temp;
//         if(n->data<temp->data)
//             temp=temp->left;
//         else
//             temp=temp->right;
//     }
//     if(y==NULL)
//         root =n;
//     else if(n->data<y->data)
//         y->left=n;
//     else
//         y->right=n;
//     splay(T,n);
// }

// splay(T,n)
// {
//     while(n->parent!=NULL)
//     {
//         if(n->parent==root)
//         {
//             if(n==n->parent->left)
//                 right_rotation(T, n->parent);
//             else
//                 left_rotation(T, n->parent);
//         }
//         else
//         {
//             p=n->parent;
//             g=p->parent;
//             if(n==n->parent->left && p==p->parent->left)
//             {
//                 left_rotation(T,g);
//                 right_rotation(T,p);
//             }
//             else if(n==n->parent->right && p==p->parent->right)
//             {
//                 left_rotation(T,g);
//                 left_rotation(T,p);
//             }
//             else if(n==n->parent->left && p==p->parent->right)
//             {
//                 right_rotation(T,p);
//                 left_rotation(T,g);
//             }
//             else
//             {
//                 left_rotation(T,p);
//                 right_rotation(T,g);
//             }
//         }
//     }
// }

// delete()
// {
//     if(root==NULL)
//         return NULL;
//     splay(root, data);
//     if(data1==root->data)
//         printf("Key is not present\n");
//     if(root->left==NULL)
//         root=root->right;
//     else
//     {
//         temp=root;
//         splay(root->left,data);
//         root1->right=root->right;
//     }
//     free(temp);
//     return root;
// }

// int main()
// {
//     printf("\t\t----- Splay Tree -----\n");
//     int choice;
//     do
//     {
//         printf("Enter the Operation.\n");
//         printf("1. Inserting an element\n");
//         printf("2. Transersing elements of the Tree\n");
//         printf("3. Deleting an element\n");
//         printf("4. Exit\n");
//         scanf("%d", &choice);
//         switch (choice)
//         {
//         case 1:
//             insert();
//             break;
//         case 2:
//             display();
//             break;
//         case 3:
//             delete();
//             break;
//         default:
//             break;
//         }
//     } while (choice != 4);
//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right, *parent;
};

struct node *root;

// Function to perform a right rotation
struct node *right_rotation(struct node *x) {
    struct node *y = x->left;
    x->left = y->right;
    if (y->right != NULL)
        y->right->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->right = x;
    x->parent = y;
    return y;
}

// Function to perform a left rotation
struct node *left_rotation(struct node *x) {
    struct node *y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
    return x;
}

// Function to splay a node in the tree
struct node *splay(struct node *root, struct node *x) {
    while (x->parent != NULL) {
        if (x->parent == root) {
            if (x == x->parent->left)
                right_rotation(x->parent);
            else
                left_rotation(x->parent);
        } else {
            struct node *p = x->parent;
            struct node *g = p->parent;

            if (x == p->left && p == g->left) {
                right_rotation(g);
                right_rotation(p);
            } else if (x == p->right && p == g->right) {
                left_rotation(g);
                left_rotation(p);
            } else if (x == p->right && p == g->left) {
                left_rotation(p);
                right_rotation(g);
            } else {
                right_rotation(p);
                left_rotation(g);
            }
        }
    }
    return x; // Return the new root after splaying
}

// Function to insert a node into the splay tree
void insert(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = newNode->parent = NULL;

    struct node *temp = root;
    struct node *y = NULL;

    while (temp != NULL) {
        y = temp;
        if (data < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if (y == NULL)
        root = newNode;
    else if (data < y->data)
        y->left = newNode;
    else
        y->right = newNode;

    newNode->parent = y;
    root = splay(root, newNode);
}

// Function to find the minimum node in the splay tree
struct node *findMin(struct node *x) {
    while (x->left != NULL)
        x = x->left;
    return x;
}

// Function to find a node in the splay tree
struct node *find(struct node *root, int data) {
    if (root == NULL || root->data == data)
        return root;

    if (data < root->data)
        return find(root->left, data);
    else
        return find(root->right, data);
}

// Function to delete a node from the splay tree
struct node *deleteNode(struct node *root, int data) {
    if (root == NULL)
        return root;

    root = splay(root, find(root, data)); // Find the node and splay it

    if (data != root->data) {
        printf("Key is not present\n");
        return root;
    }

    if (root->left == NULL) {
        struct node *newRoot = root->right;
        free(root);
        return newRoot;
    } else {
        struct node *temp = root;
        struct node *newRoot = findMin(root->right);
        root->right = newRoot->right;
        free(temp);
        return root;
    }
}

// Function to perform an in-order traversal of the splay tree
void inOrderTraversal(struct node *x) {
    if (x != NULL) {
        inOrderTraversal(x->left);
        printf("%d ", x->data);
        inOrderTraversal(x->right);
    }
}

int main() {
    printf("\t\t----- Splay Tree -----\n");
    int choice, element;

    do {
        printf("Enter the Operation.\n");
        printf("1. Inserting an element\n");
        printf("2. Transersing elements of the Tree\n");
        printf("3. Deleting an element\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            insert(element);
            break;
        case 2:
            printf("In-order traversal: ");
            inOrderTraversal(root);
            printf("\n");
            break;
        case 3:
            printf("Enter the element to delete: ");
            scanf("%d", &element);
            root = deleteNode(root, element);
            break;
        case 4:
            // Cleanup and exit
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    // Clean up the allocated memory
    // Implement a function to free the memory of all nodes in the tree

    return 0;
}
