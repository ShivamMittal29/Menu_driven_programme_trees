#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *left;
struct node *right;
};

struct node* newnode(int data)
{
struct node *node=(struct node*)malloc(sizeof(struct node));

node->data=data;
node->left=NULL;
node->right=NULL;

return (node);
}

struct node* insert(struct node* node,int data)
{
if(node==NULL)
return (newnode(data));

else
{
if(data<=node->data)
node->left=insert(node->left,data);
else
node->right=insert(node->right,data);

return node;
}
}

void printInorder(struct node* node)
{
if(node==NULL)
return;

printInorder(node->left);
printf("%d ",node->data);
printInorder(node->right);

}


void deleteTree(struct node* node)
{
if(node==NULL)
return;

deleteTree(node->left);
deleteTree(node->right);
printf("\n Deleted node:%d",node->data);
free(node);
}




int size(struct node* node)
{
if(node==NULL)
return 0;

else
return (size(node->left)+1+size(node->right));
}
void printGivenLevel(struct node* root, int level);
int height(struct node* node);
struct node* newNode(int data);

/* Function to print level order traversal a tree*/
void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}

/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(struct node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);

        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}

//the reverse order traversal//
void GivenLevel(struct node* root, int level);
int height1(struct node* node);
struct node* newNode(int data);

/* Function to print REVERSE level order traversal a tree*/
void reverseLevelOrder(struct node* root)
{
    int h1 = height1(root);
    int i;
    for (i=h1; i>=1; i--) //THE ONLY LINE DIFFERENT FROM NORMAL LEVEL ORDER
        GivenLevel(root, i);
}


void GivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        GivenLevel(root->left, level-1);
        GivenLevel(root->right, level-1);
    }
}


int height1(struct node* node)
{
    if (node==NULL)
        return 0;
    else
    {

        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}


int main()
{
int choice;
struct node* root=newnode(1);
root->left=newnode(12);
root->right=newnode(13);
root->left->left=newnode(14);
root->left->right=newnode(15);
root->right->left=newnode(16);
while(1)
{


printf("\n\tMenu Driven\n");
printf("1.Insert\n");
printf("2.Inorder\n");
printf("3.Delete\n");
printf("4.Size\n");
printf("5.level order traversal\n");
printf("6.Reverse level order traversal \n");
printf("7.Exit\n");


printf("Enter your choice:");
scanf("%d",&choice);


switch(choice)
{

case 1:
{
struct node* root=NULL;
printf("Insertion:\n");
root=insert(root,50);
insert(root,11);
insert(root,14);
insert(root,12);
insert(root,13);

printf("\nInorder Traversal\n");
printInorder(root);

}
break;

case 2:
{
printf("\nInorder traversal of Tree:\n");
printInorder(root);
}
break;
case 3:
{
deleteTree(root);
root=NULL;
printf("\nTree Deleted!");
}
break;

case 4:
{
struct node* root=NULL;
root=insert(root,50);
insert(root,11);
insert(root,14);
insert(root,12);
insert(root,13);

printf("Size of tree:%d",size(root));
}
break;
case 5:
    {
    printf("Level Order traversal of binary tree is \n");
    printLevelOrder(root);
    }
    break;
case 6:
    {
         printf("Reverse Level Order traversal of binary tree is \n");
    reverseLevelOrder(root);

    }

break;

case 7:
exit(0);
break;

default:
printf("\nInvalid Choice!");
}

}
getchar();
return 0;
}
