// CS303_Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>
#include "SinglyLinkedList.h"
/// using namespace std;

SinglyList::SinglyList() : head(nullptr), tail(nullptr), num_items(0) {}

SinglyList::~SinglyList() {
    while (!empty()) {
        pop_front();
    }
}

bool SinglyList::empty() const { 
    return num_items == 0;
}

void SinglyList::push_front(int item) { //add to the front of list
    Node* newNode = new Node(item);
    newNode->next = head;
    head = newNode;

    if (num_items == 0) {
        tail = head;
    }

    num_items++;
}

void SinglyList::push_back(int item) { //add to the back of list
    Node* newNode = new Node(item);
    if (empty()) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }

    num_items++; //iterate
}

void SinglyList::pop_front() { 
    if (empty()) throw std::underflow_error("The list is empty"); // throws error if the list is empty or num_items = 0

    Node* temp = head;
    head = head->next;
    delete temp;

    num_items--;
    if (num_items == 0) tail = nullptr;
}

void SinglyList::pop_back() {
    if (empty()) throw std::underflow_error("The list is empty");

    if (head == tail) { // only one item in the list
        delete head;
        head = tail = nullptr;
    }
    else {
        Node* prev = head;
        while (prev->next != tail) {
            prev = prev->next;
        }
        delete tail;
        tail = prev;
        tail->next = nullptr;
    }

    num_items--;
}

int SinglyList::front() const { //returns front/first node
    if (empty()) throw std::underflow_error("The list is empty");
    return head->data;
}

int SinglyList::back() const {  //returns last/back node
    if (empty()) throw std::underflow_error("The list is empty");
    return tail->data;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file