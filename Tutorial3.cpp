#include <iostream>
#include <string>
using namespace std;

// Simple hash function for IP addresses: sum of ASCII values mod s (servers)
int hashIP(string ip) {
    int sum = 0;
    int len = 0;

    // Count string length manually
    while (ip[len] != '\0') {
        len++;
    }

    // Add ASCII values of each character
    for (int i = 0; i < len; i++) {
        sum += ip[i];
    }

    return sum;
}

int main(){
	int s,r,hash_val;
	
	cout<<"Enter no. of servers : ";
	cin>>s;
	
	cout<<"\nEnter no. of requests : ";
	cin>>r;
	
	string hash_server[s];
	// Initializing the hash_table values by 0
	for(int i=0;i<s;i++){
		hash_server[i]="";
	}
	
	cout<<endl;
	// Entering the value of requests
	for(int i=0;i<r;i++){
		string ip;
        cout << "\nEnter IP address for request " << i + 1 << ": ";
        cin >> ip;
        
        // Convert IP to hash value
        hash_val = hashIP(ip) % s;
		
		//Handling Collision using Linear Probing
		if(hash_server[hash_val] == ""){
			hash_server[hash_val] = ip;
		}
		else{
			for(int j=hash_val;j<s-1;j++){
				hash_val = hash_val+1;
				if(hash_server[hash_val] == ""){
					hash_server[hash_val] = ip;
					break;
				}
	
			}
			if (hash_val == s-1){
				for(int j=0;j<s-1;j++){
					if(hash_server[j] == ""){
						hash_server[j] = ip;
						break;
					}
				}				
			}
		}
		cout << "Request (IP) " << ip << " assigned to Server " << hash_val << endl;
	}
	
	// Displaying the request in server hash table
	cout << "\n=== Server Assignment Table ===" << endl;
	for (int i = 0; i < s; i++) {
		cout << "Server " << i << ": ";
		if (hash_server[i] != "")
			cout << hash_server[i];
		else
			cout << "Idle";
		cout << endl;
	}

	return 0;
}
