#include "gtest/gtest.h"
#include "./../ListSequence.h"
#include "./../Matrix.h"
int arr[] = {1, 2, 3, 4, 5};
int arr_M[] = {1, 2, 3, 4, 5, 6};
int arr_M2[] = {1, 2, 3, 4};
int arr_M3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
float arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
int *ABOBA = arr;
int *MAMAM = arr_M;
int  *Matrix2 = arr_M2;
int  *Matrix3 = arr_M3;
float *BABAB = arr2;
TEST(DynamicArray, Default){
DynamicArray<int> array = DynamicArray<int>(0);
ASSERT_EQ(0, array.GetSize());
}
TEST(DynamicArray, Getsize){
DynamicArray<int> array = DynamicArray<int>(10);
ASSERT_EQ(10, array.GetSize());
}
TEST(DynamicArray, Float){
DynamicArray<float> array = DynamicArray<float>(BABAB,5);
ASSERT_EQ(5, array.GetSize());
EXPECT_FLOAT_EQ(1.1, array.Get(0));
EXPECT_FLOAT_EQ(5.5, array.Get(4));
}
TEST(DynamicArray, FromArray_Get){
DynamicArray<int> array = DynamicArray<int>(ABOBA, 5);
ASSERT_EQ(5, array.GetSize());
ASSERT_EQ(1, array.Get(0));
ASSERT_EQ(5, array.Get(4));
}
TEST(DynamicArray, Set){
DynamicArray<int> array = DynamicArray<int>(3);
array.Set(2,999);
ASSERT_EQ(999, array.Get(2));
}
TEST(DynamicArray, Resize){
DynamicArray<int> array = DynamicArray<int>(ABOBA, 5);
array.Resize(3);
ASSERT_EQ(3, array.Get(2));
}
TEST(LinkedList, InitDefault) {
LinkedList<int> arr = LinkedList<int>();
ASSERT_EQ(0, arr.GetLength());
}
TEST(LinkedList, Creation_from_array) {
LinkedList<int> list = LinkedList<int>(ABOBA, 5);
ASSERT_EQ(5,list.GetLength());
}
TEST(LinkedList, Get) {
LinkedList<int> list = LinkedList<int>(ABOBA, 5);
ASSERT_EQ(1,list.Get(0));
ASSERT_EQ(5,list.Get(4));
}
TEST(LinkedList, float) {
LinkedList<float> list = LinkedList<float>(BABAB, 5);
EXPECT_FLOAT_EQ(1.1,list.Get(0));
EXPECT_FLOAT_EQ(5.5,list.Get(4));
}
TEST(LinkedList, GetLast_GetFirst) {
LinkedList<int> list = LinkedList<int>(ABOBA, 5);
ASSERT_EQ(1,list.GetFirst());
ASSERT_EQ(5,list.GetLast());
}
TEST(LinkedList, Getsublist) {
LinkedList<int> list = LinkedList<int>(ABOBA, 5);
LinkedList<int>* list1 = new LinkedList<int>();
list1 = list.GetSublist(1,3);
ASSERT_EQ(2,list1->GetFirst());
ASSERT_EQ(4,list1->GetLast());
}
TEST(LinkedList, Append) {
LinkedList<int> list = LinkedList<int>(ABOBA, 5);
list.Append(22);
ASSERT_EQ(22, list.Get(5));
}
TEST(LinkedList, Prepend) {
LinkedList<int> list = LinkedList<int>(ABOBA, 5);
list.Prepend(22);
ASSERT_EQ(22, list.Get(0));
}
TEST(LinkedList, Insert) {
LinkedList<int> list = LinkedList<int>(ABOBA, 5);
list.InsertAt(11,2);
ASSERT_EQ(11, list.Get(2));
}
TEST(LinkedList, Clear) {
LinkedList<int> list = LinkedList<int>(ABOBA, 5);
list.Clear();
ASSERT_EQ(0, list.GetLength());
}
TEST(ArraySequence, Get_First_Last) {
DynamicArray<int> array = DynamicArray<int>(ABOBA, 5);
ArraySequence<int> seq = ArraySequence<int>(&array);
ASSERT_EQ(1, seq.GetFirst());
ASSERT_EQ(5, seq.GetLast());
}
TEST(ArraySequence, GetSubseq) {
DynamicArray<int> array = DynamicArray<int>(ABOBA, 5);
ArraySequence<int> seq = ArraySequence<int>(&array);
ArraySequence<int> *seq1 = new ArraySequence<int>();
seq1 = seq.GetSubSequence(0, 1);
ASSERT_EQ(1, seq1->GetFirst());
ASSERT_EQ(2, seq1->GetLast());
}
TEST(ArraySequence, Set1) {
DynamicArray<int> array = DynamicArray<int>(ABOBA, 5);
ArraySequence<int> seq = ArraySequence<int>(&array);
seq.Set(0,11);
ASSERT_EQ(11, seq.Get(0));
}
TEST(ArraySequence, operator_) {
DynamicArray<int> array = DynamicArray<int>(ABOBA, 5);
ArraySequence<int> seq = ArraySequence<int>(&array);
ASSERT_EQ(1, seq[0]);
ASSERT_EQ(2, seq[1]);
ASSERT_EQ(3, seq[2]);
ASSERT_EQ(4, seq[3]);
ASSERT_EQ(5, seq[4]);
}
TEST(ListSequence, Get_First_Get_Last) {
LinkedList<int> list = LinkedList<int>(ABOBA, 5);
ListSequence<int> seq = ListSequence<int>(&list);
ASSERT_EQ(1, seq.GetFirst());
ASSERT_EQ(5, seq.GetLast());
}
TEST(ListSequence, GetSize) {
LinkedList<int> list = LinkedList<int>(ABOBA, 5);
ListSequence<int> seq = ListSequence<int>(&list);
ASSERT_EQ(5, seq.GetSize());
}
TEST(ListSequence, Set) {
LinkedList<int> list = LinkedList<int>(ABOBA, 5);
ListSequence<int> seq = ListSequence<int>(&list);
seq.Set(1, 11);
ASSERT_EQ(11, seq.Get(1));
}

