#include<iostream>
#include <string>

using namespace std;

class CircularInt{
    private :
        int start;
        int end;
        void norm();
        
    public : 
        int cur;
        CircularInt(int s, int e);
        
        //-------------------------------------
        // Logical operators
        //-------------------------------------
        friend bool operator !(const CircularInt& c1); //NOT - not c1
        friend bool operator &&(const CircularInt& c1, const CircularInt& c2);// AND - c1 and c2
        friend bool operator ||(const CircularInt& c1, const CircularInt& c2);// OR - c1 or c2
        
        //-------------------------------------
        // Bitwise operators
        //-------------------------------------
        //CircularInt operator ~(const CircularInt& c1); //NOT
        CircularInt operator &(const CircularInt& c1); //AND
        CircularInt operator |(const CircularInt& c1); //OR
        CircularInt operator ^(const CircularInt& c1); //XOR
        CircularInt operator <<(const CircularInt& c1); //Bitwise left shift
        CircularInt operator >>(const CircularInt& c1); //Bitwise right shift
        
        //----------------------------------
        // friend global IO operators
        //----------------------------------
        friend ostream& operator<< (ostream& os, const CircularInt& c);  //toString (cout)
        friend istream& operator>> (istream& input,  CircularInt& c);  // (cin)
        //-------------------------------------
        // friend global binary operators
        //-------------------------------------
        friend const CircularInt operator+ (const int& i, CircularInt& c); 
        friend const CircularInt operator* (const int& i, CircularInt& c);
        friend const CircularInt operator- (const int& i, CircularInt& c);
        friend const CircularInt operator/ (const int& i, CircularInt& c);
        friend bool operator == (const CircularInt& c1, const CircularInt& c2);
        friend bool operator != (const CircularInt& c1, const CircularInt& c2);
        friend bool operator > (const CircularInt& c1, const CircularInt& c2);
        friend bool operator < (const CircularInt& c1, const CircularInt& c2);
        friend bool operator >= (const CircularInt& c1, const CircularInt& c2);
        friend bool operator <= (const CircularInt& c1, const CircularInt& c2);
        friend bool operator == (const CircularInt& c1, const int& i);
        friend bool operator == ( const int& i,const CircularInt& c1);
        
        friend bool operator != ( const int& i,const CircularInt& c1);
        friend bool operator != (const CircularInt& c1, const int& i);
        friend bool operator < ( const int& i,const CircularInt& c1);
        friend bool operator < (const CircularInt& c1, const int& i);
        friend bool operator > ( const int& i,const CircularInt& c1);
        friend bool operator > (const CircularInt& c1, const int& i);
        friend bool operator <= ( const int& i,const CircularInt& c1);
        friend bool operator <= (const CircularInt& c1, const int& i);
        friend bool operator >= ( const int& i,const CircularInt& c1);
        friend bool operator >= (const CircularInt& c1, const int& i);

        //-------------------------------------
        // 2 parameters
        //-------------------------------------
        const CircularInt operator-(const CircularInt& other); //this hour - hour
        const CircularInt operator+(const CircularInt& other); //this hour + hour
        const CircularInt operator*(const CircularInt& other); //this hour * hour
        const CircularInt operator/(const CircularInt& other); //this hour / hour
        const CircularInt operator-(const int i); //this hour - int
        const CircularInt operator+(const int i); //this hour + int
        const CircularInt operator*(const int i); //this hour * int
        const CircularInt operator/(const int i); //this hour / int
        
