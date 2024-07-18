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
    virtual void _delete(const std::string& word) = 0;
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

    bool isEmpty(TrieNode *root){
        for(int i=0; i<26; i++)
            if(root->child[i] != nullptr)
                return false;
        return true;        
    }

    void _delete(const std::string& word) override{
        // check if the word we want to delete exists in the trie if it's not we return
        if(!search(word))
            return;

        // determine if the word is a part of a branch or it's a branch itself 
        std::stack<TrieNode*> trie_node_ptr_st;
        TrieNode* curr = root;
        for (char x : word) {
            int index = x - 'a';
            trie_node_ptr_st.push(curr);
            curr = curr->child[index];
        }
        curr->isEnd = false; // this will delete the word if it's part of a branch

        // if it's a branch itself then we need to delete that branch
        if (isEmpty(curr)) {
            while (!trie_node_ptr_st.empty()) {
                TrieNode* node_to_delete = trie_node_ptr_st.top();
                trie_node_ptr_st.pop();
                int index = word[trie_node_ptr_st.size()] - 'a';
                node_to_delete->child[index] = nullptr; // Remove the link to the last node
                delete curr;
                curr = node_to_delete;
            }
        }
    }
};

class Solution {
private:
    int rows, cols;
    Trie trie;

    void dfs(vector<vector<char>>& board, int row_ind, int col_ind,
            TrieNode* curr, std::vector<std::vector<bool>> &visited,
            std::vector<std::string> &result, string str) {
        
        if (row_ind < 0 || row_ind >= rows || col_ind < 0 || col_ind >= cols || visited[row_ind][col_ind])
            return;

        char c = board[row_ind][col_ind];
        int index = c - 'a';
        if (curr->child[index] == nullptr)
            return; // No valid word with this prefix

        curr = curr->child[index];
        str += c;
        visited[row_ind][col_ind] = true;

        if (curr->isEnd) {
            result.push_back(str);
            curr->isEnd = false; // Mark as visited
        }

        static const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (const auto& dir : directions) {
            int ni = row_ind + dir.first;
            int nj = col_ind + dir.second;
            dfs(board, ni, nj, curr, visited, result, str);
        }
        
        visited[row_ind][col_ind]=false;    
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = board.size();
        cols = board[0].size();
            
        std::vector<std::vector<bool>> visited;    
        visited.assign(rows, std::vector<bool>(cols, false));
        
        std::vector<std::string> result;    

        for (const auto& word : words)
            trie.insert(word);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                dfs(board, i, j, trie.getRoot(), visited, result, "");
            }
        }

        return result;
    }
};