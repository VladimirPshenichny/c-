#pragma once
#include <iostream>
#include <locale.h>
#include <math.h>
#include <conio.h>
#include <string>

class stack {
private:
    class Node {
    private:
        int value;
        char sign;
        Node* next;

    public:
        explicit Node(int value, char sign) {
            this->value = value;
            this->sign = sign;
            this->next = nullptr;
        }

        Node(int value, char sign, Node* next) {
            this->value = value;
            this->sign = sign;
            this->next = next;
        }

        Node* getNext() const {
            return next;
        }
        
        int getValue() const {
            return value;
        }
        char getSign() const {
            return sign;
        }
    };

    Node* head = nullptr;
    int size = 0;

public:
    void push(int value, char sign) {
        if (head == nullptr) {
            head = new Node(value, sign);
        }
        else {
            head = new Node(value, sign, head);
        }
        size++;
    }

    void pop() {
        if (head == nullptr) {
        }
        else {
            Node* previous_head = head;
            head = head->getNext();

            free(previous_head);
            size--;
        }
    }

    char getHead() {
        if (size == 0) {
            return 0;
        }
        else {
            return head->getSign();
        }
    }

    int getValue() {
        if (size == 0) {
            return 0;
        }
        else {
            return head->getValue();
        }
    }
};