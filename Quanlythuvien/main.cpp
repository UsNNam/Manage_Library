#include"Quanlythuvien.h"
#include<iostream>
#include<math.h>
#include<iomanip>
#include<cstdlib>
#include<string>
#include<fstream>
using namespace std;
int main() {
	resizeConsole(1500, 800);
	int count = 0;
	ifstream filein;
	ofstream fileout;
	docgia Docgia[100];
	sach Sach[100];
	phieumuonsach Phieumuonsach[100];
	phieutrasach Phieutrasach[100];
	string phieumuonsach[100][10] = { "" };
	string phieutrasach[100][10] = { "" };

	string ngayhomnay;
	cout << "Nhap ngay hom nay: " << endl;
	getline(cin, ngayhomnay);
	cout << "Danh sach chuc nang gom co:" << endl;
	cout << "1. Quan ly doc gia" << endl;
	cout << "2. Quan ly sach " << endl;
	cout << "3. Lap phieu muon sach" << endl;
	cout << "4. Lap phieu tra sach" << endl;
	cout << "5. Cac thong ke co ban" << endl;
	cout << "Chon 0 de dung chuong trinh" << endl;
	while (true)
	{
		cout << "Chon chuc nang chinh (vi du: 1,2,3,...):" << endl;
		int chucnang;
		cin >> chucnang;
		if (chucnang != 1 && chucnang != 2 && chucnang != 3 && chucnang != 4 && chucnang != 5) break;
		switch (chucnang) {
		case 1:
		{
			Docfiledocgia(filein, Docgia);
			cout << "a.Xem danh sach doc gia trong thu vien" << endl;
			cout << "b.Them doc gia" << endl;
			cout << "c.Chinh sua thong tin mot doc gia" << endl;
			cout << "d.Xoa thong tin mot doc gia" << endl;
			cout << "e.Tim kiem doc gia theo CMND" << endl;
			cout << "f.Tim kiem sach theo ho ten" << endl;
			cout << "Chon chuc nang (vi du:a,b,c,...):" << endl;
			string s;
			cin >> s;
			if (s == "a") {
				Inradanhsachdocgia(filein,Docgia);
			}
			else if (s == "b") {
				Themdocgia(fileout,Docgia);
			}
			else if (s == "c") {
				string madocgia;
				cin.ignore(32767, '\n');
				cout << "Nhap ma doc gia can chinh sua:";
				getline(cin, madocgia);
				cout << endl;
				Chinhsuathongtindocgia(Docgia, madocgia,filein, fileout);
				cout << endl;
			}
			else if (s == "d") {
				string madocgia;
				cout << "Nhap ma doc gia can xoa:";
				cin.ignore(32767, '\n');
				getline(cin, madocgia);
				for (int i = 0; i < 100; i++) {
					if (madocgia == Docgia[i].madocgia) {
							Docgia[i].madocgia = "";
							Docgia[i].hoten = "";
							Docgia[i].cmnd = "";
							Docgia[i].ngaysinh = "";
							Docgia[i].gioitinh = "";
							Docgia[i].email = "";
							Docgia[i].diachi = "";
							Docgia[i].ngaylapthe = "";
							Docgia[i].ngayhethan = "";
					}
				}
				Capnhatfiledocgia(fileout, Docgia);

			}
			else if (s == "e") {
				string CMND;
				cout << "Nhap so CMND:";
				cin.ignore(32767, '\n');
				getline(cin, CMND);
				cout << endl;
				timdanhsachtheocmnd(Docgia, CMND,filein);
			}
			else if (s == "f") {
				string hoten;
				cin.ignore(32767, '\n');
				cout << "Nhap ho ten can tim:";
				getline(cin, hoten);
				Timdanhsachtheohoten(Docgia, hoten);
			}
			else {
				cout << "Chuc nang ban da chon khong ton tai" << endl;
			}
			break;
		}
		case 2:
		{
			Docfilesach(filein, Sach);
			cout << "a.Xem danh sach cac sach trong thu vien" << endl;
			cout << "b.Them sach" << endl;
			cout << "c.Chinh sua thong tin mot quyen sach" << endl;
			cout << "d.Xoa thong tin sach" << endl;
			cout << "e.Tim kiem sach theo ISBN" << endl;
			cout << "f.Tim kiem sach theo ten sach" << endl;
			cout << "Chon chuc nang(vi du a,b,c...):" << endl;
			string s;
			cin >> s;
			if (s == "a") {
				Inradanhsachsach(Sach,filein);
			}
			else if (s == "b") {
				Themsach(Sach,fileout);
			}
			else if (s == "c") {
				string ISBN;
				cin.ignore(32767, '\n');
				cout << "Nhap ma sach can chinh sua:";
				getline(cin, ISBN);
				cout << endl;
				Chinhsuathongtin1quyensach(Sach,ISBN,fileout);
			}
			else if (s == "d") {
				string ISBN;
				cout << "Nhap ma sach ISBN can xoa:";
				cin.ignore(32767, '\n');
				getline(cin, ISBN);
				for (int i = 0; i < 100; i++) {
					if (ISBN == Sach[i].ISBN) {
						Sach[i].ISBN = "";
						Sach[i].tensach = "";
						Sach[i].tacgia = "";
						Sach[i].NXB = "";
						Sach[i].namXB = "";
						Sach[i].theloai = "";
						Sach[i].giasach = "";
						Sach[i].soluong = "";
					}
				}
				Capnhatfilesach(fileout, Sach);
			}
			else if (s == "e") {
				string ISBN;
				cout << "Nhap ISBN can tim:";
				cin.ignore(32767, '\n');
				getline(cin, ISBN);
				TimkiemsachtheoISBN(Sach, ISBN);
			}
			else if (s == "f") {
				string tensach;
				cout << "Nhap ten sach can tim:";
				cin.ignore(32767, '\n');
				getline(cin, tensach);
				Timkiemdanhsachtheotensach(Sach, tensach);
			}
		}
		break;
		case 3:
		{
			hamphieumuonsach(Phieumuonsach,Sach,Docgia,ngayhomnay);
			Capnhatfilephieumuonsach(fileout, Phieumuonsach);
			Capnhatfilesach(fileout, Sach);
		}
		break;
		case 4:
		{
			trasach(Sach,Phieumuonsach, Phieutrasach);
			Capnhatfilephieumuonsach(fileout, Phieumuonsach);
			Capnhatfilesach(fileout, Sach);
		}
		break;
		case 5:
		{
			Docfiledocgia(filein, Docgia);
			Docfilesach(filein, Sach);
			cout << "a.Thong ke so luong sach trong thu vien" << endl;
			cout << "b.Thong ke so luong sach theo the loai" << endl;
			cout << "c.Thong ke so luong doc gia" << endl;
			cout << "d.Thong ke so luong doc gia theo gioi tinh" << endl;
			cout << "e.Thong ke so luong sach dang duoc muon" << endl;
			cout << "f.Thong ke danh sach doc gia bi tre han" << endl;
			string l;
			cin >> l;
			if (l == "a") {
				Thongkesoluongsachcotrongthuvien(Sach);
				break;
			}
			else if (l == "b") {
				string dstheloai[100] = { "" };
				int soluongtheloai[100] = { 0 };
				Inradanhsachcactheloaisach(Sach, dstheloai,soluongtheloai);
				cout << endl;
				string theloai;
				cout << "Chon the loai:";
				cin.ignore(32767, '\n');
				getline(cin, theloai);
				Thongkesoluongsachtheotheloai(Sach, theloai);
			}
			else if (l == "c") {
				cout << "So luong doc gia: " << Thongkesoluongdocgia(Docgia)<<endl;
			}
			else if (l == "d") {
				Thongkesoluongdocgiatheogioitinh(Docgia);
			}
			else if (l == "e") {
				cout << "So luong sach dang duoc muon: " << Thongkesosachdangduocmuon(Phieumuonsach)<<endl;
			}
			else if (l == "f") {
				cout << "Danh sach doc gia tre han: " << endl;
				Danhsachdocgiatrehan(Docgia, Phieumuonsach,ngayhomnay);
			}
		}
		break;
		case 0:
			break;
		default:
			cout << "Ban da nhap sai chuc nang"<<endl;
			break;
		}
		
	}
	return 0;
}