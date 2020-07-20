## c++基础

### const限定符
* const对象一旦被创建后无法被改变，所以必须初始化
    ```cpp
    const int k; //错误 k是未经初始化的常量
    ```
    在用一个对象初始化另一个const对象时 可以不是const对象
* 默认状态下 const对象仅在文件内有效
    ```cpp
    extern cosnt int buffsize; //多文件共享cosnt对象时需要加extern 
    ```
* const的引用
    对const的引用不能被用作修改其绑定的对象
    ```cpp
    const int c1 = 1024;
    const int &r1 =c1;
    r1=42;   //错误:r1为对常量的引用
    ```
    >常量引用仅对引用可参与的操作做出了限定，对引用的对象本身是不是常量未作限定
    ```cpp
    int i=42;
    int &r1 = i;
    const int &r2 =i;
    r1=0;   //正确
    r2=0;   错误
    ```

* 指针和const
    指向常量的指针:不能用于改变其指向的对象
    >指向常量的指针没有规定所指对象必须为常量，仅仅要求不能通过该指针改变对象的值
    ```cpp
    const double pi=3.14;
    double *ptr = &pi;          //错误：ptr是普通指针
    const double *cptr =&pi;    //正确
    *cptr=42;                   //错误
    ```
    常量指针:不允许指针改变指向
    >因为指针本身也是对象，所以允许把指针本身定义为常量
    ```cpp
    int errNum = 0;
    int *const curErr ==&errNum;  //此后curErr将一直指向errNum
    const double pi;
    const double *const pip =&pi;  //指向常量对象的常量指针
    ```
* 顶层const和底层const
    >指针本身是否为常量和指针指向的内容是否为常量是两个独立的问题，顶层const表示指针本身是常量，底层const表示指针指向的对象为cosnt。指针既可以为顶层const也可为底层const。
    >拷贝时非常量可转换为常量，常量不能转换为非常量

### constexpr和常量表达式
* 常量表达式
    >常量表达式是指值不会改变并在编译阶段就能得到计算结构的表达式
    ```cpp
    const int max_files=20;         //max_files是常量表达式
    const int limit = max_files+1;  //limit是常量表达式
    int staff_size = 27;            //不是常量表达式
    const int sz = get_size();      //不是常量表达式 必须运行才能获取到值
    ```

* constexpr变量
    >c++11中允许将变量声明为constexpr类型以便由编译器来验证变量的值是否为一个常量表达式
    ```cpp
        constexpr int mf=20;        //20为常量表达式
        constexpr int limit =mf+1;  //mf+1为常量表达式
        constexpr int sz =size();   //只有当size()为constexpr函数时该声明正确
    ```
    >一般来说，如果你认定变量为常量表达式，那就将其声明成constexpr类型
* 字面值类型
    类型简单，值显而易见、容易得到的数据类型。  
    算数类型、引用和指针都属于字面类型。自定义类、IO库、string类型则不属于字面值类型。

### 处理类型
* 类型别名
    定义类型的别名由两种方法使用关键字`typedef`:
    ```cpp
    typedef double wages;
    typedef wages base,*p;
    ```
    >typedef为声明语句中的基本数据类型，typedef不声明变量而是定义类型别名。
    c++11中使用别名声明来定义类型的别名
    ```cpp
    using SI=Sales_item; //这里的Sales_item是个类的名字
    ```

* `auto`类型
    当无法知道表达式的类型时，使用`auto`类型说明符，则由编译器去分析表达式的类型。但`auto`定义的类型必须有初始值

    <br>

* 复合类型、常量和`auto`
    <br>

* decltype类型指示符  c++11新
    >希望从表达式的类型推断出要定义变量的类型，但不用该表达式进行初始化
    ```cpp
    const int ci=0;&cj=ci;
    decltype(ci)  x = 0;   //x的类型为const int
    decltype(cj) y = x;     //y为const 引用，绑定到对象x
    decltype(cj) z;

    decltype(*p)  //返回类型是 引用
    decltype((variable))  //的结果永远是引用
    decltype(variable)    //只有当variable是引用时结果才是引用             
    ```

### 命名空间`using`声明
* 域操作符 `::`编译器从操作符左侧名字所示的作用域中寻找右侧的名字

    ```cpp
        std::cin
        std::cout
    ```
    用`using`声明可以直接访问该命名空间中的名字
    ```cpp
        using namespace :: name;
    ```

