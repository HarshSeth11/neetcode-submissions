class TriesNode {
public:
    char val;
    TriesNode* children[26];
    bool isTerminal;

    TriesNode(char ch) {
        val = ch;
        for(int i=0; i<26; i++) children[i] = NULL;
        isTerminal = false;
    }
};

class WordDictionary {
public:
    TriesNode* triesNode;
    WordDictionary() {
        triesNode = new TriesNode('0');
    }
    
    void addWord(string word) {
        TriesNode* temp = triesNode;
        for(int i=0; i<word.size(); i++) {
            if(!temp->children[word[i]-'a']) {
                temp->children[word[i]-'a'] = new TriesNode(word[i]);
            }
            temp = temp->children[word[i]-'a'];

            if(word.size()-1 == i) temp->isTerminal = true;
        }
    }

    bool help(string& word, TriesNode* node, int idx) {
        if(idx == word.size())
            return node->isTerminal;

        if(word[idx] == '.') {
            for(int j = 0; j < 26; j++) {
                if(node->children[j] &&
                help(word, node->children[j], idx + 1))
                    return true;
            }
            return false;
        }

        int ch = word[idx] - 'a';

        if(!node->children[ch])
            return false;

        return help(word, node->children[ch], idx + 1);
    }
    
    bool search(string word) {
        TriesNode* temp = triesNode;
        
        return help(word, triesNode, 0);
    }
};
