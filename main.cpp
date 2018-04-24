#include <iostream>
#include <cassert>
using namespace std;

#include "CircularInt.hpp"

void test1() {
  CircularInt hour1 {2, 12};
  assert(hour1==2);
  assert((hour1+= 4)==6);
  assert((hour1-=6)==11); // 6-4=2 , 2-1=12 , 12-1=11; 
}

void test2() {
	CircularInt hour2 {3, 7};
	CircularInt hour3 {1, 9};
	assert((hour2*=2)==6);
	assert((hour3-=2)==8);
	assert(hour2<hour3);
} 

void test3() {
	CircularInt hour4 {-2, 10};
	assert((-hour4) == -1);
}
void test4(){
	CircularInt hour5 {-10,-1};
	assert((-hour5) == -1);
}

int main() {
	CircularInt hour {1, 12};                 // <hour is an integer between 1 and 12, like an hour on the clock>
	cout << hour << endl;                     // 1
	hour += 4;  cout << hour << endl;         // 5
	(hour += 2)++;  cout << hour << endl;     // 8
	hour += 18;   cout << hour << endl;       // 2   (18 hours after 8)
    cout << -hour << endl;                    // 10  (2 hours before midnight)
	hour = 1 - hour; cout << hour.cur << endl;    // 11  (2 hours before 1)
	cout << hour+hour << endl;                // 10 (11 hours after 11)
	hour *= 2;   cout << hour << endl;        // 10 (11*2 = 11+11)
	cout << hour/2 << endl;                   // TWO OPTIONS: 11 (since 11*2=10) or 5 (since 5*2=10 too).
	try {
		cout << hour/3;
	} catch (const string& message) {
		cout << message << endl;     // "There is no number x in {1,12} such that x*3=10"
	}
	test1();
	test2();
	test3();
	test4();
	
	// RIDDLES (not for submission): 
	//  * when is there exactly one answer to a/b?
	//  * when are there two or more answers to a/b?
	//	* when is there no answer to a/b?
}