TEST(ListSequence, operator_) {
LinkedList<int> list = LinkedList<int>(ABOBA, 5);
ListSequence<int> seq = ListSequence<int>(&list);
ASSERT_EQ(1, seq[0]);
ASSERT_EQ(2, seq[1]);
ASSERT_EQ(3, seq[2]);
ASSERT_EQ(4, seq[3]);
ASSERT_EQ(5, seq[4]);
}

TEST(Matrix, Empty_Matrix) {
CommonMatrix<int> matrix = CommonMatrix<int>();
ASSERT_EQ(0, matrix.GetDim());
}
TEST(Matrix, GetRow_GetEl) {
ArraySequence<int> seq = ArraySequence<int>(Matrix3, 9);
CommonMatrix<int> matrix = CommonMatrix<int>(seq, 3, "common");
Sequence<int>* row = matrix.GetRow(0);
ASSERT_EQ(1,row->Get(0));
ASSERT_EQ(2,row->Get(1));
ASSERT_EQ(3,row->Get(2));
ASSERT_EQ(1,matrix.GetElement(0,0));
ASSERT_EQ(9,matrix.GetElement(2,2));
}
TEST(Matrix, SetEl) {
ArraySequence<int> seq = ArraySequence<int>(Matrix3, 9);
CommonMatrix<int> matrix = CommonMatrix<int>(seq, 3, "common");
Sequence<int>* row = matrix.GetRow(0);
matrix.SetElement(0,0, 11);
matrix.SetElement(1,1, 55);
matrix.SetElement(2,2, 99);
ASSERT_EQ(11,matrix.GetElement(0,0));
ASSERT_EQ(55,matrix.GetElement(1,1));
ASSERT_EQ(99,matrix.GetElement(2,2));
}
TEST(Matrix, operator_plus) {
ArraySequence<int> seq = ArraySequence<int>(Matrix2, 4);
CommonMatrix<int> matrix = CommonMatrix<int>(seq, 2, "common");
CommonMatrix<int> matrix1 = matrix + matrix;
ASSERT_EQ(2,matrix1.GetElement(0,0));
ASSERT_EQ(4,matrix1.GetElement(0,1));
ASSERT_EQ(6,matrix1.GetElement(1,0));
ASSERT_EQ(8,matrix1.GetElement(1,1));
}

TEST(Matrix, operator_minus) {
ArraySequence<int> seq = ArraySequence<int>(Matrix2, 4);
CommonMatrix<int> matrix = CommonMatrix<int>(seq, 2, "common");
CommonMatrix<int> matrix1 = matrix - matrix;
ASSERT_EQ(0,matrix1.GetElement(0,0));
ASSERT_EQ(0,matrix1.GetElement(0,1));
ASSERT_EQ(0,matrix1.GetElement(1,0));
ASSERT_EQ(0,matrix1.GetElement(1,1));
}

