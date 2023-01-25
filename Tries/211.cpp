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

class WordDictionary {
public:
    TrieNode* root;
    
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
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
        return recursiveSearch(temp, 0, word);
    }
    
    bool recursiveSearch(TrieNode* node, int index, string &word){
        if(node == NULL){
            return false;
        }
        if(index == word.size()){
            return node->isWord;
        }
        if(word[index] != '.'){
            return recursiveSearch(node->children[word[index]-'a'], index+1,word);
        }else{
            for(int i = 0;i < 26;i++){
                if(recursiveSearch(node->children[i],index+1,word)){
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */