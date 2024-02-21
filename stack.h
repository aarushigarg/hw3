#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private vector<T>
{
public:
    Stack() {}
    ~Stack() {}
    bool empty() const {
        return vector<T>::empty();
    }
    size_t size() const {
        return vector<T>::size();
    }
    void push(const T& item) {
        vector<T>::push_back(item);
    }
    void pop() { // throws std::underflow_error if empty
        if (vector<T>::empty()) {
            throw underflow_error("Stack is empty");
        }
        vector<T>::pop_back();
    }
    const T& top() const { // throws std::underflow_error if empty
        if (vector<T>::empty()) {
            throw underflow_error("Stack is empty");
        }
        return vector<T>::back();
    }
    // Add other members only if necessary
};


#endif