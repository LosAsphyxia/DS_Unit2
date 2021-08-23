#include"/home/wth/VSproj/CProj/Proj1/include/Polynomial.h"
#include<stdlib.h>

bool Init_SqList(Polynomial &L){
    L.elem = (Pnode*)malloc(MAXSIZE * sizeof(Pnode));
    if(!L.elem)
        return false;
    L.length = 0;
    return true;
}

bool Destroy_List(Polynomial &L){
    if(!L.elem)
        return false;    
    free(L.elem);
    L.length = 0;
    return true;
}

bool Clear_List(Polynomial &L){
    if(!L.elem)
        return false;
    L.length = 0;
    return true;
}

int Get_Length(Polynomial L){
    return L.length;
}

bool Is_Empty(Polynomial L){
    if(L.length != 0)
        return false;
    return true;
}

bool Get_Elem(Polynomial L, int i, Pnode &e){
    if(i>0 && i <=L.length){
        e = *(L.elem + i - 1);
        return true;
    }
    else
        return false;
}

bool Insert_Elem(Polynomial &L, Pnode e){
    if(L.length >= MAXSIZE)
        return false;
    L.elem[L.length] = e;
    L.length++;
    return true;
}//尾插

bool Insert_Elem_M(Polynomial &L, int n, Pnode e){
    if(n > L.length+1 || n < 1)
        return false;
    if(L.length >= MAXSIZE)
        return false;
    for(int i=L.length; i>n-1;i--)
        L.elem[i] = L.elem[i-1];
    L.elem[n-1] = e;
    L.length++;
    return true;
}

int Locate_Elem(Polynomial L, Pnode e){
    for(int i=0; i<L.length; i++)
        if((L.elem[i].e==e.e) || (L.elem[i].p==e.p))
            return i+1;
    return 0;
}