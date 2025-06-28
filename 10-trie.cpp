
//    WE ARE GGOING TO IMPLEMENT A TRIE DATA STRUCTURE, USING IT TO MAKE DICTIONARY

#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26]; // Assuming only lowercase letters a-z
    bool isTerminal; // Indicates if the node marks the end of a word to
                     // differentiate between "abc" and "abcde"

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;
public:
    Trie()
    {
        root = new TrieNode('\0'); // Root node initialized with null character
    }

    void insertUtil(TrieNode *node, string word)
    {
        if (word.length() == 0)
        {
            node->isTerminal = true;
            return;
        }

        int index = word[0] - 'a'; //assuming all characters are lowercase a-z
        TrieNode *child;

        if (node->children[index] != nullptr) // present
        {
            child = node->children[index];
        }
        else // absent
        {
            child = new TrieNode(word[0]);
            node->children[index] = child;
        }
        insertUtil(child, word.substr(1)); // Recur for the next character
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *node, string word)
    {
        if (word.length() == 0)
        {
            return node->isTerminal; 
        }

        int index = word[0] - 'a'; 
        TrieNode *child;
        if (node->children[index] != nullptr) // present
        {
            child = node->children[index];
        }
        else // absent
        {
            return false; // Word not found
        }
        return searchUtil(child, word.substr(1)); // Recur for the next character
    }

    bool search(string word)
    {
        return searchUtil(root, word);
    }

    void removeUtil(TrieNode *node, string word)
    {
        if (word.length() == 0)
        {
            node->isTerminal = false; // Mark the end of the word as false
            return;
        }

        int index = word[0] - 'a'; // Assuming all characters are lowercase a-z
        TrieNode *child;

        if (node->children[index] != nullptr) // present
        {
            child = node->children[index];
            removeUtil(child, word.substr(1)); // Recur for the next character

            // If child is not terminal and has no children, delete it
            if (!child->isTerminal)
            {
                for (int i = 0; i < 26; i++)
                {
                    if (child->children[i] != nullptr)
                        return; // Child has children, so we cannot delete it
                }
                delete child; // Delete the child node
                node->children[index] = nullptr; // Remove reference from parent
            }
        }
    }
    void removeWord(string word)
    {
        removeUtil(root, word);
    }

};

int main()
{
    Trie* t = new Trie();
    t->insertWord("abcd");
    t->insertWord("abcde");
    cout << "Present or Not: " << t->search("abcd") << endl; // Should return true
    cout << "Present or Not: " << t->search("abcde") << endl;
    t->removeWord("abcde");
    cout << "Present or Not: " << t->search("abcde") << endl; // Should return false
}