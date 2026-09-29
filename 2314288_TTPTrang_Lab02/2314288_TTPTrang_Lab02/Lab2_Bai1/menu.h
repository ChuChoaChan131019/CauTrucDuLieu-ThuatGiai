
void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, NhanVien a[MAX], int& n);


void XuatMenu()
{
	cout << "========================================MENU========================================";
	cout << "\n0. Thoat chuong trinh";
	cout << "\n1. Tao danh sach nhan vien";
	cout << "\n2. Xem danh sach nhan vien";
	cout << "\n3. Tim kiem theo ho, ten - Xuat cac nhan vien trung ho va ten cho truoc";
	cout << "\n4. Tim kiem nam sinh - Xuat cac nhan vien cung nam sinh";
	cout << "\n5. Tim kiem theo ho, ten va nam sinh - Xuat cac nhan vien trung ho, ten cho truoc va co nam sinh < x";
	cout << "\n6. Tim kiem theo ten va dia chi - Xuat cac nhan vien cung ten va dia chi cho truoc";
	cout << "\n7. Tim kiem theo nam sinh va luong - Xuat cac nhan vien co muc luong >= x va co nam sinh <= y";
	cout << "\n8. Tim kiem nhi phan theo ma nhan vien cho truoc (can ktra tinh don dieu cua du lieu";
	cout << "\n====================================================================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap mot so [0..." << soMenu << "] de chon menu, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, NhanVien a[MAX], int& n)
{
	char filename[MAX];
	int kq;
	Name name;
	unsigned int namSinh, luong;
	const int namHienTai = 2024;
	string diaChi, maNV;

	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat chuong trinh";
		cout << endl;
		break;

	case 1:
		cout << "\n1. Tao danh sach nhan vien";
		do {
			cout << "\nNhap ten tap tin, filename = ";
			cin >> filename;
			kq = TapTin_MangCT(filename, a, n);
		} while (!kq);

		cout << "\nDanh sach nhan vien vua nhap: \n";
		XuatDSNV(a, n);
		cout << endl;
		break;

	case 2:
		cout << "\n2. Xem danh sach nhan vien";
		cout << "\nDanh sach nhan vien : \n";
		XuatDSNV(a, n);
		cout << endl;
		break;

	case 3:
		cout << "\n3. Tim kiem theo ho, ten - Xuat cac nhan vien trung ho va ten cho truoc";
		cout << "\nDanh sach nhan vien: \n";
		XuatDSNV(a, n);
		cout << "\nNhap ho nhan vien = ";
		cin >> name.ho;
		cout << "\nNhap ten nhan vien = ";
		cin >> name.ten;
		TimKiemTheoHoTen(a, n, name, 9999);
		cout << endl;
		break;

	case 4:
		cout << "\n4. Tim kiem nam sinh - Xuat cac nhan vien cung nam sinh";
		cout << "\nDanh sach nhan vien: \n";
		XuatDSNV(a, n);
		do
		{
			cout << "\nNhap nam sinh cua nhan vien: ";
			cin >> namSinh;
		} while (namSinh <= 0 || namSinh >= namHienTai || !namSinh);
		TimKiemTheoNamSinh(a, n, namSinh);
		cout << endl;
		break;

	case 5:
		cout << "\n5. Tim kiem theo ho, ten va nam sinh - Xuat cac nhan vien trung ho, ten cho truoc va co nam sinh < x";
		cout << "\nDanh sach nhan vien: \n";
		XuatDSNV(a, n);
		cout << "\nNhap ho nhan vien = ";
		cin >> name.ho;
		cout << "\nNhap ten nhan vien = ";
		cin >> name.ten;
		cout << "\nNhap nam sinh nhan vien = ";
		cin >> namSinh;
		TimKiemTheoHoTen(a, n, name, namSinh);
		cout << endl;
		break;

	case 6:
		cout << "\n6. Tim kiem theo ten va dia chi - Xuat cac nhan vien cung ten va dia chi cho truoc";
		cout << "\nDanh sach nhan vien: \n";
		XuatDSNV(a, n);
		cout << "\nNhap ten nhan vien = ";
		cin >> name.ten;
		cout << "\nNhap dia chi = ";
		cin >> diaChi;
		TimKiemTheoTenVaDiaChi(a, n, name, diaChi);
		cout << endl;
		break;

	case 7:
		cout << "\n7. Tim kiem theo nam sinh va luong - Xuat cac nhan vien co muc luong >= x va co nam sinh <= y";
		cout << "\nDanh sach nhan vien: \n";
		XuatDSNV(a, n);
		do
		{
			cout << "\nNhap nam sinh cua nhan vien: ";
			cin >> namSinh;
		} while (namSinh <= 0 || namSinh >= namHienTai || !namSinh);
		TimKiemTheoNamSinh(a, n, namSinh);

		do
		{
			cout << "\nNhap luong cua nhan vien: ";
			cin >> luong;
		} while (luong <= 0 || !luong);
		TimKiemTheoNamSinhVaLuong(a, n, namSinh, luong);
		cout << endl;
		break;

	case 8:
		cout << "\n8. Tim kiem nhi phan theo ma nhan vien cho truoc (can ktra tinh don dieu cua du lieu";
		SapXep(a, n);
		cout << "\nDanh sach nhan vien: \n";
		XuatDSNV(a, n);

		if (!isSorted(a, n)) {
			cout << "\nDanh sach nhan vien khong duoc sap xep! Vui long sap xep truoc khi tim kiem." << endl;
			break;
		}
		cout << "\nNhap ma nhan vien can tim: ";
		cin >> maNV;
		int index = TimKiemNhiPhan(a, n, maNV);
		if (index != -1)
		{
			cout << "Nhan vien tim thay: " << endl;
			XuatTieuDe();
			Xuat1NV(a[index]);
			XuatDongKe('=');
		}
		else
			cout << "Khong tim thay nhan vien co ma: " << maNV << endl;
		cout << endl;
		break;
	}
	(void)_getch();
}