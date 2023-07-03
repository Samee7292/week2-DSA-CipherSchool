//left max sum

#include <iostream>
#include <climits>
using namespace std;


struct Node
{
	int data;
	Node *left, *right;

	Node(int data)
	{
		this->data = data;
		this->left = this->right = nullptr;
	}
};


int findMaxSumPath(Node* root, int &max_sum)
{
	
	if (root == nullptr) {
		return 0;
	}


	int left = findMaxSumPath(root->left, max_sum);

	
	int right = findMaxSumPath(root->right, max_sum);

	

	
	if (root->left == nullptr) {
		return right + root->data;
	}


	if (root->right == nullptr) {
		return left + root->data;
	}

	
	int cur_sum = left + right + root->data;

	
	max_sum = max(cur_sum, max_sum);

	
	return max(left, right) + root->data;
}


int findMaxSumPath(Node* root)
{
	int max_sum = INT_MIN;
	findMaxSumPath(root, max_sum);

	return max_sum;
}

int main()
{
	

	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->right = new Node(-4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(8);

	cout << findMaxSumPath(root) << endl;

	return 0;
}









//max sum path

//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



class Solution{
    public:
    
    void solve(Node *root,int curr,int &ans){
        if(!root) return;
        curr += root->data;
        if(!root->left && !root->right) {
            ans = max(ans,curr);
            return;
        }
        solve(root->left,curr,ans);
        solve(root->right,curr,ans);
    }
    
    int maxPathSum(Node* root)
    {
        int ans = INT_MIN;
        solve(root,0,ans);
        return ans;
    }
};


  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.maxPathSum(root) << endl;
    }
    return 0;
}








//postorderInorder



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
typedef TreeNode Node;
class Solution {
public:
    void build(unordered_map<int,int> &mp,vector<int> &inorder){
        for(int i =0 ;i<inorder.size();i++)
            mp[inorder[i]]=i;
        return;
    }

    Node* solve(vector<int> &pre,vector<int> &in,int &index,int start,int end,int size,unordered_map<int,int> &mp){
        if(index >= size || start > end) return NULL;
        int ele = pre[index++];
        Node * root= new Node(ele);
        root->left = solve(pre,in,index,start,mp[ele]-1,size,mp);
        root->right = solve(pre,in,index,mp[ele]+1,end,size,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index =0 ;
        unordered_map<int,int> mp;
        build(mp,inorder);
        int n = preorder.size();
        return solve(preorder,inorder,index,0,n-1,n,mp);
    }
};












