class Trie{
    struct Node{
        Node* links[26];
        bool end=false;
        bool contains(char ch){return links[ch-'a']!=nullptr;}
        void put(char ch,Node* node){links[ch-'a']=node;}
        Node* get(char ch){return links[ch-'a'];}
        void setEnd(){end=true;}
        bool isEnd(){return end;}
    };
    
    Node* root;

  public:
    Trie(){root=new Node();}

    void insert(string word){
        Node* node=root;
        for(char ch:word){
            if(!node->contains(ch)){
                node->put(ch,new Node());
            }
            node=node->get(ch);
        }
        node->setEnd();
    }

    bool search(string word){
        Node* node=root;
        for(char ch:word){
            if(!node->contains(ch))return false;
            node=node->get(ch);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix){
        Node* node=root;
        for(char ch:prefix){
            if(!node->contains(ch))return false;
            node=node->get(ch);
        }
        return true;
    }
};
