# Leetcode 54 螺旋矩阵
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

```
示例 1:
输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:
输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]
```
## 分析

首先考虑示例1中的矩阵，m=3,n=3

|返回值|col|row|
|--|--|--|
|1，2，3|0，1，2|2|
|6，9|2|1，2|
|8，7|1，0|2|
|4|0|1|
|5|1|1|

对于示例2中的矩阵，m=3,n=4

|返回值|col|row|
|--|--|--|
|1,2,3,4|0,1,2,3|3|
|8,12|3|1,2|
|11,10,9|2,1,0|2|
|5|0|1|
|6,7|1,2|1|

可以发现，每当遍历完一行或一列后，下次遍历时col（或row）的值保持不变，而row(或col)的值从上次遍历结束时的值减1（或加1）开始。
且随着遍历次数的增加，col(或row)的最小取值增大，最大取值减小。
因此，定义colstart、colend、rowstart、rowend四个变量，分别表示col和row取值范围的最小值和最大值，通过i来记录所读取的元素个数，以完成顺时针读取矩阵元素的操作。
最后，考虑输入为空的情况，在开始添加相应的if语句。
## 代码

``` C++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result = {};
        if (matrix.empty())
            return result;
        int col = matrix[0].size();
        int row = matrix.size();
        int colstart = 0, colend = col-1;
        int rowstart = 0, rowend = row-1;
        int total = col*row;
        int i = 0;

        while (i < total)
        {
            for (col = colstart; col <= colend; col++)
            {
                i++;
                result.push_back(matrix[rowstart][col]);
            }
            if (i >= total)
                break;
            rowstart++;
            for (row = rowstart; row <= rowend; row++)
            {
                i++;
                result.push_back(matrix[row][colend]);
            }
            if (i >= total)
                break;
            colend--;
            for (col = colend; col >= colstart; col--)
            {
                i++;
                result.push_back(matrix[rowend][col]);
            }
            if (i >= total)
                break;
            rowend--;
            for (row = rowend; row >= rowstart; row--)
            {
                i++;
                result.push_back(matrix[row][colstart]);
            }
            if (i >= total)
                break;
            colstart++;
        }
        return result;
    }
};
```

# Leetcode 59 螺旋矩阵Ⅱ
给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
```
示例:
输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
```
## 分析
这道题与上一道题的基本思路一样，可以直接将上面的代码稍作修改来完成。但是修改后的代码运行时间过长。
参考Leetcode给出的程序范例，分析如下：
由于生成矩阵的行和列数相等，除了在n等于奇数是矩阵中心只有一个数字外，每一圈逆时针循环可分为上、下、左、右四个方向。以n=3为例，每一圈循环分为4步，每一步的赋值如下：

|赋值|col|row|
|--|--|--|
|1,2|0,1|0|
|3,4|2|0,1|
|5,6|2,1|2|
|7,8|0|2,1|

对于一个n\*n的矩阵，不考虑矩阵中心的元素，共需要循环n/2次。并且循环中的四步按照
- col增加，row不变
- col不变，row增加
- col减少，row不变
- col不变，row减少

的顺序进行。
循环结束后，col和row指向循环开始时指向的第一个元素，只要分别对col和row进行加1操作，就可以指向下一圈循环中的第一个元素。而每循环一次，col和row的取值范围就会减小2。
最后考虑当n为奇数时，矩阵中心的元素一定为n\*n，因此可以在初始化时将矩阵的值初始化为n\*n。

## 代码
```C++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int cur = 1, len = n - 1, row = 0, col = 0;
        vector<vector<int>> res(n, vector<int>(n, n*n));
        for (int i = 0; i < n/2; ++i) {
            for (int j = 0; j < len; ++j)
                res[row][col++] = cur++;
            for (int j = 0; j < len; ++j)
                res[row++][col] = cur++;
            for (int j = 0; j < len; ++j)
                res[row][col--] = cur++;
            for (int j = 0; j < len; ++j)
                res[row--][col] = cur++;
            ++row;
            ++col;
            len -= 2;
        }
        return res;
    }
};
```
