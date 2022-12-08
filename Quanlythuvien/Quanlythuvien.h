#pragma once
#include<iostream>

using namespace std;
struct docgia {
	string madocgia;
	string hoten;
	string cmnd;
	string ngaysinh;
	string gioitinh;
	string email;
	string diachi, ngaylapthe,ngayhethan;
};
struct sach {
	string ISBN, tensach,tacgia, NXB, namXB, theloai, giasach, soluong;
};
struct phieumuonsach {
	string madocgia, ngaymuon, ngaytradukien, ISBN;
};
struct phieutrasach {
	string madocgia, ngaymuon, ngaytradukien, ngaytrathucte, ISBN;
};
void resizeConsole(int width, int height);
void Inradanhsachdocgia(ifstream &filein,docgia Docgia[100]);
void Themdocgia(ofstream &fileout, docgia Docgia[100]);
void timdanhsachtheocmnd(docgia Docgia[100], string CMND, ifstream& filein);
void Timdanhsachtheohoten(docgia Docgia[100], string hoten);
void Docfiledocgia(ifstream& filein, docgia Docgia[100]);
void Capnhatfiledocgia(ofstream& fileout, docgia Docgia[100]);
void Capnhatfilesach(ofstream& fileout, sach Sach[100]);
void Docfilesach(ifstream& filein, sach Sach[100]);
void Docfilephieumuonsach(ifstream& filein, phieumuonsach phieumuonsach[100]);
void Capnhatfilephieumuonsach(ofstream& fileout, phieumuonsach phieumuonsach[100]);
void Capnhatfilephieutrasach(ofstream& fileout, phieutrasach phieutrasach[100]); 
void Inradanhsachdocgia(ifstream& filein, docgia Docgia[100]);
void Chinhsuathongtindocgia(docgia Docgia[100], string madocgia, ifstream& filein, ofstream& fileout);
void Inradanhsachsach(sach Sach[100], ifstream& filein);
void Themsach(sach Sach[100], ofstream& fileout);
void Chinhsuathongtin1quyensach(sach Sach[100], string ISBN, ofstream& fileout);
void TimkiemsachtheoISBN(sach Sach[100], string ISBN);
void Timkiemdanhsachtheotensach(sach Sach[100], string tensach);
void hamphieumuonsach(phieumuonsach phieumuonsach[100], sach Sach[100], docgia Docgia[100], string ngayhomnay);
void Thongkesoluongsachcotrongthuvien(sach Sach[100]);
void Thongkesoluongsachtheotheloai(sach Sach[100], string theloai);
void Inradanhsachcactheloaisach(sach Sach[100], string dstheloai[100], int soluongtheloai[100]);
int Thongkesoluongdocgia(docgia Docgia[100]);
void Thongkesoluongdocgiatheogioitinh(docgia Docgia[100]);
void Capnhatsoluongmuonsach(sach Sach[100], phieumuonsach phieumuonsach[100]);
void Capnhatsoluongtrasach(sach Sach[100], phieutrasach phieutrasach[100]);
void trasach(sach Sach[100], phieumuonsach phieumuonsach[100], phieutrasach phieutrasach[100]);
int Trehan(string a, string b);
int thutungay(int year, int month, int day);
int phatmatsach(string ISBN, sach Sach[100]);
int Thongkesosachdangduocmuon(phieumuonsach phieumuonsach[100]);
void Danhsachdocgiatrehan(docgia Docgia[100], phieumuonsach phieumuonsach[100], string ngayhomnay);