class WordDictionary {
public:
    struct TrieNode {
        TrieNode* child[26];
        bool isWord;
        TrieNode()
            : isWord(false)
        {
            for (auto& a : child) {
                a = NULL;
            }
        }
    };
    /** Initialize your data structure here. */
    WordDictionary() { root = new TrieNode(); }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        TrieNode* p = root;
        for (auto& a : word) {
            int i = a - 'a';
            if (!p->child[i])
                p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }

    /** Returns if the word is in the data structure. A word could contain the
     * dot character '.' to represent any one letter. */
    bool search(string word) { return searcWord(word, root, 0); }

    bool searcWord(string& word, TrieNode* p, int i)
    {
        if (i == word.size())
            return p->isWord;
        if (word[i] == '.') {
            for (auto& a : p->child) {
                if (a && searcWord(word, a, i + 1))
                    return true;
            }
            return false;
        } else {
            return p->child[word[i] - 'a']
                && searcWord(word, p->child[word[i] - 'a'], i + 1);
        }
    }

private:
    TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
