#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef char ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *lchild, *rchild;
} Node, *BiTree;

void CreatTree(BiTree *root); // ����չ����������Ϊ���봴������������#����ʾ����������Ըú�����ʵ��
void leafroutine(BiTree root, int level);
int main()
{
    BiTree rt = NULL;
    CreatTree(&rt);
    leafroutine(rt, 0);
    return 0;
}

/* ����������д�� */
void printPath(ElemType path[], int pathLength)
{
    for (int i = 0; i < pathLength; i++)
    {
        printf("%c  ", path[i]);
    }
    printf("\n");
}

void leafroutine(BiTree root, int level)
{
    if (root == NULL)
    {
        return;
    }

    static ElemType path[100]; // ���ڴ洢·��������
    path[level] = root->data;  // ����ǰ�ڵ��ֵ�洢��·����

    if (root->lchild == NULL && root->rchild == NULL)
    {
        // �����Ҷ�ӽڵ㣬��ӡ·��
        printPath(path, level + 1);
    }
    else
    {
        // �ݹ������������������
        leafroutine(root->lchild, level + 1);
        leafroutine(root->rchild, level + 1);
    }
}
void CreatTree(BiTree *root)
{ // �����������д���������
    char ch;
    scanf("%c", &ch);

    if (ch == '#')
    {
        (*root) = NULL;
    }
    else
    {
        if (!(*root = (BiTree)malloc(sizeof(Node))))
        {
            exit(-1);
        }
        (*root)->data = ch;
        CreatTree(&((*root)->lchild));
        CreatTree(&((*root)->rchild));
    }
}
