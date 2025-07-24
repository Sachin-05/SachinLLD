#include <bits/stdc++.h>
using namespace std;

// so we are planning the game here for the transportation
// so if we don't have to touch the main service class and have ot add multiple new objects so we can use this design pattern

class Animal{
public:
	virtual void makesound() = 0;
	virtual ~Animal() {};
};

class Dog : public Animal{
	public:
	 void makesound() override{
		cout << "Bark\n";
	}
};

class Lion : public Animal{
	public:
		void makesound() override{
		cout << "Roar\n";	
	}
};

int main(){
	Animal* a = new Dog();
	a->makesound();
	delete a;   // to save on the memory leaks
	return 0;
};
