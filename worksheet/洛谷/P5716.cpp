#include <iostream>

using namespace std;
bool isbig(int m){
    int month[7]={1,3,5,7,8,10,12};
    for(int i=0; i < 7; i++){
        if(m == month[i]){
            return 1;
        }
    }
    return 0;
}

int main(void){
    int y,m;

    cin >> y >> m;

    if(y >= 1582 && y <= 2020 && m >= 1 && m <= 12){
        if((y % 4 == 0 && y % 100 != 0) ||( y % 100 == 0 && y % 400 == 0)){
            if(m == 2){
                cout << "29";
            }else if(isbig(m)){
                cout << "31";
            }else{
                cout << "30";
            }
        }else{
             if(m == 2){
                cout << "28";
            }else if(isbig(m)){
                cout << "31";
            }else{
                cout << "30";
            }
        }
    }
        
    return 0;
}



/* AI改错记录
# P5716 · isbig 函数里 `return 0;` 的位置

> 现象：输入 `1926 8`，输出 `30`（8 月是大月，应为 31）。
> 原因：`return 0;` 还留在 `for` 循环体内，函数在第一轮就返回了。

## 1. 错误写法

```cpp
int isbig(int m) {
    int month[7] = {1, 3, 5, 7, 8, 10, 12};
    for (int i = 0; i < 7; i++) {
        if (m == month[i]) {
            return 1;
        }
        return 0;      // ← 问题在这里，它在 for 里面
    }
}
```

执行过程（m = 8）：

```
i = 0  →  month[0] = 1，8 != 1
       →  走到 return 0，函数结束
i = 1、2…… 一次都没执行
```

于是 `isbig` 永远只回答「m 是不是 1」：
- `m == 1` → 返回 1，输出 31
- 其它月份 → 返回 0，全部按 30 处理（二月另有分支）

所以 `1926 8` 输出 30。验证方法：输入 `1926 1`，它能输出 31，其余大月全灭。

## 2. 正确写法

```cpp
int isbig(int m) {
    int month[7] = {1, 3, 5, 7, 8, 10, 12};
    for (int i = 0; i < 7; i++) {
        if (m == month[i]) {
            return 1;          // 找到了，立刻返回
        }
    }
    return 0;                  // 循环全部跑完再返回，位置在 for 外面
}
```

对比两版只差一层大括号，语义差很多：

| 位置 | 含义 |
| --- | --- |
| `return 0;` 在 `for` 内 | 第一条不匹配就直接放弃，只检查了 `month[0]` |
| `return 0;` 在 `for` 外 | 七个数全扫完仍没有，才判定不是大月 |

## 3. 判断口诀

> `return` 出现在哪一层，程序的执行就在哪一层被掐断。
> 循环里的 `return` 是「提前收工」，循环外的 `return` 是「扫完再说」。

写找东西的函数时，可以这样摆结构：

```
for (...) {
    if (找到) return 1;   // 提前收工
}
return 0;                 // 一个都没找到
```

这个骨架几乎适用于所有「在一组东西里找某项」的题，翻书、查表、找下标都是它。

## 4. 顺手一提：也可以用 break + flag

不想在循环里 `return`，就用标志位：

```cpp
int isbig(int m) {
    int month[7] = {1, 3, 5, 7, 8, 10, 12};
    int flag = 0;
    for (int i = 0; i < 7; i++) {
        if (m == month[i]) {
            flag = 1;
            break;
        }
    }
    return flag;
}
```

`break` 只跳出循环，函数继续往下跑，最后统一 `return`。两种都行，`return 1` 更短。

## 5. 更省事的替代（查表法）

不用判断大月小月，直接给出每月天数：

```cpp
int md[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int d = md[m];
if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))) d = 29;
cout << d;
```

## 6. 完整可交版本

```cpp
#include <iostream>
using namespace std;

int isbig(int m) {
    int month[7] = {1, 3, 5, 7, 8, 10, 12};
    for (int i = 0; i < 7; i++) {
        if (m == month[i]) return 1;
    }
    return 0;
}

int main(void) {
    int y, m;
    cin >> y >> m;

    if (m == 2) {
        if ((y % 4 == 0 && y % 100 != 0) || (y % 100 == 0 && y % 400 == 0))
            cout << 29;
        else
            cout << 28;
    } else if (isbig(m)) {
        cout << 31;
    } else {
        cout << 30;
    }
    return 0;
}
```

## 7. 自测用例

| 输入 | 期望输出 | 覆盖点 |
| --- | --- | --- |
| 1926 8 | 31 | 大月 |
| 1926 1 | 31 | 数组第一个元素 |
| 1926 12 | 31 | 数组最后一个元素 |
| 1926 4 | 30 | 小月 |
| 2000 2 | 29 | 400 的倍数 |
| 1900 2 | 28 | 100 的倍数但不是 400 |
| 1926 2 | 28 | 普通闰年判断失败 |
*/