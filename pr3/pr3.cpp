#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int value) :
        data(value),
        next(nullptr),
        prev(nullptr) {
    }
};
class DoublyLinkedList {
public:

    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    void push_front(int value) {
        Node* node = new Node(value);
        node->next = head;
        if (head != nullptr) {
            head->prev = node;
        }
        else {
            
            tail = node;
        }
        head = node;
    }
    void push_back(int value) {
        Node* node = new Node(value);
        node->prev = tail;
        if (tail != nullptr) {
            tail->next = node;
        }
        else {
           
            head = node;
        }
        tail = node;
    }
    void pop_front() {
        if (head == nullptr) {
            cout << "Список пуст, удалять нечего." << endl;
            return;
        }

        Node* node = head;
        head = head->next;  

        if (head != nullptr) {
            head->prev = nullptr;  
        }
        else {
            tail = nullptr;  
        }

        delete node;  
    }
    void pop_back() {
        if (tail == nullptr) {
            cout << "Список пуст, удалять нечего." << endl;
            return;
        }

        Node* node = tail;
        tail = tail->prev;  

        if (tail != nullptr) {
            tail->next = nullptr;  
        }
        else {
            head = nullptr; 
        }

        delete node;  
    }
    void display() {
        Node* node = head;
        if (node == nullptr) {
            cout << "Список пуст" << endl;
            return;
        }
        while (node != nullptr) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }

    void sort() {
        if (head == nullptr) {
            return; 
        }

        bool swapped;
        Node* current;
        Node* last = nullptr; 

        do {
            swapped = false;
            current = head;

            while (current->next != last) {
                if (current->data > current->next->data) {
                    
                    int temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    swapped = true;
                }
                current = current->next;
            }
            last = current; 

        } while (swapped); 
    }
    
    void remove_duplicates()
    {

    }
  
};
int main() {
    setlocale(LC_ALL, "Russian");
    DoublyLinkedList trum;

    while (true) {
        cout << "\nМЕНЮ:" << endl;
        cout << "1. Добавить элемент в начало.\n"
            << "2. Добавить элемент в конец.\n"
            << "3. Удалить элемент с начала.\n"
            << "4. Удалить элемент с конца.\n"
            << "5. Отобразить список.\n"
            << "6. Сортировать список.\n"
            << "7. Удалить дубликаты.\n"
            << "8. Выход." << endl;
        cout << "Введите номер команды: ";
        int a;
        cin >> a;

        switch (a) {
        case 1: {
            int value;
            cout << "\nВведите элемент, который хотите добавить: ";
            cin >> value;
            trum.push_front(value);
            trum.display();
            break;
        }
        case 2: {
            int value;
            cout << "\nВведите элемент, который хотите добавить: ";
            cin >> value;
            trum.push_back(value);
            trum.display();
            break;
        }
        case 3: {
            cout << "\nУдаление элемента из начала списка" << endl;
            trum.pop_front();
            trum.display();
            break;
        }
        case 4: {
            cout << "\nУдаление элемента из конца списка" << endl;
            trum.pop_back();
            trum.display();
            break;
        }
        case 5: {
            trum.display();
            break;
        }
        case 6: {
            trum.sort();
            cout << "\nСортированный список:" << endl;
            trum.display();
            break;
        }
        case 7: {
            cout << "\nУдаление дупликатов" << endl;
            trum.remove_duplicates();
            cout << "\nОТРЕДАКТИРОВАННЫЙ СПИСОК:" << endl;
            trum.display();
            break;
        }
        case 8: {
            cout << "\nВыход из программы." << endl;
            return 0;  
        }
        default: {
            cout << "\nВведено некорректное значение." << endl;
        }
        }
    }
}
