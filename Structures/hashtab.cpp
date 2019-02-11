// Hash table

#include <iostream>
#include <time.h>
#include <string>
#include <string.h>

using namespace std;

typedef unsigned long long int hashType;

struct Data{
    string firstName;
    string lastName;
    int age;
    hashType hash;
};

struct Node{
    Data data;
    Node* next;
};

hashType hashf(Data person){
    hashType hash = 0; // person.age;
    string name = person.firstName + person.lastName;
    for(int i = 0; i < name.length(); i++)
        hash ^= (int)name[i] << (i%8)*8;
    return hash;
}

Data newData(string first, string last, int age){
    Data person;
    person.firstName = first;
    person.lastName = last;
    person.age = age;
    person.hash = hashf(person);
    return person;
}


void printTab(Data* tab, int n){
    printf("List of people\n");
    for(int i = 0; i < n; i++)
        cout << tab[i].firstName << " " << tab[i].lastName << " " << tab[i].age << endl;
}

void printHTab(Node** tab, int n){
    for(int i = 0; i < n; i++){
        Node* tmp = tab[i];
        printf("->%d: ",i);
        while(tmp != NULL){
            cout << tmp->data.firstName << " " << tmp->data.lastName << ";  ";
            tmp = tmp->next;
        }
        printf("\n");
    }
}

void addToHTable(Node** tab, int n, Data data){
    hashType key = hashf(data) % n;
    Node* tmp;
    tmp = tab[key];
    tab[key] = new Node;
    tab[key]->data = data;
    tab[key]->next = tmp;
}

bool checkIfExist(Node** tab, int n, string fname, string lname){
    Data tmpPerson = newData(fname,lname,0);
    hashType key = hashf(tmpPerson) % n;
    Node* tmpNode = tab[key];
    while(tmpNode != NULL){
        if(tmpNode->data.firstName == fname && tmpNode->data.lastName == lname)
            return true;
        else tmpNode = tmpNode->next;
    } 
    return false;
}

int main(){
    int n;
    cin >> n;
    int N = 2*n;
    Data* tab = new Data[2*n];
    Node** hashTable = new Node*[N];
    for(int i = 0; i < N; i++)
        hashTable[i] = NULL;

    for(int i = 0; i < n; i++){
        string f,l;
        int a;
        cin >> f >> l >> a;
        Data newPerson = newData(f,l,a);
        // tab[i] = newPerson;
        addToHTable(hashTable,N,newPerson);
    }
    // printTab(tab,n);
    printHTab(hashTable,N);
    cout << "?  ";
    string f,l;
    cin >> f >> l;
    if(checkIfExist(hashTable,N,f,l)) cout << "EXIST\n";
    else cout << "NOT EXIST\n";

}