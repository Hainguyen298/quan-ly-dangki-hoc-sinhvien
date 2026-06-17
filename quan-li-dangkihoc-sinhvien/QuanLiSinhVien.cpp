#include "QuanLiSinhVien.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Tim sinh vien
int QuanLiSinhVien::timSinhVien(const vector<SinhVien>& ds, const string& maSV) {
    for (int i = 0; i < (int)ds.size(); i++)
        if (ds[i].getMaSV() == maSV) return i;
    return -1;
}

// Them sinh vien
void QuanLiSinhVien::themSinhVien(vector<SinhVien>& ds) {
    cout << "\n---- THEM SINH VIEN ----\n";
    string maSV;
    cout << "Nhap ma sinh vien : "; 
    cin >> maSV;
    if (timSinhVien(ds, maSV) != -1) {
        cout << "Ma sinh vien da ton tai!\n";
        return;
    }
    cin.ignore();
    string hoTen, ngaySinh, diaChi;
    float diemTB;
    cout << "Nhap ho ten: "; 
    getline(cin, hoTen);
    cout << "Nhap ngay sinh: "; 
    getline(cin, ngaySinh);
    cout << "Nhap dia chi: "; 
    getline(cin, diaChi);
    cout << "Nhap diem TB: "; 
    cin >> diemTB;

    ds.push_back(SinhVien(maSV, hoTen, ngaySinh, diaChi, diemTB));
    cout << "Da them sinh vien " << maSV << ".\n";
}

// Sua sinh vien
void QuanLiSinhVien::suaSinhVien(vector<SinhVien>& ds) {
    cout << "\n--- SUA SINH VIEN ---\n";
    string ma;
    cout << "Nhap ma sinh vien can sua: ";
    cin >> ma;
    int idx = timSinhVien(ds, ma);
    if (idx == -1) { cout << "[!] Khong tim thay sinh vien.\n"; return; }

    SinhVien& sv = ds[idx];
    cin.ignore();
    string t;
    cout << "Ho ten [" << sv.getHoTen()<< "]: ";
    getline(cin, t);
    if (!t.empty()) 
        sv.setHoTen(t);
    cout << "Ngay sinh [" << sv.getNgaySinh() << "]: ";
    getline(cin, t);
    if (!t.empty())
        sv.setNgaySinh(t);
    cout << "Dia chi [" << sv.getDiaChi()   << "]: ";
    getline(cin, t);
    if (!t.empty())
        sv.setDiaChi(t);
    cout << "Diem TB [" << sv.getDiemTB()   << "]: ";
    getline(cin, t);
    if (!t.empty()) {
        try { sv.setDiemTB(stof(t)); }
        catch (...) { cout << "Diem TB khong hop le, giu nguyen diem cu.\n"; }
    }
    cout << "Da cap nhat sinh vien " << ma << ".\n";
}

// Xoa sinh vien
void QuanLiSinhVien::xoaSinhVien(vector<SinhVien>& ds, const vector<DangKiHoc>& dsDK) {
    cout << "\n--- XOA SINH VIEN ---\n";
    string ma;
    cout << "Nhap ma sinh vien can xoa: "; cin >> ma;
    int idx = timSinhVien(ds, ma);
    if (idx == -1) {
        cout << "[!] Khong tim thay sinh vien.\n";
        return;
    }

    for (const auto& dk : dsDK) {
        if (dk.getMaSV() == ma) {
            cout << "Sinh vien dang dang ky lop " << dk.getMaLop()
                 << ". Khong the xoa!\n";
            return;
        }
    }
    ds.erase(ds.begin() + idx);
    cout << " Da xoa sinh vien " << ma << ".\n";
}

//  Liet ke sinh vien
void QuanLiSinhVien::lietKeSinhVien(const vector<SinhVien>& ds) {
    cout << "\n--- DANH SACH SINH VIEN ---\n";
    if (ds.empty()) {
        cout << "  (Chua co sinh vien nao)\n";
        return;
    }
    cout << left
         << setw(10) << "Ma SV"
         << setw(25) << "Ho Ten"
         << setw(12) << "Ngay Sinh"
         << setw(20) << "Dia Chi"
         << setw(8)  << "Diem TB"
         << "\n";
    cout << string(75, '-') << "\n";
    for (const auto& sv : ds) {
        cout << left
             << setw(10) << sv.getMaSV()
             << setw(25) << sv.getHoTen()
             << setw(12) << sv.getNgaySinh()
             << setw(20) << sv.getDiaChi()
             << fixed << setprecision(2) << sv.getDiemTB()
             << "\n";
    }
    cout << "Tong cong: " << ds.size() << " sinh vien.\n";
}
