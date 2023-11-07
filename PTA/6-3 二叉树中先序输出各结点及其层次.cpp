#include <stdio.h>
#include <stdlib.h>
typedef char DataType;

typedef struct Node
{
    DataType data;
    struct Node *Lchild;
    struct Node *Rchild;
} BiTNode, *BiTree;

BiTree CreatBiTree(); // ����չ����������д�����������
void PreOrderLayer(BiTree bt, int lay);
main()
{
    BiTree root;
    root = CreatBiTree();
    PreOrderLayer(root, 1);
}
BiTree CreatBiTree()
{
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
    {
        return NULL;
    }
    BiTree root = (BiTree)malloc(sizeof(BiTNode));
    root->data = ch;
    root->Lchild = CreatBiTree();
    root->Rchild = CreatBiTree();
    return root;
}

/* ����������д�� */
void PreOrderLayer(BiTree bt, int lay)
{
    if (bt == NULL)
    {
        return;
    }
    printf("(%c,%d)", bt->data, lay);   // �����ǰ�ڵ㼰������
    PreOrderLayer(bt->Lchild, lay + 1); // �ݹ����������
    PreOrderLayer(bt->Rchild, lay + 1); // �ݹ����������
}