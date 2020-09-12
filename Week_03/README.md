
# 学习总结
## 1. 泛型递归与树的递归
### 1.1 递归代码模板：

```
// C/C++
void recursion(int level, int param) { 
  // recursion terminator
  if (level > MAX_LEVEL) { 
    // process result 
    return ; 
  }
  // process current logic 
  process(level, param);
  // drill down 
  recursion(level + 1, param);
  // reverse the current level status if needed
}
```

### 1.2 思维要点
1、不要进行人肉递归（最大的误区）  

2、找到最近最简方法，将其拆解成可重复解决的问题（重复子问题）

3、数学归纳法思维


### 1.3 括号生成
括号生成解题思路
![ef94ba96cbc472d3a0a10d070a0399c4.png](en-resource://database/2488:1)


## 2.分治与回溯

### 2.1 分治代码模板:
```
int divide_conquer(Problem *problem, int params) {
  // recursion terminator
  if (problem == nullptr) {
    process_result
    return return_result;
  } 
  // process current problem
  subproblems = split_problem(problem, data)
  subresult1 = divide_conquer(subproblem[0], p1)
  subresult2 = divide_conquer(subproblem[1], p1)
  subresult3 = divide_conquer(subproblem[2], p1)
  ...
  // merge
  result = process_result(subresult1, subresult2, subresult3)
  // revert the current level status
 
  return 0;
}
```
### 2.2 回溯
&emsp;回溯法采用试错的思想，它尝试分步的去解决一个问题。在分步解决问题的过程中，当它通过尝试发现现有的分步答案不能得到有效的正确的解答的时候，它将取消上一步甚至是上几步的计算，再通过其他的可能的坑的分步解答再次尝试寻找问题的答案。
&emsp;回溯法通常用最简单的递归方法来实现，在反复重复上述的步骤可能出现两种情况：
>找到一个可能存在的正确的答案；  
>在尝试了所有可能的分步方法后宣告该问题没有答案。

在最坏的情况下，回溯法会导致一次复杂度为指数时间的计算。
