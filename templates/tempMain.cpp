#include <iostream>
#include <string>
#include "matrix.h"

using namespace std;

template <typename T1>
void demoTemplate(Matrix<T1>& M, T1 array1[][MAXCOLS], T1 array2[][MAXCOLS]);

int main()
{
    string Str1[MAXROWS][MAXCOLS] = 
       { 
	  {"Congra", "y", "ar"},
	  {"alm", "don", "La"}
       };
    string Str2[MAXROWS][MAXCOLS] = 
       { 
	  {"tulations", "ou", "e"},
	  {"ost", "e    the", "b!"}
       };
    int Num1[MAXROWS][MAXCOLS] = 
       {
	  {1,2,3},
	  {4,5,6}
       };
    int Num2[MAXROWS][MAXCOLS] = 
       {
	  {6,5,4},
	  {3,2,1}
       };
    float f1[MAXROWS][MAXCOLS] =
      {
        {1.6,2.5,3.4},
        {4.3,5.2,6.1}
      };
    float f2[MAXROWS][MAXCOLS] =
      {
        {5.1,5.2,4.3},
        {3.4,2.5,1.6}
      };
    
    Matrix<string> stringMatrix;
    Matrix<int> intMatrix;
    Matrix<float> floatMatrix;
    
    cout << "\nDemonstrating with string matrix:" << endl;
    demoTemplate(stringMatrix, Str1, Str2);

    cout << "\nDemonstrating with int matrix:" << endl;
    demoTemplate(intMatrix, Num1, Num2);

    cout << "\nDemonstrating with float matrix:" << endl;
    demoTemplate(floatMatrix, f1, f2);
    
    cout << "\n" << endl;
    return 0;                
}


template <typename T1>
void demoTemplate(Matrix<T1>& M, T1 array1[][MAXCOLS], T1 array2[][MAXCOLS])
{
    M.setMatrix(array1);
    cout << "\nMatrix set to first array" << endl;
    M.printMatrix();

    M.addMatrix(array2);
    cout << "\nMatrix incremented by second array" << endl; 
    M.printMatrix();
}
