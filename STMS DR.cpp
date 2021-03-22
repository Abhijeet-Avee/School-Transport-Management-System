#include<fstream>
#include<iomanip>
#include<windows.h>
#include<conio.h>
#include <ctype.h>
#include<stdlib.h>
#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
void gotoXY(int x, int y); 								//custom function for windows cursor movement
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
int std_num,stf_num;
static int a;       									//declaration of static variable to count number of registrations
class staff_login;										//class specifications
class student_login;
class register_now
{
	string name[10];
	public:
		int notice();
		int instructionsform();
		int registration_form();
		int confirmform();
		int routes();
		friend student_login;							//friend function
		friend staff_login;								//friend function
};
class student_login 
{
	public:
		int login();
		int allotmentform();
		int contactdetails();
		int complaints();
		friend register_now;							//friend function
};
class staff_login 
{
	public:
		int login();
		int complaintbox();
		int notice();
		int allot_route();
};
int staff_login::login()						// Login function for staffs
{
	staff_login s1;
	int u;
	string a[100],user1,user2,user3;
	char line[80];
	system("cls");										// clear console screen 
	cout<<"\n\n\n\n\n\n\n\n\n\n                    USERNAME:";
	cin>>user1;
	int i=0;
	char pwd[5];							
	cout<<"                    PASSWORD:";
	while(i<4)	
	{
		pwd[i]=getch();
		putchar('*');
		++i;
	}
	int j=0;
	user2=pwd;
	user3=user1+user2;							//username+password
	ifstream fil5;
	fil5.open("login.txt",ios::out);			//open file using ifstream 
	while(fil5)
	{
		fil5.getline(line,80);
		a[j]=line;
		j++;
	}
	for(int k=0;k<50;k++)
	{
		if(a[k]==user3)							// user login credentials authentication
		{
		while(1)
		{
			system("cls");
			cout<<"\n\n WELCOME TO "<<user1;
			cout<<"\n\n\n\n\n\n                     1.Complaint Box"<<"\n                     2.Edit notice";
			cout<<"\n                     3.Routes with alloted staff"; 
			cout<<"\n                     4.To LOGOUT";
			cout<<"\n\n\n Select your option";
			cin>>u;
			switch(u)
			{
				case 1:system("COLOR 5F");			//calling batch command color using function system() to change background color
				s1.complaintbox();
						 break;
				case 2:system("COLOR 5F");
				s1.notice();
						break;
				case 3:system("COLOR 5F");
				s1.allot_route();
						break;
				case 4:system("COLOR 5F");
				system("cls");
						cout<<"\n\n\n\n\n\n\n           LOADING PLEASE WAIT ... ";
						Sleep(500);
						return 0;
				break;
				default:return 0;
			}
		}
	}
}
	system("cls");
		cout<<"\n\n\n      SORRY,"
			<<"\n      invalid username or password";
		Sleep(300);
	return 1;
}
int staff_login::notice()				// Function to edit notices accessible to staffs only
{
	system("cls");
	fstream fin;
	fin.open("program.txt",ios::out | ios::app );
	fin<<endl;							// writing newline character to begin editing from a new line
	string mystr;
   	getline (cin, mystr);
  	cout << "Enter the Notice :";
  	getline (cin, mystr);
  	fin<<mystr;							// Updating notices list
  	cout<<"\n\n\n\nEnter any key to return main menu :";
  	getch();
  	return 1;
}

