//Contanct.c 用来实现函数 
#include "contanct.h" //自定义头文件 
// 通过名字查找它在数组中对应下标的函数
int Findby_name(struct Contanct *ps, char name[MAX_NAME])
{
    int i;
    for (i = 0; i < ps->size; i++)
    {
        if (0 == strcmp(ps->date[i].name, name))
            return i; // 找到了，返回下标 
    }
    return -1; // 找不到
}
// 初始化通讯录的函数
void InitContact(struct Contanct *ps)
{
    memset(ps->date, 0, sizeof(ps->date));
    ps->size = 0; // 设置通讯录最初只有0个元素
}
void AddContact(struct Contanct *ps)
{
    system("cls");//清空屏幕 
    if (ps->size == MAX)
    {
        printf("通讯录已满，无法增加");
    }
    else
    {
        printf("请输入修改后名字:");
        scanf("%s", ps->date[ps->size].name);
        printf("请输入修改后年龄:");
        scanf("%d", &(ps->date[ps->size].age));
        printf("请输入修改后性别:");
        scanf("%s", ps->date[ps->size].sex);
        printf("请输入修改后电话:");
        scanf("%s", ps->date[ps->size].tele);
        printf("请输入修改后地址:");
        scanf("%s", ps->date[ps->size].addr);
        ps->size++;
        system("cls");
        printf("添加成功!\n");
    }
}
// 打印通讯录的信息
void ShowContanct(const struct Contanct *ps)
{
    system("cls");
    if (ps->size == 0)
    {
        printf("通讯录为空\n");
    }
    else
    {
        printf("%-20s\t%4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
        int i = 0;
        for (i = 0; i < ps->size; i++)
        {
            printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
                   ps->date[i].name,
                   ps->date[i].age,
                   ps->date[i].sex,
                   ps->date[i].tele,
                   ps->date[i].addr);
        }
    }
}
// 删除指定的联系人
void DelContact(struct Contanct *ps)
{
    system("cls");
    char name[MAX_NAME];
    printf("请输入要删除人的名字：");
    scanf("%s", name);
    int pos = Findby_name(ps, name);
    if (pos == -1)
        printf("要删除的人不存在\n");
    else
    {
        int j = 0;
        for (j = pos; j < ps->size - 1; j++)
        {
            ps->date[j] = ps->date[j + 1];  //从后往前赋值，均向前移动一个 
        }
        ps->size--;
        printf("删除成功！\n");
    }
}
// 查找指定的联系人
void SEARCHContanct(struct Contanct *ps)
{
    system("cls");
    char name[MAX_NAME];
    printf("请输入查找人的名字:");
    scanf("%s", name);
    int pos = Findby_name(ps, name);
    if (pos == -1)
    {
        printf("要查找的人不存在\n");
    }
    else
        printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
               ps->date[pos].name,
               ps->date[pos].age,
               ps->date[pos].sex,
               ps->date[pos].tele,
               ps->date[pos].addr);
}
// 修改指定联系人
void MODIFYContanct(struct Contanct *ps)
{
    system("cls");
    char name[MAX_NAME];
    printf("请输入要修改联系人的名字\n");
    scanf("%s", name);
    int pos = Findby_name(ps, name);
    if (pos == -1)
    {
        printf("要修改的联系人不存在\n");
    }
    else
    {
        printf("请输入名字:");
        scanf("%s", ps->date[pos].name);
        printf("请输入年龄:");
        scanf("%d", &(ps->date[pos].age));
        printf("请输入性别:");
        scanf("%s", ps->date[pos].sex);
        printf("请输入电话:");
        scanf("%s", ps->date[pos].tele);
        printf("请输入地址:");
        scanf("%s", ps->date[pos].addr);
        ps->size++;
        printf("修改完成!\n");
    }
}
void EXITContanct(struct Contanct *ps)
{
	system("cls");
	printf("退出通讯录\n");
    FILE* f=fopen("C:show.txt","w");//上一级文件夹temp 
    if(f==NULL)
      	printf("error");
    int i;
    for(i=0;i<ps->size;i++)
    {
      fprintf(f,"%-20s\t%4s\t%-5s\t%-12s\t%-20s\n",ps->date[i].name,ps->date[i].age,ps->date[i].sex,ps->date[i].tele,ps->date[i].addr);
	}
	fclose(f);
}

