#include <iostream>
#include <vector>
 
using namespace::std;

class numbered{
	public:
		numbered(){mysn = num ++;}

		numbered(const numbered &orj): mysn(orj.num ++)
			{}

		int mysn= 0;

	private:
		static int num;
};

int numbered::num =0;

void f (numbered &s)
{
	cout << s.mysn << endl;
}
 
int main()
{
	numbered a, b=a , c=b;

	f(a);

	f(b);

	f(c);


	//system("pause");

	return 0;
}