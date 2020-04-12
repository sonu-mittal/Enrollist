#include <iostream>
#include <math.h>
#include <windows.h>
#include <ctime>
#include <iomanip>
#include <limits>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <fstream>
using namespace std;

COORD coord = {0,0};
void gotoxy(int x, int y)
{

	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition( GetStdHandle (STD_OUTPUT_HANDLE), coord );
}
void time()
{
	gotoxy(2,25);
		time_t now;
	time (&now);
	cout << "\n\n\t\t Current Date & Time is: "<<ctime(&now);;
}

void loading()
{
	gotoxy(24,26);
	int i;
	for (i=1; i<=5; i++)
	{
		cout << "\xdb\xdb\xdb\xdb\xdb";
		Sleep(100);
	}
	Sleep(500);
	cout << endl << endl;
	gotoxy(24,28);
}

void mainEntrance()
{
	gotoxy(1,2);
	cout<<   "   лллл лллл     ллл     ллл    лл     ллл      ллллллл  ллллллл  лллл лллл ллллллл ллл    лл лллллллл";
    cout<<"\n    лл ллл лл    лл лл    лллл   лл    лл лл     лл       лл       лл ллл лл лл      лллл   лл    лл";
    cout<<"\n    лл  л  лл   ллллллл   лл лл  лл   ллллллл    лл лллл  ллллл    лл  л  лл ллллл   лл лл  лл    лл";
    cout<<"\n    лл     лл  лл     лл  лл  лл лл  лл     лл   лл   лл  лл       лл     лл лл      лл  лл лл    лл";
    cout<<"\n    лл     лл лл       лл лл   лллл лл       лл  ллллллл  ллллллл  лл     лл ллллллл лл   лллл    лл";
    gotoxy(1,8);
    cout<<  "\t\t        ллллллл лл    лл ллллллл лллллллл ллллллл лллл лллл";
    cout<<"\n\t\t        лл       лл  лл  лл         лл    лл      лл ллл лл";
    cout<<"\n\t\t        ллллллл   лллл   ллллллл    лл    ллллл   лл  л  лл";
    cout<<"\n\t\t             лл    лл         лл    лл    лл      лл     лл";
    cout<<"\n\t\t        ллллллл    лл    ллллллл    лл    ллллллл лл     лл";

	gotoxy(6,15);
	cout << "     **************************************************************" << endl;
	gotoxy(6,16);
	cout << "                                LOGIN                     " << endl;
	gotoxy(6,17);
	cout << "     **************************************************************" << endl;
}

void login()
{
	system("cls");

	string username = "";
	string password = "";
	char ch,ch2,retry;
	int i = 0, j = 0;
	mainEntrance();
	time();
	gotoxy(55,10);
	gotoxy(20,18);
	cout << "Enter Username: \n\t\t    Enter Password: ";
	gotoxy(36,18);

	ch2=getch();
	while(ch2 != 13){

		if(ch2 == '\b')
		{
			if(username.size() > 0 )
			{
				username.erase(username.begin() + username.size() -1);
				cout << "\b \b";
				j--;
			}
			ch2 = getch();
		}
		else
		{
			if(j<10)
			{
				cout << ch2;
				username.push_back(ch2);
				ch2 = getch();
				j++;
			}
			else{
				ch2 = getch();
			}
		}
	}

	gotoxy(36,19);
	ch=getch();
	while(ch != 13){

		if(ch == '\b')
		{
			if(password.size() > 0)
			{
				password.erase(password.begin() + password.size() -1);
				cout << "\b \b";
				i--;
			}
			ch = getch();
		}
		else
		{
			if(i<10)
			{
				password.push_back(ch);
				cout << "*";
				ch = getch();
				i++;
			}
			else
			{
				ch = getch();
			}
		}
	}
	if (username == "admin" && password == "12345")
	{
		gotoxy(15,16);
		cout << "\n\n Username & Password Matched !! ";
		cout << "\n\n\t Access Granted...\n\n";
		cout << "\n\n\t\t Now Loading: ";
		loading();
		return;
	}
	else
	{
		system("cls");
		cout << "\n\n You entered Wrong UserName/Password ";
		cout << "\n\n\t Press 'R' or 'r' to Enter Again OR any other key to exit ...\n\n";
		cin >> retry;
			if(retry == 'r' || retry == 'R')
			{
				system("cls");
				login();
			}
			else
			{
				exit(0);
			}
	}
}

