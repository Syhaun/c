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
    // ����ͨѶ¼
    struct Contanct con;
    // ��ʼ��ͨѶ¼
    InitContact(&con);
    do
    {
        menu();
        printf("��ѡ��>");
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
            printf("�˳�ͨѶ¼\n");
            return 0;
        default:
            printf("ѡ�����\n");
        }
    } while (1);
}
