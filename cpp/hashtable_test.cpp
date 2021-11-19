#include<iostream>
#include "hashtable.h"
using namespace std;


int main(){
 
    Hashtable<int> h;
    h.insert("Mango",100);
    h.insert("Apple",120);
    h.insert("banana",140);
    h.insert("orange",110);
   
    h.print();

    string fruit;
    cin>>fruit;
    
    int *price = h.search(fruit);
    if(price!=NULL){
    	cout<< "Price of fruit is "<< *price <<endl;
    }else{
    	cout<<"Fruit is not present";
    }

    // supercool functionlity

    h["newFruit"] = 200;
    cout<<"New fruit cost: "<<h["newFruit"]<<endl;
    h["newFruit"] += 20;

    cout<<"New fruit updated cost: "<<h["newFruit"]<<endl;

	return 0;
}