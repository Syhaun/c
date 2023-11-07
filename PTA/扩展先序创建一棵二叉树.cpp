#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BiTree;
struct TNode
{
    ElementType Data;
    BiTree Left;
    BiTree Right;
};

BiTree CreatBiTree();

void PreorderTraversal(BiTree BT)
{
    // 实现细节忽略
    if(BT == NULL)
        return;
    printf("%c ", BT->Data);
    PreorderTraversal(BT->Left);
    PreorderTraversal(BT->Right);
}
void InorderTraversal(BiTree BT)
{
    // 实现细节忽略
    if (BT == NULL)
        return;
    InorderTraversal(BT->Left);
    printf("%c ", BT->Data);
    InorderTraversal(BT->Right);

}
void PostorderTraversal(BiTree BT)
{
    // 实现细节忽略
    if(BT == NULL)
        return;
    PostorderTraversal(BT->Left);
    PostorderTraversal(BT->Right);
    printf("%c ", BT->Data);
}
int main()
{
    BiTree BT = CreatBiTree();
    printf("Preorder:");
    PreorderTraversal(BT);
    printf("\n");
    printf("Inorder:");
    InorderTraversal(BT);
    printf("\n");
    printf("Postorder:");
    PostorderTraversal(BT);
    return 0;
}
/* 请在这里填写答案 */
BiTree CreatBiTree()
{
    ElementType ch;
    scanf("%c", &ch);
    if (ch == '#')
    {
        return NULL;
    }
    BiTree root = (BiTree)malloc(sizeof(struct TNode));
    root->Data = ch;
    root->Left = CreatBiTree();
    root->Right = CreatBiTree();
    return root;
}