struct stud
{
    int roll;
    char name[30];
    float english;
    float percentage;

}s1,t1[100];
long int counter=0;
static int height = 0;

class records
{
	public:
		struct student
		{
			int roll;
			char name[30];
			char contact[30];
			float maths;
			float physics;
			float chemistry;
			float english;
			float percentage;

			student *left;
			student *right;
		}s;

		student *root;
			records();
			void insert();
			void display(int);
			void show1 (student *&);
			void show4 (student *&);
			void search();
			void deleteRecords();
			int remove(int rn, student *&,int &found);
			void del (student *&nodeptr);
			void totalNodes();
			int findHeight(student *&);
			void findDepthOfNode();
			void read(char *in_file);
			void studentMenu();
};

records r;

records :: records()
{
	root = NULL;
}

static int count=0;
void records :: insert()
{
    fstream fout,fin;
 fin.open("student" , ios::in|ios::out);
 char t[2];
	system("cls");

	label:
	student *newnode, *nodeptr;
	char ch;

	cout << "\n\n ________________________RECORDS INSERTION_________________________";
	do
	{
		newnode = new student;

	cout << "\n\n Enter Roll Number of Student: ";
	while(1)
	{
		cin >> newnode->roll;
		s1.roll=newnode->roll;
		t1[count].roll=newnode->roll;
		if (cin.fail() || newnode->roll < 1 )
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(),'\n');
			cout << "\nInvalid Input...\nPlease Enter a Roll No. greater than or equal to 1: ";
		}
		else
			break;
	}

	student *temp = new student;
	temp = root;
	while (temp != NULL)
	{
		if(newnode->roll == temp->roll)
		{
			cout << "\n\n This Roll No. has already been used";
			cout << "\n\n\t Please Enter a unique Roll NO. \n\n";
			system("pause");
			goto label;
			break;
		}
		else if(newnode->roll > temp->roll)
		{
			temp = temp->right;
		}
		else if(newnode->roll < temp->roll)
		{
			temp = temp->left;
		}
	}

	label1:
	cout << "\n\n Enter Name of Student: ";
	cin.ignore();
	cin.getline (newnode->name,30);
    strcpy(s1.name,newnode->name);
    strcpy(t1[count].name,newnode->name);
	int check1 = 0;
	for(int i = 0; i < strlen(newnode->name); i++)
	{
        if(isalpha(newnode->name[i]) == 0)
		{
        	if (newnode->name[i] == ' ')
        	{
        		check1 = 0;
			}
			else
			{
            cout << "\n\nInvalid Input...\nPlease Enter alphabets only:";
            check1 = 1;
            break;
        	}
        }
    }
    if (check1 == 1)
    {
    	goto label1;
	}

	label2:
	cout << "\n\n Enter Contact number of Student: ";
	cin.getline(newnode->contact,30);

	cout << "\n\n Enter your marks- "<<endl;
  int r=1;
	while(1)
	{

	    if(r==1)
	    {
	        cout<<"maths:";
		cin >> newnode->maths;
		cout<<endl;
		if (cin.fail() || (newnode->maths < 0.0) || (newnode->maths > 100.0) )
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(),'\n');
			cout << "\nInvalid Input...\nPlease Enter Marks ranging from 0.0 to 100.0: "<<endl;;
			continue;
		}

        cout<<"physics:";
		cin >> newnode->physics;
		cout<<endl;
		if (cin.fail() || (newnode->physics < 0.0) || (newnode->physics> 100.0) )
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(),'\n');
			cout << "\nInvalid Input...\nPlease Enter Marks ranging from 0.0 to 100.0: "<<endl;
			continue;
		}

        cout<<"chemistry:";
		cin >> newnode->chemistry;
		cout<<endl;
		if (cin.fail() || (newnode->chemistry < 0.0) || (newnode->chemistry> 100.0) )
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(),'\n');
			cout << "\nInvalid Input...\nPlease Enter Marks ranging from 0.0 to 100.0: "<<endl;
			continue;
		}

        cout<<"english:";
		cin >> newnode->english;
		s1.english=newnode->english;
		if (cin.fail() || (newnode->english < 0.0) || (newnode->english> 100.0) )
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(),'\n');
			cout << "\nInvalid Input...\nPlease Enter Marks ranging from 0.0 to 100.0: "<<endl;
			continue;
		}
		newnode->percentage=(newnode->maths+newnode->physics+newnode->english+newnode->chemistry)/4;
		s1.percentage=newnode->percentage;
		t1[count].percentage=newnode->percentage;
		r++;
		count++;
		counter=count;
	}
	else
        break;
	}


	newnode->left = NULL;
	newnode->right = NULL;

	if (root == NULL)
	{
		root = newnode;
		height++;
	}
	else
	{
		nodeptr = root;
		while (nodeptr != NULL)
		{
			if (newnode->roll < nodeptr->roll)
			{
				if (nodeptr->left != NULL)
				{
					nodeptr = nodeptr->left;
				}
				else
				{
					nodeptr->left = newnode;
					height++;
					break;
				}
			}
			else if (newnode->roll > nodeptr->roll)
			{
				if(nodeptr->right != NULL)
				{
					nodeptr = nodeptr->right;
				}
				else
				{
					nodeptr->right = newnode;
					height++;
					break;
				}
			}
		}
	}
	fin.write((char*)&s1,sizeof(s1));
	 cin.getline(t,2);

		cout << "\n\n\t Do you want to enter more Records ? \n\n";
		ch=getch();
	} while(ch == 'y' || ch == 'Y');
