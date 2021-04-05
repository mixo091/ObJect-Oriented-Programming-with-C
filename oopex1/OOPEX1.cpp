#include <iostream>
#include <cstdlib>
#include <cstring> 

#define CLASSES 6
#define FLOORS 4

using namespace std;






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











class Teacher{
	
	const char*  name;
	const char*  surname;
	//int Teacherid ;
	int classNum;
	int floorNum;
	bool presentInclass;
	
	public:
	
	
	Teacher(int Cn,int Fn):classNum(Cn),floorNum(Fn){
		presentInclass=false;
		name=names[rand()%66];
		surname=surnames[rand()%120];   
		cout<<"Professor::name :"<<name<<", surname:"<<surname<<endl;
		
	}
	
	void setPresent(bool x){
		presentInclass=x;
	}
	
	bool getPresent(){
		return presentInclass;
	}
	~Teacher();
};



class Student{	
	private:
		int stud_Num;
		int classNum;
		int floorNum; 
		int inClass;
		int whereIsHe;
		const char*  name;
	    const char*   surname;
	    int has_Tried;
		
	public:
		Student(int Sn,int Cn, int Fn):stud_Num(Sn),classNum(Cn),floorNum(Fn){ //Constructor function
		this->inClass=0;
		//this->stud_Num=STUDENTSNUM+1;
		this->whereIsHe=0;
		name=names[rand()%66];
		surname=surnames[rand()%120]; 
	    has_Tried=0;
		cout<<"A student has been created!"<<endl; 
	
		
		}
		int getFloor(){ 
			return this->floorNum;
		}
		
		int getClass(){ 
			return this->classNum;
		}
		int setHimIn(){
			this->inClass=1;
		}
		void setNum(int num){
			this->stud_Num=num;
		}
		int getNum(){
			return this->stud_Num;
		}
		void setWhere(int there){
			whereIsHe=there;
		}
		int getWhere(){
			return this->whereIsHe;
		}
		int isIN(){
			return inClass;
		}
		
		void hasTried(){
			has_Tried=1;
		}
		void print(){
			cout<<name<<" "<<surname<<" with student id:"<<stud_Num;
					}
		~Student(){
		//cout<<"A student has been destroyed!"<<endl;
		} 
		int getHasTried(){
			return has_Tried;
		}
}; 



class Class {   
	int classNum;
	int floor;
	int numOfStudents;
	int Cmax;
	Teacher*  pr;
	Student** studentsInC;

public:
	Class(int no, int max,int Fn,int students=0) : classNum(no), Cmax(max), floor(Fn),numOfStudents(students) {
			studentsInC = new Student*[Cmax];
	     	for(int i=0; i<Cmax;i++){
	    	studentsInC[i]=NULL;
		}	
		pr=new Teacher(no,Fn);
		
		cout<<"Class "<<classNum <<" has been created !"<<endl;
	}
	
	
	void place(){
		
		pr->setPresent(true);
	}
	
	
	bool hasTeacher(){
		return pr->getPresent();
	}
	
	void enter(Student*s ){
		
		if(studentsInC[numOfStudents]==NULL){
		    studentsInC[numOfStudents]=s;
		    s->print();
		    cout<<"enters class number"<<classNum<<" !"<<endl;
			numOfStudents++;}
	}
	
	~Class() {cout<<"Class number "<<classNum<< "has been destroyed!" <<endl;}
	int get_space() {return (Cmax-numOfStudents);}
};




class Corridor{
	int numOfStudents;
	int CorrMax;
	Student** studentsInCorr;
	
	public:
	
		Corridor(int max,int students=0) : CorrMax(max), numOfStudents(students) {
			studentsInCorr = new Student*[CorrMax];
	     	for(int i=0; i<CorrMax;i++){
	    	studentsInCorr[i]=NULL;
		}	
		
		cout<<"Corridor has been created!"<<endl;
	}
	
	void enter(Student* s){
		if(studentsInCorr[numOfStudents]==NULL){
		    studentsInCorr[numOfStudents]=s;
		    s->print();
		    cout<<"enters corridor!"<<endl;
			numOfStudents++;}
	}
	