int staff_login::complaintbox()			//function to preview complaints filed
{
	char ch;
	system("cls");
	ifstream fin6;
	fin6.open("complaintbox.cpp",ios::in);
	while(fin6)
	{
		fin6.get(ch);
		cout<<ch;
	} 
	cout<<"\n\n\n\n\n\n   Enter the any key to return to main menu";
	getch();
	return 1;
}
int staff_login::allot_route()			// Function to preview availabe bus routes services for passengers
{
	system("cls");
	char ch;
	ifstream fin6;
	fin6.open("ROUTES.cpp",ios::in);
	while(fin6)
	{
		fin6.get(ch);
		cout<<ch;
	} 
	cout<<"\n\n\n\n\n\n   Enter the any key to return to main menu";
	getch();
	return 1;
}
int student_login::login()				//Student login function
{
	student_login s2;
	int u;
	string a[100],user1,user2,user3;
	char line[80];
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n                    USERNAME:";
	cin>>user1;
	int i=0;char ch;
	char pwd[5];
	cout<<"                    PASSWORD:";
	while(i<4)	
	{
		pwd[i]=getch();
		putchar('*');
		++i;
	}
	int j=0;
	user2=pwd;
	user3=user1+user2;					//username+password
	ifstream fil5;
	fil5.open("login.txt",ios::out);
	while(fil5)
	{
		fil5.getline(line,80);
		a[j]=line;
		j++;
	}
		for(int k=0;k<50;k++)
		{
		if(a[k]==user3)					//authentication for student login
		{
		while(1)
		{
			system("cls");
			cout<<"\n\n WELCOME TO "<<user1;
			cout<<"\n\n\n\n\n                  1.Allotment form";
			cout<<"\n                  2.Complaint"<<"\n                  3.Staff contact details";
			cout<<"\n                  4.To LOGOUT";
			cout<<"\n\n\n\n\n\n Select your option: ";
			cin>>u;
			switch(u)
				{
				case 1: system("COLOR 5F");
				s2.allotmentform();
						break;
				case 2: system("COLOR 5F");
				s2.complaints();
						break;
				case 3: system("COLOR 5F");
				s2.contactdetails();
						break;
				case 4:system("cls");
						cout<<"\n\n\n\n\n\n\n            PLEASE WAIT ... LOADING";
						Sleep(500);
						return 0;
				default:return 0;
				}
			}
    	}
    }
		system("cls");
		cout<<"\n\n\n      SORRY,"
			<<"\n      invalid username and password";
		Sleep(300);
	return 1;
}
int student_login::allotmentform()			//Function for Seat allotment form for Students
{
	system("cls");
	string j,tem[10];
	int i,d;
	cout<<"Enter your Username :";
	cin>>j;
	ifstream f8;
	f8.open("list_of_students",ios::in);		//open list of students file
	f8.seekg(0,ios::beg);						//seek cursor to the beginning of the file
	while(!f8.eof())
    {
        i++;
        string temp;
        f8 >> temp;
        if(temp == j)
        {
            d=f8.tellg();
            break;
        }
	}
	int y=d+6;
	int l=0;
	while(d!=y)
	{
		d++;
		string temp;
		f8>>temp;
		tem[l]=temp;
		l++;
	}
	system("cls");
	cout.setf(ios::left,ios::adjustfield);			//adjusting formatted position for the cout object
	cout<<endl<<endl<<"     NAME :"<<tem[0];
	cout<<"                  FATHER NAME :"<<tem[1];
	cout<<endl<<endl<<"     Ph_no:"<<tem[2];
	cout<<"                   ADDRESS:"<<tem[3];
	cout<<endl<<endl<<"     Alloted seat Number:"<<tem[4];
	cout<<endl<<endl<<endl<<"\n            Total amount DUE : Rs "<<tem[5]<<"|-"<<endl<<endl
	<<"                                                             student sign";
   	cout<<"Enter any key to retun back to menu :";
	getch();
	return 1;
}
int student_login::complaints() 				//function to fill complaints for students
{
	char ch;
	system("cls");
	ofstream fin9;
	fin9.open("complaintbox.cpp",ios::app);
	fin9<<endl;
	string mystr;
   	getline (cin, mystr);
  	cout << "Enter the Complaint :";
  	getline (cin, mystr);
  	fin9<<mystr;							//writing complaint to the file
  	cout<<"\n\n\nEnter any key to retun back to menu :";
	getch();
	return 1;
}
int student_login::contactdetails()			//function to show contact information
{
	system("cls");
	cout<<"\n\n\n   Dr. Ritika Watson,\n   Associate Professor,\n   Dept. of Computer Science, MCA,"
	<<"\n  BVICAM Room no:E-201,"<<"\n   PASCHIM VIHAR,NEW DELHI";
	cout<<"\n   Phone no: 9832333393";
	cout<<"\n\n\n\nEnter any key to retun back to menu :";
	getch();
	return 1;
}



