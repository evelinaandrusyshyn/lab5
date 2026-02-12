#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int SIZE=10;
const int MAX_SIZE=100;
void inputArray(int arr[], int n) 
{
    cout<<"Введіть "<<n<<" елементів масиву:\n";
    for(int i=0; i<n; i++) 
    {
        cin>>arr[i];
    }
}
void randomArray(int*arr, int n) 
{
    srand((unsigned)time(NULL));
    for(int i=0; i<n; i++) 
    {
        *(arr+i)=rand()%100;
    }
}
void printArrayIndex(int arr[], int n) 
{
    cout<<"Масив (індекси): ";
    for(int i=0; i<n; i++) 
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void printArrayPointer(int*arr, int n) 
{
    cout<<"Масив (вказівники): ";
    for(int i=0; i<n; i++) 
    {
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}
void insertIntoSortedArray(int arr[], int &n, int x) 
{
    int i;
    for(i=0; i<n; i++) 
        if(arr[i]<=x) break;
    for(int j=n; j>i; j--) 
        arr[j]=arr[j-1];
    arr[i]=x;
    n++;
}
int main() 
{
    int arr[SIZE+1];
    int n=SIZE;
    int choice;
    cout<<"Оберіть спосіб заповнення масиву:\n";
    cout<<"1 - Ввід з клавіатури\n";
    cout<<"2 - Випадкові числа\n";
    cin>>choice;
    if(choice==1) 
    {
        inputArray(arr, n);
    } 
    else if (choice==2) 
    {
        randomArray(arr, n);
    } 
    else 
    {
        cout<<"Невірний вибір!\n";
        return 0;
    }
    cout<<"Початковий масив:"<<endl;
    printArrayIndex(arr, n);
    printArrayPointer(arr, n);
    for(int i=0; i<n-1; i++) 
    {
        for(int j=i+1; j<n; j++) 
        {
            if(arr[i]<arr[j]) 
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout<<"Відсортований масив за спаданням:"<<endl;
    printArrayIndex(arr, n);
    int x;
    cout<<"Введіть число для вставки у відсортований масив: ";
    cin>>x;
    insertIntoSortedArray(arr, n, x);
    cout<<"Масив після вставки числа:"<<endl;
    printArrayIndex(arr, n);
    return 0;
}
