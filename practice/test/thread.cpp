#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>

using namespace std;

int main()
{
    static once_flag flag;


    auto f = []()
    {
        call_once(
            flag,
            [](){
                cout << "only once" << endl;
            }
        );
    };
    
    thread t1(f);
    thread t2(f);

    

    return 0;
}