fin.close();
}


void records :: show1(student *&temp)
{
	if(temp != NULL)
	{
		show1(temp->left);
		cout << "\n\n\n\n Roll-No: " << temp->roll;
		cout << "\n\n Name: " << temp->name;
		cout << "\n\n Contact: " << temp->contact;
		cout << "\n\n Maths: " << temp->maths;
        cout << "\n\n Physics: " << temp->physics;
        cout << "\n\n English: " << temp->english;
        cout << "\n\n Chemistry: " << temp->chemistry;
        cout << "\n\n Percentage: " << temp->percentage;
		show1(temp->right);
	}
}



void records :: show4(student *&temp)
{

    if(temp != NULL)
	{
		show4(temp->right);
		cout << "\n\n\n\n Roll-No: " << temp->roll;
		cout << "\n\n Name: " << temp->name;
		cout << "\n\n Contact: " << temp->contact;
		cout << "\n\n Maths: " << temp->maths;
        cout << "\n\n Physics: " << temp->physics;
        cout << "\n\n English: " << temp->english;
        cout << "\n\n Chemistry: " << temp->chemistry;
        cout << "\n\n Percentage: " << temp->percentage;

		show4(temp->left);
	}
}

void records :: display(int choice)
{
	system("cls");
	if(root == NULL)
	{
		cout << "\n\n\tPlease enter some Record First...\n\n";
		return;
	}
	cout << "\n\n _________________________RECORDS DISPLAY_________________________";
	if (choice == 1)
	{
		records :: show1(root);
	}
	else if (choice == 2)
	{
		records :: show4(root);
	}

}
int flag=0;
void records :: search()
{
	system("cls");
	if (root == NULL)
	{
		cout << "\n\n\tPlease Enter Some Record First...\n\n";
		return;
	}
	int rn,check = 0;
	student *temp;
	cout << "\n\n _________________________RECORDS SEARCH_________________________";
	cout << "\n\n Please Enter Roll No. of Student to Search: ";
	while(1)
	{
		cin >> rn;
		if (cin.fail() || rn < 1 )
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(),'\n');
			cout << "\nInvalid Input...\nPlease Enter a Roll No. greater than or equal to 1: ";
		}
		else
			break;
	}

	temp = root;
	while(temp != NULL)
	{
		if (temp->roll == rn)
		{
			cout << "\n\n\n\n Roll-No: " << temp->roll;
			cout << "\n\n Name: " << temp->name;
			cout << "\n\n Contact: " << temp->contact;
			cout << "\n\n Maths: " << temp->maths;
		    cout << "\n\n Physics: " << temp->physics;
		    cout << "\n\n English: " << temp->english;
            cout << "\n\n Chemistry: " << temp->chemistry;
            cout << "\n\n Percentage: " << temp->percentage;
			check = 1;
			break;
		}

		else if(rn < temp->roll)
		{
			temp = temp->left;
		}

		else if(rn > temp->roll)
		{
			temp = temp->right;
		}
	}
		if (check == 0)
		{
			cout << "\n\n\t Record of Student with Roll NO. " << rn << " not Found...!\n\n";
			return;
		}
}

