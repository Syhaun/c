#define _CRT_SECURE_NO_WARNINGS 1
#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct PeoInfo
{
    char name[MAX_NAME];
    int age;
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
};
enum Option
{
    EXIT,
    ADD,
    DEL,
    SEARCH,
    MODIFY,
    SHOW,
};
// 通讯录类型
struct Contanct
{
    struct PeoInfo date[MAX]; // 存放一个信息
    int size;                 // 记录当前已有元素个数
};
// 初始化通讯录的函数
void InitContact(struct Contanct *ps);
// 增加一个信息到通讯录
void AddContact(struct Contanct *ps);
// 打印通讯录的信息
void ShowContanct(const struct Contanct *ps);
// 删除指定的联系人
void DelContact(struct Contanct *ps);
// 查找指定的联系人
void SEARCHContanct(struct Contanct *ps);
// 修改指定联系人
void MODIFYContanct(struct Contanct *ps);
//输出通讯录到指定的文件地址
void EXITContanct(struct Contanct *ps)
 
