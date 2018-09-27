// .cpp files contain code definitions for methods that have been declared
// in the according .hpp file. The skeleton has been set up here for you.
// That is, the methods have been initiated, and your mission, should you 
// choose to accept it (which you should for marks), is to fill in each method
// with the appropriate code.
//
// A note about the "::" syntax: generally, this means "the thing on the right
// belongs to the thing on the left." So, SequentialList::empty() means the method
// empty() belongs to the class SequentialList. This allows empty() to access (and
// potentially change) the member variables in class SequentialList.

#include "SequentialList.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std; 
// This is the constructor.
SequentialList::SequentialList(unsigned int cap)
{
        data_= new DataType [cap];
	    capacity_=cap;
	    size_=0;
}

SequentialList::~SequentialList()
{
        delete(data_);
	    capacity_=0;
	    size_=0;
}

bool SequentialList::empty() const
{
      if (size_==0){
        return true;
    }
    return false;
}

unsigned int SequentialList::size() const
{
         return size_; 
}

unsigned int SequentialList::capacity() const
{
         	return capacity_;
}

bool SequentialList::full() const
{
     if (size_>=capacity_){
        return true;
    }
    else{
    	 return false;
	}
   
}

void SequentialList::print() const
{
     for (int x=0;x<size_;++x){
        std::cout<<data_[x];
    }
}

// NOTE on inserts: do NOT grow the array if we reach capacity. Simply return false.
bool SequentialList::insert_front(DataType val)
{
     return insert(val,0);
}

bool SequentialList::remove_front()
{
     return remove(0);
}

bool SequentialList::insert_back(DataType val)
{
    if (size_==capacity_){
    	return false;
	}
	
	size_++;
	data_[size_-1]=val;
	
	 return true; 
}

bool SequentialList::remove_back()
{
     	if(size_==0){
     		return false;
		 }
		 else{
		 	size_--;
		 	return true;
		 	
		 }
}

bool SequentialList::insert(DataType val, unsigned int index)
{
     	if (size_ >= capacity_ || index >= capacity_ || index > size_){
				return false;
		}
		else if (size_==0){
			data_[0]=val;
			++size_;
			return true;
		}
		else{
			for (int x=size_-1;x>index;x--){
				data_[x+1]=data_[x];
			}
			data_[index]=val;
				++size_;
				return true;
		}
}

bool SequentialList::remove(unsigned int index)
{
     if (size_==0 ||index>=size_){
		return false;
	}
	else{
		for (int x=index+1;x<size_;x++){
			data_[x-1]=data_[x];
		}
		size_--;
		return true;
	}
}

unsigned int SequentialList::search(DataType val) const
{
       for (int x=0;x<size_;x++){
		if (data_[x]==val){
			return x;
		}
	}
	 return size_;
	
	
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
        if (index>0 && index<size_){
			return data_[index];
		}
		
}

bool SequentialList::replace(unsigned int index, DataType val)
{
     if (index>0 && index<size_){
		data_[index]=val;
		return true;
	}
	else{
		return false;
	}
}
