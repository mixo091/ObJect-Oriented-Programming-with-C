#include <iostream>
#include <cstdlib>
#include <cstring> 

#define CLASSES 6
#define FLOORS 5

using namespace std;




//some names to create random names for the students and the teachers
		const char* names[66] = {"Sophia","Sanjay","Jacob","Jon","Isabella","Guido","Emma","William","Jayden","Mehmet","Emily","Mia","Noah","Michael", "Ethan",
		"Chloe","Aiden","Daniel","Elizabeth","Ava","Avery","Benjamin","Gennady","David","Sofia","Grace","Andrew","Bjarne","Logan","Zoey","Alexis","Lucas","Gabriel",
		"Kaylee","Isaac","Taylor","Evan","Landon","Jack","Alexa","Fabrice","Aaron","Brandon","Linus","Steve","Dough","Connor","Arianna","Scarlett","Eva", "bourne",
		"Dennis","James","Adam","John","Anders","Stephen","Jeff","Ian","Tim","Brian","Ken","Ferhat","Richard","Petr","Donald"};
		
		const char* surnames[120] = {"Smith","Johnson","Williams","Brown","Jones","Rossum","Watson","Stone","Miller","Davis","Torvalds","Garcia","Rodrigez","Wilson", "Ethan",
		"Anderson","Clarke","Thomas","Lee","Ava","White","Moore","Hernandez","Harris","Sofia","Grace","Lewis","Stroustrup","Hall","Zoey",
		"Walker","Perez","Gabriel", "Lopez","Newton","Edison","Evan","Robinson","Dorsey","Alexa","Fabrice","Eder","Fischer","Clark","Jobs",
		"Doug","Connor","Arianna","Scarlett","Eva","Again","Schwarz", "Maier","Mayr","Egger","Claes","Nielsen","Petersen","Madsen","Ilves",
		"Robert","Leroy","Lion","Martin","Hawking","Meyer","Weber","Schulz","Becker","Hoffmann","Samaras","koufos","Kritikos","Papp","Jensen",
		"Waage","Kvaran","Rossi","Russo","Ferrari","Esposito", "Bianchi","Romano","Emine","Egzon","Arben","Yilmaz","Demir","Sahin","Celik","Kaya",
		"Aydin","Ozdemir","Arslan","Dogan","Kilic","Yildiz","Ozturk","Yildirim","Melnyk","Kovalenko","Boyko","Koval","Moroz","Petrenko","Robinson","Wood",
		"Ritchie","Gosling","Gontier","John","Anders","Bezos","Ian","Cook","Brian","Gecdogan","Richard","Petr","Donald"};




//base class of physical beings

class person{
	//info for a person 
	protected:
	const char*  name;
	const char*   surname;
    int classNum;
	int floorNum;
	int personId;
	int inClass;
	bool presentInclass;
	int tiredPoints;
	//L for each person  
	int tirednessGrowth;

	//functionality
	public:
	//creating a person	
	//Constructor function
	person(int id,int Cn, int Fn,int L):personId(id),classNum(Cn),floorNum(Fn),tirednessGrowth(L){ 
		this->inClass=0;
	//	this-whereIsHe=0;
		name=names[rand()%66];
		surname=surnames[rand()%120]; 
		cout<<"A person has been created!"<<endl; 
		tiredPoints=0;
		}
		
	//-----------------------------------------------
		int getFloor(){ 
			return this->floorNum;
		}
		int getClass(){ 
			return this->classNum;
		}
		int setHimIn(){
			this->inClass=1;
		}
		void setId(int id){
			this->personId=id;
		}
		int getId(){
			return this->personId;
		}
		int isIN(){
			return inClass;
		}
		
		
		void printPerson(){
			cout<<name<<" "<<surname<<" !"<<"TiredPoints:"<<tiredPoints<<" "<<endl;
	}
		
		
		
		int getTiredness(){
			return tiredPoints;
		}
		void virtual print(){
			cout<<name<<" "<<surname<<" with id:"<<personId<<endl;
					}
};




//derived classes of person class
//1) Student

class Student:public person {
	

public:
	//consructor
	
	Student(int id,int Cn, int Fn,int L):person(id,Cn, Fn, L){
		
		cout<<"A student has been created!"<<endl;
	}
	//-----------------------------------------------------------
	void attend(){
		tiredPoints=tiredPoints+ tirednessGrowth;
	}
	
