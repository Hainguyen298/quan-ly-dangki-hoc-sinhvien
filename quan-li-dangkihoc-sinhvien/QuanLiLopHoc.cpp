#include "QuanLiLopHoc.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Tim lop hoc
int QuanLiLopHoc::timLopHoc(const vector<LopHoc>& ds, const string& maLop) {
    for (int i = 0; i < (int)ds.size(); i++)
        if (ds[i].getMaLop() == maLop) return i;
    return -1;
}

//Them lop hoc
void QuanLiLopHoc::themLopHoc(vector<LopHoc>& ds) {
    cout << "\n--- THEM LOP HOC ---\n";
    string maLop;
    cout << "Nhap ma lop    : "; cin >> maLop;
    if (timLopHoc(ds, maLop) != -1) {
        cout << "Ma lop da ton tai!\n";
        return;
    }
    cin.ignore();
    string tenLop;
    int siSoToiDa;
    cout << "Nhap ten lop: ";
    getline(cin, tenLop);
    cout << "Si so toi da: ";
    cin >> siSoToiDa;

    ds.push_back(LopHoc(maLop, tenLop, siSoToiDa));
    cout << "Da them lop " << maLop << ".\n";
}

//Sua lop hoc
void QuanLiLopHoc::suaLopHoc(vector<LopHoc>& ds) {
    cout << "\n--- SUA LOP HOC ---\n";
    string ma;
    cout << "Nhap ma lop can sua: ";
    cin >> ma;
    int idx = timLopHoc(ds, ma);
    if (idx == -1) {
        cout << "Khong tim thay lop hoc.\n";
        return;
    }

    LopHoc& lop = ds[idx];
    cin.ignore();
    string t;
    cout << "Ten lop  [" << lop.getTenLop() << "]: ";
    getline(cin, t);
    if (!t.empty())
        lop.setTenLop(t);

    cout << "Si so toi da [" << lop.getSiSoToiDa() << "]: ";
    getline(cin, t);
    if (!t.empty()) {
        try {
            int ss = stoi(t);
            if (ss < lop.getSiSoHienTai()) {
                cout << "Si so toi da khong the nho hon si so hien tai "
                     << lop.getSiSoHienTai() << ")!\n";
            } else {
                lop.setSiSoToiDa(ss);
            }
        } catch (...) {
            cout << "[!] Si so khong hop le, giu nguyen.\n";
        }
    }
    cout << "Da cap nhat lop " << ma << ".\n";
}

//Xoa lop hoc
void QuanLiLopHoc::xoaLopHoc(vector<LopHoc>& ds, const vector<DangKiHoc>& dsDK) {
    cout << "\n--- XOA LOP HOC ---\n";
    string ma;
    cout << "Nhap ma lop can xoa: ";
    cin >> ma;
    int idx = timLopHoc(ds, ma);
    if (idx == -1) {
        cout << "Khong tim thay lop hoc.\n";
        return;
    }

    for (const auto& dk : dsDK) {
        if (dk.getMaLop() == ma) {
            cout << " Lop dang co sinh vien dang ky. Khong the xoa!\n";
            return;
        }
    }
    ds.erase(ds.begin() + idx);
    cout << " Da xoa lop " << ma << ".\n";
}

//Liet ke lop hoc
void QuanLiLopHoc::lietKeLopHoc(const vector<LopHoc>& ds) {
    cout << "\n--- DANH SACH LOP HOC ---\n";
    if (ds.empty()) { cout << "  (Chua co lop hoc nao)\n"; return; }
    cout << left
         << setw(12) << "Ma Lop"
         << setw(25) << "Ten Lop"
         << setw(12) << "Si So Max"
         << setw(12) << "Hien Tai"
         << "\n";
    cout << string(61, '-') << "\n";
    for (const auto& lop : ds) {
        cout << left
             << setw(12) << lop.getMaLop()
             << setw(25) << lop.getTenLop()
             << setw(12) << lop.getSiSoToiDa()
             << setw(12) << lop.getSiSoHienTai()
             << "\n";
    }
    cout << "Tong cong: " << ds.size() << " lop hoc.\n";
}