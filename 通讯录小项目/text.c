#include"contanct.h"
void menu()
{
    printf("*********************************************\n");
    printf("***********1.add             2.del **********\n");
    printf("***********3.search          4.modify *******\n");
    printf("***********5.show            0.exit *********\n");
    printf("*********************************************\n");
    printf("*********************************************\n");
}
int main()
{
    int input;
    // 创建通讯录
    struct Contanct con;
    // 初始化通讯录
    InitContact(&con);
    do
    {
        menu();
        printf("请选择：>");
        scanf("%d", &input);
        switch (input)
        {
        case ADD:
            AddContact(&con);
            break;
        case DEL:
            DelContact(&con);
            break;
        case SEARCH:
            SEARCHContanct(&con);
            break;
        case MODIFY:
            MODIFYContanct(&con);
            break;
        case SHOW:
            ShowContanct(&con);
            break;
        case EXIT:
            printf("退出通讯录\n");
            return 0;
        default:
            printf("选择错误！\n");
        }
    } while (1);
}
