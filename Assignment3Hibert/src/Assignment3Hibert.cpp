//============================================================================
// Name        : Assignment2Part3.cpp
// Author      : Madhukar BS
// Version     :
// Copyright   : NA
// Description :Form Hilbert Matrix, compute Inverse, get back the Identity and Original matrix from the computed Inverse.
//============================================================================
#include <iostream>
#include <cmath>
#include<iomanip>
/***** Complete this program. *****/

using namespace std;

const int MAX_SIZE = 5;  // maximum matrix size

// Error codes for singular matrices, which cannot be inverted.
enum ErrorCode {ZERO_ROW, SINGULAR_MATRIX, NO_CONVERGENCE};

/**
 * Invert a matrix using the LU Decomposition Algorithm.
 * @param n the size of the matrix.
 * @param A the matrix to invert.
 * @param Ainv the computed inverse of A.
 */
void invert(const int n, double A[][MAX_SIZE], double Ainv[][MAX_SIZE]);

/**
 * Decompose matrix A by computing lower and upper triangular matrices
 * L and U and permutation matrix P so that LU = PA. Store L-I and U in LU.
 * A and LU can be passed the same matrix.
 * @param n the size of the matrices.
 * @param A the matrix to decompose.
 * @param LU the computed decomposition such that LU = PA.
 * @param ps the computed permuted row indices.
 */
void decompose(const int n, double A[][MAX_SIZE],
               double LU[][MAX_SIZE], int ps[MAX_SIZE]);

/**
 * Solve Ax = b using LU from function decompose.
 * @param n the size of the matrices and vectors.
 * @param A the coefficient matrix.
 * @param x the computed solution vector.
 * @param b the right-hand-side vector.
 * @param ps the permuted row indices.
 */
void solve(const int n, double LU[][MAX_SIZE],
           const double b[], double x[], const int ps[MAX_SIZE]);

/**
 * Indicate a singular matrix.
 * @param code the error code.
 */
void singular(const ErrorCode code);

/**
 * Forms Hilbert matrix defined as H[i,j] = 1/(i+j-1)
 * @param size the size of the nxn matrix
 */

void formHilbertnDisplay(int size);

/**
 * Multiplies 2 given matrices
 * @param matrix1
 * @param matrix2
 * @param mutiply - is the product of the 2 matrices.
 */

void multiplyMatrices(double matrix1[][MAX_SIZE],double matrix2[][MAX_SIZE],double multiply[][MAX_SIZE],int size);
/**
 * The main.
 * Repeatedly prompt the user for the size of the Hilbert matrix
 * and then perform the computations.
 */
int main()
{	int size=0 ;

	for(int i=0;;i++){
		cout<<"Size of Hilbert matrix (1-5)? ";
		cin >> size;

		  if(size <=0 || size>5)
			  break;

    formHilbertnDisplay(size);



	}
    cout << endl << "Done!" << endl;
    return 0;
}

void displayMatrix(double matDisplay[][MAX_SIZE], int size){


	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(6);

	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<right<<setw(15)<<matDisplay[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}


void formHilbertnDisplay(int size){
	  if(size>0 && size < 6){
	 double inPut[size][MAX_SIZE],inv[size][MAX_SIZE],multiply[size][MAX_SIZE] ;
	 for(int i=0;i<size;i++){
	     	for(int j=0;j<size;j++){
	     		inPut[i][j] = (static_cast<double>(1))*1.0/(i+j+2-1); //index start from zero, hence adding 2 to offset i and j by 1
	     	}
	     }
	 cout<<endl;
	 cout<<"Hilbert matrix of size "<<size<<":"<<endl<<endl;
	 displayMatrix(inPut,size);
	 //Inverse of a matrix
	 invert(size,inPut,inv);
	 cout<<"Hilbert matrix inverted:"<<endl<<endl;
	 displayMatrix(inv,size);

	 //Mutiplying matrices input and its inverse to get Identity Matrix
	 multiplyMatrices(inPut,inv,multiply,size);
	 cout<<"Hilbert matrix multiplied by its inverse:"<<endl<<endl;
	 displayMatrix(multiply,size);

	 //Inverting the Inverse Hilbert matrix to see if we get back the original Hilbert Matrix
	 invert(size,inv,inPut);
	 cout<<"Inverse Hilbert matrix inverted:"<<endl<<endl;
	 displayMatrix(inPut,size);

	  }
}

void multiplyMatrices(double matrix1[][MAX_SIZE],double matrix2[][MAX_SIZE],double multiply[][MAX_SIZE],int size){
double temp = 0;

	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			for(int k=0;k<size;k++){
			temp = temp + matrix1[i][k]*matrix2[k][j];
			}
			multiply[i][j] = abs(temp);
			temp = 0;
		}

	}

}

