#include "PipleTree.h"
#include <memory>
#include <iostream>

PipleTree::PipleTree() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            friend_matrix[i][j] = 0;
    for (int i = 0; i < SIZE; i++) {
        busyids.add(false);
    }
}
void PipleTree::add(char name) {
    if(root == nullptr) {
        // если дерево пустое, то новый элемент станет корнем
        root = new Node(name);
    }
    else {
        Node* current = root; // начинаем с корня
        Node* newNode = nullptr;
        while(newNode == nullptr) {
			newNode = new Node(name, current);
            current->rightChild = newNode;
        }
    }
}

void PipleTree::setFriendship(char name_1, char name_2) {
    Node m1 = findManByName(name_1);
    Node m2 = findManByName(name_2);
    if (m1.id < 0 || m2.id < 0)
        return;
    friend_matrix[m1.id][m2.id] = 1;
    friend_matrix[m2.id][m1.id] = 1;
}

void PipleTree::showThreeHandshakes() {
    int wavesLevels[SIZE];
    for (int i = 0; i < SIZE; i++) {
        wavesLevels[i] = -1;
    }
    wavesLevels[0] = 0;

    StaticArray<int> queue;
    queue.add(0);

    while (queue.size()) {
        int currentManIndex = queue[0];
        queue.del(0);
        for (int i = 0; i < people.size(); i++)
            if (are_friends(people[currentManIndex], people[i]) &&
                  wavesLevels[i] == -1) 
            {
                wavesLevels[i] = wavesLevels[currentManIndex] + 1;
                queue.add(i);
            }
    }

    for (int i = 0; i < people.size(); i++) {
        for (int j = i + 1; j < people.size(); j++) {
            if (abs(wavesLevels[i] - wavesLevels[j]) <= 3) {
                std::cout << people[i].name << " " << people[j].name << std::endl;
            }
        }
    }
}


bool PipleTree::are_friends(const Node& m1, const Node& m2) {
    return friend_matrix[m1.id][m2.id] == 1;
}

PipleTree::Node PipleTree::findManByName(const Name name) {
    for (int i = 0; i < people.size(); i++)
        if (!strcmp(name, people[i].name))
            return people[i];
    return Node();
}
