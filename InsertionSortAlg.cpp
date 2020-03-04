#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
    int value = 0;
    int arr[20];
    int currentRand;
    srand((long)time(NULL));

    for (int i = 0; i < 20; i++){
        do {
            currentRand = rand() % 100 + 1;
            for (int j = 0; j < i; j++){
                if (currentRand == arr[j]){
                    currentRand = -1;
                break;
                }
            }
        }while(currentRand == -1);
        arr[i] = currentRand;
    }

    for (int b = 0; b < 20; b++){
        cout << arr[b] << ", ";
    }
}
