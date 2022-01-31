// [A] Write a C++ program to study implementation of Hierarchical form of Inheritance
#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<cstring>
using namespace std;
class student
{
	protected:
		char name[20];
		int roll_no;
		char address[20];
		char college[20];
		int uni_pr_num;
	public:
		void getdata()
		{
			fflush(stdin);
			cout << "Enter the name of the student:";
			cin.getline(name, 100);
			
			cout << "Enter the roll no:";
			cin >> roll_no;
			
			fflush(stdin);
			cout << "Enter the address:";
			cin.getline(address,20);
			
			fflush(stdin);
			cout << "Enter the college name:";
			cin.getline(college,20);
			
			cout << "Enter the university registration number:";
			cin >> uni_pr_num;
			
		}
		void display()
		{
			cout << name << setw(20) << roll_no << setw(35) << address << setw(23) << college;
			cout << setw(35) << uni_pr_num;
		}
};
class arts:public student
{
	string arts_subject;
	
	public:
		arts()
		{
			arts_subject = "Fine arts";
		}
		void display_arts()
		{
			this->display();
			cout << setw(45) << arts_subject << endl;
		}
		
		int search_arts(int roll)
		{
			if (roll_no == roll)
			{
				this->display_arts();
				return 1;
			}
			return -1;
		}
		
};
class medical:public student
{
	string medical_subject;
	public:
		medical()
		{
			medical_subject = "Autonomy";
		}
		void display_medical()
		{
			this->display();
			cout << setw(45) << medical_subject << endl;
		}
		
