#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

int main()
{
    string word;

    vector<string> v1;

    while(cin >> word)
    {
        v1.push_back(word);
    }

    for( decltype(v1.size()) i =0 ; i!=v1.size() ; i++)
    {
        for(auto &j : v1[i])
            j=toupper(j);
        cout << v1[i] <<endl;
    }  

    system("pause");

    return 0;
}