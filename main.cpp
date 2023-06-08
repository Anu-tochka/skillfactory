#include <iostream>
#include "Trie.h"

using namespace std;

int main(char* ar[], int count)
{
    Trie tr;

    tr.add("ability");
    tr.add("acacia");
    tr.add("acorn");
    tr.add("acumen");
    tr.add("adder");
	tr.add("ado");
    tr.add("aerodrom");
    tr.add("aeroplane");
    tr.add("affray");
    tr.add("age");
    tr.add("aim");
    tr.add("air");
    tr.add("alder");
    tr.add("ale");
    tr.add("alloy");
    tr.add("amber");
    tr.add("amity");
    tr.add("ancoir");
    tr.add("angel");
    tr.add("ant");
    tr.add("apex");
    tr.add("apple");
    tr.add("apron");
    tr.add("arm");
    tr.add("army");
    tr.add("arrow");
    tr.add("ash");
    tr.add("asp");
    tr.add("atom");
    tr.add("attic");
    tr.add("auger");
    tr.add("aunt");
    tr.add("avarice");
    tr.add("awe");
    tr.add("axe");
    tr.add("axis");
    tr.add("azote");
    
	string s = '';
    cout << "Введите начало слова на a: "; 
    cin >> s;
	string prefix(s);

    Trie * current = Trie->search(prefix);

    if (current == NULL or current == Trie->root) {
        cout << "Нет подходящих слов" << endl;
    } else {
        bool haschildren = false;
        for (int c = 0; c < SIZE; c++) {
            if (current->children[c] != NULL) {
                 haschildren = true; break;
            }
        }
        if (haschildren == false) {
            cout << "Нет подходящих слов" << endl;
        } else {
            cout << "Найдены слова: " << prefix << endl;
            Trie->зrint(current, prefix);
        }
    }
    return 0;
}