#include <iostream>
using namespace std;

class TaskNode {
public:
    string name;
    int priority;
    int execTime;
    TaskNode *next;

    // Constructor to initialize a new node
    TaskNode() {
        name = "";
        priority = 0;
        execTime = 0;
        next = NULL;
    }
};

class TaskScheduler {
public:
    TaskNode *head = NULL;



    // Insert a task in priority order (higher priority first)
    void insertTask(string taskName, int taskPriority, int taskExecTime) {
        TaskNode *newNode = new TaskNode();
        newNode->name = taskName;
        newNode->priority = taskPriority;
        newNode->execTime = taskExecTime;
        newNode->next = NULL;

        // If list is empty, newNode becomes head and tail
        if (head == NULL) {
            head = newNode;
        }

        // If newNode has higher priority than head, insert at head
        if (newNode->priority > head->priority) {
            newNode->next = head;
            head = newNode;
        }

        // Otherwise, find the correct position to insert
        TaskNode *current = head;
        TaskNode *previous = NULL;
        while (current != NULL && newNode->priority <= current->priority) {
            previous = current;
            current = current->next;
        }

        // Insert newNode between previous and current
        previous->next = newNode;
        newNode->next = current;

    }

    // Display all tasks 
    void displayTasks() {
        if (head == NULL) {
            cout << "No tasks scheduled." << endl;
        }

        TaskNode *temp = head;
        cout << "\nTasks in priority order:" << endl;
        while (temp != NULL) {
            cout << "Task Name: " << temp->name << ", Priority: " << temp->priority 
                 << ", Execution Time: " << temp->execTime << endl;
            temp = temp->next;
        }
    }

    // Execute tasks 
    void executeTasks() {
        while (head != NULL) {
            cout << "Executing task: " << head->name 
                 << " (Priority: " << head->priority 
                 << " ) in " << head->execTime << " ms..." << endl;
            deleteTask();
        }
    }

    // Delete the head node
    void deleteTask() {
        if (head == NULL) {
        }
        TaskNode *temp = head;
        head = head->next;
        delete temp;
    }
};

int main() {
    TaskScheduler scheduler;
    string name;
    int priority, execTime,num;
    
    cout<<"Enter the number of tasks : ";
    cin>>num;
    int n = num;
    while(num--){
        cout << "\nEnter task name: ";
        cin >> name;
        cout << "Enter task priority (higher number = higher priority): ";
        cin >> priority;
        cout << "Enter execution time: ";
        cin >> execTime;

        scheduler.insertTask(name, priority, execTime);
    } 

	if(n == 0){
		 cout << "No tasks scheduled." << endl;
    }
    else {
		scheduler.displayTasks();

		cout << "\nStarting task execution...\n";
		scheduler.executeTasks();
		cout<<"All tasks executed";
	}
    
    return 0;
}
