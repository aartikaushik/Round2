#include<iostream>
#include <ctime>
#include<string>
using namespace std;

void encrypt( char [ ] ); // prototypes of functions used in the code
void decrypt( char * ePtr );

int i=1; // for nodeNumber (unique incremental integral value)

// structure of node
struct node
{
    string data; // information
    int nodeNumber; // unique incremental value
    unint32_t nodeId; // 32 bit id uniquely identifies a node
    struct node* referenceNodeId; // address of parent node
    vector<string> childReferenceNodeId; // containing all child nodes
    string genesisReferenceNodeId; // root node address
    string HashValue; // hash of complete structure
    time_t now;  // current date/time based on current system
};

struct Node* new_node(string key, unint32_t uni_id)
{
    struct Node* temp = new node; // creating new node

    //filling all parameters
    temp->data = key;
    temp->referenceNodeId = NULL; // initially keep the parent node null
    temp->nodeNumber = i+1; // serial no. (unique incremental value)
    fill(temp->childReferenceNodeId.begin(), temp->childReferenceNodeId.end(), ""); // initially keep all child node as NULL
    temp->nodeId = uni_id; 
    temp->now = time(0);
    temp->HashValue = myhash(node const& s);
    return temp;
};

// function for computing hash of complete structure (used in boost)
std::size_t myhash(node const& s)
{
    std::size_t res = 0;
    hash_combine(res,s.now);
    hash_combine(res,s.data);
    hash_combine(res,s.nodeNumber);
    hash_combine(res,s.nodeId);
    hash_combine(res,s.referenceNodeId);
    hash_combine(res,s.childReferenceNodeId);
    hash_combine(res,s.genesisReferenceNodeId);
    return res;
}


int main()
{
    node obj;
    uint32_t id = reinterpret_cast<uint32_t>(&obj); //32 bit id uniquely identifies a node
    int owner_id; // assuming owner id to be within integer range i.e -32,768 to 32,767 or -2,147,483,648 to 2,147,483,647
    string name,info,all;
    float val;
    cout<<"Enter owner id";
    cin>>owner_id;
    cout<<"Enter value in floating point integer fixed upto 2 decimal places"; // assuming the value entered will be upto 2 decimal places only otherwise can use setprecision function
    cin>>val;
    cout<<"Enter owner name";
    getline(cin,name);
    all = name + to_string(owner_id) + to_string(val); // to_string defined in <string> headerfile. converts an integer into string
    info = encrypt(all);
    struct node* np = new_node(info,id); // calling new_node
}
//for encrypting data
void encrypt (char e[] ) 
{
for( int i=0; e[i] != '\0'; ++i ) ++e[i];
} 

//for decrypting data
void decrypt( char * ePtr ) {
for( ; * ePtr != '\0'; ==* ePtr ) --(* ePtr);
}



