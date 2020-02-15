#include <iostream>
using namespace std;

int main()
{
     int dividend[20];
     int divisor[20];

    cout<<"Enter the number of bits in divisor: ";
    int n1,n2;
    cin >>n1;
    cout<<endl<<"Enter the bits of divisor: ";
    for (int i=0;i<n1;i++)
    {

        cin>>divisor[i];
    }

   cout<<endl<<"Enter the number of bits in dividend: ";
    cin>>n2;
    cout<<endl<<"Enter the bits of dividend: ";
    for (int i=0;i<n2;i++)
    {
        cin>>dividend[i];
    }
    for (int i=n2;i<n2+(n1-1);i++)
    {
        dividend[i]=0;
    }
    n2=n2+(n1-1);

    for (int i=0;i<=(n2-n1);i++)
    {
        int key=i;
        if(dividend[i]==0)
        {
            for (int j=0;j<n1;j++)
            {
              dividend[key]=dividend[key]^ 0 ;
              key++;
            }
        }
        else
        {

            for (int j=0;j<n1;j++)
            {
                 dividend[key]=dividend[key]^divisor[j];
                 key++;
            }

        }

    }
    int remainder[n1-1];
    int key2=n2-(n1-1);
    for(int i=0;i<(n1-1);i++)
    {
        remainder[i]=dividend[key2++];

    }
    cout<<endl<<"CRC BITS: ";
    for (int i=0;i<(n1-1);i++)
    {
        cout<<remainder[i]<<'\t';

    }


}