int records :: remove (int rn, student *&nodeptr,int &found)
{
	if (nodeptr == NULL)
	{
		return found;
	}

	else if(rn < nodeptr->roll)
	{
		records :: remove(rn,nodeptr->left,found);
	}

	else if (rn > nodeptr->roll)
	{
		records :: remove (rn,nodeptr->right,found);
	}
	else if (rn == nodeptr->roll)
	{
		found = 1;
		records :: del(nodeptr);
	}

		return found;
}

void records :: del (student *&nodeptr)
{
		student *temp;
		if(nodeptr->left == NULL && nodeptr->right == NULL)
			{
			    height--;
				delete nodeptr;
				nodeptr = NULL;
				flag=3158;
				cout << "\n\n RECORD DELETED SUCCESSFULLY...\n";
			}
		else if (nodeptr->right == NULL)
			{
				temp = nodeptr;
				nodeptr = nodeptr->left;
				delete temp;
				height--;
				flag=3158;
				cout << "\n\n RECORD DELETED SUCCESSFULLY...\n";
			}
		else if (nodeptr->left == NULL)
			{
				temp = nodeptr;
				nodeptr = nodeptr->right;
				delete temp;
				height--;
				flag=3158;
				cout << "\n\n RECORD DELETED SUCCESSFULLY...\n";
			}
		else if (nodeptr->right != NULL && nodeptr->left != NULL)
		{
			temp = nodeptr->right;

			while (temp->left != NULL)   // Traversing to find Min
			{
				temp = temp->left;
			}
				temp->left = nodeptr->left;

				temp = nodeptr;
				nodeptr = nodeptr->right;
				delete temp;
                flag=3158;
				height--;
				cout << "\n\n RECORD DELETED SUCCESSFULLY...\n";
		}
			return;
	}


void records :: deleteRecords()
{
	system("cls");
	int rn,f=0,found=0;

	if(r.root == NULL)
	{
		cout << "Please Enter some Record First....";
		return;
	}

	cout << "\n\n _________________________RECORDS DELETION_________________________";
	cout << "\n\n\tPlease Enter Roll No. of student to Delete: ";

	while(1)
	{
		cin >> rn;
		if (cin.fail() || rn < 1 )
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(),'\n');
			cout << "\nInvalid Input...\nPlease Enter a Roll No. greater than or equal to 1: ";
		}
		else
			break;
	}

	f=r.remove(rn,r.root,found);

	if( f== 0)
	{
		cout << "\n\n\t Record of Student with Roll NO. " << rn << " not Found...!\n\n";
		return;
	}
}

void records :: totalNodes()
{
	system("cls");
	if (height == 0)
	{
		cout << "\n\n\t Please Insert Some Records First...";
		return;
	}
	else
	{
		cout << "\n\n Total Number of Students are: " << height;
	}
}

