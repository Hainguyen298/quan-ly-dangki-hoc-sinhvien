#include "FileIO.h"
#include <iostream>

using namespace std;

void QuanLyFile::ghiDSSinhVien(const vector<SinhVien>& ds) {
    ofstream f(tenFileSinhVien);   // mo file de ghi (van ban)
    if (!f) { cerr << "Loi mo file " << tenFileSinhVien << "\n"; return; }

    for (const auto& sv : ds) {
        f << sv.getMaSV()     << "\n";
        f << sv.getHoTen()    << "\n";
        f << sv.getNgaySinh() << "\n";
        f << sv.getDiaChi()   << "\n";
        f << sv.getDiemTB()   << "\n";
    }
}

vector<SinhVien> QuanLyFile::docDSSinhVien() {
    vector<SinhVien> ds;
    ifstream f(tenFileSinhVien);
    if (!f) return ds;   // file chua ton tai -> tra ve danh sach rong

    string maSV, hoTen, ngaySinh, diaChi, diemTBStr;
    // Doc 5 dong moi lan, lap lai cho den het file
    while (getline(f, maSV)) {
        getline(f, hoTen);
        getline(f, ngaySinh);
        getline(f, diaChi);
        getline(f, diemTBStr);

        float diemTB = stof(diemTBStr);   // doi chuoi "8.5" -> so 8.5
        ds.push_back(SinhVien(maSV, hoTen, ngaySinh, diaChi, diemTB));
    }
    return ds;
}
void QuanLyFile::ghiDSLopHoc(const vector<LopHoc>& ds) {
    ofstream f(tenFileLopHoc);
    if (!f) { cerr << "Loi mo file " << tenFileLopHoc << "\n"; return; }

    for (const auto& lop : ds) {
        f << lop.getMaLop()       << "\n";
        f << lop.getTenLop()      << "\n";
        f << lop.getSiSoToiDa()   << "\n";
        f << lop.getSiSoHienTai() << "\n";
    }
}

vector<LopHoc> QuanLyFile::docDSLopHoc() {
    vector<LopHoc> ds;
    ifstream f(tenFileLopHoc);
    if (!f) return ds;

    string maLop, tenLop, line;
    while (getline(f, maLop)) {
        getline(f, tenLop);

        LopHoc lop;
        lop.setMaLop(maLop);
        lop.setTenLop(tenLop);

        getline(f, line);  lop.setSiSoToiDa(stoi(line));
        getline(f, line);  lop.setSiSoHienTai(stoi(line));

        ds.push_back(lop);
    }
    return ds;
}
void QuanLyFile::ghiDSDangKi(const vector<DangKiHoc>& ds) {
    ofstream f(tenFileDangKy);
    if (!f) { cerr << "Loi mo file " << tenFileDangKy << "\n"; return; }

    for (const auto& dk : ds) {
        f << dk.getMaSV()  << "\n";
        f << dk.getMaLop() << "\n";
    }
}

vector<DangKiHoc> QuanLyFile::docDSDangKi() {
    vector<DangKiHoc> ds;
    ifstream f(tenFileDangKy);
    if (!f) return ds;

    string maSV, maLop;
    while (getline(f, maSV)) {
        getline(f, maLop);
        ds.push_back(DangKiHoc(maSV, maLop));
    }
    return ds;
}