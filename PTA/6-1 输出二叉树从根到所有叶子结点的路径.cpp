#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef char ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *lchild, *rchild;
} Node, *BiTree;

void CreatTree(BiTree *root); // 以扩展的先序序列为输入创建二叉树，‘#’表示空树，请忽略该函数的实现
void leafroutine(BiTree root, int level);
int main()
{
    BiTree rt = NULL;
    CreatTree(&rt);
    leafroutine(rt, 0);
    return 0;
}

/* 请在这里填写答案 */
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

    static ElemType path[100]; // 用于存储路径的数组
    path[level] = root->data;  // 将当前节点的值存储到路径中

    if (root->lchild == NULL && root->rchild == NULL)
    {
        // 如果是叶子节点，打印路径
        printPath(path, level + 1);
    }
    else
    {
        // 递归遍历左子树和右子树
        leafroutine(root->lchild, level + 1);
        leafroutine(root->rchild, level + 1);
    }
}
void CreatTree(BiTree *root)
{ // 根据所有序列创建二叉树
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
