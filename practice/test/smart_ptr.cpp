#include<iostream>
#include<utility> //pair类型所在头文件
#include<memory>  //智能指针
#include<assert.h>


using namespace std;

int main()
{
    unique_ptr<int> ptr(new int(10)); //指向int型的智能指针
    assert(*ptr == 10);    //使用*取内容
    assert(ptr != nullptr);  //判断是否为空指针

    unique_ptr<string> ptr2(new string("hello"));
    assert(*ptr2 == "hello");  
    assert(ptr2->size() == 5); //使用->调用成员函数 

    //使用工厂函数make_unique()强制创建智能指针时初始化。
    //防止使用未初始化的空指针

    auto ptr3 = make_unique<int>(42);  //c++ 14才有
    assert(ptr3 && *ptr3 == 42);

    auto ptr4 = make_unique<string>("hello");
    assert(!ptr4->empty());

    //unique_ptr 表示指针的所有权是唯一的，不允许共享，任何时候只能有一个人持有。
    //使用move显示声明转义所有权。

    auto ptr4 = make_unique<int>(32);

    auto ptr5 = move(ptr4);  //显示转移所有权

    assert(!ptr4 && ptr5); 


    //shered ptr也可以使用工厂函数创建
    shared_ptr<int> prt(new int(10));

    shared_ptr<string> ptr1(new string("hello"));






    return 0;
}