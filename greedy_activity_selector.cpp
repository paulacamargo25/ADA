vector<int> greedy_activity_selector(vector<int> s,vector<int> f, int n)
{
    vector<int> A;
    A.push_back(s[0]);
    int k=0;
    for (int m=1;m<n;m++)
    {
        if(s[m]>=f[k])
        {
            A.push_back(s[m]);
            k=m;
        }
    }
    return A;
}

int main()
{
    int s1[11]={1,3,0,5,3,5,6,8,8,2,12};
    int f1[11]={4,5,6,7,9,9,10,11,12,14,16};
    vector<int> s (s1, s1 + sizeof(s1) / sizeof(int) );
    vector<int> f (f1, f1 + sizeof(f1) / sizeof(int) );
    vector<int> t=recursive_activity_selector(s,f,-1,11);
    for(int i=0;i<t.size();i++)
    {
        cout<<t[i]<<endl;
    }

    return 0;
}
