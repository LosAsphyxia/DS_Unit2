typedef struct Pnode
{
    float coef;
    int expn;
    struct Pnode *next;
    
}Pnode, *Polynomial;

void CreatePolyn(Polynomial &P, int n);

void Display(Polynomial &P);

void AddPolyn(Polynomial &a, Polynomial &b, Polynomial &c);