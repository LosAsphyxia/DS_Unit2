
using namespace std;
const int MaxSize = 100;
//顺序队类型定义
typedef struct SqQueue
{
	char data[MaxSize];
	int front, rear;//front队首，rear队尾
};
//初始化队列
void InitQueue(SqQueue*& q);
//销毁队列
void DestoryQueue(SqQueue*& q);
//判断队列是否为空
bool QueueEmpty(SqQueue* q);
//进队列
bool enQueue(SqQueue*& q, char e);
//出队列
bool deQueue(SqQueue*& q, char e);
//上述可能会出现“假溢出”状态，
//使用环形队列解决

//环形队列的实现方法：
//将rear++改为rear=(rear+1)%MaxSize
//将front++改为front=(front+1)%MaxSize
//约定rear==front为队空条件
//(rear+1)%MaxSize==front为队满条件
/*已知front，rear，求队中元素个数count：
count=(rear-front+MaxSize)%MaxSize */
/*已知front，count，求rear
rear=(front+count)%MaxSize */
/*已知rear，count，求front
front=(rear-count+MaxSize)%MaxSize */

//仅使用front和count定义环形队列
typedef struct QuType
{
	char data[MaxSize];
	int front, count;
};
//初始化
void InitQueue(QuType*& qu);
//进队算法
bool EnQueue(QuType*& qu, char x);
//出队算法
bool DeQueue(QuType*& qu, char& x);
//判断队空
bool QueueEmpty(QuType* qu);

//链队
//数据节点类型定义
typedef struct qnode
{
	char data;
	struct qnode* next;
}DataNode;
//头节点类型定义
typedef struct LinkQuNode
{
	DataNode* front;
	DataNode* rear;
};
//初始化队列
void InitQueue(LinkQuNode*& q);
//销毁队列
void DestroyQueue(LinkQuNode*& q);
//判断队列是否为空
bool QueueEmpty(LinkQuNode* q);
//进队
void enQueue(LinkQuNode*& q, char e);
//出队
bool deQueue(LinkQuNode*& q, char e);
//只有尾结点的循环单链表存储队列
//初始化队运算算法
typedef struct LinkList
{
	char data;
	LinkList* next;
};
void initQueue(LinkList*& rear);
//判队空运算算法
bool queueEmpty(LinkList* rear);
//进队运算算法
void enQueue(LinkList*& rear, char x);
//出队运算算法
bool deQueue(LinkList*& rear, char& x);