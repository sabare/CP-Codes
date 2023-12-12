#include<bits/stdc++.h>

using namespace std;



double angle(vector<double>& a, vector<double>& b, vector<double>& c){

    vector<double> v1;
    v1.push_back(b[0]-a[0]);
    v1.push_back(b[1]-a[1]);

    
    vector<double> v2;
    v2.push_back(b[0]-c[0]);
    v2.push_back(b[1]-c[1]); 

    double dot_pdt = v1[0]*v2[0] + v1[1]*v2[1];

    double v1_mag = sqrt(v1[0]*v1[0] + v1[1]*v1[1]);
    double v2_mag = sqrt(v2[0]*v2[0] + v2[1]*v2[1]);

    return acos(dot_pdt/(v1_mag*v2_mag));
}

bool is_clockwise(vector<double>& a, vector<double>& b, vector<double>& c){

    double det = ( (b[0]-a[0]) * (c[1]-a[1]) ) - ( (c[0]-a[0]) * (b[1]-a[1]) );
    return det<0;
}

double clamp_idx(double x, double a, double b){

    x = x<a?b:x;
    x = x>b?a:x;

    return x;
}

vector<vector<vector<double>>> triangulate(vector<vector<double>>& points){

    int n = points.size();

    int m = n;

    int max_x = points[0][0];
    int j = 0;


    for(int i = 1;i<n;i++){

        if(points[i][0]> max_x){

            max_x = points[i][0];
            j=  i;
        }

    }

    double i0 = clamp_idx(j-1, 0, n-1);
    double i2 = clamp_idx(j+1, 0, n-1);

    vector<double> A=points[i0];
    vector<double> B=points[j];
    vector<double> C=points[i2];

    bool clockwise = is_clockwise(A, B, C);

    vector<double> angles(n);

    for(int i = 0;i<n;i++){

        vector<double> a=points[i];
        vector<double> b= points[(i+1)%n];
        vector<double> c=points[(i+2)%n];

        double theta = angle(a, b, c);
        bool triangle_cw = is_clockwise(a, b, c);

        if(triangle_cw!=clockwise){

            theta = 2*M_PI - theta;   
        }

        angles[(i+1)%n]=theta;
    }

    vector<vector<vector<double>>> triangles;

    for(int i = 0;i<m-2;i++){

        double min_ang = *min_element(angles.begin(), angles.end());

        int min_ang_idx = min_element(angles.begin(), angles.end()) - angles.begin();

        i0 = clamp_idx(min_ang_idx-1, 0, n-1);
        i2 = clamp_idx(min_ang_idx+1, 0, n-1);

        A=points[i0];
        B=points[min_ang_idx];
        C=points[i2];

        triangles.push_back({A, B, C});

        vector<double> a = points[clamp_idx(i0-1, 0, n-1)];
        vector<double> b = points[i0];
        vector<double> c = points[i2];

        double theta = angle(a, b, c);
        bool triangle_cw = is_clockwise(a, b, c);

        if(triangle_cw!=clockwise){

            theta = 2*M_PI - theta;   
        }

        angles[i0] = theta;

        a = points[i0];
        b = points[i2];
        c = points[clamp_idx(i2+1, 0, n-1)];

        theta = angle(a, b, c);
        triangle_cw = is_clockwise(a, b, c);

        if(triangle_cw!=clockwise){

            theta = 2*M_PI - theta;   
        }

        angles[i2] = theta;

        points.erase(points.begin() + min_ang_idx);
        angles.erase(angles.begin() + min_ang_idx);

        n--;
    }

    return triangles;
}


int main(){

    // vector<vector<double>> points = {{343, 392}, {475, 103}, {245, 151}, {193, 323}, {91, 279}, {51, 301},
    //                                   {25, 381}, {80, 334}, {142, 418}, {325, 480}, {340, 564}, {468, 597}};

    
    vector<vector<double>> points = {{0, 0}, {62.23, 191.75}, {331.22, 343.93}, {200, 500}, {-65.3, 428.6}, {23.29, 277.39}, 
                {-12.79, 175.68}, {-173.54, 294.64}, {-94.24, 373.94}, {-187.47, 459.68}, {-297.86, 274.27}, {-96.94, 213.19}};

    vector<vector<vector<double>>> triangles = triangulate(points);

    cout<<'[';
    for(auto triangle: triangles){
        cout<<'[';
        cout<<'[';
        for(auto point: triangle){

            cout<<point[0]<<", ";
        }

        cout<<triangle[0][0];
        cout<<"],";

        cout<<'\n';

        cout<<'[';
        for(auto point: triangle){

            cout<<point[1]<<", ";
        }
        cout<<triangle[0][1];
        cout<<']';
        cout<<"],"; 
        cout<<"\n\n";
    }
    cout<<']';

    return 0;
}