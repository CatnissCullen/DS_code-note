# c++ STL



## 函数

### 数学

-   **`numeric_limits<T>::<max()|min()>`** ：**`T`** 型的**最值** 

### 容器

-   **`std::find(it1, it2, val)`** ：（没啥用） 查找 **`it1`** 到 **`it2`** 间值为 **`val`** 的第一个元素并返回其位置处迭代器，**`it1`** 和 **`it2`** 为迭代器 

    ```c++
    #include<algorithm>;
    ```

-   **`.swap(c)`** ：交换容器和另一同类型容器的元素序列以及所有指针、迭代器和大小属性

-   **`std::swap(c1, c2)`** ：**`.swap`** 的优化，通过只交换变量名来交换两个对象的内容（更快）

-   **`std::reverse(str.begin(), str.end());`**

    ```
    #include<algorithm>;
    ```

-   **`std::sort(first, last)`** ：默认的升序排序，**`first`** 和 **`last`** 为迭代器

-   **`std::sort(first, last, cmp)`** ：

    ```
    #include<algorithm>;
    ```

    ```c++
    bool cmp(const <T> &a, const <T> &b) {
        return a > b;  // 降序
    }
    ```

-   



## 容器 & string

>   ***c++ 没有容器 String ！！！*** 

### 概述 

-   **vector**：可变数组/ 倍增思想
-   **string**：字符串/ substr()返回子串/ c_str返回对应字符型数组头指针 
-   **queue**：普通队列/ push()从队尾入队/ front()获取队头/ pop()从队头出队
-   **priority_queue**：堆（优先队列）/ push()插入堆/ top() 获取堆顶/ pop()弹出<u>堆顶</u>
-   **stack**：栈/ push()从栈顶入栈/ top()获取栈顶/ pop()从栈顶出栈
-   **deque**：双端队列/ 队头队尾都可入队出队/ 可随机访问
-   **set, map, multiset, multimap**：有序集（键有序）/ 基于**平衡二叉树（红黑树，特殊的平衡二叉树）**/ 动态维护
-   **unordered_set, unordered_map, unordered_multiset, unordered_multimap**： 无序集/ 基于**哈希表**（查找/插入/删除快于且存储空间小于 set, map, multiset, multimap）
-   **bitset**：压位（进制存储）



### 注意点

-   用 for all 循环要**用引用**才能改变元素值
-   erase() 前必须**判断是否空**，erase() 后下标注意不要多移动
-   string 和 vector/ map 的 **erase 语法不同**，vector/ map 参数为迭代器；vector 的 erase 返回值为被删除部分的下一元素迭代器或 .end()
-   queue、stack 都**不支持迭代器和索引取值**，queue 只能取 front() 和 back()，stack 只能取 top() ；不支持 clear()；进出都是 push() 和 pop()，而 string 和 vector 是 push_back()、pop_back()
-   map 和 unordered_map **都不允许有重复键**；map 默认按键升序排序（可在定义时传入自定义比较函数进行自定义的键排序；不能按值排序）；multi_map 允许有重复键
-   list 是链表，没有索引功能，**不能用索引随机访问（常数时间）**，只能用迭代器线性访问（线性时间）
-   list 、 set  、各种 map 都是非线性存储，不能用索引遍历，**可以用迭代器遍历** 



### 比较符

#### 对 String、Vector 的支持

-   **`==`** ：**`.size()`** 相等且从左到右各元素相等时返回 **`true`** ，否则 **`false`**
-   **`<`** ：从左到右**存在索引对应**元素符合 **`<`** 时返回 **`true`** ，否则 **`false`**

*其他比较符同理*

#### 对 Map 、 Multimap 、 UnorderedMap 都不支持！ 

>   **只能取出键/ 值分别比较**



### 大小控制

#### 对 string、Vector 的支持

-   **`.size()`** ：元素个数
-   **`.capacity()`** ：当前已分配的容量，可用 **`.reserve()`** 显式改变，否则就是目前已系统分配的或显式分配的容量
-   **`.maxsize()`** ：当前内存中允许扩充到的最大容量，即允许 **`.reserve()`** 到的最大容量 
-   **`.empty()`** ：等价于 **`return <vec/str>.size()==0`** 
-   **`.reserve((int) s)`** ：当 **`s`** > **`.maxsize()`** ，抛出异常；当 **`.maxsize()`** >  **`s`** > **`.capacity()`** ，扩充 **`.capacity()`** 至 **`s`** ；当 **`.capacity()`** > **`s`** ，不做任何改变
-   **`.shrink_to_fit()`** ：减小 **`.capacity()`** 至 **`.size()`**

#### 对 Map 、 Multimap 、 UnorderedMap 的支持

-   **`.size()`** ：元素个数
-   ***没有 `.capacity` 和 `.reserve` ！*** 
-   **`.maxsize()`** ：当前内存中允许扩充到的最大容量，即允许 **`.reserve()`** 到的最大容量 



### 随机访问和遍历

#### 索引

##### 对 string、Vector 的支持

>   **线性存储，索引可用于随机访问 & 遍历**

