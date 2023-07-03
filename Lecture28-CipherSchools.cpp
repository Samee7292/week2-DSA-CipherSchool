#include<bits/stdc++.h>

using namespace std;

struct node
{
int data;
struct node* left;
struct node* right;
};

bool printAncestors(struct node *root, int target)
{
if (root == NULL)
	return false;

if (root->data == target)
	return true;
if ( printAncestors(root->left, target) ||
	printAncestors(root->right, target) )
{
	cout << root->data << " ";
	return true;
}

return false;
}

struct node* newnode(int data)
{
struct node* node = (struct node*)
					malloc(sizeof(struct node));
node->data = data;
node->left = NULL;
node->right = NULL;

return(node);
}

int main()
{
struct node *root = newnode(1);
root->left	 = newnode(2);
root->right	 = newnode(3);
root->left->left = newnode(4);
root->left->right = newnode(5);
root->left->left->left = newnode(7);

printAncestors(root, 7);

getchar();
return 0;
}
