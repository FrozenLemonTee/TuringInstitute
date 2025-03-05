//
// Created by Lenovo on 25-3-5.
//
#include "list.h"
#include "iostream"

void SListPrint(List list) {
    List cur = findNode(list, 0);
    std::cout << "List(";
    while (cur){
        if (cur != list)
            std::cout << ", ";
        std::cout << cur->val;
        cur = cur->next;
    }
    std::cout << ")";
}

void addAtIndex(List list, int index, int val) {
    if (index == 0){
        addAtHead(list, val);
    } else if (index >= sizeList(list)){
        addAtTail(list, val);
    } else{
        List cur = findNode(list, index - 1);
        List next = cur->next;
        List new_node = new Node{val, nullptr};
        connectList(cur, new_node);
        connectList(new_node, next);
    }
}

void deleteAtIndex(List list, int index) {
    if (index == 0)
        return deleteAtHead(list);
    if (index >= sizeList(list))
        return deleteAtTail(list);
    List cur = findNode(list, index - 1);
    List new_next = cur->next->next;
    delete cur->next;
    connectList(cur, new_next);
}

void addAtTail(List list, int val) {
    if (sizeList(list) == 0){
        connectList(list, new Node{val, nullptr});
    } else{
        List cur = findNode(list, sizeList(list) - 1);
        connectList(cur, new Node{val, nullptr});
    }
}

void addAtHead(List list, int val) {
    if (sizeList(list) == 0){
        connectList(list, new Node{val, nullptr});
    } else{
        List cur = findNode(list, 0);
        List new_head = new Node{val, nullptr};
        connectList(list, new_head);
        connectList(new_head, cur);
    }
}

List createList() {
    return new Node{0, nullptr};
}

List findNode(List list, int index) {
    List cur = list->next;
    for (int i = 0; i < index && cur; ++i, cur = cur->next);
    return cur;
}

int sizeList(List list) {
    List cur = list->next;
    int size = 0;
    for (; cur; cur = cur->next, ++size);
    return size;
}

void connectList(List list1, List list2) {
    if (list1) list1->next = list2;
}

void deleteAtHead(List list) {
    if (sizeList(list) == 0)
        return;
    if (sizeList(list) == 1){
        delete list->next;
        connectList(list, nullptr);
        return;
    }
    List new_head = findNode(list, 1);
    delete findNode(list, 0);
    connectList(list, new_head);
}

void deleteAtTail(List list) {
    if (sizeList(list) == 0)
        return;
    if (sizeList(list) == 1){
        delete list->next;
        connectList(list, nullptr);
        return;
    }
    List new_tail = findNode(list, sizeList(list) - 2);
    delete new_tail->next;
    connectList(new_tail, nullptr);
}

void destroyList(List list) {
    while (list->next) {
        deleteAtHead(list);
    }
    delete list;
}