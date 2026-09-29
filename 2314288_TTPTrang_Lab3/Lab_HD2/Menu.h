void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, sinhvien a[MAX], int& n);

void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu ";
	cout << "\n2. Xem du lieu";
	cout << "\n3. Sap tang danh sach voi QuickSort";
	cout << "\n4. Sap tang danh sach voi HeapSort";
	cout << "\n5. Sap tang danh sach voi MergeSort";
	cout << "\n==================================================";

}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\nNhap mot so (0 <= so <= " << soMenu << " ) de chon menu, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, sinhvien a[MAX], int& n)
{
	int kq;
	int i;
	char filename[MAX];
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Tao du lieu";
		do
		{
			cout << "\nNhap ten tap tin, filename = ";
			cin >> filename;
			kq = File_Array(filename, a, n);
		} while (!kq);
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xem du lieu";
		cout << "\nDanh sach mang vua nhap: ";
		Output_Arr(a, n);
		break;
	case 3:
		system("CLS");
		cout << "\n3. Sap tang danh sach voi QuickSort";
		QuickSort(a, n);
		cout << "\nDanh sach mang sau khi sap xep: ";
		Output_Arr(a, n);
		break;
	case 4:
		system("CLS");
		cout << "\n4. Sap tang danh sach voi HeapSort";
		HeapSort(a, n);
		cout << "\nDanh sach mang sau khi sap xep: ";
		Output_Arr(a, n);
		break;
	case 5:
		system("CLS");
		cout << "\n5. Sap tang danh sach voi MergeSort";
		MergeSort(a, n);
		cout << "\nDanh sach mang sau khi sap xep: ";
		Output_Arr(a, n);
		break;
	}
}