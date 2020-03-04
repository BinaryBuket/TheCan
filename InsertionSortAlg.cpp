#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
    string ans = " ";
    int arrSize = 13;
    int arr[arrSize];
    int key;
    int num;
    int PrevNum;
    int flipper;
    int median;
    bool good = true;
    srand((int)time(NULL));

    cout << "Would you like to enter 13 values for me to sort?\n";

    do {
        cin >> ans;
        good = true;
        if (ans == "y"){
            for (int a = 0; a < arrSize; a++){
                cout << "Number " << a + 1 << ": ";
                cin >> arr[a];
            }
        }else if (ans == "n"){
            for (int i = 0; i < arrSize; i++){
                arr[i] = rand() % 15 + 1;
            }
        }else{
            cout << "10 values? (y or n)" << endl;
            good = false;
        }
    }while(!good);

    for (int j = 1; j < arrSize; j++){
        key = arr[j];
        num = j - 1;
        /* uses num as a constant kind of number for a value before the key */

        while (num >= 0 && arr[num] > key){
            arr[num + 1] = arr[num];
            num = num - 1;

            // showing user the stuff + graph
            cout << "\n" << arr[num] << " and " << key << endl;
            for (int c = 0; c < arrSize; c++){
                cout << "ARR POS " << c << ": ";
                for (int d = 0; d <= arr[c]; d++){
                    cout << "*";
                }
                cout << endl;
            }
        }
        arr[num + 1] = key;
    }
    // the graph isn't right without this last step
    median = arr[6] + 1;
    cout << "\nFinal graph: median = " << median << endl;
    for (int c = 0; c < arrSize; c++){
        cout << "ARR POS " << c << ": ";
        for (int d = 0; d <= arr[c]; d++){
            cout << "*";
        }
        cout << endl;
    }
}
