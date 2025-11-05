#include <iostream> 
using namespace std; 

class Queue { 
	 int front, rear, size; 
	 string arr[10]; // fixed array size for simplicity 
	public: 
	 Queue(int s) { 
		 size = s; 
		 front = -1; 
		 rear = -1; 
	 } 
	 // Add new job 
	 void add(string job) { 
		 if ((rear + 1) % size == front) { 
			 cout << "Queue is full! Cannot add more jobs.\n";  return; 
		 } 
		 if (front == -1) { // first element 
			 front = 0; 
			 rear = 0; 
		 } else { 
			 rear = (rear + 1) % size; 
		 } 
		 arr[rear] = job; 
		 cout << "Print job \"" << job << "\" added to the spooler.\n"<<endl; 
	 } 
	 // Process job 
	 void process() { 
		 if (front == -1) { 
			 cout << "Queue is empty! No jobs to process.\n";  return; 
		 } 
			 cout << "Processing print job: \"" << arr[front] << "\"\n"<<endl; 
		 if (front == rear) {
		 // only one element left 
		 front = rear = -1; 
		 } else { 
		 front = (front + 1) % size; 
		 } 
	 } 
	 // Show all jobs 
	 void show() { 
		 if (front == -1) { 
			 cout << "Queue is empty.\n"; 
			 return; 
		 } 
		 cout << "Current Print Queue: "; 
		 int i = front; 
		 while (true) { 
			 cout << "\"" << arr[i] << "\""; 
			 if (i == rear) break; 
			 cout << " -> "; 
			 i = (i + 1) % size; 
		 } 
		 cout <<endl; 
	 } 
}; 

int main() { 
	 int n; 
	 cout << "Enter maximum number of print jobs in spooler: ";  cin >> n; 
	 Queue q(n); 
	 
	 // Print menu once 
	 cout << "\nPrinter Spooler Menu\n"; 
	 cout << "1. Add Print Job\n"; 
	 cout << "2. Process Print Job\n"; 
	 cout << "3. Show All Print Jobs\n"; 
	 cout << "4. Exit\n"; 
	 
	 int choice; 
	 string name;
	 do { 
		 cout << "Choose an option: "; 
		 cin >> choice; 
		 switch (choice) { 
			 case 1: 
				 cout << "Enter print job name: ";  cin >> name; 
				 q.add(name); 
				 break; 
			 case 2: 
				 q.process(); 
				 break; 
			 case 3: 
				 q.show(); 
				 break; 
			 case 4: 
				 cout << "\nExit! Thank you!\n"; 
				 break; 
			 default: 
				 cout << "Invalid option! Please select a valid option.\n"; 
		 } 
	 } while (choice != 4); 
	 return 0; 
}
