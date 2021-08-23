#define MAXSIZE 1000

typedef struct 
{
    float p;//系数
    int e;//指数
}Pnode;

typedef struct 
{
    Pnode *elem; //存储空间基地址
    int length; //多项式中当前项的个数
}Polynomial;

bool Init_SqList(Polynomial &L);

bool Destroy_List(Polynomial &L);

bool Clear_List(Polynomial &L);

int Get_Length(Polynomial L);

bool Is_Empty(Polynomial L);

bool Get_Elem(Polynomial L, int i, Pnode &e);

bool Insert_Elem(Polynomial &L, Pnode e);//尾插

bool Insert_Elem_M(Polynomial &L, int n, Pnode e);

int Locate_Elem(Polynomial L, Pnode e);