	void print(){
		cout<<"Student: "<<name<<" "<<surname<<" ,";
	}
	
	//destuctor
	~Student(){
		cout<<"A student has been destroyed!"<<endl;
	}
		
};


//2) Teacher


class Teacher:public person {
	

public:
	//consructor
	
	Teacher(int id,int Cn, int Fn,int L):person(id,Cn, Fn, L){
		
		cout<<"A teacher has been created!"<<endl;
	}
	//-----------------------------------------------------------
	void teach(){
		tiredPoints=tiredPoints+ tirednessGrowth;
	}
	
	void print(){
		cout<<"Teacher: "<<name<<" "<<surname<<endl;
	}
	
	//destuctor
	~Teacher(){
		cout<<"A teacher has been destroyed!"<<endl;
	}
		
};



//-----------------------------------------------------------------------------------



//absrtact class Space

class Space{
	protected:
		//info of space
		int Capacity;
		int numOfStudents;
		Student** studentList;
	public:
		
		Space(int Cs){
			Capacity=Cs;
			numOfStudents=0;
			//initializing the list of students of every space in the building
			studentList = new Student*[Capacity];
			for(int i =0; i<Capacity;i++){
	    	studentList[i]=NULL;}
	    	cout<<"A space has been created!"<<endl;
		
		}
		
        int getSpace(){
        	return Capacity-numOfStudents;
		}
		
		//a function for a specific student to exit the space
		//exit for getting out a specific student
	    void exit(Student*s){
    		int pos=-1;
			for (int i=0; i<numOfStudents;i++){
			if(studentList[i]->getId()==s->getId()){
				pos=i;
				}
				}
			//------------------------------------------------------
			Student* temp=NULL;
			temp=studentList[pos];
			studentList[pos]=NULL;
			//..........................................
			int n=(sizeof(studentList[0])*(numOfStudents-pos))/sizeof(studentList[0]);
        	memmove(studentList+pos,studentList+pos+1,sizeof(Student*)*(n-1));
       		studentList[numOfStudents-1]=NULL;
       	 	numOfStudents--;
       	 	temp->print();
       	 	exitingMessage();
				}
       	 	
       	 	
    //exit for getting out the fisrt student in line  	 	
    Student* exit(){
	    Student* s=NULL;
		s=studentList[0];
	//		cout<<" s "<<s->getNum()<<endl;
		studentList[0]=NULL;
		int n=(sizeof(studentList[0])*numOfStudents)/sizeof(studentList[0]);
  	
	    Student* tmp=studentList[0];
        memmove(studentList,studentList+1,sizeof(Student*)*(n-1));
        studentList[n-1]=tmp;
        numOfStudents--;
        s->print();
        exitingMessage();
        return s;
	
}	
       	 	
       	 	
       	 	
       	void virtual enter(Student*s ){
		if(studentList[numOfStudents]==NULL){
		    studentList[numOfStudents]=s;
		    s->print();
		    enteringMessage();
			numOfStudents++;}
	    }
	 	
       	//the entering message is a pure virtual function 
       	//its differents in every class
       	virtual void enteringMessage()=0;
        virtual void exitingMessage ()=0;
       	int getStudents(){
       		return numOfStudents;
		   } 	

		~Space(){
		    delete[] studentList;		
		}
        void virtual printStudents(){
        	for(int i=0;i<numOfStudents;i++){
        		studentList[i]->printPerson();
        		
			}
		}	
	
	
	
	
	
	
};


class Corridor:public Space{
	
	public:
			
	Corridor(int max) :Space(max){		
		cout<<"Corridor has been created!"<<endl;
	}
	
	void enteringMessage(){
	    	cout<<" enters corridor!"<<endl;
		}	
	void exitingMessage(){
	    	cout<<" exits corridor!"<<endl;
		}
/*This function return the fisrt student at the
 Corridor list whose class is c .*/ 	
    Student* search_c(int c){
	 for(int i=0 ;i<numOfStudents;i++){
	 	if(studentList[i]->getClass()==c){
	 		cout<<"student "<<studentList[i]->getId()<<" "<<studentList[i]->getFloor()<< endl;
	 		return studentList[i];
		 }
	 }
	 return NULL;
}
	~Corridor() {cout<<"Corridor has been destroyed!" <<endl;}
	
};


































