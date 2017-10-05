#include <iostream>
#include "Matrix.cpp"

using namespace std;

int main() {
    /*  Matrix<double> tmp1(2, 2, 5.2);
  //    tmp1(0,0)=1000;
      tmp1.print();
      Matrix<double> tmp2(2, 2, 2);
      tmp2.print();
      if (tmp1 != tmp2) {
          cout << "hello..." << endl;
      }
      Matrix<double> tmp4 = tmp1 ^1;
      tmp4(0,1)=111.22;
      tmp4.print();
      tmp4.transpose();
      tmp4.print();*/

    /*double Array[4]={1,-2,0,1};
    Matrix<double > tmp5(Array,2,2);
    tmp5.print();
    tmp5.negative();
    tmp5.print();
    tmp5.ones(4,4);
    tmp5.print();
    tmp5.AddRows(0,1,1.2);
    tmp5.print();*/


    /*double a=2.2;
    Matrix<int> tmp3=tmp1*a;
    tmp3.print();
    return 0;*/

    /*Matrix<double> tmp(5, 5, 1.8);
    tmp.print();
    int RowSlice[2] = {1, 4};
    int ColSlice[2] = {2, 4};
    Matrix<double> tmp1 = tmp.slice(RowSlice, ColSlice);
    tmp1.print();
    cout<<endl;
    int RowSliceIndex1[3] = {0, 2, 4};
    int RowSliceIndex2[3] = {1, 3};
    Matrix<double> tmp2 = tmp.sliceByIndex(RowSliceIndex1, 3, RowSliceIndex2, 2);
    tmp2.print();*/

    /* double Array[4] = {1, 1, -1, 1};
     Matrix<double> tmp5(Array, 2, 2);
     tmp5.print();
     Matrix<double> tmp_inv=tmp5.inv();
     string str="hello";
     Matrix<string> tmpnew(4,4,str);
     tmpnew.print();
     tmp_inv.print();*/

    /*double Array[4] = {10, 100, -10, 1};
    Matrix<double> tmp5(Array, 2, 2);
    tmp5.print();
    cout << tmp5.min() << endl;
    Matrix<double> tmp=tmp5.max(0);
    tmp.print();
    cout<<tmp.sum()<<endl;
    cout<<tmp.mean()<<endl;
    Matrix<double> tmp11=tmp5.sum(0);*/

    /* double Array[4] = {10, 100, -10, 1};
     Matrix<double> tmp(Array, 2, 2);*/
    /*tmp.print();
    tmp.inv().print();
    tmp.sort().transpose().print();
    tmp.slice(0, 2, 0, 1).sort().print();*/
    /*cout << tmp;
    tmp.range(0, 10, 10);
    cout << tmp;
    Matrix<double> RowIndex(1, 1, 0);
    Matrix<double> ColIndex;
    ColIndex.range(0, 6, 4);
    tmp.sliceByIndex(RowIndex, ColIndex).print();
    Matrix<double > tmp11=tmp^2;
    tmp11.print();*/
    double Array[4] = {0, 100, -10, 1};
    Matrix<double> tmp(Array, 2, 2);
    if(tmp.haveZero()){
        cout << tmp;
    }
    Matrix<double> ret=~(tmp==1);
    cout<<ret;
    tmp.setVal(ret,1022);
    cout << tmp;
    if((tmp&ret).haveZero()){
        cout<<"helllo"<<endl;
    }
    Matrix<double> MAT=tmp(ret)=233;
    cout<<MAT<<endl;
}