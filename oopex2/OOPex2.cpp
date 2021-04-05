#include <iostream>
#include <cstdlib>
#include <string>
#include<ctime>
#include <bits/stdc++.h> 

#define StudentsPerClass 32





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



using namespace std;

int K;

class Student{   
	
	    
		int stud_Num;
		int classNum;
		char sex;
		bool hasCouple;
		bool quiet;
		const char* name;
		const char* surname;
		
		
	public:
		Student(int Sn,int Cn, int Sex):stud_Num(Sn),classNum(Cn),sex(Sex){ 
		   hasCouple=false;
		   quiet=true;
		   name=names[rand()%66];
		   surname=surnames[rand()%120];
		   
		   cout<<"name :"<<name<<", surname:"<<surname<<endl;
		   
		 
		}
	
		bool has_Couple(){
			return hasCouple;
		}
		
		void setCouple(bool x){
			hasCouple=x;
		}
		int getClass(){ 
			return this->classNum;
		}

		void setNum(int num){
			this->stud_Num=num;
		}
		int getNum(){
			return this->stud_Num;
		}
        char get_sex(){
        	return sex;
		}
		
		bool isQuite(){
			return quiet;
		}
		
		void beingQuite()
		{
			quiet=true;
		}
		
		void beingMessy(){
			quiet=false;
		}
		
		void printName(){
			cout<<" "<<name <<" "<<surname;
		}
		bool isBoy(){
			return true;
		}
		~Student(){} 
		
}; 





struct Couple{
 int classNum;
 int coupleNum;
 int changeType;
 Student* s1;  
 Student* s2;  
 bool hasChanged;
 public:
 Couple* next;
	
	Couple(Student* stud1,Student* stud2,int number ,Couple* n=NULL):s1(stud1),s2(stud2),coupleNum(number),next(n){
		changeType=1;
		hasChanged=false;
		classNum=stud1->getClass();
	//	cout<<" student number "<< s1->getNum()<<" and student "<< s2->getNum()<<"are now a coupple"<<endl;
		
	}
	
	void  getBoy(Student** x){

		*x=s2;
		

	}
	
	Student* getGirl(){
		return s1;
	}
	
	void setBoy(Student* boy){
		s2=boy;
		
	}
	
	void setGirl(Student* girl){
		s1=girl;
	}
	
	void set_hasChanged(bool x){
		hasChanged=x;
	}
	
	
	bool get_hasChanged(){
		return hasChanged;
	}
	
	
	
	int getNumber(){
		return coupleNum;
	}
	
	
	void setChangeType(int change){
		changeType=change;
	}
	
	int getClass(){
	
	    return classNum;}
	
	int getChangeType(){
		return changeType;
	}
	int isMessy(){
		if(s1->isQuite()==false && s2->isQuite()==false){
			return 1;
		}
	}
	void PrintCouple(){
		cout<<changeType<< " Couple["<< coupleNum  <<"]:"<<" ( "<<s1->getNum()<<"-"<<s1->get_sex();
		s1->printName();
		cout<<", quiet ::"<<s1->isQuite()<<", "<<" "<<s2->getNum()<<"-"<<s2->get_sex();
		s2->printName();
		cout<<", quiet ::"<<s2->isQuite()<<")"<<endl;;
		
	}       

};




class ClassLine{
	Couple* start;
	int size;
	int classNum;
	int messyPoints;
	public:
	
	ClassLine(int n=-1):start(NULL),size(0),classNum(n){
		messyPoints=0;
		cout<<"Class_line number"<< n<<" has been created"<< endl;
	}
	
	
    void pushFront(Student* s1,Student* s2) {
    	start = new Couple(s1,s2,size,start);
 		size++;
    }
  void print() 
       {     cout<<"Messy Points: "<<messyPoints<<endl;
             Couple* t = start;
             while (t != NULL) {
              t->PrintCouple();
              t = t->next;
 } }


  void print1(int Tq,int Tm) 
       {     cout<<"Messy Points: "<<messyPoints<<endl;
       
       
            int x=Tq*StudentsPerClass/100;
            int y=Tq*StudentsPerClass/100;
            if(x>=messyPoints){
            	cout<<"what a quiet class"<<endl;
            	
			}else if(y<=messyPoints){
				cout<<"what a messy class!"<<endl;
			}
			else{
				cout<<"please be quiet!"<<endl;
			}
       
       
       
             Couple* t = start;
             while (t != NULL) {
              t->PrintCouple();
              t = t->next;
 } }


