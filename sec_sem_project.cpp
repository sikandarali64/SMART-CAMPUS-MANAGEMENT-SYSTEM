#include<iostream>
using namespace std;
class person{
	public:
		  string Teacher[6]={"Ravi kumar","Mohsin koodhar","Mam Irfana"};
		  
		  
    	  string name[15]={"zaheer","fazal","Ab haq","ilyan",
		  "hishmat","Ali","Mudasir","fayaz","sameer","sikandar"}; 
		  
		   
		  string id[15] ={"24cse10","24cse15","24cse48","24cse24",
		  "24cse14","24cse12","24cse59","24cse40","24cse03","24cse55"};
		  
		  
          string contact[15]={"0313-3407607","0312-3431034","0310-8315638",
		  "0321-3379342","049-7230823","0319-20782311","0349-4580737","0301-3241900",
		  "0316-37021103","0303-3398359"};
          
		  int total=10;
          char att[19];
          double percentage[15];
          double lectures=65;
          double part[47];
          char z[10];
    
 string Fname[10]={"Jahanzaib","Shahzaib","Asmatullah","Waliullah","zohaib"};
    string Fid[10]={"f101","f102","f103","f104","f105"};
    string Fcontact[10]={""};
    int ft=5;
    
    
        
		void P(){
			int Y;
			cout<<"WELCOME TO MANANGEMENT SYSTEM:"<<endl;
			cout<<"1.Students:"<<endl;
			cout<<"2.Faculty:"<<endl;
			cout<<"enter the choice:"<<endl;
			cin>>Y;
			
			if(Y==1){
				cout<<"WELCOME STUDENTS:"<<endl;
				int B;
				cout<<"1.chcek my account:"<<endl;
				cout<<"2.check My Registration:"<<endl;
				cout<<"enter the choice:"<<endl;
				cin>>B;
				
				if(B==1){
					string I;
					cout<<"enter your ID:"<<endl;
					cin>>I;
					
					for(int i=0;i<total;i++){
						if(id[i]==I){
							cout<<"ACCOUNT FOUND!"<<endl;
							cout<<"NAME: "<<name[i]<<endl;
							cout<<"ID: "<<id[i]<<endl;
							cout<<"Contact: "<<contact[i]<<endl;
							
							
						}
					}
					
					
				}else if(B==2){
					string Z;
					cout<<"enter your ID:"<<endl;
					cin>>Z;
					
				   for(int i=0;i<total;i++){
				   	if(id[i]==Z){
				   		cout<<"you are registered:"<<endl;
				   		cout<<"Name: "<<name[i]<<endl;
				   		cout<<"ID: "<<id[i]<<endl;
				   		cout<<"Contact: "<<contact[i]<<endl;
				   		
				   		
					   }else{
					   	cout<<"You are not Regsitered:"<<endl;
					   }
				   }
				}
				
			}else if(Y==2){
				cout<<"Welcome Fculty Members:"<<endl;
				int R;
				cout<<"1.Check Account:"<<endl;
				cout<<"2.check Registration:"<<endl;
				cin>>R;
				
				if(R==1){
					string D;
					cout<<"Enter ID:"<<endl;
					cin>>D;
					
					for(int i=0;i<ft;i++){
						if(Fid[i]==D){
							cout<<"ACCOUNT FOUND:"<<endl;
							cout<<"Name: "<<Fname[i]<<endl;
							cout<<"ID: "<<Fid[i]<<endl;
							
						}
						
					}
				}else if(R==2){
					string O;
					cout<<"Enter your Id:"<<endl;
					cin>>O;
					
					for(int i=0;i<ft;i++){
						if(Fid[i]==O){
							cout<<"Already Registered!:"<<endl;
							cout<<"Name:"<<Fname[i]<<endl;
							cout<<"ID: "<<Fid[i]<<endl;
							
						}
						
					}
					
				}
			}
			
    
    
    
			
		}
		
};
class library:public person{
	public:
		void L(){
			cout<<"WELCOME TO LIBRARY:"<<endl;
			int C;
			cout<<"1.Issue book:"<<endl;
			cout<<"2.Return book:"<<endl;
			cin>>C;
			
			if(C==1){
				int l;
				cout<<"1.Css books:"<<endl;
				cout<<"2.Programing Books:"<<endl;
				cout<<"3.Stories:"<<endl;
				cout<<"4.CDS:"<<endl;
				cout<<"Enter the choice:"<<endl;
				cin>>l;
				
				if(l==1){
					cout<<"CSS BOOKS SET:Total Books are:"<<endl;
					cout<<"1.English:"<<endl;
					cout<<"2.PS:"<<endl;
					cout<<"3.Islamiat:"<<endl;
					cout<<"4.Magzines:"<<endl;
					cout<<"5.Dawn:"<<endl;
					cout<<"Here total books(5) 1 book 1 Rupee Per day:"<<endl;
					int days;
						cout<<"Total Issues days(1 day 5 Rupee charge):"<<endl;
						cin>>days;
						int date;
						cout<<"enter the Return date:"<<endl;
						cin>>date;
						
						double charge;
						double rs=5;
						charge=days*rs;
						cout<<"Total charges for:"<<days<<"="<<charge<<endl;
						
						cout<<"You Must Have to submit Books on return date"
						" else extra charges will be added:"<<endl;
						
					
				     
				}else if(l==2){
					cout<<"Total Programing Books are:"<<endl;
					cout<<"1.C lnaguage :(by Herry):"<<endl;
					cout<<"2.C++ language :(by shardha Khapra):"<<endl;
					cout<<"3.Python :(by Rahul):"<<endl;
					cout<<"4.HTML :(by Amna):"<<endl;
					cout<<"5.CSS :(by Virat):"<<endl;
					int D;
					double Rs=5;
					double charges;
					cout<<"Total Programing Books(5):"<<endl;
					cout<<"enter the days:(1 day 5 rupees charges:"<<endl;
					cin>>D;
					
					charges=Rs*D;
					cout<<"Total charges for "<<D<<" days: "<<charges<<endl;
				}else if(l==3){
					cout<<"Here Total Stories are:"<<endl;
					cout<<"1."<<endl;
				}else if(l==4){
					cout<<"Heres Total CDS are:"<<endl;
					
				}else{
					cout<<"Please Enter the vailid choice:"<<endl;
				}
			}else if(C==2){
				int G,H;
				cout<<"enter the issue date of books:"<<endl;
				cin>>G;
				cout<<"Total days:"<<endl;
				cin>>H;
				
				double R,V;
				R=5;
				V=H*R;
				
				cout<<"Plaase First Pay the Fines Rs:"<<V<<endl;
				
				
				
				
			}else{
				cout<<"Please enter the correct choice:"<<endl;
			}
		}
		
};
class attendance:public person{
	public:
		attendance(){
        	cout<<"                     *=====COMPUTER SYSTEMS ENGINEERING" 
			" DEPARTMENT====*"<<endl;
		}
		void A(){
			cout<<"WELCOME TO ATTEDDDANCE SYSTEM:"<<endl;
			string c;
			cout<<"1.TEACHER:"<<endl;
			cout<<"2.FACULTY:"<<endl;
			cout<<"3.STUDENTS:"<<endl;
			cout<<"enter the choice accordingly:"<<endl;
			cin>>c;
			
			if(c=="1"){
				cout<<"WELCOME SIR:"<<endl;
				string j;
				cout<<"1.Register students:"<<endl;
				cout<<"2.Upload Attedance:"<<endl;
				cout<<"Enter the choice:"<<endl;
				cin>>j;
				
				if(j=="1"){
					cout<<"student Name: "<<endl;
					cin>>name[50];
					cout<<"Students ID: "<<endl;
					cin>>id[50];
					cout<<"Registration successfully:"<<endl;
					total++;
					cout<<"Now Total Registered students is "<<total<<endl;
					
					
				}else if(j=="2"){
					cout<<"Thanks for Uplodaing attendance:"<<endl;
					for(int i=0;i<total;i++){
						cout<<"Name: "<<name[i]<<endl;
						cout<<"ID :"<<id[i]<<endl;
						cout<<"Today He/She Present Or Abesent:"<<endl;
						cin>>att[i];
						cout<<"How many He/She attend lectures(65):"<<endl;
						cin>>part[i];
						percentage[i]=(part[i]/lectures)*100;
						cout<<"Now your Attendance :"<<percentage[i]<<"%"<<endl;
						
						
						
					}
			    }else{
			    	cout<<"Wrong choice:"<<endl;
				}
					
					
				
			}else if(c=="2"){
				cout<<"WELCOME FACULTY MEMBER:"<<endl;
				string b;
				cout<<"1.Registration:"<<endl;
				cout<<"2.Upload Attendance:"<<endl;
				cout<<"enter the choice:"<<endl;
				cin>>b;
				
				if(b=="1"){
					cout<<"Faculty Member Name: "<<endl;
					cin>>Fname[10];
					cout<<"enter the Id number:"<<endl;
					cin>>Fid[10];
					ft++;
					cout<<"Registration succefully:"<<endl;
					cout<<"Now total faculty Members are: "<<ft<<endl;
				}else if(b=="2"){
					string F,f;
					cout<<"Upload your Attendance:"<<endl;
					cout<<"Enter your name:"<<endl;
					cin>>F;
					cout<<"Enter your Id number:"<<endl;
					cin>>f;
					string A;
					
					for(int i=1;i<=ft;i++){
						if(Fname[i]==F){
							cout<<"Name: "<<Fname[i]<<endl;
							cout<<"ID: "<<Fid[i]<<endl;
							cout<<"Contact: "<<Fcontact[i]<<endl;
							cout<<"Today present or Absent(P/A):"<<endl;
							cin>>A;
							double O;
							cout<<"Total Present days out of(30):"<<endl;
							cin>>O;
							
							double L=30,K;
							K=(O/L)*100;
							cout<<"YOUR Attendance:"<<K<<"%"<<endl;
						
							
							
						}
					}
					
					
					
				
				
				}
				
			}else if(c=="3"){
				string g;
				cout<<"WELCOME STUDENTS:"<<endl;
				cout<<"        "<<endl;
			    cout<<"1.About My self:"<<endl;
				cout<<"2.check attendance for eligibility:"<<endl;
				cout<<"enter the choice:"<<endl;
				cin>>g;
				if(g=="0"){
					string Nn,Nni;
					cout<<"Enter your name:"<<endl;
					cin>>Nn;
					cout<<"enter your ID number:"<<endl;
					cin>>Nni;
					if(Nn==name[47]&&Nni==id[47]){
						cout<<"Searching..."<<endl;
						cout<<"Name: "<<Nn<<endl;
						cout<<"ID: "<<Nni<<endl;
						
					}
				}else if(g=="1"){
					cout<<"Check your name ,id number,contact,attendance"<<endl;
					string E;
					cout<<"enter your id number(i-e 24cse100):"<<endl;
					cin>>E;
					
					bool foun=false;
					for(int i=1;i<=total;i++){
						if(id[i]==E){
							foun=true;
							cout<<"Name: "<<name[i]<<endl;
							cout<<"ID: "<<id[i]<<endl;
							cout<<"contact: "<<contact[i]<<endl;
							cout<<"Attendance: "<<percentage[i]<<endl;
						}
						
					}
				}else if(g=="2"){
					string st,stid;
					cout<<"Check Attendance:"<<endl;
					cout<<"enter your name:"<<endl;
					cin>>st;
					cout<<"enter your id number:"<<endl;
					cin>>stid;
					
					bool found=false;
					
					for(int i=0;i<total;i++){
						if(name[i]==st && id[i]==stid){
							found=true;
							cout<<"Name :"<<name[i]<<endl;
							cout<<"ID :"<<id[i]<<endl;
							cout<<"Your attendnace is :"<<percentage[i]<<endl;
							
							if(percentage[i]>=75){
								cout<<"Congrates! your are eligible for"
								" Exams:"<<endl;
								
							}else if(percentage[i]>=60 && percentage[i]<=74){
								cout<<"You are in condonation:"<<endl;
								
							}else {
								cout<<"Sorry! you are not Eligible:"<<endl;
							}
							break;
						}
						
					}
					if(!found){
						cout<<"Student not found May be attendance not "
						"upload yet:"<<endl;
						
					}
				}else{
					cout<<"Wrong choice Try again!"<<endl;
				}
				
			}else{
				cout<<"Wrong choice Try again!"<<endl;
			}
		}
		
