#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

int *m = new int[2000];

void maxZPliku(string nazwaPliku, int system)
{
	ifstream plik2;
    plik2.open(nazwaPliku);
    string liczba1, liczba2;
    bool pierwszy = true;
    long liczba, max;
    int licznik=0;
    int x=0;
    char* endptr;
   
    if(plik2.good()) {
      	while(!plik2.eof()) {
           	plik2>>liczba1>>liczba2;
           	liczba =  strtol(liczba2.c_str(), &endptr, system);
           
           	if(pierwszy) {
                max = liczba;
                licznik=1;
                pierwszy = false;
           	}
           	else {
              	if(liczba > max) {
                   max = liczba;
                   licznik=1;
            	}
        	}
        	m[x]=licznik;
        	x++;
       	}
    }
}

void zliczenie() {
	
}

int main(int argc, char** argv)
{
	ofstream plik1;
	plik1.open("wy.txt");
	maxZPliku("dane_systemy1.txt", 2);    
 	maxZPliku("dane_systemy2.txt", 4);
 	maxZPliku("dane_systemy3.txt", 8);
 	
 	

 	plik1.close();
	return 0;
}
