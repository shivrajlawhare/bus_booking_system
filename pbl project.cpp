#include<iostream>
#include<fstream>
using namespace std;
class bus{
public:
	string boarding_point,destination;
	static int count_sleeper;
	static int count_seater;
	bus(){
		boarding_point=" ";
		destination=" ";
	}

	void bus_get_data();
};
int bus :: count_seater;
int bus :: count_sleeper;

void bus::bus_get_data(){
	cout<<"Enter the boarding point."<<endl;
	cin>>boarding_point;
	cout<<"Enter the destination."<<endl;
	cin>>destination;
}

class sleeper:public bus{
public:
	string name;
	float price;
	int seat_no[30],bus_no;
	sleeper(){
			name=" ";
			price=0.0;
			bus_no=0;
			for(int i=0;i<30;i++){
				seat_no[i]=0;
			}
		}
	void get_data();
	void show_data();
	void booking(bus obj);
};

void sleeper::booking(bus obj){
	if((boarding_point==obj.boarding_point)&&(destination==obj.destination)){
		cout<<"Match for your bus is found."<<endl;
		show_data();
		cout<<"Total seat remaining are "<<(30-count_sleeper)<<endl;
		cout<<"Enter the number of seats you want to book."<<endl;
		int e;
		cin>>e;
		string msg1;
		int g[e];
		for(int i=0;i<e;i++){
			cout<<"Enter the seat number you want to book."<<endl;
			cin>>g[i];
			try{


			if(g[i]>30){
				throw msg1;
			}
			else{
				if(seat_no[g[i]-1]==0){
								seat_no[g[i]-1]=1;
								cout<<"Seat number "<<g[i]<<" is booked."<<endl;
								count_sleeper++;
							}
							else{
								cout<<"This seat is already booked please select another  seat."<<endl;
								i--;
							}
						}
			}
			catch(...){
				cout<<"Enter the valid seat number."<<endl;
				i--;

			}
			}
		cout<<"Seat number ";
		for(int j=0;j<e;j++){
		cout<<g[j]<<", ";
		}
		cout<<"are booked."<<endl;
		int p=e*price;
		cout<<"Total amount of booking is "<<p<<endl;
	}
	else{
		return;
	}
}

void sleeper::get_data(){
	cout<<"Enter the name of bus."<<endl;
	cin>>name;
	cout<<"Enter the bus number."<<endl;
	cin>>bus_no;
	cout<<"Enter the pricing per seat."<<endl;
	cin>>price;
}

void sleeper::show_data(){
	cout<<"----------"<<name<<"----------"<<endl;
	cout<<"Boarding point - "<<boarding_point<<endl;
	cout<<"Destination - "<<destination<<endl;
	cout<<"Bus number - "<<bus_no<<endl;
	cout<<"Price per seat - "<<price<<endl;
	cout<<"                          Driver side"<<endl;
	cout<<"Upper"<<"    "<<"Lower"<<"           "<<"Upper"<<"          "<<"Lower"<<endl;
	for(int i=0;i<5;i++){
		cout<<seat_no[i*6]<<"        "<<seat_no[i*6+1]<<"              "<<seat_no[i*6+2]<<"    "<<seat_no[i*6+3]<<"           "<<seat_no[i*6+4]<<"    "<<seat_no[i*6+5]<<endl;
		cout<<"("<<i*6+1<<")"<<"    "<<"("<<i*6+2<<")"<<"            "<<"("<<i*6+3<<")"<<"  "<<"("<<i*6+4<<")"<<"        "<<"("<<i*6+5<<")"<<"  "<<"("<<i*6+6<<")"<<endl;
		cout<<endl<<endl;
	}
}

class seater:public bus{
public:
	string name;
	float price;
	int seat_no[36],bus_no;
     seater(){
		name=" ";
		price=0.0;
		bus_no=0;
		for(int i=0;i<36;i++){
			seat_no[i]=0;
		}
	}
	void get_data();
	void show_data();
	void booking(bus obj);
};

void seater::get_data(){
	cout<<"Enter the name of bus."<<endl;
	cin>>name;
	cout<<"Enter the bus number."<<endl;
	cin>>bus_no;
	cout<<"Enter the pricing per seat."<<endl;
	cin>>price;
}

