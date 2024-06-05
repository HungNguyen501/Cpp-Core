#include <iostream>
#include <fstream>
#include "linked_list.h"
using namespace std;	

int main() {
    int input[] = {4, 2, 3, 4, 1};
    int tc = 0;
    int n = input[tc++];
  	mrroot501::LinkedList<int> mylist(mrroot501::Node<int>(10));
    while(n-- > 0){
        mrroot501::Node<int> node(input[tc++]);
        mylist.append(node);
    }	
	// mylist.show();

    // mrroot501::Node<int> *reverseNode = mylist.reverse(head);
    // mylist.display(reverseNode);
    return 0;
}