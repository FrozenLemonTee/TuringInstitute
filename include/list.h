//
// Created by Lenovo on 25-3-5.
//

#ifndef TURINGINSTITUTE_LIST_H
#define TURINGINSTITUTE_LIST_H

typedef struct Node{
    int val; //当前节点存储的值
    struct Node* next; //下一个节点
}Node;
typedef Node *List; // List表示头结点, List->next是第一个存储数据的节点

/*
功能: 创建一个链表
参数: void
返回值: 返回一个新的空链表
*/
List createList();
/*
功能: 新建一个节点, 放到链表头(放到List的next)
参数:
List: 链表
val: 新节点的值
返回值: void
*/
void addAtHead(List list, int val);
/*
功能: 新建一个节点, 放到链表的尾节点 (原本的尾节点成为倒数第二个节点)
参数:
List: 链表
val: 新节点的值
返回值: void
*/
void addAtTail(List list, int val);
/*
功能: 新建一个节点, 放到链表的第index个节点处 (原本的第index个节点成为第index+1个节点)
参数:
List: 链表
index: 新节点的位置
val: 新节点的值
返回值: void
*/
void addAtIndex(List list,int index, int val);
/*
功能: 删除第index个节点(原本的第index+1个节点成为第index个节点)
参数:
List: 链表
int: 被删除的节点
返回值: void
*/
void deleteAtIndex(List list, int index);

// 辅助函数，删除链表头部节点
void deleteAtHead(List list);

// 辅助函数，删除链表尾部节点
void deleteAtTail(List list);

/*
功能: 打印这条链表
参数: void
返回值: void
*/
void SListPrint(List list);

// 辅助函数，根据索引找到对应节点
List findNode(List list, int index);

// 辅助函数，返回链表长度
int sizeList(List list);

// 辅助函数，连接两个链表
void connectList(List list1, List list2);

// 辅助函数，删除整个链表
void destroyList(List list);

#endif //TURINGINSTITUTE_LIST_H
