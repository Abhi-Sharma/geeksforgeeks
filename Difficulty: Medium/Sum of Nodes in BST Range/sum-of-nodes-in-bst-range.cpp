/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
        if(!root) return 0;
        stack<Node*> st;
        st.push(root);
        int sum = 0;
        while(!st.empty()){
            Node* node = st.top();
            st.pop();
            if(!node) continue;
            if(node->data >= l && node->data <= r){
                sum += node->data;
            }
            if(node->data > l) st.push(node->left);
            if(node->data < r) st.push(node->right);
        }
        return sum;
    }
};
