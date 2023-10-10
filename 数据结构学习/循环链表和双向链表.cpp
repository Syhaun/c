//用尾指针将两个循环链表合并成一个表
p=rearA->next;//保存A表的头结点
rearA->next=rearB->next->next;//将本是指向B表的第一个结点，赋值给reaA->next
q=rearB->next;
rearB->next=p;//将原A表的头结点赋值给rearB->next
free(q);//释放q

//双向链表
//线性表的双向链表存储结构
typedef struct DulNode
{
	ElemType data;
	struct DuLNode *prior;//直接前驱指针
	struct DuLNode *next; //直接后继指针 
 } DulNode,*DuLinkList;
 
 //插入核心代码
 s->prior=p;//把p赋值给s的前驱 
 s->next=p->next;//把p->next赋值给s的后继 
 p->next->prior=s;//把s赋值给p->next的前驱 
 p->next=s; //把s赋值给p的后继
 //先搞定s的前驱和后继，再后结点的前驱，再前结点的后继
 
 //删除核心代码
 p->prior->next=p->next;//把p->next赋值给p->prior的后继 
 p->next->prior=p->prior; //把p->prior赋值给p->next的前驱 