// member functions definitions of register_now class
int register_now::instructionsform() 
{
	system("cls");
	cout<<"\n          ";
	char b[]="Read the following Instructions\n";
	int x=strlen(b);
	for(int i=0;i<x;i++)
	{
		Sleep(25);
		cout<<b[i];					// print character by character (animation effect!!)
	}
	char ch;
	char a;
	ifstream ins1;
	ins1.open("instructions.txt",ios::in);
		while(ins1) 
		{
			ins1.get(ch);
			cout<<ch;
		}
	cout<<"To accept the above instructions press Y : ";
	cin>>a;
		if(a == 'y' || a == 'Y')
		{
			registration_form();		//calling registration form function
		}
	 	else 
		{
			system("cls");
			cout<<"\n\n\n\n\n               sorry,YOU ENTERED A WRONG CHOICE.....";
			Sleep(1000);
			system("cls");
		}
}
int register_now::registration_form()
{
	string password;
	char pwd[5];
	int i=0;
	system("cls");
	a++;					//static variable 'a'
	fstream fil5;
	fil5.open("login.txt",ios::out|ios::app);
	ifstream stud;
	stud.open("std.txt");
	stud>>std_num;
	stud.close();
	ifstream staff;
	staff.open("staff.txt");
	staff>>stf_num;
	cout<<"              \n";
	char b[]="REGISTRATION FORM\n";
	int x=strlen(b);
	for(int i=0;i<x;i++)
	{
		Sleep(25);
		cout<<b[i];					//printing character by character
	}
	cout<<endl<<endl<<setw(5)<<"NAME :";
	cin>>name[0];
	cout<<setw(40)<<"FATHER NAME :";
	cin>>name[1];
	cout<<endl<<setw(5)<<"Ph_no:";
	cin>>name[2];
	cout<<setw(35)<<"ADDRESS:";
	cin>>name[3];
	cout<<endl<<setw(5)<<"Select seat Number:"<<endl;
	int count=1;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(j==3)
			{
			cout<<"   ";
			}cout<<setw(4)<<count<<"  ";
			count++;
		}
		cout<<endl;
	}
	cout<<" ";
	for(int i=51;i<=60;i++)
	{
		cout<<setw(3)<<i;
	}
	string user4;
	cout<<"\nSeat Number: ";
	cin>>name[4];
	cout<<"staff or student: ";
	cin>>user4;
	if(user4=="student")
	{
    std_num++;
    ofstream stud;
    stud.open("std.txt",ios::trunc);
    stud<<std_num;
    stud.close();
	cout<<endl<<endl<<"Your username :";
	cout<<"CBIT"<<std_num;
	cout<<endl<<"PASSWORD :";
	while(i<4)	
	{
		pwd[i]=getch();
		putchar('*');
		++i;
	}
	password=pwd;
	fil5<<"CBIT"<<std_num;
	fil5<<password<<"\n";
	name[5]="1700";
	cout<<"FEE: "<<name[5];
	fil5.close();
	fstream fil2;
	fil2.open("list_of_students",ios::in | ios::out | ios::app);
	fil2.seekg(74);
	fil2<<"CBIT"<<std_num<<"          ";
	for(int i=0;i<6;i++)
	{
	fil2.setf(ios::left,ios::adjustfield);
	fil2<<setw(20)<<name[i];
	count++;
	}
	fil2<<endl;
	Sleep(500);
}
	else
	{
		if(user4=="staff")
		{
			stf_num++;
			ofstream staff;
    		staff.open("staff.txt",ios::trunc);
    		staff<<stf_num;
    		staff.close();
				cout<<endl<<endl<<"Your username :";
	cout<<"STAF"<<stf_num;
	cout<<endl<<"PASSWORD :";
	while(i<4)	
	{
		pwd[i]=getch();
		putchar('*');
		++i;
	}
	password=pwd;
	fil5<<"STAF"<<stf_num;
	fil5<<password<<"\n";
	name[5]="1700";
	cout<<"FEE: "<<name[5];
	fil5.close();
	fstream fil2;
	fil2.open("list_of_students",ios::in | ios::out | ios::app);
	fil2.seekg(74);
	fil2<<"STAF"<<stf_num<<"          ";
	for(int i=0;i<6;i++)
	{
	fil2.setf(ios::left,ios::adjustfield);
	fil2<<setw(20)<<name[i];
	count++;
	}
	fil2<<endl;
	Sleep(500);		
		}
	}
	confirmform();
}
int register_now::confirmform()
{
	char ch;
	system("cls");
	char sentzz[]="          ***************CONFIRM FORM*****************";
	int x;              //special dialogue
	int size; 
	size=strlen(sentzz);
    for(x=0;x<size;x++)
    {   
        Sleep(50); 
        cout<<sentzz[x];
    }
    cout.setf(ios::left,ios::adjustfield);
	cout<<endl<<endl<<"     NAME :"<<name[0];
	cout<<"                  FATHER NAME :"<<name[1];
	cout<<endl<<endl<<"     Ph_no:"<<name[2];
	cout<<"                   ADDRESS:"<<name[3];
	cout<<endl<<endl<<"     Alloted seat Number:"<<name[4];
	cout<<endl<<endl<<endl<<"            Total amount to be paid : Rs 1,700|- on or before 5th july"<<endl
	<<endl<<endl<<"                                                               signature";
    	int a;
    	Sleep(400);
    	cout<<endl<<endl<<"    Enter any key to return back to main menu :";
    	getch();
    	return 1;
	}