-   **`[]`** ：索引越界时不抛出异常（越界时是未定义索引）
-   **`.at((int) i)`** ：**`i`** 越界时抛出异常
-   **`.front()`** ：首元素的直接引用；在 **`.empty()`** 为 **`true`** 时为未定义引用
-   **`.back()`** ：尾元素的直接引用；在 **`.empty()`** 为 **`true`** 时为未定义引用
-   **`.data()`** ：指向首元素的指针

##### 对 Map 、 Multimap 、 UnorderedMap 的支持

>   ***可用于随机访问；不能用于遍历，因为不是线性存储***

-   **`[]`** ：索引越界时不抛出异常（越界时是自动构造这个新元素，即便没有赋值）
-   **`.at((int) i)`** ：**`i`** 越界时抛出异常

##### 对 List 的支持

>   ***不支持！既不能随机访问也不能遍历***

****

#### 迭代器

>   **定义方式要带上容器类型！因为迭代器是容器对象的 iterator 属性！！**

```c++
map<<T1>, <T2>>::iterator it;
```

>   **迭代器相当于指针，解析值用 ' \* '**  

```c++
pair<T1, T2> myPair = *it; // map 的迭代器
<T1> map_key = myPair.first;
<T2> map_value = myPair.second;
```

>     **迭代器相当于结构体指针，可直接通过成员指针解析成员值**

```c++
<T1> map_key = it->first；
<T2> map_value = it->second;
```

##### 对 string、Vector 的支持

>   ***容器连续存储，迭代器的遍历效果与索引一样（遍历本身就是线性时间的操作）***

-   **`.begin()`** ：指向首元素的迭代器，方向为顺向
-   **`.end()`** ：指向尾元素的**后一个虚空元素**的迭代器，方向为顺向
-   **`.rbegin()`** ：指向尾元素的迭代器，方向为逆向
-   **`.rend()`** ：指向首元素的**前一个虚空元素**的迭代器，方向为逆向

##### 对 List、Set、各种 Map的支持

>   ***容器非连续存储，索引不支持遍历，可使用迭代器遍历*** 

```c++
for (map<<T1>, <T2>>::iterator it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }  

```

****

#### 范围 for 循环

>   **支持任何容器的遍历**

```c++
for (item_variable: range){  // range 支持任何容器、数组、string
	...
}
```

***不修改元素：***

```c++
for (const auto pair : myMap) {
	...
}
```

**可修改元素：**

```c++
for (const auto& pair : myMap) {  // 引用！！
	...
}
```





### 修改器

#### 彻底释放容器

**以释放 Vector `vec` 举例** 

```c++
vector<T>().swap(vec);
```

#### 对 String、Vector 的支持

##### 赋值

-   **`=`** ：替换整个元素序列（改变 **`.size()`** ，超过当前 **`.capacity()`** 会自动扩充）
    -   **`= (<vector<T>/str>) x`** ：将 **`=`** 的右值 **`x`** 复制一份赋值给 **`<vec/str>`** 【深拷贝】 
    -   **`= a`** ：将数组 **`a`** 的元素序列作为初始化列表赋值给整个 **`<vec/str>`**
        -   对于 **`vec`** ， **`T a[N]={(T)..., (T)..., (T)...}`** 
        -   对于 **`str`** ，**`a`** 应是一个字符串字面量
-   **`.assign`** ：替换整个元素序列（改变 **`.size()`** ，超过当前 **`.capacity()`** 会自动扩充）
    -   **`.assign((InputIterator) first, (InputIterator) last)`** ：**`first`** 和 **`last`** 是另一个 **`<vector/string>`** 的前后两个迭代器，取该 **`<vector/string>`** 在 [**`first`, `last`**) 范围内的元素序列赋值给整个 **`<vec/str>`** 
    -   **`.assign((int) n, (<T/char>) val)`** ：将 **`n`** 个 **`val`** 的元素序列赋值给整个 **`<vec/str>`** 
    -   **`.assign(a)`** ：将数组 **`a`** 的元素序列作为初始化列表赋值给整个 **`<vec/str>`** 
        -   对于 **`vec`** ， **`T a[N]={(T)..., (T)..., (T)...}`** 
        -   对于 **`str`** ，**`a`** 应是一个字符串字面量或另一个 **`string`**

##### 增减

