
#include <iostream>
using namespace std;

#include "DynamicArray.h"
#include "ArraySequence.h"
#include "LinkedList.h"
#include "ListSequence.h"
#include "menu.h"

int main(){
    cout << "Choose type:" << endl;
    cout << "Integer -> 1" << endl;
    cout << "Float -> 2" << endl;
    cout << "Complex -> 3" << endl;
    int choice;
    cin >> choice;
    cout << endl;
    if (choice != 1 & choice != 2 & choice != 3) {
        cout << "Wrong number" << endl;
        throw invalid_argument(INVALID_ARGUMENT);
    }
    cout << "Set matrix size:";
    int size = 0;
    while (size<=0){
        cin >> size;
        if (size <= 0){
            cout << "Size should be > 0, try again:"<<endl;
        }
    }
    cout << endl;
    cout << "Zeros on top -> 0" << endl;
    cout << "Zeros in bottom -> 1" << endl;
    cout << "Common Matrix -> 2" << endl;
    int str_N;
    cin >> str_N;
    string str;
    switch (str_N) {
        case 0:
            str = "lower";
            break;
        case 1:
            str = "upper";
            break;
        case 2:
            str = "common";
            break;
        default:
            throw invalid_argument(INVALID_ARGUMENT);
    }
    cout << endl;
    if (choice == 1) {
        RealMatrixOperations<int>(size, str);
    } else if (choice == 2) {
        RealMatrixOperations<float>(size, str);
    } else if (choice == 3) {
        ComplexMatrixOperations(size, str);
    }
}
