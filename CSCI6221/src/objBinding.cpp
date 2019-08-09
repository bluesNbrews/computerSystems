/*  Author: Mark Williams
**  Class: CSCI 6221
**  Assignment: Opt-OOP
*/


#include <iostream>
using namespace std;

class A {
	
	public:

		string className;

		A(){

			className = "Class A";

		}

		virtual void printName(){

			cout << "Class Name is: " << className << endl;

		}

};


class B : public A {
	
	public:

		string className;

		B(){

			className = "Class B";

		}

		void printName(){

			cout << "Class Name is: " << className << endl;

		}

};

class C : public B {
	
	public:

		string className;

		C(){

			className = "Class C";

		}

		void printName(){

			cout << "Class Name is: " << className << endl;

		}

};

class T {

	public:

		//Pointer to A and objects of B an C, respectively
		A* testA = new A;
		B testB;
		C testC;

		void printName(){

			//Static binding of A's method
			testA->printName();

			//Dynamic binding of B's method to A
			testA = &testB;
			testA->printName();

			//Dynamic binding of C's method to A
			testA = &testC;
			testA->printName();
			
		}

};


int main () {
	
	//Use object testT of class T 
	T testT; 
	testT.printName();

	return 0; 
}