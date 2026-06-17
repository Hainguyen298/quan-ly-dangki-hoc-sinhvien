#include"SinhVien.h"
#include <iostream>
#include <string>
using namespace std;

SinhVien::SinhVien()
        :diemTB(0.0f){}
SinhVien::SinhVien(const string& maSV, const string& hoTen, 
             const string& ngaySinh, const string& diaChi,
             float diemTB)
        : maSV(maSV), hoTen(hoTen), ngaySinh(ngaySinh),
          diaChi(diaChi), diemTB(diemTB) {}
string SinhVien::getMaSV() const{
        return maSV;
}

string SinhVien::getHoTen() const{
        return hoTen;
}
string SinhVien::getNgaySinh() const{
        return ngaySinh;
}
string SinhVien::getDiaChi() const{
        return diaChi;
}
float SinhVien::getDiemTB() const{
        return diemTB;
}

void SinhVien::setMaSV(const string& other){
        maSV = other;
}
void SinhVien::setHoTen(const string& other){
        hoTen = other;
}
void SinhVien::setNgaySinh(const string& other){
        ngaySinh = other;
}
void SinhVien::setDiaChi(const string& other){
        diaChi = other;
}
void SinhVien::setDiemTB(float other){
        diemTB = other;
}