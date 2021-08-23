typedef struct Lnode
{
    float data;
    struct Lnode *next;
}Lnode, *LinkList;

bool Init_List(LinkList &L);

bool Destroy_List(LinkList &L);

//不删头结点（清空链表）
bool Clear_List(LinkList &L);

//表长
int Count_Lnode(LinkList L);

//取单链表中第i个元素的内容
bool Get_Elem(LinkList L, int n, Lnode &e);

//查找
int Search_Elem(LinkList L, float e);

//插入算法
bool Insert_Elem(LinkList &L, int n, float e);

//删除算法
bool Delete_Elem(LinkList &L, int n);

//头插法建立单链表
void CreateList_H(LinkList &L, int n);

//尾插法建立单链表
void CreateList_T(LinkList &L, int n);

void Collect_end(LinkList &a, LinkList b);

void Display(LinkList a);

void Collect_sort(LinkList &a, LinkList &b);

void Collect_sort2(LinkList &a, LinkList &b, LinkList &c);







//循环链表（带尾指针）合并
LinkList Connect(LinkList Ta, LinkList Tb);

//双向链表
typedef struct DuLnode
{
    float data;
    DuLnode *piror, *next;
}DuLnode, *DuLinkList;

//双向链表的插入运算
bool ListInsert_DuL(DuLinkList &L, int i, float e);
//双向链表的删除运算
bool ListInsert_DuL(DuLinkList &L, int i);