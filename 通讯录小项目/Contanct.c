//Contanct.c ����ʵ�ֺ��� 
#include "contanct.h" //�Զ���ͷ�ļ� 
// ͨ�����ֲ������������ж�Ӧ�±�ĺ���
int Findby_name(struct Contanct *ps, char name[MAX_NAME])
{
    int i;
    for (i = 0; i < ps->size; i++)
    {
        if (0 == strcmp(ps->date[i].name, name))
            return i; // �ҵ��ˣ������±� 
    }
    return -1; // �Ҳ���
}
// ��ʼ��ͨѶ¼�ĺ���
void InitContact(struct Contanct *ps)
{
    memset(ps->date, 0, sizeof(ps->date));
    ps->size = 0; // ����ͨѶ¼���ֻ��0��Ԫ��
}
void AddContact(struct Contanct *ps)
{
    system("cls");//�����Ļ 
    if (ps->size == MAX)
    {
        printf("ͨѶ¼�������޷�����");
    }
    else
    {
        printf("�������޸ĺ�����:");
        scanf("%s", ps->date[ps->size].name);
        printf("�������޸ĺ�����:");
        scanf("%d", &(ps->date[ps->size].age));
        printf("�������޸ĺ��Ա�:");
        scanf("%s", ps->date[ps->size].sex);
        printf("�������޸ĺ�绰:");
        scanf("%s", ps->date[ps->size].tele);
        printf("�������޸ĺ��ַ:");
        scanf("%s", ps->date[ps->size].addr);
        ps->size++;
        system("cls");
        printf("��ӳɹ�!\n");
    }
}
// ��ӡͨѶ¼����Ϣ
void ShowContanct(const struct Contanct *ps)
{
    system("cls");
    if (ps->size == 0)
    {
        printf("ͨѶ¼Ϊ��\n");
    }
    else
    {
        printf("%-20s\t%4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
// ɾ��ָ������ϵ��
void DelContact(struct Contanct *ps)
{
    system("cls");
    char name[MAX_NAME];
    printf("������Ҫɾ���˵����֣�");
    scanf("%s", name);
    int pos = Findby_name(ps, name);
    if (pos == -1)
        printf("Ҫɾ�����˲�����\n");
    else
    {
        int j = 0;
        for (j = pos; j < ps->size - 1; j++)
        {
            ps->date[j] = ps->date[j + 1];  //�Ӻ���ǰ��ֵ������ǰ�ƶ�һ�� 
        }
        ps->size--;
        printf("ɾ���ɹ���\n");
    }
}
// ����ָ������ϵ��
void SEARCHContanct(struct Contanct *ps)
{
    system("cls");
    char name[MAX_NAME];
    printf("����������˵�����:");
    scanf("%s", name);
    int pos = Findby_name(ps, name);
    if (pos == -1)
    {
        printf("Ҫ���ҵ��˲�����\n");
    }
    else
        printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
               ps->date[pos].name,
               ps->date[pos].age,
               ps->date[pos].sex,
               ps->date[pos].tele,
               ps->date[pos].addr);
}
// �޸�ָ����ϵ��
void MODIFYContanct(struct Contanct *ps)
{
    system("cls");
    char name[MAX_NAME];
    printf("������Ҫ�޸���ϵ�˵�����\n");
    scanf("%s", name);
    int pos = Findby_name(ps, name);
    if (pos == -1)
    {
        printf("Ҫ�޸ĵ���ϵ�˲�����\n");
    }
    else
    {
        printf("����������:");
        scanf("%s", ps->date[pos].name);
        printf("����������:");
        scanf("%d", &(ps->date[pos].age));
        printf("�������Ա�:");
        scanf("%s", ps->date[pos].sex);
        printf("������绰:");
        scanf("%s", ps->date[pos].tele);
        printf("�������ַ:");
        scanf("%s", ps->date[pos].addr);
        ps->size++;
        printf("�޸����!\n");
    }
}
void EXITContanct(struct Contanct *ps)
{
	system("cls");
	printf("�˳�ͨѶ¼\n");
    FILE* f=fopen("C:show.txt","w");//��һ���ļ���temp 
    if(f==NULL)
      	printf("error");
    int i;
    for(i=0;i<ps->size;i++)
    {
      fprintf(f,"%-20s\t%4s\t%-5s\t%-12s\t%-20s\n",ps->date[i].name,ps->date[i].age,ps->date[i].sex,ps->date[i].tele,ps->date[i].addr);
	}
	fclose(f);
}

