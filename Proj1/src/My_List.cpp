#include"/home/wth/VSproj/CProj/Proj1/include/My_List.h"
#include<stdio.h>
#include<stdlib.h>

bool ClearList(My_List &L){
    L.length = 0;
    return true;
}

bool Insert_end(My_List &L, float e){
    if(L.length >= MAX_SIZE - 1)
        return false;
    else{
        L.data[L.length] = e;
        L.length++;
    }
    return true;
}

bool Insert_elem(My_List &L, float e, int n){
    if(L.length >= MAX_SIZE-1 || n > L.length)
        return false;
    else{
        for(int i=L.length; i>n-1; i--){
            L.data[i] = L.data[i-1];
        }
        L.data[n-1] = e;
        L.length++;
        return true;
    }
}

bool Delete_elem(My_List &L, int n){
    if(n >= L.length || n<=0)
        return false;
    for(int i=n; i<L.length; i++){
        L.data[i-1] = L.data[i];
    }
    L.length--;
    return true;
}

int LocateElem(My_List L, float e){
    int cnt = 0;
    while ((abs(L.data[cnt]-e)>1e-4) && (L.length-1>cnt)){
        cnt++;
    }
    if(abs(L.data[cnt]-e)<1e-4)
        return cnt+1;
    else
        return 0;
}

float Get_Elem(My_List L, int n){
    if(n >= L.length || n<=0)
        return 0;
    return L.data[n-1];
}

bool trans_to_list(My_List &L, float arr[], int n){
    if(n > MAX_SIZE || n <= 0)
        return false;
    for(int i=0; i<n; i++){
        L.data[i] = arr[i];
    }
    L.length = n;
    return true;
}

void Display(My_List L){
    if(L.length==0)
        printf("null\n");
    for(int i=0; i<L.length;i++){
        printf("%f\t", L.data[i]);
    }
    printf("\n");
}

bool collect(My_List a, My_List &b){
    for(int i=0; i<a.length; i++)
        if(!LocateElem(b, a.data[i]))
            Insert_end(b, a.data[i]);
    return true;
}

void collect_sort(My_List a, My_List &b){
    int i, j;
    for(i=0, j=0; i<a.length && j<b.length;){
        if(a.data[i] > b.data[j])
            j++;
        else if(a.data[i] < b.data[j]){
            Insert_elem(b, a.data[i], j+1);
            i++;
            j++;
        }
        else
            i++;
    }
    while(i < a.length){
        Insert_end(b, a.data[i]);
        i++;
    }
}