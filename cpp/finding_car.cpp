#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

class Car{

public:
	string id;
	int x,y;
	Car(string id,int x,int y){
		this->id = id;
		this->x = x;
		this->y = y;

	}
	int dist() const{
		return x*x + y*y; 
	}
};

class Carcompare{
public:
	bool operator()(const Car A,const Car B){
		return A.dist() < B.dist();

	}
};

void printNearestCar(vector<Car> cars,int k){

// create a max heap of size K
	priority_queue<Car, vector<Car> , Carcompare> max_heap(cars.begin(),cars.begin() + k);

   // remaining cars
	for(int i=k; i<cars.size(); i++){
		auto car = cars[i];

		if(car.dist() < max_heap.top().dist()){
			max_heap.pop();
			max_heap.push(car);
		}
	}
	// print all the cars inside the heap they will be smallest
	vector<int> output;

	while(!max_heap.empty()){
		// cout<< max_heap.top().id <<endl;
		output.push_back(max_heap.top());
        max_heap.pop();
	}
	// vector of k nearest cars
	reverse(output.begin(),output.end());

	for(auto car : output){
		cout<< car.id << endl;
	}
	return;

}


int main(){

	int N,K;
	cin>>N>>K;

	string id;
	int x,y;
 
    vector<Car> cars;

    for(int i=0; i<N; i++){
    	cin>>id>>x>>y;
    	Car car(id,x,y);
    	cars.push_back(car);
    }
    printNearestCar(cars,K);

    return 0;

}