#include <iostream>
using namespace std;

int main(){
	
	
	float temperature[3][7];
	
	for(int i=0;i<3;i++){
		cout<<"\nEnter the temperature data for city "<<i+1<<"\n";
		for(int j=0;j<7;j++){
		cout<<"Enter temperature for day "<<j+1<<": ";
		cin>>temperature[i][j];
		}
	}
	
	cout<<"\nTemperature data : \n";
	cout<<"City\tDay1\tDay2\tDay3\tDay4\tDay5\tDay6\tDay7\tAverage"<<endl;
	
	for(int i=0;i<3;i++){
		float avg;
		float sum =0;
		cout<<"City "<<i+1<<"\t";
		for(int j=0;j<7;j++){
			cout<<temperature[i][j]<<"\t";
			sum += temperature[i][j];
		}
		avg = sum/7;
		cout<<avg<<endl;
	}
	

	return 0;
}