    void setMessyPoints(){
    	Couple* t=start;
    	Student* temp=NULL;
    	while(t!=NULL){
    		if(t->getChangeType()==3 || t->getChangeType()==2){
    			//2 students are going to change class
				//so 2+2
				
				messyPoints=messyPoints+4; 
    			
			}
			else if (t->getChangeType()==1){
				
				t->getBoy(&temp);
				if(temp->isQuite()==0){
					messyPoints++;
				}
				temp=t->getGirl();
				if(temp->isQuite()==0){
					messyPoints++;
				}
			}
			
			t=t->next;
		}
    	
    	
	}




	int getMessyPoints(){
		return messyPoints;
	}

    
    
    
    
    void InitializeForNextRound(){
    	
    	Couple* t = start;
            while (t != NULL) {
                t->set_hasChanged(false);
                t=t->next;
			  }
              
	}
    	
	


    void setChangeType(int change,int pos){
    	    Couple* t = start;
             while (t != NULL) {
              if(t->getNumber()==pos){
              	t->setChangeType(change);
              	return ;
			  }
              t = t->next;
	}
}





    Couple* GetCoupleTochangeClass(int type){
    	     Couple* t = start;
    	    
             while (t!= NULL) {

             if((t->getChangeType()==type) && t->get_hasChanged()==false){
             	cout<<"edv"<<endl;
             	t->set_hasChanged(true);
             	return t;
			 }
              t = t->next;
    }
    	return NULL;
	}

    void Change_type_marker(){
    	int messyCouples=0;
    	int couples[size];
    	for(int i=0;i<size;i++){
    		couples[i]=0;
		}
		Couple* t = start;
        while (t != NULL) {
        couples[t->getNumber()]=t->isMessy();
        if(couples[t->getNumber()]==1){
        	messyCouples++;
		}
        t = t->next;	
	}
    if(messyCouples>2){
    	
    	int i=0;
    	
    	while(i<size){
    		if(couples[i]==1){
    			//messy couple detected
    			setChangeType(2,i);
			
    		if(couples[i]==1 && couples[i+1]==1 && couples[i+2]==1){
    			//for starters this means that we have 2 or more consecutive messy couples
    			setChangeType(3,i);
    			setChangeType(3,i+1);
    			setChangeType(3,i+2);
    			i=i+3;
    			
    			while(couples[i]==1){
    				setChangeType(3,i);
    				i++;
				}	
			}
			i++;
    	}else if(couples[i]==0){
    		i++;
		}
		}
	}}
	
	
	Student* PermutateWithRarndomStudent(Student* s){
		int randomCouple=rand()%size;
		
		cout<<" the couple that was randomly chossen is"<<randomCouple<<"of class"<<classNum<<endl;
		
		Student* temp=NULL;
		Couple* t = start;
    	    
             while (t!= NULL) {
              t->PrintCouple();
             if(t->getNumber()==randomCouple){
             	cout<<t->getNumber()<<endl;
             	cout<<s->getNum()<<endl;
             	
             	if(s->get_sex()=='B'){
             	
             		 t->PrintCouple();
             	     t->getBoy(&temp);
             		cout<<"the retuning value is"<<temp<<endl;
             		cout<<"ghcyhugecyhugce"<<temp->getNum()<<endl;;
             		
             		t->setChangeType(1);
             		
             		
             		//that student is also going to change so is ging to be quite anyway 
             		temp->beingQuite();
             		
             		
             		t->setBoy(s);
				 }else if (s->get_sex()=='G'){
				 	temp=t->getGirl();
				 	cout<<"vwvewvwvew"<<temp->getNum()<<endl;;
				 	//that student is also going to change so is ging to be quite anyway 
             		temp->beingQuite();
				 	
				 	t->setChangeType(1);
				 	t->setGirl(s);
				 
				 }
                 cout <<"the student who was randomly picked is"<<temp->getNum()<<"ánd was in class"<<classNum<< "and belonged to the couple number "<<t->getNumber()<<endl;;
                t->PrintCouple();
             	return temp;			
	}
	t=t->next;
		
}}
	
	
	
	
	
	
	
	
	
	
 	
