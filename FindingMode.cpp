#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

int main(){
    int timesRoll = 20;
    int roll;
    int value = 1;
    int bigValue = value;
    int num;
    // kind of like making an array the size of
    // timesRoll, and making all of the values false

    // initialize array
    int numsRolled[timesRoll];
    vector<bool> visited(timesRoll, false);
    srand((int)time(NULL));

    // rolls and stores values
    for (int i = 0; i < timesRoll; i++){
        cout << "NUM " << i + 1 << ": ";
        cin >> roll;
        numsRolled[i] = roll;
    }
    cout << endl;

    // finds values in array
    for (int j = 0; j < timesRoll; j++){
        value = 1;
        if (visited[j] == true){
            continue;
        }

        for (int a = j + 1; a < timesRoll; a++){
            // compares numsRolled[j] to every value in numsRolled
            if (numsRolled[j] == numsRolled[a]){
                visited[a] = true;
                value++;
            }
        }
        if (value > bigValue){
            bigValue = value;
            num = numsRolled[j];
        }
    }
    cout << "The mode is " << num << " with " << bigValue << " of it self.\n";
}
