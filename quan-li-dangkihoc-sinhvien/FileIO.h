#ifndef FILEIO_H
#define FILEIO_H
#include <vector>
#include <string>
#include <fstream>
#include "SinhVien.h"
#include "LopHoc.h"
#include "DangKiHoc.h"

using namespace std;

class QuanLyFile {
private:
    string tenFileSinhVien;
    string tenFileLopHoc;
    string tenFileDangKy;
public:
    QuanLyFile()
        : tenFileSinhVien("sinhvien.txt"),
          tenFileLopHoc("lophoc.txt"),
          tenFileDangKy("dangky.txt") {}
    QuanLyFile(const string& fileSV, const string& fileLop, const string& fileDK)
        : tenFileSinhVien(fileSV), tenFileLopHoc(fileLop), tenFileDangKy(fileDK) {}

    void ghiDSSinhVien(const vector<SinhVien>& ds);
    vector<SinhVien> docDSSinhVien();

    void ghiDSLopHoc(const vector<LopHoc>& ds);
    vector<LopHoc> docDSLopHoc();
    
    void ghiDSDangKi(const vector<DangKiHoc>& ds);
    vector<DangKiHoc> docDSDangKi();
      
};

#endif