TEST(Matrix, multiply) {
ArraySequence<int> seq = ArraySequence<int>(Matrix2, 4);
CommonMatrix<int> matrix = CommonMatrix<int>(seq, 2, "common");
CommonMatrix<int> matrix1 = matrix * 5;
ASSERT_EQ(5,matrix1.GetElement(0,0));
ASSERT_EQ(10,matrix1.GetElement(0,1));
ASSERT_EQ(15,matrix1.GetElement(1,0));
ASSERT_EQ(20,matrix1.GetElement(1,1));
}

TEST(Matrix, Norm) {
ArraySequence<int> seq = ArraySequence<int>(Matrix2, 4);
CommonMatrix<int> matrix = CommonMatrix<int>(seq, 2, "common");
ASSERT_EQ(5,matrix.MatrixNorm<int>());
}

TEST(Matrix, Elementary_operations_1) {
ArraySequence<int> seq = ArraySequence<int>(Matrix2, 4);
CommonMatrix<int> matrix = CommonMatrix<int>(seq, 2, "common");
matrix.Sw_row(0,1,2);
matrix.Sw_col(0,1,2);
ASSERT_EQ(4,matrix.GetElement(0,0));
ASSERT_EQ(3,matrix.GetElement(0,1));
ASSERT_EQ(2,matrix.GetElement(1,0));
ASSERT_EQ(1,matrix.GetElement(1,1));
}

TEST(Matrix, Elementary_operations_2) {
ArraySequence<int> seq = ArraySequence<int>(Matrix2, 4);
CommonMatrix<int> matrix = CommonMatrix<int>(seq, 2, "common");
matrix.Sum_row(0,1,2);
matrix.Sum_col(0,1,2);
ASSERT_EQ(10,matrix.GetElement(0,0));
ASSERT_EQ(6,matrix.GetElement(0,1));
ASSERT_EQ(7,matrix.GetElement(1,0));
ASSERT_EQ(4,matrix.GetElement(1,1));
}

TEST(Matrix, Elementary_operations_3) {
ArraySequence<int> seq = ArraySequence<int>(Matrix2, 4);
CommonMatrix<int> matrix = CommonMatrix<int>(seq, 2, "common");
matrix.Multiply_row(2,0,2);
matrix.Multiply_col(2,0,2);
ASSERT_EQ(4,matrix.GetElement(0,0));
ASSERT_EQ(4,matrix.GetElement(0,1));
ASSERT_EQ(6,matrix.GetElement(1,0));
ASSERT_EQ(4,matrix.GetElement(1,1));
}

TEST(Matrix, Complex_Norm) {
ArraySequence<int> seq = ArraySequence<int>(Matrix2, 4);
CommonMatrix<int> matrix = CommonMatrix<int>(seq, 2, "common");
matrix.Multiply_row(2,0,2);
matrix.Multiply_col(2,0,2);
ASSERT_EQ(4,matrix.GetElement(0,0));
ASSERT_EQ(4,matrix.GetElement(0,1));
ASSERT_EQ(6,matrix.GetElement(1,0));
ASSERT_EQ(4,matrix.GetElement(1,1));
}

TEST(TriangleMatrix, GetEl_SetEl) {
ArraySequence<int> seq = ArraySequence<int>(MAMAM, 6);
TriangleMatrix<int> matrix = TriangleMatrix<int>(seq, 3, "upper");
ASSERT_EQ(3,matrix.GetDim());
ASSERT_EQ(1,matrix.GetElement(0,0));
ASSERT_EQ(6,matrix.GetElement(2,2));
TriangleMatrix<int> matrix1 = TriangleMatrix<int>(seq, 3, "lower");
matrix1.SetElement(1,1, 11);
ASSERT_EQ(11,matrix1.GetElement(1,1));
ASSERT_EQ(1,matrix1.GetElement(0,0));
ASSERT_EQ(6,matrix1.GetElement(2,2));
}
TEST(TriangleMatrix, complex) {
complex c1 = complex(1,5);
complex c2 = complex(3,9);
complex c3 = complex(-1,-3);
complex c4 = complex(-5,3);
complex c5 = complex(0,1);
complex c6 = complex(6,0);
complex c_arr[]={c1, c2, c3, c4, c5, c6};
complex *c_ptr = c_arr;
ArraySequence<complex> seq_c = ArraySequence<complex>(c_ptr,6);
TriangleMatrix<complex> matrixC = TriangleMatrix<complex>(seq_c, 3, "upper");
complex norm = matrixC.MatrixNorm<complex>();
EXPECT_FLOAT_EQ(2.5884647,norm.real());
EXPECT_FLOAT_EQ(4.32985,norm.imag());
}


/*
EXPECT_FLOAT_EQ(0,0);
EXPECT_ANY_THROW(arr.GetFirst());
EXPECT_ANY_THROW(arr.GetLast());
*/