    int getLineNumber(){
    	return classNum;
	}
	
    int getSize()  { return size; }
	
	~ClassLine(){
		Couple* t1 = start;
        while (t1 != NULL) {
        Couple* t2 = t1;
        t1 = t1->next;
        delete t2;
 }
		cout<<"Class_line number"<< classNum<<" has been destroyed!"<< endl;
	}
};





//the class object 



class Class{
	int classNumber;
	int NumberofStudents;
	int studentsInCouple;
	int  messPoints;
	ClassLine* line;
//	Class * next;
	
	
	public:
		Class * next;
		//constructor
		Class(int number,Class *Next ,int students=0):classNumber(number),next(Next),NumberofStudents(students){
			messPoints=0;
			studentsInCouple=0;
			line=new ClassLine(number);
			cout<<"Class number "<< classNumber << " has been created !" <<endl;	
		}
		
		
		
		void addCouple(Student* s1,Student*s2){
			line->pushFront(s1,s2);
			studentsInCouple=studentsInCouple+2;
			
		}
		
		
		void printLine(){
			cout<<"-------Class "<<line->getLineNumber()<<" Line------"<<endl;
			cout<<"Students in line: "<<studentsInCouple<<endl;
			line->print();
		}
		
		void printLine1(int Tq,int Tm){
			cout<<"-------Class "<<line->getLineNumber()<<" Line------"<<endl;
			cout<<"Students in line: "<<studentsInCouple<<endl;
			line->print1(Tq,Tm);
		}
		
		void mark(){
			line->Change_type_marker();		
		}
		
		
		
		
		Couple* coupleToChange(int type){
		      Couple* temp=line->GetCoupleTochangeClass(type);   
		      if(temp!=NULL){
			  cout<<"Couple to change"<<endl;
			  temp->PrintCouple();
			  return temp;
			}
			
			return NULL;
			}
		
		
		void incStudents(){
			NumberofStudents++;
		}
		int getStudents(){
			return NumberofStudents;
		}
		
		//getting the class number
		int get_ClassNumber(){
			return classNumber;
		}
		
		
		
	    Student* PermutateWithRarndomStudent(Student* s)
	    {
	    	//now lest pick random student of random couple 
	    	
	    return 	line->PermutateWithRarndomStudent( s);
	    	
		}
		
		
		void setMessyPoints(){
			line->setMessyPoints();
		}
		
		
		int getMessyPoints(){
			line->getMessyPoints();
		}
	
        void InitializeForNextRound(){
        	
        	line->InitializeForNextRound();
		}
	
	
	
};





//the List of classes -----------------------------------------------------------------------------------------------------



class ClassList{
	Class* start;
	int size;
	
	
	public:
		
	//constructor
	ClassList():start(NULL),size(0){
		
		//cout<<n<<endl;		
		cout<<"The list of classes has been constructed!"<<endl;
	}
	
	//put a class in the list 
    void pushFront(int classNum) {
    	start = new Class(classNum, start);
 		size++;
 		cout<<"Class number "<< start->get_ClassNumber() <<" has been add to class_list" <<endl;
 	//	cout<<"size now is "<<size<<" !"<<endl;
		     }
    
    //returning the size of the list 
    int getSize()  { return size; }
    
    //printing the current situation of the classes 
    

 
 
    int getStudents(int i){   
		Class* t1 = start;
        while (t1 != NULL) {
        if(t1->get_ClassNumber()==i){
        	return t1->getStudents();
	}
	 t1 = t1->next;
}
}
    void incStudents(int i){	
//	cout <<"increase"<<endl;	
    	Class* t1 = start;
    //	cout<<t1->get_ClassNumber()<<endl;
        while (t1 != NULL) {
     //   cout<<"2"<<t1->get_ClassNumber()<<endl;
        if(t1->get_ClassNumber()==i){
        //	cout<<t1->get_ClassNumber()<<endl;
  //      	cout <<"increase"<<endl;
        	t1->incStudents();
        	break;
	//	}else{
		//	cout<<"no"<<endl;
		}
		 t1 = t1->next;
 }
    	
	}
	
