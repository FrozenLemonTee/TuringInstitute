//
// Created by Lenovo on 25-3-5.
//
#include "list.h"
#include <gtest/gtest.h>

// 测试创建链表
TEST(ListTest, CreateList) {
List list = createList();
EXPECT_EQ(sizeList(list), 0);
destroyList(list);
}

// 测试头插入
TEST(ListTest, AddAtHead) {
List list = createList();
addAtHead(list, 10);
EXPECT_EQ(sizeList(list), 1);
EXPECT_EQ(findNode(list, 0)->val, 10);
addAtHead(list, 20);
EXPECT_EQ(sizeList(list), 2);
EXPECT_EQ(findNode(list, 0)->val, 20);
destroyList(list);
}

// 测试尾插入
TEST(ListTest, AddAtTail) {
List list = createList();
addAtTail(list, 10);
addAtTail(list, 20);
EXPECT_EQ(sizeList(list), 2);
EXPECT_EQ(findNode(list, 0)->val, 10);
EXPECT_EQ(findNode(list, 1)->val, 20);
destroyList(list);
}

// 测试索引插入
TEST(ListTest, AddAtIndex) {
List list = createList();
addAtTail(list, 10);
addAtTail(list, 30);
addAtIndex(list, 1, 20);
EXPECT_EQ(sizeList(list), 3);
EXPECT_EQ(findNode(list, 0)->val, 10);
EXPECT_EQ(findNode(list, 1)->val, 20);
EXPECT_EQ(findNode(list, 2)->val, 30);
destroyList(list);
}

// 测试删除节点
TEST(ListTest, DeleteAtIndex) {
List list = createList();
addAtTail(list, 10);
addAtTail(list, 20);
addAtTail(list, 30);
deleteAtIndex(list, 1);
EXPECT_EQ(sizeList(list), 2);
EXPECT_EQ(findNode(list, 0)->val, 10);
EXPECT_EQ(findNode(list, 1)->val, 30);
destroyList(list);
}

// 测试删除头节点
TEST(ListTest, DeleteAtHead) {
List list = createList();
addAtHead(list, 10);
addAtHead(list, 20);
deleteAtHead(list);
EXPECT_EQ(sizeList(list), 1);
EXPECT_EQ(findNode(list, 0)->val, 10);
destroyList(list);
}

// 测试删除尾节点
TEST(ListTest, DeleteAtTail) {
List list = createList();
addAtTail(list, 10);
addAtTail(list, 20);
deleteAtTail(list);
EXPECT_EQ(sizeList(list), 1);
EXPECT_EQ(findNode(list, 0)->val, 10);
destroyList(list);
}

// 测试连接链表
TEST(ListTest, ConnectList) {
List list1 = createList();
List list2 = createList();
addAtTail(list1, 10);
addAtTail(list2, 20);
connectList(findNode(list1, 0), findNode(list2, 0));
EXPECT_EQ(findNode(list1, 1)->val, 20);
destroyList(list1);
destroyList(list2);
}