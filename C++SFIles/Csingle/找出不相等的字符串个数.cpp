#include <iostream>
#include <string>
using namespace std;
class zifu
{
public:
    int a[26] = {0};
};
int main()
{
    int n;
    cin >> n;
    int m = 0;
    zifu *p = new zifu[n];
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        zifu r;
        bool flag=true;
        for (int j = 0; s[j] != '\0'; j++)
        {
            int q = s[j] - 97;
            r.a[q]++;
        }
        for (int g=0;g<m;g++){
       
    if(r.a[0]==p[g].a[0]&&
    r.a[1]==p[g].a[1]&&
    r.a[2]==p[g].a[2]&&
    r.a[3]==p[g].a[3]&&
    r.a[4]==p[g].a[4]&&
    r.a[5]==p[g].a[5]&&
    r.a[6]==p[g].a[6]&&
    r.a[7]==p[g].a[7]&&
    r.a[8]==p[g].a[8]&&
    r.a[9]==p[g].a[9]&&
    r.a[10]==p[g].a[10]
    &&r.a[11]==p[g].a[11]&&
    r.a[12]==p[g].a[12]&&
    r.a[13]==p[g].a[13]&&r.a[14]==p[g].a[14]&&r.a[15]==p[g].a[15]&&
    r.a[16]==p[g].a[16]&&r.a[17]==p[g].a[17]&&r.a[18]==p[g].a[18]&&
    r.a[19]==p[g].a[19]&&r.a[20]==p[g].a[20]&&r.a[21]==p[g].a[21]&&
    r.a[22]==p[g].a[22]&&r.a[23]==p[g].a[23]&&r.a[24]==p[g].a[24]&&
    r.a[25]==p[g].a[25]){
                flag=false;
            }
        }
        if(flag||m==0)
        {
            p[m]=r;
            m++;
        }
        else continue;     
    }
    cout << m << endl;
    system("pause");
}