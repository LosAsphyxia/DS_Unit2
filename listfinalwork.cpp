/*
#include"/home/wth/VSproj/CProj/Proj1/include/My_List.h"
int main(int argc, char** argv){
    float ar[5] = {1.1, 1.2, 1.4, 1.8, 1.9};
    float br[3] = {1.4, 1.5, 1.6};
    My_List a, b;
    trans_to_list(a, ar, 5);
    trans_to_list(b, br, 3);
    Display(a);
    collect_sort(a, b);
    Display(b);
    return 0;
}
*/
/*
#include"/home/wth/VSproj/CProj/Proj1/include/Link_List.h"
int main(int argc, char** argv){
    LinkList a, b;
    CreateList_T(a, 5);
    CreateList_T(b, 7);
    Collect_sort(a, b);
    Display(a);
    return 0;
}
*/
/*
#include"/home/wth/VSproj/CProj/Proj1/include/Polynomial.h"
#include<stdio.h>
int main(){
    Polynomial tst;
    Init_SqList(tst);
    Pnode a, b, c, d, t;
    a.e = 3; a.p = 1.415;
    b.e = 4; b.p = 0.235;
    c.e = 5; c.p = 1.254;
    d.e = 6; d.p = 7.245;
    Insert_Elem(tst, a);
    Insert_Elem(tst, b);
    Insert_Elem(tst, d);
    Insert_Elem_M(tst, 3, c);

    bool flg = Get_Elem(tst, 3, t);
    printf("%d\n", Locate_Elem(tst, b));

    if(flg)
        printf("yes: %fx^%d\n", t.p, t.e);
    else
        printf("no\n");   
     
    return 0;
}
*/
/*
#include"/home/wth/VSproj/CProj/Proj1/include/Stack.h"
int main(){
    //SqStack S;
    //InitSqStack(S);
    //LineEdit(S);
    //conversion(S);
    char a='a', b='b', c='c';
    hanoi(3, a, b, c);
    return 0;
}
*/
#include"/home/wth/VSproj/CProj/Proj1/include/Polynomial2.h"
int main(){
    Polynomial a, b, c;
    CreatePolyn(a, 5);
    CreatePolyn(b, 4);
    Display(a);
    Display(b);
    AddPolyn(a, b, c);
    Display(c);
    return 0;
}