#include<iostream>
#include<vector>
using namespace std;

class User{
	protected:
		string name;
		int id;
	public:
		
		User(){
			cout << "User Constructor Call" << endl ;
		}
		
		User(string name , int id):id(id),name(name){
			cout << "User parameterized Constructor Call" << endl ;
		}
		
		virtual void accessPortal()const=0;
		
		void displayInfo()const{
			cout << "User Name is: " << name << " and User Id is: "<< id << endl ;
		}

        string getName() const { return name; }
        int getId() const { return id; }
		
		virtual ~User(){
	      	cout << "User Destructor Call" << endl ;	
		}
};

// ---------------- Course Class ----------------
class Course{
	private:
		int course_id;
		string course_name;
	
	public:
		Course(int id = 0 , string name = ""):course_id(id),course_name(name){
		    cout << "Course Constructor is Call" << endl;
		}
	    
		void courseInfo()const{
	        cout << "Course ID: " << course_id << " | Course Name: " << course_name << endl ;    	
		}

        int getCourseId() const { return course_id; }
        string getCourseName() const { return course_name; }
		
		~Course(){
			cout << "Course Destructor is Call" << endl;
		}	
};

// ---------------- Admin Class ----------------
class Admin:public User{
    vector<Course> courses;  // Admin manages course list
	public:
		
	Admin(){
        cout << "Admin Constructor Call" << endl ;
	}
		
	Admin(string name , int id):User(name,id){
        cout << "Admin parameterized Constructor Call" << endl ;
	}
	
	void accessPortal()const override {
        cout << "Admin can create/delete courses" << endl;			
	}

    void addCourse(const Course& c){
        courses.push_back(c);
        cout << "Admin added course: ";
        c.courseInfo();
    }

    void showCourses()const{
        cout << "--- Course List by Admin ---" << endl;
        for(const auto& c : courses){
            c.courseInfo();
        }
    }
			
	~Admin(){
	    cout << "Admin Destructor Call" << endl ;	
	}
};

// ---------------- Teacher Class ----------------
class Teacher:public User{
	public:
	 Teacher(){
	    cout << "Teacher Constructor Call" << endl ;	
	 }
	
	Teacher(string name , int id):User(name,id){
        cout << "Teacher parameterized Constructor Call" << endl ;
	}
	
	void accessPortal()const override {
        cout << "Teacher can upload materials and grade students" << endl;			
	}

    void assignGrade(const User& student, const Course& c, char grade)const{
        cout << "Teacher assigned grade '" << grade 
             << "' to student " << student.getName()
             << " for course " << c.getCourseName() << endl;
    }
			
	~Teacher(){
	    cout << "Teacher Destructor Call" << endl ;	
	}		
};

// ---------------- Student Class ----------------
class Student:public User{
    vector<Course> enrolled;
	public:
		
	Student(){
	    cout << "Student Constructor Call" << endl ;	
	}
		
	Student(string name , int id):User(name,id){
        cout << "Student parameterized Constructor Call" << endl ;
	}
	
	void accessPortal()const override {
        cout << "Student can view materials and submit assignments" << endl;			
	}

    void enroll(const Course& c){
        enrolled.push_back(c);
        cout << "Student enrolled in: ";
        c.courseInfo();
    }

    void showEnrolledCourses()const{
        cout << "--- Courses enrolled by " << name << " ---" << endl;
        for(const auto& c : enrolled){
            c.courseInfo();
        }
    }
			
	~Student(){
	    cout << "Student Destructor Call" << endl ;	
	}		
};

// ---------------- Main ----------------
int main(){
	User* u1[] = { new Admin("Admin",1) , new Teacher("Teacher",2) , new Student("Student",3) };
	
	cout << "\n--- Access Portal Polymorphism ---" << endl;
	for(auto& i : u1){
		i->accessPortal();
		i->displayInfo();
	}

    cout << "\n--- Extra Functionality ---" << endl;
    Admin* admin = dynamic_cast<Admin*>(u1[0]);
    Teacher* teacher = dynamic_cast<Teacher*>(u1[1]);
    Student* student = dynamic_cast<Student*>(u1[2]);

    if(admin && teacher && student){
        Course c1(101,"OOP");
        Course c2(102,"Data Structures");

        admin->addCourse(c1);
        admin->addCourse(c2);
        admin->showCourses();

        student->enroll(c1);
        student->showEnrolledCourses();

        teacher->assignGrade(*student, c1, 'A');
    }

	cout << "\n--- Deleting Users ---" << endl;
	for(auto& i : u1){
	  delete i;
	}
	
	return 0;
}