		int search_medical(int roll)
		{
			if (roll_no == roll)
			{
				this->display_medical();
				return 1;
			}
			return -1;
		}
};
class engineering:public student
{
	protected:
		string branch;
		string instruction_stream = "RC 2019-20";
};
class mech: public engineering
{
	string mech_sub;
	public:
		mech()
		{
			mech_sub = "Machine Drawing";
			branch = "Mechanical";
		}
		void display_mech()
		{
			this->display();
			cout << setw(45) << mech_sub << endl;
		}
		int search_mech(int roll)
		{
			if (roll_no == roll)
			{
				this->display_mech();
				return 1;
			}
			return -1;
		}
		
};
class comp: public engineering
{
	string comp_sub;
	public:
		comp()
		{
			comp_sub = "Logic Design";
			branch = "Computer Science";
		}
		void display_cs()
		{
			this->display();
			cout << setw(45) << comp_sub << endl;
		}
		int search_comp(int roll)
		{
			if (roll_no == roll)
			{
				this->display_cs();
				return 1;
			}
			return -1;
		}
		
};
class etc: public engineering
{
	string etc_sub;
	public:
		etc()
		{
			etc_sub = "VLSI Design";
			branch = "Electrical and Telecommunication";
		}
		void display_etc()
		{
			this->display();
			cout << setw(45) << etc_sub << endl;
		}
		bool search_etc(int roll)
		{
			if (roll_no == roll)
			{
				this->display_etc();
				return 1;
			}
			return -1;
		}
};
class it: public engineering
{
	string it_sub;
	public:
		it()
		{
			it_sub = "Networks";
			branch = "Information Technology";
		}
		void display_it()
		{
			this->display();
			cout << setw(45) << it_sub << endl;
		}
		int search_it(int roll)
		{
			if (roll_no == roll)
			{
				this->display_it();
				return 1;
			}
			return -1;
		}
};
int main()
{
	int choice,i,na,nm,ncs,netc,nmech,nit,roll,found;

	char branch_code;
	comp *cs;
	mech *Mech;
	etc *e;
	it *IT;
	
	while(1)
	{
		cout << endl;
		cout << setfill('*') << setw(20)<< " Menu " << setw(16) << "" << endl;
		cout << "-----------------------------------\n";
		cout << "1.Enter details of Arts student" << endl;
		cout << "2.Enter details of Medical students" << endl;
		cout << "3.Enter details of Engineering students" << endl;
		cout << "4.Display details of Arts students" << endl;
		cout << "5.Display details of Medical students" << endl;
		cout << "6.Display details of Engineering students" << endl;
		cout << "7.Search the details" << endl;
		cout << "8. Exit" << endl;
		cout << "-----------------------------------\n";
		
		cout << "Enter choice:";
		cin >> choice;
		cout.fill(' ');
		switch(choice)
		{
			case 1: 
					cout << "Enter the number of students in Arts stream:";
					cin >> na;
					
					arts *a;
					a = new arts[na];
					cout << "\n-----------------------------------\n";
					for(i=0;i<na;i++)
					{
						a[i].getdata();
						if (i != na-1)
							cout << "\n-----------------------------------\n";
					}
					break;
			case 2: 
					cout << "Enter the number of students in Medical stream:";
					cin >> nm;
					
					medical *m;
					m = new medical[nm];
					cout << "\n-----------------------------------\n";
					for(i=0;i<nm;i++)
					{
						m[i].getdata();
						if (i != nm-1)
							cout << "\n-----------------------------------\n";
					}
					break;
			
			case 3: 
					cout << "Choose from the branch given below:" << endl;
					cout << "a. CS" << endl;
					cout << "b. ETC" << endl;
					cout << "c. IT" << endl;
					cout << "d. MECH" << endl;
					
					fflush(stdin);
					cout << "Enter the branch code:";
					cin.get(branch_code);
					
					switch(branch_code)
					{
						case 'a': 
								cout << "Enter the number of students in CS branch:";
								cin >> ncs;
								
								cs = new comp[ncs];
								cout << "\n-----------------------------------\n";
								
								for(i=0;i<ncs;i++)
								{
									cs[i].getdata();
									if (i != ncs-1)
										cout << "\n-----------------------------------\n";
								}
								break;
								
						case 'b': 
								cout << "Enter the number of students in ETC branch:";
								cin >> netc;
								
								e = new etc[netc];
								cout << "\n-----------------------------------\n";
								
								for(i=0;i<netc;i++)
								{
									e[i].getdata();
									if (i != netc-1)
										cout << "\n-----------------------------------\n";
								}
								break;
						case 'c':
								cout << "Enter the number of students in IT branch:";
								cin >> nit;
							
								IT = new it[nit];
								cout << "\n-----------------------------------\n";
								for(i=0;i<nit;i++)
								{
									IT[i].getdata();
									if (i != nit-1)
										cout << "\n-----------------------------------\n";
								}
								break;
						case 'd':
								cout << "Enter the number of students in MECH branch:";
								cin >> nmech;
								
								Mech = new mech[nmech];
								cout << "\n-----------------------------------\n";
								for(i=0;i<nmech;i++)
								{
									Mech[i].getdata();
									if (i!= nmech)
										cout << "\n-----------------------------------\n";
								}
								break;
						default: cout << "Enter valid branch" << endl;	
					}
					break;
			case 4: 
					if (na == 0)
					{
						cout << "No entries present" << endl;
						break;
					}
					cout << "The details of students enrolled in arts stream:" << endl;
					cout << "Name" << setw(20) << "Roll Number" << setw(35) << "Address" << setw(23) <<"College" << setw(35) << "University Registration Number" << setw(45) << "Subject" << endl;
					for(i=0;i<na;i++)
					{
						a[i].display_arts();
					}
					break;
			case 5:	
					if (nm == 0)
					{
						cout << "No entries present" << endl;
						break;
					}
					cout << "The details of students enrolled in medical stream:" << endl;
					cout << "Name" << setw(20) << "Roll Number" << setw(35) << "Address" << setw(23) <<"College" << setw(35) << "University Registration Number" << setw(45) << "Subject" << endl;
					for(i=0;i<nm;i++)
					{
						m[i].display_medical();
					}
					break;
			case 6:
					cout << "Choose from the branch given below:" << endl;
					cout << "a. CS" << endl;
					cout << "b. ETC" << endl;
					cout << "c. IT" << endl;
					cout << "d. MECH" << endl;
					
					fflush(stdin);
					cout << "Enter the branch code:";
					cin.get(branch_code);
					
					switch(branch_code)
					{
						case 'a':
									if (ncs == 0)
									{
										cout << "No entries present" << endl;
										break;
									}		
									cout << "Name" << setw(20) << "Roll Number" << setw(35) << "Address" << setw(23) <<"College" << setw(35) << "University Registration Number" << setw(45) << "Subject" << endl;
									for(i=0;i<ncs;i++)
									{
										cs[i].display_cs();
									}
									break;
						case 'b': 
									if (netc == 0)
									{
										cout << "No entries present" << endl;
										break;
									}
									cout << "Name" << setw(20) << "Roll Number" << setw(35) << "Address" << setw(23) <<"College" << setw(35) << "University Registration Number" << setw(45) << "Subject" << endl;
									for(i=0;i<netc;i++)
									{
										e[i].display_etc();
									}
									break;
									
						case 'c':
									if (nit == 0)
									{
										cout << "No entries present" << endl;
										break;
									}
									cout << "Name" << setw(20) << "Roll Number" << setw(35) << "Address" << setw(23) <<"College" << setw(35) << "University Registration Number" << setw(45) << "Subject" << endl;
									for(i=0;i<nit;i++)
									{
										IT[i].display_it();
									}
									break;
						
						case 'd':	
									if (nmech == 0)
									{
										cout << "No entries present" << endl;
										break;
									}	
									cout << "Name" << setw(20) << "Roll Number" << setw(35) << "Address" << setw(23) <<"College" << setw(35) << "University Registration Number" << setw(45) << "Subject" << endl;
									for(i=0;i<nmech;i++)
									{
										Mech[i].display_mech();
									}
									break;
						default: cout << "Enter a valid branch:" << endl;
					}
					break;
			case 7: 
					int stream_choice;
					cout << "Enter the stream to which the student to be searched belongs:" << endl;
					cout << "71. Arts" << endl;
					cout << "72. Medical" << endl;
					cout << "73. Engineering" << endl;
					
					cout << "Enter your choice:";
					cin >> stream_choice;
					
					switch(stream_choice)
					{
						case 71: 
								cout << "Enter the roll number of the student to be searched:";
								cin >> roll;
								
								if (na == 0)
								{
									cout << "No entries present" << endl;
									break;
								}
								for(i=0;i<na;i++)
								{
									found = a[i].search_arts(roll);
									if (found == 1)
									{
										break;
									}
								}
								if (found == -1)
								{
									cout << roll << " does not exist" << endl;
								}
								break;
						
						case 72: 
								cout << "Enter the roll number of the student to be searched:";
								cin >> roll;
								
								if (nm == 0)
								{
									cout << "No entries present" << endl;
									break;
								}
								
								for(i=0;i<nm;i++)
								{
									found = m[i].search_medical(roll);
									if (found == 10)
									{
										break;
									}
								}
								if (found == -1)
								{
									cout << roll << " does not exist " << endl;
								}
								break;
								
						case 73: 
								cout << "Choose from the branch given below to which the student to be seached belongs:" << endl;
								cout << "a. CS" << endl;
								cout << "b. ETC" << endl;
								cout << "c. IT" << endl;
								cout << "d. MECH" << endl;
								
								fflush(stdin);
								cout << "Enter the branch code:";
								cin.get(branch_code);
					
								switch(branch_code)
								{
									case 'a':
											cout << "Enter the roll number of the student to be searched:";
											cin >> roll;
								
											if (ncs == 0)
											{
												cout << "No entries present" << endl;
												break;
											}
											
											for(i=0;i<ncs;i++)
											{
												found = cs[i].search_comp(roll);
												if (found == 1)
												{
													break;
												}
											}
											
											if (found == -1)
											{
												cout << roll << " does not exist" << endl;
											}											break;
											
									case 'b':
											cout << "Enter the roll number of the student to be searched:";
											cin >> roll;
											
											if (netc == 0)
											{
												cout << "No entries present" << endl;
												break;
											}	
											
											for(i=0;i<netc;i++)
											{
												found = e[i].search_etc(roll);
												if (found == 1)
												{
													break;
												}
											}
											if (found == -1)
											{
												cout << roll << " does not exist" << endl;
											}
											break;
									case 'c':
											cout << "Enter the roll number of the student to be searched:";
											cin >> roll;
								
											if (nit == 0)
											{
												cout << "No entries present" << endl;
												break;
											}	
											
											for(i=0;i<nit;i++)
											{
												found = IT[i].search_it(roll);
												if (found == 1)
												{
													break;
												}
											}
											if (found == -1)
											{
												cout << roll << " does not exist " << endl;
											}
											break;
									
									case 'd':
											cout << "Enter the roll number of the student to be searched:";
											cin >> roll;
								
											if (nmech == 0)
											{
												cout << "No entries present" << endl;
												break;
											}	
											
											for(i=0;i<nmech;i++)
											{
												found = Mech[i].search_mech(roll);
												if (found == 1)
												{
													break;
												}
											}
											if (found == -1)
											{
												cout << roll << " does not exist" << endl;
											}
											break;
											
									default: cout << "Enter a valid branch:" << endl;
											break;
								} 
							break;
							break;
					}
			case 8: return 0;
			default: cout << "Enter a valid option:" << endl;
		}
	}
	return 0;
}