void records :: findDepthOfNode()
{
	system("cls");
	int rn;
	int count = 0;
	int check = 0;
	student *temp;

	if (height == 0)
	{
		cout << "Please Enter some Record First....";
		return;
	}
	else
	{
		cout << "\n _________________________DEPTH OF NODE_________________________";
		cout << "\n\n Enter Roll No. of Student to Find the Depth of Node: ";

		while(1)
		{
			cin >> rn;
			if (cin.fail() || rn < 1 )
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize> :: max(),'\n');
				cout << "\nInvalid Input...\nPlease Enter a Roll No. greater than or equal to 1: ";
			}
			else
				break;
		}

		temp = root;
		while (temp != NULL)
		{
			if (temp->roll == rn)
			{
				cout << "\n\n Depth of Node you Entered starting From Zero is: " << count;
				check = 1;
				break;
			}
			else if (rn < temp->roll)
			{
				temp = temp->left;
				count++;
			}
			else if (rn > temp->roll)
			{
				temp = temp->right;
				count++;
			}
		}
		if(check == 0)
		{
			cout << "\n\nThe Student with Roll No. " << rn << " was not FOUND...\n\n";
		}
	}
}

void records::read(char *in_file)
{

int i,j;
student s[height],t;
stud s2[height];
string end_of_file = "eof";

ifstream inFile;
inFile.open("student");

for(i=0;i<height;i++)
{
    inFile >> s2[i].roll;
    inFile >> s2[i].name;
    inFile >> s2[i].percentage;
}

inFile.close();
}


void merit_list()
{
int i,j,rnk=0;
stud temp1;
for(i=0;i<counter;i++)
{
for(j=i+1;j<counter;j++)
{
    if(t1[i].percentage<t1[j].percentage)
    {
        temp1=t1[i];
        t1[i]=t1[j];
        t1[j]=temp1;
    }
}
}
cout<<"\n\nRank\t\t"<<"Roll\t\t"<<"Name\t\t"<<"Percentage\t\t\n"<<endl;
for(i=0;i<counter;i++)
{
    if(flag!=t1[i].roll)
	{
		cout<<++rnk<<"\t\t";
    	cout<<t1[i].roll<<"\t\t";
    	cout<<t1[i].name<<"\t\t";
		cout<<t1[i].percentage<<endl;
    }

}
}
int merit_list(int enrol)
{
int i,j,rnk=0;
stud temp1;
for(i=0;i<counter;i++)
{
for(j=i+1;j<counter;j++)
{
    if(t1[i].percentage<t1[j].percentage)
    {
        temp1=t1[i];
        t1[i]=t1[j];
        t1[j]=temp1;
    }
}
}

for(i=0;i<counter;i++)
{
	rnk++;
    if(enrol==t1[i].roll)
	{
		cout<<"\n\nRank\t\t"<<"Roll\t\t"<<"Name\t\t"<<"Percentage\t\t\n"<<endl;
		cout<<rnk<<"\t\t";
    	cout<<t1[i].roll<<"\t\t";
    	cout<<t1[i].name<<"\t\t";
		cout<<t1[i].percentage<<endl;
		return 0;
		break;
    }		
}
if(i==counter)
	{
		cout<<"Enter Correct Roll Number.\n";
		return 1;
	}
}

