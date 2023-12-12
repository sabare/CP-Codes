#include<bits/stdc++.h>

using namespace std;

class employee{

    private:
        int emp_num;
        float emp_compensation;

    public:

        void setData(){
            int n;
            float c;

            cout<<"Enter Employee Number : ";
            cin>>n;
            cout<<"\nEnter Employee Compensation : ";
            cin>>c;
            cout<<'\n';


            emp_num = n;
            emp_compensation = c;
        }
        void setData(int n, float c){

            emp_num = n;
            emp_compensation = c;
        }

        void viewData(){

            cout<<"Employee Number : "<<emp_num<<'\n';
            cout<<"Employee Compensation : "<<emp_compensation<<'\n';
        }


};


int main(){
    
    
    return 0;
}