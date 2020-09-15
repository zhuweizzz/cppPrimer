#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};

    //使用成员函数获得迭代器
    auto iter1 = v.begin();
    auto iter2 = v.end();
    //使用全局函数获得迭代器
    auto iter3 = begin(v);
    auto iter4 = end(v);

    //使用for_each
    for_each(v.begin(),v.end(), 
                [](const auto &x){
                    cout << x << endl;
                }
    );


    return 0;
}