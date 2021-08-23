#include<stdlib.h>
#include<stdio.h>
#include"/home/wth/VSproj/CProj/Proj1/include/Stack.h"
bool InitSqStack(SqStack &S){
    S.base = (char*)malloc(sizeof(char) * STACK_INIT_SIZE);
    if(!S.base)
        return false;
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;;
    return true;
}

bool GetTop(SqStack S, char &e){
    if(S.top == S.base)
        return false;
    e = *(S.top - 1);
    return true;
}

bool Push(SqStack &S, char e){
    if(S.top - S.base >= STACK_INIT_SIZE){
        S.base = (char*)realloc(S.base, sizeof(char) * (STACK_INIT_SIZE + STACKINCREMENT));
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *(S.top++) = e;
    return true;
}

bool Pop(SqStack &S, char &e){
    if(S.base == S.top)
        return false;
    e = *(--S.top);
    return true;
}

bool StackEmpty(SqStack &S){
    if(S.base == S.top)
        return true;
    return false;
}

/*10转8
void conversion(SqStack &S){
    int tst = 0;
    scanf("%c", &tst);
    while(tst){
        Push(S, tst % 8);
        tst /= 8;
    }
    while (!StackEmpty(S)){
        Pop(S, tst);
        printf("%d", tst);
    }
}
*/

void ClearSqStack(SqStack &S){
    S.top = S.base;
}

//行编辑程序
void LineEdit(SqStack &S){
    char ch = getchar();//第一个字符
    char e = '0';
    while(ch != EOF){//EOF 全文结束符
        while (ch != EOF && ch != '\n')//筛选
        {
            switch (ch)
            {
            case '#':
                Pop(S, e);
                break;
            case '@':
                ClearSqStack(S);
                break;
            default:
                Push(S, ch);
                break;
            }
            ch = getchar();//后续字符
        }
        while(S.base!=S.top){//test
            printf("%c", *(--S.top));
        }
        ClearSqStack(S);//清空缓冲区行
        if(ch != EOF)
            ch = getchar();//第一个字符
    }
    //DestroyStack(S);
}

//汉诺塔
void move(char x, int n, char z){
    static int c;
    printf("%d: Move disk %d from %c to %c\n", ++c, n, x, z);
}
void hanoi(int n, char x, char y, char z){
    if(n==1){
        move(x, 1, z);
    }
    else{
        hanoi(n-1, x, z, y);
        move(x, n, z);
        hanoi(n-1, y, x, z);
    }
}