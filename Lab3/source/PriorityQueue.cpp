#include "PriorityQueue.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;
typedef int DataType;

// Implement the functions here.


PriorityQueue::PriorityQueue (unsigned int capacity)
{
	capacity_=capacity;
	size_=0;
	heap_=new DataType(capacity_+1);
}

PriorityQueue::~PriorityQueue(){
	delete heap_;
}

bool PriorityQueue::empty() const{
	if (size_==0){
		return true;
	}
		return false;
	
}

unsigned int PriorityQueue::size() const{
	return size_;
}

bool PriorityQueue::full() const{
	if (size_==capacity_){
		return true;
	}
	else{
		return false;
	}
}

void PriorityQueue::print() const{
	//starts at 1
	for(int x=1; x<=size_; x++){
		cout<<heap_[x]<<" ";
	}
	cout<<endl;
}

DataType PriorityQueue::max() const{
	return heap_ [1];
}

bool PriorityQueue::enqueue(DataType val){


	
	if(full())
	{
		return false;
		}
	else if (size_==0){
		heap_[1]=val;
		size_++;
		return true;
	}
	else{
		heap_[size_+1]=val;
		int current=size_+1;
		int parent=(size_+1)/2;
		int temp;
		while(heap_[current]>heap_[parent] && heap_[1]!=val){
			temp=heap_[current];
			heap_[current]=heap_[parent];
			heap_[parent]=temp;
			current=parent;
			parent=current/2;
		}
		size_++;
		return true;
		
	}
}

bool PriorityQueue::dequeue()
{
	if (size_==0){
		return false;
	}
	else{
		int current=1;
		int temp;
		heap_[1]=heap_[size_];
		
		while((heap_[current]<heap_[2*current]||heap_[current]<heap_[2*current+1] ) &&current<size_-1){
			
			if (heap_[2*current]>heap_[2*current+1]){
				if (heap_[current]<heap_[current*2]){
					temp=heap_[current];
					heap_[current]=heap_[current*2];
					heap_[current*2]=temp;
					current=current*2;
				}
			}
			else{
					if (heap_[current]<heap_[current*2+1]){
					temp=heap_[current];
					heap_[current]=heap_[current*2+1];
					heap_[current*2+1]=temp;
					current=current*2+1;
				}
				
			}
		}
		size_--;
		return true;
		
	}
}
