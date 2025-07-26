class WordDictionary{
    struct Node{
        Node* links[26]{};
        bool end=false;
    };

    Node* root;

    bool dfs(string &word,int idx,Node* node){
        if(idx==word.size())return node->end;
        char ch=word[idx];
        if(ch!='.'){
            if(!node->links[ch-'a'])return false;
            return dfs(word,idx+1,node->links[ch-'a']);
        }
        for(int i=0;i<26;i++){
            if(node->links[i]&&dfs(word,idx+1,node->links[i]))return true;
        }
        return false;
    }

  public:
    WordDictionary(){root=new Node();}

    void addWord(string word){
        Node* node=root;
        for(char ch:word){
            if(!node->links[ch-'a'])node->links[ch-'a']=new Node();
            node=node->links[ch-'a'];
        }
        node->end=true;
    }

    bool search(string word){
        return dfs(word,0,root);
    }
};
