#include"Quanlythuvien.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<sstream>
#include<Windows.h>
#include<fstream>
using namespace std;
/*Ham nay dung de chinh sua kich thuoc cua man hinh console, voi gia tri dau vao la chieu dai va chieu rong,
co y nghia thay doi kich thuoc de phu hop voi cac thong tin duoc the hien tren man hinh console.*/
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
// Ham nay dung de tinh ngay het han cua mot doc gia trong thu vien voi dau vao la ngay lap the duoi dang kieu ky tu tuong ung.
string Ngayhethan(string a) {
	string ngayhethan="";
	string day1 = "";
	string month1 = "";
	string year1 = "";
	day1.append(a, 0, 2);
	stringstream str1(day1);
	int ngay1 = 0;
	str1 >> ngay1;
	month1.append(a, 3, 4);
	stringstream str2(month1);
	int thang1 = 0;
	str2 >> thang1;
	year1.append(a, 6, 10);
	stringstream str3(year1);
	int nam1 = 0;
	str3 >> nam1;
	nam1 = nam1 + 4;
	ngayhethan.append(to_string(ngay1));
	ngayhethan.append("/");
	ngayhethan.append(to_string(thang1));
	ngayhethan.append("/");
	ngayhethan.append(to_string(nam1));
	return ngayhethan;
}
/*Ham nay dung de doc thong tin tu tap tin co san voi du lieu dau vao la filein de mo file 
va mang 1 chieu voi kieu du lieu da duoc dinh nghia san, co y nghia lay thong tin tu file 
co san de tai len chuong trinh. */
void Docfiledocgia(ifstream &filein, docgia Docgia[100]) {
	filein.open("Docgia.txt", ios::in);
	if (filein.fail() == true) {
		cout << "Khong tim thay file"<<endl;
	}
	else {
		int i = 0;
		while (filein.eof() == false) {
			getline(filein, Docgia[i].madocgia,';');
			getline(filein, Docgia[i].hoten, ';');
			getline(filein, Docgia[i].cmnd, ';');
			getline(filein, Docgia[i].ngaysinh, ';');
			getline(filein, Docgia[i].gioitinh, ';');
			getline(filein, Docgia[i].email, ';');
			getline(filein, Docgia[i].diachi, ';');
			getline(filein, Docgia[i].ngaylapthe, ';');
			getline(filein, Docgia[i].ngayhethan);
			i++;
		}
		filein.close();
	}
	
}
/*Ham nay dung de cap nhat thong tin tu chuong trinh tro lai file voi hai du lieu dau vao
la fileout de ghi du lieu va mang 1 chieu voi kieu du lieu duoc dinh nghia san, ham
nay co y nghia co the giup cap nhat thong tin vao tap tin sau moi lan xu ly cac
tac vu tren chuong trinh, cac thong tin tren chuong trinh thay doi thi deu duoc luu lai tren tap tin .*/
void Capnhatfiledocgia(ofstream& fileout, docgia Docgia[100]) {
	fileout.open("Docgia.txt", ios::trunc);
	if (fileout.fail() == true) {
		cout << "Khong tim thay file \n";
	}
	else {
		for (int i = 0; i < 100; i++) {
			if (Docgia[i].madocgia == "") continue;
			fileout << Docgia[i].madocgia << ";";
			fileout << Docgia[i].hoten << ";";
			fileout << Docgia[i].cmnd << ";";
			fileout << Docgia[i].ngaysinh << ";";
			fileout << Docgia[i].gioitinh << ";";
			fileout << Docgia[i].email << ";";
			fileout << Docgia[i].diachi << ";";
			fileout << Docgia[i].ngaylapthe << ";";
			fileout << Docgia[i].ngayhethan<<endl;
		}
	}
	fileout.close();
}
/*Ham nay dung de cap nhat thong tin tu chuong trinh tro lai file voi hai du lieu dau vao
la fileout de ghi du lieu va mang 1 chieu voi kieu du lieu duoc dinh nghia san, ham
nay co y nghia co the giup cap nhat thong tin vao tap tin sau moi lan xu ly cac
tac vu tren chuong trinh, cac thong tin tren chuong trinh thay doi thi deu duoc luu lai tren tap tin .*/
void Capnhatfilesach(ofstream& fileout, sach Sach[100]) {
	fileout.open("Sach.txt", ios::trunc);
	if (fileout.fail() == true) {
		cout << "Khong tim thay file \n";
	}
	else {
		for (int i = 0; i < 100; i++) {
			if (Sach[i].ISBN == "") continue;
			fileout << Sach[i].ISBN << ";";
			fileout << Sach[i].tensach << ";";
			fileout << Sach[i].tacgia << ";";
			fileout << Sach[i].NXB << ";";
			fileout << Sach[i].namXB << ";";
			fileout << Sach[i].theloai << ";";
			fileout << Sach[i].giasach << ";";
			fileout << Sach[i].soluong << endl;
		}
	}
	fileout.close();
}
/*Ham nay dung de doc thong tin tu tap tin co san voi du lieu dau vao la filein de mo file
va mang 1 chieu voi kieu du lieu da duoc dinh nghia san, co y nghia lay thong tin tu file
co san de tai len chuong trinh. */
void Docfilesach(ifstream& filein, sach Sach[100]) {
	filein.open("Sach.txt", ios::in);
	if (filein.fail() == true) {
		cout << "Khong tim thay file" << endl;
	}
	else {
		int i = 0;
		while (filein.eof() == false) {
			getline(filein, Sach[i].ISBN, ';');
			getline(filein, Sach[i].tensach, ';');
			getline(filein, Sach[i].tacgia, ';');
			getline(filein, Sach[i].NXB, ';');
			getline(filein, Sach[i].namXB, ';');
			getline(filein, Sach[i].theloai, ';');
			getline(filein, Sach[i].giasach, ';');
			getline(filein, Sach[i].soluong);
			i++;
		}
		filein.close();
	}
}
/*Ham nay dung de doc thong tin tu tap tin co san voi du lieu dau vao la filein de mo file
va mang 1 chieu voi kieu du lieu da duoc dinh nghia san, co y nghia lay thong tin tu file
co san de tai len chuong trinh. */
void Docfilephieumuonsach(ifstream& filein, phieumuonsach phieumuonsach[100]) {
	filein.open("Phieumuonsach.txt", ios::in);
	if (filein.fail() == true) {
		cout << "Khong tim thay file" << endl;
	}
	else {
		int i = 0;
		while (filein.eof() == false) {
			getline(filein, phieumuonsach[i].madocgia, ';');
			getline(filein, phieumuonsach[i].ngaymuon, ';');
			getline(filein, phieumuonsach[i].ngaytradukien, ';');
			getline(filein, phieumuonsach[i].ISBN);
			i++;
		}
		filein.close();
	}
}
/*Ham nay dung de cap nhat thong tin tu chuong trinh tro lai file voi hai du lieu dau vao
la fileout de ghi du lieu va mang 1 chieu voi kieu du lieu duoc dinh nghia san, ham
nay co y nghia co the giup cap nhat thong tin vao tap tin sau moi lan xu ly cac
tac vu tren chuong trinh, cac thong tin tren chuong trinh thay doi thi deu duoc luu lai tren tap tin .*/
void Capnhatfilephieumuonsach(ofstream& fileout, phieumuonsach phieumuonsach[100]) {
	fileout.open("Phieumuonsach.txt", ios::trunc);
	if (fileout.fail() == true) {
		cout << "Khong tim thay file \n";
	}
	else {
		for (int i = 0; i < 100; i++) {
			if (phieumuonsach[i].madocgia == "") continue;
			fileout << phieumuonsach[i].madocgia << ";";
			fileout << phieumuonsach[i].ngaymuon << ";";
			fileout << phieumuonsach[i].ngaytradukien << ";";
			fileout << phieumuonsach[i].ISBN << endl;
		}
	}
	fileout.close();
}
/*Ham nay dung de doc thong tin tu tap tin co san voi du lieu dau vao la filein de mo file
va mang 1 chieu voi kieu du lieu da duoc dinh nghia san, co y nghia lay thong tin tu file
co san de tai len chuong trinh. */
void Docfilephieutrasach(ifstream& filein, phieutrasach phieutrasach[100]) {
	filein.open("Phieutrasach.txt", ios::in);
	if (filein.fail() == true) {
		cout << "Khong tim thay file" << endl;
	}
	else {
		int i = 0;
		while (filein.eof() == false) {
			getline(filein, phieutrasach[i].madocgia, ';');
			getline(filein, phieutrasach[i].ngaymuon, ';');
			getline(filein, phieutrasach[i].ngaytradukien, ';');
			getline(filein, phieutrasach[i].ngaytrathucte, ';');
			getline(filein, phieutrasach[i].ISBN);
			i++;
		}
		filein.close();
	}
}
/*Ham nay dung de cap nhat thong tin tu chuong trinh tro lai file voi hai du lieu dau vao
la fileout de ghi du lieu va mang 1 chieu voi kieu du lieu duoc dinh nghia san, ham
nay co y nghia co the giup cap nhat thong tin vao tap tin sau moi lan xu ly cac
tac vu tren chuong trinh, cac thong tin tren chuong trinh thay doi thi deu duoc luu lai tren tap tin .*/
void Capnhatfilephieutrasach(ofstream& fileout, phieutrasach phieutrasach[100]) {
	fileout.open("Phieutrasach.txt", ios::trunc);
	if (fileout.fail() == true) {
		cout << "Khong tim thay file \n";
	}
	else {
		for (int i = 0; i < 100; i++) {
			if (phieutrasach[i].madocgia == "") continue;
			fileout << phieutrasach[i].madocgia << ";";
			fileout << phieutrasach[i].ngaymuon << ";";
			fileout << phieutrasach[i].ngaytradukien << ";";
			fileout << phieutrasach[i].ngaytrathucte << ";";
			fileout << phieutrasach[i].ISBN << endl;
		}
	}
	fileout.close();
}
/* Ham nay de in ra thong doc gia va can chinh cac ky tu xuat hien tren man hinh de tao thanh danh sach thong tin doc gia, 
thong tin dau vao la kieu ky tu cua mang 2 chieu luu danh sach doc gia, co y nghia dua ra cai nhin truc quan cho nguoi quan ly
de de dang quan ly tat ca thong tin doc gia.*/
void Inradanhsachdocgia(ifstream &filein,docgia Docgia[100]) {
	Docfiledocgia(filein, Docgia);
	cout << setfill('-');
	cout << setw(174) << "-" << endl;
	cout << setfill(' ');
	cout << setw(20) << left << "Ma doc gia";
	cout << setw(25) << left << "Ho ten";
	cout << setw(15) << left << "CMND";
	cout << setw(12) << left << "Ngay sinh";
	cout << setw(12) << left << "Gioi tinh";
	cout << setw(30) << left << "Email";
	cout << setw(30) << left << "Dia chi";
	cout << setw(15) << left << "Ngay lap the";
	cout << setw(15) << left << "Ngay het han" << endl;
	cout << setfill('-');
	cout << setw(174) << "-" << endl;
	cout << setfill(' ');
	for (int i = 0; i < 100; i++) {
		if (Docgia[i].madocgia == "") continue;
		cout << setw(20) << left << Docgia[i].madocgia;
		cout << setw(25) << left << Docgia[i].hoten;
		cout << setw(15) << left << Docgia[i].cmnd;
		cout << setw(12) << left << Docgia[i].ngaysinh;
		cout << setw(12) << left << Docgia[i].gioitinh;
		cout << setw(30) << left << Docgia[i].email;
		cout << setw(30) << left << Docgia[i].diachi;
		cout << setw(15) << left << Docgia[i].ngaylapthe;
		cout << setw(15) << left << Docgia[i].ngayhethan << endl;
	}
	cout << setfill('-');
	cout << setw(174) << "-" << endl;
	cout << setfill(' ');
}
/* Ham nay dung de them doc gia vao mang 2 chieu da tao san, thong tin dau vao la mang 2 chieu kieu ky tu chua thong tin doc gia,
them doc gia o phan ngay sinh phai dien duoi dang dd//mm//yyyy de ham co the hoat dong binh thuong,
ham nay co y nghia de doc gia dang ky de thuc hien cac tuong tac lien quan den thu vien*/
void Themdocgia(ofstream& fileout,docgia Docgia[100]) {
	fileout.open("Docgia.txt", ios::app);
	for (int i = 0; i < 100; i++) {
		if (Docgia[i].madocgia != "") continue;
		cout << "Nhap ma doc gia:" << endl;
		cin.ignore(32767, '\n');
		getline(cin, Docgia[i].madocgia);
		fileout << Docgia[i].madocgia << ";";
		cout << "Ho ten:" << endl;
		getline(cin, Docgia[i].hoten);
		fileout << Docgia[i].hoten << ";";
		cout << "CMND:" << endl;
		getline(cin, Docgia[i].cmnd);
		fileout << Docgia[i].cmnd << ";";
		cout << "Ngay sinh:" << endl;
		getline(cin, Docgia[i].ngaysinh);
		fileout << Docgia[i].ngaysinh << ";";
		cout << "Gioi tinh:" << endl;
		getline(cin, Docgia[i].gioitinh);
		fileout << Docgia[i].gioitinh << ";";
		cout << "Email:" << endl;
		getline(cin, Docgia[i].email);
		fileout << Docgia[i].email << ";";
		cout << "Dia chi:" << endl;
		getline(cin, Docgia[i].diachi);
		fileout << Docgia[i].diachi << ";";
		cout << "Ngay lap the:" << endl;
		getline(cin, Docgia[i].ngaylapthe);
		fileout << Docgia[i].ngaylapthe << ";";
		cout << "Ngay het han:"<<endl;
		cout<< Ngayhethan(Docgia[i].ngaylapthe)<<endl;
		Docgia[i].ngayhethan = Ngayhethan(Docgia[i].ngaylapthe);
		fileout << Docgia[i].ngayhethan << endl;
		cout << "Ban co muon nhap them?(Chon 1 de nhap them hoac 2 de thoat)";
		int t;
		cin >> t;
		if (t == 2) break;
		if (t == 1) continue;
		if (t != 1 && t != 2) {
			cout << "Ban da nhap sai chuc nang" << endl;
			break;
		}
	}
	fileout.close();
}
/* Ham nay dung de tim va in ra man hinh doc gia theo du lieu dau vao la CMND cua doc gia ay,
thong tin dau vao la mang 2 chieu chua thong tin tat ca doc gia va CMND da nhap tu ban phim,
ham nay co y nghia in ra thong tin nhanh chong theo CMND da nhap, tiet kiem thoi gian va thuan tien
*/
void timdanhsachtheocmnd(docgia Docgia[100], string CMND, ifstream &filein) {
	int t=-1;
		for (int i = 0; i < 100; i++) {
			if (CMND == Docgia[i].cmnd) {
				t = i;
			}
		}
			cout << setfill('-');
			cout << setw(174) << "-" << endl;
			cout << setfill(' ');
			cout << setw(20) << left << "Ma doc gia";
			cout << setw(25) << left << "Ho ten";
			cout << setw(15) << left << "CMND";
			cout << setw(12) << left << "Ngay sinh";
			cout << setw(12) << left << "Gioi tinh";
			cout << setw(30) << left << "Email";
			cout << setw(30) << left << "Dia chi";
			cout << setw(15) << left << "Ngay lap the";
			cout << setw(15) << left << "Ngay het han" << endl;
			cout << setfill('-');
			cout << setw(174) << "-" << endl;
			cout << setfill(' ');
			if (t >= 0) {
			cout << setw(20) << left << Docgia[t].madocgia;
			cout << setw(25) << left << Docgia[t].hoten;
			cout << setw(15) << left << Docgia[t].cmnd;
			cout << setw(12) << left << Docgia[t].ngaysinh;
			cout << setw(12) << left << Docgia[t].gioitinh;
			cout << setw(30) << left << Docgia[t].email;
			cout << setw(30) << left << Docgia[t].diachi;
			cout << setw(15) << left << Docgia[t].ngaylapthe;
			cout << setw(15) << left << Docgia[t].ngayhethan << endl;
			}
			else cout << "Khong tim thay CMND"<<endl;
			cout << setfill('-');
			cout << setw(174) << "-" << endl;
			cout << setfill(' ');
	
};
/* Ham nay dung de tim va in ra man hinh doc gia theo du lieu dau vao la ho cua doc gia ay,
thong tin dau vao la mang 2 chieu chua thong tin tat ca doc gia va ho ten da nhap tu ban phim, 
chi can nhap dung mot phan cua ho ten van co the tim ra danh sach lien quan, ham nay co y nghia
tim thong tin doc gia theo ho ten chinh xac de xem cac thong tin lien quan */
void Timdanhsachtheohoten(docgia Docgia[100], string hoten) {
	cout << setfill('-');
	cout << setw(174) << "-" << endl;
	cout << setfill(' ');
	cout << setw(20) << left << "Ma doc gia";
	cout << setw(25) << left << "Ho ten";
	cout << setw(15) << left << "CMND";
	cout << setw(12) << left << "Ngay sinh";
	cout << setw(12) << left << "Gioi tinh";
	cout << setw(30) << left << "Email";
	cout << setw(30) << left << "Dia chi";
	cout << setw(15) << left << "Ngay lap the";
	cout << setw(15) << left << "Ngay het han" << endl;
	cout << setfill('-');
	cout << setw(174)<< "-" << endl;
	cout << setfill(' ');
	for (int i = 0; i < 100; i++) {
		if (Docgia[i].madocgia == "") continue;
		if ((int)(Docgia[i].hoten).find(hoten) >= 0) {
				cout << setw(20) << left << Docgia[i].madocgia;
				cout << setw(25) << left << Docgia[i].hoten;
				cout << setw(15) << left << Docgia[i].cmnd;
				cout << setw(12) << left << Docgia[i].ngaysinh;
				cout << setw(12) << left << Docgia[i].gioitinh;
				cout << setw(30) << left << Docgia[i].email;
				cout << setw(30) << left << Docgia[i].diachi;
				cout << setw(15) << left << Docgia[i].ngaylapthe;
				cout << setw(15) << left << Docgia[i].ngayhethan << endl;
			}
		}
	cout << setfill('-');
	cout << setw(174) << "-" << endl;
	cout << setfill(' ');
};
/*Ham nay dung de chinh sua thong tin doc gia co san trong mang 1 chieu luu thong tin cua doc gia,
thong tin dau vao la mang 1 chieu chua toan bo thong tin cua tat ca doc gia va ma doc gia duoc nhap tu ban phim,
ham nay co y nghia de nguoi doc gia co the chinh sua thong tin cua minh khi nhap sai du lieu luc dang ky */
void Chinhsuathongtindocgia(docgia Docgia[100], string madocgia, ifstream &filein, ofstream& fileout) {
	int i=-1;
	for (int j = 0; j < 100; j++) {
		if (Docgia[j].madocgia == madocgia) i = j;
		}
	if (i != -1) {
		cout << "Thong tin chinh sua:"<<endl;
		cout << "Nhap ma doc gia:" << endl;
		getline(cin, Docgia[i].madocgia);
		cout << "Ho ten:" << endl;
		getline(cin, Docgia[i].hoten);
		cout << "CMND:" << endl;
		getline(cin, Docgia[i].cmnd);
		cout << "Ngay sinh:" << endl;
		getline(cin, Docgia[i].ngaysinh);
		cout << "Gioi tinh:" << endl;
		getline(cin, Docgia[i].gioitinh);
		cout << "Email:" << endl;
		getline(cin, Docgia[i].email);
		cout << "Dia chi:" << endl;
		getline(cin, Docgia[i].diachi);
		cout << "Ngay lap the:" << endl;
		getline(cin, Docgia[i].ngaylapthe);
		Docgia[i].ngayhethan = Ngayhethan(Docgia[i].ngaylapthe);
		cout << "Da chinh sua thanh cong"<<endl;
		Capnhatfiledocgia(fileout, Docgia);
	}
	else cout << "Ma doc gia ban nhap khong ton tai";
};
/* Ham nay dung de in ra danh sach cac sach co san trong thu vien va can chinh thong tin de in ra man hinh 
voi dang bang danh sach, thong tin dau vao la danh sach sach luu cac thong tin sach duoi dang kieu ky tu 
va filein de doc du lieu tu tap tin, ham nay co y nghia lam cho nguoi quan ly 
co cai nhin tong quan ve tat ca cac sach co trong thu vien */
void Inradanhsachsach(sach Sach[100], ifstream &filein) {
	cout << setfill('-');
	cout << setw(174) << "-" << endl;
	cout << setfill(' ');
	cout << setw(18) << left << "ISBN";
	cout << setw(45) << left << "Ten sach";
	cout << setw(25) << left << "Ten tac gia";
	cout << setw(25) << left << "Nha xuat ban";
	cout << setw(15) << left << "Nam xuat ban";
	cout << setw(14) << left << "The loai";
	cout << setw(12) << left << "Gia sach";
	cout << setw(20) << left << "So quyen sach";
	cout << endl;
	cout << setfill('-');
	cout << setw(174) << "-" << endl;
	cout << setfill(' ');
	for (int i = 0; i < 100; i++) {
		if (Sach[i].ISBN == "") continue;
		cout << setw(18) << left << Sach[i].ISBN;
		cout << setw(45) << left << Sach[i].tensach;
		cout << setw(25) << left << Sach[i].tacgia;
		cout << setw(25) << left << Sach[i].NXB;
		cout << setw(15) << left << Sach[i].namXB;
		cout << setw(14) << left << Sach[i].theloai;
		cout << setw(12) << left << Sach[i].giasach;
		cout << setw(20) << left << Sach[i].soluong;
		cout << endl;
	}
	cout << setfill('-');
	cout << setw(174) << "-" << endl;
	cout << setfill(' ');
}
/* Ham nay dung de them sach khi nhap sach ve danh cho nguoi quan ly thu vien, thong tin dau vao
la danh sach sach mang 1 chieu luu cac thong tin ve sach co trong thu vien va fileout de cap nhat du lieu vao tap tin,
ham nay co y nghia giup cho nguoi quan ly thu vien co the lam da dang sach co trong thu vien. */
void Themsach(sach Sach[100], ofstream &fileout) {
	for (int i = 0; i < 100; i++) {
		if (Sach[i].ISBN != "") continue;
		cin.ignore(32767, '\n');
		cout << "Nhap ISBN:" << endl;
		getline(cin, Sach[i].ISBN);
		cout << "Ten sach:" << endl;
		getline(cin, Sach[i].tensach);
		cout << "Tac gia:" << endl;
		getline(cin, Sach[i].tacgia);
		cout << "Nha xuat ban:" << endl;
		getline(cin, Sach[i].NXB);
		cout << "Nam xuat ban:" << endl;
		getline(cin, Sach[i].namXB);
		cout << "The loai:" << endl;
		getline(cin, Sach[i].theloai);
		cout << "Gia sach:" << endl;
		getline(cin, Sach[i].giasach);
		cout << "So quyen sach:" << endl;
		getline(cin, Sach[i].soluong);
		cout << "Ban co muon nhap them?(Chon 1 de nhap them hoac 2 de thoat)";
		int f;
		cin >> f;
		if (f == 2) break;
		if (f == 1) continue;
		if (f != 1 && f != 2) {
			cout << "Ban da nhap sai chuc nang" << endl;
			break;
		}
	}
	Capnhatfilesach(fileout, Sach);
};
/* Ham nay dung de chinh sua thong tin cac quyen sach da co san trong thu vien, 
thong tin dau vao la danh sach sach, ma ISBN cua quyen sach can chinh sua va fileout de cap nhat thong tin vao tap tin,
ham co y nghia giup cho nguoi quan ly thu vien co the dieu chinh thong tin cua cac sach co san trong thu vien. */
void Chinhsuathongtin1quyensach(sach Sach[100], string ISBN, ofstream &fileout) {
	int i = -1;
	for (int j = 0; j < 100; j++) {
		if (Sach[j].ISBN == ISBN) i = j;
	}
	if (i != -1) {
		cout << "Thong tin chinh sua:" << endl;
		cout << "Nhap ISBN:" << endl;
		getline(cin, Sach[i].ISBN);
		cout << "Ten sach:" << endl;
		getline(cin, Sach[i].tensach);
		cout << "Tac gia:" << endl;
		getline(cin, Sach[i].tacgia);
		cout << "Nha xuat ban:" << endl;
		getline(cin, Sach[i].NXB);
		cout << "Nam xuat ban:" << endl;
		getline(cin, Sach[i].namXB);
		cout << "The loai:" << endl;
		getline(cin, Sach[i].theloai);
		cout << "Gia sach:" << endl;
		getline(cin, Sach[i].giasach);
		cout << "So quyen sach:" << endl;
		getline(cin, Sach[i].soluong);
		cout << "Da chinh sua thanh cong" << endl;
		Capnhatfilesach(fileout, Sach);
	}
	else cout << "Ma sach ban nhap khong ton tai";
};
/* Ham nay dung de tim kiem sach bang ISBN da biet, thong tin dau vao la danh sach sach
da co san trong thu vien va ma ISBN duoc nhap, ham nay co y nghia tim kiem sach theo thong tin 
co san nhanh chong va tien loi. */
void TimkiemsachtheoISBN(sach Sach[100], string ISBN) {
		cout << setfill('-');
		cout << setw(174) << "-" << endl;
		cout << setfill(' ');
		cout << setw(18) << left << "ISBN";
		cout << setw(45) << left << "Ten sach";
		cout << setw(25) << left << "Ten tac gia";
		cout << setw(25) << left << "Nha xuat ban";
		cout << setw(15) << left << "Nam xuat ban";
		cout << setw(14) << left << "The loai";
		cout << setw(12) << left << "Gia sach";
		cout << setw(20) << left << "So quyen sach";
		cout << endl;
		cout << setfill('-');
		cout << setw(174) << "-" << endl;
		cout << setfill(' ');
		for (int i = 0; i < 100; i++) {
			if ((int)Sach[i].ISBN.find(ISBN) >= 0) {
				cout << setw(18) << left << Sach[i].ISBN;
				cout << setw(45) << left << Sach[i].tensach;
				cout << setw(25) << left << Sach[i].tacgia;
				cout << setw(25) << left << Sach[i].NXB;
				cout << setw(15) << left << Sach[i].namXB;
				cout << setw(14) << left << Sach[i].theloai;
				cout << setw(12) << left << Sach[i].giasach;
				cout << setw(20) << left << Sach[i].soluong;
				cout << endl;
			}
		}
		cout << setfill('-');
		cout << setw(174) << "-" << endl;
		cout << setfill(' ');

}
/* Ham nay dung de tim kiem sach bang ten sach da biet, thong tin dau vao la danh sach sach
da co san trong thu vien va ten sach duoc nhap, ham nay co y nghia tim kiem sach theo thong tin
co san nhanh chong va tien loi. */
void Timkiemdanhsachtheotensach(sach Sach[100], string tensach) {
	cout << setfill('-');
	cout << setw(174) << "-" << endl;
	cout << setfill(' ');
	cout << setw(18) << left << "ISBN";
	cout << setw(45) << left << "Ten sach";
	cout << setw(25) << left << "Ten tac gia";
	cout << setw(25) << left << "Nha xuat ban";
	cout << setw(15) << left << "Nam xuat ban";
	cout << setw(14) << left << "The loai";
	cout << setw(12) << left << "Gia sach";
	cout << setw(20) << left << "So quyen sach";
	cout << endl;
	cout << setfill('-');
	cout << setw(174) << "-" << endl;
	cout << setfill(' ');
	for (int i = 0; i < 100; i++) {
		if ((int)Sach[i].tensach.find(tensach) >= 0) {
			cout << setw(18) << left << Sach[i].ISBN;
			cout << setw(45) << left << Sach[i].tensach;
			cout << setw(25) << left << Sach[i].tacgia;
			cout << setw(25) << left << Sach[i].NXB;
			cout << setw(15) << left << Sach[i].namXB;
			cout << setw(14) << left << Sach[i].theloai;
			cout << setw(12) << left << Sach[i].giasach;
			cout << setw(20) << left << Sach[i].soluong;
			cout << endl;
		}
	}
	cout << setfill('-');
	cout << setw(174) << "-" << endl;	
	cout << setfill(' ');
}
/* Ham nay dung de tinh so ngay tre han cua 2 moc thoi gian, thong tin dau vao la 2 moc thoi gian,
ham nay se phan tach du lieu tu kieu string de lay ra cac thong tin can thiet va tinh duoc so ngay chenh lech giua
hai moc thoi gian, ham nay co y nghia tinh ngay tre han cua doc gia hoac su chenh lech ngay giua hai moc thoi gian kieu string
theo dinh dang da cho. */
int Trehan(string a, string b) {

	string day1 = "";
	string month1 = "";
	string year1 = "";
	day1.append(a, 0, 2);
	stringstream str1(day1);
	int ngay1 = 0;
	str1 >> ngay1;
	month1.append(a, 3, 4);
	stringstream str2(month1);
	int thang1 = 0;
	str2 >> thang1;
	year1.append(a, 6, 10);
	stringstream str3(year1);
	int nam1 = 0;
	str3 >> nam1;
	string day2 = "";
	string month2 = "";
	string year2 = "";
	day2.append(b, 0, 2);
	stringstream str4(day2);
	int ngay2 = 0;
	str4 >> ngay2;
	month2.append(b, 3, 4);
	stringstream str5(month2);
	int thang2 = 0;
	str5 >> thang2;
	year2.append(b, 6, 10);
	stringstream str6(year2);
	int nam2 = 0;
	str6 >> nam2;
	int ngaytrehan = thutungay(nam2, thang2, ngay2) - thutungay(nam1, thang1, ngay1) - 7;
	if (ngaytrehan <= 0) return 0;
	else return ngaytrehan;
}
/* Ham nay dung de tao ra cac phieu muon sach cho doc gia, thong tin dau vao la mang 1 chieu de luu phieu muon sach,
danh sach doc gia, danh sach sach va thoi gian ngay hom nay, ham nay co y nghia giup doc gia co the dang ky muon sach tu thu vien,
ham nay co bao gom kiem tra ngay het han cua phieu doc gia, neu het han thi khong the dang ky muon sach. */
void hamphieumuonsach(phieumuonsach phieumuonsach[100], sach Sach[100], docgia Docgia[100], string ngayhomnay) {
	int l = 1;
	int g = 0;
	cout << setfill('-');
	cout << setw(79) << "-";
	cout << "Phieu muon sach";
	cout << setw(79) << "-" << endl;
	cout << setfill(' ');
	for (int i = 0; i < 100; i++) {
		if (phieumuonsach[i].madocgia != "") continue;
		int t = -1;
		cout << "Nhap ma doc gia:" << endl;
		cin.ignore(32767, '\n');
		getline(cin, phieumuonsach[i].madocgia);
		for (int j = 0; j < 100; j++) {
			if (phieumuonsach[i].madocgia == Docgia[j].madocgia && Trehan(ngayhomnay,Docgia[j].ngayhethan)>=0) {
				t = 1;
				break;
			}
			if (j == 99) {
				cout << "Ma doc gia khong ton tai hoac da het han.";
				t = 5;
				phieumuonsach[i].madocgia = "";
			}
		}
		if (t != 5) {
			cout << "Ngay muon:" << endl;
			getline(cin, phieumuonsach[i].ngaymuon);
			cout << "Ngay tra du kien:" << endl;
			getline(cin, phieumuonsach[i].ngaytradukien);
			cout << "Danh sach ISBN cua cac sach duoc muon:" << endl;
			for (int f = 0; f < 100; f++) {
				if (Sach[f].ISBN == "") continue;
				stringstream str2(Sach[f].soluong);
				int x = 0;
				str2 >> x;
				if (x > 0) {
					cout << l << "." << Sach[f].ISBN << endl;
					l++;
				}
			}
			cout << "Chon ISBN can muon:" << endl;
			getline(cin, phieumuonsach[i].ISBN);
			
			for (int z = 0; z < 100; z++) {
				if (phieumuonsach[i].ISBN == Sach[z].ISBN) g = 1;
			}
			if (g == 1) {
				cout << "Ban da lap phieu muon sach thanh cong" << endl;
				Capnhatsoluongmuonsach(Sach, phieumuonsach);
			}
			else {
				cout << "Ban da nhap sai ma ISBN, lap phieu muon sach that bai"<<endl;
				phieumuonsach[i].madocgia = "";
				phieumuonsach[i].ngaymuon = "";
				phieumuonsach[i].ngaytradukien = "";
				phieumuonsach[i].ISBN = "";
			}
			

		}
		cout << "Nhap so 1 de tao them phieu muon sach hoac so 2 de thoat khoi chuc nang" << endl;
		int e;
		cin >> e;
		if (e == 1) continue;
		else break;
	}
	cout << setfill('-');
	cout << setw(174) << "-" << endl;
	cout << setfill(' ');
}
/* Ham nay dung de tao ra cac phieu tra sach cho doc gia, thong tin dau vao la
danh sach sach, phieu muon sach va phieu tra sach, ham nay co y nghia giup cho doc gia tra lai nhung quyen sach da muon
tu thu vien va dong tien nop phat neu tra khong dung thoi han hoac lam mat sach. */
void trasach(sach Sach[100],phieumuonsach phieumuonsach[100],phieutrasach phieutrasach[100]) {
	cout << setfill('-');
	cout << setw(79) << "-";
	cout << "Phieu tra sach";
	cout << setw(79) << "-" << endl;
	cout << setfill(' ');
	for (int i = 0; i < 100; i++) {
			if (phieutrasach[i].madocgia != "") continue;
			int t = -1;
			cout << "Nhap ma doc gia:" << endl;
			cin.ignore(32767, '\n');
			getline(cin, phieutrasach[i].madocgia);
			for (int j = 0; j < 100; j++) {
				if (phieutrasach[i].madocgia == phieumuonsach[j].madocgia) {
					t = 1;
					break;
				}
				if (j == 99) {
					cout << "Ma doc gia khong ton tai.";
					t = 5;
					phieutrasach[i].madocgia = "";
				}
			}
			if (t != 5) {
				int z;
				cout << "Ban co lam mat sach hay khong? Chon 1 neu da mat sach va 0 neu khong mat sach: ";
				cin >> z;
				if (z == 0) {
					cout << "Ngay muon:" << endl;
					cin.ignore(32767, '\n');
					getline(cin, phieutrasach[i].ngaymuon);
					cout << "Ngay tra du kien: " << endl;
					getline(cin, phieutrasach[i].ngaytradukien);
					cout << "Ngay tra thuc te: "<<endl;
					getline(cin, phieutrasach[i].ngaytrathucte);
					cout << "Nhap ma ISBN cua sach da muon"<<endl;
					getline(cin, phieutrasach[i].ISBN);
					cout << "Tien phat: ";
					cout << Trehan(phieutrasach[i].ngaymuon, phieutrasach[i].ngaytrathucte)*5000<<endl;
					Capnhatsoluongtrasach(Sach,phieutrasach);
					for (int e = 0; e < 100; e++) {
						if (phieutrasach[i].ISBN == phieumuonsach[e].ISBN && phieutrasach[i].madocgia==phieumuonsach[e].madocgia) {
							phieumuonsach[e].madocgia = "";
							phieumuonsach[e].ngaymuon = "";
							phieumuonsach[e].ngaytradukien = "";
							phieumuonsach[e].ISBN = "";
						}
					}
				}
				else {
					cout << "Nhap ma ISBN cua sach da muon"<<endl;
					cin.ignore(32767, '\n');
					getline(cin, phieutrasach[i].ISBN);
					cout << "So tien phai tra: "<< phatmatsach(phieutrasach[i].ISBN, Sach)<<endl;
					
					for (int e = 0; e < 100; e++) {
						if (phieutrasach[i].ISBN == phieumuonsach[e].ISBN && phieutrasach[i].madocgia == phieumuonsach[e].madocgia) {
							phieumuonsach[e].madocgia = "";
							phieumuonsach[e].ngaymuon = "";
							phieumuonsach[e].ngaytradukien = "";
							phieumuonsach[e].ISBN = "";
						}
					}
				}
			}
			cout << "Nhap so 1 de tao them phieu muon sach hoac so 2 de thoat khoi chuc nang" << endl;
			int e;
			cin >> e;
			if (e == 1) continue;
			else break;
		}
	cout << setfill('-');
	cout << setw(173) << "-" << endl;
	cout << setfill(' ');
	
}
/* Ham nay dung de thong ke so luong sach co san trong thu vien, kiem tra so luong 
quyen sach cua tung sach neu >0 thi +1 va cuoi cung xuat ra so luong sach co san trong thu vien,
thong tin dau vao la danh sach sach, ham nay co y nghia cho nguoi quan ly thay duoc so luong sach
con trong thu vien. */
void Thongkesoluongsachcotrongthuvien(sach Sach[100]) {
	int count = 0;
	for (int i = 0; i < 100; i++) {
		if (Sach[i].ISBN == "") continue;
		stringstream str2(Sach[i].soluong);
		int x = 0;
		str2 >> x;
		if (x > 0) {
			count++;
		}
	}
	cout << "So luong sach co trong thu vien: " << count << endl;	
}
/* Ham nay dung de thong ke danh sach sach co san trong thu vien theo the loai, sau khi chon mot the loai thi
se xuat ra thong tin cua cac quyen sach co trong theo the loai da nhap, thong tin dau vao la danh sach sach va
the loai duoc nhap, ham nay co y nghia cho nguoi doc co the xem cac sach co the loai ma minh yeu thich. */
void Thongkesoluongsachtheotheloai(sach Sach[100], string theloai) {
	cout << setfill('-');
	cout << setw(174) << "-" << endl;
	cout << setfill(' ');
	cout << setw(18) << left << "ISBN";
	cout << setw(45) << left << "Ten sach";
	cout << setw(25) << left << "Ten tac gia";
	cout << setw(25) << left << "Nha xuat ban";
	cout << setw(15) << left << "Nam xuat ban";
	cout << setw(14) << left << "The loai";
	cout << setw(12) << left << "Gia sach";
	cout << setw(20) << left << "So quyen sach";
	cout << endl;
	cout << setfill('-');
	cout << setw(174) << "-" << endl;
	cout << setfill(' ');
	for (int i = 0; i < 100; i++) {
		if (Sach[i].ISBN == "") continue;
		if (Sach[i].theloai == theloai) {
			cout << setw(18) << left << Sach[i].ISBN;
			cout << setw(45) << left << Sach[i].tensach;
			cout << setw(25) << left << Sach[i].tacgia;
			cout << setw(25) << left << Sach[i].NXB;
			cout << setw(15) << left << Sach[i].namXB;
			cout << setw(14) << left << Sach[i].theloai;
			cout << setw(12) << left << Sach[i].giasach;
			cout << setw(20) << left << Sach[i].soluong;
			cout << endl;
		}
	}
	cout << setfill('-');
	cout << setw(174) << "-" << endl;
	cout << setfill(' ');
};
/* Ham nay dung de thong ke so luong sach co san trong thu vien theo the loai, thong tin dau vao
la danh sach sach, danh sach the loai de luu cac the loai va so luong the loai de luu so luong the loai tuong ung
ham nay co y nghia giup cho nguoi doc gia hay quan ly co the thay duoc so luong sach co voi tung the loai khac nhau . */
void Inradanhsachcactheloaisach(sach Sach[100], string dstheloai[100], int soluongtheloai[100]) {
	int c = 1;
	dstheloai[0] = Sach[0].theloai;
	for (int i = 1; i < 100; i++) {
		int t = 0;
		for (int j = 0; j < i; j++) {
			if (Sach[i].theloai == dstheloai[j]) t=1;
		}
		if (t == 0) {
			dstheloai[c] = Sach[i].theloai;
			c++;
		}
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (Sach[j].theloai == dstheloai[i]) soluongtheloai[i]++;
		}
	}
	cout << "Cac the loai: " << endl;
	for (int i = 0; i < c; i++) {
		if(dstheloai[i] !="")	cout << i + 1 << "." << dstheloai[i] << ". So luong: " << soluongtheloai[i] << endl;
	}
}
/* Ham nay dung de thong ke so luong doc gia, thong tin dau vao la danh sach doc gia da co san, 
ham nay co y nghia giup cho nguoi quan ly xem duoc so luong doc gia dang co trong thu vien. */
int Thongkesoluongdocgia(docgia Docgia[100]) {
	int count = 0;
	for (int i = 0; i < 100; i++) {
		if (Docgia[i].madocgia != "") count++;
	}
	return count;
}
/* Ham nay dung de thong ke so luong doc gia theo gioi tinh, thong tin dau vao la danh sach doc gia da co san,
ham nay co y nghia giup cho nguoi quan ly xem duoc so luong doc gia dang co trong thu vien theo cac gioi tinh khac nhau. */
void Thongkesoluongdocgiatheogioitinh(docgia Docgia[100]) {
	int count = 0;
	int nam = 0;
	int nu = 0;
	for (int i = 0; i < 100; i++) {
		if (Docgia[i].gioitinh == "Nam" || Docgia[i].gioitinh == "nam" || Docgia[i].gioitinh == "Nam " || Docgia[i].gioitinh == "nam ") {
			nam++;
		}
		if (Docgia[i].gioitinh == "Nu" || Docgia[i].gioitinh == "nu" || Docgia[i].gioitinh == "Nu " || Docgia[i].gioitinh == "nu ") {
			nu++;
		}
	}
	cout << "1. So luong doc gia nu la: " << nu<<endl;
	cout << "2. So luong doc gia nam la: " << nam<<endl;
}
/* Ham nay dung de cap nhap so luong sach co trong thu vien moi khi doc gia muon sach, thong tin 
dau vao la danh sach sach va phieu muon sach de truy xuat duoc nhung cuon sach da muon hay da tra lai,..., ham nay
co y nghia cap nhat lai so luong sach cho chinh xac o tung thoi diem xac dinh. */
void Capnhatsoluongmuonsach(sach Sach[100], phieumuonsach phieumuonsach[100]) {
	int t = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (Sach[i].ISBN == phieumuonsach[j].ISBN) {
				stringstream str2(Sach[i].soluong);
				int x = 0;
				str2 >> x;
				x--;
				Sach[i].soluong = to_string(x);
			}
		}	
	}
}
/* Ham nay dung de cap nhap so luong sach co trong thu vien moi khi doc gia tra sach, thong tin
dau vao la danh sach sach va phieu muon sach de truy xuat duoc nhung cuon sach da muon hay da tra lai,..., ham nay
co y nghia cap nhat lai so luong sach cho chinh xac o tung thoi diem xac dinh. */
void Capnhatsoluongtrasach(sach Sach[100], phieutrasach phieutrasach[100]) {
	int t = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (Sach[i].ISBN == phieutrasach[j].ISBN) {
				stringstream str2(Sach[i].soluong);
				int x = 0;
				str2 >> x;
				x++;
				Sach[i].soluong = to_string(x);
			}
		}
	}
}
/* Ham nay dung de tinh thu tu ngay tinh tu ngay 01-01-0001, tu do co the dung cac ham khac de tinh do chenh lech giua cac moc thoi gian
thong tin dau vao la ngay thang nam can quy doi thanh thu tu, ham nay co y nghia tinh thu tu ngay tu moc thoi gian co dinh giup
tinh duoc do chenh lech ngay giua cac moc thoi gian. */
int thutungay(int nam, int thang, int ngay) {
	if (thang < 3) {
		nam--;
		thang = thang + 12;
	}
	return 365 * nam + nam / 4 - nam / 100 + nam / 400 + (153 * thang - 457) / 5 + ngay - 306;
}
/* Ham nay dung de tinh tien phat khi lam mat sach, chuyen doi du lieu tu kieu string sang dang int va thuc
hien cac thao tac tinh tien phat, du lieu dau vao la ISBN cua sach da muon va danh sach sach. */
int phatmatsach(string ISBN, sach Sach[100]) {
	for (int i = 0; i < 100; i++) {
		if (ISBN == Sach[i].ISBN) {
			stringstream str(Sach[i].giasach);
			int x = 0;
			str >> x;
			return x * 2;
		}
	}
}
/* Ham nay dung de thong ke so luong sach da duoc muon tu doc gia o thu vien, 
du lieu dau vao la phieu muon sach. */
int Thongkesosachdangduocmuon(phieumuonsach phieumuonsach[100]) {
	int count = 0;
	for (int i = 0; i < 100; i++) {
		if (phieumuonsach[i].madocgia != "") {
			count++;
		}
	}
	return count;
}
/* Ham nay dung de thong ke danh sach doc gia bi tre han bang cach tinh su chenh lech giua cac moc thoi gian 
de xuat ra man hinh cac doc gia tre han, du lieu dau vao la danh sach doc gia, phieu muon sach va thoi gian la ngay hom nay,
ham nay co y nghia thong ke duoc cac doc gia da tre han de thu vien co cac bien phap xu ly hay nhac nho,... */
void Danhsachdocgiatrehan(docgia Docgia[100], phieumuonsach phieumuonsach[100], string ngayhomnay) {
	cout << setfill('-');
	cout << setw(174) << "-" << endl;
	cout << setfill(' ');
	cout << setw(20) << left << "Ma doc gia";
	cout << setw(25) << left << "Ho ten";
	cout << setw(15) << left << "CMND";
	cout << setw(12) << left << "Ngay sinh";
	cout << setw(12) << left << "Gioi tinh";
	cout << setw(30) << left << "Email";
	cout << setw(30) << left << "Dia chi";
	cout << setw(15) << left << "Ngay lap the";
	cout << setw(15) << left << "Ngay het han" << endl;
	cout << setfill('-');
	cout << setw(174) << "-" << endl;
	cout << setfill(' ');
	for (int i = 0; i < 100; i++) {
		if (phieumuonsach[i].madocgia == "") continue;
		if (Trehan(phieumuonsach[i].ngaymuon, ngayhomnay) > 0) {
			for (int b = 0; b < 100; b++) {
				if (phieumuonsach[i].madocgia == Docgia[b].madocgia) {
					cout << setw(20) << left << Docgia[b].madocgia;
					cout << setw(25) << left << Docgia[b].hoten;
					cout << setw(15) << left << Docgia[b].cmnd;
					cout << setw(12) << left << Docgia[b].ngaysinh;
					cout << setw(12) << left << Docgia[b].gioitinh;
					cout << setw(30) << left << Docgia[b].email;
					cout << setw(30) << left << Docgia[b].diachi;
					cout << setw(15) << left << Docgia[b].ngaylapthe;
					cout << setw(15) << left << Docgia[b].ngayhethan << endl;
				}
			}
		}

	}
	cout << setfill('-');
	cout << setw(174) << "-" << endl;
	cout << setfill(' ');
	
}