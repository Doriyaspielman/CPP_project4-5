#include "CircularInt.hpp"
#include <iostream>
using namespace std;

CircularInt:: CircularInt(int s, int e){ //constructor
    start = s;  
    end = e;
    cur = start;
}

//----------------------------------
// operator ?=
//----------------------------------

CircularInt& CircularInt::operator+=(int num){
    int y, sum =0 ;
    y = end-start+1;
    sum = (cur+num) % y;
    if(sum < start){
        cur = sum+y;
    }
    else{
        cur = sum;
    }
        return *this;
}

CircularInt& CircularInt::operator-=(int num){
    int y, sum =0 ;
    y = end-start+1;
    sum = (cur-num) % y;
    if(sum < start){
        cur = sum+y;
    }
    else{
        cur = sum;
    }
        return *this;
}

CircularInt& CircularInt::operator*=(int num){
    int y = 0;
    y = end-start+1;
    cur = (cur * num) % y;
    if(cur < start){
        cur = cur+y;
    }
        return *this;
}

CircularInt& CircularInt::operator/=(int num){
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
    int y;
    y = end-start+1;
    if(cur+1 >= end){
        cur = (cur+1) % y;
    }
    else{
       cur++;
    }
    return *this;
}

const CircularInt CircularInt::operator++(int){ //postfix
    CircularInt cpy(*this); 
    int y;
    y = end-start+1;
    if(cur+1 >= end){
        cur = (cur+1) % y;
    }
    else{
       cur++;
    }
    return cpy;
}


 CircularInt& CircularInt::operator--(){//prefix
    int y;
    y = end-start+1;
    if(cur-1 <= start){
        cur = (cur-1) + y;
    }
    else{
       cur--;
    }
    return *this;
}

const CircularInt CircularInt::operator--(int){ //postfix
    CircularInt cpy(*this); 
    int y;
    y = end-start+1;
    if(cur-1 <= start){
        cur = (cur-1) + y;
    }
    else{
       cur--;
    }
    return cpy;
}

//----------------------------------
// operator ?
//----------------------------------
CircularInt CircularInt::operator-(){
    CircularInt cpy(*this); 
    int ans = cpy.end - cpy.cur;
    int y = cpy.end-cpy.start+1;
    if(ans < cpy.start){
        cpy.cur = ans + y;
    }
    else {
        cpy.cur = ans;
    }
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
    int y = end-start+1;
    cpy.cur = (cur - other.cur) % y;
    if(cpy.cur < cpy.start){
        cpy.cur = cpy.cur+y;
    }
    return cpy; 
}
   
const CircularInt CircularInt:: operator+(const CircularInt& other) { //this hour + hour
    CircularInt cpy(*this); 
    int y = end-start+1;
    cpy.cur = (cur + other.cur) % y;
    return cpy; 
} 

const CircularInt CircularInt:: operator*(const CircularInt& other) { //this hour * hour
    CircularInt cpy(*this); 
    int y = end-start+1;
    cpy.cur = (cur * other.cur) % y;
    return cpy; 
} 

const CircularInt CircularInt:: operator/(const CircularInt& other) { //this hour / hour
    CircularInt cpy(*this); 
    int y = end-start+1;
    cpy.cur = (cur / other.cur) % y;
    return cpy; 
} 


