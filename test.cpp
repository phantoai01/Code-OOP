#include<iostream>
using namespace std;

/*1.	Khai báo lớp ma trận với các thuộc tính: số hàng, số cột, các phần tử của ma trận.
2.	Xây dựng các phương thức: nhập, xuất một đối tượng ma trận.
3.	Nhập vào hai ma trận đồng cấp. Thực hiện cộng hai ma trận vừa nhập (dùng hàm bạn). In ra màn hình hai ma trận ban đầu và ma trận kết quả.

*/

class MT {
	private:
		int n, m, a[1000][1000];
	public:
		void nhap() {
			cout << "Nhap so hang cua ma tran: ";
			cin >> n;
			cout << "Nhap So cot cua ma tran: ";
			cin >> m;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << "Nhap gia tri cua phan tu thu: " << i + 1 << endl;
					cout << "a[" << i << "]" << "[" << j << "] = ";
					cin >> a[i][j];
				}
			}
		}
		void xuat() {
			cout << "Mang vua nhap la." << endl;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << a[i][j] << " ";
				}
			}
		}

};


int main() {
	MT mt;
	mt.nhap();
	mt.xuat();
	return 0;
}
