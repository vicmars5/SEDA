#include <iostream>

/*
 *
 *Autor:  UnoCuatro
*/

 using namespace std;

 int main () {
 	int i,j,k;
 	int suma, producto;
 	cout << "Dame un numero";
 	cin >> k;
 	cout << endl;

 	for(i = 1; i <= k; i++){
 		suma=0;
 		producto=0;
 		
 		cout << " " << i << " ";
 		suma+=i;
 		
 		for(j = 2; j <= i; j++){
	 		cout << "+ " << i << " ";
	 		suma+=i;
 		}
 		cout << "= " << suma << ", ";

 		cout << " " << i << " ";
 		producto=i;
 		
 		for(j = 2; j <= i; j++){
	 		cout << "* " << i << " ";
	 		producto*=i;
 		}

 		cout << "= " << producto << endl;
 	}
 	return 0;
 }