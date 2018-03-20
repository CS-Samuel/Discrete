//------------------------------------------------------------------------------------------------------------
//
// Name:  Samuel Weems
//
// Course:  CS 2433, Spring 17, Cerise Wuthrich
//
// Purpose:  This program reads integers from an input file into two separate sets.
//           The elements of both sets are displayed.
//           The intersection, union, complements, and difference (both ways) are found and displayed.
//           The Universal set is integers 1 - 30 inclusive
//------------------------------------------------------------------------------------------------------------


#include<iostream>
#include<fstream>
#include<set>


using namespace std;

// Output Function Prototype and global variable for output to file

void Print (set<int> printSet);
ofstream outputFile;

// Main Function

int main (){
    
    set<int> A, B;                                                                 // Declares sets A and B to receive two sets from data file
    set<int> Intersect, Union, AComp, BComp, AminusB, BminusA;                     // Declares Sets to be found
    int input = 0;                                                                 // Variable for data input
    
// Declare Iterators (pointers)
    
    set<int>::iterator pointer1;
    set<int>::iterator pointer2;
    
// Open Data File
    
    ifstream inputFile;
    inputFile.open ("sets.dat");

// Read file data into set A (-999 as sentinel value that indicates end of first set)
    
    while (input != -999)
    {
        inputFile >> input;
        if (input != -999)
            A.insert(input);
    }
    
// Read file data into set B
    
    while (inputFile >> input)
        B.insert(input);
    
// Find the Intersection of A and B
    
    for (pointer1 = A.begin(); pointer1 != A.end(); pointer1++)                         // Add any element in both A and B to the Intersect Set
        for (pointer2 = B.begin(); pointer2 != B.end(); pointer2++)
            if (*pointer1 == *pointer2)
                Intersect.insert (*pointer1);
    
// Place Universal Set into AComp and BComp

    for (int i=1; i<31; i++)
    {
        AComp.insert(i);
        BComp.insert(i);
    }
    
// Add Set A into Union Set and AminusB, Remove Set A from AComp
   
    for (pointer1 = A.begin(); pointer1 != A.end(); pointer1++)
    {
        Union.insert(*pointer1);
        AminusB.insert(*pointer1);
        AComp.erase(*pointer1);                                                         // Completes A Complement Set Operation
    }

// Add Set B into Union Set and BminusA, Remove Set B from AminusB and BComp
    
    for (pointer2 = B.begin(); pointer2 != B.end(); pointer2++)
    {
        Union.insert(*pointer2);                                                        // Completes Union Set Operation
        BminusA.insert(*pointer2);
        AminusB.erase(*pointer2);                                                       // Completes A-B Set Operation
        BComp.erase(*pointer2);                                                         // Completes B Complement Set Operation
    }

// Remove Set A from BminusA
    
    for (pointer1 = A.begin(); pointer1 != A.end(); pointer1++)
        BminusA.erase(*pointer1);                                                       // Completes B-A Set Operation
    
// Create Output File and display information
    
    outputFile.open ("weems_samuel_sets.txt");
    
    outputFile << "Samuel Weems" << endl << endl;                                       // Output Name
    
    outputFile << "Set A = {";                                                          // Output Set A
    Print (A);

    outputFile << "Set B = {";                                                          // Output Set B
    Print (B);
    
    outputFile << "The intersection of Sets A and B = {";                               // Output Intersection of A and B
    Print (Intersect);
    
    outputFile << "The union of Sets A and B = {";                                      // Output Union of A and B
    Print (Union);
    
    outputFile << "A - B = {";                                                          // Output A - B
    Print (AminusB);
             
    outputFile << "B - A = {";                                                          // Output B - A
    Print (BminusA);
    
    outputFile << "A Complement = {";                                                   // Output A Complement
    Print (AComp);
             
    outputFile << "B Complement = {";                                                   // Output B Complement
    Print (BComp);
    
    outputFile.close();

    return 0;
}

// Output Function

void Print (set<int> printSet)
{
    int counter = 0;                                                                    // Counter variable used for output formatting
    set<int>::iterator pointer1;
    
    for (pointer1 = printSet.begin(); pointer1 != printSet.end(); pointer1++)
        {
            outputFile << *pointer1;
            counter = counter + 1;
            if (counter < printSet.size())
                outputFile << ", ";
        }
             
    outputFile << "}" << endl << endl;
   
}
