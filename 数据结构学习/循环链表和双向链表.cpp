//��βָ�뽫����ѭ������ϲ���һ����
p=rearA->next;//����A���ͷ���
rearA->next=rearB->next->next;//������ָ��B��ĵ�һ����㣬��ֵ��reaA->next
q=rearB->next;
rearB->next=p;//��ԭA���ͷ��㸳ֵ��rearB->next
free(q);//�ͷ�q

//˫������
//���Ա��˫������洢�ṹ
typedef struct DulNode
{
	ElemType data;
	struct DuLNode *prior;//ֱ��ǰ��ָ��
	struct DuLNode *next; //ֱ�Ӻ��ָ�� 
 } DulNode,*DuLinkList;
 
 //������Ĵ���
 s->prior=p;//��p��ֵ��s��ǰ�� 
 s->next=p->next;//��p->next��ֵ��s�ĺ�� 
 p->next->prior=s;//��s��ֵ��p->next��ǰ�� 
 p->next=s; //��s��ֵ��p�ĺ��
 //�ȸ㶨s��ǰ���ͺ�̣��ٺ����ǰ������ǰ���ĺ��
 
 //ɾ�����Ĵ���
 p->prior->next=p->next;//��p->next��ֵ��p->prior�ĺ�� 
 p->next->prior=p->prior; //��p->prior��ֵ��p->next��ǰ�� 