	void exit(Student*s){
	int pos=-1;
	for (int i=0; i<numOfStudents;i++){
		if(studentsInCorr[i]->getNum()==s->getNum()){
			pos=i;
		}
	}
//	cout<<"THE SUDENTS IS AT POS "<<pos <<endl;
	//------------------------------------------------------
		Student* temp=NULL;
		temp=studentsInCorr[pos];
//		cout<<" temp "<<temp->getNum()<<endl;
		studentsInCorr[pos]=NULL;
		//..........................................
		
		int n=(sizeof(studentsInCorr[0])*(numOfStudents-pos))/sizeof(studentsInCorr[0]);
  //   	cout<<"N "<< n<<endl;
        memmove(studentsInCorr+pos,studentsInCorr+pos+1,sizeof(Student*)*(n-1));
        studentsInCorr[numOfStudents-1]=NULL;
        numOfStudents--;
        temp->print();
        cout<<"exits Corridor!"<<endl;
        //return s;
	
}	
	~Corridor() {cout<<"Corridor has been destroyed!" <<endl;}
	int get_space() {return (CorrMax-numOfStudents);}
	
	
	Student* search_c(int c){
	//  cout <<"search"<<endl;
	 for(int i=0 ;i<numOfStudents;i++){
	 	if(studentsInCorr[i]->getClass()==c){
	 		cout<<"student "<<studentsInCorr[i]->getNum()<<" "<<studentsInCorr[i]->getFloor()<< endl;
	 		return studentsInCorr[i];
		 }
	 }
	 return NULL;
}
		
};



class Floor{
	int floorNum;
	int Fspace;
	int numOfStudents;
	Class** classes;
	Corridor* corridor;
	Student** studentsInF;
	public:
		Floor(int num,int Cf,int Ccorr,int Cclass,int students=0):Fspace(Cf),floorNum(num),numOfStudents(students){
			studentsInF = new Student*[Fspace];
	     	for(int i=0; i<Fspace;i++){
	    	studentsInF[i]=NULL;
		}	
		corridor=new Corridor(Ccorr);
		classes = new Class*[CLASSES];
	    for(int i=0; i<CLASSES; i++) { classes[i] = new Class(i+1,Cclass,floorNum);}
	    
			cout<<"Floor number "<<floorNum<<"has been created!"<<endl;}
			
			
			
		void enter(Student* s)
	    {   if(studentsInF[numOfStudents]==NULL){
	    	s->setWhere(4);
		    studentsInF[numOfStudents]=s;
			numOfStudents++;}
		}
		
		void enterCorridor(Student* s){
			if(corridor->get_space()>0){
				s->print();
				cout<<" enters floor "<<floorNum<<" !"<<endl;
				corridor->enter(s);}
		}
		
		
        void place(){
        	for(int i=0;i<CLASSES;i++){
        		if(rand()%2==1){
        			classes[i]->place();
				}
			}
		}
	
		
		void CorridorMoving(){
			cout<<"CorridorMoving"<<endl;
			Student* s=NULL;
			for(int c=0; c<CLASSES;c++){
				s=corridor->search_c(c);
				if(s!=NULL){
					s->hasTried();
				}
				if(classes[c]->hasTeacher()==false){
					while(classes[c]->get_space()>0 && s!=NULL){
					corridor->exit(s);	
					s->setHimIn();
					classes[c]->enter(s);		
					s=corridor->search_c(c);
				    if(s!=NULL){
					s->hasTried();}
				
					}
				}else{
					cout<<"Sorry the Professor is already in!!!"<<endl;
			
				}
	
				}
				
			}
						
		int getSpace(){
			return (Fspace-numOfStudents);
		}
		
