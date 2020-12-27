#include <bits/stdc++.h>
using namespace std;
class LinkedList;    // ���F�Nclass LinkedList�]��class ListNode��friend,
                     // �ݭn���ŧi
class ListNode{
private:
    int data;
    ListNode *next;
public:
    ListNode():data(0),next(0){};
    ListNode(int a):data(a),next(0){};

    friend class LinkedList;
};

class LinkedList{
private:
    // int size;                // size�O�ΨӰO��Linked list������, �D���n
    ListNode *first;            // list���Ĥ@��node
public:
    LinkedList():first(0){};
    void PrintList();           // �L�Xlist���Ҧ����
    void Push_front(int x);     // �blist���}�Y�s�Wnode
    void Push_back(int x);      // �blist�����ڷs�Wnode
    void Delete(int x);         // �R��list���� int x
    void Clear();               // ����list�R��
    void Reverse();             // �Nlist����: 7->3->14 => 14->3->7
};