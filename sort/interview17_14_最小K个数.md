# interview17_14_最小K个数

---

设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。

示例：

输入： arr = [1,3,5,7,2,4,6,8], k = 4
输出： [1,2,3,4]
提示：

0 <= len(arr) <= 100000
0 <= k <= min(100000, len(arr))


解题思路:

method 1: heap sort

建立小根堆， 找到前 k 个即可

前 k 个， 速度较快， 大概时间复杂度可到 O(N)， 实际： 80 ms / 13.8 MB

T: O(N)

S: O(1)


method 2: quick sort

快排， 题目不要求前 k 个有序， 所以快排的 partition 比较适合

速度快， 实际： 68 ms / 13.3 MB

T: O(N)

S: O(1)


[src](https://leetcode-cn.com/problems/smallest-k-lcci/) <br>
[code](code/interview17_14.c) <br>
