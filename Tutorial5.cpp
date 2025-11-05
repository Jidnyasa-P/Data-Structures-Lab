#include <iostream>
#include <string>
using namespace std;

class stack{
	public:
	int top;
	int *ptr;
	
	stack()
	{
		top = -1;
	}
	
	
	void push(int p){
			top += 1;
	}
	
	void pop(){
		if(top == -1){
			cout<<"\nEmpty";
		}
		else{
		top -= 1;
		}
	}
	
	int isEmpty(){
		if(top == -1){
			return 1;
		}
		else{
			return 0;
		}
	}
	
};

int main()
{
	stack s;
	int n;
	cout<<"Enter the number of elements : "<<endl;
	cin>>n;
	string exp[n];
	cout<<"Enter the expression : ";
	
	for(int i=0;i<5;i++){
	cin>>exp[i];
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<exp[i];
	}
	
	int *ptr;
	ptr = &exp[0];
	for(int i=ptr;i!='\0';i++){
		if(ptr == '(' || ptr == '[' || ptr == '{'){
			s.push(ptr);
			ptr++;
		}
		else{
			if((ptr == ')' && s.top == '(') || (ptr== ']' && s.top == '[' )|| (ptr == '}' && s.top == '{')){
				s.pop();
				ptr++;
			}
		}
	}
				
	return 0;
}
