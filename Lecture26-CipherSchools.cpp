//serialize Deserialize

class Codec {
public:
    string serialize(TreeNode* root) {
        if(root == NULL) {
            return "";
        }
        
        string res = "";
        queue<TreeNode *> q;
        q.push(root);
        
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            if (curr == NULL)
            {
                res.append("#,");
            }

            else
            {
                res += to_string(curr->val)+',';
                if (curr->left)
                {
                    q.push(curr->left);
                }
                else
                {
                    q.push(NULL);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
                else
                {
                    q.push(NULL);
                }
            }
        }
        return res;
    }
  
    TreeNode* deserialize(string data) {
        if (data.size() == 0)
        {
            return NULL;
        }
        stringstream ss(data);
        string str;
        getline(ss,str, ',');
        
        TreeNode *ans;
        queue<TreeNode *> q;
        
       
        ans = new TreeNode(stoi(str));
        q.push(ans);
        
    
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            getline(ss,str,','); 
            if (str == "#")
            {
                curr->left = NULL;
            }
            else
            {
                curr->left = new TreeNode(stoi(str));
                q.push(curr->left);
            }
            
            getline(ss,str,',');
            if (str == "#")
            {
                curr->right = NULL;
            }
            else
            {
                curr->right = new TreeNode(stoi(str));
                q.push(curr->right);
            }
        }
        return ans;        
    }
};







//Root to leaf\



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





///
