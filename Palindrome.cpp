#include <iostream>
#include <string>

using namespace std;
/* mảng lưu sự kiểm tra của mỗi xâu con của s. VD check[4][6] là xâu con từ vị trí 4 đến vị trí 6 của s
   nếu đó là palind thì check[4][6]=1, else =0; */
int check[1000][1000];

//ham xay dung gia tri cua check
 void checkPalind(string s)
 {
     int n = s.size();
     for (int i=n-1;i>=0;i--)
     {
         check[i][i]=1;
         for (int j=i+1;j<n;j++)

             check[i][j] = (s[i]==s[j]) && (i==j-1 || check[i+1][j-1]);

     }
 }

bool checkSub(int i, int j)
{
    return check[i][j];
}
 int main()
 {
     string s;
     cin >> s;
     checkPalind(s);
     int n = s.size()-1;
     cout << checkSub(0,n);
     return 0;
 }
