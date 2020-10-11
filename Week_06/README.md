
# 学习总结
## 1. 递归模板
```
// C/C++
void recursion(int level, int param) { 
  // recursion terminator
  if (level > MAX_LEVEL) { 
  // process result 
    return ; 
  }

  // process current logic 
  process(level, param);

  // drill down 
  recursion(level + 1, param);

  // reverse the current level status if needed
}

```

## 2. 分治模板
```

C/C++
int divide_conquer(Problem *problem, int params) {
  // recursion terminator
  if (problem == nullptr) {
    process_result
    return return_result;
  } 

  // process current problem
  subproblems = split_problem(problem, data)
  subresult1 = divide_conquer(subproblem[0], p1)
  subresult2 = divide_conquer(subproblem[1], p1)
  subresult3 = divide_conquer(subproblem[2], p1)
  ...

  // merge
  result = process_result(subresult1, subresult2, subresult3)
  // revert the current level status
 
  return 0;
}
```
## 3. 使用递归的思维方式

1. 人肉递归是低效的
2. 找到最近最简的方法，将其拆解成可重复解决的问题
3. 数学归纳法的思维（利用归纳，而不是手动展开递归）

计算机算法的本质：寻找问题中存在的重复性；计算机只能判断某个语句是真或假，或者是执行重复的循环。

## 4. 动态规划
### 4.1 规划定义

将一个复杂的问题拆分成多个简单的子问题（用递推的方式）

动态规划= 分治+最优子结构

三个关键点

1. 动态规划和递归或者分治没有根本上的区别（区别主要在有无最优子结构）
2. 共性：找到重复子问题
3. 差异：最优子结构、中途可淘汰次优解

### 4.2典型题目
#### 4.2.1Fibonacci数列

Fibonacci数列的定义：
F(0)=0，F(1)=1，F(2)=1, F(n)=F(n - 1)+F(n - 2)（n ≥ 3，n ∈ N* ）

##### 递归
傻递归（不作任何处理）
```
class Solution {
public:
    int fib(int N) {
        if(N <= 0){
            return 0;
        }
        else if(N == 1){
            return 1;
        }
        else{
            return fib(N - 1) + fib(N - 2);
        }
    }
};

```

##### 迭代

```
class Solution {
    public int fib(int N) {
        if (N <= 1) {
            return N;
        }
        if (N == 2) {
            return 1;
        }

        int current = 0;
        int prev1 = 1;
        int prev2 = 1;

        for (int i = 3; i <= N; i++) {
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return current;
    }
}

```

##### 动态规划
对结果进行存放，已经计算过的不进行递归计算
```
int fib(int N, int memo[]) {
     if (N <= 0){
         return 0;
     }

     else if (N == 1){
         return 1;
     }

     else if (memo[N] == 0){
         memo[N] = fib(N - 1, memo) + fib(N - 2, memo);
     }

     return memo[N];
}

```

#### 4.2.2 路径计数
解题思路：
1、避免人肉递归，从最简单的问题入手：假设棋盘上没有障碍物，棋盘大小为1x1,2x2,3x3，4x4...等比较简单的情形。
2、利用数学归纳法，从简单情形，找到最小子问题。起始位置到目标位置的走法为N，起始位置的下一步有X种走法，这X种走法的位置到目标位置的走法相加即是N，将问题拆解成：下一步到目标位置的走法有多少种。
3、从递推的方式获得结果，好处是可以知道每一步的走法有多少种。
状态转移方程（DP方程）
```
opt[i, j] = opt[i+1, j] + opt[i, j+1]
完整逻辑：
if a[i, j] = '空地':
    opt[i, j] = opt[i+1, j] + opt[i, j+1]
else:
    opt[i, j] = 0
```
#### 动态规划关键点
1、最优子结构 opt[n] = best_of(opt[n -1], opt[n -2], ...)
2、储存中间状态：opt[i]
3、递推公式（状态转移方程或DP方程）
Fib: opt[i] = opt[n-1] + opt[n-2]
二维路径：   opt[i, j] = opt[i+1, j] + opt[i, j+1] （且判断a[i][j]是否为空地）









