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
    初始化`string`对象的方法:
    ```cpp
    string s1;              //默认初始化
    string s2(s1);          //s2是s1的副本
    string s2 = s1;         //等加以s2(s1)
    string s3("value");     //s3是字面值"value"的副本
    string s3 = "value";    //等价域s3("value")
    string s4(n,'c');       //把s4初始化为由连续n个字符串c组成的串
    ```
    >如果使用=初始化一个变量，实际上执行的是**拷贝初始化**，把等号右侧的初始值拷贝到新建的对象中去。如果不用等号，则执行的是**直接初始化**



    






