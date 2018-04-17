#include<iostream>
#include <string>

#include<string>
using namespace std;

class CircularInt{
    private :
        int start;
        int end;
        
    public : 
    //       CircularInt (const int& s= 0,   //רשימת אתחול
    //          const int& e= 0)
    //     : _start(s), _end(e), _cur(s) {
    // }
    //
        int cur;
        CircularInt(int s, int e);
        // ~CircularInt(); //???
        
        //----------------------------------
        // friend global IO operators
        //----------------------------------
        friend ostream& operator<< (ostream& os, const CircularInt& c);  //toString
        //-------------------------------------
        // friend global binary operators
        //-------------------------------------
        friend const CircularInt operator+ (const int& i, CircularInt& c); 
        friend const CircularInt operator* (const int& i, CircularInt& c);
        friend const CircularInt operator- (const int& i, CircularInt& c);
        friend const CircularInt operator/ (const int& i, CircularInt& c);
        friend bool operator == (const CircularInt& c1, const CircularInt& c2);
        friend bool operator != (const CircularInt& c1, const CircularInt& c2);
        
        //-------------------------------------
        // 2 parameters
        //-------------------------------------
        const CircularInt operator-(const CircularInt& other); //this hour - hour
        const CircularInt operator+(const CircularInt& other); //this hour + hour
        const CircularInt operator*(const CircularInt& other); //this hour * hour
        
        //-------------------------------------
        // 1 parameters
        //-------------------------------------
        CircularInt& operator+=(int num);
        CircularInt& operator++();// prefix
        const CircularInt operator++(int); //postfix
        CircularInt& operator-=(int num);
        CircularInt& operator--(); //prefix
        const CircularInt operator--(int); //postfix
        CircularInt operator-();
        CircularInt& operator-(const int& num);

};

        inline ostream &operator<<(ostream &os, CircularInt const &m) {  //toString
            int ans = m.cur;
            return os << to_string(ans);
        }
        
        inline const CircularInt operator+ (const int& i, CircularInt& c) {  //int + hour
            int y, sum =0;
            y = c.end-c.start+1;
            sum = (c.cur+i) % y;
            if(sum < c.start){
            c.cur = sum+y;
            }
            else{
                c.cur = sum;
            }
                return c;
        }
                
         inline const CircularInt operator* (const int& i,  CircularInt& c) {  //int * hour
            int y, sum =0;
            y = c.end-c.start+1;
            sum = (c.cur*i) % y;
            if(sum < c.start){
            c.cur = sum+y;
            }
            else{
                c.cur = sum;
            }
                return c;
        }
         
        inline const CircularInt operator- (const int& i, CircularInt& c) {  //int - hour
            int y, sum =0 ;
            y = c.end-c.start+1;
            sum = (i-c.cur) % y;
            if(sum < c.start){
                c.cur = sum+y;
            }
            else{
                c.cur = sum;
            }
                return c;
        }
        
        // inline const CircularInt operator/ (const int& i,  CircularInt& c) {   //int / hour
        //     int y, sum =0;
        //     y = c.end-c.start+1;
        //     sum = (c.cur) % y;
        //     if(sum < c.start){
        //     c.cur = sum+y;
        //     }
        //     else{
        //         c.cur = sum;
        //     }
        //         return c;
        // }
        
        inline bool operator == (const CircularInt& c1, const CircularInt& c2) {   // if hour == hour
            return ((c1.cur == c2.cur) && (c1.start == c2.start) && (c1.end == c2.end));
        }
        
        inline bool operator != (const CircularInt& c1, const CircularInt& c2) {   //if hour != hour
            return (!(c1==c2));
        }
  
