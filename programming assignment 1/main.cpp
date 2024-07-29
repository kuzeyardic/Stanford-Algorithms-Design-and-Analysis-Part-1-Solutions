#include <iostream>
#include <fstream>

const int MAX_SIZE = 100000;


long long mergeCross(int* arr,int first, int last){

   int mid =(last+first)/2;
    int left = first;
    int right = mid+1;
    int index=0;
    long long crossInv = 0;
    
    int temp[MAX_SIZE];

    while(left<=mid&&right<=last){
        if (arr[left] < arr[right]) {
               temp[index] = arr[left];
               left++;
        }
        else {
            crossInv+= (mid-left)+1;
            temp[index] = arr[right];
            right++;
        }
        index++;
    }
    
    while(left<=mid){
        temp[index++] = arr[left];
        left++;
    }
    
    while(right<=last){
        temp[index++] = arr[right];
        right++;
    }
    
    for(int i=first; i<=last; i++){
        arr[i] = temp[i-first];
    }

    return crossInv;

}

long long findInversion(int* arr,int startIndex, int endIndex){
    if((endIndex-startIndex)< 1){
        return 0;
    }
    int mid = (startIndex+endIndex)/2;
    long long left = findInversion(arr,startIndex,mid);
    long long right = findInversion(arr,mid+1,endIndex);
    long long cross = mergeCross(arr,startIndex,endIndex);

    return left+right+cross;
}

using namespace std;
int main() {
    std::string inputFilePath = "log.txt";

    const int ARRAY_SIZE = 100000;
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

    long long inversionNo = findInversion(numbers,0,99999);

    cout<<inversionNo<<endl;

    return 0;
}


