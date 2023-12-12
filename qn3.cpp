#include<bits/stdc++.h>
using namespace std;

class Queue
{
    private:
        static  int MAX = 10;
        int items[MAX];  
        int head;        
        int tail;        

    public:
        Queue()          
        {
            head = -1;   
            tail = -1;   
        }

        bool isEmpty()
        {
            return head == -1; 
        }

        bool isFull()
        {
            return (tail + 1) % MAX == head; 
        }

        void put(int value)
        {
            if (isFull())
            {
                return;
            }

            if (isEmpty())
            {
                head = 0;  
            }

            tail = (tail + 1) % MAX;  
            items[tail] = value;      
        }

        int get()
        {
            if (isEmpty())
            {
                cout << "Queue is empty. Cannot dequeue." << endl;
                return -1;  
            }

            int value = items[head];
            if (head == tail)
            {
                
                head = -1;
                tail = -1;
            }
            else
            {
                head = (head + 1) % MAX;
            }

            return value;
    }
};

int main(){

    Queue q1;
    q1.put(5);
    q1.put(6);
    cout<<q1.get()<<'\n';
    q1.put(7);
    cout<<q1.get()<<'\n';
    cout<<q1.get()<<'\n';
    cout<<q1.get()<<'\n';

    return 0;
}