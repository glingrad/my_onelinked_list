#include <iostream>
using namespace std;

// Класс, представляющий узел списка
class Node {
public:
    int data; // Значение, хранящееся в узле
    Node* next; // Указатель на следующий узел в списке

    // Конструктор для инициализации узла
    Node(int value) : data(value), next(nullptr) {}
};

// Класс, представляющий односвязный список
class SinglyLinkedList {
private:
    Node* head; // Указатель на первый узел списка
public:
    // Конструктор для инициализации пустого списка
    SinglyLinkedList() : head(nullptr) {}

    // Метод для добавления узла в конец списка
    void push_back(int val) {
        Node* newnode = new Node(val); // Создаем новый узел
        if (head == nullptr) { // Если список пуст
            head = newnode; // Устанавливаем новый узел как голову
            return;
        }
        Node* curr = head; // Начинаем с головы
        // Проходим до конца списка
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newnode; // Добавляем новый узел в конец
    }

    // Метод для добавления узла в начало списка
    void push_front(int val) {
        Node* newnode = new Node(val); // Создаем новый узел
        newnode->next = head; // Новый узел указывает на текущую голову
        head = newnode; // Новый узел становится головой списка
    }
    // Метод для удаления последнего узла
    void pop_back() {
        if (head == nullptr) {
            cout << "Список пуст. Невозможно удалить последний элемент." << endl;
            return;
        }

        if (head->next == nullptr) { // Если в списке только один узел
            delete head; // Удаляем единственный узел
            head = nullptr; // Обновляем голову
            return;
        }

        Node* curr = head;
        // Ищем предпоследний узел
        while (curr->next->next != nullptr) {
            curr = curr->next; // Переходим к следующему узлу
        }

        delete curr->next; // Удаляем последний узел
        curr->next = nullptr; // Обновляем указатель на nullptr
    }

    // Метод для удаления первого узла
    void pop_front() {
        if (head == nullptr) { // Проверка на пустоту списка
            cout << "Список пуст. Невозможно удалить первый элемент." << endl;
            return;
        }
        Node* temp = head; // Сохраняем текущую голову
        head = head->next; // Обновляем голову
        delete temp; // Удаляем старую голову
    }

    // Метод для вставки узла в заданную позицию
    void insert(int value, int position) {
        if (position < 0) {
            cout << "Позиция не может быть отрицательной." << endl;
            return;
        }
        Node* newNode = new Node(value);
        // Вставка в начало списка
        if (position == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* curr = head;
        int index = 0;

        // Найти узел перед указанной позицией
        while (curr != nullptr && index < position - 1) {
            curr = curr->next;
            index++;
        }
        // Если текущий узел не найден, вставляем в конец
        if (curr == nullptr) {
            cout << "Позиция превышает длину списка. Вставляем в конец." << endl;
            delete newNode; // Удаляем новый узел, если он не будет вставлен
            push_back(value); // Метод для добавления в конец
            return;
        }

        // Вставка нового узла
        newNode->next = curr->next;
        curr->next = newNode;
    }
    // Метод для удаления узла с заданным значением
    void remove(int val) {
        if (head == nullptr) { // Проверка на пустоту списка
            cout << "Список пуст. Невозможно удалить элемент." << endl;
            return;
        }
        Node* curr = head; // Начинаем с головы
        Node* prev = nullptr; // Предыдущий узел

        // Поиск узла с заданным значением
        while (curr != nullptr && curr->data != val) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr) { // Если значение не найдено
            cout << "Значение " << val << " не найдено." << endl;
            return;
        }

        // Удаление узла
        if (curr == head) { // Если удаляем голову
            head = head->next;
        } else {
            prev->next = curr->next; // Пропускаем узел
        }
        delete curr;
        curr = nullptr; // Обнуление указателя после удаления

    }

    // Метод для поиска узла с заданным значением
    void find(int val) {
        if (head == nullptr) { // Проверка на пустоту списка
            cout << "Список пуст." << endl;
            return;
        }
        Node* curr = head; // Начинаем с головы
        // Поиск узла с заданным значением
        while (curr != nullptr) {
            if (curr->data == val) {
                cout << "Найдено значение: " << curr->data << endl;
                return;
            }
            curr = curr->next;
        }
        cout << "Значение не найдено." << endl; // Если значение не найдено
    }

    // Деструктор для освобождения памяти
    ~SinglyLinkedList() {
        Node* current = head; // Начинаем с головы
        while (current) {
            Node* nextNode = current->next; // Сохраняем следующий узел
            delete current; // Удаляем текущий узел
            current = nextNode; // Переходим к следующему узлу
        }
    }
};

int main() {
    SinglyLinkedList list; // Создаем новый односвязный список
    list.push_back(10); // Добавляем 10 в конец списка
    list.push_back(20); // Добавляем 20 в конец списка
    list.insert(5, 0); // Вставка 5 в начало
    list.insert(15, 1); // Вставка 15 в позицию 1
    list.insert(25, 5); // Вставка, превышающая длину списка
    list.find(10); // Поиск 10 в списке
    list.remove(20); // Удаление 20 из списка
    list.pop_back(); // Удаление последнего узла
    list.pop_front(); // Удаление первого узла

    return 0; // Завершение программы
}
