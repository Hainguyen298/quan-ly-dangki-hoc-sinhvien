#ifndef SINHVIEN_H
#define SINHVIEN_H
#include <iostream>
#include <string>
using namespace std;

class SinhVien{
private:
    string maSV;
    string hoTen;
    string ngaySinh;
    string diaChi;
    float diemTB;
public:
//Constructor mac dinh
    SinhVien();
    //Constructor day du
    SinhVien(const string& maSV, const string& hoTen, 
             const string& ngaySinh, const string& diaChi,
             float diemTB);
    //Getter
    string getMaSV() const;
    string getHoTen() const;
    string getNgaySinh() const;
    string getDiaChi() const;
    float getDiemTB() const;
    //Setter
    void setMaSV(const string& other);
    void setHoTen(const string& other);
    void setNgaySinh(const string& other);
    void setDiaChi(const string& other);
    void setDiemTB(float other);
};
#endif