#ifndef LOPHOC_H
#define LOPHOC_H
#include <string>
using namespace std;

class LopHoc{
private:
    string maLop;
    string tenLop;
    int siSoToiDa;
    int siSoHienTai;
public:
    LopHoc();
    LopHoc(const string& maLop, const string& tenLop, int siSoToiDa);

    string getMaLop() const;
    string getTenLop() const;
    int getSiSoToiDa() const;
    int getSiSoHienTai() const;

    void setMaLop(const string& other);
    void setTenLop(const string& other);
    void setSiSoToiDa(int other);
    void setSiSoHienTai(int other);

    void tangSiSo();
    void giamSiSo();

    bool lopDay() const;
};
#endif