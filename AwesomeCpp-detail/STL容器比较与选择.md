

一、顺序容器
1. vector 可变大小数组，支持快速随机存取(时间复杂度为O(1))，查询时间复杂度是O(n)，插入\删除时间复杂度是O(n)，添加一个新元素后，可能需要重新分配内存，将所有元素赋值过去，然后清除原先内存，这个过程很耗时；
2. string 类似于vector的可变大小数组，只不过存的内容是字符，支持快速随机存取(时间复杂度为O(1))，查询时间复杂度是O(n)，插入\删除时间复杂度是O(n)；
3. deque 双端队列，支持快速随机存取(时间复杂度为O(1))，查询时间复杂度是O(n)，头部尾部插入\删除速度快(时间复杂度O(1))，中间插入\删除的时间复杂度是O(n)；
4. array 固定大小数组，定义时需要指定数组的大小，支持快速随机存取(时间复杂度O(1)),不支持插入\删除操作，查询时间复杂度是O(n)；
5. list 双向链表，支持双向顺序访问，任意位置插入\删除(知道目标节点指针时)时间复杂度是O(1)，但是查询时间复杂度是O(n)，不支持随机访问(因为内存是不连续的);
6. forward_list 单向链表，支持单向顺序访问，任意位置插入\删除(知道目标节点指针时)时间复杂度是O(1)，但是查询时间复杂度是O(n)，不支持随机访问;

二、顺序容器适配器
1. stack 栈，不支持快速随机存取(不支持下标访问)，无迭代器，不支持查询，头部插入\删除速度快(时间复杂度O(1))，访问顶部元素的时间复杂度是O(1),具有先进后出的特点；
2. queue 队列，不支持快速随机存取(不支持下标访问)，无迭代器，不支持查询，尾部插入\头部删除速度快(时间复杂度O(1))，访问顶部元素的时间复杂度是O(1),具有先进先出的特点；
3. priority_queue 优先队列(头文件queue)，不支持快速随机存取(不支持下标访问)，无迭代器，不支持查询，本质是大顶堆或者小顶堆，插入删除时间复杂度是O(logn),访问顶部元素的时间复杂度是O(1)；


三、关联容器
1. set 由红黑树实现，其内部元素依照其值自动排序，每个元素只出现一次，不允许重复(红黑树是平衡二叉树的一种)，增删改查近似：O(log n)
	1）元素有序  2）无重复元素 3）插入删除操作的效率比序列容器高，因为对于关联容器来说，不需要做内存的拷贝和内存的移动
2. map由红黑树实现，其元素都是键值对，每个元素的键是排序的准则，每个键只能出现一次，不允许重复，增删改查基本是O(log N)
3. unordered_set 用哈希函数组织的set，unordered版本的map和set只提供前向迭代器（非unorder版本提供双向迭代器）
   对于unordered_set，insert/find/erase的平均复杂度是O(1), 但是最坏情况下插入删除查询的时间复杂度是O(N)的，这里N是指容器中元素数
   有两种情况会出现O(N)复杂度。
   1)是你的哈希函数太烂了，导致很多不同key元素的哈希值都相同，全是碰撞，这种情况复杂度会变成O(N)。但是这种情况一般不用担心，因为对于string以及int double之类的基本数据类型，都有默认的哈希函数，而且默认的哈希函数足够好，不会退化到O(N)。如果是你自定义的哈希函数，那你要小心一点，别写的太差了。
   2)是如果insert很多数据，会触发rehash。就是整个哈希表重建。这个过程有点类似向vector里不断添加元素，vector会resize。比如你新建一个vector时，它可能只申请了一块最多保存10个元素的内存，当你插入第11个元素的时候，它会自动重新申请一块更大空间，比如能存下20个元素。哈希表也是类似，不过rehash不会频繁发生，均摊复杂度还是O(1)的，也不用太担心。
4. 对于unordered_map，基于hash table实现，insert/find/erase的平均复杂度是O(1)，但是最坏情况下插入删除查询的时间复杂度是O(N)的
