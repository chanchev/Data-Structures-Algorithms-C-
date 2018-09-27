#include "DoublyLinkedList.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

DoublyLinkedList::Node::Node(DataType data)
{
	value = data;
	next = NULL;
	prev = NULL;
	
}

DoublyLinkedList::DoublyLinkedList()
{
	head_=NULL;
	tail_=NULL;
	size_=0;
}

DoublyLinkedList::~DoublyLinkedList()
{

	Node* current=head_;
	Node* previous=head_;
	while(current != NULL ){
		previous=current;
		current= current->next;
		delete(previous);
	}
	delete(current);
	
	head_=NULL;
	tail_=NULL;
	size_=0;
	
}

bool DoublyLinkedList::empty() const
{
	if (size_==0){
		return true;
	}
	else{
		return false;
	}
}

unsigned int DoublyLinkedList::size() const
{
	return size_;
}

void DoublyLinkedList::print() const
{
	Node* current=head_;
	
	if (size_==0){
		return;
	}
	cout << "(";
	while (current!=NULL){
		cout << "[" << current->value << "]";
		current =current->next;
		if (current!=NULL){
			cout<< "->";
		}
		cout << ")\n";
	}

}

bool DoublyLinkedList::insert_front(DataType value)
{
	insert(value,0);
}

bool DoublyLinkedList::remove_front()
{
	remove(0);
}

bool DoublyLinkedList::insert_back(DataType value)
{
	insert(value, size_);
}

bool DoublyLinkedList::remove_back()
{
	remove(size_-1);
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
	Node* newNode= new Node(value);
	
	if (size_==CAPACITY || index>size_){
		return false;
	}
	else if(size_==0){
		head_=newNode;
		tail_=newNode;
		
	}
	else if (index==0 && size_!=0){
		Node* current=head_;
		head_=newNode;		
		current->prev=newNode;
		newNode->next=current;
		newNode->prev=NULL;
	}
	else if (index==size_){
		Node*current = tail_;
		tail_=newNode;
		current->next=newNode;
		newNode->prev=current;
		newNode->next=NULL;
	
	}
	else{
		Node* before= getNode(index-1);
		Node* after= getNode(index);
		before->next=newNode;
		newNode->prev=before;
		newNode->next=after;
		after->prev=newNode;
	}
	size_++;
	return true;
}

bool DoublyLinkedList::remove(unsigned int index)
{
	if (size_==0 || index>size_){
		return false;
	}
	else if (size_==1){
		Node* current= head_;
		delete current;
		head_=NULL;
		tail_=NULL;
		
		size_--;
		return true;
	}
	else if (index==0 && size_!=1){
		Node* current= getNode(0);
		Node* after = getNode(1);
		head_=after;
		current->next=NULL;
		after->prev=NULL;
		delete current;
		size_--;
		return true;
	}
	else if (index==size_-1){
		Node* current=getNode(index);
		Node* before= getNode(index-1);
		tail_=before;
		before->next=NULL;
		current->prev=NULL;
		delete current;
		size_--;
		return true;
		
	}
	else{
		Node* current= getNode(index);
		Node* before= getNode(index-1);
		Node* after= getNode(index+1);
		
		before->next=after;
		after->prev=before;
		current->prev=NULL;
		current->next=NULL;
		delete current;
		size_--;
		return true;
			
	}
	


}

unsigned int DoublyLinkedList::search(DataType value) const
{
	Node* current=head_;
	int x=0;
	
	while(current !=NULL){
		if (current->value==value){
			return x;
		}
		current=current->next;
		x++;
	}
	return size_;
	
	
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
	if (index>=size_){
		return size_;
	}
	else{
		Node* current = getNode(index);
		return current->value;	
	}
	
	
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
	Node* current= getNode(index);
	current->value=value;
	return true;
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
	Node* current= head_;
	
	for (int x=0; x<index;x++){
		current=current->next;
	}
	return current;
	
}
bool DoublyLinkedList::full() const
{
	if (size_== CAPACITY){
		return true;
	}
	else{
		return false;
	}
}
