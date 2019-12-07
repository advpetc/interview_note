/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:
        int target;
    public:
        vector<string> binaryTreePaths(TreeNode* root) {
            if (!root) { return {}; }
            target = 2;
            vector<string> res;
            dfs(root, res, to_string(root -> val));
            return res;
        }

        /******************************************************************************
        * Function:         void dfs
        * Description:      search all the path until to the leaf nodes
        * Where:            from root node
        * Return:           void 
        * Error:            NaN 
        *****************************************************************************/
        void dfs(TreeNode* node, vector<string>& str, string nxt){
            if (!node -> left && !node -> right) {
                str.push_back(nxt);
                return;
            }
            if (node -> left) {
                if (node -> left -> val == target)
                    cout << "(" << nxt << "->" << target << ")" << endl;
                dfs(node -> left, str, nxt + "->" + to_string(node -> left -> val));
            }
            if (node -> right) {
                if (node -> right -> val == target)
                    cout << "(" << nxt << "->" << target << ")" << endl;
                dfs(node -> right, str, nxt + "->" + to_string(node -> right -> val));
            }
        }
};
