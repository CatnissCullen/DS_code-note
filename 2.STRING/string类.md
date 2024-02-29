# string 类处理方法集合（c++风格字符串）

⚠ ***字符串相关的算法题能直接输出就不要原地修改原字符串！若不能直接输出就另开一个和原串一样的新串，对原串检查，==若是修改元素则可只对新串修改，若有长度变动则两串都要改（原串可用无关字符填充）==***



### 写在前面

⭐ 只能用 `cin>>` 读入，默认遇到空格结束读入，结尾会加上‘\0’

⭐ string内部也可以有‘\0’元素（直接赋值带‘\0’的字符串，不是读入），但不占内存（不算在size中），遇到'\0'时截断size()

⭐ `getline(cin,str)` 可整行读入 string 类 str （<u>会吃掉结尾换行符，相当于 c-string 的 gets()</u> ） 

⭐ .size 和 .length 等效，都不包括 '\0' 且以第一个 '\0' 结束





### 构造函数

- `string(size_t n, char c);`：使用 n 个 c 字符初始化 string 对象
- `string str(char[] cs);`：使用 c-string 初始化 string 对象





### 重载运算符

- `=`：string 赋值给 string ；字符串文字量（"xxxx"）赋值给 string ；char[] 赋值给 string【 c-string 转 string ！】
- `+`：追加，与 append 等效
- `<` `>` `==`：比较值，与 compare 等效





### 基本操作函数

 **参数表都有多种形式，但记住下面的就足够（语法都是用 ‘.’ 访问成员函数）：**

- clear：清空串

- empty：判断串是否为空（返回 bool ）

- back：返回最后一个字符

- front：返回第一个字符

- push_back：追加一个字符

- pop_back：从尾部弹出一个字符

- c_str：将 string 转化为 char[]（方便使用`<cstring> `中 string 未实现的库函数，如 strtok 、atoi 等）：

  ```c++
  char cs[N]; strcpy(cs,str.c_str());
  ```

  

- append（相当于 c-string 的 strcat ，但不用考虑预留内存 ）/ assign（相当于 c-string 的 strcpy ，但不用考虑预留内存 ） 都支持：

  ```c++
  (副串, 副串起点下标, 副串取用长度)//后两个参数可省
  ```

  insert 支持：

  ```c++
  (主串起点下标, 副串, 副串起点下标, 副串取用长度)//后两个参数可省
  ```

- erase 支持：

  ```
  (主串起点下标, 主串处理长度)
  ```

  replace 支持：

  ```c++
  (主串起点下标, 主串处理长度, 副串, 副串起点下标, 副串取用长度)//后两个参数可省
  ```

  substr 语法：

  ```c++
  string sstr=str.substr(主串起点下标, 主串取用长度);
  ```

- swap 语法：

  ```c++
  主串.swap(副串);
  ```

- find 语法（相当于 c-string 的 strstr）：

  ```c++
  size_t i=主串.find(子串, 第一次出现位置起点在主串中下标);//子串可以是string或char[]；i可以看成unsigned int，表示子串第一次出现在j开始主串中的首元素下标，若不存在则 i=nops（实际值为-1）
  ```

- rfind 语法（找最后一个匹配的位置）：

  ```c++
  size_t i=主串.find(子串, 最后一次出现位置起点在主串中下标);//子串可以是string或char[]；i可以看成unsigned int，表示子串第一次出现在j开始主串中的首元素下标，若不存在则 i=nops（实际值为-1）
  ```
  
- compare 语法（相当于 c-string 的 strcmp）:

  ```c++
  int flg=主串.compare(副串);//返回值规则与strcmp相同
  ```



***其他函数具体见 =》https://cplusplus.com/reference/string/string/?kw=string***





### 格式化函数



#### string 转数



##### 法1

**须包含`sstream`库**：

```c++
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    double x;
    string str;
    stringstream ss;
    cin >> str;//"3.14159"
    ss << str;//把str的值转化为字符串流输出到ss
    ss >> x;//3.14159（内存中为3.1415899999999999）
    //cout << x;(输出3.14159)
    return 0;
}
```



##### 法2

**须把 string 用 c_str 转化为 c-string，且包含 `<cstdlib>`库**；

只用记下面几个，其他的不用

- [**atof**](https://cplusplus.com/reference/cstdlib/atof/)

  Convert string to double (function)【只有一个 c-string 参数】, return `double`

- [**atoi**](https://cplusplus.com/reference/cstdlib/atoi/)

  Convert string to integer (function)【只有一个 c-string 参数】【只能以十进制识别】, return `int`

- [**atol**](https://cplusplus.com/reference/cstdlib/atol/)

  Convert string to long integer (function)【只有一个 c-string 参数】【只能以十进制识别】, return `long`

- [**atoll** ](https://cplusplus.com/reference/cstdlib/atoll/)

  Convert string to long long integer (function)【只有一个 c-string 参数】, return `long long`

- [**strtol**](https://cplusplus.com/reference/cstdlib/strtol/)

  Convert string to long integer (function) 【第二个参数是一个指针，不用管，填NULL，第三个参数为以什么进制识别字符串中的数字！！支持 2、10、16，默认为 10 ，填 0 则自动识别】, return `long`

- [**strtoul**](https://cplusplus.com/reference/cstdlib/strtoul/)

  Convert string to unsigned long integer (function)【第二个参数是一个指针，不用管，填NULL，第三个参数为以什么进制识别字符串中的数字！！支持 2、10、16，默认为 10 ，填 0 则自动识别】, return `unsigned long`

- [**strtoull** ](https://cplusplus.com/reference/cstdlib/strtoull/)

  Convert string to unsigned long long integer (function)【第二个参数是一个指针，不用管，填NULL，第三个参数为以什么进制识别字符串中的数字！！支持 2、10、16，默认为 10 ，填 0 则自动识别】, return `unsigned long long`

**转化失败（如无合法数字可识别）均返回 0 ！**

不要用`<string>`类的格式化函数！转化失败会报错！



#### 数转 string

```c++
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    double x;
    string str;
    stringstream ss;
    cin >> x;//3.14159（内存中为3.1415899999999999）
    ss << x;//把x的值转化为字符串流输出到ss
    ss >> str;//"3.14159"
    // cout << str;（输出"3.14159"）
    return 0;
}
```

