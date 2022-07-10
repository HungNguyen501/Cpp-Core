#include <iostream>
#include <fstream>
using namespace std;	

class Node {
    public:
    int data;
    Node *next;

    Node(int d)
    {
        data=d;
        next=NULL;
    }
};

class Solution {
    public:

    Node* insert(Node *head,int data)
    {
        if (head == NULL) {
            return new Node(data);
        } else {
            Node *cur = insert(head->next, data);
            head->next = cur;
            return head;
        }
    }

    Node* reverse(Node* node) {
        Node* cur = node;
        Node* prev = NULL;

        while(cur) {
            Node* nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }

        return prev;
    }

    void del(Node *head, int data) {
        if (head->data == data) {
            head = head->next;
            return;
        }

        Node *r = head->next;
        Node *last_node = head;

        while (r) {
            if (r->data == data) {
                last_node->next = r->next;
                r = nullptr;
                return;
            }
            last_node = r;
            r = r->next;
        }

    }

    void display(Node *head)
    {
        Node *start=head;
        while(start)
        {
            cout<<start->data<<" ";
            start=start->next;
        }
        cout << endl;
    }
};

int main() {
    ifstream read;
    read.open("CPP\\Data Structure and Algorithms\\Linked List\\input.txt");

	Node* head=NULL;
  	Solution mylist;
    int T,data;
    read >> T;
    while(T-->0){
        read >> data;
        head=mylist.insert(head,data);
    }	
	mylist.display(head);

    Node* reverseNode = mylist.reverse(head);
    mylist.display(reverseNode);
	
    system("pause");
    return 0;
}