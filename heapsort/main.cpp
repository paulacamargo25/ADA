#include <iostream>
#include <math.h>
using namespace std;

void inter(int* A,int a, int b)
{
    int tem=A[a];
    A[a]=A[b];
    A[b]=tem;
}

int parent(int i)
{
    return i/2;
}

int left(int i)
{
    return 2*(i+1)-1;
}

int right(int i)
{
    return 2*(i+1);
}

void imprimir2(int *a, int nivel,int i,int tam)
{
    int h;
    for (h=0;h<pow(2,nivel);h++)
    {
        if (i+h>=tam)
            return;
        cout<<a[i+h]<<" ";
    }
    cout<<endl;
    imprimir2(a,nivel+1,i+h,tam);
}


void imprimir(int *a,int tam)
{
    imprimir2(a,0,0,tam);
}


void MaxHeapify(int* a,int i,int tam)
{
    int l=left(i);
    int r=right(i);
    int largest;
    if (l<tam and a[l]>a[i])
    {
        largest=l;
    }
    else
    {
        largest=i;
    }
    if (r<tam and a[r]>a[largest])
    {
        largest=r;
    }
    if (largest!=i)
    {
        inter(a,i,largest);
        MaxHeapify(a,largest,tam);
    }
}

int* BuildMaxHeap(int *a,int tam)
{
    for (int i=tam/2;i>=0;i--)
    {
        MaxHeapify(a,i,tam);
        //cout<<"i"<<i<<endl;
        //imprimir(a,tam);
        //cout<<endl;
    }
    return a;
}

void heapsort(int* a,int tam)
{
    BuildMaxHeap(a,tam);
    int tam_heap=tam;
    cout<<"Maxheap: "<<endl;
    for(int i=0;i<tam;i++)
    {
       cout<<a[i]<<" ";
    }
    cout<<endl;
    for (int i=tam-1;i>0;i--)
    {
        inter(a,0,i);
        tam_heap=tam_heap-1;
        MaxHeapify(a,0,tam_heap);
    }
}

int main()
{
   cout<<"Ingrese tamaño: ";
    int tam;
    cin>>tam;
    int lista[tam];
    int temp;

    srand(time(NULL));

    for(int i=0;i<tam;i++)
    {
        temp=rand()%tam;
        lista[i]=temp;
    }

    cout<<"Lista: "<<endl;

    for(int i=0;i<tam;i++)
    {
       cout<<lista[i]<<" ";
    }

    cout<<endl;

    heapsort(lista,tam);

    //BuildMaxHeap(lista,tam);
    cout<<"Lista Ordenada: "<<endl;

    for(int i=0;i<tam;i++)
    {
       cout<<lista[i]<<" ";
    }
    cout<<endl;
    //imprimir(lista,tam);
}
