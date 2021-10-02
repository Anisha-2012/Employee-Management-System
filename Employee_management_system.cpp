#include<iostream>
using namespace std;

#define MAX_SCORE 100

#define TOTAL_WORKING_DAYS 256

#define MAX_APPRAISAL 5000

#define ItotalProjects 20

//Creating a Department class
class Department{

    private:

      int ID;

      string location;

      int employees;

    public:
       //Default Constructor
       Department(){}
       //Parameterized Constructor
       Department(int ID, string location, int employees){
           this->ID = ID; 
           this->location = location; 
           this->employees=employees;
           
       }
       //declaring friend function
       friend void display();
       void display(){
           cout<<"ID of the department:"<<ID<<"\n";
           cout<<"Location of the department:"<<location<<"\n";
           cout<<"Number of employees:"<<employees<<"\n";
           
       }

};
       //Inheriting HR_Department class from Department class
       class HR_Department: public Department{
           private:
             double esalary;
             double appraisalScore;
             double newsalary;
             
           public:
             string ename;
             int days;
          //Default Constructor
          HR_Department(){}   
          //Parameterized Constructor
          HR_Department(string ename,double esalary,int days): Department(){
             this->ename=ename;
             this->esalary=esalary;
             this->days=days;
              
          }
          //Method to appraise employee
          void AppraiseEmployee(){
              appraisalScore =(days/TOTAL_WORKING_DAYS*100);
              newsalary=esalary+(MAX_APPRAISAL*appraisalScore/100);
              
          }
          void display(){
              cout<<"Name of the employee is: "<<ename<<"\n";
              cout<<"AppraisalScore is: "<<appraisalScore<<"\n";
              cout<<"Employee'S salary is: "<<esalary<<"\n";
              cout<<"Employee's new salaryis: "<<newsalary<<"\n";
              
          }
           
       };
       //Inheriting Employee class from HR_Department class
       class Employee : public HR_Department{
           private:
              double e_sal;
              
           public:
              int eID;
              string e_name;
              
              Employee(){}             //Default Constructor
              Employee(int eID,string e_name, double e_sal){   //Parameterized Constructor
                  this->eID = eID;
                  this->e_name = e_name;
                  this->e_sal = e_sal;
                  
              }
              
              void display(){
                  cout<<"ID of the Employee is:"<<eID<<endl;
                  cout<<"Name of the Employee is:"<<e_name<<endl;
                  cout<<"Salary of the Employee is:"<<e_sal<<endl<<"\n";
                  
              }
              //Operator Overloading
              Employee operator >(Employee temp){
                 Employee obj = Employee();
                  if(temp.e_sal>e_sal){
                      obj=temp;
                      
                  }
                  else{
                      obj.eID=this->eID;
                      obj.e_name=this->e_name;
                      obj.e_sal=this->e_sal;
                      
                  }
                  return obj;
                  
              }
           
       };
       
 //Creating IT Department Employee class      
 class ITEmployee{
   public:
      int IID;
      string Iname;
      double IappraisalScore;
      int IprojectCompleted;
     
      int Irating;
      ITEmployee(){}
      ITEmployee(int IID, string Iname,int Irating, int IprojectCompleted){
        this->IID = IID;
        this->Iname = Iname;
        this->Irating = Irating;
        this->IprojectCompleted = IprojectCompleted;
        
    }
    //Creating Inline function
    inline void IappraisalIEmployee(){
        cout<<"Enter the projects completed by them: "<<endl;   //Performing Exception handling
        cin>>IprojectCompleted;
        try{
            if(IprojectCompleted > 0)
            {
                IappraisalScore = (IprojectCompleted*100)/ItotalProjects;
                cout<<"Their appraisal score is: "<<IappraisalScore<<endl;
            }
            else
            {
                throw(IprojectCompleted);
            }
        }
        catch(int num){
            cout<< "They haven't completed the projects."<<endl;
            cout<<"The projects completed by them are: "<<num;
        }
    }
    
    ~ITEmployee(){}      //Destroying ITEmployee
};

//Creating an ITDepartment class
class ITDepartment{
    public:
    
     ITDepartment(){}
       //Creating an array for Best employee
       void Bestemp(ITEmployee* earr,int size){
           int max1=-1;
           string bestname;
           for(int i=0;i<size;i++){
               max1=max(max1,earr[i].Irating);
           }
           for(int j=0;j<size;j++){
               if(max1==earr[j].Irating){
                   cout<<"\nThe best employee of the year is: "<<earr[j].Iname<<"\n";
                   cout<<"Whose employee ID is: "<<earr[j].IID<<"\n";
                   cout<<"And has an outstanding rating of: "<<earr[j].Irating<<"\n";
                   }
           }
       }
};

