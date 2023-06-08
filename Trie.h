#pragma once 

#define SIZE 20

class Trie
{
public:
   /* struct*/ Trie/*Node*/ *children[SIZE];
   // isEndOfWord - true, если ключ является концом слова
   bool isEndOfWord;
//   Snack(const char* snackName);// конструктор
 	~Trie(); // деструктор
    char word;
    void print (TrieNode * current, string prefix);
    bool search(string key)
    void add(string str);
};