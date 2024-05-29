#include <iostream>
#include <fstream>
#include "linked_list.h"
using namespace std;	

int main() {
    ifstream read;
    read.open("DataStructure/LinkedList/input.txt");

	mrroot501::Node<int>* head=NULL;
  	mrroot501::LinkedList<int> mylist;
    int T,data;
    read >> T;
    while(T-->0){
        read >> data;
        head=mylist.insert(head,data);
    }	
	mylist.display(head);

    mrroot501::Node<int> *reverseNode = mylist.reverse(head);
    mylist.display(reverseNode);
    return 0;
}