		int CorridorSpace(){
			corridor->get_space();
		}
		void print(){
			cout<<"Printing floor number -----"<< floorNum<<"-----number of students"<< numOfStudents <<endl;
	          for(int i=0; i <numOfStudents;i++){
		      cout<<"student number "<<studentsInF[i]->getNum()<<"inside Floor"<<endl;
                 	}
			
		}	
		~Floor(){ 
		    
	    	delete[] studentsInF;
		for(int i=0; i<CLASSES; i++)
			delete classes[i];
		delete corridor;
		cout<<"Floor number "<<floorNum<<"has been destroyed!"<<endl;
		
		}	
	
	
};



class Staircase {
	int Cstairs;
	int numOfStudents;
	Student** studentsInS;
	public:
		Staircase(int Cs,int students=0):Cstairs(Cs),numOfStudents(students){
		studentsInS = new Student*[Cstairs];
		for(int i=0; i<Cstairs;i++){
	    	studentsInS[i]=NULL;
		}
			
			cout<<"staircase has been created \n";
		}
		void printList();
		int getspace();
		void  enter(Student *s);
		
		void stairsMoving(Floor** floors);
		Student* search_f(int f);
		void exit(Student *s);
		void stairsMoving1(Floor** floors);
		~Staircase(){ 
			delete[] studentsInS;
		cout<<"staircase has been destroyed\n";
		}
		
};



int Staircase::getspace(){
	return (Cstairs-numOfStudents);
}

void  Staircase::enter(Student *s){
	    s->setWhere(3);
    	if(studentsInS[numOfStudents]==NULL){
		studentsInS[numOfStudents]=s;
		s->print();
		cout<<"enters Stairs!"<<endl;
		numOfStudents++;
		}
	}
	
void Staircase::printList(){
	cout<<"printing stairs"<<endl;
	for(int i=0; i <numOfStudents;i++){
		cout<<"student number "<<studentsInS[i]->getNum()<<"and floor number"<<studentsInS[i]->getFloor() <<"inside stairs"<<endl;
	}	
	
}


Student* Staircase:: search_f(int f){
	//cout <<"search"<<endl;
	 for(int i=0 ;i<numOfStudents;i++){
	 	if((studentsInS[i]->getFloor())==f){
	 		cout<<"student "<<studentsInS[i]->getNum()<<" "<<studentsInS[i]->getFloor()<< endl;
	 		return studentsInS[i];
		 }
	 }
	 return NULL;
}


void Staircase::exit(Student*s){
	int pos=-1;
	for (int i=0; i<numOfStudents;i++){
		if(studentsInS[i]->getNum()==s->getNum()){
			pos=i;
		}
	}
	//cout<<"THE SUDENTS IS AT POS "<<pos <<endl;
	//------------------------------------------------------
		Student* temp=NULL;
		temp=studentsInS[pos];
	//	cout<<" temp "<<temp->getNum()<<endl;
		studentsInS[pos]=NULL;
		//..........................................
		
		int n=(sizeof(studentsInS[0])*(numOfStudents-pos))/sizeof(studentsInS[0]);
     //	cout<<"N "<< n<<endl;
        memmove(studentsInS+pos,studentsInS+pos+1,sizeof(Student*)*(n-1));
        studentsInS[numOfStudents-1]=NULL;
        numOfStudents--;
        temp->print();
        cout<<"exit Stairs!"<<endl;
        //return s;
	
}




void Staircase:: stairsMoving(Floor** floors){
	   Student* s=NULL;
	   for(int f=0; f<FLOORS;f++){
	   	cout<<"Floor number ------"<<f<<endl;
	   	//if there is space to the floor && the corridor of course
	   	if(floors[f]->getSpace()>0 && floors[f]->CorridorSpace()>0){
	   		cout<<"floor has space"<<endl;
	   		//find the first one in stairs for the floor f
	      	s=search_f(f);
	   		if(s!=NULL){
	   			exit(s);
	   			cout<<"s "<<s->getNum()<<endl;
	   			floors[f]->enter(s);
	   			floors[f]->enterCorridor(s);
	   			//floors[f]->CorridorMoving();
			   }
	   		
	   		
		   }
	   	
	   }
	
	
} 






