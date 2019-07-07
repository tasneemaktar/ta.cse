#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
void insertionsort(int arr[],int n)
{
    int i,key,index;
    for(i=1;i<n;i++)
    {
      key=arr[i];
      index=i-1;
      while((index>=0) &&  (arr[index]>key))
      {
          arr[index+1]=arr[index];
          index=index-1;
      }
      arr[index+1]=key;
    }
}
int main()
{


    ofstream fileinput;
    srand(89345);
    fileinput.open("10.txt");
    int n=1000;
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
    insertionsort(arr,n);
    //end time
    clock_t endTime=clock();

    ofstream fileoutput;
    fileoutput.open("output10.txt");
    for(int i=0;i<1000;i++)
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
