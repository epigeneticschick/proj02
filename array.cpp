/* array.cpp defines "C style" array operations
 * Name:
 * Date:
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */
 
#include "array.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

void initialize(double *a, unsigned size) {
	int val = 0;
	for (unsigned i = 0; i < size; i++) {
		val = i+1;
		a[i] = val;
	}
}
 
void print(double *a, unsigned size) {
	//prints values in array
	for (unsigned i = 0; i < size; i++) {
		cout << *a << '\t';
		a++;
	}
}		

double average(double *a, unsigned size) {
	//Calculates the average value for an array
	double value = 0;
	for(unsigned i = 0; i < size; i++){
		value += *a;
		a++;
	}
	value = value/size;
	return value;
}

double sum(double *a, int size){
	//Calculates the sum of values in an array
	double value = 0;
	for(int i = 0; i < size; i++){
		value += *a;
		a++;
	}
	return value;
}
void read(istream& in, double *a, int size){
	//This function should read size values from in and store them in a.
	string input;
	for(int i = 0; i < size; i++){
		getline(in, input);
		a[i]= atof(input.c_str());
	}

}


void resize(double *&a, int oldSize, int newSize){
	// changes the size of an array
	double *b = new double [newSize];
	int difference = newSize - oldSize;
	if (newSize > oldSize){
		for(int i = 0; i <oldSize; i++){
			b[i]= a[i];
		}
		for(int i = oldSize; i < difference; i++){
			b[i] = 0;
		}

	}
	if (oldSize > newSize){
		for(int i = 0; i <newSize; i++){
			b[i]= a[i];
		}
	}
	delete [] a;
	a = b;
	//delete [] b;
}

void fill(const string& fileName, double *&a, int &numValues){

	// opens file stream
	ifstream fin(fileName.c_str());

	// extracts numValues and puts them in fin
	fin >> numValues;

	// delets junk values for the array
	delete [] a;

	// creates a new array with an adequate size
	a = new double[numValues];

	// adds values from array to file
	for(int i=0; i <numValues; ++i){
		fin >> a[i];
	}

	// close file stream
	fin.close();


}
void concat(double *a1, int size1, double *a2, int size2, double *&a3, int &size3){

	//intializes size 3
	size3 = size1 + size2;

	// deletes junk values in a3
	delete a3;

	// creates new array
	a3 = new double[size3];

	// adds values from array 1 to array 3

	for(int i = 0; i < size1; i++){
		a3[i]= a1[i];
	}

	// adds values from array 2 to array 3
	for(int i = 0; i < size2; i++){
		a3[i+size1]= a2[i];
	}

}

