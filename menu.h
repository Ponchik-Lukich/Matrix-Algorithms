
#include "Matrix.h"
#ifndef MAT_MENU_H
#define MAT_MENU_H
#endif
#include <cstdlib>
#include "random"

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_real_distribution<float> dist(-25.0, 25.0);


template <typename T> CommonMatrix<T> SetRealMatrix(int size, string str) {
    int count;
    if (str == "common"){
        count = size*size;
    } else{
        count = size*(size+1)/2;
    }
    cout<<"Input by your hands -> 0"<<endl;
    cout<<"Auto input(numbers from -25 to 25) -> 1"<<endl;
    ArraySequence<T> seq = ArraySequence<T>(0);
    int Var;
    int Go=0;
    while (Go==0){
        cin >> Var;
        if (Var == 0) {
            Go =1;
            cout<<"Set "<<count<<" elements"<<endl;
            for (int i = 0; i<count; i++) {
                T item;
                cout<<"№"<<i+1<<":";
                cin>>item;
                seq.Append(item);
            }
        }
        else if (Var == 1) {
            Go =1;
            for (int i = 0; i<count; i++) {
                T item = dist(mt);
                seq.Append(item);
            }
        }
        else{
            cout<<"Wrong Number"<<endl;
        }
    }
    if (str == "common"){
        CommonMatrix<T> matrix = CommonMatrix<T>(seq, size, str);
        return matrix;
    } else{
        TriangleMatrix<T> matrix = TriangleMatrix<T>(seq, size, str);
        return matrix;
    }
}

CommonMatrix<complex> SetComplexMatrix(int size, string str) {
    int count;
    if (str == "common"){
        count = size*size;
    } else{
        count = size*(size+1)/2;
    }
    cout<<"Input by your hands -> 0"<<endl;
    cout<<"Auto input(numbers from -25 to 25) -> 1"<<endl;
    ArraySequence<complex> seq = ArraySequence<complex>(0);
    int Var;
    int Go=0;
    while (Go == 0){
        cin >> Var;
        if (Var == 0) {
            Go = 1;
            cout<<"Set "<<count<<" elements:"<<endl;
            cout<<"real part - imag part"<<endl;
            for (int i = 0; i<count; i++) {
                cout<<"№"<<i+1<<":";
                float re,im;
                cin>>re>>im;
                complex item = complex(re,im);
                seq.Append(item);
            }
        }
        else if (Var == 1) {
            Go = 1;
            for (int i = 0; i<count; i++) {
                int re = dist(mt);
                int im = dist(mt);
                complex item = complex(re,im);
                seq.Append(item);
            }
        }
        else{
            cout<<"Wrong Number"<<endl;
        }
    }
    if (str == "common"){
        CommonMatrix<complex> matrix = CommonMatrix<complex>(seq, size, str);
        return matrix;
    } else{
        TriangleMatrix<complex> matrix = TriangleMatrix<complex>(seq, size, str);
        return matrix;
    }
}

//Print matrix or real numbers
template <typename T> void PrintRealMatrix(CommonMatrix<T>& matrix) {
    for (int i = 0; i<matrix.GetDim(); i++ ) {
        cout<<"________";
    }
    cout<<endl;
    for (int i = 0; i < matrix.GetDim(); i++) {
        for (int j = 0; j < matrix.GetDim(); j++) {
            cout <<setw(9)<<left<< matrix.GetElement(i,j) << " ";
        }
        cout<<endl;
    }
    for (int i = 0; i<matrix.GetDim(); i++ ) {
        cout<<"________";
    }
    cout<<endl;
}
//Print matrix of complex numbers
void PrintComplexMatrix(CommonMatrix<complex>& matrix) {
    for (int i = 0; i<matrix.GetDim(); i++ ) {
        cout<<"___________";
    }
    cout<<endl;
    for (int i=0; i<matrix.GetDim(); i++) {
        for (int j=0; j<matrix.GetDim(); j++) {
            matrix.GetElement(i,j).print();
            cout<<" ";
        }
        cout<<endl;
    }
    for (int i = 0; i<matrix.GetDim(); i++ ) {
        cout<<"____________";
    }
    cout<<endl;
}

