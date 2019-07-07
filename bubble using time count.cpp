#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
void bubblesort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main()
{


    ofstream fileinput;
    srand(89345);
    fileinput.open("100k.txt");
    int n=100000;
    //fileinput>>n;
    int*arr=new int[n];

    for(int i=0;i<n;i++)
    {
        fileinput<<rand()<<endl;
        arr[i]=rand();
    }

    fileinput.close();
    //atrat time
    clock_t startTime=clock();
    bubblesort(arr,n);
    //end time
    clock_t endTime=clock();

    ofstream fileoutput;
    fileoutput.open("output100.txt");
    for(int i=0;i<100000;i++)
    {
        fileoutput<<arr[i]<<endl;
    }
    //count the lapse
    double timelapse=double (endTime-startTime)/CLOCKS_PER_SEC;
    cout<<"timelapse: "<<timelapse<<endl;
    fileoutput<<"timelapse: "<<timelapse<<endl;
    fileoutput.close();
    delete[] arr;
}
