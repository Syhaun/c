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
// ͨѶ¼����
struct Contanct
{
    struct PeoInfo date[MAX]; // ���һ����Ϣ
    int size;                 // ��¼��ǰ����Ԫ�ظ���
};
// ��ʼ��ͨѶ¼�ĺ���
void InitContact(struct Contanct *ps);
// ����һ����Ϣ��ͨѶ¼
void AddContact(struct Contanct *ps);
// ��ӡͨѶ¼����Ϣ
void ShowContanct(const struct Contanct *ps);
// ɾ��ָ������ϵ��
void DelContact(struct Contanct *ps);
// ����ָ������ϵ��
void SEARCHContanct(struct Contanct *ps);
// �޸�ָ����ϵ��
void MODIFYContanct(struct Contanct *ps);
//���ͨѶ¼��ָ�����ļ���ַ
void EXITContanct(struct Contanct *ps)
 
