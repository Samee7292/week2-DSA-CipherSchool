//kth smallest element

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		left = right = NULL;
	}
};

Node* insert(Node* root, int x)
{
	if (root == NULL)
		return new Node(x);
	if (x < root->data)
		root->left = insert(root->left, x);
	else if (x > root->data)
		root->right = insert(root->right, x);
	return root;
}
int count = 0;
Node* kthSmallest(Node* root, int& k)
{
	if (root == NULL)
		return NULL;
	Node* left = kthSmallest(root->left, k);
	if (left != NULL)
		return left;
	count++;
	if (count == k)
		return root;
	return kthSmallest(root->right, k);
}
void printKthSmallest(Node* root, int k)
{Node* res = kthSmallest(root, k);
	if (res == NULL)
		cout << "There are less than k nodes in the BST";
	else
		cout << "K-th Smallest Element is " << res->data;
}

int main()
{
	Node* root = NULL;
	int keys[] = { 20, 8, 22, 4, 12, 10, 14 };

	for (int x : keys)
		root = insert(root, x);

	int k = 3;
	printKthSmallest(root, k);
	return 0;
}



//median of infinite integers


#include <bits/stdc++.h>

using namespace std;
int binarySearch(float arr[], float item, int low, int high)
{
	if (low >= high) {
		return (item > arr[low]) ? (low + 1) : low;
	}

	int mid = (low + high) / 2;

	if (item == arr[mid])
		return mid + 1;

	if (item > arr[mid])
		return binarySearch(arr, item, mid + 1, high);

	return binarySearch(arr, item, low, mid - 1);
}
void printMedian(float arr[], int n)
{
	int i, j, pos;
	float num;
	int count = 1;

	cout << "Median after reading 1"
		<< " element is " << arr[0] << "\n";

	for (i = 1; i < n; i++) {
		float median;
		j = i - 1;
		num = arr[i];
		pos = binarySearch(arr, num, 0, j);
		while (j >= pos) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = num;
		count++;
		if (count % 2 != 0) {
			median = arr[count / 2];
		}
		else {
			median = (arr[(count / 2) - 1] + arr[count / 2])
					/ 2;
		}

		cout << "Median after reading " << i + 1
			<< " elements is " << median << "\n";
	}
}

int main()
{
	float arr[] = { 5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printMedian(arr, n);

	return 0;
}
