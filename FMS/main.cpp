#include <iostream>

using namespace std;

int* FMCS(int *A,int low, int mid, int high)
{
    int leftsum= -100000;
    int maxleft,maxright;
    int sum=0;
    for(int i=mid; i>=low;i--)
    {
        sum+=A[i];
        if(sum>leftsum)
        {
            leftsum=sum;
            maxleft=i;
        }
    }
    int rightsum=-100000;
    sum=0;
    for(int j=mid+1; j<high;j++)
    {
        sum+=A[j];
        if(sum>rightsum)
        {
            rightsum=sum;
            maxright=j;
        }
    }
    int R[3]={maxleft,maxright,leftsum+rightsum};
    //cout<<endl<<maxleft<<" "<<maxright<<" "<<leftsum+rightsum<<endl;
    return R;

}
int* FMS(int* A, int low, int high)
{
    int R[3];
    int* r;
    if(high==low)
    {
        R[0]=low;
        R[1]=high;
        R[2]=A[low];
        return R ;
    }
    int mid=(low+high)/2;

    r=FMS(A,low,mid);
    int leftlow=r[0], lefthigh=r[1],leftsum=r[2];

    r=FMS(A,mid+1,high);
    int rightlow=r[0], righthigh=r[1],rightsum=r[2];

    r=FMCS(A,low,mid,high);
    int crosslow=r[0], crosshigh=r[1],crosssum=r[2];

    if(leftsum>=rightsum && leftsum>=crosssum)
    {
        R[0]=leftlow;
        R[1]=lefthigh;
        R[2]=leftsum;
        return R;
    }
    else if (rightsum>= leftsum && rightsum >=crosssum)
    {
        R[0]=rightlow;
        R[1]=righthigh;
        R[2]=rightsum;
        return R;
    }
    else
    {
        R[0]=crosslow;
        R[1]=crosshigh;
        R[2]=crosssum;
        return R;
    }
}



int main()
{
    cout << "FMS" << endl;
    //         0   1  2  3  4  5   6  7  8  9  10  11 12 13 14 15
    int A[16]={34, 7, 6,20,-34,-1, 5, 6,21,102,-27,39,47,98,-39,86};
    int* a;
    int* b;
    int x,y,z;
    a=A;

    b=FMS(a,0,16);
    x=b[0];
    y=b[1];
    z=b[2];
    cout<<endl<<"RESPUESTA"<<endl;
    cout<< x<<endl;
    cout<< y<<endl;
    cout<< z<<endl;

    return 0;
}
