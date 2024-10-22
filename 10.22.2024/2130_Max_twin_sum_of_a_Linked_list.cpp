// Solution for problem 2130: Max twin sum of a Linked list

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Определение структуры узла односвязного списка
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Класс решения для задачи
class Solution {
public:
    // Подход через вектор (как у тебя в первом варианте)
    int pairSum(ListNode* head) {
        vector<int> val;
        ListNode* temp = head;
        while (temp != nullptr) {
            val.push_back(temp->val);
            temp = temp->next;
        }

        int n = val.size();
        int max_sum = 0;
        for (int i = 0; i < n / 2; i++) {
            int sum = val[i] + val[n - 1 - i];
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }

    // Подход через два указателя без дополнительной памяти
    int pairSum_two_point(ListNode* head) {
        ListNode* slow = head, *fast = head;
        ListNode* prev = nullptr;

        // Шаг 1: Найти середину списка и развернуть первую половину
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            ListNode* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        // Шаг 2: Найти максимальную сумму близнецов
        int max_sum = 0;
        while (slow != nullptr) {
            max_sum = max(max_sum, prev->val + slow->val);
            prev = prev->next;
            slow = slow->next;
        }

        return max_sum;
    }
};

// Функция для создания списка из массива
ListNode* createLinkedList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for (size_t i = 1; i < arr.size(); ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

// Функция для вывода связанного списка
void printLinkedList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    // Создание тестового примера списка
    vector<int> values = {1, 2, 23, 4, 423, 543, 7, 1000};
    ListNode* head = createLinkedList(values);

    // Вывод исходного списка
    cout << "Linked list ";
    printLinkedList(head);

    Solution ans;

    // Тестирование первого подхода через вектор
    int result1 = ans.pairSum(head);
    cout << "max with vector: " << result1 << endl;

    // Тестирование второго подхода через два указателя
    int result2 = ans.pairSum_two_point(head);
    cout << "nax with two pointers: " << result2 << endl;

    return 0;
}
