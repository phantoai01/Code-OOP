#include<iostream>
using namespace std;
// Phan Huu Toai
class MTV {
        private:
        int n;
        int a[100][100];
        public:
        void nhap(){
                cout << "Nhap cap cua ma tran: ";
                cin >> this->n;
                for(int i = 0; i < n;i++){
                        for(int j = 0;j < n; j++){
                                cout << "a[" << i << "]" << "[" << j << "] = ";
                                cin >> a[i][j];
                        }
                }

        }
    void xuat() {
        cout << "Mang vua nhap la." << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
        void TCC(){
                int Sum = 0,Sum2 = 0;
                for(int i =0; i < n;i++){
                        for(int j =0;j < n;j++){
                                if(i == j){
                                        Sum += a[i][j];
                                }
                        }
                }

                cout << "Tong cac phan tu nam tren duong cheo chinh la S1 = " << Sum << endl;
                for(int i =0; i < n;i++){
                        for(int j =0;j < n;j++){
                                if(i + j == n - 1){
                                        Sum2 += a[i][j];
                                }
                        }
                }
                cout << "Tong cac phan tu nam tren duong cheo phu la S2 = " << Sum2 << endl;
        }
};


int main(){
        MTV mt;
        mt.nhap();
        mt.xuat();
        mt.TCC();
        return 0;
}