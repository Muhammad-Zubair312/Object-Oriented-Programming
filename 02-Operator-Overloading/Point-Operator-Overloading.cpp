#include<iostream>
#include<cmath>

using namespace std;

class Point{
	private:
		int x;
		int y;
	public:
		Point(int x = 0 , int y = 0): x(x) , y(y){}
		Point(int x , int y): x(x) , y(y){}
		Point(): x(0),y(0){}
		
		Point operator +(Point p2){
			return Point(x + p2.x,y + p2.y);
		}

        Point operator -(Point p2){
        	Point p;
        	p.x = x - p2.x >= 0  ? x - p2.x :  0;
        	p.y = y - p2.y >= 0  ? y - p2.y :  0;
			return p;
		}

        void operator+=(Point p2){
            
			x += p2.x;
            y += p2.y;
			
		}
        
        
        void operator ++(){
            
			++x;
            ++y;
			
		}
        
        void operator ++(int){
            
			x++;
            y++;
			
		}

        bool operator==(Point p2)const{
        	
			return (x == p2.x && y == p2.y);
			
		}		
		
		bool operator !()const{
			return this->x == 0 && this->y == 0;
		}
	
	
		int& operator[](int index){
			
			if(index == 0){
				return this->x;
			}
			return this->y;
			}
		
		int operator()()const{
			
			return sqrt(x*x + y*y);
			
			}
	
		
		
		friend ostream& operator<< (ostream&,const Point&);

		
		friend istream& operator>> (istream&,Point&);
		
	};
 ostream& operator<< (ostream& out,const Point& p){
			out << "X Point: " << p.x << endl;
			out << "Y Point: " << p.y << endl;
			return out;
		}


istream& operator>> (istream& in,Point& p){
			
			cout << "Enter X Point: ";
			in >> p.x ;
			cout << "Enter Y Point: ";
			in >> p.y ;
			return in;
		}

int main(){
	Point p1(9,6),p2(6,8),p3,p4;
	
	//overload + operator
	cout << "overload + operator" << endl;
	p3 = p1 + p2;
	
	//overload << operator
	cout << "overload << operator" << endl;
	cout << p3;
	
	//overload - operator
	cout << "overload - operator" << endl;
    p4 = p1 - p2;
    
    //overload >> operator
    cout << "overload >> operator" << endl;
    cin >> p4;
    
    //overload << operator	
	cout << "overload << operator" << endl;
	cout << p4;
	
	p4 = p3;
	
	//overload == operator
	cout << "overload == operator" << endl;
	if(p4 == p3){
		cout << "True";
	}
	else{
		cout << "False";
	}
	cout << endl;
	
	//overload += operator
	cout << "overload += operator" << endl;
	p1 += p4;
	cout << p1;
	
	//overload ++ operator prefix
	cout << "overload ++ prefix operator" << endl;
	++p1;
	cout << p1;
	
    //overload ++ operator postfix
	cout << "overload ++ post operator" << endl;
	p1++;
	cout << p1;


    //overload logical not ! operator 
	cout << "overload logical not ! operator" << endl;
	if(!p1){
		cout << "P1 is at origin";
	}
	else{
		cout << "P1 is not at origin";
	}
	cout << endl;

    //overload access[] operator
	cout << "overload access [] operator" << endl;
	 p2[0] = 9;
	 p2[1] = 12;
	 cout << "Point p2 is: " << p2 << endl;
	 
    
    //overload access[] operator
	cout << "overload distance() operator" << endl;
    cout << "Distance of Point p2 from origin is: " << p2() << endl;
	
	return 0;
	
}