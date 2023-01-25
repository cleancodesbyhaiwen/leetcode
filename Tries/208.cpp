class TrieNode{
public:    
    TrieNode* children[26];
    bool isWord;
    
    TrieNode(){
        for(int i = 0;i < 26;i++){
            children[i] = NULL;
        }
        isWord = false;
    }

};


class Trie {
public:
    
    TrieNode* root = new TrieNode();

    Trie() {

    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(int i = 0;i < word.size();i++){
            if(temp->children[word[i]-'a'] == NULL){
                temp->children[word[i]-'a'] = new TrieNode();
            }
            temp = temp->children[word[i]-'a'];
        }
        temp->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        
        for(int i = 0;i < word.size();i++){
            if(temp->children[word[i]-'a'] == NULL){
                return false;
            }
            temp = temp->children[word[i]-'a'];
        }
        return temp->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(int i = 0;i < prefix.size();i++){
            if(temp->children[prefix[i]-'a'] == NULL){
                return false;
            }
            temp = temp->children[prefix[i]-'a'];
        }        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */