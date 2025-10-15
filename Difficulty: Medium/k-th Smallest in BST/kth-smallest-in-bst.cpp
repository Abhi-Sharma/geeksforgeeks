/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int kthSmallest(Node *root, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* node= q.front();
            q.pop();
            pq.push(node->data);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        int min = 0;
        while(k){
            if(pq.empty()) return -1;
            min = pq.top();
            pq.pop();
            k--;
        }
        return min;
    }
};