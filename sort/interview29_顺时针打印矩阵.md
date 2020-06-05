# interview29_顺时针打印矩阵

---

面试题29. 顺时针打印矩阵
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

 

示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：

输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 

限制：

0 <= matrix.length <= 100
0 <= matrix[i].length <= 100
注意：本题与主站 54 题相同：https://leetcode-cn.com/problems/spiral-matrix/

解题思路:

简单题， 模拟绕圈打印即可， 注意细节， 注意数组越界

T: O(N)

S: O(N)


[src](https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/) <br>
[code](code/interview29.c) <br>
