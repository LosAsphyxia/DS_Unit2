#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct
{
    char *top;
    char *base;
    int stacksize;
}SqStack;

bool InitSqStack(SqStack &S);

bool GetTop(SqStack S, char &e);

bool Push(SqStack &S, char e);

bool Pop(SqStack &S, char &e);

bool StackEmpty(SqStack &S);

/*10转8
void conversion(SqStack &S);
*/

void ClearSqStack(SqStack &S);

//行编辑程序
void LineEdit(SqStack &S);

//汉诺塔
void move(char x, int n, char z);

void hanoi(int n, char x, char y, char z);