///derived clases of class space 

class Class:public Space {   
	int classNum;
	int floor;
	Teacher*  pr;

public:
	Class(int no, int max,int Fn) :Space(max),classNum(no),floor(Fn){
	
		cout<<"Class "<<classNum <<" has been created !"<<endl;
		pr=NULL;
	}	
	void enteringMessage(){
	    cout<<" enters class "<<classNum<<" !"<<endl;
		}
	void exitingMessage(){
	    cout<<" exits class "<<classNum<<" !"<<endl;
		}
		
    void place(int Lt){
		pr=new Teacher(classNum*floor,classNum,floor,Lt);
		pr->setHimIn();
		pr->print();
		cout<<"placed at Class!"<<endl;
	}
	
	void Operate(int N){
		int j;
		for(int i=0;i<N;i++){
			//teacher teaching 
		//	cout<<"class Operating "<<classNum<<"hour"<<i<<endl;
			if(pr!=NULL){
			pr->teach();}
			//students attending
			for(j=0;j<numOfStudents;j++){
				//cout<<j<< " - "<<numOfStudents<<endl;
				if(studentList[j]!=NULL){
				
				studentList[j]->attend();}
			}
		
	}
	
}
	
	
	~Class() {cout<<"Class number "<<classNum<< "has been destroyed!" <<endl;}

};



class Floor:public Space{
	int floorNum;
	Class** classes;
	Corridor* corridor;
	
	
	//functionality 
	
	public:
	//constructor	
	Floor(int num,int Cf,int Ccorr,int Cclass):Space(Cf),floorNum(num){	
		corridor=new Corridor(Ccorr);
		classes = new Class*[CLASSES];
	    for(int i=0; i<CLASSES; i++) { classes[i] = new Class(i+1,Cclass,floorNum);}
			cout<<"Floor number "<<floorNum<<"has been created!"<<endl;}	
	
	//function to print the floor
	void print(){
		cout<<"Printing floor number -----"<< floorNum<<"-----number of students"<< numOfStudents <<endl;
	        for(int i=0; i <numOfStudents;i++){
		    	studentList[i]->print();
                 	}
					}
	
	void enteringMessage(){
	    cout<<" enters floor number "<<floorNum<<" !"<<endl;
	}
	void exitingMessage(){
	    cout<<" exits floor number "<<floorNum<<" !"<<endl;
	}

	void enterCorridor(Student* s){
		if(corridor->getSpace()>0){
			s->print();
			enteringMessage();
			corridor->enter(s);}
		}
    void CorridorMoving();
    
    void place(int Lt){
        	for(int i=0;i<CLASSES;i++){
        			classes[i]->place(Lt);
				}
			}
		
		int CorridorSpace(){
			corridor->getSpace();
		}

     void printStudents(){
     	cout<<"Corridor currently!"<<endl;
     	corridor->printStudents();
     	cout<<"---------------------------------"<<endl;
     	for(int i=0;i<CLASSES;i++){
     		cout<<"Class number:"<<i<<" currently"<<endl;
     		classes[i]->printStudents();
      		cout<<"---------------------------------"<<endl;    		
		 }
     	
	 }
     
     
    void Operate(int N );



	//destructor
	~Floor(){ 
		for(int i=0; i<CLASSES; i++)
			delete classes[i];
		delete corridor;
		cout<<"Floor number "<<floorNum<<"has been destroyed!"<<endl;
		}
	
};



	void Floor:: CorridorMoving(){
			cout<<"CorridorMoving"<<endl;
			Student* s=NULL;
			for(int c=0; c<CLASSES;c++){
				s=corridor->search_c(c);
					while(classes[c]->getSpace()>0 && s!=NULL){
					corridor->exit(s);	
					s->setHimIn();
					classes[c]->enter(s);		
					s=corridor->search_c(c);
				
					}
			
	
				}
				
			}
			
			
			
			
   void Floor:: Operate(int N ){
		for(int i=0;i<CLASSES;i++){
		//	cout<< " floor operating !"<<endl;
			cout<<i<<endl;
     		classes[i]->Operate(N);
      	   		
	}
   }









//------------------------------------------------------------------------------------------



