#include <vector>

template<typename E>
class MyArrayStack {
private:
    std::vector<E> arr;

public:
    void push(const E& e) {
        arr.push_back(e);
    }

    E pop() {
        E topElement = arr.back();
        arr.pop_back();
        return topElement;
    }

    E peek() const {
        return arr.back();
    }

    int size() const {
        return arr.size();
    }
};