#include<iostream>
#define pie 3.14
#include<cmath>
using namespace std;

class Shape{
	protected:
		string name;
	public:
		
		Shape(string name){
			this->name = name;
			cout << "Shape Constructor Call" << endl ;
		}
		
		virtual void draw()const{
			cout << "This is only Shape " << endl ;
		}
		
       ~Shape(){
		cout << "Shape Destructor" << endl;
	   }
};

class Triangle:public Shape{
	public:
	Triangle(string name = ""):Shape(name){
        cout << "Triangle Constructor is call" << endl; 
		}
		
	void draw()const  override{
		cout << "This is a Shape of " << name << endl ;
	}	
	
	~Triangle(){
		cout << "Triangle Destructor" << endl;
	}
};

class Square:public Shape{
	public:
		Square(string name = ""):Shape(name){ 
		cout << "Square Constructor is call" << endl;
		}
		
	void draw()const  override {
	cout << "This is a Shape of " << name << endl ;
	}
		
	~Square(){
		cout << "Square Destructor" << endl;
	}
};

int main(){
	Triangle t("Triangle");
	Square s("Square");
	
	Shape& sp = t;
	sp.draw();
	 sp = s;
	sp.draw();
	
//	Vehicle& v = c;
//	v.display();
//	
//	Vehicle* v1 = new Car("Mercides",190);
//	v1->display();
//	delete v1;
	return 0;
}