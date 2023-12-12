#include<bits/stdc++.h>
using namespace std;

class Point{
    private:
        int x;
        int y;
        int z;
    public:
        Point(): x(0), y(0), z(0){}
        Point(int dx, int dy, int dz): x(dx), y(dy), z(dz){}
        Point(Point& other): x(other.x), y(other.y), z(other.z){}
    
        void negate(){

            x*=-1;
            y*=-1;
            z*=-1;

            return;
        }


        double norm(){

            return sqrt((x*x) + (y*y) + (z*z));
        }

        void print(){

            cout<<"X : "<<x<<" Y : "<<y<<" Z : "<<z;
            cout<<'\n';

            return;
        }
    


};

int main(){

    Point pt1;
    Point pt2(2, 3, 4);
    Point pt4 = pt2;
    
    pt4.print();
    pt4.negate();
    pt4.print();
    cout<<pt2.norm();

    return 0;

}