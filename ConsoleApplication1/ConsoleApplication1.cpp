// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

struct Node {
    int data;
    Node *next;
} *head, *tail, *LinkListHead, *LinkListTail;
//创建单链表,头插法法
Node *CreateLinkListByHead(int n) {
    Node *p;
    LinkListHead = new Node;
    LinkListHead->next = NULL;
    head = LinkListHead;
    for (auto i = 0; i < n; i++) {
        p = new Node;
        p->data = i;
        p->next = LinkListHead->next;
        LinkListHead->next = p;
    }
    std::cout << "头插法创建的单链表" << std::endl;
    return head;
}
//创建单链表，尾插法
Node *CreateLinkListByTail(int n) {
    Node *p;
    LinkListTail = new Node;
    LinkListTail->next = NULL;
    tail = LinkListTail;
    Node *temp = LinkListTail;
    for (auto i = 0; i < n; i++) {
        p = new Node;
        p->data = i;
        temp->next = p;
        temp = p;
    }
    temp->next = NULL;
    std::cout << "尾插法创建的单链表" << std::endl;
    return tail;
}
//遍历链表
void ForeachLinkList(Node *head)
{
    Node *p = head->next;
    while (p != NULL)
    {
        std::cout << p->data << "  ";
        p = p->next;
    }
    std::cout << "遍历完成";
    std::cout << "\n";
}
void DeleteLinkList(Node *head) {
    Node *p = head->next;
    Node *temp;
    while (p) {
        temp = p->next;
        delete p;
        p = temp;
    }
    head->next = NULL;
}
int main()
{
    Node *LinkListHead = CreateLinkListByHead(10);
    ForeachLinkList(LinkListHead);
    Node *LinkListTail = CreateLinkListByTail(10);
    ForeachLinkList(LinkListTail);

    DeleteLinkList(LinkListHead);
    std::cout << "执行删除操作之后遍历链表" << std::endl;
    ForeachLinkList(LinkListHead);
    return 0;
}

