
void XuatMenu()
{
	cout << "\n========================== Menu ===========================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu ";
	cout << "\n2. Xem du lieu";
	cout << "\n3. Chon truc tiep - tai moi buoc dua GTNN ve dau mang";
	cout << "\n4. Chon truc tiep - tai moi buoc dua GTLN ve dau mang";
	cout << "\n5. Chon hai dau";
	cout << "\n6. Chen truc tiep - chen vao day con tang ben trai";
	cout << "\n7. Chen truc tiep - chen vao day con tang ben phai";
	cout << "\n8. Chen nhi phan";
	cout << "\n9. Doi cho Truc tiep - tai moi buoc dua GTNN ve dau mang";
	cout << "\n10. Doi cho Truc tiep - tai moi buoc dua GTLN ve cuoi mang";
	cout << "\n11. Noi bot - tai moi buoc dua GTNN ve dau mang";
	cout << "\n12. Noi bot - tai moi buoc dua GTLN ve cuoi mang";
	cout << "\n===========================================================";

}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\nNhap so menu (0 <= so <= " << soMenu << " ), stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, int a[MAX], int& n)
{
	int kq;
	char filename[MAX];
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Tao du lieu\n";
		do
		{
			cout << "\nNhap ten tap tin, filename = ";
			cin >> filename;
			kq = TaoFile(filename, a, n);
		} while (!kq);
		Xuat(a, n);
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xem du lieu";
		cout << "\nDah sach vua nhap la: \n";
		Xuat(a,n);
		break;
	case 3:
		system("CLS");
		cout << "\n3. Chon truc tiep - tai moi buoc dua GTNN ve dau mang";
		Xuat(a, n);
		cout << "\nCac buoc sap xep chon truc tiep dua GTNN ve dau mang:\n";
		ChonTT_GTNN(a, n);
		cout << "\nDanh sach sau khi xep la:\n";
		Xuat(a, n);
		break;
	case 4:
		system("CLS");
		cout << "\n4. Chon truc tiep - tai moi buoc dua GTLN ve dau mang";
		Xuat(a, n);
		break;
	case 5:
		system("CLS");
		cout << "\n5. Chon hai dau";
		Xuat(a, n);
		cout << "\nDanh sach sau khi xep la:\n";
		Chon2Dau(a, n);
		Xuat(a, n);
		break;
	case 6:
		system("CLS");
		cout << "\n6. Chen truc tiep - chen vao day con tang ben trai";
		Xuat(a, n);
		cout << "\nDanh sach sau khi xep la:\n";
		ChenTT_DayTang(a, n);
		Xuat(a, n);
		break;
	case 7:
		system("CLS");
		cout << "\n7. Chen truc tiep - chen vao day con tang ben phai";
		Xuat(a, n);
		cout << "\nDanh sach sau khi xep la:\n";
		ChenTT_DayGiam(a, n);
		Xuat(a, n);
		break;
	case 8:
		system("CLS");
		cout << "\n8. Chen nhi phan";
		break;
	case 9:
		system("CLS");
		cout << "\n9. Doi cho Truc tiep - tai moi buoc dua GTNN ve dau mang";
		Xuat(a, n);
		cout << "\nDanh sach sau khi xep la:\n";
		DoiChoTT_GTNN(a, n);
		Xuat(a, n);
		break;
	case 10:
		system("CLS");
		cout << "\n10. Doi cho Truc tiep - tai moi buoc dua GTLN ve cuoi mang";

		break;
	case 11:
		system("CLS");
		cout << "\n11. Noi bot - tai moi buoc dua GTNN ve dau mang";
		break;
	case 12:
		system("CLS");
		cout << "\n12. Noi bot - tai moi buoc dua GTLN ve cuoi mang";
		break;

	}
}