//Creating Template class
template<class T>  
class salesdepartment { 
protected: 

    T rank; 

public: 

   salesdepartment (T aa){ 

        rank = aa; 

        cout<<"Sales department rank: "<<this->rank<<endl; //Displaying sales department rank

    } 

}; 

template <class T>  

class PGsalesdepartment: public salesdepartment<T>{ 

    public: 

        PGsalesdepartment(T a): salesdepartment<T>(a) { 

        } 

        //Here is the method in derived class  

    void print() { 

cout<<"In derived print method, rank: "<<this->rank<<"\n"; 

    } 

}; 

class salarysavings { 

    private: 

        double balance; 

    public: 

        salarysavings(){} 

        salarysavings(double balance){ 

            this->balance = balance; 

        } 

        salarysavings operator +(salarysavings & ssavings){  //overloading the + operator for salary

            salarysavings ss; 

            ss.balance = this->balance + ssavings.balance; 

            return ss; 

        } 

        void display(){ 

            cout<<"Balance of the savings is: "<<this->balance<<"\n"; 

        } 

}; 
template<typename T>  

class employee { 

    public: 

        T ID; 

        employee(T id){ 

            this->ID = id; 

        } 

        void print(){ 

            cout<<"ID:"<<this->ID<<"\n"; 

        } 

}; 

template <class T> 

T mmax(T x,T y){ 

    return (x>y) ? x:y; 

} 

class cDate 
{ 

    int mDay,mMonth,mYear; 

public: 

    cDate() 

    { 

        mDay = 10; 
        mMonth = 11; 
        mYear = 1999; 

    } 
    cDate(int d,int m ,int y) 

    { 

        mDay = d; 
        mMonth = m; 
        mYear = y; 

    } 
    void display() 

    { 

        cout << "Day" << mDay << endl; 
        cout <<"Month" << mMonth << endl; 
        cout << "Year" << mYear << endl; 

    } 
}; 
// Container class 

class cEmployee          
{ 

protected: 

    int mId; 

    int mBasicSal; 

    // Contained Object 

    cDate mBdate;        

public: 

    cEmployee() 

    { 

        mId = 1; 
        mBasicSal = 10000; 
        mBdate = cDate(); 

    } 

    cEmployee(int, int, int, int, int); 

    void display(); 
}; 


cEmployee :: cEmployee(int i, int sal, int d, int m, int y) 
{ 

    mId = i; 
    mBasicSal = sal; 
    mBdate = cDate(d,m,y); 
} 

void cEmployee::display() 
{ 

    cout << "Id : " << mId <<endl; 

    cout << "Salary :" <<mBasicSal << endl; 

    mBdate.display(); 
} 

int main()
{
    Department D = Department(634,"New Delhi",500000);
    D.display();               //calling the display of Department class
    
    HR_Department H = HR_Department("Arav",1000, 100);
    H.AppraiseEmployee();      //apprasing the employee
    H.display();             //displaying the appraised salary
    
    Employee E1= Employee(100,"Ansh",10000);
    E1.display();
    Employee E2= Employee(101,"Riya",2000);
    E2.display();
    cout<<"Employee with greater salary is:"<<endl;
    Employee e= E1 > E2;          //calling the operator overloaded
    e.display();
    
    PGsalesdepartment<int> q(1); 
    q.print();     // calling the methods 
    employee<int> s(10); 
    s.print(); 
    cEmployee e1;           // Default constructor call  
    e1.display(); 
    cEmployee e2(2,20000,11,11,1999);  // Parameterized constructor called 
    e2.display(); 
    salarysavings ss1 = salarysavings(10000.0); 
    ss1.display();          
    salarysavings ss2 = salarysavings(20000.0); 
    ss2.display(); 
    ss1 = ss1 + ss2; 
    ss1.display(); 
    
    int N;
    cout<<"Enter the number of Employee:";
    cin>>N;

    ITEmployee* earr= new ITEmployee[N]; //Dynamic Object
    for(int i=0;i<N;i++){
        int IID;
        string Iname;
        int Irating;
        int IprojectCompleted;
        cout<<"Enter the name of Employee:"<<endl;
        cin>>Iname;
        cout<<"Enter the ID of the Employee:"<<endl;
        cin>>IID;
        cout<<"Enter the rating of this Employee out of 10:"<<endl;
        cin>>Irating;
        
        earr[i]=ITEmployee(IID,Iname,Irating,ItotalProjects);
    }
    
ITEmployee IE;
IE.IappraisalIEmployee();
    
   ITDepartment I=ITDepartment();
    I.Bestemp(earr,N);
    delete[] earr;  //deleting the employee array
 
    return 0;	
}