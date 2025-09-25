#include <iostream>
#include <string>
using namespace std;

class node
{
	public:
	string customer_name;
	node *next;
};

class queue
{
	node *front;
	node *rear;
	
	public :
	
	queue(){
		front = NULL;
		rear = NULL;
	}
	
	void enqueue(string name){
		node *temp = new node{name,nullptr};
		if(rear == nullptr){
			front = rear = temp;
			cout<<name<<" joined the line\n"<<endl;
			return;
		}
		rear->next = temp;
		rear = temp;
		cout<<name<<" joined the line\n"<<endl;
	}
	
	void dequeue(){
		if(front == nullptr){
			cout<<"No Customers in the line\n"<<endl;
			return;	
		}
		else {
		node *temp = front;
		cout<<temp->customer_name<<"'s order is ready. They leave the line.\n"<<endl;
		if(front->next == nullptr){
			front = rear = nullptr;
		}
		else{
		front = front->next;
		}
		
		delete temp;
	}
	}
	
	void display(){
		if(front == nullptr){
			cout<<"Line is empty\n";
		}
		else{
		cout<<"Current Line : ";
		node *temp = front;
		while(temp!=nullptr){
			cout<<temp->customer_name;
			if(temp->next!=nullptr){
				cout<<"->";
			}
			temp=temp->next;
		}
		cout<<endl;
	}
	}
};

int main()
{
	queue q;
	string name;
	int choice;
	
	cout<<"\n--- Coffee Shop Queue Menu ---\n";
    cout<<"1. New Customer Arrival (Enqueue)\n";
	cout<<"2. Serve Customer (Dequeue)\n";
	cout<<"3. Show Queue\n";
	cout<<"4. Exit\n";
		
	do {
		cout<<"Choose an option: ";
		cin>>choice;
		
		switch(choice){
			case 1 :{
				cout<<"\nEnter Customer name : ";
				cin>>name;
				q.enqueue(name);
				break; 
			}
			case 2 :{
				q.dequeue();
				break; 
			}
			case 3 : {
				q.display();
				break; 
			}
			case 4 : {
				break;
			}
		}
	}
		while(choice != 4);
		
	return 0;
}
