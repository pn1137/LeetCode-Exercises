/*
	637. Average of Levels in Binary Tree

	Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
	Example 1:
	Input:
			3
		 / \
		9  20
			/  \
		 15   7
	Output: [3, 14.5, 11]
	Explanation:
	The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
	Note:
	The range of node's value is in the range of 32-bit signed integer.
*/

///Runtime: 20 ms
///Memory Usage: 22.5 MB

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
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> averages;
        int level = 0;
        int current_width = 1;  // Current level's width
        int width_counter = 1; // Decrement and assign next_width
        int next_width = 0; // Next level's width, Increment and reset
        
        //BFS
        q.push(root); 
        averages.push_back(0.0);
            
        while (!q.empty())
        {
            if (q.front()->left != nullptr)
            {
                q.push(q.front()->left);
                next_width++;
            }
            
            if (q.front()->right != nullptr)
            {
                q.push(q.front()->right);
                next_width++;
            }
            
            averages[level] += q.front()->val;
            
            q.pop();
            width_counter--;
            
            if (width_counter == 0)
            {
                averages[level] /= (double)current_width;
                
                width_counter = current_width = next_width;
                next_width = 0;
                level++;
                
                if (!q.empty())
                averages.push_back(0.0);
            }
        }
        
        return averages;        
    }
};


///sample 4 ms submission
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
/*
class Solution {
public:
    void bfs(TreeNode* root,vector<double>&ans){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            long temp = 0;
            for(int i=0;i<s;i++){
                TreeNode *t =  q.front();
                q.pop();
                if(t->left){
                    q.push(t->left);
                }

                if(t->right){
                    q.push(t->right);
                }    
                temp += t->val;
            }
            ans.push_back((double)temp/s);
        }
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        bfs(root,ans);
        return ans;
    }
};
*/