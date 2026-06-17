#include "DangKiHoc.h"
#include <string>
using namespace std;

DangKiHoc::DangKiHoc(){}
DangKiHoc::DangKiHoc(const string& maSV, const string& maLop)
          :maSV(maSV), maLop(maLop){}

string DangKiHoc::getMaSV() const{
    return maSV;
}
string DangKiHoc::getMaLop() const{
    return maLop;
}
void DangKiHoc::setMaSV(const string& other){
    maSV = other;
}
void DangKiHoc::setMaLop(const string& other){
    maLop = other;
}