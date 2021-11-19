// File : hashtable.h
#include<iostream>
#include<string>
using namespace std;


template<typename T>
class Node{
public:
	string key;
	T value;
	Node * next;

	Node(string key,T value){
		this->key = key;
		this->value = value;
		next = NULL;
	}
	~Node(){
		if(next!=NULL){
			delete next;
		}
	}

};

template<typename T>

class Hashtable{
   
   Node<T> ** table;
   int cs;
   int ts;

   int hashFn(string key){

   	int idx=0;
   	int power = 1;

   	for(auto ch:key){
   		idx=idx+ch*power;
   		power = (power*29)%ts;
   	}

   	return idx;
   }

void rehash(){
	// save the ptr to the oldtable and we will do insertion in the new table
	Node<T> **oldTable = table;

	int oldTs = ts;

	// increase the table size
	cs = 0;
	ts = 2*ts + 1;
	table = new Node<T>*[ts];

	for(int i=0; i<ts; i++){
		table[i] = NULL;
	}

	// /copy element from old table to new table 
	for(int i=0; i<oldTs; i++){
      
      Node<T> *temp = oldTable[i];

      while(temp!=NULL){
      	string key = temp->key;
      	T value = temp->value;
      	insert(key,value);
      	temp = temp->next;
      }

      // destroy the ith linkedlist
      if(oldTable[i]!=NULL){
      	delete oldTable;
      }

	}
	delete [] oldTable;
}
public:
	Hashtable(int default_size=7){
		cs = 0;
		ts = default_size;

		table = new Node<T>*[ts];

		for(int i=0; i<ts; i++){
			table[i] = NULL;
		}
	}

	void insert(string key,T val){
		// Next
		int idx = hashFn(key);

		Node<T>* n = new Node<T>(key,val);

		// insertion at head of the linkedlist
		n->next = table[idx];
		table[idx] = n;

		cs++;
		float load_facrtor = cs/float(ts);
		if(load_facrtor > 0.7){
			rehash();
		}

	}
  
  T* search(string key){
  	int idx = hashFn(key);

  	Node<T> *temp = table[idx];

  	while(temp!=NULL){
  		if(temp->key == key){

         }
         temp = temp->next;

  		}
  		return NULL;
  	
  }
  // Homework over buckets
  void erase(string key){
    // find the bucket id
    // iterate over the linked list
    

  }

  T& operator[](strng key){
        // return the value
        // if key is not found then create a new node return
        // return the existing node
        T* valueFound = search(key);
        if(valueFound==NULL){
            T object;
            insert(key,object);
            valueFound = search(key);

        }

        return **valueFound;
    }

void print(){
	// Iterator over buckets
	for(int i=0; i<ts; i++){
		cout<<"Bucket"<<i<<"->";

		Node<T> *temp = table[i];
		while(temp!=NULL){
			cout<< temp->key <<"->";
		}
		cout<<endl;
	}
}

};