void Staircase:: stairsMoving1(Floor** floors){
	   Student* s=NULL;
	   for(int f=0; f<FLOORS;f++){
	   	cout<<"Floor number ------"<<f<<endl;
	   	s=search_f(f);
	   	//if there is space to the floor && the corridor of course
	   	while(floors[f]->getSpace()>0 && floors[f]->CorridorSpace()>0 && s!=NULL){
	   		//cout<<"floor has space"<<endl;
	   		//find the first one in stairs for the floor f
	      	//s=search_f(f);
	   		if(s!=NULL){
	   			exit(s);
	   			cout<<"s "<<s->getNum()<<endl;
	   			floors[f]->enter(s);
	   			floors[f]->enterCorridor(s);
	   		
			   }
	   		s=search_f(f);
	   		
		   }
		   //Corridor Moving
		   	floors[f]->CorridorMoving();	
	   }
} 


class Yard{
	int Cyard;
	int numOfStudents;
	Student** studentsInY;
	public:
		Yard(int Cy,int students=0):Cyard(Cy),numOfStudents(students){
		studentsInY = new Student*[Cyard];
	    for(int i=0; i<Cyard;i++){
	    	studentsInY[i]=NULL;
			
		}
		cout<<"yard has been created \n";
	}
		~Yard(){
		 delete[] studentsInY;
		 cout<<"yard has been destroyed \n";
			}
		void enter(Student* s);
		void exit(Student* s, int i);
		int getStudents(){
			return numOfStudents;
		}
		int getSpace(){
			return (Cyard-numOfStudents);
		}
		void printList();
		Student*exit();
		};

void Yard::enter(Student *s ){
    	s->setWhere(2);
    	if(studentsInY[numOfStudents]==NULL){
		studentsInY[numOfStudents]=s;
		s->print();
		cout<<" enters the Yard!"<<endl;
		numOfStudents++;}	
}





void Yard:: printList(){
	cout<<"printing yard"<<endl;
	for(int i=0; i <numOfStudents;i++){
		cout<<"student number "<<studentsInY[i]->getNum()<<"inside yard"<<endl;
	}	
}
Student* Yard::exit(){
	    Student* s=NULL;
		s=studentsInY[0];
//		cout<<" s "<<s->getNum()<<endl;
		studentsInY[0]=NULL;
		int n=(sizeof(studentsInY[0])*numOfStudents)/sizeof(studentsInY[0]);
  //   	cout<<"N "<< n<<endl;
	    Student* tmp=studentsInY[0];
        memmove(studentsInY,studentsInY+1,sizeof(Student*)*(n-1));
        studentsInY[n-1]=tmp;
        numOfStudents--;
        s->print();
        cout<<"exits yard!"<<endl;
        return s;
	
}








//================== school class===============================

class School{
	int maxN;
	int numOfStudents;
	Yard yard;
    Staircase staircase;
    Floor ** floors;
	Student** studentsIn; 
	public:
		
		//constructor
		School(int n, int Cy, int Cs,int Cf,int Ccorr,int Cclass  ,int students=0) : maxN(n), numOfStudents(students), yard(Cy), staircase(Cs) {
			
		floors = new Floor*[FLOORS];
		for(int i=0; i<FLOORS; i++){
		    floors[i] = new Floor(i,Cf,Ccorr,Cclass);
	     }
			
	    studentsIn = new Student*[maxN];
	    for(int i=0; i<maxN;i++){
	    	studentsIn[i]=NULL;
		}
		cout<<"A New School has been created!"<<endl;}
	
	    //general functions
	    bool  keepMoving();
		int getStudents();
		void printList();	
		void leftRotate();
		void printYard();
		void printStairs();
		void printFloors();
	    void enter1(Student* s ,int current);
	    void place();
	
	    //destructor
		~School() {   
	    	for(int i=0; i<FLOORS; i++)
				delete floors[i];
			cout<<"The School has been destroyed!"<<endl; 
			delete[] studentsIn;}
};


int School::getStudents(){
	return numOfStudents;
}




