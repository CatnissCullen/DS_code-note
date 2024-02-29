# c++ STL





## 写在前面



-   **vector**：可变数组/ 倍增思想
-   **string**：字符串/ substr()返回子串/ c_str返回对应字符型数组头指针
-   **queue**：普通队列/ push()从队尾入队/ front()获取队头/ pop()从队头出队
-   **priority_queue**：堆（优先队列）/ push()插入堆/ top() 获取堆顶/ pop()弹出<u>堆顶</u>
-   **stack**：栈/ push()从栈顶入栈/ top()获取栈顶/ pop()从栈顶出栈
-   **deque**：双端队列/ 队头队尾都可入队出队/ 可随机访问
-   **set, map, multiset, multimap**：有序集（键有序）/ 基于**平衡二叉树（红黑树，特殊的平衡二叉树）**/ 动态维护
-   **unordered_set, unordered_map, unordered_multiset, unordered_multimap**： 无序集/ 基于**哈希表**（查找/插入/删除快于且存储空间小于 set, map, multiset, multimap）
-   **bitset**：压位（进制存储）



## 注意点

-   用 for all 循环要**加上引用**才能改变元素值
-   erase() 前必须**判断是否空**，erase() 后下标注意不要多移动
-   string 和 vector/ map 的 **erase 语法不同**，vector/ map 参数为迭代器；vector 的 erase 返回值为被删除部分的下一元素迭代器或 .end()
-   queue、stack 都**不支持迭代器和索引取值**，queue 只能取 front() 和 back()，stack 只能取 top() ；不支持 clear()；进出都是 push() 和 pop()，而 string 和 vector 是 push_back()、pop_back()
-   map 和 unordered_map **都不允许有重复键值**
