#ifndef QUANLILOPHOC_H
#define QUANLILOPHOC_H
#include <vector>
#include "LopHoc.h"
#include "DangKiHoc.h"

class QuanLiLopHoc{
public:
    int timLopHoc(const vector<LopHoc>& ds, const string& maLop);
    void themLopHoc(vector<LopHoc>& ds);
    void suaLopHoc(vector<LopHoc>& ds);
    void xoaLopHoc(vector<LopHoc>& ds, const vector<DangKiHoc>& dsDK);
    void lietKeLopHoc(const vector<LopHoc>& ds);
};
#endif