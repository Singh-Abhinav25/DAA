// menu driven program to perform various operations on a singly linked list

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};
Node* head = nullptr;
Node* tail = nullptr;
int size = 0;

void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }
    ::size++;
    cout << "Inserted " << value << " at the beginning." << endl;
}

void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (tail != nullptr) {
        tail->next = newNode;
    }
    tail = newNode;
    if (head == nullptr) {
        head = newNode;
    }
    ::size++;
    cout << "Inserted " << value << " at the end." << endl;
}

void insertInBetween(int value, int position) {
    if (position < 1 || position > ::size + 1) {
        cout << "Invalid position." << endl;
        return;
    }
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }
    if (position == ::size + 1) {
        insertAtEnd(value);
        return;
    }
    Node* newNode = new Node();
    newNode->data = value;
    Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    ::size++;
    cout << "Inserted " << value << " at position " << position << "." << endl;
}

void deleteFromBeginning() {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    cout << "Deleted " << temp->data << " from the beginning." << endl;
    delete temp;
    ::size--;
}

void deleteFromEnd() {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }
    if (head->next == nullptr) {
        cout << "Deleted " << head->data << " from the end." << endl;
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        cout << "Deleted " << tail->data << " from the end." << endl;
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }
    ::size--;
}

void deleteAtNode(int position) {
    if (position < 1 || position > ::size) {
        cout << "Invalid position." << endl;
        return;
    }
    if (position == 1) {
        deleteFromBeginning();
        return;
    }
    if (position == ::size) {
        deleteFromEnd();
        return;
    }
    Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    cout << "Deleted " << nodeToDelete->data << " from position " << position << "." << endl;
    delete nodeToDelete;
    ::size--;
}

void searchNode(int value) {
    Node* temp = head;
    int position = 1;
    while (temp != nullptr) {
        if (temp->data == value) {
            cout << "Value " << value << " found at position " << position << "." << endl;
            return;
        }
        temp = temp->next;
        position++;
    }
    cout << "Value " << value << " not found in the list." << endl;
}

void displayList() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    cout << "List elements: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void displaySize() {
    cout << "Size of the list: " << ::size << endl;
}

int main() {
    int choice, value;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insertion in between\n";
        cout << "4. Delete from beginning \n";
        cout << "5. Delete from last \n";
        cout << "6. Deletion at node\n";
        cout << "7. Search Node and display its position from head\n";
        cout << "8. Display all nodes\n";
        cout << "9. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                insertAtEnd(value);
                break;
            case 3:
                int position;
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position to insert at: ";
                cin >> position;
                insertInBetween(value, position);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                cout << "Enter position to delete from: ";
                cin >> position;
                deleteAtNode(position);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                searchNode(value);
                break;
            case 8:
                displayList();
                break;
            case 9:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
}        } while (choice != 9);
    return 0;
}