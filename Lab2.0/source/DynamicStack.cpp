#include "DynamicStack.hpp"
#include <iostream>

using namespace std;

typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
	
	size_=0;
	init_capacity_=16;
	capacity_=init_capacity_;
	items_= new StackItem [capacity_];
	for (int x=0;x<capacity_;x++){
		items_[x]=0;
	}
	
	
}

DynamicStack::DynamicStack(unsigned int capacity)
{
	
	size_=0;
	if (capacity==0){
		init_capacity_=16;
	}
	else{
		init_capacity_=capacity;
	}
	capacity_=init_capacity_;
	items_= new StackItem [capacity_];
	for (int x=0;x<capacity_;x++){
		items_[x]=0;
	}
	
}

DynamicStack::~DynamicStack()
{
	size_=0;
	capacity_=0;
	init_capacity_=0;
	delete items_;
}

bool DynamicStack::empty() const
{
	if (size_==0){
		return true;
	}
	else{
		return false;	
	}

}

int DynamicStack::size() const
{
	return size_;
}

void DynamicStack::push(StackItem value)
{
	if (capacity_==size_){
		StackItem* array=new StackItem [capacity_*2];
		for (int x=0;x<capacity_;x++){
			array[x]=items_[x];
		}		
		delete items_;
		items_=array;
		capacity_=capacity_*2;
	}
	items_[size_]=value;
	size_++;
	
	
}

StackItem DynamicStack::pop()
{
	if(size_==0){
		return EMPTY_STACK;
	}
	else{
		
		
		
		if(size_<=capacity_/4){
			if (capacity_/2>=init_capacity_){
				StackItem* array=new StackItem [capacity_*2];
				for (int x=0;x<capacity_;x++){
				array[x]=items_[x];
						}		
				delete items_;
				items_=array;
				capacity_=capacity_/2;
			}
		}
		size_--;
		return items_[size_];
	}
}

StackItem DynamicStack::peek() const
{
	if(size_==0){
		return EMPTY_STACK;
	}
	return items_[size_-1];
}

void DynamicStack::print() const
{
	for(int i=size_-1;i>=0;i--){
		cout<<items_[i]<<" ";
	}
	cout<<endl;
}
