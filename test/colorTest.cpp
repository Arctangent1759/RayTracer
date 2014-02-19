#include "Color.hpp"
#include <iostream>

int main(){
    Color a(1.0,0.5,1.0);
    Color b(0.8,0.5,0.0);
    cout << a << " " << b << endl;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * 0.5 << endl;
    cout << a / 5 << endl;
    a+=b;
    cout << a << endl;
    a-=b;
    cout << a << endl;
    a*=2;
    cout << a << endl;
    a/=2;
    cout << a << endl;

    Color c1(1.0,0.0,0.0);
    Color c2(0.0,1.0,0.0);
    Color c3(0.0,0.0,1.0);
    Color c4(1.0,1.0,1.0);

    BRDF r(c1,c2,c3,c4);

    cout << r << endl;
}
