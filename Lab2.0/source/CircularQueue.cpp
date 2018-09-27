#include<cstring>
#include<iostream>
#include "CircularQueue.hpp"

using namespace std;

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
	
	 capacity_=16;
	 head_=0;
	 tail_=0;
	 size_=0;
	items_= new QueueItem [capacity_];
	
}

CircularQueue::CircularQueue(unsigned int capacity)
{
	 capacity_=capacity;
	 head_=0;
	 tail_=0;
	 size_=0;
	items_= new QueueItem [capacity_];
}

CircularQueue::~CircularQueue()
{
	head_=0;
	tail_=0;
	size_=0;
	capacity_=0;
	delete items_;
}

bool CircularQueue::empty() const
{    
	if (size_==0){
		return true;
		}
	else{ 
		return false;		
	}
}

bool CircularQueue::full() const
{
	if (size_==capacity_){
		return true;
	}
	else{
		return false;
	}
}

int CircularQueue::size() const
{  
	return size_;
}

bool CircularQueue::enqueue(QueueItem value)
{
	if(size_==capacity_){
		return false;
	}
	else{
		items_[tail_]=value;
		tail_=(tail_+1)%capacity_;
		size_++;
		return true;
	}
}

QueueItem CircularQueue::dequeue()
{
	if(size_==0){
		return EMPTY_QUEUE;
	}
	else{
		QueueItem temp=items_[head_];
		head_=(head_+1)%capacity_;
		size_--;
		return temp;
	}
}

QueueItem CircularQueue::peek() const
{
	if (size_==0){
		return EMPTY_QUEUE;
	}
	else{
		return items_[head_];
	}
}

void CircularQueue::print() const
{
	for(int i=head_;i<=head_+size_;i++){
		cout<<items_[i%size_]<<" ";
	}
	cout<<endl;
}
