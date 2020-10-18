# 第7周 学习总结
## 1. 高级搜索

### 1.1 初级搜索  
1. 朴素搜索
2. 优化方式：不重复、剪枝
3. 搜索方向  
__DFS：深度优先搜索__  
递归代码模板：
```
//C/C++
//递归写法：
map<int, int> visited;

void dfs(Node* root) {
  // terminator
  if (!root) return ;

  if (visited.count(root->val)) {
    // already visited
    return ;
  }

  visited[root->val] = 1;

  // process current node here. 
  // ...
  for (int i = 0; i < root->children.size(); ++i) {
    dfs(root->children[i]);
  }
  return ;
}
```

非递归代码模板：
```
//C/C++
//非递归写法：
void dfs(Node* root) {
  map<int, int> visited;
  if(!root) return ;

  stack<Node*> stackNode;
  stackNode.push(root);

  while (!stackNode.empty()) {
    Node* node = stackNode.top();
    stackNode.pop();
    if (visited.count(node->val)) continue;
    visited[node->val] = 1;


    for (int i = node->children.size() - 1; i >= 0; --i) {
        stackNode.push(node->children[i]);
    }
  }

  return ;
}
``` 
__BFS：广度优先搜索__
代码模板：
```
// C/C++
void bfs(Node* root) {
  map<int, int> visited;
  if(!root) return ;

  queue<Node*> queueNode;
  queueNode.push(root);

  while (!queueNode.empty()) {
    Node* node = queueNode.top();
    queueNode.pop();
    if (visited.count(node->val)) continue;
    visited[node->val] = 1;

    for (int i = 0; i < node->children.size(); ++i) {
        queueNode.push(node->children[i]);
    }
  }

  return ;
}
```    

4. 高级搜索  
__双向搜索__  
__启发式搜索__

### 1.2双向BFS
如果使用两个同时进行的广搜可以有效地减少搜索空间。一边从 beginWord 开始，另一边从 endWord 开始。我们每次从两边各扩展一个节点，当发现某一时刻两边都访问了某一顶点时就停止搜索。这就是双向广度优先搜索，它可以可观地减少搜索空间大小，从而降低时间和空间复杂度。

### 1.3 A*(启发式搜索) 
代码模板
```
class Node {
public:
    int x;
    int y;
    bool operator< (const Node &A) {
        // 
    }
};

void generate_related_nodes(Node &node) {
    // 
}

void process(Node &node) {
    // 
}

void AstarSearch(vector<vector<int>>& graph, Node& start, Node& end) {
    vector<vector<bool> > visited(graph.size(), vector<bool>(graph[0].size(), false));
    priority_queue<Node> q;
    q.push(start);

    while (!q.empty()) {
        Node cur = q.top();
        q.pop();
        visited[cur.x][cur.y] = true;


        process(node);
        vector<Node> nodes = generate_related_nodes(node) 
        for (auto node : nodes) {
            if (!visited[node.x][node.y]) q.push(node);
        }
    }

    return ;
}
```
## 2. 红黑树和AVL树
### 2.1 AVL总结
1. AVL是一种平衡二叉搜索树
2. 每个结点满足平衡因子
3. 有四种旋转操作
4. 不足：结点需要存储额外信息、且调整次数频繁


### 2.2 红黑树
__定义__：是一种近似平衡的二叉搜索树;能够确保任何一个结点的左右子树的高度差小于两倍  

满足条件
1. 每个结点要么是红色，要么是黑色
2. 根结点是黑色
3. 每个叶结点（NIL结点，空结点）是黑色的
4. 不能有相邻的两个红色结点
5. 从任一结点到其每个叶子的所有路径都包含相同数目的黑色结点
