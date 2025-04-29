// Trie Node structure
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};


class Trie {
private:
    TrieNode* root;

    bool removeHelper(TrieNode* node, const string& key, int depth) {
        if (!node) return false;

        if (depth == key.size()) {
            if (!node->isEndOfWord) return false;
            node->isEndOfWord = false;

            // If the node has no children, it can be deleted
            return node->children.empty();
        }

        char ch = key[depth];
        if (removeHelper(node->children[ch], key, depth + 1)) {
            delete node->children[ch];
            node->children.erase(ch);

            // Return true if the current node has no children and is not end of a word
            return node->children.empty() && !node->isEndOfWord;
        }
        return false;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root;
    }

    void insert(const string& word) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            if (!currentNode->children.count(ch)) {
                currentNode->children[ch] = new TrieNode();
            }
            currentNode = currentNode->children[ch];
        }
        currentNode->isEndOfWord = true;
    }

    bool search(const string& word) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            if (!currentNode->children.count(ch)) {
                return false;
            }
            currentNode = currentNode->children[ch];
        }
        return currentNode->isEndOfWord;
    }

    void remove(const string& word) {
        removeHelper(root, word, 0);
    }

    string longestCommonPrefix(const string& query) {
        TrieNode* currentNode = root;
        string prefix = "";

        for (char ch : query) {
            if (currentNode->children.count(ch) && currentNode->children.size() == 1 && !currentNode->isEndOfWord) {
                prefix += ch;
                currentNode = currentNode->children[ch];
            } else {
                break;
            }
        }
        return prefix;
    }
};
