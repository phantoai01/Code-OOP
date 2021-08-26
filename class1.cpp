#include<iostream>
#include<string>
#include<iomanip>
//Phan Huu Toai
using namespace std;
class ThiSinh{
        private:
        string mats, hoten;
        double toan,ly,hoa;
        public:
        void NhapTs(){
                cin.ignore();
                cout << "\nNhap Ho ten Thi Sinh: " ;    getline(cin,hoten);
                cout << "\nNhap vao ma Thi Sinh: ";       getline(cin,mats);
                cout << "\nNhap Diem Toan: ";     cin >> toan ;
                cout << "\nNhap Diem Ly: "; cin >> ly;
                cout << "\nNhap Diem Hoa: "; cin >> hoa;
        }
        string getterHOTEN(){
                return hoten;
        }
        
        void xuat(){
                double Sum = toan + ly + hoa;
                // cout << setw(20) << left << "MaTS";
                // cout << setw(20) << left << "HoTen";
                // cout << setw(20) << left << "Diem Toan";
                // cout << setw(20) << left << "Diem Ly";
                // cout << setw(20) << left << "Diem Hoa";
                // cout << setw(20) << left << "Tong Diem";
                // cout << endl;
                cout << setw(20) << left << mats;
                cout << setw(20) << left << hoten;
                cout << setw(20) << left << toan;
                cout << setw(20) << left << ly;
                cout << setw(20) << left << hoa;
                cout << setw(20) << left << tinhtong();
                cout << endl;
                
        }
        double tinhtong(){
                return toan + ly + hoa;
        }

};

        void swap(ThiSinh &x,ThiSinh &y){
        ThiSinh temp = x;
        x = y;
        y = temp;
        }
        void NhapNTs(ThiSinh *ds, int n){
                cout << "\n____________________________________\n";
	        for (int i = 0; i < n; i++) {
		        cout << "\nNhap vao sinh vien thu: " <<  i + 1;
		        (ds+i)->NhapTs();
                cout << "\n____________________________________\n";
	        }
        }


        void XuatNTs(ThiSinh *ds, int n){
                cout << "\nDanh sach sinh vien gom:\n";
                cout << setw(20) << left << "MaTS";
                cout << setw(20) << left << "HoTen";
                cout << setw(20) << left << "Diem Toan";
                cout << setw(20) << left << "Diem Ly";
                cout << setw(20) << left << "Diem Hoa";
                cout << setw(20) << left << "Tong Diem";
                cout << endl;
                for (int i = 0; i < n; ++i) {
		        (ds+i)->xuat();
	        }
        }
        void SXDStheoten(ThiSinh *ds, int n) {
                for (int i = 0; i < n - 1; i++) {
                        for (int j = i + 1; j < n; j++) {
                                if (ds[i].getterHOTEN() > ds[j].getterHOTEN() ) {
                                        // ThiSinh tg;
                                        // tg = ds[i];
                                        // ds[i] = ds[j];
                                        // ds[j] = tg;
                                        swap(ds[i],ds[j]);
                                }
                        }
                }
                XuatNTs(ds,n);
        }
        void max(ThiSinh *ds, int n){
        double max = 0;
        for (int i = 0; i < n; i++)
        {
                if (max < ds[i].tinhtong())
                max = ds[i].tinhtong();
        }
        cout<<"-----------------------------------------"<<endl;
        cout<<"Sinh vien diem cao nhat la:"<<endl;
        for (int i = 0; i < n; i++)
        {
                if (ds[i].tinhtong() == max)
                ds[i].xuat();
        }
        cout<<"------------------------------------------"<<endl;
        }
int main(){
        int n;
        cout << "Nhap so luong Thi Sinh:";
        cin >> n;
        ThiSinh *ts,*ds;
        ds = new ThiSinh[n];
        NhapNTs(ds,n);
        XuatNTs(ds,n);
        SXDStheoten(ds,n);
        max(ds,n);
        delete[]ds;
        return 0;
}