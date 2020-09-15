#include <iostream>
#include <string>

using namespace std;

class Employee{

    friend void get_info(const Employee &);

    public:
        Employee() { number= cretnum++; }
        Employee(const string &n): 
            name(n),number(cretnum++)
            {}
        Employee(const Employee &r):
            name(r.name) , number(cretnum++)
            {}
        Employee & operator= ( const Employee &rsh)
        {
            name = rsh.name;
            number = cretnum++;
        }
        


    private:
        string name;
        int number = 0;
        static int cretnum;
};

int Employee::cretnum = 0;

void get_info(const Employee & t){
    cout << t.name << " " << t.number <<endl;
}

int main()
{
    Employee e1("james"),e2;

    Employee e3;

    e2 = e1;

    get_info(e1);

    get_info(e2);

    get_info(e3);
    
    return 0;
}