	void printClasses(){
		cout<<"printing classes"<<endl;
		Class* t1=start;
		while(t1!=NULL){
			cout<<"class number"<<t1->get_ClassNumber()<<endl;
			
			t1=t1->next;
		}
		
	}
	
	
	//printing the simulation currently 
	
	
	void printSimulation(int Tq,int Tm){
		cout<<"=========================SIMULATION CURRENTLY==============================="<<endl;
		Class* t1=start;
		while(t1!=NULL){
			cout<<"Class number[ "<<t1->get_ClassNumber()<<" ]"<<endl;
			t1->printLine1( Tq, Tm);
			t1=t1->next;
		}	
		
	}
	
	
	
	
	
	
	
	void MarkType(){
		//for each class lets find and mark the messy couples
	//	cout<<"lets see what type of changes we need to do to the couples"<<endl;
		Class* temp=start;
		while(temp!=NULL){
		//	cout<<"Printing line before Types"<<endl;
		//	temp->printLine();
		//	cout<<"Getting Types"<<endl;
			temp->mark();
		   // cout<<"Printing line after Types"<<endl;
		//	temp->printLine();
			temp=temp->next;
		}
	}
	
	
	
	
	Student* PermutateWithRarndomStudent(Student* s){
		//pick random class except student's
		
		
		cout<<"picking random student to exchange him with "<<s->getNum()<<endl;
		int randomClass=rand()%K;
		while(randomClass==s->getClass()){
			randomClass=rand()%K;
		}
		Class* temp=start;
		while(temp!=NULL){
            if(temp->get_ClassNumber()==randomClass){
            	break;
			}
			temp=temp->next;
		}
		
		//now lets pick random student
		
		s=temp->PermutateWithRarndomStudent(s);
	
		return s;
		
		
	}
	
Student* PermutateToNextClass(Student* s,int currentClass){
	//fisrt of all lest find the  next class
	int nextClass=currentClass+1;
	if(currentClass==(K-1)){
		nextClass=0;
	}
	Class* temp=start;
	
		while(temp!=NULL){
            if(temp->get_ClassNumber()==nextClass){
            	break;
			}
			temp=temp->next;
		}	
		
	//now lets pick random student
    s=temp->PermutateWithRarndomStudent(s);

	return s;
	
}
	
	
Student* PermutateInClass(Student* s,int currentClass){
		Class* temp=start;
	
		while(temp!=NULL){
            if(temp->get_ClassNumber()==currentClass){
            	break;
			}
			temp=temp->next;
		}
		s=temp->PermutateWithRarndomStudent(s);
		return s;	
	
}	
	
	
	
	
	
	
	
	
	
	
	void alakseTmima(Couple* t){
		
		
		//get the  students of the noizy couple
		cout<<"The couple that we are going to change is:"<<endl;
		t->PrintCouple();
		//lets get the students
		
		Student* boy;
		t->getBoy(&boy);
		Student* girl=t->getGirl();
		
		
		cout<<" the boy of the couple is student number "<<boy->getNum()<<endl;
		cout<<" the girl of the couple is student number "<<girl->getNum()<<endl;
		//they are going to change class so now they will be quite 
		
		boy->beingQuite();
		girl->beingQuite();
		
		
		t->PrintCouple();
		boy=PermutateWithRarndomStudent(boy);
		girl=PermutateWithRarndomStudent(girl);
		
		
		
		cout<<"the students randomly chooseb were:"<< boy->getNum()<<" && "<<girl->getNum()<<endl;
		
		t->setBoy(boy);
		t->setGirl(girl);
		
		
		cout<<"the couple after the change has formulated like that"<<endl;
		t->setChangeType(1);
		t->PrintCouple();
				
	}
	
	
	
	void epomenoTmima(Couple* t){
		cout<<"The couple that we are going to change is:"<<endl;
		t->PrintCouple();
		Student* boy;
		t->getBoy(&boy);
		Student* girl=t->getGirl();
		cout<<" the boy of the couple is student number "<<boy->getNum()<<endl;
		cout<<" the girl of the couple is student number "<<girl->getNum()<<endl;
		//they are going to change class so now they will be quite 
		
		boy->beingQuite();
		girl->beingQuite();
		t->PrintCouple();
		
		//get the current class of the students != original class of the students 
		int currentClass=t->getClass();
		
		//now lets change them with random students of the next class
		
		boy=PermutateToNextClass(boy,currentClass);
		girl=PermutateToNextClass(girl,currentClass);
		
				
		cout<<"the students randomly chooseb were:"<< boy->getNum()<<" && "<<girl->getNum()<<endl;
		
		t->setBoy(boy);
		t->setGirl(girl);
		
		t->setChangeType(1);
		cout<<"the couple after the change has formulated like that"<<endl;
		
		t->PrintCouple();
					
	}
	
	
	