class Staircase:public Space {

	public:
		Staircase(int Cs):Space(Cs){
			cout<<"Staircase has been created \n";
		}
		void enteringMessage(){
	    	cout<<" enters staircase!"<<endl;
		}
    	void exitingMessage(){
	    	cout<<" exits staircase!"<<endl;
		}
		Student*  search_f(int f);
		void stairsMoving(Floor** floors);
		~Staircase(){ 
		cout<<"staircase has been destroyed\n";
		}
		
};

/*This function return the fisrt student at the
 staircase list whose class is at the floor f .*/ 

Student* Staircase:: search_f(int f){
	 for(int i=0 ;i<numOfStudents;i++){
	 	if((studentList[i]->getFloor())==f){
	 		cout<<"student "<<studentList[i]->getId()<<" "<<studentList[i]->getFloor()<< endl;
	 		return studentList[i];
		 }
	 }
	 return NULL;
}

/*
This function simulates the movement of the staircase
*/
void Staircase:: stairsMoving(Floor** floors){
	   Student* s=NULL;
	   for(int f=0; f<FLOORS;f++){
	   	cout<<"Floor number ------"<<f<<endl;
	   	s=search_f(f);
	   	//if there is space to the floor && the corridor of course
	   	while(floors[f]->getSpace()>0 && floors[f]->CorridorSpace()>0 && s!=NULL){
	   		if(s!=NULL){
	   			exit(s);
	   			floors[f]->enter(s);
	   			floors[f]->enterCorridor(s);
	   		
			   }
	   		s=search_f(f);
	   		
		   }
		   //Corridor Moving
		   //CorridorMoving is a function of the floor class which simulates the movement of students at the corridor of each floor.
		   	floors[f]->CorridorMoving();	
	   } 
} 

























class Yard:public Space{

	public:
		Yard(int Cy):Space(Cy){
			cout<<"The yard has been created \n";
		}
         	
	    void enteringMessage(){
	    	cout<<" enters yard!"<<endl;
		}
		void exitingMessage(){
	    	cout<<" exits yard!"<<endl;
		}
		~Yard(){
		 	cout<<"The yard has been destroyed \n";
			}
		};





class School:public Space{
	
	Yard yard;
    Staircase staircase;
    Floor ** floors;
	
	//functionality
	
	public:
		//constructor
		School(int n, int Cy, int Cs,int Cf,int Ccorr,int Cclass  ,int students=0) :Space(n), yard(Cy), staircase(Cs){			
		floors = new Floor*[FLOORS];
		for(int i=0; i<FLOORS; i++){
		    floors[i] = new Floor(i,Cf,Ccorr,Cclass);
	     }
		cout<<"A New School has been created!"<<endl;}
		
		void enter(Student* s ,int current);
		void enteringMessage(){
	    	cout<<" enters school!"<<endl;
		}
		void exitingMessage(){
	    	cout<<" exits school!"<<endl;
		}
		void printSimulationStatus();
		void place(int Lt);
		bool keepMoving(int N );
		void Operate(int N);
			
		//destructor
		~School() {   
	    	for(int i=0; i<FLOORS; i++)
				delete floors[i];
			cout<<"The School has been destroyed!"<<endl; }
	
	
	
};

bool School:: keepMoving(int N){
	if(yard.getStudents()>0 || numOfStudents<N ){
		return true;
	}else{
		return false;
	}
}



void School ::place(int Lt){
	for(int i=0; i<FLOORS;i++){
		floors[i]->place(Lt);
	}
}











void School::enter(Student* s ,int current){
	Student* t=NULL;
	//if there is space in the school
	if(numOfStudents<Capacity && yard.getSpace()>0 && s!=NULL){
		s->setId(current);
		//s->setWhere(1);
		studentList[numOfStudents]=s;
	    s->print();
	    //cout<<" enters School!"<<endl;
		numOfStudents++;
		//s->print();
	    cout<<" enters School!"<<endl;
		yard.enter(s);	}
       if(yard.getSpace()==0 || numOfStudents==Capacity || s==NULL){
		while(staircase.getSpace()>0 && yard.getStudents()>=1){
	    t=yard.exit();
	    //yard.printList();
	    //cout<<"exits yard !"<<endl;
	    staircase.enter(t);	
	    }
	    if(staircase.getSpace()==0 || (staircase.getSpace()>0 && yard.getStudents()==0)){
	    	cout<<"-----------STAIRS MOVING------------"<<endl;
	        staircase.stairsMoving(floors);
		}
	   }
	
}




