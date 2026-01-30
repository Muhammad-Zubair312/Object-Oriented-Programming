#include<iostream>

using namespace std;

class Employee{
	
	private:
		string name;
		int id;
		int salary;
	
	public:
         
		 
		 	
		Employee(string name, int b , int num) : name(name) , id(b) , salary(num){}
		Employee() : name("") , id() , salary(0){}
		
		static Employee Highest(Employee e[],int size);
		
		void display()const;
		
};


  Employee Employee::Highest(Employee e[],int size){
	Employee m;
	m = e[0];
	
	for(int i = 1 ; i < size ; i++){
		 if(m.salary < e[i].salary){
		 	m = e[i];
		 }
	}
	return m;
}

void Employee::display()const{

cout << "Name: " << this->name << endl;
cout << "ID: " << this->id << endl;
cout << "Salary: " << this->salary << endl;
	
}

int main(){
	Employee e[3];
	e[0] = Employee("Usman",030754,90000);
	e[1] = Employee("Zubair",254,96000);
    e[2] = Employee("Zubair",254,96000);
    Employee e1 = Employee::Highest(e,3);
	e1.display();
	return 0;
	}