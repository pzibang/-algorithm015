class Solution {
public:
    TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        //termination
        if(root == NULL){
            return false;
        }

        //process current logic
        //drill down
        bool rson = dfs(root->right, p, q);
        bool lson = dfs(root->left, p, q);

        if((rson && lson) || ((root->val == p->val) ||(root->val == q->val)) && (rson || lson)){
            ans = root;
        }

        //reserve current static if needed

        return (rson || lson || ((root->val == p->val) ||(root->val == q->val)) );
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        dfs(root, p, q);
        return ans;
    }
};
