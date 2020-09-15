#include <iostream>
#include <string>

using namespace std;

class TreeNode {   //一个用了计数引用的类  
    public:
        TreeNode(): value(""), count(new int(1)), left(nullptr), right(nullptr)  //默认构造函数
        {}

        TreeNode(const TreeNode &r) : value(r.value), count(r.count), left(r.left) , right(r.right)  //拷贝构造函数
        {
            *count++;
        }

        TreeNode & operator= (const TreeNode &rsh){  // 拷贝赋值运算符
            ++*rsh.count;
            if(--count==0){
                delete left;
                delete right;
                delete count;
            }
            value = rsh.value;
            count = rsh.count;
            left = rsh.left;
            right = rsh.right;
            return *this;
        }
  
        ~TreeNode()   //析构函数
         {  
            if(--*count == 0)
            {
                delete count;
                delete right;
                delete left;
            }
        }

    private:        
        string value;
        int *count;
        TreeNode *left;
        TreeNode *right;
};

class BinStrTree{

    BinStrTree():
        root(new TreeNode())
    {}

    BinStrTree( const BinStrTree &r){
        root = r.root;
    }

    BinStrTree & operator= (const BinStrTree &r)
    {
        TreeNode* newp = new TreeNode(*r.root);
        delete root;
        root = newp;
        return *this;
    }

    ~BinStrTree(){
        delete root;
    }

    private:
        TreeNode *root;
};

int main()
{

    return 0;
}