void School::printSimulationStatus(){
	cout<<"School Simulation currently!"<<endl;
	cout<<"----------------------------------------------------"<<endl;
	cout<<"Yard currently!"<<endl;
	yard.printStudents();
	cout<<"----------------------------------------------------"<<endl;
	cout<<"Staircase currently!"<<endl;
	staircase.printStudents();
	cout<<"----------------------------------------------------"<<endl;
	for(int i=0;i<FLOORS;i++){
		cout<<"floor number "<<i<<" currently!"<<endl;
		floors[i]->printStudents();
		cout<<"----------------------------------------------------"<<endl;	
	}
	
		
}


void School::Operate(int N)
{
	cout<<"Operate for  "<<N<<" hours!"<<endl;
	cout<<"----------------------------------------------------"<<endl;
	for(int i=0;i<FLOORS;i++){
		cout<<i<<endl;
		floors[i]->Operate(N);
	
	}
	
	
}








//---------------------------------------------------------------------------------------------




































int main (){
	
	int flag=0;
	 int N,Cyard,Cstair,Cfloor,Ccorr,Cclass,Ls,Lj,Lt,Nh;
	
	//lets create our students and teachers .a.k.a person
	while(flag==0){
	
   
	cout<<"Give me max number of students for the school!"<<endl;
	cin>>N;
	cout<<"Give me max number of students for the yard!"<<endl;;
	cin>>Cyard;
	cout<<" Give me max number of students for the staircase!"<<endl;
	cin>>Cstair;
	cout<<" Give me max number of students for the floors!"<<endl;
	cin>>Cfloor;
	cout<<" Give me max number of students for the Corridors!"<<endl;
	cin>>Ccorr;
	cout<<" Give me max number of students for the classes!"<<endl;
	cin>>Cclass;
	cout<<"Give me Ls!"<<endl;
	cin>>Ls;
	cout<<"Give me Lj!"<<endl;
	cin>>Lj;
	cout<<"Give me Lt!"<<endl;
	cin>>Lt;
    cout<<"Give me hours to Operate"<<endl;
    cin>>Nh;
	if(Cfloor*FLOORS<N ){
		cout<<"invalid numbers put them, again "<<endl;
	}else{
		flag=1;
	}
	
	
	
}
	int tirednessGrowth;
	//---------------CREATING ARRAY OF STUDENTS---------------------------------
	Student** students;
	students = new Student*[N];
	int randomClass;
	
	int Lsenior=Ls;
	int Ljunior=Lj;
	
	
	
	
	
	for (int i=0; i<=N ; i++){
		randomClass=rand()%CLASSES;
		if(randomClass>2){
			tirednessGrowth=Lsenior;
		}else{
			tirednessGrowth=Ljunior;
		}
	    students[i] = new Student(i+1,randomClass,rand()%FLOORS,tirednessGrowth);
	    students[i]->print();
	    }
	
	int numberOfTeachers=CLASSES*FLOORS;
	
	int Lteacher=Lt;
	


	
	
	
	
	
	
	
	

	
	//--------------CREATING SCHOOL--------------------------------------------
	School school(N,Cyard,Cstair,Cfloor,Ccorr,Cclass);
	
	
	
	cout<<"Placing the teachers to their classes randomly"<<endl;
	school.place(Lteacher);

	
	
	
	//lets put the students in 
	int studentsIn=0;
	while (school.getStudents()<N  ){
    	if(school.getStudents()<N){
    	school.enter(students[studentsIn],studentsIn);
	    studentsIn++;}
	}
	
    school.printSimulationStatus();
	
	while(school.keepMoving(N)==true){
		school.enter(NULL,studentsIn);
		studentsIn++;
	}
	school.printSimulationStatus();
	
	school.Operate(Nh);
	
	cout<<"print status after Operating"<<endl;
	
	school.printSimulationStatus();
	
	
	
	
	
	//free the space of students
	
	
	for (int i=0; i<N; i++) {
	    delete students[i];
	}
	delete[] students;

	
	
	
	return 0;
}
