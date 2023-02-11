#include <iostream>
class Rational{
    private:
    int num;
    int den;
    void ReductFraction();
    public:
    Rational(int n=0,int d=1){num=n;den=d;ReductFraction();};
    Rational operator+(const Rational &r1)const;
    Rational operator*(const Rational &r1)const;
    bool operator>(const Rational &r1)const;
    bool operator==(const Rational &r1)const;
    void display()const {std::cout<<num<<"/"<<den;};
};
void Rational::ReductFraction(){
int tmp=(num>den)?den:num;
for(;tmp>1;tmp--){
    if (num%tmp==0&&den%tmp==0){
        num/=tmp;
        den/=tmp;
    }
}    
}
Rational Rational::operator+(const Rational &r1)const{
    Rational tmp;
    tmp.num=r1.num*den+num*r1.den;
    tmp.den=r1.den*den;
    tmp.ReductFraction();
    return tmp;
}
int main(){
    Rational m(1,3);
    Rational n(2,4);
    Rational tmp;
    tmp=m+n;
    tmp.display();
}