		void d(){
			string T;
			cout<<"Welcome for Reading Instructions:"<<endl;
			cout<<"1.Istruction for Teachers:"<<endl;
			cout<<"2.Instruction for Faculty:"<<endl;
			cout<<"3.Istruction for Students:"<<endl;
			cout<<"4.About Project:"<<endl;
			cout<<"Enter the choice That You want to Read:"<<endl;
			cin>>T;
			
			if(T=="1"){
				cout<<"Welcome Sir For Reading Instructions:"<<endl;
				cout<<"1.Teachers Only Upload Attendance:"<<endl;
				cout<<"2.Teachers Can Be Register Students:"<<endl;
				cout<<"3.Teacher Must Have remember the Id number"
				"else he will not be allowed to enter the project:"<<endl;
				cout<<"4.Teacher himself/herself can be update his/her Name"<<endl;
				cout<<"5.If Teachers have any confucsion he/she can be contact"
				"with the faculty:"<<endl;
				
			}else if(T=="2"){
				cout<<"Welcome Faculty Members:"<<endl;
				cout<<"1.you can not remove or add any students without permision "
				"of teachers:"<<endl;
				cout<<"2.Only you can upload him/her Attendance:"<<endl;
				cout<<"3.you can check your attendance:"<<endl;
	
			}else if(T=="3"){
				cout<<"Welcome Students:"<<endl;
				cout<<"1.Only You can check your Attendance:"<<endl;
				cout<<"2.You can not upload attendance,register etc..."<<endl;
				cout<<"3.you can check  Eligibility for Exams:"<<endl;
				
			}else if(T=="4"){
				cout<<"ABOUT PROJECT:"<<endl;
				cout<<"1.Developer: Zaheer Ahmed Chachar:"<<endl;
				cout<<"2.Usage: Advanced OOPS concepts like:"<<endl;
				cout<<"(a): Classes:"<<endl;
				cout<<"(b): Objects:"<<endl;
				cout<<"(c): Constructors:"<<endl;
				cout<<"(d): Destructors:"<<endl;
				cout<<"(e): Inheritance:"<<endl;
				cout<<"(f): Polymorphism:"<<endl;
				cout<<"(g): Functions: etc..."<<endl;
				

			}else{
				cout<<"Wrong choice Try again!"<<endl;
			}
			
		}
		
	
		
};
int main(){
	
	person s;
	library l;
	attendance a;
	
	
	string choice; 
	cout<<" "<<endl;
	cout<<"                             ### SMART CAMPUS MANAGEMENT SYSTEM ###"<<endl;
	
	
	do{
	cout<<"MAIN MENU:"<<endl;
	
	
	cout<<"1. MANANGEMENT SYSTEM:"<<endl;
	cout<<"2. LIBRARY SYSTEM:"<<endl;
	cout<<"3. ATTENDANCE SYSYTEM:"<<endl;
	cout<<"4. Instructions Must Read:"<<endl;
	cout<<"   enter your choice:"<<endl;
	cin>>choice;
	
	if(choice=="1"){
		s.P();
	}else if(choice=="2"){
		l.L();
	}else if(choice=="3"){
		a.A();
		
	}else if(choice=="4"){
		a.d();
	}else{
		cout<<"Wrong Choice Try again:"<<endl;
	}
  }while(choice!="4");
}
