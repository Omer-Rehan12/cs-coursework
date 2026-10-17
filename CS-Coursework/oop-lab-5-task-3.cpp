#include<iostream>
using namespace std;
class patient{
	public:
		string name;
		int age;
		string condition;	
};
class hospital{
	patient patient[3];
	int i;
	public:
		void AddPatient(string name,string condition,int age,int i)
		{
			patient[i].name= name;
			patient[i].age= age;
			patient[i].condition= condition;
		}
		void display() {
			for(i=0;i<3;i++)
			{
				cout << "The details of patient " << patient[i].name << " are as follows:" << endl;
            	cout << "Age: " << patient[i].age << "\nCondition: " << patient[i].condition << "\n";
			}
		}
};
int main()
{
	hospital h1;
	int i;	
	for(i=0;i<3;i++)
	{
		string name,condition;
		int age;
		cout<<"Please enter the name,age and condition of patient"<<i+1<<"\n";
		cin>>name>>age>>condition;
		h1.AddPatient(name,condition,age,i);
	}
	h1.display();
	return 0;
}
