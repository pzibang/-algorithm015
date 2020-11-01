# 动态规划复习

1、避免人肉递归
2、找到最简方法，拆分成最小子问题
3、数学归纳法

本质：寻找重复性——计算机指令集

## 动态规划
动态规划要点：
1. 将复杂问题拆分成更简单的最小子问题
2. 分治+最优子结构
3. 顺推模式：动态递推


# 字符串算法

## 高级字符串算法

## 字符串匹配算法
字符串匹配——暴力法——从暴力法中的优化：
1. rabin-karp 算法
    通过比较字符串中的hash与匹配字符串的hash加速枚举。
    2. KMP算法
    枚举字符串与匹配字符串的最大前后缀作为下一次比较的移动长度。
    
### 暴力法

暴力法模板：
```

//C/C++
int forceSearch(string text, string pattern) {
    int len_txt = text.length();
    int len_pat = pattern.length();

    for (int i = 0; i <= len_txt - len_pat; i++) {
        int j = 0;
        for (j = 0; j < len_pat; j++) {
            if (text[i + j] != pattern[j]) break;
        }
        if (j == len_pat) {
            return i;
        }
    }
    return -1;
}

```

###  rabin-karp 算法
简介：
![4aa3a5152044232b233986bd4e5d1262.png](en-resource://database/3445:1)
要点：
![0f499cc88873a961051612771aa1e998.png](en-resource://database/3447:1)

代码示例：
```

//C/C++
const int D = 256;
const int Q = 9997;

int RabinKarpSerach(string txt, string pat) {
    int M = pat.length();
    int N = txt.length();
    int i, j;
    int patHash = 0, txtHash = 0;

    for (i = 0; i < M; i++) {
        patHash = (D * patHash + pat[i]) % Q;
        txtHash = (D * txtHash + txt[i]) % Q;
    }
    int highestPow = 1;  // pow(256, M-1)
    for (i = 0; i < M - 1; i++) 
        highestPow = (highestPow * D) % Q;

    for (i = 0; i <= N - M; i++) { // 枚举起点
        if (patHash == txtHash) {
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j])
                    break;
            }
            if (j == M)
                return i;
        }
        if (i < N - M) {
            txtHash = (D * (txtHash - txt[i] * highestPow) + txt[i + M]) % Q;
            if (txtHash < 0)
                txtHash += Q;
        }
    }

    return -1;
}

```







