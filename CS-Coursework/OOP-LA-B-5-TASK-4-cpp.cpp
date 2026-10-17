#include<iostream>
using namespace std;
class warehouse{
	public:
	string location;
	int capacity;
	warehouse(string location,int capacity):location(location),capacity(capacity)  {}
}; 
class service{
	string id;
	warehouse* start;
	warehouse* end;
	public:
		service(string id,warehouse*on,warehouse*off):id(id),start(on),end(off){}
		
		void update(string newl )
		{
			end->location=newl;
		}
		void display()
		{
			cout<<" Delivery Service: "<<id<<""<<endl;
			cout<<"Starting point: Warehouse at "<<start->location<<" | Capacity: "<<start->capacity<<" units"<<endl;
			cout<<"Current Destination: Warehouse at "<<end->location<<" | Capacity: "<<end->capacity<<" units"<<endl;
		}
};
int main()
{
	warehouse starting("New York",1000);
	warehouse destination("Los Angeles",1500);
	service s1("DS-001",&starting,&destination);
	s1.display();
	s1.update("Chicago");
	s1.display();
	return 0;
}