void invert(const int n, double A[][MAX_SIZE], double Ainv[][MAX_SIZE])
{
    double LU[MAX_SIZE][MAX_SIZE];
    double x[MAX_SIZE];  // solution vector
    double b[MAX_SIZE];  // right-hand-side vector
    int ps[MAX_SIZE];    // permuted row indices

    decompose(n, A, LU, ps);

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            b[i] = i == j ? 1 : 0;
        }

        solve(n, LU, b, x, ps);
        for (int i = 0; i < n; i++) Ainv[i][j] = x[i];
    }
}

void decompose(const int n, double A[][MAX_SIZE],
               double LU[][MAX_SIZE], int ps[MAX_SIZE])
{
    double scales[MAX_SIZE];  // vector of scaling factors
    int pivot_index;
    double norm_row, pivot, size, biggest, mult;

    // Initialize ps, LU, and scales.
    for (int i = 0; i < n; i++)
    {
        ps[i] = i;
        norm_row = 0;

        for (int j = 0; j < n; j++)
        {
            LU[i][j] = A[i][j];

            // Find the largest row element.
            if (norm_row < abs(LU[i][j])) norm_row = abs(LU[i][j]);
        }

        // Set the scaling factor for row equilibration.
        if (norm_row != 0) scales[i] = 1/norm_row;
        else
        {
            scales[i] = 0;
            singular(ZERO_ROW);
        }
    }

    // Gaussian elimination with partial pivoting.
    for (int k = 0; k < n-1; k++)
    {
        pivot_index = -1;
        biggest = 0;

        // Go down rows from row k.
        for (int i = k; i < n; i++)
        {
            // Divide by the largest row element.
            size = abs(LU[ps[i]][k])*scales[ps[i]];

            if (biggest < size)
            {
                biggest     = size;  // biggest scales column element
                pivot_index = i;     // row index of this element
            }
        }

        if (biggest == 0) singular(SINGULAR_MATRIX);
        else
        {
            if (pivot_index != k)
            {
                // Exchange rows.
                int j = ps[k];
                ps[k] = ps[pivot_index];
                ps[pivot_index] = j;
            }

            pivot = LU[ps[k]][k];  // pivot element

            // Go down rest of rows.
            for (int i = k+1; i < n; i++)
            {
                mult = LU[ps[i]][k]/pivot;
                LU[ps[i]][k] = mult;

                if (mult != 0)
                {
                    // Inner loop.
                    for (int j = k+1; j < n; j++)
                    {
                        // Only the column subscript varies.
                        LU[ps[i]][j] -= mult*LU[ps[k]][j];
                    }
                }
            }
        }
    }

    // Check the bottom right element of the permuted matrix.
    if (LU[ps[n-1]][n-1] == 0) singular(SINGULAR_MATRIX);
}

void solve(const int n, double LU[][MAX_SIZE],
           const double b[], double x[], const int ps[MAX_SIZE])
{
    double dot;  // dot product

    // Ly = b : solve for y.
    for (int i = 0; i < n; i++)
    {
        dot = 0;
        for (int j = 0; j <= i-1; j++) dot += LU[ps[i]][j]*x[j];
        x[i] = b[ps[i]] - dot;
    }

    // Ux = y : solve for x.
    for (int i = n-1; i >= 0; i--)
    {
        dot = 0;
        for (int j = i+1; j < n; j++) dot += LU[ps[i]][j]*x[j];
        x[i] = (x[i] - dot)/LU[ps[i]][i];
    }
}

void singular(const ErrorCode code)
{
    switch (code)
    {
        case ZERO_ROW:
            cout << "Matrix with zero row in decompose." << endl;
            break;
        case SINGULAR_MATRIX:
            cout << "Singular matrix in decompose." << endl;
            break;
        case NO_CONVERGENCE:
            cout << "No convergence in improve" << endl;
            break;
    }
}
