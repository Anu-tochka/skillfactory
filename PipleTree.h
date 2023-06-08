#pragma once

#define SIZE 5

class PipleTree {
    public:
        struct Node { // структура узла
            Node();
            
            Node* leftNode; // левый узел
            Node* rightNode; // правый узел
            
            char Name; 
        };
    
        PipleTree()
        {
            root = nullptr;
        };
		
        ~PipleTree()
        {
            if(root != nullptr)
            {
                delete root;
            }
        };

		void add(char name);
		void setFriendship(char name_1, char name_2);
		void showThreeHandshakes();
		
    private:       
        Node* root; // корневой узел
		bool are_friends(const Human& m1, const Human& m2);
        
        // поиск по имени
        Human findManByName(const Name name);
    private: 
        int friend_matrix[SIZE][SIZE]; // матрица дружбы
};