#include <iostream>

using namespace std;

struct Node{

    int data;
    Node* next;

    Node(int val): data(val), next(nullptr) {}
};

class Linklist {
private:
    Node* head;

public:
    Linklist(): head(nullptr) {}

    void add(int data){
        Node* newNode = new Node(data);
        newNode->next = head;  
        head = newNode;        
    }


    void delete_last_node(){
        if(head == nullptr)
            return;

        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while(temp->next->next == nullptr){
            temp = temp->next;
        }

        delete temp->next ;
        temp->next = nullptr;
        return;

    }


    void delete_node(int key){
        if (head == nullptr)
            return;

        if (head -> data ==  key){
            Node* temp = head;
            head = head-> next;
            delete temp;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        while(temp != nullptr && temp -> data != key){
            prev = temp;
            temp = temp -> next;
        }

        if (temp == nullptr) 
            return;
        
        prev -> next = temp -> next;
        delete temp;
    }

    void printf() const{
        Node* temp = head;
        while(temp != nullptr){
            cout << temp-> data << " -> ";
            temp = temp->next;
        }   
        cout << "nullptr" << endl;

    }
};

int main() {
    Linklist list;

    list.add(10);
    list.add(20);
    list.add(30);

    cout << "Initial list: ";
    list.printf();

    // Удаляем последний элемент
    list.delete_last_node();
    cout << "After deleting last element: ";
    list.printf();

    // Удаляем элемент со значением 20
    list.delete_node(20);
    cout << "After deleting node with value 20: ";
    list.printf();

    return 0;
}

// Решение заданий 
// class Solution {
// public:
//     ListNode* deleteMiddle(ListNode* head) {
//         if (head == nullptr || head->next == nullptr) {
//             return nullptr;
//         }
    
//         int n = 0; 
//         ListNode* temp = head;  
//         while(temp != nullptr){
//             n++;
//             temp = temp->next;
//         }

//         int mid_ind = n / 2;
        
//         temp = head;
//         for(int i =0 ; i < mid_ind - 1; i++){
//             temp = temp->next;
//         }
//         ListNode* node_to_del = temp->next;
//         temp->next = temp->next->next;
//         delete node_to_del;        
//         return head;
//         };
// };