#include "QuanLiDangKi.h"
#include "QuanLiSinhVien.h"
#include "QuanLiLopHoc.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Dang ki lop hoc
void QuanLiDangKi::dangKyHoc(vector<DangKiHoc>& dsDK,
                             const vector<SinhVien>& dsSV,
                             vector<LopHoc>& dsLop)
{
    cout << "\n--- DANG KY HOC ---\n";
    string maSV, maLop;
    cout << "Nhap ma sinh vien: ";
    cin >> maSV;
    QuanLiSinhVien qlSV;
    if (qlSV.timSinhVien(dsSV, maSV) == -1) {
        cout << "Sinh vien khong ton tai!\n";
        return;
    }
    
    cout << "Nhap ma lop: ";
    cin >> maLop;
    QuanLiLopHoc qlLop;
    int idxLop = qlLop.timLopHoc(dsLop, maLop);
    if (idxLop == -1) {
        cout << "Lop hoc khong ton tai!\n";
        return;
    }

    for (const auto& dk : dsDK) {
        if (dk.getMaSV() == maSV && dk.getMaLop() == maLop) {
            cout << "Sinh vien da dang ky lop nay roi!\n";
            return;
        }
    }

    if (dsLop[idxLop].lopDay()) {
        cout << "Lop da day! Khong the dang ky.\n";
        return;
    }

    dsDK.push_back(DangKiHoc(maSV, maLop));
    dsLop[idxLop].tangSiSo();
    cout << "Dang ky thanh cong: " << maSV << " -> " << maLop << ".\n";
}

//Huy dang ki
void QuanLiDangKi::huyDangKy(vector<DangKiHoc>& dsDK, vector<LopHoc>& dsLop) {
    cout << "\n--- HUY DANG KY HOC ---\n";
    string maSV, maLop;
    cout << "Nhap ma sinh vien: ";
    cin >> maSV;
    cout << "Nhap ma lop: ";
    cin >> maLop;

    QuanLiLopHoc qlLop;

    for (int i = 0; i < (int)dsDK.size(); i++) {
        if (dsDK[i].getMaSV() == maSV && dsDK[i].getMaLop() == maLop) {
            dsDK.erase(dsDK.begin() + i);
            int idx = qlLop.timLopHoc(dsLop, maLop);
            if (idx != -1) dsLop[idx].giamSiSo();
            cout << " Da huy dang ky " << maSV << " khoi lop " << maLop << ".\n";
            return;
        }
    }
    cout << "Khong tim thay dang ky tuong ung.\n";
}

//Liet ke sinh vien va lop hoc
void QuanLiDangKi::lietKeLopVaSinhVien(const vector<DangKiHoc>& dsDK,
                                       const vector<SinhVien>& dsSV,
                                       const vector<LopHoc>& dsLop)
{
    cout << "\n--- DANH SACH LOP VA SINH VIEN DANG KY ---\n";
    QuanLiSinhVien qlSV;
    
    for (const auto& lop : dsLop) {
        cout << "\nLop: " << lop.getMaLop() << " - " << lop.getTenLop()
             << "  [" << lop.getSiSoHienTai() << "/" << lop.getSiSoToiDa() << "]\n";
        cout << string(55, '-') << "\n";
        bool coSV = false;
        for (const auto& dk : dsDK) {
            if (dk.getMaLop() == lop.getMaLop()) {
                int idx = qlSV.timSinhVien(dsSV, dk.getMaSV());
                if (idx != -1) {
                    cout << "  " << left
                         << setw(10) << dsSV[idx].getMaSV()
                         << setw(25) << dsSV[idx].getHoTen()
                         << "\n";
                    coSV = true;
                }
            }
        }
        if (!coSV) cout << "  (Chua co sinh vien nao)\n";
    }
}