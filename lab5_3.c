#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int ROWS=3;
const int COLS=4;
void inputArray(int arr[ROWS][COLS]) 
{
    cout<<"Введіть елементи масиву ("<<ROWS*COLS<<" чисел):\n";
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            cin>>arr[i][j];
        }
    }
}
void randomArray(int arr[ROWS][COLS], int minVal=0, int maxVal=100) 
{
    srand(time(0));
    for(int i=0; i<ROWS; i++) 
    {
        for(int j=0; j<COLS; j++) 
        {
            arr[i][j]=minVal+rand()%(maxVal-minVal+1);
        }
    }
}
void printArrayIndex(int arr[ROWS][COLS]) 
{
    cout<<"Масив (індекси): \n";
    for(int i=0; i<ROWS; i++) 
    {
        for(int j=0; j<COLS; j++) 
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void printArrayPointer(int arr[ROWS][COLS]) 
{
    cout<<"Масив (вказівники):\n";
    for(int i=0; i<ROWS; i++) 
    {
        for(int j=0; j<COLS; j++) 
        {
            cout<<*(*(arr+i)+j)<<"\t";
        }
        cout<<endl;
    }
}
void replaceMaxInColumnIndex(int arr[ROWS][COLS], int col)
{
    if(col<0||col>=COLS) 
    {
        cout<<"Некоректний номер стовпчика!\n";
        return;
    }
    int maxVal=arr[0][col];
    int maxRow=0;
    for(int i=1; i<ROWS; i++) 
    {
        if(arr[i][col]>maxVal) 
        {
            maxVal=arr[i][col];
            maxRow=i;
        }
    }
    arr[maxRow][col]=0;
}
void replaceMaxInColumnPointer(int arr[ROWS][COLS], int col) 
{
    if(col<0||col>=COLS) 
    {
        cout<<"Некоректний номер стовпчика!\n";
        return;
    }
    int*ptr=&arr[0][col];
    int maxVal=*ptr;
    int maxRow=0;
    for(int i=1; i<ROWS; i++) 
    {
        if(*(ptr+i*COLS)>maxVal) 
        {
            maxVal=*(ptr+i*COLS);
            maxRow=i;
        }
    }
    *(ptr+maxRow*COLS)=0;
}

int main() 
{
    int arr[ROWS][COLS];
    int choice;
    cout<<"Оберіть спосіб заповнення масиву:\n";
    cout<<"1 - Ввід з клавіатури\n";
    cout<<"2 - Випадкові числа\n";
    cin>>choice;
    if(choice==1) 
    {
        inputArray(arr);
    } 
    else if(choice==2) 
    {
        randomArray(arr);
    } 
    else 
    {
        cout<<"Невірний вибір!\n";
        return 0;
    }
    printArrayIndex(arr);
    printArrayPointer(arr);
    int col;
    cout<<"Введіть номер стовпчика для заміни найбільшого елемента на 0 (0-" << COLS-1 << "): ";
    cin>>col;
    replaceMaxInColumnIndex(arr, col);
    cout<<"\nМасив після заміни найбільшого елемента через індекси:\n";
    printArrayIndex(arr);
    replaceMaxInColumnPointer(arr, col);
    cout<<"\nМасив після заміни найбільшого елемента через вказівники:\n";
    printArrayPointer(arr);
    return 0;
}
