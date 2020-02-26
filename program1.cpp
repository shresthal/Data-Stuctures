/*
luja shrestha
k687e787
program1
*/
#include <iostream>
#include <cstdlib> // srand()and rand()
#include <ctime> // for time
#include <fstream> //to operate files

using namespace std;
void insertion_sort ( int randomnumber[], int size);

 int main()
{
   ofstream myfile;  // to create files
   myfile.open ("sorted.txt ");
   myfile << " Sorted numbers: " << endl;
   srand (time(NULL)); // to generate randomnumber
   int size = 50000;
   int *randomnumber = new int[size];

   for ( int i=0; i<size; i++)
   {
    randomnumber[i]= rand()%50000000+1;
    }
   insertion_sort(randomnumber,size);
    for (int i=0; i<size; i++)
    {
     cout << randomnumber[i] << " " ;
     myfile << randomnumber[i] << " " <<endl;

    }
    delete [] randomnumber;
    myfile.close();
    return 0;
}
void insertion_sort(int randomnumber[],int size) //to sorts randomnumber
{
    for (int i=1; i<size; i++)
    {
        int key = randomnumber[i];
        int j = i -1;
        for ( ;j >= 0 && randomnumber[j] >= key ;j--)
        {
            randomnumber[j+1]= randomnumber[j];
        }
        randomnumber[j+1]=key;


    }
}
