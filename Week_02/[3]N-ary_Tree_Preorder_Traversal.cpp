
//1. recursive

class Solution {
private:
    void traver(Node* root, vector<int>& res){
        if(root == NULL){
            return ;
        }

        res.push_back(root->val);
        for(Node* i: root->children){
            traver(i, res);
        }
    }
public:
    vector<int> preorder(Node* root) {
         if(root == NULL){
            return {};
        }
        vector<int> res;
        traver(root, res);

        return res;
    }
};

//2. iterative
class Solution {

public:
    vector<int> preorder(Node* root) {
        vector<int> res;
         if(root == NULL){
            return res;
        }
        
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            Node *cur = st.top();
            st.pop();
            res.push_back(cur->val);

            for(int i = cur->children.size()-1; i >= 0; i--){
                if(cur->children[i] != NULL){
                    st.push(cur->children[i]);
                }
            }
        }
        
        return res;
    }
};


