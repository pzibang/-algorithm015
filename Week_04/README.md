

# 学习总结

## 1.深度优先搜索和广度优先搜索
&emsp;问题产生：在搜索遍历树或图结构时，每个节点都要访问一次，且仅访问一次。
&emsp;对节点的访问顺序不同，分为深度优先和广度优先。

### 1.1 深度优先搜索模板
深度优先搜索：Depth-First-Search，简称是DFS。
#### 1.1.1 递归模板
```
map<int, int> visited;

void dfs(Node* root) {
  // terminator
  if (!root) return ;

  if (visited.count(root->val)) {
    // already visited
    return ;
  }

  visited[root->val] = 1;

  // process current node here. 
  // ...
  for (int i = 0; i < root->children.size(); ++i) {
    dfs(root->children[i]);
  }
  return ;
}
```
#### 1.1.2 非递归模板
```
void dfs(Node* root) {
  map<int, int> visited;
  if(!root) return ;

  stack<Node*> stackNode;
  stackNode.push(root);

  while (!stackNode.empty()) {
    Node* node = stackNode.top();
    stackNode.pop();
    if (visited.count(node->val)) continue;
    visited[node->val] = 1;


    for (int i = node->children.size() - 1; i >= 0; --i) {
        stackNode.push(node->children[i]);
    }
  }

  return ;
}
```
### 1.2 广度优先搜索
&emsp;广度优先搜索：Breadth-First-Search，简称是BFS。

### 1.2.1广度优先搜索模板

```
void bfs(Node* root) {
  map<int, int> visited;
  if(!root) return ;

  queue<Node*> queueNode;
  queueNode.push(root);

  while (!queueNode.empty()) {
    Node* node = queueNode.top();
    queueNode.pop();
    if (visited.count(node->val)) continue;
    visited[node->val] = 1;

    for (int i = 0; i < node->children.size(); ++i) {
        queueNode.push(node->children[i]);
    }
  }

  return ;
}
```

## 2.贪心算法
&emsp;概念：贪心算法是一种在每一步中都采取在当前状态下最好或最优（即最有利）的选择，从而希望导致结果是全局最好或最优的算法。


&emsp;存在缺陷：子问题最优解，对于整个问题的解并不是最优的解。

## 3.二分查找
&emsp;概念：

&emsp;二分查找的前提：
>1、目标函数单调性（单调递增或单调递减）；
2、存在上下界；（bounded）
3、能够通过索引访问。（index accessible）

&emsp;实现模板
```
int binarySearch(const vector<int>& nums, int target) {
  int left = 0, right = (int)nums.size()-1;
  
  while (left <= right) {
    int mid = left + (right - left)/ 2;
    if (nums[mid] == target) return mid;
    else if (nums[mid] < target) left = mid + 1;
    else right = mid - 1;
  }
  
  return -1;
}
```


## 3.课后作业
要求：
>使用二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方  
```
#includ
