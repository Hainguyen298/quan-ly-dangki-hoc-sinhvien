#ifndef QUANLIDANGKI_H
#define QUANLIDANGKI_H
#include <vector>
#include "SinhVien.h"
#include "LopHoc.h"
#include "DangKiHoc.h"

using namespace std;

class QuanLiDangKi {
public:
    void dangKyHoc(vector<DangKiHoc>& dsDK,
                   const vector<SinhVien>& dsSV,
                   vector<LopHoc>& dsLop);

    void huyDangKy(vector<DangKiHoc>& dsDK,
                   vector<LopHoc>& dsLop);

    void lietKeLopVaSinhVien(const vector<DangKiHoc>& dsDK,
                             const vector<SinhVien>& dsSV,
                             const vector<LopHoc>& dsLop);
};
#endif