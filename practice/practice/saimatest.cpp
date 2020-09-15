#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int max=0;
    int num;
    vector<int> v1;
    vector<int> v2;
    while( cin >> num )
    {
        v1.push_back(num);
        if(num > max)
            max = num;
    }

    int nowgu = 1;
    int falg = 1;
    int days = 1;
    int temp = 1;
    v2.push_back(1);

    for( int d = 2 ; d <= max ; d++)
    {
        if(falg)  //如果是涨
        {
            ++nowgu;
            if(--temp == 0)
                falg = 0;
        }
        else  //跌
        {
            --nowgu;
            falg = 1;
            temp = ++days;
        }

        v2.push_back(nowgu);

    }

    for(const auto &t : v1)
        cout << v2[t-1] << endl;

    system("pause");

    return 0;
}