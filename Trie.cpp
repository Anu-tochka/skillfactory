#include "Trie.h"
#include <memory>
#include <iostream>


// корневой узел с пустыми детьми
Trie *root('a')
{
   // Выделяем память под новый узел
   struct Trie *pNode =  new Trie;

   // устанавливаем флаг конца слова в false
   pNode->isEndOfWord = false;

   // инициализируем детей нулевым указателем
   for (int i = 0; i < SIZE; i++)
       pNode->children[i] = nullptr;

   return pNode;
}

void Trie::add(string str) {
    Trie* current = root; // начинаем с корня
    Trie* newNode = nullptr;
    for (int i = 0; i < str.length(); i++) {
        if (current->children[str[i]-'a'] == NULL) {
            current->children[str[i]-'a'] = new Trie;
            current->children[str[i]-'a']->word = str[i);
        }
        current = current->children[str[i]-'a'];
    }
    current->isEndOfWord = true;
}

bool Trie::search(string key)
{
   Trie *node = root;
   for (int i = 0; i < key.length(); i++)
   {
       int index = key[i] - 'a';
       if (!node->children[index])
           return false;

       node = node->children[index];
   }

   return (node != nullptr && node->isEndOfWord);
}

void Trie::print (TrieNode * current, string prefix) {
        if (current->end_of_word) {
            cout << prefix << endl;
        }
        for (int i=0; i<SIZE; i++) {
            string temp = prefix;
            if (current->children[i]) {
                temp += current->children[i]->letter;
                print(current->children[i], temp);
            }
        }
    }
}



