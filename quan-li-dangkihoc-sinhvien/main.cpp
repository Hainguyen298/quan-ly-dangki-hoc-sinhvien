#include <iostream>
#include <vector>
#include <limits>
#include "SinhVien.h"
#include "LopHoc.h"
#include "DangKiHoc.h"
#include "FileIO.h"
#include "QuanLiSinhVien.h"
#include "QuanLiLopHoc.h"
#include "QuanLiDangKi.h"

using namespace std;

// ─────────────────────────────────────────────
void hienMenu() {
    cout << "\n========================================\n";
    cout << "   QUAN LY DANG KY HOC CUA SINH VIEN\n";
    cout << "========================================\n";
    cout << " 1.  Nhap them 1 sinh vien\n";
    cout << " 2.  Sua thong tin sinh vien (theo ma)\n";
    cout << " 3.  Xoa 1 sinh vien (theo ma)\n";
    cout << " 4.  Nhap them 1 lop hoc\n";
    cout << " 5.  Sua thong tin lop hoc (theo ma)\n";
    cout << " 6.  Xoa lop hoc (theo ma)\n";
    cout << " 7.  Dang ky hoc\n";
    cout << " 8.  Huy dang ky hoc\n";
    cout << " 9.  Liet ke toan bo sinh vien\n";
    cout << " 10. Liet ke toan bo lop hoc\n";
    cout << " 11. Liet ke lop hoc cung sinh vien dang ky\n";
    cout << " 12. Thoat\n";
    cout << "----------------------------------------\n";
    cout << " Lua chon: ";
}

// ─────────────────────────────────────────────
int main() {
    QuanLyFile      fileIO;
    QuanLiSinhVien  qlSV;
    QuanLiLopHoc    qlLop;
    QuanLiDangKi    qlDK;

    // Doc du lieu tu file khi khoi dong
    vector<SinhVien>  dsSV  = fileIO.docDSSinhVien();
    vector<LopHoc>    dsLop = fileIO.docDSLopHoc();
    vector<DangKiHoc> dsDK  = fileIO.docDSDangKi();

    int luaChon = 0;
    do {
        hienMenu();
        if (!(cin >> luaChon)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            luaChon = -1;
        }

        switch (luaChon) {
            case 1:
                qlSV.themSinhVien(dsSV);
                fileIO.ghiDSSinhVien(dsSV);
                break;
            case 2:
                qlSV.suaSinhVien(dsSV);
                fileIO.ghiDSSinhVien(dsSV);
                break;
            case 3:
                qlSV.xoaSinhVien(dsSV, dsDK);
                fileIO.ghiDSSinhVien(dsSV);
                break;
            case 4:
                qlLop.themLopHoc(dsLop);
                fileIO.ghiDSLopHoc(dsLop);
                break;
            case 5:
                qlLop.suaLopHoc(dsLop);
                fileIO.ghiDSLopHoc(dsLop);
                break;
            case 6:
                qlLop.xoaLopHoc(dsLop, dsDK);
                fileIO.ghiDSLopHoc(dsLop);
                break;
            case 7:
                qlDK.dangKyHoc(dsDK, dsSV, dsLop);
                fileIO.ghiDSDangKi(dsDK);
                fileIO.ghiDSLopHoc(dsLop);   // cap nhat si so
                break;
            case 8:
                qlDK.huyDangKy(dsDK, dsLop);
                fileIO.ghiDSDangKi(dsDK);
                fileIO.ghiDSLopHoc(dsLop);   // cap nhat si so
                break;
            case 9:
                qlSV.lietKeSinhVien(dsSV);
                break;
            case 10:
                qlLop.lietKeLopHoc(dsLop);
                break;
            case 11:
                qlDK.lietKeLopVaSinhVien(dsDK, dsSV, dsLop);
                break;
            case 12:
                cout << "\nTam biet!\n";
                break;
            default:
                cout << "[!] Lua chon khong hop le. Vui long nhap lai.\n";
        }
    } while (luaChon != 12);

    return 0;
}