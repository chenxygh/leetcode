# interview53_I_在排序数组中查找数字_I

---

统计一个数字在排序数组中出现的次数。

 

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: 2
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: 0
 

限制：

0 <= 数组长度 <= 50000

 

注意：本题与主站 34 题相同（仅返回值不同）：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/


解题思路:

二分查找

找到后，向左向右统计即可

当然，第一次想到的是，找到 target 最左端出现的位置，然后向右统计

实际上，这是没有必要的，无论在哪个位置找到，直接向左向右统计即可


[src](https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/) <br>
[code](code/interview53_I.c) <br>
