#include <iostream>
#include <fstream>
using namespace std;
int choosePivot(int* arr, int first, int last,int& pIndex){
        int mid = first+ (last-first)/2;
        int f = arr[first];
        int l = arr[last];
        int m = arr[mid];

    if((f<=l&&f>=m)||(f<=m&&f>=l)){
        pIndex = first;
        return f;
    }
    if((l<=f&&l>=m)||(l<=m&&l>=f)){
        pIndex = last;
        return l;
    }
    if((f<=m&&l>=m)||(l<=m&&f>=m)){
        pIndex = mid;
        return m;
    }

    return f;


}

void partition(int* arr, int first, int last, int& pivot){

   
    int pivotValue =  choosePivot(arr,first,last,pivot);;
    int a = arr[first];
    arr[first] = pivotValue;
    arr[pivot] = a;
    int lastS1 = first;
    int firstUnknown = first + 1;

    while(firstUnknown <= last){
        if(arr[firstUnknown] > pivotValue){
            firstUnknown++;
        } else {
            int temp = arr[++lastS1];
            arr[lastS1] = arr[firstUnknown];
            arr[firstUnknown] = temp;
            firstUnknown++;
        }
    }

    int temp = arr[lastS1];
    arr[lastS1] = arr[first];
    arr[first] = temp;

    pivot = lastS1;
}

void quickSort(int* arr, int first, int last,int& compCount){
    int pivot;
    if(first < last){
        compCount += last-first;
        partition(arr, first, last, pivot);
        quickSort(arr, first, pivot - 1,compCount);
        quickSort(arr, pivot + 1, last,compCount);
    }
}

int main(int argc, char const *argv[])
{
   std::string inputFilePath = "QuickSort.txt";

    const int ARRAY_SIZE = 10000;
    int numbers[ARRAY_SIZE];

    std::ifstream inputFile(inputFilePath);
    if (!inputFile) {
        std::cerr << "Error opening input file: " << inputFilePath << std::endl;
        return 1;
    }

    int number;
    int index = 0;
    while (inputFile >> number && index < ARRAY_SIZE) {
        numbers[index] = number;
        index++;
    }

    inputFile.close();

    int comp =0;

    quickSort(numbers,0,9999,comp);

    cout<<"The total number of comparison is: "<<comp<<endl;


    return 0;
}
