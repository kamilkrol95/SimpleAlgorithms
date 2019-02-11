#include <iostream>

using namespace std;

struct Data{
	char* f_name;
	char* l_name;
	int age;
};

int hash(Data data, int m){
	int res = 0;
	for(int i = 0; data.f_name[i] != '\0'; i++) res += (int)data.f_name[i];
//	res = res % m;
	for(int i = 0; data.l_name[i] != '\0'; i++) res += (int)data.l_name[i];
//	res = res % m;
	res = res + data.age;
	res = res % m;
	return res;
}

int main(){
	
	char* z = "AAA";
	int m = 100;
	int* h_tab = new int[m];
	int res;
	
	Data d;
	d.f_name = "Kaml";
	d.l_name = "Krol";
	d.age = 22;
	
//	for(int i = 0; z[i] != '\0'; i++) res += (int)z[i];
	
	cout << hash(d,m) << endl;
	
	delete [] h_tab;
	return 0;
}
