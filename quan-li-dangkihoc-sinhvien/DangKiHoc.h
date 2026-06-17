#ifndef DANGKIHOC_H
#define DANGKIHOC_H
#include <string>
using namespace std;

class DangKiHoc{
private:
    string maSV;
    string maLop;
public:
    DangKiHoc();
    DangKiHoc(const string& maSV, const string& maLop);

    string getMaSV() const;
    string getMaLop() const;

    void setMaSV(const string& other);
    void setMaLop(const string& other);
};
#endif