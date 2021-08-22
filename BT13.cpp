#include<iostream>
//Phan Huu Toai
using namespace std;

class MT {
private:
	int n, m, a[100][100];
public:
	void nhap() {
		cout << "Nhap so hang cua ma tran: ";
		cin >> n;
		cout << "Nhap So cot cua ma tran: ";
		cin >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << "a[" << i << "]" << "[" << j << "] = ";
				cin >> a[i][j];
			}
		}
	}
	void xuat() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}
	friend MT operator + (MT a, MT b) {
		//kiem tra xem so hang va so cot nhap co bang nhau khong
		if (a.n != b.n || a.m != b.m) {
			cout << "2 Ma tran khong cung kich thuoc!" << endl;
			exit(0);
		}
		MT c;
		c.n = a.n;
		c.m = a.m;
		for (int i = 0; i < c.n; i++) {
			for (int j = 0; j < c.m; j++) {
				c.a[i][j] = a.a[i][j] + b.a[i][j];
			}
		}
		return c;
	}
        // friend void tinhxungquanh();
};
// void tinhxungquanh()
// {   
//         MT mt;
//     int s = 0;
//     for(int i=0;i< mt.m;i++)
//     {
//         s=s+ mt.a[i][0]+ mt.a[i][mt.n-1];
//     }
//     for(int j=1;j< mt.n-1;j++)
//     {
//         s = s + mt.a[0][j] + mt.a[mt.m-1][j];
//     }
//     cout << "Tong cac phan tu nam tren 4 duong vien cua ma tran S = " << s << endl;
// }

int main() {
	MT a;
	a.nhap();
	MT b;
	b.nhap();
	cout << "Ma tran A[][] vua nhap la:" << endl;
	a.xuat();
	cout << "Ma Tran B[][] vua nhap la:" << endl;
	b.xuat();
	cout << "Tong 2 ma tran vua nhap la:" << endl;
	MT c;
	c = a + b;
	c.xuat();
        // tinhxungquanh();
	return 0;
}
