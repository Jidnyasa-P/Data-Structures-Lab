#include <iostream>
using namespace std;

class insertion_sort{
	public:
	int m;
	int key;
	int player[12];
	void function()
{
	int j;
	cout<<"\nBy Insertion Sort\n";
	cout<<"\nEnter the total number of players ";
	cin>>m;
	cout<<"Enter the numbers :\n";
	for(int i=0;i<m;i++){
		cin>>player[i];
	}
	cout<<"The number entered by players before sorting are ";
	for(int i=0;i<m;i++){
		cout<<player[i]<<" ";
	}
	
	for(int i=1;i<m;j++){
		key=player[i];
		j=i-1;
		
		while(j>=0 && player[j]>key)
		{
			player[j+1] = player[j];
			j=j-1;
		}
		
		player[j+1] = key;
	}
}
};

int main(){
	insertion_sort val;
	val.function();
	
	return 0;
}
