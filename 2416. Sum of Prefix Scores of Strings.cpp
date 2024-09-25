#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;
    int freq = 0; // Initialize frequency to 0

    bool containsKey(char c)
    {
        return links[c - 'a'] != NULL;
    }

    void put(char c, Node *node)
    {
        links[c - 'a'] = node;
    }

    Node *get(char c)
    {
        return links[c - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }

    void increaseFreq()
    {
        freq++;
    }

    int getFreq()
    {
        return freq;
    }
};

class Trie
{
public:
    Node *root;

    Trie()
    { // Initialize root
        root = new Node();
    }

    void insert(const string &s)
    {
        Node *node = root;
        for (char ch : s)
        {
            if (!node->containsKey(ch))
            {
                node->put(ch, new Node());
            }
            node = node->get(ch); // Move to the next node
            node->increaseFreq(); // Increase frequency after moving to the next node
        }
        node->setEnd();
    }

    int getPrefixScore(const string &s)
    {
        Node *node = root;
        int totalScore = 0;

        for (char ch : s)
        {
            if (!node->containsKey(ch))
            {
                return totalScore; // If character doesn't exist, return the accumulated score
            }
            node = node->get(ch);          // Move to the next node
            totalScore += node->getFreq(); // Add the frequency of the current node
        }

        return totalScore;
    }
};

class Solution
{
public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        Trie trie;
        vector<int> result;

        // Insert all words into the Trie
        for (const string &word : words)
        {
            trie.insert(word);
        }

        // Calculate prefix scores for each word
        for (const string &word : words)
        {
            result.push_back(trie.getPrefixScore(word));
        }

        return result;
    }
};

int main()
{
    Solution sl;
    vector<string> words = {"abc", "ab", "bc", "b"};
    vector<int> ans = sl.sumPrefixScores(words);

    for (int i : ans)
        cout << i << " ";

    return 0;
}