	void insideChange(Couple* t){
		int currentClass=t->getClass();
		Student* boy;
		t->getBoy(&boy);
		Student* girl=t->getGirl();
		if(boy->isQuite()==0){
			boy->beingQuite();
			boy=PermutateInClass(boy,currentClass);
			t->setBoy(boy);
			if(girl->isQuite()==0){
				girl->beingQuite();
				girl=PermutateInClass(girl,currentClass);
			    t->setGirl(girl);
				
			}
		}else if(girl->isQuite()==0){
			girl->beingQuite();
			girl=PermutateInClass(girl,currentClass);
			t->setGirl(girl);
			if(boy->isQuite()==0){
			boy->beingQuite();
			boy=PermutateInClass(boy,currentClass);
			t->setBoy(boy);}
		}
		
		
	}
	
	
	
	
	
	
	
	void setMessyPoints(){
		
		Class* temp=start;
		
		while(temp!=NULL){
		temp->setMessyPoints();	
		
		//cout<<"MESSY POINTS "<<temp->getMessyPoints()<<endl;
		temp=temp->next;
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	void doPermutationsBetweenClasses(){
		cout<<"---------------------------LETS DO PERMUTATIONS ------------------"<<endl;
		Class* temp =start;
		
		while(temp!=NULL){
			
			
			cout<<"Printing line before permutations"<<endl;
			temp->printLine();
			cout<<"Class number"<<temp->get_ClassNumber()<<endl;
			Couple* t=temp->coupleToChange(3);
		    if(t!=NULL){t->PrintCouple();}
		    //------------------------------------
			while(t!=NULL)	{
		
			if(t!=NULL && t->getChangeType()==3){
			//i have the couple of the class that its students need to change class
		    alakseTmima(t);
			}
	        t=temp->coupleToChange(3);}
		    cout<<"Printing line after permutations"<<endl;
			temp->printLine();
			temp=temp->next;
		
	}
		//----------------------------------------------------------------
		 temp =start;
		
		while(temp!=NULL){
			
			
			cout<<"Printing line before permutations"<<endl;
			temp->printLine();
			cout<<"Class number"<<temp->get_ClassNumber()<<endl;
			Couple* t=temp->coupleToChange(2);
		    if(t!=NULL){t->PrintCouple();}
		    //------------------------------------
			while(t!=NULL)	{
			if (t!=NULL && t->getChangeType()==2){
			//sto epomeno
			cout<<"edww"<<endl;
		    epomenoTmima(t);
			}
		    t=temp->coupleToChange(2);
	
	   }
	
		    cout<<"Printing line after permutations"<<endl;
			temp->printLine();
			temp=temp->next;
		}		
		
	}
	
	void doPermutationsInsideClass(){
		Class* temp =start;
		while(temp!=NULL){
		
		
		Couple* t=temp->coupleToChange(1);
		if(t!=NULL){t->PrintCouple();}
		    //------------------------------------
			while(t!=NULL)	{
			if(t!=NULL && t->getChangeType()==1){
			//i have the couple of the class that its students need to change class
		    insideChange(t);
			}
	        t=temp->coupleToChange(1);}
		    cout<<"Printing line after permutations"<<endl;
			temp->printLine();	
		temp=temp->next;	
		}
		
	}
	

	
	void addCouple(Student* s1,Student* s2){
		int classnum=s1->getClass();
		Class* t1 = start;
        while (t1 != NULL) {
        if(t1->get_ClassNumber()==classnum){
        //put them to the sequence of this particular class 
        t1->addCouple(s1,s2);
        	break;}
		 t1 = t1->next;
    }
	}
	
	void InitializeForNextRound(){
		
		Class* temp=start;
		
		while(temp!=NULL){
			
			temp->InitializeForNextRound();
			
			temp=temp->next;
		}
	}
	
	
	
	

	//destructor
	
	~ClassList(){
		Class* t1 = start;
        while (t1 != NULL) {
        Class* t2 = t1;
        t1 = t1->next;
        delete t2;
 }
		cout<<"Class_List has been destroyed!"<< endl;
	}	
};



















int main (){
	
   int k,L,Tq,Tm;
   cout<<"Give me K"<<endl;
   cin>>k;
   K=k;
   cout<<"Give me L"<<endl;
   cin>>L;
   cout<<"Give me Tquiet"<<endl;
   cin>>Tq;
   cout<<"give me Tmessy"<<endl;
   cin>>Tm;


	//create students for K Classes
	
	int  boy=1;
    //create the classes
    //and within the classes i intiliaze the student sequence for every class
    ClassList* classes=new ClassList();
    
    //DID
    for(int i=K-1; i>=0; i--){
    	classes->pushFront(i);
    //	cout<<"here"<<endl;
    	
	}
	//create students for K Classes
	//girls and boys are the same number in each class
	Student** students;
	students = new Student*[StudentsPerClass*K];
	int c=0; //c for class
    for(int i=0; i<StudentsPerClass*K;i++){
    	if(classes->getStudents(c)==StudentsPerClass){
    //		cout<<"this class is full lets go to the next one "<<endl;
    		c++;
		}
		if(boy==1){
		students[i] = new Student(i,c,'G');
	  //  cout<<"student number" << students[i]->getNum()<<",its a "<<students[i]->get_sex()<< " and belongs to class"<< students[i]->getClass() <<endl;
	    classes->incStudents(c);
	   // cout <<classes->getStudents(c)<<endl;
		boy=0;
		}
		else if(boy==0){
		students[i] = new Student(i,c,'B');			
       	//cout<<"student number" << students[i]->getNum()<<",its a "<<students[i]->get_sex()<< " and belongs to class"<< students[i]->getClass() <<endl;
       	classes->incStudents(c);
       	//cout <<classes->getStudents(c)<<endl;
		boy=1;
			}		
	}
    
    //lets create the couples and add them to each sequence
    
    
    
// for starters lets assume boys and girls are even 
//lets create the lines th the starting point of the simulation
 	for(int i=0;i<StudentsPerClass*K;i++){
 	  if(students[i]->get_sex()=='G' && students[i+1]->get_sex()=='B' && students[i]->getClass()==students[i+1]->getClass()){
 	  	//then make them a couple 
 	  	
 	  	//cout <<"we have a couple"<<endl;
 	  	classes->addCouple(students[i],students[i+1]);
 	  	
 	  	i++;
	   }
  	
  	
  }
    

    //now lets print the current situation ot the classes and theier lines
   // classes->printSimulation();


     
    int nums[StudentsPerClass*K] ;
    for(int i=0;i<StudentsPerClass*K;i++){
    	 nums[i]=i;
	}
    std::random_shuffle(nums, nums + StudentsPerClass*K);



//}
    

    int messyStudents=0;
    
    classes->printSimulation(Tq,Tm);
    
    //continue the simulation for L times
    
    for(int i=1; i<=L;i++){
	
	cout <<"---------------------TIME -------------"<<i<<endl;
	
	
	std::random_shuffle(nums, nums + StudentsPerClass*K);

    //lets pick random number of students to be messy
   
     messyStudents=0;
	srand(time(0));
    messyStudents=(rand()%StudentsPerClass*K)+1; 

    cout << "Messy students" <<messyStudents<< "\n"; 
    for(int i=0; i<messyStudents;i++){
    	
  //   cout << "The random student is: "<<nums[i]<< endl;
     students[nums[i]]->beingMessy();
    	
	}
	
	
	cout<<"BEFORE CHANGES============================================================================================="<<endl;
	
	classes->printSimulation(Tq,Tm);
    classes->MarkType();
    classes->setMessyPoints(); 
    classes->doPermutationsBetweenClasses();
    classes->doPermutationsInsideClass() ;
    cout<<"AFTER CHANGES============================================================================================="<<endl;
    classes->printSimulation(Tq,Tm);
    
    classes->InitializeForNextRound();

}

    delete classes;
	
	return 0;
}

