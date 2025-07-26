struct Node{
    char ch;
    int freq;
    Node *left,*right;
    Node(char c,int f){
        ch=c;freq=f;
        left=right=nullptr;
    }
};

struct cmp{
    bool operator()(Node *a,Node *b){
        return a->freq>b->freq;
    }
};


class Solution {
  public:
    void preorder(Node *root,string code,vector<string> &res){
        if(!root)return;
        if(!root->left&&!root->right)res.push_back(code);
        preorder(root->left,code+"0",res);
        preorder(root->right,code+"1",res);
    }

    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        // Code here
        priority_queue<Node*,vector<Node*>,cmp> pq;
        for(int i=0;i<N;i++)pq.push(new Node(S[i],f[i]));
        while(pq.size()>1){
            Node *l=pq.top();pq.pop();
            Node *r=pq.top();pq.pop();
            Node *m=new Node('$',l->freq+r->freq);
            m->left=l;m->right=r;
            pq.push(m);
        }
        vector<string> res;
        preorder(pq.top(),"",res);
        return res;
    }
};