-   **`.push_back((T) val)`** ：压入 **`val`** 元素到当前尾元素后方（改变 **`.size()`** ，超过当前 **`.capacity()`** 会自动扩充，**`.end()`** 和 **`.back()`** 自动更新） 
-   **`.pop_back()`** ：弹出当前尾元素（改变 **`.size()`** ，不改变**`.capacity()`** ，**`.end()`** 和 **`.back()`** 自动更新） 
-   **`.insert`** ：插入**已构造好对象**的元素/ 元素序列（改变 **`.size()`** ，超过当前 **`.capacity()`** 会自动扩充），先复制对象后插入，**返回指向插入元素（序列）的首元素的迭代器**
    -   **`.insert((Iterator) it, (<T/char>) val)`** ：在 **`it`** 迭代器处插入 **`val`**
    -   **`.insert((Iterator) it, (int) n, (<T/char>) val)`** ：在 **`it`** 迭代器处插入 **`n`** 个 **`val`**
    -   **`.insert((Iterator) it, (InputIterator) first, (InputIterator) last)`** ：**`first`** 和 **`last`** 是另一个 **`<vector/string>`** 的前后两个迭代器，在 **`<vec/str>`** 的 **`it`** 迭代器处插入另一个 **`<vector/string>`** 在 [**`first`, `last`**) 范围内的元素序列
    -   **`.insert((Iterator) it, a)`** ：将数组 **`a`** 的元素序列作为初始化列表插入到 **`it`** 迭代器处
        -   对于 **`vec`** ， **`T a[N]={(T)..., (T)..., (T)...}`** 
        -   对于 **`str`** ，**`a`** 应是一个字符串字面量或另一个 **`string`**
-   **`.erase`** ：抽除元素/ 元素序列（改变 **`.size()`** ，不改变**`.capacity()`** ）
    -   **`.erase((Iterator) it)`** ：抽除 **`it`** 迭代器处元素
    -   **`.erase((Iterator) first, (Iterator) last)`** ：**`first`** 和 **`last`** 是 **`<vec/str>`** 的前后两个迭代器，抽除 **`<vec/str>`** 在 [**`first`, `last`**) 范围内的元素序列
-   **`.clear()`** ：清空所有元素（改变 **`.size()`** ，不改变**`.capacity()`** ）

***此外 `string` 的 `insert` 和 `erase` 还支持索引参数*** 

#### 对 Map 的支持

-   **`.erase((T1) key)`** ：抽除键为 **`key`** 的元素（改变 **`.size()`** ，不改变**`.capacity()`** ）




### string

```c++
#include <string>
string str;
```

#### 输入输出

-   **`cin`** ：以空格为结束符读入（读入一个词）
-   **`getline`** ：以换行符为结束符读入（读入一整行）

-   **`cout`** ：输出任意内容

#### 和数的转换

-   **`to_string((int)num)`** ：整数转化为 **`string`**
-   **`stoi(str)`** ：**`str`** 转化为整数

#### 子串操作

-   **`.find((string) substr)`** ：在 **`str`** 中寻找子串 **`substr`** ，找到时返回其起始索引，否则返回 **`npos`** 
-   **`.substr((int) pos, (int) len)`** ：返回 **`str`** 中从 **pos** 处起长为 **`len`** 的子串

#### 修改器

>   ***（除公共修改器外）***

##### 增减

-   **`+`** ：拼接单个字符或 **`string`** 或 **char\*** （字符数组），返回新的一个字符串而不改变 **`str`**
-   **`.append()`**：在字符串末尾添加 **`string`** 或 **char\*** （字符数组），在 **`str`** 上修改并返回新 **`str`** 的引用
-   **`.insert`** ：**除迭代器外还支持索引** 
    -   **`.insert((int) pos, (string) s)`** ：在 **`pos`** 处插入 **`s`**
    -   **`.insert((int) pos, (string) other_str, (int) other_pos, (int) other_sublen)`** ：在 **`pos`** 处插入 **`other_str`** 从 **`other_pos`** 处起长 **`other_sublen`** 的子串
    -   **`.insert((int) pos, (int) n, (char) ch)`** ：在 **`pos`** 处插入 **`n`** 个 **`ch`** 
-   **`.erase`** ：**除迭代器外还支持索引** 
    -   **`.erase((int) pos, (int) n)`** ：删除 **`pos`** 处起的 **`n`** 个字符
    -   **`.erase((int) pos)`** ：删除 **`pos`** 处起剩下的所有字符

##### 替换

**`.replace((int)pos, (int)len, (string)s)`**：在 **`pos`** 处起把长 **`len`** 的子串替换为字符串 **`s`**



### Vector

```c++
#include <vector>
vector<T> vec;
```

#### 修改器

***除公共修改器外***

##### 增减

-   **`.emplace((Iterator) it, <args>)`** ：在 **`vec`** 中的 **`it`** 迭代器处就地创建元素/ 元素序列对象以插入，没有复制对象操作；**`args`** 可以是 {**`{(InputIterator) first, (InputIterator) last}`, `(T[]) a`, `(T) val`**} （改变 **`vec`** 的 **`.size()`** ，超过当前 **`.capacity()`** 会自动扩充）
-   **`.emplace_back(<args>)`** ：在 **`vec`** 中的 **`.end()`** 迭代器处就地创建元素/ 元素序列对象以插入，没有复制对象操作；**`args`** 可以是 {**`{(InputIterator) first, (InputIterator) last}`, `(T[]) a`, `(T) val`**} （改变 **`vec`** 的 **`.size()`** ，超过当前 **`.capacity()`** 会自动扩充）



### Map

#### 查找

**`.find((T1) key)`** ：查找是否有等于 **`key`** 的键，否则返回 **`.end()`** ，是则返回对应键值对的迭代器



### Multimap

#### 计数

**`.count((T1) key)`** ：返回键 **`key`** 出现的次数 