template <typename T>
void RealMatrixOperations(int size, string str){
    CommonMatrix<T> matrix= SetRealMatrix<T>(size,str);
    cout << "Your Matrix:" << endl;
    PrintRealMatrix(matrix);
    cout<<"Choose operation:"<<endl;
    cout<<"Sum -> 1"<<endl;
    cout<<"Multiply -> 2"<<endl;
    cout<<"Get norm -> 3"<<endl;
    cout<<"Simple matrix operations -> 4"<<endl;
    int Var;
    int Go = 0;
    while (Go == 0){
        cin >> Var;
        cout<<endl;
        if (Var == 1) {
            Go = 1;
            cout<<"Zeros at the top -> 0"<<endl;
            cout<<"Zeros at the bottom -> 1?"<<endl;
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
            CommonMatrix<T> matrix2 = SetRealMatrix<T>(size, str);
            cout<<"Second Matrix:"<<endl;
            PrintRealMatrix(matrix2);
            cout<<"Result:"<<endl;
            CommonMatrix<T> matrixR = matrix+matrix2;
            PrintRealMatrix(matrixR);
            cout<<""<<endl;
        }
        else if (Var ==2) {
            Go = 1;
            float factor;
            cout<<"Your Factor:"<<endl;
            cin>>factor;
            CommonMatrix<T> matrixR = matrix*factor;
            cout<<"Result:"<<endl;
            PrintRealMatrix(matrixR);
        }
        else if (Var == 3) {
            Go = 1;
            cout << "Matrix K-norm is " << matrix.template MatrixNorm<float>();
        }
        else if (Var == 4) {
            Go = 1;

            while (Go==1){
                cout<<"Choose operation:"<<endl;
                cout<<"Switch rows -> 1"<<endl;
                cout<<"Switch columns -> 2"<<endl;
                cout<<"Multiply row on scalar -> 3"<<endl;
                cout<<"Multiply column on scalar -> 4"<<endl;
                cout<<"Sum rows -> 5"<<endl;
                cout<<"Sum columns -> 6"<<endl;
                cout<<"Exit -> 7"<<endl;
                cin >> Var;
                int first;
                int second;
                T scalar;
                switch (Var) {
                    case 1:
                        cout << "Starts with 0"<< endl;
                        cout << "Switch row №";
                        cin >> first;
                        cout << "With row №";
                        cin >> second;
                        matrix.Sw_row(first, second, size);
                        PrintRealMatrix(matrix);
                        break;
                    case 2:
                        cout << "Starts with 0"<< endl;
                        cout << "Switch column №";
                        cin >> first;
                        cout << "With column №";
                        cin >> second;
                        matrix.Sw_col(first, second, size);
                        PrintRealMatrix(matrix);
                        break;
                    case 3:
                        cout << "Starts with 0"<< endl;
                        cout << "Multiply row №";
                        cin >> first;
                        cout << "on scalar:";
                        cin >> scalar;
                        matrix.Multiply_row(scalar, first, size);
                        PrintRealMatrix(matrix);
                        break;
                    case 4:
                        cout << "Starts with 0"<< endl;
                        cout << "Multiply column №";
                        cin >> first;
                        cout << "on scalar:";
                        cin >> scalar;
                        matrix.Multiply_col(scalar, first, size);
                        PrintRealMatrix(matrix);
                        break;
                    case 5:
                        cout << "Starts with 0"<< endl;
                        cout << "Add row №";
                        cin >> second;
                        cout << "to row №:";
                        cin >> first;
                        matrix.Sum_row(first, second, size);
                        PrintRealMatrix(matrix);
                        break;
                    case 6:
                        cout << "Starts with 0"<< endl;
                        cout << "Add column №";
                        cin >> second;
                        cout << "to column №:";
                        cin >> first;
                        matrix.Sum_col(first, second, size);
                        PrintRealMatrix(matrix);
                        break;
                    default:
                        Go = 2;
                        cout << "Exit...";
                        break;
                }
            }
        } else{
            cout << "Wrong Number" << endl;
        }
    }


}

