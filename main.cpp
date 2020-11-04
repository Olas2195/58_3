#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#define SIZE 3

using namespace std;

int *m = new int[2000];

class program {
	ofstream plik1;
	ifstream pliki[SIZE];
	
	bool pierwszy=true;
	bool znaleziono;
	string liczba1[SIZE];
	string liczba2[SIZE];
	long liczba[SIZE];
	long max[SIZE];
	int licznik;
	char* endptr;
	
	public:
		program();
		~program();
		void maxZPliku();
		void wypisanie();
};

program::program() {
	plik1.open("wy.txt");
	pliki[0].open("dane_systemy1.txt");
	pliki[1].open("dane_systemy2.txt");
	pliki[2].open("dane_systemy3.txt");
}
void program::maxZPliku() {	
	licznik=0;
	if(pliki[0].good() && pliki[1].good() && pliki[2].good() ) {
		while(!pliki[0].eof() && !pliki[1].eof() && !pliki[2].eof() ) {
			int system = 1;
			for(int i=0; i<SIZE; i++) {
	            pliki[i]>>liczba1[i] >> liczba2[i];
            	liczba[i]=strtol(liczba2[i].c_str(), &endptr, system*= 2);
	        }
	        if(pierwszy) {
	            for(int i=0; i<SIZE; i++){
	                max[i]=liczba[i];
	                cout<<max[i]<<" ";
	        	}
	            licznik++;
	            cout<<"m"<<licznik<<"\n";
	            pierwszy=false;
	        }
			else {
				znaleziono=false;
	            for(int i=0; i<SIZE; i++){
	                if(liczba[i]>max[i]) {
	                    max[i] = liczba[i];
	                    znaleziono=true;
	                    cout<<max[i]<<" ";
	                }
	            }
	            if(znaleziono) {
	            	licznik++;
	            	cout<<"m"<<licznik<<"\n";
				}
	        }
		}
	}	
}
void program::wypisanie() {
	plik1<<licznik<<"\n";
	cout<<licznik<<"\n";
}
program::~program() {
	plik1.close();
	pliki[0].close();
	pliki[1].close();
	pliki[2].close();
}

int main(int argc, char** argv)
{
	program p;
	p.maxZPliku();
	p.wypisanie();
	
	return 0;
}
