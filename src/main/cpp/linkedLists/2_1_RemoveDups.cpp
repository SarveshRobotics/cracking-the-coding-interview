#include "LinkedList.h"

int main(){
	LinkedList ll;

	// Make a linked list
	ll.insert(5);
	ll.insert(9);
	ll.insert(5);
	ll.insert(6);

	ll.printLL();

	ll.removeDuplicates();

	ll.printLL();
}