#include "CircularInt.hpp"
#include <iostream>
#include <string>
using namespace std;

CircularInt:: CircularInt(int s, int e){ //constructor
    if(e>s){
        start = s;  
        end = e;
        cur = start;
    
    }
}

void CircularInt::norm(){
    int y = end-start+1;
    if(cur>= start && cur<= end){
        return;
    }
    while(cur < start) cur += y;
    while(cur > end) cur -= y;
}

//----------------------------------
// operator ?=
//----------------------------------
CircularInt& CircularInt::operator=(int num){

        cur=num;
        norm();
    
        return *this;
}

CircularInt& CircularInt::operator+=(int num){
    cur += num;
    norm();
        return *this;
}

CircularInt& CircularInt::operator-=(int num){
    cur -= num;
    norm();
        return *this;
}

CircularInt& CircularInt::operator*=(int num){
    cur *= num;
    norm();
        return *this;
}

CircularInt& CircularInt::operator/=(int num){
    if (num == 0) throw string("you can't divide in zero!");
    if ((cur%num) != 0){ throw string("There is no number x in {"+to_string(start)+","+to_string(end)+"} such that x*"+to_string(num)+"="+to_string(cur));}
    int y = 0;
    y = end-start+1;
    cur = (cur / num) % y;
    if(cur < start){
        cur = cur+y;
    }
        return *this;
}

//----------------------------------
// operator ??
//----------------------------------

CircularInt& CircularInt::operator++(){// prefix
    cur++;
    norm();
    return *this;
}

const CircularInt CircularInt::operator++(int){ //postfix
    CircularInt cpy(*this); 
    ++cur;
    norm();
    return cpy;
}


 CircularInt& CircularInt::operator--(){//prefix
    cur --;
    norm();
    return *this;
}

const CircularInt CircularInt::operator--(int){ //postfix
    CircularInt cpy(*this); 
    --cur;
    norm();
    return cpy;
}

//----------------------------------
// operator ?
//----------------------------------
CircularInt CircularInt::operator-(){  // end - this hour
    CircularInt cpy(*this); 
    cpy.cur = cpy.end - cpy.cur;
    cpy.norm();
    return cpy;
}

// CircularInt& CircularInt::operator-(const int& num){
//     int y, sum =0 ;
//     y = end-start+1;
//     sum = (num - cur) % y;
//     if(sum < start){
//         cur = sum+y;
//     }
//     else {
//         cur = sum;
//     }
//     return *this;
// }

const CircularInt CircularInt:: operator-(const CircularInt& other) { //this hour - hour
    CircularInt cpy(*this); 
    cpy.cur-=other.cur;
    cpy.norm();
    return cpy; 
}
   
const CircularInt CircularInt:: operator+(const CircularInt& other) { //this hour + hour
    CircularInt cpy(*this); 
    cpy.cur+=other.cur;
    cpy.norm();
    return cpy;
} 

const CircularInt CircularInt:: operator*(const CircularInt& other) { //this hour * hour
    CircularInt cpy(*this); 
    cpy.cur*=other.cur;
    cpy.norm();
    return cpy; 
} 

const CircularInt CircularInt:: operator/(const CircularInt& other) { //this hour / hour
    if(other.cur == 0) throw string("you can't divide in zero!");
    if((cur%other.cur)!=0){ throw string("There is no number x in {"+to_string(start)+","+to_string(end)+"} such that x*"+to_string(other.cur)+"="+to_string(cur));}
    CircularInt cpy(*this); 
    int y = end-start+1;
    cpy.cur = (cur / other.cur) % y;
    return cpy; 
} 

const CircularInt CircularInt:: operator-(const int i) { //this hour - int
    CircularInt cpy(*this); 
    cpy.cur -= i;
    cpy.norm();
    return cpy; 
}
   
const CircularInt CircularInt:: operator+(const int i) { //this hour + int
    CircularInt cpy(*this); 
    cpy.cur += i;
    cpy.norm();
    return cpy;  
} 

const CircularInt CircularInt:: operator*(const int i) { //this hour * int
    CircularInt cpy(*this); 
    cpy.cur *= i;
    cpy.norm();
    return cpy;  
} 

const CircularInt CircularInt:: operator/(const int num) { //this hour / int
    if (num == 0) throw string("you can't divide in zero!");
    if ((cur%num) != 0){ throw string("There is no number x in {"+to_string(start)+","+to_string(end)+"} such that x*"+to_string(num)+"="+to_string(cur));}
    int temp;
    CircularInt cpy(*this); 
    int y = end-start+1;
    temp = (cur / num) % y;
        if(temp == 0){
        cpy.cur=y;
    }
    else cpy.cur=temp;
    return cpy; 
}

    CircularInt& CircularInt::operator+=(const CircularInt& other){
        cur += other.cur;
        norm();
        return *this;
    }        
        
    
    CircularInt& CircularInt::operator*=(const CircularInt& other){
        cur *= other.cur;
        norm();
        return *this;
    }
    
    
    CircularInt& CircularInt::operator-=(const CircularInt& other){
        cur -= other.cur;
        norm();
        return *this;       
        
    }
    
    CircularInt& CircularInt::operator/=(const CircularInt& other){
    if (other.cur == 0) throw string("you can't divide in zero!");
    if ((cur%other.cur) != 0){ throw string("There is no number x in {"+to_string(start)+","+to_string(end)+"} such that x*"+to_string(other.cur)+"="+to_string(cur));}
    int y = 0;
    y = end-start+1;
    cur = (cur / other.cur) % y;
    if(cur < start){
        cur = cur+y;
    }
        return *this;        
        
    }

    // CircularInt CircularInt::operator ~(const CircularInt& c1){ //NOT
    //     int temp;
    //     CircularInt cpy(*this);
    //     temp=cpy.cur~c1.cur;
        
        
    //     return cpy;
    // }
    
    CircularInt CircularInt::operator &(const CircularInt& c1){ //AND
        int temp;
        CircularInt cpy(*this);
        temp=cpy.cur&c1.cur;
        
        
        return cpy;
    }
    
    CircularInt CircularInt::operator |(const CircularInt& c1){ //OR
        int temp;
        CircularInt cpy(*this);
        temp=cpy.cur|c1.cur;
        
        
        return cpy;    
    }
    
    CircularInt CircularInt::operator ^(const CircularInt& c1){ //XOR
        int temp;
        CircularInt cpy(*this);
        temp=cpy.cur^c1.cur;
        
        
        return cpy;    
    }
    
    CircularInt CircularInt::operator <<(const CircularInt& c1){ //Bitwise left shift
        int temp;
        CircularInt cpy(*this);
        temp=cpy.cur<<c1.cur;
        
        
        return cpy;    
    }
    
    CircularInt CircularInt::operator >>(const CircularInt& c1){ //Bitwise right shift
        int temp;
        CircularInt cpy(*this);
        temp=cpy.cur>>c1.cur;
        
        
        return cpy;    
    }