void ComplexMatrixOperations(int size, string str){
    CommonMatrix<complex> matrix= SetComplexMatrix(size,str);
    cout << "Your Matrix:" << endl;
    PrintComplexMatrix(matrix);
    cout<<"Choose:"<<endl;
    cout<<"Sum -> 1"<<endl;
    cout<<"Multiply -> 2"<<endl;
    cout<<"Get norm -> 3"<<endl;
    cout<<"Simple matrix operations -> 4"<<endl;
    int Var;
    int Go = 0;
    while (Go == 0){
        cin >> Var;
        cout<<endl;
        if (Var == 1) {
            Go =1;
            cout<<"Zeros at the top -> 0"<<endl;
            cout<<"Zeros at the bottom -> 1?"<<endl;
            cout<<"Common Matrix -> 2"<<endl;
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
            CommonMatrix<complex> matrix2 = SetComplexMatrix(size, str);
            cout<<"Second Matrix:"<<endl;
            PrintComplexMatrix(matrix2);
            CommonMatrix<complex> matrixR = matrix+matrix2;
            cout<<"Result:"<<endl;
            PrintComplexMatrix(matrixR);
        }
        else if (Var ==2) {
            Go = 1;
            cout<<"Your factor:"<<endl;
            complex factor;
            float re,im;
            cout<<"Put real and imag part:"<<endl;
            cin>>re>>im;
            factor = complex(re,im);
            CommonMatrix<complex> matrixR = matrix*factor;
            cout<<"Result:"<<endl;
            PrintComplexMatrix(matrixR);
        }
        else if (Var == 3) {
            Go = 1;
            cout<<"Matrix K-norm:";
            matrix.MatrixNorm<complex>().print();
        }
        else if (Var == 4) {
            Go = 1;
            while (Go==1){
                cout<<"Choose operation:"<<endl;
                cout<<"Switch rows -> 1"<<endl;
                cout<<"Switch columns -> 2"<<endl;
                cout<<"Multiply row on scalar -> 3"<<endl;
                cout<<"Multiply column on scalar -> 4"<<endl;
                cout<<"Sum rows -> 5"<<endl;
                cout<<"Sum columns -> 6"<<endl;
                cout<<"Exit -> 7"<<endl;
                cin >> Var;
                int first;
                int second;
                complex scalar;
                float re,im;
                switch (Var) {
                    case 1:
                        cout << "Starts with 0"<< endl;
                        cout << "Switch row №";
                        cin >> first;
                        cout << "With row №";
                        cin >> second;
                        matrix.Sw_row(first, second, size);
                        PrintComplexMatrix(matrix);
                        break;
                    case 2:
                        cout << "Starts with 0"<< endl;
                        cout << "Switch column №";
                        cin >> first;
                        cout << "With column №";
                        cin >> second;
                        matrix.Sw_col(first, second, size);
                        PrintComplexMatrix(matrix);;
                        break;
                    case 3:
                        cout << "Starts with 0"<< endl;
                        cout << "Multiply row №";
                        cin >> first;
                        cout << "on scalar:";
                        cin>>re>>im;
                        scalar = complex(re,im);
                        matrix.Multiply_row(scalar, first, size);
                        PrintComplexMatrix(matrix);
                        break;
                    case 4:
                        cout << "Starts with 0"<< endl;
                        cout << "Multiply column №";
                        cin >> first;
                        cout << "on scalar:";
                        cin>>re>>im;
                        scalar = complex(re,im);
                        matrix.Multiply_col(scalar, first, size);
                        PrintComplexMatrix(matrix);
                        break;
                    case 5:
                        cout << "Starts with 0"<< endl;
                        cout << "Add row №";
                        cin >> second;
                        cout << "to row №:";
                        cin >> first;
                        matrix.Sum_row(first, second, size);
                        PrintComplexMatrix(matrix);
                        break;
                    case 6:
                        cout << "Starts with 0"<< endl;
                        cout << "Add column №";
                        cin >> second;
                        cout << "to column №:";
                        cin >> first;
                        matrix.Sum_col(first, second, size);
                        PrintComplexMatrix(matrix);
                        break;
                    default:
                        Go = 2;
                        cout << "Exit...";
                        break;
                }
            }
        } else{
            cout << "Wrong Number" << endl;
        }
    }
}