void records :: studentMenu()
{
	label5:
	system("cls");
	cout << "\n\n\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
	cout << "\n\t\tлл\t\t 1: Administrator Portal \t\tлл"<<endl;
	cout << "\n\t\tлл\t\t 2: Student Portal \t\t\tлл"<<endl;
	cout << "\n\t\tлл\t\t Any other to Exit \t\t\tлл"<<endl;
	cout << "\n\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллл";

	cout << "\n\n\n\t\t Enter your Choice: ";
	int choice;
	choice = getche();
	if(choice=='1')
	{
		while(true)
		{
			system("cls");

			cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл";
			cout << "\n\n\t\t\tлл\t  _________________________ADMIN PORTAL_________________________\t\tлл";
			cout << "\n\n\t\t\tлл\t 1: Insert Record                                               \t\tлл";
			cout << "\n\n\t\t\tлл\t 2: Display Records in Ascending Order                          \t\tлл";
			cout << "\n\n\t\t\tлл\t 3: Display Records in Descending Order                         \t\tлл";
			cout << "\n\n\t\t\tлл\t 4: Search Record                                               \t\tлл";
			cout << "\n\n\t\t\tлл\t 5: Delete Record                                               \t\tлл";
			cout << "\n\n\t\t\tлл\t 6: Check Total No. of Students                                 \t\tлл";
			cout << "\n\n\t\t\tлл\t 7: Depth of Specific Node                                      \t\tлл";
			cout << "\n\n\t\t\tлл\t 8: Show merit list of students                                 \t\tлл";
			cout << "\n\n\t\t\tлл\t 9: Return to Portals                                           \t\tлл";
			cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл";
			cout << "\n\n\t\t\t\t Enter your Choice: ";
			

			label1:
			choice = getch();

		if (choice >= '1' && choice <= '9')
		{
			goto label2;
		}
		goto label1;

		label2:
		cout << choice-48;

		system("cls");
		switch(choice)
		{
			case '1':
				r.insert();
				cout << "\n\n\t";
				system("pause");
				break;
			case '2':
				r.display(1);
				cout << "\n\n\t";
				system("pause");
				break;
			case '3':
				r.display(2);
				cout << "\n\n\t";
				system("pause");
				break;
			case '4':
				r.search();
				cout << "\n\n\t";
				system("pause");
				break;
			case '5':
				r.deleteRecords();
				cout << "\n\n\t";
				system("pause");
				break;
			case '6':
				r.totalNodes();
				cout << "\n\n\t";
				system("pause");
				break;
			case '7':
				r.findDepthOfNode();
				cout << "\n\n\t";
				system("pause");
				break;
			case '8':
			   // r.read("student");
                merit_list();
                cout << "\n\n\t";
				system("pause");
				break;
			case '9':
				goto label5;
				break;
			default:
				cout << "\n\n Please Enter a valid Choice: \n\n";
				system ("pause");
				break;
			}
		}
	}
	else if(choice=='2')
	{
		while(true)
		{
			system("cls");
			cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл";
			cout << "\n\n\t\t\tлл\t  _________________________STUDENT PORTAL_________________________      лл";
			cout << "\n\n\t\t\tлл\t 1: Display Records in Ascending Order                                  лл";
			cout << "\n\n\t\t\tлл\t 2: Merit List                                                          лл";
			cout << "\n\n\t\t\tлл\t 3: Know Your Rank                                                      лл";
			cout << "\n\n\t\t\tлл\t 4: Search Record                                                       лл";
			cout << "\n\n\t\t\tлл\t 5: Return to Portals                                                   лл";
			cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл";
			cout << "\n\n\t\t\t\t Enter your Choice: ";

			label3:
			choice = getch();

		if (choice >= '1' && choice <= '9')
		{
			goto label4;
		}
		goto label3;

		label4:
		cout << choice-48;

		system("cls");
		switch(choice)
		{
			case '1':
				r.display(1);
				cout << "\n\n\t";
				system("pause");
				break;
			case '2':
				merit_list();
				cout << "\n\n\t";
				system("pause");
				break;
			case '3':
				int yo;
				YOO:
				cout<<"Enter Your Roll No. : ";
				cin>>yo;
				if(merit_list(yo))
				{
					goto YOO;
				}
				cout << "\n\n\t";
				system("pause");
				break;
			case '4':
				r.search();
				cout << "\n\n\t";
				system("pause");
				break;
			case '5':
				goto label5;
				break;
			default:
				cout << "\n\n Please Enter a valid Choice: \n\n";
				system ("pause");
				break;
			}
		}
	}
	else
		exit(1);
}

int main()
{
	system("color c1");
	login();
	while(true)

	{

			system("cls");
			r.studentMenu();

	}
	return 0;
}
