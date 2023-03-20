#include<iostream>
#include<stdlib.h>
#include<sstream>
#include <string.h>
using namespace std;
//Structure definition
struct treeNode
{
//Structure member
int data;
treeNode *left;
treeNode *right;
};//End of structure

//Returns the node having minimum value
treeNode* FindMin(treeNode *tnode)
{
if(tnode == NULL)
{
//There is no element in the tree
return NULL;
}
//Go to the left sub tree to find the min element
if(tnode -> left)
return FindMin(tnode -> left);
else
return tnode;
}//End of function

//Returns the node having maximum value
treeNode* FindMax(treeNode *tnode)
{
if(tnode == NULL)
{
//There is no element in the tree
return NULL;
}
//Go to the left sub tree to find the min element
if(tnode -> right)
return(FindMax(tnode -> right));
else
return tnode;
}//End of function

//Insert a node
treeNode *Insert(treeNode *tnode,int value)
{
if(tnode == NULL)
{
treeNode *temp;
temp = new treeNode;
temp -> data = value;
temp -> left = temp -> right = NULL;
return temp;
}
if(value >(tnode -> data))
{
tnode -> right = Insert(tnode -> right, value);
}
else if(value < (tnode -> data))
{
tnode -> left = Insert(tnode -> left, value);
}
//Else there is nothing to do as the data is already in the tree.
return tnode;
}//End of function

treeNode * Delete(treeNode *tnode, int value)
{
treeNode *temp;
if(tnode == NULL)
{
cout<<"Element Not Found";
}
else if(value < tnode -> data)
{
tnode -> left = Delete(tnode -> left, value);
}
else if(value > tnode -> data)
{
tnode -> right = Delete(tnode -> right, value);
}
else
{
//Now We can delete this node and replace with either minimum element in the right sub tree or maximum element in the left subtree
if(tnode -> right && tnode -> left)
{
//Here we will replace with minimum element in the right sub tree
temp = FindMin(tnode -> right);
tnode -> data = temp -> data;

//As we replaced it with some other node, we have to delete that node
tnode -> right = Delete(tnode -> right, temp -> data);
}
else
{
//If there is only one or zero children then we can directly remove it from the tree and connect its parent to its child
temp = tnode;
if(tnode -> left == NULL)
tnode = tnode -> right;
else if(tnode -> right == NULL)
tnode = tnode -> left;
//Delete temp
free(temp);
}//End of inner else
}//End of outer else
return tnode;
}//End of function

//Search for a node
treeNode * Find(treeNode *tnode, int value)
{
if(tnode == NULL)
{
//Element is not found
return NULL;
}
if(value > tnode -> data)
{
//Search in the right sub tree.
return Find(tnode -> right, value);
}
else if(value < tnode -> data)
{
//Search in the left sub tree.
return Find(tnode -> left, value);
}
else
{
//Element Found
return tnode;
}
}//End of function

//Inorder traversal
void Inorder(treeNode *tnode)
{
if(tnode == NULL)
{
return;
}
Inorder(tnode -> left);
cout<<tnode -> data<<" ";
Inorder(tnode -> right);
}//End of function

//Pre order traversal
void Preorder(treeNode *tnode)
{
if(tnode == NULL)
{
return;
}
cout<<tnode -> data<<" ";
Preorder(tnode -> left);
Preorder(tnode -> right);
}//End of function

//Post order traversal
void Postorder(treeNode *tnode)
{
if(tnode == NULL)
{
return;
}
Postorder(tnode -> left);
Postorder(tnode -> right);
cout<<tnode -> data<<" ";
}//End of function

//Main function
int main()
{
//Creates root and temporary node
treeNode *root = NULL,*temp;
char ch[10];
int val, x, y;
char cho;
//Loops till user choice is 'e'
while(1)
{
//Displays the menu
cout<<"\n i for Insert \n d for Delete \n oin for Inorder \n opre for Preorder \n opost Postorder \n e for Exit\n";
cout<<"Enter your choice:";
cin>>ch;
//Finds the length of choice
for(x = 0; ch[x]!='\0'; x++) ;

if(x == 2)
val = ch[1] - 48;
else if(x == 3)
val = (ch[1] - 48) * 10 + (ch[2] - 48);
else if(x == 4)
val = (ch[1] - 48) * 100 + (ch[2] - 48) * 10 + (ch[2] - 48);
cho = ch[0];
//Checks the choice
if(cho == 'i')
{
root = Insert(root, val);
}
else if(cho == 'd')
{
root = Delete(root,val);
}
else if(strcmp(ch,"oin") == 0)
{
cout<<"\nInorder Travesals is:";
Inorder(root);
}
else if(strcmp(ch,"opre") == 0)
{
cout<<"\nPreorder Traversals is:";
Preorder(root);
}
else if(strcmp(ch,"opost") == 0)
{
cout<<"\nPostorder Traversals is:";
Postorder(root);
}
else if(cho == 'e')
exit(0);
else
cout<<"\n Enter correct choice:";
}//End of while
return 0;
}//End of main