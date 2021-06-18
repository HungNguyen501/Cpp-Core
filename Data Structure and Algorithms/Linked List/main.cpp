#include <iostream>
#include <fstream>
using namespace std;	

class Node
{
    public:
        int data;
        Node *next;
        Node(int d){
            data=d;
            next=NULL;
        }
};

class Solution{
    public:

      Node* insert(Node *head,int data)
      {
          //Complete this method
          if (head == NULL) {
              return new Node(data);
          } else {
              Node *cur = insert(head->next, data);
              head->next = cur;
              return head;
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

int main()
{
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
	
    system("pause");
    return 0;
}