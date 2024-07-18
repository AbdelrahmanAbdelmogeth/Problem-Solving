// TrieNode class for individual nodes
class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; ++i)
            child[i] = nullptr;
        isEnd = false;
    }
};

// Interface for trie operations
class ITrieOperations {
public:
    virtual void insert(const std::string& word) = 0;
    virtual bool search(const std::string& word) = 0;
    virtual bool startsWith(const std::string& prefix) = 0;
};

// Concrete Trie class implementing ITrieOperations
class Trie : public ITrieOperations {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    TrieNode* getRoot(){
        return root;
    }
    void insert(const std::string& word) override {
        TrieNode* curr = root;
        for (char x : word) {
            int index = x - 'a';
            if (curr->child[index] == nullptr)
                curr->child[index] = new TrieNode();
            curr = curr->child[index];
        }
        curr->isEnd = true;
    }

    bool search(const std::string& word) override {
        TrieNode* curr = root;
        for (char x : word) {
            int index = x - 'a';
            if (curr->child[index] == nullptr)
                return false;
            curr = curr->child[index];
        }
        return curr->isEnd;
    }

    bool startsWith(const std::string& prefix) override {
        TrieNode* curr = root;
        for (char x : prefix) {
            int index = x - 'a';
            if (curr->child[index] == nullptr)
                return false;
            curr = curr->child[index];
        }
        return true;
    }
};

// WordDictionary class using wildcard matching
class WordDictionary {
private:
    Trie trie;

public:
    WordDictionary() {}

    void addWord(const std::string& word) {
        trie.insert(word);
    }

    bool dfs(string word, TrieNode *trie_node){
        TrieNode *curr = trie_node;
        for(int i=0; i<word.size(); i++){
            char c = word[i];
            if(c == '.'){
                // Explore all child nodes
                for (auto x : curr->child) {
                    if (x != nullptr && dfs(word.substr(i + 1), x)) {
                        return true;
                    }
                }
                return false; // No valid word found
            }else{
                int index = c - 'a';
                if(curr->child[index] == nullptr)
                    return false;
                curr = curr->child[index];
            }
        }
        return curr->isEnd;
    }

    bool search(const std::string& word) {
        return dfs(word, trie.getRoot());
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */