#include"/home/wth/VSproj/CProj/Proj1/include/Polynomial2.h"
#include<stdlib.h>
#include<stdio.h>
void CreatePolyn(Polynomial &P, int n){
    P = (Pnode *)malloc(sizeof(Pnode));
    P->next = NULL;//建立一个带头结点的单链表
    for(int i=1; i<=n; i++){
        Pnode *s = (Pnode*)malloc(sizeof(Pnode));
        scanf("%f %d", &s->coef, &s->expn);
        Pnode *pre = P;
        Pnode *q = P->next;
        while(q && q->expn < s->expn){//找到第一个大于输入项指数的项*q
            pre = q;
            q = q->next;
        }
        s->next = q;
        pre->next = s;
    }
}

void Display(Polynomial &P){
    Pnode *q = P->next;
    while (q->next)
    {
        printf("%f*x^%d  +  ", q->coef, q->expn);
        q = q->next;
    }
    printf("%f *x^%d\n", q->coef, q->expn);    
}


void AddPolyn(Polynomial &a, Polynomial &b, Polynomial &c){
    Pnode *p = a->next;
    Pnode *p_pre = a;//main
    Pnode *q = b->next;
    Pnode *q_pre = b;
    c = a;
    while (p && q){
        if(q->expn < p->expn){//q小于p，插在p前面
            q_pre->next = q->next;//b删除结点q
            
            q->next = p;//q结点接上a(p)
            p_pre->next = q;
            p_pre = p_pre->next;//pre前进

            q = q_pre->next;//q指针回到b中
        }

        else if(q->expn == p->expn){
            p->coef += q->coef;
            if(!p->coef){
                p_pre->next = p->next;//删除结点
                p = p_pre->next;
            }
            q_pre = q;
            q = q->next;//q往后
        }

        else{//q大于p，p往后
            p_pre = p;
            p = p->next;
        }
    }
    if(q)
        p_pre->next = q;
}