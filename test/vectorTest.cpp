#include "Vect.hpp"
#include <iostream>

int main(){
    Vect a(1,1,1);
    Vect b(1,-1,1);
    double s = 5;
    cout << a << " " << endl;
    cout << b << " " << endl;
    cout << a+b << " " << b+a << endl;
    cout << a-b << " " << b-a << endl;
    cout << a*b << " " << b*a << endl;
    cout << b*s << " " << s*b << endl;
    cout << a.cross(b) << " " << b.cross(a) << endl;
    cout << cross(a,b) << " " << cross(b,a) << endl;
    cout << a/s << " " << b/s << endl;
    Vect c = a+=b;
    cout << a << " " << c << endl;
    Vect d = b*=s;
    cout << b << " " << d << endl;
    Vect e = d-=c;
    cout << d << " " << e << endl;
    Vect f = e*=s;
    cout << e << " " << f << endl;

    cout << endl << endl << endl << endl;
    
    a = Vect(1,1,1);
    cout << a.normSq() << endl;
    cout << a.norm() << endl;
    cout << a.normalized() << endl;
    cout << a.normalize() << endl;
    cout << a << endl;

    cout << endl << endl << endl << endl;

    Normal n1(b); 
    Normal n2(1,1,1); 

    cout << n1 << endl;
    cout << n2 << endl;

    cout << n1 + n2 << endl;
    cout << n1 - n2 << endl;
    n1+=n2;
    cout << n1 << endl;

    n1-=n2;
    cout << n1 << endl;

    Point p(1,2,3);
    cout << p << endl;

    Ray r(p,a);
    cout << r << endl;
}
