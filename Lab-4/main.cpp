/*
 Owen Neros
 Lab 4
 C++ Fall 2022
 This lab has us create a code that will input numbers from a file and display them along with a certain number of stars on a scale similar to a temperature scale
 */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string temp;
string inputFileName = "/Users/owenneros/Desktop/HelloWorld/C++/Lab-4/Lab-4/WeatherInput";
string readIn;

void value(int & x, int & o, int & y, int & z, int & q); // pre - value must be inputed to a external file
// post - function pulls the value and assigns it to a value 'x' and continues for howeever many values that are inputed
void tempout(int & x, int & o, int & y, int & z); // pre - value from input must be assigned to the int variable 'x'
// post - function takes the integer and divides by three and takes the remainder into consideration to compute the number of stars needed to display
void display(int & x, int & o, int & y, int & q);// pre - value must be assigned the number of stars to output from tempout function
// post - function displays the temp that was inputed and the number of stars while computing the correct spacing depending on the number of characters

int main() {
    
    
    int x=0;
    int y = x/3;
    int z = x%3;
    int o = 0;
    int q = 10 - o;
    
    cout << "     -30                  0                  30                  60                  90                  120" << endl;
    
    value(x, y, z, o, q); // Call this function in main to extract the numbers on the input file

    return 0;
}

void value(int & x, int & o, int & y, int & z, int & q){
    
    ifstream inFile;
    inFile.open(inputFileName);
    
    inFile >> x;
    
    while (inFile){
        tempout(x, o, y, z);
        display(x, o, y, q);
        inFile >> x; // keeps collecting the numbers until there are not any left and assigns them the variable x while the two functions are called.
    }

}
void tempout(int & x, int & o, int & y, int & z){
    o = 0;
    y = x/3;
    z = x%3; // finds remainder of x/3
    
    if (z == 2){ // this function adds 1 to the variable o, which is the number of stars, if the number is closer to said multiple of 3
        o = y + 1;
    }
    else if (z == -2){ // This does the same thing but for the negative numbers. Has to subtract 1 because I have not multiplied by -1 yet to assign stars
        o = y - 1;
    }
    else{
        o = y;
    }
}

void display(int & x, int & o, int & y, int & q){
    
    
    if (x > 0 && x < 121){ // excludes numbers not in range
        cout << x << "  ";
        if (x < 10){ // adds a space to positive single character numbers
            cout << " ";
        }
        if (x < 100){ // adds another space to any positive number with 2 or less characters
            cout << " ";
        }
        cout << "                     " << "|"; // Spacing line up
        for (int i = 0; i < o; i++){
            cout << "* ";
        }
        
        cout << endl;
    }
    else if(x < 121 && x > -31){
        o = o*-1;
        q = 10 - o; // variable q is number of spaces before star output for spacing
        
        cout << x << "   ";
        for (int i=0; i<q; i++){ // adds space per 'q' value
            cout << "  ";
        }
        if (x < 0 && x > -10){ // adds space for single character negative numbers
            cout << " ";
        }
        for (int i =0; i < o; i++){// adds stars per 'o' value
            cout << "* ";
        }
        if (x == 0){
            cout << "  "; // spacing line up for just one character
        }
        cout << "|" << endl;
    }
}
