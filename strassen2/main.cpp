
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void ikjalgorithm(int **&A,int **&B, int **&C, int tam)
{
    for (int i = 0; i < tam; i++) {
        for (int k = 0; k < tam; k++) {
            for (int j = 0; j < tam; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int** crearMatriz(int f, int c){
    int** m = new int*[f];
    for(int i=0; i<f;i++)
    {
        (*(m+i)) = new int[c];
    }
    for(int i=0; i<f; i++)
    {
        for (int j=0; j<c; j++)
        {
            *((*(m+i))+j) = 0;
        }
    }
    return m;
}

void imprimirmatriz(int** z, int tam)
 {

 for (int y=0; y<tam; y++)
 {
    for (int x=0; x<tam; x++)
     {
         cout<< " ";
         cout<< *((*(z+y))+x);
     }
     cout<<"\n";
 }
 }


void suma(int** &A, int** &B, int** &C, int tam) {
    int i, j;
    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void resta(int** &A, int** &B, int** &C, int tam) {
    int i, j;
    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}



void strassenR (int ** &A,int **&B, int **&C, int tam)
{
    if (tam <= 1) {
        ikjalgorithm(A, B, C, tam);
        return;
    }
    else {
        int ntam = tam/2;
        //int a11[ntam][ntam],a12[ntam][ntam],a21[ntam][ntam],a22[ntam][ntam],b11[ntam][ntam],b12[ntam][ntam],b21[ntam][ntam],b22[ntam][ntam],c11[ntam][ntam],c12[ntam][ntam],c21[ntam][ntam],c22[ntam][ntam],p1[ntam][ntam],
        //p2[ntam][ntam],p3[ntam][ntam],p4[ntam][ntam],p5[ntam][ntam],p6[ntam][ntam],p7[ntam][ntam],aResult[ntam][ntam],bResult[ntam][ntam];

        int **a11=crearMatriz(ntam,ntam);
        int **a12=crearMatriz(ntam,ntam);
        int **a21=crearMatriz(ntam,ntam);
        int **a22=crearMatriz(ntam,ntam);
        int **b11=crearMatriz(ntam,ntam);
        int **b12=crearMatriz(ntam,ntam);
        int **b21=crearMatriz(ntam,ntam);
        int **b22=crearMatriz(ntam,ntam);
        int **c11=crearMatriz(ntam,ntam);
        int **c12=crearMatriz(ntam,ntam);
        int **c21=crearMatriz(ntam,ntam);
        int **c22=crearMatriz(ntam,ntam);
        int **p1=crearMatriz(ntam,ntam);
        int **p2=crearMatriz(ntam,ntam);
        int **p3=crearMatriz(ntam,ntam);
        int **p4=crearMatriz(ntam,ntam);
        int **p5=crearMatriz(ntam,ntam);
        int **p6=crearMatriz(ntam,ntam);
        int **p7=crearMatriz(ntam,ntam);
        int **aResult=crearMatriz(ntam,ntam);
        int **bResult=crearMatriz(ntam,ntam);


        int i, j;

        //dividing the matrices in 4 sub-matrices:
        for (i = 0; i < ntam; i++)
        {
            for (j = 0; j < ntam; j++) {
                a11[i][j] = A[i][j];
                a12[i][j] = A[i][j + ntam];
                a21[i][j] = A[i + ntam][j];
                a22[i][j] = A[i + ntam][j + ntam];

                b11[i][j] = B[i][j];
                b12[i][j] = B[i][j + ntam];
                b21[i][j] = B[i + ntam][j];
                b22[i][j] = B[i + ntam][j + ntam];
            }
        }
        // p1 a p7:

        //suma(a11, a22, aResult, ntam); // a11 + a22
        //suma(b11, b22, bResult, ntam); // b11 + b22
        resta(b12,b22,aResult,ntam);//b12-b22
        strassenR(a11, aResult, p1, ntam); // p1 = (a11) * (b12-b22)

        suma(a11, a12, aResult, ntam); // a11 + a12
        strassenR(aResult, b22, p2, ntam); // p2 = (a11+a12) * (b22)

        suma(a21, a22, bResult, ntam); // a21+a22
        strassenR(bResult,b11, p3, ntam); // p3 = (A21+A22) * (b11)

        resta(b21, b11, bResult, ntam); // b21 - b11
        strassenR(a22, bResult, p4, ntam); // p4 = (a22) * (b21 - b11)

        suma(a11, a22, aResult, ntam); // a11 + a22
        suma(b11,b22,bResult,ntam);  // b11+b22
        strassenR(aResult, bResult, p5, ntam); // p5 = (a11+a22) * (b11+b22)


        resta(a12, a22, aResult, ntam); // a12 - a22
        suma(b21, b22, bResult, ntam); // b21 + b22
        strassenR(aResult, bResult, p6, ntam); // p6 = (a12-a22) * (b21+b22)


        resta(a11, a21, aResult, ntam); // a11 - a21
        suma(b11, b12, bResult, ntam); // b11 + b12
        strassenR(aResult, bResult, p7, ntam); // p7 = (a11-a21) * (b11+b12)

        // calculando c21, c21, c11 e c22:

        suma(p1, p2, c12, ntam); // c12 = p1 + p2
        suma(p3, p4, c21, ntam); // c21 = p3 + p4

        suma(p5, p1, aResult, ntam); // p1 + p4
        resta(aResult, p3, bResult, ntam); // p1 + p4 + p7
        resta(bResult, p7, c22, ntam); // c11 = p1 + p4 - p5 + p7

        suma(p5, p4, aResult, ntam); // p1 + p3
        resta(aResult, p2, bResult, ntam); // p1 + p3 + p6
        suma(bResult, p6, c11, ntam); // c22 = p1 + p3 - p2 + p6


        for (i = 0; i < ntam ; i++) {
            for (j = 0 ; j < ntam ; j++) {
                C[i][j] = c11[i][j];
                C[i][j + ntam] = c12[i][j];
                C[i + ntam][j] = c21[i][j];
                C[i + ntam][j + ntam] = c22[i][j];
            }
        }
    }
}

int nextPowerOfTwo(int n) {
    return pow(2, int(ceil(log2(n))));
}

void strassen(int** &A,int** &B, int** &C, int n) {

    int m = nextPowerOfTwo(n);
    int ** Aprep=crearMatriz(m,m);
    int ** Bprep=crearMatriz(m,m);
    int ** Cprep=crearMatriz(m,m);

    for(int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            Aprep[i][j] = A[i][j];
            Bprep[i][j] = B[i][j];
        }
    }

    strassenR(Aprep, Bprep, Cprep, m);

    for(int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            C[i][j] = Cprep[i][j];
        }
    }
}

int tam;

int main () {
    tam=3;
    int** A=crearMatriz(tam,tam);
    int** B=crearMatriz(tam,tam);
    int** C=crearMatriz(tam,tam);

    cout<<"Matriz A:"<<endl;
    for (int i = 0; i < tam; i++) {
            for (int j = 0; j < tam; j++) {
                cin>>A[i][j];
            }
    }

    cout<<"Matriz B:"<<endl;
    for (int i = 0; i < tam; i++) {
            for (int j = 0; j < tam; j++) {
                cin>>B[i][j];
            }
    }

    strassen(A, B, C, tam);
    imprimirmatriz(C, tam);
    return 0;
}
