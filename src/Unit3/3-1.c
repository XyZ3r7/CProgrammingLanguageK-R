//
// Created by xyz3r7 on 5/18/26.
//

#include <stdio.h>
#include <time.h>   // 必须包含这个头文件

// 这里放你写的两个 binsearch 函数
int binsearch_old(int x, int v[], int n);
int binsearch_new(int x, int v[], int n);

#define SIZE 50000       // 数组大小
#define ITERATIONS 100000 // 循环查找的次数（让子弹飞一会儿）

int main() {
    int test_array[SIZE];
    int i;
    clock_t start_t, end_t;
    double total_t;

    // 1. 初始化一个递增的有序数组（二分查找的前提）
    for (i = 0; i < SIZE; i++) {
        test_array[i] = i * 2;
    }

    // ================= 测试老版本 =================
    start_t = clock(); // 掐表开始
    for (i = 0; i < ITERATIONS; i++) {
        // 故意查找各种各样的数（有的在数组里，有的不在，有的在中间）
        binsearch_old(i, test_array, SIZE);
    }
    end_t = clock();   // 掐表结束

    // 计算时间：结束时间 - 开始时间，再除以 CLOCKS_PER_SEC 转换成秒
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("老版本（两次判断）耗时: %f 秒\n", total_t);


    // ================= 测试新版本 =================
    start_t = clock(); // 重新掐表
    for (i = 0; i < ITERATIONS; i++) {
        binsearch_new(i, test_array, SIZE);
    }
    end_t = clock();   // 掐表结束

    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("新版本（一次判断）耗时: %f 秒\n", total_t);

    return 0;
}

int binsearch_old(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        }else if (x > v[mid]) {
            low = mid + 1;
        }else {
            return mid;
        }
    }
    return -1;
}

int binsearch_new(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;

    // 1. 循环条件改为了 low < high，不再是 low <= high
    while (low < high) {
        mid = (low + high) / 2;

        // 2. 循环内部只有这一个 if-else 判断
        if (x > v[mid]) {
            low = mid + 1;    // 目标在右半部分
        } else {
            high = mid;       // 目标在左半部分（或者 mid 就是目标）
        }
    }

    // 3. 循环结束后，low 和 high 碰头，此时做唯一一次等值检查
    if (x == v[low]) {
        return low;           // 找到了，返回下标
    } else {
        return -1;            // 没找到
    }
}