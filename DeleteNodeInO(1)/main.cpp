//
//  main.cpp
//  DeleteNodeInO(1)
//
//  Created by chenyufeng on 8/8/16.
//  Copyright © 2016 chenyufeng. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 *  在O(1)时间删除链表节点
 给定单链表的头指针和一个节点指针，定义一个函数在O(1)时间删除该节点
 */

typedef struct ListNode{

    int element;
    struct ListNode *next;
}Node;

void CreateList(Node **pListHead);
void DeleteNode(Node **pListHead, Node *pToBeDeleted);
void PrintList(Node *pListHead);

int main(int argc, const char * argv[])
{
    Node *pHead;
    CreateList(&pHead);

    PrintList(pHead);

    DeleteNode(&pHead, pHead->next->next); // 删除第二个节点
    cout << "O(1)时间删除节点后的链表" << endl;
    PrintList(pHead);

    return 0;
}

void CreateList(Node **pListHead)
{
    cout << "请输入链表节点，输入<=0结束" << endl;

    // 头结点
    *pListHead = new Node;
    memset(*pListHead, 0, sizeof(Node));
    (*pListHead)->next = NULL;

    // 第一个节点
    Node *pNode = new Node;
    memset(pNode, 0, sizeof(Node));
    pNode->next = NULL;

    Node *pMove = *pListHead;
    cin >> pNode->element;
    while (pNode->element > 0)
    {
        pMove->next = pNode;
        pMove = pNode;

        pNode = new Node;
        memset(pNode, 0, sizeof(Node));
        pNode->next = NULL;

        cin >> pNode->element;
    }
}

void DeleteNode(Node **pListHead, Node *pToBeDeleted)
{
    pToBeDeleted->element = pToBeDeleted->next->element;
    delete pToBeDeleted->next;
    pToBeDeleted->next =  pToBeDeleted->next->next;
}

void PrintList(Node *pListHead)
{
    Node *pMove = pListHead->next;

    while (pMove != NULL)
    {
        cout << pMove->element << " ";
        pMove = pMove->next;
    }

    cout << endl;
}
