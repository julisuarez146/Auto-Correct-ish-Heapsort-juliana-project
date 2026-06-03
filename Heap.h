// The heap data structure itself insertion, extraction, and internal reordering.
// It should not know about names, files, or UI.
// Created by Juliana Suarez


#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <stdexcept>

template <typename T, typename Comparator>
class Heap {
private:
    //store heap in a vector - binary tree
    std::vector<T> data;
    Comparator compare; // priority

    //moves an item upward, after every time a new element is inserted
    void siftUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2; //parent index

            if (!compare(data[index], data[parent]))
                break;

            std::swap(data[index], data[parent]);
            //check parent
            index = parent;
        }
    }

    //moves an item downward, after removing the top element.
    void siftDown(int index) {
        int size = data.size();

        while (true) {
            int left = 2 * index + 1; //left child index
            int right = 2 * index + 2; //right child index
            int betterO = index; //priority index

            //left has higher priority it would be the better option
            if (left < size && compare(data[left], data[betterO]))
                betterO = left;
            //right has higher priority it would be the better option
            if (right < size && compare(data[right], data[betterO]))
                betterO = right;
            //if the current element its better than the l and r children, heap restored
            if (betterO == index)
                break;

            std::swap(data[index], data[betterO]); //better children upward
            index = betterO; //continue check
        }
    }

public:
    //insert element into the heap
    void insert(const T& item) {
        data.push_back(item);
        siftUp(data.size() - 1);
    }

    //remove, return highest priority element
    T extractTop() {
        if (data.empty())
            throw std::runtime_error("Heap is empty");

        T top = data[0]; //index 0
        data[0] = data.back(); //move last to the root
        data.pop_back();

        //restore heap after remove root
        if (!data.empty())
            siftDown(0);

        return top;
    }

    //return true if heap dont have element
    bool empty() const {
        return data.empty();
    }

    //return number of elements in heap
    int size() const {
        return data.size();
    }
};
#endif //HEAP_H
