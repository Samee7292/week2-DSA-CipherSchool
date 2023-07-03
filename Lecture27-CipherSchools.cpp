
//soted array to bst
#include<bits/stdc++.h>
using namespace std;

class TNode
{
	public:
	int data;
	TNode* left;
	TNode* right;
};

TNode* newNode(int data);
TNode* sortedArrayToBST(int arr[],
						int start, int end)
{
	if (start > end)
	return NULL;
	int mid = (start + end)/2;
	TNode *root = newNode(arr[mid]);

	root->left = sortedArrayToBST(arr, start,
									mid - 1);
	root->right = sortedArrayToBST(arr, mid + 1, end);

	return root;
}

TNode* newNode(int data)
{
	TNode* node = new TNode();
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void preOrder(TNode* node)
{
	if (node == NULL)
		return;
	cout << node->data << " ";
	preOrder(node->left);
	preOrder(node->right);
}
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int n = sizeof(arr) / sizeof(arr[0]);
	TNode *root = sortedArrayToBST(arr, 0, n-1);
	cout << "PreOrder Traversal of constructed BST \n";
	preOrder(root);

	return 0;
}




//LCA of bst

#include <bits/stdc++.h>
using namespace std;
struct Node {
	int key;
	struct Node *left, *right;
};
Node* newNode(int k)
{
	Node* temp = new Node;
	temp->key = k;
	temp->left = temp->right = NULL;
	return temp;
}
bool findPath(Node* root, vector<int>& path, int k)
{
	if (root == NULL)
		return false;
	path.push_back(root->key);
    if (root->key == k)
		return true;
	if ((root->left && findPath(root->left, path, k))
		|| (root->right && findPath(root->right, path, k)))
		return true;
	path.pop_back();
	return false;
}
int findLCA(Node* root, int n1, int n2)
{
	vector<int> path1, path2;
	if (!findPath(root, path1, n1)
		|| !findPath(root, path2, n2))
		return -1;
	int i;
	for (i = 0; i < path1.size() && i < path2.size(); i++)
		if (path1[i] != path2[i])
			break;
	return path1[i - 1];
}
int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	cout << "LCA(4, 5) = " << findLCA(root, 4, 5);
	cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6);
	cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4);
	cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4);
	return 0;
}



//Range of BST



#include<bits/stdc++.h>
using namespace std;
class node
{
	public:
	int data;
	node *left;
	node *right;
};
void Print(node *root, int k1, int k2)
{
	if ( NULL == root )
		return;

	Print(root->left, k1, k2);
	if ( k1 <= root->data && k2 >= root->data )
		cout<<root->data<<" ";
Print(root->right, k1, k2);
}
node* newNode(int data)
{
	node *temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}
int main()
{
	node *root = new node();
	int k1 = 10, k2 = 25;
	root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->left->right = newNode(12);

	Print(root, k1, k2);
	return 0;
}