void seater::show_data(){
	cout<<"----------"<<name<<"----------"<<endl;
	cout<<"Boarding point - "<<boarding_point<<endl;
	cout<<"Destination - "<<destination<<endl;
	cout<<"Bus number - "<<bus_no<<endl;
	cout<<"Price per seat - "<<price<<endl;
	cout<<"                          Driver side"<<endl;
	for(int i=0;i<9;i++){
		cout<<seat_no[i*4]<<"       "<<seat_no[i*4+1]<<"                 "<<seat_no[i*4+2]<<"       "<<seat_no[i*4+3]<<endl;
		cout<<"("<<i*4+1<<")"<<"    "<<"("<<i*4+2<<")"<<"             "<<"("<<i*4+3<<")"<<"     "<<"("<<i*4+4<<")";
		cout<<endl;
		cout<<endl;
	}
}

void seater::booking(bus obj){
	if((boarding_point==obj.boarding_point)&&(destination==obj.destination)){
			cout<<"Match for your bus is found."<<endl;
			show_data();
			cout<<"Total seat remaining are "<<(36-count_seater)<<endl;
			cout<<"Enter the number of seats you want to book."<<endl;
			int e;
			cin>>e;
			int g[e];
			string msg;

			for(int i=0;i<e;i++){
				cout<<"Enter the seat number you want to book."<<endl;
				cin>>g[i];
				try{

				if(g[i]>37){
					 throw msg;
				}
				else{
					if(seat_no[g[i]]==0){
									seat_no[g[i]]=1;
									cout<<"Seat number "<<g[i]<<" is booked."<<endl;
									count_seater++;
								}
								else{
									cout<<"This seat is already booked please select another  seat."<<endl;
									i--;
								}
							}
			}
				catch(string msg)
						{
								cout<<"Enter valid seat number\n ";

								i--;

							}

				}

            cout<<"Seat number ";
			for(int j=0;j<e;j++){
			cout<<g[j]<<", ";
			}
			cout<<"are booked."<<endl;
			int p=e*price;
			cout<<"Total amount of booking is "<<p<<endl;
		}
		else{
			return;
		}
}

int main(){
	int a,m,n;
	fstream s1,s2;
	cout<<"How many sleeper buses data you want to enter."<<endl;
	cin>>m;
	cout<<"How many seater buses data you want to enter."<<endl;
	cin>>n;
	seater b[n];
	sleeper c[m];
	do{
		cout<<"Enter 1 to enter bus details."<<endl;
		cout<<"Enter 2 to book the tickets."<<endl;
		cin>>a;
		switch(a){
			case 1:{

				cout<<"Enter the data for sleeper buses."<<endl;
				s1.open("C:/Users/Shivraj Lawhare/OneDrive/Desktop/sleeper.txt",ios::binary|ios::out);
				for(int i=0;i<m;i++){
					cout<<"Enter the data of "<<i+1<<" bus"<<endl;
					c[i].bus_get_data();
					c[i].get_data();
					s1.write((char*) &c[i], sizeof(c[i]));
					c[i].show_data();
				}
				s1.close();
				cout<<"Enter the data for seater buses."<<endl;
				s2.open("C:/Users/Shivraj Lawhare/OneDrive/Desktop/seater.txt",ios::binary|ios::out);
				for(int i=0;i<n;i++){
					cout<<"Enter the data of "<<i+1<<" bus"<<endl;
					b[i].bus_get_data();
					b[i].get_data();
					s2.write((char*) &b[i], sizeof(b[i]));
					b[i].show_data();
				}
				s2.close();
				break;
			}
			case 2:{
				cout<<"Enter 1 to book seater bus."<<endl;
				cout<<"Enter 2 to book sleeper bus."<<endl;
				int d;
				cin>>d;
				if(d==1){
					seater d[n];
					s2.open("C:/Users/Shivraj Lawhare/OneDrive/Desktop/seater.txt",ios::binary|ios::in);
					for(int i=0;i<n;i++){
						s2.read((char*) &d[i], sizeof(d[i]));
					}
					s2.close();

					bus obj;
					obj.bus_get_data();
					for(int i=0;i<n;i++){
						d[i].booking(obj);
					}
				}
				else{
       				sleeper e[m];
					s1.open("C:/Users/Shivraj Lawhare/OneDrive/Desktop/sleeper.txt",ios::binary|ios::in);
					for(int i=0;i<m;i++){
					     s1.read((char*) &e[i], sizeof(e[i]));
					}
					s1.close();
					bus obj;
					obj.bus_get_data();
					for(int i=0;i<m;i++){
						e[i].booking(obj);
					}

				}

				break;
			}
			}

	}while(a<3);
	return 0;
}