        //-------------------------------------
        // 1 parameters
        //-------------------------------------
        CircularInt& operator=(int num);
        CircularInt& operator+=(int num);
        CircularInt& operator++();// prefix
        const CircularInt operator++(int); //postfix
        CircularInt& operator-=(int num);
        CircularInt& operator--(); //prefix
        const CircularInt operator--(int); //postfix
        CircularInt operator-();
        // CircularInt& operator-(const int& num); // check if needed- doesnt work well. there is another function who works.
        CircularInt& operator*=(int num);
        CircularInt& operator/=(int num);
        CircularInt& operator+=(const CircularInt& other);
        CircularInt& operator*=(const CircularInt& other);
        CircularInt& operator-=(const CircularInt& other);
        CircularInt& operator/=(const CircularInt& other);



};

        inline ostream &operator<<(ostream &os, CircularInt const &m) {  //toString
            int ans = m.cur;
            return os << to_string(ans);
        }
        
       inline istream& operator>> (istream& input,  CircularInt& c){ // (cin)
        int x,y;
        input >> x >> y ;
        if(x<y){
            c.start=x;
            c.end=y;
        }
        else{
            c.start=y;
            c.end=x;            
        }
        return input;
    //         // remember place for rewinding
    //     ios::pos_type startPosition = input.tellg();

    //     if ( (!(input >> c.start))                 ||
    //     (!getAndCheckNextCharIs(input,'+')) ||
    //      (!(input >> c.end))                 ||
    //      (!(getAndCheckNextCharIs(input,'i'))) ) {

    //     // rewind on error
    //     auto errorState = input.rdstate(); // remember error state
    //     input.clear(); // clear error so seekg will work
    //     input.seekg(startPosition); // rewind
    //     input.clear(errorState); // set back the error flag
    //     }

    // return input;
            
         }

        inline const CircularInt operator+ (const int& i, CircularInt& c) {  //int + hour
            CircularInt cpy(c);
            int y, sum =0;
            y = c.end-c.start+1;
            sum = (c.cur+i) % y;
            if(sum < c.start){
            cpy.cur = sum+y;
            }
            else{
                cpy.cur = sum;
            }
                return cpy;
        }
                
         inline const CircularInt operator* (const int& i,  CircularInt& c) {  //int * hour
            CircularInt cpy(c);
            int y, sum =0;
            y = c.end-c.start+1;
            sum = (c.cur*i) % y;
            if(sum < c.start){
            cpy.cur = sum+y;
            }
            else{
                cpy.cur = sum;
            }
                return cpy;
        }
         
        inline const CircularInt operator- (const int& i, CircularInt& c) {  //int - hour
            CircularInt cpy(c);
            int y, sum =0 ;
            y = c.end-c.start+1;
            sum = (i-c.cur) % y;
            if(sum < c.start){
                cpy.cur = sum+y;
            }
            else{
                cpy.cur = sum;
            }
                return cpy;
        }
        
        inline const CircularInt operator/ (const int& i,  CircularInt& c) {   //int / hour
            CircularInt cpy(c);
            int y, sum =0;
            y = c.end-c.start+1;
            sum = (i/c.cur) % y;
            if(sum < c.start){
            cpy.cur = sum+y;
            }
            else{
                cpy.cur = sum;
            }
                return cpy;
        }

        inline bool operator == (const CircularInt& c1, const CircularInt& c2) {   // if hour == hour
            return ((c1.cur == c2.cur) && (c1.start == c2.start)) && ((c1.start == c2.start) && (c1.end == c2.end));
        }
        
        inline bool operator != (const CircularInt& c1, const CircularInt& c2) {   //if hour != hour
            return (!(c1==c2));
        }
        
        inline bool operator >(const CircularInt& c1, const CircularInt& c2) {   // if hour > hour
            return (c1.cur > c2.cur);
        }
        
        inline bool operator <(const CircularInt& c1, const CircularInt& c2) {   //if hour < hour
            return (c2.cur > c1.cur);
        }
        
        inline bool operator >=(const CircularInt& c1, const CircularInt& c2) {   // if hour >= hour
            return (!(c1 < c2));
        }
        
        inline bool operator <=(const CircularInt& c1, const CircularInt& c2) {   //if hour <= hour
            return (!(c1 > c2));
        }
        
        inline bool operator == (const CircularInt& c1, const int& i){
            return(c1.cur==i);
        }
        
        inline bool operator == ( const int& i,const CircularInt& c1){
            return(i==c1.cur);

}
        inline bool operator !(const CircularInt& c1){ //NOT - not c1
            return (!c1.cur);
        }

        inline bool operator &&(const CircularInt& c1, const CircularInt& c2){// AND - c1 and c2
            return (c1.cur && c2.cur);
        }

        inline bool operator ||(const CircularInt& c1, const CircularInt& c2){// OR - c1 or c2
            return (c1.cur || c2.cur);
        }
        
        inline bool operator != ( const int& i,const CircularInt& c1){
            return(i!=c1.cur);

        }
        
        inline bool operator != (const CircularInt& c1, const int& i){
            return(c1.cur!=i);
            
        }
        
        inline bool operator < ( const int& i,const CircularInt& c1){
            return(i<c1.cur);

        }
        
        inline bool operator < (const CircularInt& c1, const int& i){
            return(c1.cur<i);
            
        }
        
        inline bool operator > ( const int& i,const CircularInt& c1){
            return(i>c1.cur);
        
        }
        
        inline bool operator > (const CircularInt& c1, const int& i){
            return(c1.cur>i);
            
        }
        
        inline bool operator <= ( const int& i,const CircularInt& c1){
            return(i<=c1.cur);
            
        }
        
        inline bool operator <= (const CircularInt& c1, const int& i){
            return(c1.cur<=i);
            
        }
        
        inline bool operator >= ( const int& i,const CircularInt& c1){
            return(i>=c1.cur);

        }
        
        inline bool operator >= (const CircularInt& c1, const int& i){
            return(c1.cur>=i);
            
        }
        
