#include <iostream>
using namespace std;
int data_bits=0;
void frame_generator(int prime_data[])
{
    int flag[8]={0,1,1,1,1,1,1,0};
    int key=0;
    int frame[data_bits+16];

    for (int i=0;i<8;i++)
    {
        frame[key]=flag[i];
        key++;
    }
    for (int i=0;i<data_bits;i++)
    {
        frame[key]=prime_data[i];
        key++;
    }
    for (int i=0;i<8;i++)
    {
        frame[key]=flag[i];
        key++;
    }
    cout<<endl<<"Data Frame : ";
    for (int i=0;i<16+data_bits;i++)
    {
        cout<<frame[i]<<" ";
    }
    cout<<endl;
}

void display(int ar[], int size)
{
    for (int i=0;i<size;i++)
    {
        cout<<ar[i]<<" ";
    }
}
void stuffer(int dataarr[],int pos)
{
    for (int i=data_bits;i>pos;i--)
    {
        dataarr[i]=dataarr[i-1];

    }
    dataarr[pos]=0;
    data_bits=data_bits+1;
   // cout<<endl<<"Data Bits : "<<data_bits;


}
/* To check if there is  0 1 1 1 1 1 case */
bool res_checker(int arr[])
{
    int flag=0;
    if (arr[0]==1)
    {
        flag=1;
    }
    for (int i=1;i<6;i++)
    {
        if(arr[i]==1)
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
//    int data_prime[16+n];
    int data[25];
    int checker[6]={1,1,1,1,1,1};
    int key2=0;
    cout<<"Enter no. data bits (max:16) :  ";
    int n;
    cin>>n;
    data_bits=n;
    int starred_index[n-5];
    cout<<endl<<"Enter bits of data: ";
    for (int i=0;i<n;i++)
    {
        cin>>data[i];
    }
    for (int i=0;i<=n-6;i++)
    {
        int res[6]={0,0,0,0,0,0};
        int key=0;
        for (int j=i;j<6+i;j++)
        {
            res[key]=data[j]^checker[key];
            key++;
        }
        //display(res,6);
        //cout<<endl;
        if(res_checker(res))
        {
            starred_index[key2]= 1;
        }
        else {
            starred_index[key2] = 0;
        }
        key2++;

    }
    cout<<endl<<endl<<"Index to be stuffed: ";
    display(starred_index,n-5);
    int pos_increaser=0;
    for (int i=0;i<n-5;i++)
    {
        if(starred_index[i])
        {
            stuffer(data,i+6+pos_increaser);
            pos_increaser++;

        }

    }
    cout<<endl<<endl<<"Stuffed Data: ";
    display(data,data_bits);
    cout<<endl<<endl<<"Total Data Bits: "<<data_bits;

    cout<<endl<<endl<<"Creating Data Frames"<<endl;
    frame_generator(data);



}
