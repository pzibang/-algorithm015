class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL){
            return {};
        }

        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> curLever;
            
            for(int i = 0; i < size; i++){
                Node* tmp = q.front();
                curLever.push_back(tmp->val);
                q.pop();
                for(auto son: tmp->children){
                    q.push(son);
                }
            }

            ans.push_back(curLever);
        }

        return ans;
    }
};
