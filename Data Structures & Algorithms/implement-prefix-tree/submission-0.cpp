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

class PrefixTree {
public:
    TriesNode* triesNode;
    PrefixTree() {
        triesNode = new TriesNode('0');
    }
    
    void insert(string word) {
        TriesNode* temp = triesNode;
        for(int i=0; i<word.size(); i++) {
            if(!temp->children[word[i]-'a']) {
                temp->children[word[i]-'a'] = new TriesNode(word[i]);
            }
            temp = temp->children[word[i]-'a'];

            if(word.size()-1 == i) temp->isTerminal = true;
        }
    }
    
    bool search(string word) {
        TriesNode* temp = triesNode;
        
        for(int i=0; i<word.size(); i++) {
            if(temp->children[word[i]-'a']) {
                temp = temp->children[word[i]-'a'];
            }
            else return false;

            if(word.size()-1 == i && !temp->isTerminal) return false;
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        TriesNode* temp = triesNode;
        
        for(int i=0; i<prefix.size(); i++) {
            if(temp->children[prefix[i]-'a']) {
                temp = temp->children[prefix[i]-'a'];
            }
            else return false;
        }
        return true;
    }
};
