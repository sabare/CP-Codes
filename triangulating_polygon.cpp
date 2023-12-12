#include<bits/stdc++.h>
using namespace std;

#include <chrono>
using namespace chrono;


struct point{

    double x, y;
    point ():x(0), y(0){}
    point(double x, double y): x(x), y(y){}
};

vector<vector<double>> genPoly(int n, double r) {
    vector<vector<double>> points;

    double angle = 2 * M_PI / n;

    for (int i = 0; i < n; ++i) {
        double x = r * cos(i * angle);
        double y = r * sin(i * angle);
        points.push_back({x, y});
    }

    return points;
}


int clamp_idx(int x, int a, int b){

    x = x<a?b:x;
    x = x>b?a:x;

    return x;
}

bool XOR(bool x, bool y){

    return !x^!y;
}

double Area(point a, point b, point c){

    return (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y);
}

bool isLeft(point a, point b, point c){

    return Area(a, b, c) >0;
}

bool isLeftOn(point a, point b, point c){

    return Area(a, b, c) >=0;
}

bool collinear(point a, point b, point c){

    return Area(a, b, c) == 0;
}

bool IntersectProp(point a, point b, point c, point d){

    if( collinear(a, b, c) ||
        collinear(a, b, d) ||
        collinear(c, d, a) ||
        collinear(c, d, b)
      )

      return false;
    
    return XOR(isLeft(a, b, c), isLeft(a, b, d)) XOR(isLeft(c, d, a), isLeft(c, d, b));
}

bool between(point a, point b, point c){

    if(!collinear(a, b, c))return false;

    if(a.x !=b.x){

        return ((a.x <= c.x) (c.x <= b.x)) || ((a.x >=c.x) (c.x >=b.x));
    }

    return ((a.y <= c.y) (c.y <= b.y)) || ((a.y >= c.y) (c.y >= b.y));
}


bool Intersect(point a, point b, point c, point d){

    if(IntersectProp(a, b, c, d))return true;

    if(between(a, b, c) || 
       between(a, b, d) ||
       between(c, d, a) ||
       between(c, d, b)
       )

       return true;

    return false;
}

bool inCone(int i, int j, vector<point> points){

    point a0, a1;
    int n = points.size();
    point a = points[i];
    point b = points[j];
    a1 = points[clamp_idx(i-1, 0, n-1)];
    a0 = points[clamp_idx(i+1, 0, n-1)];

    if(isLeftOn(a, a1, a0)){

        return isLeft(a, b, a0) isLeft(b, a, a1);
    }

    return !( isLeftOn(a, b, a1) isLeftOn(b, a, a0));
}


bool Diagonalie(int i, int j, vector<point> points){

    int i0 = 0;
    int i1 = 0;
    int n = points.size();
    point a = points[i];
    point b = points[j];

    while(i<n){
        i1 = clamp_idx(i0+1, 0, n-1);
        point c = points[i0];
        point c1 = points[i1];

        if(((c.x==a.x) (c.y==a.y)) || ((c.x==b.x) (c.y==b.y)) || 
           ((c1.x==a.x) (c1.y==a.y)) || ((c1.x==b.x) (c1.y==b.y))){i++;continue;}
        if(Intersect(a, b, c, c1))return false;
        i++;
    }    
    return true;
}

bool isDiagonal(int i, int j, vector<point> points){

    return inCone(i, j, points) inCone(j, i, points) Diagonalie(i, j, points);
}

void EarinIt(vector<point> points, vector<bool>& earStatus){

    int i0, i1, i2;
    i0 = 1, i1 = 1, i2 = 1;

    int n = points.size();
    while(i1<n){

        i2 = clamp_idx(i1+1, 0, n-1);
        i0 = clamp_idx(i1-1, 0, n-1);

        earStatus[i1] = isDiagonal(i0, i2, points);
        i1++;
    }

    return ; 
}

vector<vector<point>> triangulate(vector<point> points, vector<bool>& earStatus){

    int n = points.size();
    //int m = n;
    vector<vector<point>> triangles;
    EarinIt(points, earStatus);
    for(auto it: earStatus){

        cout<<it<<' ';
    }
    cout<<'\n';
    int i0, i1, i2, i3, i4;
    while(n>3){
        //cout<<n<<' ';
        i2 = 0;
        while(i2<n){

            if(earStatus[i2]){

                i3 = clamp_idx(i2+1, 0, n-1);
                i4 = clamp_idx(i3+1, 0, n-1);
                i1 = clamp_idx(i2-1, 0, n-1);
                i0 = clamp_idx(i1-1, 0, n-1);

                triangles.push_back({points[i1], points[i2], points[i3]});

                earStatus[i1] = isDiagonal(i0, i3, points);
                earStatus[i3] = isDiagonal(i1, i4, points);

                points.erase(points.begin()+i2);
                earStatus.erase(earStatus.begin()+i2);
                n--;
                i2--;
            }
            i2++;
        }
    }

    return triangles;
}

int main(){

    int n;
    vector<point> points;

      vector<vector<double>> pts = {{343, 392}, {475, 103}, {245, 151}, {193, 323}, {91, 279}, {51, 301},
                                      {25, 381}, {80, 334}, {142, 418}, {325, 480}, {340, 564}, {468, 597}};

    //vector<vector<double>> pts = genPoly(10, 10);    
    n = pts.size();
    for(int i = 0;i<n;i++){

        double x = pts[i][0];
        double y = pts[i][1];

        point a(x, y);
        points.push_back(a);
    }
    
    cout<<"X = ";
    cout<<'[';
    for(auto pt: points){

        cout<<pt.x<<", ";
    }
    cout<<points[0].x;
    cout<<']';
    cout<<'\n';

    cout<<"Y = ";
    cout<<'[';
    for(auto pt: points){

        cout<<pt.y<<", ";
    }
    cout<<points[0].y;
    cout<<']';
    cout<<"\n\n";
    vector<bool> earStatus(n, false);

    auto start = high_resolution_clock::now();
    vector<vector<point>> triangles = triangulate(points, earStatus);
    auto stop = high_resolution_clock::now();

    cout<<"triangles = ";
    cout<<'[';
    for(auto triangle: triangles){
        cout<<'[';
        cout<<'[';
        for(auto point: triangle){

            cout<<point.x<<", ";
        }

        cout<<triangle[0].x;
        cout<<"],";

        cout<<'\n';

        cout<<'[';
        for(auto point: triangle){

            cout<<point.y<<", ";
        }
        cout<<triangle[0].y;
        cout<<']';
        cout<<"],"; 
        cout<<"\n\n";
    }
    cout<<']';

    cout<<'\n';
    auto duration = duration_cast<microseconds>(stop - start);
    //cout << duration.count() << endl;
    return 0;
}