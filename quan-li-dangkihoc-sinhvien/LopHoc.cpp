#include"LopHoc.h"
#include <string>
using namespace std;

LopHoc::LopHoc():siSoToiDa(0), siSoHienTai(0){}
LopHoc::LopHoc(const string& maLop, const string& tenLop, int siSoToiDa)
        : maLop(maLop), tenLop(tenLop),
          siSoToiDa(siSoToiDa), siSoHienTai(0){}

string LopHoc::getMaLop() const{
    return maLop;
}
string LopHoc::getTenLop() const{
    return tenLop;
}
int LopHoc::getSiSoToiDa() const{
    return siSoToiDa;
}
int LopHoc::getSiSoHienTai() const{
    return siSoHienTai;
}

void LopHoc::setMaLop(const string& other){
    maLop = other;
}
void LopHoc::setTenLop(const string& other){
    tenLop = other;
}
void LopHoc::setSiSoToiDa(int other){
    siSoToiDa = other;
}
void LopHoc::setSiSoHienTai(int other){
    siSoHienTai = other;
}

void LopHoc::tangSiSo(){
    siSoHienTai++;
}
void LopHoc::giamSiSo(){
    if(siSoHienTai > 0)
        siSoHienTai--;
}
bool LopHoc::lopDay() const{
    return siSoHienTai >= siSoToiDa;
}