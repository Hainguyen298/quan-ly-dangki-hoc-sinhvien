#ifndef QUANLISINHVIEN_H
#define QUANLISINHVIEN_H
#include <vector>
#include "SinhVien.h"
#include "DangKiHoc.h"

class QuanLiSinhVien{
public:
    int timSinhVien(const vector<SinhVien>& ds, const string& maSV);
    void themSinhVien(vector<SinhVien>& ds);
    void suaSinhVien(vector<SinhVien>& ds);
    void xoaSinhVien(vector<SinhVien>& ds, const vector<DangKiHoc>& dsDK);
    void lietKeSinhVien(const vector<SinhVien>& ds);
}; 
#endif