void School::enter1(Student* s ,int current){
	Student* t=NULL;
	//if there is space in the school
	if(numOfStudents<maxN && yard.getSpace()>0 && s!=NULL){
		s->setNum(current);
		s->setWhere(1);
		studentsIn[numOfStudents]=s;
	    s->print();
	    //cout<<" enters School!"<<endl;
		numOfStudents++;
		s->print();
	    cout<<" enters School!"<<endl;
		yard.enter(s);	}
       
       if(yard.getSpace()==0 || numOfStudents==maxN || s==NULL){
		while(staircase.getspace()>0 && yard.getStudents()>=1){
	    t=yard.exit();
	    //t->print();
	    //cout<<"exits yard!";
	    //yard.printList();
	    staircase.enter(t);	
	    }
	    if(staircase.getspace()==0 || (staircase.getspace()>0 && yard.getStudents()==0)){
	    	cout<<"-----------STAIRS MOVING------------"<<endl;
	        staircase.stairsMoving1(floors);
		}
	   }
	
}


bool School:: keepMoving(){
	if(yard.getStudents()>0 ){
		return true;
	}else{
		return false;
	}
}


void School ::place(){
	for(int i=0; i<FLOORS;i++){
		floors[i]->place();
	}
}



void School ::leftRotate(){
	int n=(sizeof(studentsIn[0])*numOfStudents)/sizeof(studentsIn[0]);
	//cout<<"N "<< n<<endl;
	Student* tmp=studentsIn[0];
    memmove(studentsIn,studentsIn+1,sizeof(Student*)*(n-1));
    studentsIn[n-1]=tmp;
	
}

void School::printList(){
	for(int i=0; i <numOfStudents;i++){
		cout<<"student number "<<studentsIn[i]->getNum()<<"inside school"<<endl;
	}
}


void School::printYard(){
	yard.printList();
}

void School::printStairs(){
	staircase.printList();
}

void School::printFloors(){
	for(int i=0; i<FLOORS;i++){
		floors[i]->print();
	}
}

//==============================end of school class=====================================




//==============================main function =============================================



int main (){
	//-----------------GETTING THE VALUES FROM THE USER-------------------------
	int N,Cyard,Cstair,Cfloor,Ccorr,Cclass;
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
	
	//---------------CREATING ARRAY OF STUDENTS---------------------------------
	Student** students;
	students = new Student*[N];
	for (int i=0; i<=N ; i++){
	    students[i] = new Student(i+1,rand()%CLASSES,rand()%FLOORS);
	    //students[i]->print();
	    //cout<<endl; 
	    }
	//--------------CREATING SCHOOL--------------------------------------------
	School school(N,Cyard,Cstair,Cfloor,Ccorr,Cclass);
    
    int studentsIn=0;
 
    int in=0;
    while (school.getStudents()<N  ){
    	cout<<"school students"<< school.getStudents()<<endl;
    	if(school.getStudents()<N){
		
    	school.enter1(students[studentsIn],studentsIn);
	    studentsIn++;}
	}	
	    //place
	    if(rand()%2==1){
	    	cout<<"Some professors are placed!!!"<<endl;
	    	school.place();
		}
		
		
		while(school.keepMoving()==true){
			school.enter1(NULL,studentsIn);
		}
	   
	        
	/*	     
    for (int i=0; i<N; i++) {
	    if(students[i]->isIN()==1){
	    students[i]->print();
	    cout<<endl;}
	}*/

   //easy printing but i also have functions to print through the objects 
    for(int i=0; i<N;i++){
    	if(students[i]->getWhere()==4){
    		students[i]->print();
    		if(students[i]->isIN()==1){
    			cout<<" is inside class "<<students[i]->getClass()<<"at floor"<<students[i]->getFloor()<<endl;
			}
			else{
				cout<<" is at corridor ,at floor"<<students[i]->getFloor()<<endl;
			}
    		
		}else if(students[i]->getWhere()==3){
				students[i]->print();
				cout<<"is inside the staircase!"<<endl;
		}
	}  
     
      
   
    //free students

	for (int i=0; i<N; i++) {
	    delete students[i];
	}
	delete[] students;

	return 0;
}












