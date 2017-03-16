#include "List.h"
#include <iostream>
#include <stdexcept>//used to be able to "throw" exceptions

using namespace std;


class List::Node //self-referential Node class
{
	public:
	   int data = 0;
	   Node* link = nullptr;
	   //link is a data member which is a pointer 
	   //to an object of the same type (i.e. Node)
	
};//end Node class definition (can only be seen by the List class)


List::~List()
{
    while(num_elements > 0)
      remove(1);
}
	
int List::size()
 {
    return num_elements;
 }

void List::insert(int val, int k)
{
	if (k < 1 or k > num_elements +1) //if the location is invalid
	     throw out_of_range("List::insert(...)");//throw an "out_of_range" exception
	
	
	Node* newPtr = new Node{val};
	
	if(k == 1)
	{
	  newPtr->link = frontPtr;
	  frontPtr = newPtr;
	}
	else
	{  
		Node* tmpPtr = frontPtr;
		for (int i=1; i<k-1; ++i)
			tmpPtr = tmpPtr->link;
	
		newPtr->link = tmpPtr->link;
		tmpPtr->link = newPtr;  
    }
    num_elements++;
 }

void List::remove(int k)
{
	if (k < 1 or k > num_elements)//if the location is invalid 
	     throw out_of_range("List::remove(...)");//throw an "out_of_range" exception
	
	Node* delPtr = frontPtr;
	
	if(k == 1)
	  frontPtr = frontPtr->link;
	  
	 else
	 {
	    Node* tmpPtr = frontPtr;
        for (int i=1; i<k-1; ++i)
	       tmpPtr = tmpPtr->link;
	
	    delPtr = tmpPtr->link;
	    tmpPtr->link = delPtr->link;
	 }
	delete delPtr;
	num_elements--;
}

int List::get(int k)
{
	if (k < 1 or k > num_elements)//if the location is invalid 
	     throw out_of_range("List::get(...)");
	     
	Node* iPtr = frontPtr;
	for (int i = 1; i<k; ++i)
		iPtr = iPtr->link;
		
	return iPtr->data;
}
	
void List::display()
{
	for (Node* curPtr=frontPtr; curPtr!=nullptr; curPtr=curPtr->link)
		cout << curPtr->data << " ";
}

void List::clear()
{//clears list, removes every element
    while (num_elements != 0)
        {
            remove(1);
            num_elements--;
        }
}
	
//Implementations of missing operations
