#define MAX_SIZE 100

typedef struct
{
    float data[MAX_SIZE] = {0};
    int length = 0;
}My_List;

bool ClearList(My_List &L);

bool Insert_end(My_List &L, float e);

bool Insert_elem(My_List &L, float e, int n);

bool Delete_elem(My_List &L, int n);

int LocateElem(My_List L, float e);

float Get_Elem(My_List L, int n);

bool trans_to_list(My_List &L, float arr[], int n);

void Display(My_List L);

bool collect(My_List a, My_List &b);

void collect_sort(My_List a, My_List &b);