### 标准库类型`string`
* 需要包含 `string`头文件 ,其命名空间在标准命名空间中
    ```cpp
    #include <string>
    using std::string;
    ```
* 定义和初始化`string`对象
    ```cpp
    string s1;             //默认初始化，空字符串
    string s2=s1;          //s2为s1的副本
    string s3="hiya";       //s3是该字符串字面值的副本
    string s4(10,'c');      //s4内容为 cccccccccc
    ```
* 初始化`string`对象的方法:
    ```cpp
    string s1;              //默认初始化
    string s2(s1);          //s2是s1的副本
    string s2 = s1;         //等加以s2(s1)
    string s3("value");     //s3是字面值"value"的副本
    string s3 = "value";    //等价域s3("value")
    string s4(n,'c');       //把s4初始化为由连续n个字符串c组成的串
    ```
    >如果使用=初始化一个变量，实际上执行的是**拷贝初始化**，把等号右侧的初始值拷贝到新建的对象中去。如果不用等号，则执行的是**直接初始化**

### string对象上的操作
>一个类除了要规定初始化其对象的方式外，还要定义对象上所能执行的操作，既能定义通过函数名调用的操作也能定义 `<<`、`+`等各种运算在该类对象的新含义

* `string`对象的操作
    ```cpp
    os<<s;               //将s写到输出流OS中，返回OS;
    is>>s;               //将is中读取字符串赋给s，字符串以空白分隔返回is
    getline(is,s);      //从is中读取一行赋给s，返回is
    s.empty();          //s为空返回yes，否则返回false
    s.size();           //返回s中字符的个数
    s[n];               //返回s中第n个字符的引用，n从0计起
    s1+s2;              //返回s1和s2连接后的结果
    s1=s2;              //用s2的副本代替s1原来的字符串
    s1==s2;             //如果s1和s2的字符完全一样，则它们相等，对大小写敏感
    <,<=,>,>=
    ```

* `getline()`读取一整行
    >getline在最终得到的字符串中保留输入时的空白符，函数从给定的输入流中读取内容，直到遇到换行符为止（换行符也被读入），将所读内容存入到string对象中(不存换行符),getline()函数会返回其流参数（其中换行符被丢弃）

* `string`的empty和size操作
    empty()函数判断`string`对象是否为空，size()函数返回string对象的长度

    size()函数返回的是`string::size_type`类型
* 字面值和`string`对象相加
    >当把`string`对象和字符字面值及字符串字面值混在一条语句中使用时，必须确保每个加法运算符`(+)`的两侧的运算对象至少有一个是`string`:(字面值不能直接相加)
    ```cpp
    string s4 = s1 + ",";       //正确：把string对象和一个字面值相加
    string s5 = "hello" + ","; //错误：两个运算对象都不是string
    string s6 = s1 + "," + "world"; //正确
    string s7 = "hello" + "," + s2; //错误
    ```
* 处理`string`对象中的字符
    `cctype`头文件中的函数
    ```cpp
    isalnum(c) //当c是字母或数字时为真
    isalpha(c) //当c是字母时为真
    iscntrl(c) //当c是控制字符时为真
    isdigit(c) //当c是数字时为真
    isgraph(c) //当c不是空格但可打印时为真
    islower(c) //当c是小写字母时为真
    isprint(c) //当c是可打印字符时为真
    ispunct(c) //当c是标点符号时为真
    isspace(c) //当c是空白时为真
    isupper(c) //当c是大写字母时为真
    isxdigit(c) //当c是十六进制数字时为真
    tolower(c) //如果是大写字母则输出其对应小写字母，否则原样输出
    toupper(c) //如果是小写字母则输出其对应大写字母，否则原样输出
    ```
    >处理字符串中的每个字符--使用基于范围的`for`语句,其语句遍历序列中的每个元素并对序列中的每个值执行某种操作，语法形式:
    ```cpp
        for( declaration : expression)
            statement
        //expression部分是一个对象,用于表示一个序列，在declarataion部分负责定义一个变量用于访问序列中的基础元素
    ```
    >如果想要改变字符串中的字符，则把循环变量定义成引用类型

* 访问`string`对象中的单个字符
    >访问string对象的单个字符有两种方式:一种是使用下标、一种是使用迭代器
    
    下标运算符：`[]`接收`string::size_type`参数，参数为要访问的字符的位置，返回是该位置上字符的引用

