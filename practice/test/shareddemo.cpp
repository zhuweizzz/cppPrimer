#include<iostream>
#include<memory>

using namespace std;

class Node final
{
    public:
        using this_type = Node;
        using shared_type = shared_ptr<this_type>;
    public:
        shared_type next;
};

int main()
{

    auto n1 = make_shared<Node>();
    auto n2 = make_shared<Node>();

    cout << "n1引用计数" << n1.use_count() << endl;
    cout << "n1的next引用计数" <<n1->next.use_count() << endl;

    cout << "n2引用计数" << n2.use_count() << endl;
    cout << "n2的next引用计数" <<n2->next.use_count() << endl;

    n1->next = n2;

    cout << "n1->next = n2后:" <<endl;

    cout << "n1引用计数" << n1.use_count() << endl;
    cout << "n1的next引用计数" <<n1->next.use_count() << endl;

    cout << "n2引用计数" << n2.use_count() << endl;
    cout << "n2的next引用计数" <<n2->next.use_count() << endl;

    n2->next = n1;

    cout << "n2->next = n1后:" <<endl;

    cout << "n1引用计数" << n1.use_count() << endl;
    cout << "n1的next引用计数" <<n1->next.use_count() << endl;

    cout << "n2引用计数" << n2.use_count() << endl;
    cout << "n2的next引用计数" <<n2->next.use_count() << endl;


    return 0;
}