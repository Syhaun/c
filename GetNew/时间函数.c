//clock()函数从程序启动以来的时钟周期数。
// 它不返回以秒为单位的实际时间，而是返回程序执行的时钟周期数。通常，clock()用于
// 测量执行的CPU时间,而不是实际经过的时间。要计算CPU时间,可以使用以下方法：
#include <stdio.h>
#include <time.h>

int main() {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    
    // 在这里执行你的代码

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("CPU time used: %f seconds\n", cpu_time_used);

    return 0;
}