int register_now::routes()
{
	char ch;
	system("cls");
	fstream fil4;
	fil4.open("ROUTES.cpp",ios::in);
	while(fil4) 
		{
			fil4.get(ch);
			cout<<ch;
		}
}
int register_now::notice()
{
	system("cls");
	char ch;
	ifstream f2;
	f2.open("program.txt",ios::in );
		while(f2) 
		{
			f2.get(ch);
			cout<<ch;
		}
	cout<<"\n\n\n Enter any to return back to menu :";
	getch();
	return 1;
}

int main() 
{
	char ch;
	system("COLOR 2C");
		while(1)
	{
		system("cls");
		cout<<endl<<endl;
		fstream f2;
		f2.open("sysmbol.txt",ios::in);
		while(f2) 
		{
			f2.get(ch);
			cout<<ch;
		}
	Sleep(1000);
	system("COLOR 8F");
		char a[]="                 $$$$$$$$$$$ SCHOOL TRANSPORT MANAGEMENT SYSTEM $$$$$$$$$$$";
		int size;
		size=strlen(a);
		for(int i=0;i<size;i++)
		{
			Sleep(25);
			cout<<a[i];
		}
		int c=1;
		cout<<endl<<endl;
		Sleep(0);
		cout<<"\n                    1.REGISTER NOW \n                    2.STAFF LOGIN \n                    3.STUDENT LOGIN \n"
		<<"                    4.NOTICES";
	for(int i=0;i<1;i++)
    {
    	int x = 16;
    	int y = 10;
    	for (y=10;y<19;y++)  
   		{
    	  gotoXY(x,y);
    	  cout << "*";
    	  Sleep(100);
  		}
  		y=19;
  		for (x=16;x<63;x++)  
   		{
    	  gotoXY(x,y);
    	  cout << "*";
    	  Sleep(20);
  		}
  		for (y=10;y<20;y++)  
   		{
    	  gotoXY(x,y);
    	  cout << "*";
    	  Sleep(100);
  		}
}
	for(int i=0;i<1;i++)
    {
    	int x = 1;
    	int y = 20;
    	for (x=40;x>1;x--)  
   		{
    	  gotoXY(x,y);
    	  cout << "Developed By Abhijeet Kumar in guidance of Dr. Ritika Watson";
    	  Sleep(100);
    	  gotoXY(x,y); 
		  cout << "                                                         ";
		     cout<<"                                            "; 
  		}
  		cout <<endl<<"       Developed By Abhijeet Kumar in guidance of Dr. Ritika Watson"<<endl;
	}
   register_now r1;
   staff_login s1;
   student_login s2;
   int ch;	
	cout<<"\nSelect your option : ";
	cin>>ch;
	fstream f1;
	switch(ch)
	{
		case 1:system("COLOR 1F");
				r1.instructionsform();
				break;
		case 2:system("COLOR 1F");
				s1.login();
				break;
		case 3:system("COLOR 1F");
				s2.login();
				break;
		case 4:system("COLOR 1F");
				r1.notice();
				break;
		default:cout<<"ssssss";
				break;
	}
}
	getch();
	return 0;	
}

void gotoXY(int x, int y) 
{ 
CursorPosition.X = x; // Locates column
CursorPosition.Y = y; // Locates Row
SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed 
}
