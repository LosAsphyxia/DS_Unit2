#include"/home/wth/VSproj/CProj/Proj1/include/Link_List.h"
#include<stdio.h>
#include<stdlib.h>

bool Init_List(LinkList &L){
    L = (LinkList)malloc(sizeof(Lnode));//头结点
    L->next = NULL;//指空
    return true;
}

bool Destroy_List(LinkList &L){
    Lnode *p;
    while(L){//包括头结点也删除
        p = L;
        L = L->next;
        free(p);
    }
    return true;
}

//不删头结点（清空链表）
bool Clear_List(LinkList &L){
    Lnode *p, *q;
    p = L->next;
    while(p){
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
    return true;
}

//表长
int Count_Lnode(LinkList L){
    Lnode *p = L->next;
    int i = 0;
    while (p){
        p = p->next;
        i++;
    }
    return i;
}

//取单链表中第i个元素的内容
bool Get_Elem(LinkList L, int n, Lnode &e){
    Lnode *p = L->next;
    int i = 1;
    while (i < n){
        p = p->next;
        i++;
        if(p==NULL)
            return false;
    }
    e = *p;
    return true;
}

//查找
int Search_Elem(LinkList L, float e){
    Lnode *p = L->next;
    int i = 1;
    while(p->data != e){
            i++;
            p = p->next;
            if(p==NULL)
                return 0;
    }
    return i;
}

//插入算法
bool Insert_Elem(LinkList &L, int n, float e){
    Lnode *p = L;
    int j = 1;
    while (j < n && p){
        p = p->next;
        j++;
    }
    if(!p || j > n)
        return false;
    LinkList s = (Lnode*)malloc(sizeof(Lnode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//删除算法
bool Delete_Elem(LinkList &L, int n){
    Lnode *p = L;
    Lnode *q = p;
    int j = 1;
    while (j < n && p){
        q = p;
        p = p->next;
        j++;
    }
    if(!p || j > n)
        return false;
    q->next = p->next;
    free(p);
    return true;
}

//头插法建立单链表
void CreateList_H(LinkList &L, int n){
    L = (LinkList)malloc(sizeof(Lnode));
    L->next = NULL;
    for(int i=0;i<n;i++){
        Lnode *p = (Lnode*)malloc(sizeof(Lnode));
        scanf("%f", &p->data);
        p->next = L->next;
        L->next = p;
    }
}

//尾插法建立单链表
void CreateList_T(LinkList &L, int n){
    L = (LinkList)malloc(sizeof(Lnode));
    L->next = NULL;
    Lnode *p = L;//尾指针
    for(int i=0;i<n;i++){
        Lnode *t = (LinkList)malloc(sizeof(Lnode));
        scanf("%f", &t->data);
        t->next = NULL;
        p->next = t;//插入到尾部
        p = t;//尾指针移动到尾结点
    }
}

//循环链表（带尾指针）合并
LinkList Connect(LinkList Ta, LinkList Tb){
    Lnode *p = Ta->next;
    Ta->next = Tb->next->next;
    free(Tb->next);
    Tb->next = p;
    return Tb;
}//时间复杂度O(1)



//双向链表的插入运算
bool ListInsert_DuL(DuLinkList &L, int i, float e){
    DuLnode *p = L->next;
    int j = 1;
    while(p && j<i){
        p = p->next;
        j++;
    }
    if(!p || j>i)return false;
    DuLnode *s = (DuLnode*)malloc(sizeof(DuLnode));
    s->data = e;
    
    s->piror = p->piror;
    p->piror->next = s;
    s->next = p;
    p->piror = s;
    
    return true;
}

//双向链表的删除运算
bool ListInsert_DuL(DuLinkList &L, int i){
    DuLnode *p = L->next;
    int j = 1;
    while(p && j<i){
        p = p->next;
        j++;
    }
    if(!p || j>i)return false;
    
    p->piror->next = p->next;
    p->next->piror = p->piror;
    free(p);
    
    return true;
}

void Collect_end(LinkList &a, LinkList b){
    LinkList p;
    p = b->next;
    while (p != NULL){
        if(!Search_Elem(a, p->data))
            Insert_Elem(a, Count_Lnode(a)+1, p->data);
        p = p->next;
    }
}

void Display(LinkList a){
    LinkList p = a->next;
    while (p!=NULL){
        printf("%.2f\t", p->data);
        p = p->next;
    }
    printf("\n");
}

void Collect_sort(LinkList &a, LinkList b){
    Lnode *pre, *p, *q;
    pre = a;
    p = a->next;
    int n = 1;
    q = b->next;//b插入到a中
    //从小到大
    while (p!=NULL && q!=NULL){
        if(p->data < q->data){
            p = p->next;
            pre = pre->next;
            n++;
        }
        else if(p->data > q->data){
            Insert_Elem(a, n, q->data);
            pre = pre->next;
            q = q->next;
            n++;
        }
        else
            q = q->next;
    }
    if(q!=NULL)
        pre->next = q;
}

void Collect_sort2(LinkList &a, LinkList &b, LinkList &c){
    LinkList pa = a->next;
    LinkList pb = b->next;
    LinkList pc = c = a;
    while (pa && pb)
    {
        if(pa->data <= pb->data){
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else{
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    delete b;
}