# interview02_06_回文链表

---

编写一个函数，检查输入的链表是否是回文的。

 

示例 1：

输入： 1->2
输出： false 
示例 2：

输入： 1->2->2->1
输出： true 
 

进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？


解题思路:

两种思路

method 1: array

运用数组， 存储再判断， 很浪费空间

T: O(N)

S: O(N)

method 2: double points

快慢指针分半， 前半头插法， 使之倒序

而后， 与后半比较即可， 注意奇数个处理

T: O(N)

S: O(1)

[src](https://leetcode-cn.com/problems/palindrome-linked-list-lcci/) <br>
[code](code/interview02_06.c) <br>