### 标准库类型vector

>标准库类型vector表示对象集合，其中所有对象的类型都相同。其中每个对象都有一个与之对应的索引，索引用于访问对象，也被称为**容器**

>C++有类模板和函数模板，其中`vector`是一个类模板。模板本身不是类或者函数。编译器根据模板创建类或者函数的过程叫实例化，使用模板时需要指出编译器应把类或函数实例化成何种类型
* 定义和初始化`vector`对象
```cpp
    vector<T> v1;  //v1是空vector，它潜在的元素是T类型，执行默认初始化
    vector<T> v2(v1);  //v2中包含有v1的所有副本
    vector<T> v2=v1;  //等价于v2(v1)
    vector<T> v3(n,value)  //v3包含了n个重复元素，每个元素的值都是val
    vector<T> v4(n)   //v4包含了n个重复地执行了值初始化的对象
    vector<T> v5{a,b,c....};   //v5包含了初始值个数的元素，每个元素被赋予相应的初始值
    vector<T> v5={a,b,c....};  //与上一条等价
```
* 区分列表初始化和值初始化
    通常情况下可以只提供vector对象容纳的元素数量而略去初始值。
    ```cpp
    vector<int> ivec(10); //10个元素，每个都初始化为0
    ```

* 向`vector`对象中添加元素
    使用`vector`的成员函数`push_back`:`push_back`将一个值当成vector对象的尾元素“压入(push)”`vector`对象的尾端(back)。
    ```cpp
    vector<int> v2;
    for(i=0;i<100;i++)
        v2.push_back(i);
    ```

* 其它vector操作
    >除了push_back之外，vector还提供了几种其他操作，大多数和`string`类似
    ```cpp
    v.empty()   //判断v是否为空
    v.size()    //返回v中元素个数
    v.push_back(t)  //向v的尾端添加一个值为t的元素
    v[n]            //返回第n个位置上元素的引用
    v1 = v2         //用v2中的元素拷贝替换v1中的元素
    v1 = {a,b,c...} //用列表中的元素拷贝替换v1中的元素
    v1 == v2;       //判断是否相等 只有元素数量相等并且对应位置元素相同
    v1 != v2;
    ```
    >不能通过元素下标向vector中添加元素。只能对确知已存在的元素执行下标操作

### 迭代器(iterator)
>可以用下标运算符来访问`string`对象的字符或`vector`对象的元素，但还有另一种更通用的机制也可实现同样的目的，除vector之外标准库还定义了其它几种容器。所有标准库容器都可以使用迭代器，但只有少数几种才同时支持下标运算符。

* 使用迭代器  
    有迭代器的类型同时拥有返回迭代器成员，这种类型都有`begin`和`end`成员，其中`begin`成员负责返回指向第一个元素的迭代器
    ```cpp
    auto b = v.begin(), e = v.end(); //b表示v的第一个元素，e表示v尾元素的下一位置
    ```
    >end成员返回的迭代器被称为尾后迭代器，指示的是容器的一个根本不存在的尾后元素，无实际含义，仅仅是个标记。当容器为空时，`begin()`和`end()`返回的是同一个迭代器，都是尾后迭代器

* 迭代器运算符
    ```cpp
    *iter  //返回迭代器iter所指元素的引用
    iter->mem  //解引用iter并获取该元素的名为mem的成员，等价于(*iter).mem
    ++iter  //令iter指向容器中的下一个元素
    --iter  //令iter指向容器中的上一个元素
    iter1 == iter2;
    iter1 != iter2; //判断两个迭代器是否相等(不相等),如果两个迭代器指示的是同一个元素或者它们是同一个容器的尾后迭代器，则相等，否则不等。
    ```
* 迭代器运算   
    只有`string`和`vector`提供了更多的额外的运算符
    >`string`和`vector`迭代器提供了更多额外的运算符，一方面可以使迭代器的每次移动跨过多个元素，另外也支持迭代器进行关系运算。（P99页）
    ```cpp
    iter+n;
    iter-n;
    iter += n;
    iter -= n;
    iter1 - iter2;
    >、>= 、< 、<= 等操作
    ```
* 数组
    C++ 11标准库里加入了`begin()`和`end()`函数,用于返回指向数组首元素的指针，`end`函数返回指向数组尾元素的下一位置的指针。



