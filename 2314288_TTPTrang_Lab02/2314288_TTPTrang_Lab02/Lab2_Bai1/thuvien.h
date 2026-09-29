#define MAX 100

struct Date {
    unsigned int ngay = 0;
    unsigned int thang = 0;
    unsigned int nam = 0;
};

struct Name {
    string ho = "";
    string tenLot = "";
    string ten = "";
};

struct NhanVien {
    string maNV = "";
    Name name;
    Date date;
    string diaChi = "";
    unsigned int luong = 0;
};


int TapTin_MangCT(char* filename, NhanVien a[MAX], int& n);
void XuatDongKe(char kitu);
void XuatTieuDe();
void Xuat1NV(NhanVien nv);
void XuatDSNV(NhanVien a[MAX], int n);
void TimKiemTheoHoTen(NhanVien a[MAX], int n, Name name, unsigned int namSinh);
void TimKiemTheoNamSinh(NhanVien a[MAX], int n, unsigned int namSinh);
void TimKiemTheoTenVaDiaChi(NhanVien a[MAX], int n, Name name, string diaChi);
void TimKiemTheoNamSinhVaLuong(NhanVien a[MAX], int n, unsigned int namSinh, unsigned int luong);
bool isSorted(NhanVien a[MAX], int n);
void SapXep(NhanVien a[MAX], int n);
int TimKiemNhiPhan(NhanVien a[MAX], int n, string maNV);


int TapTin_MangCT(char* filename, NhanVien a[MAX], int& n)
{
    ifstream input(filename);
    if (!input)
    {
        cout << "\nLoi doc file! " << endl;
        return 0;
    }
    int i = 0;
    while (i < MAX &&
        input >> a[i].maNV
        >> a[i].name.ho
        >> a[i].name.tenLot
        >> a[i].name.ten
        >> a[i].date.ngay
        >> a[i].date.thang
        >> a[i].date.nam
        >> a[i].diaChi
        >> a[i].luong) {
        i++;
    }
    n = i;
    input.close();
    return 1;
}

void XuatDongKe(char kitu)
{
    const int chieuDai = 89;
    cout << '|';
    for (int i = 0; i < chieuDai; i++)
        cout << kitu;
    cout << '|' << endl;
}

void XuatTieuDe()
{
    XuatDongKe('=');
    cout << setiosflags(ios::left)
        << '|' << setw(10) << "Ma NV"
        << '|' << setw(11) << "Ho"
        << setw(11) << "tLot"
        << setw(11) << "Ten"
        << '|' << setw(13) << "NTN Sinh"
        << '|' << setw(16) << "Dia Chi"
        << '|' << setw(13) << "Luong";
    cout << '|' << endl;
    XuatDongKe('=');
}

void Xuat1NV(NhanVien nv)
{
    cout << setiosflags(ios::left)
        << '|' << setw(10) << nv.maNV
        << '|' << setw(11) << nv.name.ho
        << setw(11) << nv.name.tenLot
        << setw(11) << nv.name.ten
        << '|' << setw(2) << nv.date.ngay
        << '/' << setw(2) << nv.date.thang
        << '/' << setw(7) << nv.date.nam
        << '|' << setw(16) << nv.diaChi
        << '|' << setw(13) << nv.luong;
    cout << '|' << endl;
}

void XuatDSNV(NhanVien a[MAX], int n)
{
    XuatTieuDe();
    for (int i = 0; i < n; i++)
    {
        Xuat1NV(a[i]);
        if ((i + 1) % 5 == 0)
            XuatDongKe('-');
    }
    XuatDongKe('=');
}

void TimKiemTheoHoTen(NhanVien a[MAX], int n, Name name, unsigned int namSinh)
{
    int m = 0;
    NhanVien b[MAX];

    for (int i = 0; i < n; i++) {
        if (a[i].name.ho == name.ho && a[i].name.ten == name.ten && a[i].date.nam < namSinh)
        {
            b[m] = a[i];
            m++;
        }
    }

    if (m == 0)
        cout << "\nKhong tim thay nhan vien co ho " << name.ho << " va co ten " << name.ten << endl;
    else
    {
        cout << "\nDa tim thay " << m << " nhan vien co ho " << name.ho << " va co ten " << name.ten << endl;
        XuatTieuDe();
        for (int i = 0; i < m; i++)
        {
            Xuat1NV(b[i]);
            if ((i + 1) % 5 == 0)
                XuatDongKe('-');
        }
        XuatDongKe('=');
    }
}

void TimKiemTheoNamSinh(NhanVien a[MAX], int n, unsigned int namSinh)
{
    int m = 0;
    NhanVien b[MAX];

    for (int i = 0; i < n; i++)
    {
        if (a[i].date.nam == namSinh)
        {
            b[m] = a[i];
            m++;
        }
    }

    if (m == 0)
        cout << "\nKhong tim thay nhan vien co nam sinh " << namSinh << endl;
    else
    {
        cout << "\nDa tim thay " << m << " nhan vien co nam sinh: " << namSinh << endl;
        XuatTieuDe();
        for (int i = 0; i < m; i++)
        {
            Xuat1NV(b[i]);
            if ((i + 1) % 5 == 0)
            {
                XuatDongKe('-');
            }
        }
        XuatDongKe('=');
    }
}

void TimKiemTheoTenVaDiaChi(NhanVien a[MAX], int n, Name name, string diaChi)
{
    int m = 0;
    NhanVien b[MAX];

    for (int i = 0; i < n; i++) {
        if (a[i].name.ten == name.ten && a[i].diaChi == diaChi)
        {
            b[m] = a[i];
            m++;
        }
    }

    if (m == 0)
        cout << "\nKhong tim thay nhan vien co ten " << name.ten << " va co dia chi " << diaChi << endl;
    else
    {
        cout << "\nDa tim thay " << m << " nhan vien co ten " << name.ten << " va co dia chi " << diaChi << endl;
        XuatTieuDe();
        for (int i = 0; i < m; i++)
        {
            Xuat1NV(b[i]);
            if ((i + 1) % 5 == 0)
            {
                XuatDongKe('-');
            }
        }
        XuatDongKe('=');
    }
}

void TimKiemTheoNamSinhVaLuong(NhanVien a[MAX], int n, unsigned int namSinh, unsigned int luong)
{
    int m = 0;
    NhanVien b[MAX];
    for (int i = 0; i < n; i++)
    {
        if (a[i].date.nam <= namSinh && a[i].luong >= luong)
        {
            b[m] = a[i];
            m++;
        }
    }

    if (m == 0)
        cout << "\nKhong tim thay nhan vien co nam sinh <= " << namSinh << " va co muc luong >= " << luong << endl;
    else
    {
        cout << "\nDa tim thay " << m << " nhan vien co nam sinh <= " << namSinh << " va co muc luong >= " << luong << endl;
        XuatTieuDe();
        for (int i = 0; i < m; i++)
        {
            Xuat1NV(b[i]);
            if ((i + 1) % 5 == 0)
            {
                XuatDongKe('-');
            }
        }
        XuatDongKe('=');
    }
}

void SapXep(NhanVien a[MAX], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j].maNV > a[j + 1].maNV)
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

bool isSorted(NhanVien a[MAX], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1].maNV > a[i].maNV)
            return false;
    }
    return true;
}

int TimKiemNhiPhan(NhanVien a[MAX], int n, string maNV)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (a[mid].maNV == maNV)
            return mid;
        if (a[mid].maNV < maNV)
            left = mid + 1;
        else right = mid - 1;
    }
    return -1; 
}