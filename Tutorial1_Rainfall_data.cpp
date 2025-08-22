#include <iostream>
using namespace std;

int main(){
	
	
	float rainfall[3][4];
	
	for(int i=0;i<3;i++){
		cout<<"\nEnter the rainfall data for city "<<i+1<<"\n";
		for(int j=0;j<4;j++){
		cout<<"Enter Rainfall for month "<<j+1<<": ";
		cin>>rainfall[i][j];
		}
	}
	
	cout<<"\nRainfall data : \n";
	cout<<"City\tMonth1\tMonth2\tMonth3\tMonth4\tAverage"<<endl;
	
	for(int i=0;i<3;i++){
		float avg;
		float sum =0;
		cout<<"City "<<i+1<<"\t";
		for(int j=0;j<4;j++){
			cout<<rainfall[i][j]<<"\t";
			sum += rainfall[i][j];
		}
		avg = sum/4;
		cout<<avg<<endl;
	}
	

	return 0;
}
