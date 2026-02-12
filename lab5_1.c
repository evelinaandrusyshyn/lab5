#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
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
double avgMinMax(int arr[], int n) 
{
    int min=arr[0];
    int max=arr[0];
    for (int i=1; i<n; i++) 
    {
        if(arr[i]<min) min=arr[i];
        if(arr[i]>max) max=arr[i];
    }
    return (min+max)/2.0;
}
int main() {
    int n;
    int arr[MAX_SIZE];
    cout<<"Введіть кількість елементів масиву (до 100): ";
    cin>>n;
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
    printArrayIndex(arr, n);
    printArrayPointer(arr, n);
    double result = avgMinMax(arr, n);
    cout<<"Середнє арифметичне між мінімальним і максимальним: "<<result<<endl;
    return 0;
}

