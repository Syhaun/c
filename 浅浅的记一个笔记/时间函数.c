//clock()�����ӳ�������������ʱ����������
// ������������Ϊ��λ��ʵ��ʱ�䣬���Ƿ��س���ִ�е�ʱ����������ͨ����clock()����
// ����ִ�е�CPUʱ��,������ʵ�ʾ�����ʱ�䡣Ҫ����CPUʱ��,����ʹ�����·�����
#include <stdio.h>
#include <time.h>

int main() {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    
    // ������ִ����Ĵ���

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("CPU time used: %f seconds\n", cpu_time_used);

    return 0;
}
