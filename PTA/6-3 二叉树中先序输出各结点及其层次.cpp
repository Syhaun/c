#include <stdio.h>
#include <stdlib.h>
typedef char DataType;

typedef struct Node
{
    DataType data;
    struct Node *Lchild;
    struct Node *Rchild;
} BiTNode, *BiTree;

BiTree CreatBiTree(); // 用扩展先序遍历序列创建二叉链表
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

/* 请在这里填写答案 */
void PreOrderLayer(BiTree bt, int lay)
{
    if (bt == NULL)
    {
        return;
    }
    printf("(%c,%d)", bt->data, lay);   // 输出当前节点及其层次数
    PreOrderLayer(bt->Lchild, lay + 1); // 递归输出左子树
    PreOrderLayer(bt->Rchild, lay + 1); // 递归输出右子树
}