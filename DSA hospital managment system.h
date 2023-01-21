#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

struct patient
{
    long ID;
	string fullname;
	int age;
	string blood;
	string gender;
    patient*next;
};
class linkedlist
{
	patient *head,*tail;
	public:
	linkedlist()
	{
		head=NULL;
		tail =NULL;
	}
    patient input();
    void insrtStart();
    void insrtEnd();
    void patientsout();
    void patientslist();
    int search(int);
    char departmentname[50];
};



patient linkedlist :: input()
{
	system("cls");
   patient *p=new patient();
   cout << "\n\tPlease Enter The Data Of Patient\n";
   getline(cin,p->fullname);
   cout<<"\tFull Name      : ";
   getline(cin,p->fullname);
   blod:
   cout<<"\tBlood Group    : ";
   cin >> p->blood;
   if(p->blood == "A+" || p->blood == "a+" || p->blood == "A-" || p->blood == "a-" ||
      p->blood == "B+" || p->blood == "b+" || p->blood == "b-" || p->blood == "B-" ||
	  p->blood == "O+" || p->blood == "o+" || p->blood == "O-" || p->blood == "o-" ||
	  p->blood == "AB+" || p->blood == "ab+" || p->blood == "AB-" || p->blood == "ab-")
	  {
	  	cout << "";
	  }
	  else 
	  {
	  	cout << "\tPlease Enter Correct";
	  	goto blod;
	  }
   gendr:
   cout<<"\tGender:";
   cin>>p->gender;
   if(p->gender == "male" || p->gender == "female" || p->gender == "Male" || p->gender == "Female" || p->gender == "f" || p->gender == "m" || p->gender == "M" || p->gender == "F")
   {
   	cout << "";	
   }
   else 
   {
   	cout << "\tWrong Gender Please Enter Correct";
   	goto gendr;
   }
   cout<<"\tAge            : ";
   cin>>p->age;
   cout<<"\tMobile number  : ";
   cin>>p->ID;
   
   return *p;
}
void output(patient *p)
{
	cout <<endl;
	cout<<"****** Patient data *******";
	cout<<"\nFirst Name         : "<<p->fullname;
	cout<<"\nGender             : "<<p->gender;
	cout<<"\nAge                : "<<p->age;
	cout<<"\nBlood Group        : "<<p->blood;
	cout<<"\nMobile Number      : "<<p->ID<<endl;
	cout<<"***************************";
}
void linkedlist :: insrtStart()
{
     patient*p=new patient();
     *p=input();
     if(p->ID==0)
     return;

     if(head==NULL)

     {
         head=p;
         tail=p;
         p->next=NULL;
     }
     else
     {
        p->next=head;
        head=p;
     }
     system("cls");
     cout << "\nPatient Admitted" <<endl;
     output(p);
}
void linkedlist:: insrtEnd()
{
     patient*p=new patient();
     *p=input();
     if(p->ID==0)
     return;

     if(head==NULL)
     {
     	head=p;
        tail=p;
        p->next=NULL;
     }
     else
     {
     	p->next=NULL;
        tail->next=p;
        tail=p;
     }
     system("cls");
     cout << "\nPatient Admitted:" <<endl;
     output(p);
}
void linkedlist :: patientsout()
{
	 system("cls");
     if(head==NULL)
     {
     	cout<<"\n\tNo Patient to operate";
     }
     else
     {
     	patient*p=new patient();
     	p=head;
     	head=head->next;
 	    cout << "\n\tPatient to operate:";
        output(p);
 	 }
}

void linkedlist :: patientslist()
{
     if(head==NULL)
     {
     	cout<<"\n\tNo patient";
 	 }
     patient*p=new patient;
     p=head;
     while(p!=NULL)
     {
     	
        cout<<"\n*** Admitted Patients ***";
		cout<<"\nFirst Name       : "<<p->fullname;
		cout<<"\nGender           : "<<p->gender;
        cout<<"\nAge              : "<<p->age;
        cout<<"\nBlood Group      : "<<p->blood;
		cout<<"\nMobile Number    : "<<p->ID<<endl;
		cout<<"*************************"<<endl;
        p=p->next;
     }
     cout<<"\n";
}


void depart(linkedlist * q)
{
    int choice;
    patient p;
    while (choice != 5)
	{
    system("cls");
	cout<<"\n\n\tWelcome To Department : " ;
	cout<<"\n\t\t[1] Add normal patient\n";
	cout<<"\t\t[2] Add critically ill patient\n";
	cout<<"\t\t[3] Take patient to Doctor\n";
	cout<<"\t\t[4] Display list\n";
	cout<<"\t\t[5] Change department or exit\n";
	cout<<"\n\tPlease enter your choice : ";
	cin >> choice;

    switch (choice)
	{
	  case 1:	q->insrtEnd();
				cout << "\n\tPress any key";
	    		getch();
	 			break;

      case 2:	q->insrtStart();
	    		cout << "\n\tPress any key";
	    		getch();
				break;

      case 3:	q->patientsout();
	 			cout<<"\n\tPress any key";
     			getch();
	      		break;

      case 4:	system("cls");
	 			q->patientslist();
	 			cout<<"\n\tPress any key";
	 			getch();
				break;
	 }
    }
}

int main ()
{
    int i, choice = 0;
	linkedlist departments[4];

	while(choice!=5)
	{
		departments[0].departmentname == "General Clinic\n";
		departments[1].departmentname == "Heart Clinic\n";
		departments[2].departmentname == "Lung Clinic\n";
		departments[3].departmentname == "Plastic Surgery\n";
		system("cls");
		cout<<"\n\tHOSPITAL MANAGEMENT SYSTEM\t";
		for (i = 0; i < 4; i++)
		{
			cout<<"\t"<<(i+1)<<": "<<departments[i].departmentname;
		}
		cout<<"\t5: Exit";
		cout<<"\n\n\tPlease enter your choice : ";
		cin >> choice;
		if(choice>=1 && choice<=4)
		{
			depart(&departments[choice-1]);
		}

	}
	if(choice==5)
	cout<<"\n\t\tThank you! \n";
	exit(0);
}