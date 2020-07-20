#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s1;
    vector<string> v1;

    while (cin >> s1  )
    {
        v1.push_back(s1);
    }

    for(auto i : v1)
        cout << i <<" "; 
        cout << endl;

    system("pause");
    
    return 0;
}