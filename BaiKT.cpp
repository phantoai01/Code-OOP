
/*Câu 26: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp SP1 mô tả các đối tượng là số phức với các thuộc tính: phần thực, phần ảo.
Xây dựng hàm tạo, phương thức nhập số phức, in số phức, tính module số phức
2.	Xây dựng lớp SP2 kế thừa từ lớp SP1 và bổ sung:
Nạp chồng các toán tử: = (gán), > (nhỏ hơn), == (so sánh bằng)
3.	Viết chương trình chính ứng dụng lớp SP2 để nhập một danh sách các đối tượng là các số phức (tối đa 10 phần tử). Tìm số phức có giá trị lớn nhất và đếm xem có bao nhiêu số phức trong danh sách có giá trị bằng 3+4i.

Số phức : a+b*i: trong a số thực b là số ảoz1
Module z = sqrt(a*a+b*b)
Z1=a1+b1*i
Z2=a2+b2*i
Z1=z2: a1==a2 và b1==b2
Z1>z2: khi module z1>module z2
*/
//khai báo thư viện 
#include<iostream>
using namespace std;
// khai báo tên lớp 
class SP1
{
	// khai báo thuộc tính
protected:
	double Phan_Thuc, Phan_Ao;
public:
	//hàm hởi tạo mặc định
	SP1()
	{
	}
	//hàm khởi tạo có đối số
	SP1(double Phan_Thuc, double Phan_Ao)
	{
		this->Phan_Thuc = Phan_Thuc;
		this->Phan_Ao = Phan_Ao;
	}
	//hàm hủy
	~SP1()
	{
	}
	//khai báo các phương thức được sử dụng
	void nhap();
	void xuat();
	double Module();
};
//phương thức nhập 1 số phức
void SP1::nhap()
{
	cout << "Nhap Phan Thuc cua So phuc: ";
	cin >> this->Phan_Thuc;
	cout << "Nhap phan ao cua so phuc: ";
	cin >> this->Phan_Ao;
}
//phương thức xuất số phức
void SP1::xuat()
{
	cout << "(" << Phan_Thuc << " + " << Phan_Ao << "i)";
}
// tính module
double SP1::Module() {
	return sqrt((Phan_Thuc * Phan_Thuc) + (Phan_Ao * Phan_Ao));
}
class SP2 : public SP1
{
public:
	SP2()
	{
	}
	
	~SP2()
	{
	}
	//khai báo các phương thức nạp chồng
	void operator = (SP2& );
	bool operator > (SP2&);
	bool operator == (const SP2& );
	//khai báo hàm bạn để truy xuất được giá trị của lớp con và lớp cha
	friend int dem(SP2* sp, int n);
};
/*2.	Xây dựng lớp SP2 kế thừa từ lớp SP1 và bổ sung:
Nạp chồng các toán tử : = (gán), > (nhỏ hơn), == (so sánh bằng)*/

bool SP2::operator == (const SP2& SP) { 
	// Neu tra ve false thi hai so phuc khac nhau
	return ((this->Phan_Thuc == SP.Phan_Thuc) && (this->Phan_Ao == SP.Phan_Ao));
}
// thực hiện nạp chồng toán tử gán =
void SP2::operator = (SP2& a) {
	// gán phần thực của đối tượng truyền vào cho phần thực của đối tượng trung gian là con trỏ this
	this->Phan_Thuc = a.Phan_Thuc;
	// gán phần ảo của đối tượng truyền vào cho phần ảo của đối tượng trung gian là con trỏ this
	this->Phan_Ao = a.Phan_Ao;
}
//thực hiện nạp chồng toán tử so sánh >
bool SP2::operator > ( SP2& a) {
	return this->Module() > a.Module();
}

//hàm nhập n số phức tương tụ xuất n số phức
void nhapN(SP2* sp, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap So Phuc Thu " << i + 1 << endl;
		(sp + i)->nhap();
	}
}
// xuất n số phức
void xuatN(SP2* sp,int n) {
	for (int  i = 0; i < n; i++)//vòng lặp để nhập được từ phần tử thứ 0 đến phần tử n
	{
		cout << "So Phuc thu : " << i + 1 << endl;
		//xuất giá trị phần tử số phức ở vị i
		(sp + i)->xuat();
		cout << endl;
	}
}
//Tìm số phức có giá trị lớn nhất và đếm xem có bao nhiêu số phức trong danh sách có giá trị bằng 3+4i.
void search(SP2* sp, int n) {
	SP2 max = sp[0];
	//duyệt mảng để kiểm tra các phần tử 
	for (int i = 0; i < n; i++)
	{
		//kiểm tra và thực hiện gán phần tử nào max
		if (sp[i] > max) {
			max = sp[i];
		}
	}
	//xuất ra sau khi tìm được phần tử max trong mảng;
	max.xuat();
}
//đếm xem có bao nhiêu số phức trong danh sách có giá trị bằng 3+4i.
int dem(SP2* sp, int n) {
	int count = 0;// biến để lưu số lượng
	for (int i = 0; i < n; i++)//duyệt từ đầu đến phần tử số phức cuối cùng để kiểm tra n số phức
	{
		// điều kiện để số phức thứ i bằng số phức 3 + 4i thực = thực , ảo = ảo
		if ((sp + i)->Phan_Thuc == 3 && (sp + i)->Phan_Ao == 4) {
			count++;//tăng lên nếu điều kiện đúng là 2 phần bằng nhau
		}
	}
	return count;
}
int main() {
	int n;
	do
	{
		cout << "Nhap Vao so luong so phuc: ";
		cin >> n;
	} while (n > 10);
	//nhập dãy n số phức
	SP2* SP = new SP2[n];
	nhapN(SP, n);
	//xuất dãy n số phức
	xuatN(SP, n);
	// số phức có giá trị lớn nhất 
	cout << "So Phuc co gia tri lon nhat : ";
	search(SP, n);
	cout << "\nSo Luong so luong so phuc trong danh sach co gia tri bang 3+4i là: " << dem(SP,n);
	delete[] SP;
}
