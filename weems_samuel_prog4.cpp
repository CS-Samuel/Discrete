//---------------------------------------------------------------------------------------------------------
//
// Name:  Samuel Weems
//
// Course:  CS 2433, Spring 17, Cerise Wuthrich
//
// Purpose:  This program uses reads integers into an n x n array and then determines whether the matrix
//           is a valid adjacency matrix for a simple graph (no loops and no parallel edges). If the matrix
//           represents a valid adjacency matrix, it will find the degree of each vertex and the total
//          number of edges. If the matrix does not represent a valid adjacency matrix it will output
//          INVALID. The first input is the number of matrices, followed by n and then 0's and 1's for
//          each matrix.The input file is "adj.dat" and the output file is "weems_samuel_adj.txt"
//---------------------------------------------------------------------------------------------------------


#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main() {
    
    int numMatrices, degreeSum, numEdges;
    int n = 0;
    
    string degreeLabels = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    ifstream inputFile;                                         // Input and Output files
    inputFile.open ("adj.dat");
    ofstream outputFile;
    outputFile.open ("weems_samuel_adj.txt");
    
    inputFile >> numMatrices;                                   // Input for the number of Matrices
    
    outputFile << "Samuel Weems" << endl;                       // Output of name
    
    for (int i=0; i<numMatrices; i++)                           // Loop for number of Matrices
    {
        inputFile >> n;                                         // Input for Matrix size (n x n)
        
        outputFile << "Matrix " << i+1 << endl;                 // Output current Matrix number
        
        int** matrix;                                               // Pointer to pointers
        matrix = new int*[n];        // Create an array of pointers size n (# rows)
        for (int j=0; j<n; j++)      // Create array of integers [columns] pointed to by pointers
            matrix[j] = new int[n];
        
    
        for (int r=0; r<n; r++)                  // Loop for rows
            for (int c=0; c<n; c++)              // Loop for columns (add 1 to take in <enter>s)
                inputFile >> matrix[r][c];       // Take single value and convert to integer
              
            
            
        
        
        int *degreeArray = new int[n];        // Define array to hold values for degrees of each vertex
        for (int j=0; j<n; j++)               // Set array values to 0
            degreeArray[j]=0;
        
        for (int r=0; r<n; r++)              // Loop through matrix values
        {
            if (matrix[r][r] !=0)            // Check that diagonal is all 0's
                goto INVALID;
            
                                            // Check for symmetry and that all values are 1 or 0
            for (int c=0; c<n; c++)
            {
                if (((matrix[r][c] < 0) || (matrix[r][c] >1)) || (matrix [r][c] != matrix[c][r]))
                    goto INVALID;
                if (matrix[r][c] == 1)                   // Sum rows and store in degreeArray
                    degreeArray[r] = degreeArray[r]+1;
            }
         }
        
        degreeSum = 0;                                    // Set sum of degrees to 0
        for (int j=0; j<n; j++)                           // Sum all degrees
            degreeSum = degreeSum + degreeArray[j];
        
        numEdges = degreeSum/2;                                 // Calculate # of edges
        
        if (numEdges ==0)                                       // Invalidate Empty Matrices
            goto INVALID;
        
        outputFile << "Degree of:" << endl;                     // Output Valid Matrix information
        
        for (int j=0; j<n; j++)
            outputFile << "Vertex " << degreeLabels[j] << ": " << degreeArray[j] << endl;
        
        outputFile << "Number of edges: " << numEdges;
        goto VALID;
        

    INVALID:  outputFile << "INVALID";
    VALID:    outputFile << endl << endl;
   
        for (int i=0; i<n; i++)                                  // Free up memory
            delete[] matrix[i];
        delete[] matrix;
        delete[] degreeArray;
        matrix = NULL;
        degreeArray = NULL;
    }
    
    inputFile.close();          // Close files
    outputFile.close();
    
     return 0;
}

    
    
    
    
    
    







