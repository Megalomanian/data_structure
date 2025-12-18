#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <sstream>

#include <cstring>
#include <algorithm>

#define MAXSIZE 100

#ifndef HUFFMAN_H
#define HUFFMAN_H

#define MAX_CHARS 27	   // 26个英文字符 + 1个空格符
#define MAX_CODE_LENGTH 32 // 假设最大编码长度不超过32位
#define NUM_SYMBOLS 27

// 哈夫曼树节点结构体
typedef struct HuffmanNode
{
	char data;	   // 字符数据
	int frequency; // 字符频率
	int parent;	   // 父节点索引 (用于编码)
	int left;	   // 左子节点索引
	int right;	   // 右子节点索引
} HuffmanNode;

// 哈夫曼编码表结构体
typedef struct
{
	char code[MAX_CODE_LENGTH]; // 存储编码串
} CodeItem;

// 外部全局变量声明 (在 main.c 中定义)
extern HuffmanNode HFTree[2 * MAX_CHARS];
extern CodeItem HFCodes[MAX_CHARS];
extern char CHAR_MAP[MAX_CHARS]; // 存储所有待编码字符的数组

#endif

typedef int ElemType;

// Simple data structure demo program (refactored I/O)

// menu template
/*
void menu3_2()
{
	int code;
	while (true)
	{
		clearScreen();
		std::cout << "\n\t\t\t\t=======链式栈=======\n"
				  << "\t\t\t\t1. 初始化栈\n"
				  << "\t\t\t\t2. 判空\n"
				  << "\t\t\t\t3. 入栈\n"
				  << "\t\t\t\t4. 出栈\n"
				  << "\t\t\t\t5. 打印栈\n"
				  << "\t\t\t\t0. 返回\n"
				  << "\t\t\t\t===================================\n";

		std::cout << "\n请输入命令序号: ";
		if (!(std::cin >> code))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "无效输入，请输入数字。" << std::endl;
			pause();
			continue;
		}

		switch ((int)code)
		{
		case 1:
			break;
		case 2:
			break;
		case 0:
			std::cout << "感谢您的使用！" << std::endl;
			return;
		default:
			std::cout << "未知命令！" << std::endl;
		}

		// pause();
	}
}*/

// --- Helper declarations ---
void clearScreen();
void pause();
void promptTwoInts(const std::string &prompt, int &x, int &y);

// --- Swap demos ---
void fakeSwitch(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void realSwitchByPointer(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void realSwitchByAlias(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

// --- Sequential List ---
typedef int ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
	int length;
} SqList;

void initSeq(SqList &l)
{
	for (int i = 0; i < l.length; i++)
	{
		l.data[i] = 0;
	}
}

void createSeq(SqList &L)
{
	int i;
	std::cout << "请输入线性表的长度: ";
	std::cin >> L.length;
	std::cout << "请依次输入线性表的元素: ";
	for (i = 0; i < L.length; i++)
		std::cin >> L.data[i];
	std::cout << "线性表创建成功！" << std::endl;
}
void insertPre(SqList &L, int i, ElemType e) // 前插入
{
	int j;
	if (i < 1 || i > L.length + 1)
	{
		std::cout << "插入位置不合法！" << std::endl;
		return;
	}
	if (L.length >= MAXSIZE)
	{
		std::cout << "线性表已满，无法插入！" << std::endl;
		return;
	}
	for (j = L.length; j >= i; j--)
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e;
	L.length++;
	std::cout << "插入成功！" << std::endl;
}
void insertPost(SqList &L, int i, ElemType e) // 后插入
{
	int j;
	if (i < 1 || i > L.length + 1)
	{
		std::cout << "插入位置不合法！" << std::endl;
		return;
	}
	if (L.length >= MAXSIZE)
	{
		std::cout << "线性表已满，无法插入！" << std::endl;
		return;
	}
	for (j = L.length; j >= i; j--)
		L.data[j] = L.data[j - 1];
	L.data[i] = e;
	L.length++;
	std::cout << "插入成功！" << std::endl;
}
void deleteV(SqList &L, ElemType e) // 按值删除
{
	int i, j;
	for (i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
			break;
	}
	if (i >= L.length)
	{
		std::cout << "未找到该元素！" << std::endl;
		return;
	}
	for (j = i; j < L.length - 1; j++)
		L.data[j] = L.data[j + 1];
	L.length--;
	std::cout << "删除成功！" << std::endl;
}
void deleteP(SqList &L, int i) // 按位删除
{
	int j;
	if (i < 1 || i > L.length)
	{
		std::cout << "删除位置不合法！" << std::endl;
		return;
	}
	for (j = i - 1; j < L.length - 1; j++)
		L.data[j] = L.data[j + 1];
	L.length--;
	std::cout << "删除成功！" << std::endl;
}
void locate(SqList L, ElemType e) // 按值查找
{
	int i;
	for (i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
		{
			std::cout << "元素 " << e << " 位于位置 " << (i + 1) << std::endl;
			return;
		}
	}
	std::cout << "未找到该元素！" << std::endl;
}
void printList(SqList L)
{
	int i;
	if (L.length <= 0)
	{
		std::cout << "线性表为空或未初始化。请先创建线性表。" << std::endl;
		return;
	}
	std::cout << "线性表元素: ";
	for (i = 0; i < L.length; i++)
		std::cout << L.data[i] << ' ';
	std::cout << std::endl;
}

// linked list
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;
void createLinkList(LinkList &L)
{
	L = (LNode *)malloc(sizeof(LNode));
	L->next = nullptr; // Initialize head node
	LNode *tail = L;   // Tail pointer for efficient insertion
	int n;
	std::cout << "请输入单链表的长度: ";
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		LNode *newNode = new LNode;
		std::cout << "请输入第 " << (i + 1) << " 个元素: ";
		std::cin >> newNode->data;
		tail->next = newNode;
		newNode->next = nullptr;
		tail = newNode; // Move tail to the new node
	}
	std::cout << "单链表创建成功！" << std::endl;
}
void insertPreNode(LinkList &L, int n, ElemType e) // Insert before node p
{
	if (n < 1)
	{
		std::cout << "插入位置不合法！" << std::endl;
		return;
	}
	if (L->next == nullptr) // List is empty
	{
		std::cout << "单链表为空，无法插入！" << std::endl;
		return;
	}
	LNode *p = L->next;
	for (int i = 1; i < n && p != nullptr; i++)
		p = p->next;
	LNode *newNode = new LNode;
	newNode->data = e;
	// To insert before p, we need to find the node before p
	LNode *prev = L;
	while (prev->next != nullptr && prev->next != p)
		prev = prev->next;
	if (prev->next == nullptr)
	{
		std::cout << "未找到指定节点，无法插入！" << std::endl;
		delete newNode;
		return;
	}
	newNode->next = p;
	prev->next = newNode;
	std::cout << "插入成功！" << std::endl;
}
void insertAfterLinkNode(LinkList &L, int n, ElemType e) // Insert after node p
{
	LNode *p = L->next;
	for (int i = 1; i < n && p != nullptr; i++)
		p = p->next;
	if (L->next == nullptr) // List is empty
	{
		std::cout << "单链表为空，无法插入！" << std::endl;
		return;
	}
	LNode *newNode = new LNode;
	newNode->data = e;
	newNode->next = p->next;
	p->next = newNode;
	std::cout << "插入成功！" << std::endl;
}
void deleteLinkValue(LinkList &L, ElemType e) // Delete by value
{
	if (L->next == nullptr) // List is empty
	{
		std::cout << "单链表为空，无法删除！" << std::endl;
		return;
	}
	LNode *prev = L;
	LNode *curr = L->next;
	while (curr != nullptr && curr->data != e)
	{
		prev = curr;
		curr = curr->next;
	}
	if (curr == nullptr)
	{
		std::cout << "未找到该元素，无法删除！" << std::endl;
		return;
	}
	prev->next = curr->next;
	delete curr;
	std::cout << "删除成功！" << std::endl;
}
void deleteLinkPosition(LinkList &L, int i) // Delete node p
{
	if (i < 1)
	{
		std::cout << "删除位置不合法！" << std::endl;
		return;
	}
	LNode *p = L->next;
	for (int j = 1; j < i && p != nullptr; j++)
		p = p->next;
	if (L->next == nullptr) // List is empty
	{
		std::cout << "单链表为空，无法删除！" << std::endl;
		return;
	}
	LNode *prev = L;
	while (prev->next != nullptr && prev->next != p)
		prev = prev->next;
	if (prev->next == nullptr)
	{
		std::cout << "未找到指定节点，无法删除！" << std::endl;
		return;
	}
	prev->next = p->next;
	delete p;
	std::cout << "删除成功！" << std::endl;
}
void locateLinkValue(LinkList L, ElemType e) // Locate by value
{
	if (L->next == nullptr) // List is empty
	{
		std::cout << "单链表为空，无法查找！" << std::endl;
		return;
	}
	LNode *p = L->next;
	int pos = 1;
	while (p != nullptr)
	{
		if (p->data == e)
		{
			std::cout << "元素 " << e << " 位于位置 " << pos << std::endl;
			return;
		}
		p = p->next;
		pos++;
	}
	std::cout << "未找到该元素！" << std::endl;
}
void printLinkList(LinkList L)
{
	if (L == nullptr)
	{
		std::cout << "单链表未创建。请先创建单链表。" << std::endl;
		return;
	}
	if (L->next == nullptr)
	{
		std::cout << "单链表为空！" << std::endl;
		return;
	}
	LNode *p = L->next;
	std::cout << "单链表元素: ";
	while (p != nullptr)
	{
		std::cout << p->data << ' ';
		p = p->next;
	}
	std::cout << std::endl;
}

// circular single linked list
typedef struct CSNode
{
	ElemType data;
	struct CSNode *next;
} CSNode, *CLinkList;
void createCLinkList(CLinkList &L)
{
	L = new CSNode;
	L->next = L;	  // Initialize circular link
	CSNode *tail = L; // Tail pointer for efficient insertion
	int n;
	std::cout << "请输入循环单链表的长度: ";
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		CSNode *newNode = new CSNode;
		std::cout << "请输入第 " << (i + 1) << " 个元素: ";
		std::cin >> newNode->data;
		tail->next = newNode;
		newNode->next = L; // Maintain circular link
		tail = newNode;	   // Move tail to the new node
	}
	std::cout << "循环单链表创建成功！" << std::endl;
}
void insertPreCLinkNode(CLinkList &L, int n, ElemType e) // Insert before node p
{
	if (n < 1)
	{
		std::cout << "插入位置不合法！" << std::endl;
		return;
	}
	// If list not created yet, create a sentinel head
	if (L == nullptr)
	{
		L = new CSNode;
		L->next = L; // empty circular list
	}

	// find the node at position n (1-based). If n==1, p will be first real node
	CSNode *p = L->next;
	int idx = 1;
	while (idx < n && p != L)
	{
		p = p->next;
		idx++;
	}

	CSNode *newNode = new CSNode;
	newNode->data = e;

	// insert before p: find prev such that prev->next == p
	CSNode *prev = L;
	while (prev->next != L && prev->next != p)
		prev = prev->next;

	// If p==L and prev->next==L, inserting at tail (append)
	newNode->next = p;
	prev->next = newNode;
	std::cout << "插入成功！" << std::endl;
}
void insertAfterCLinkNode(CLinkList &L, int n, ElemType e) // Insert after node p
{
	if (L == nullptr)
	{
		// create list with single node
		L = new CSNode;
		L->next = L;
	}

	CSNode *p = L->next;
	int idx = 1;
	while (idx < n && p != L)
	{
		p = p->next;
		idx++;
	}

	CSNode *newNode = new CSNode;
	newNode->data = e;
	newNode->next = (p == L) ? L->next : p->next;
	if (p == L)
	{
		// append at end: find tail and attach
		CSNode *tail = L;
		while (tail->next != L)
			tail = tail->next;
		tail->next = newNode;
	}
	else
	{
		p->next = newNode;
	}
	std::cout << "插入成功！" << std::endl;
}
void deleteCLinkValue(CLinkList &L, ElemType e) // Delete by value
{
	if (L == nullptr || L->next == L) // List is empty or not created
	{
		std::cout << "循环单链表为空或未创建，无法删除！" << std::endl;
		return;
	}
	CSNode *prev = L;
	CSNode *curr = L->next;
	while (curr != L && curr->data != e)
	{
		prev = curr;
		curr = curr->next;
	}
	if (curr == L)
	{
		std::cout << "未找到该元素，无法删除！" << std::endl;
		return;
	}
	prev->next = curr->next;
	delete curr;
	std::cout << "删除成功！" << std::endl;
}
void deleteCLinkPosition(CLinkList &L, int i) // Delete node p
{
	if (i < 1)
	{
		std::cout << "删除位置不合法！" << std::endl;
		return;
	}
	CSNode *p = L->next;
	for (int j = 1; j < i && p != L; j++)
		p = p->next;
	if (L->next == L) // List is empty
	{
		std::cout << "循环单链表为空，无法删除！" << std::endl;
		return;
	}
	CSNode *prev = L;
	while (prev->next != L && prev->next != p)
		prev = prev->next;
	if (prev->next == L)
	{
		std::cout << "未找到指定节点，无法删除！" << std::endl;
		return;
	}
	prev->next = p->next;
	delete p;
	std::cout << "删除成功！" << std::endl;
}
void locateCLinkValue(CLinkList L, ElemType e) // Locate by value
{
	if (L->next == L) // List is empty
	{
		std::cout << "循环单链表为空，无法查找！" << std::endl;
		return;
	}
	CSNode *p = L->next;
	int pos = 1;
	while (p != L)
	{
		if (p->data == e)
		{
			std::cout << "元素 " << e << " 位于位置 " << pos << std::endl;
			return;
		}
		p = p->next;
		pos++;
	}
	std::cout << "未找到该元素！" << std::endl;
}
void printCLinkList(CLinkList L)
{
	if (L == nullptr)
	{
		std::cout << "循环单链表未创建。请先创建循环单链表。" << std::endl;
		return;
	}
	if (L->next == L)
	{
		std::cout << "循环单链表为空！" << std::endl;
		return;
	}
	CSNode *p = L->next;
	std::cout << "循环单链表元素: ";
	do
	{
		std::cout << p->data << ' ';
		p = p->next;
	} while (p != L);
	std::cout << std::endl;
}

// Josephus problem
void JosSeq()
{
	SqList l;
	std::cout << "请输入约瑟夫环的长度：";
	int length, circle;
	std::cin >> length;
	std::cout << "请输入约瑟夫环的密码：";
	std::cin >> circle;
	l.length = length;
	for (int i = 0; i < length; i++)
	{
		l.data[i] = 1;
	}
	int ptr = 0;
	int rest = length;
	int now = 1;
	while (1)
	{
		// printList(l);
		// pause();
		ptr = ptr % l.length;
		if (rest == 1)
		{
			printList(l);
			break;
		}
		else if (l.data[ptr] == 0)
		{
			ptr++;
			continue;
		}
		else if (now == circle)
		{
			now = 0;
			rest--;
			l.data[ptr] = 0;
			ptr++;
			now++;
			printList(l);
			continue;
		}
		else
		{
			now++;
			ptr++;
			continue;
		}
	}
	int final = 0;
	for (; final < l.length; final++)
	{
		if (l.data[final] == 1)
		{
			break;
		}
	}
	std::cout << "最后剩下的人是第" << final + 1 << "个";
	pause();
}

void JosLink()
{
	CLinkList L = nullptr;
	int length, circle;
	std::cout << "请输入约瑟夫环的长度：";
	std::cin >> length;
	std::cout << "请输入约瑟夫环的密码：";
	std::cin >> circle;
	int rest = length;
	for (int i = 1; i <= length; i++)
	{
		insertPreCLinkNode(L, 1, i);
	}
	CSNode *ptr = L;
	int now = 1;
	while (1)
	{
		if (rest == 1)
		{
			break;
		}
		else if (now != circle)
		{
			ptr = ptr->next;
			now++;
		}
		else if (now == circle)
		{
			CSNode *temp = ptr;
			ptr->next = ptr->next->next;
			now = 1;
			rest--;
		}
		printCLinkList(L);
	}
	std::cout << "最后剩下的人是第" << ptr->data << "个";
	pause();
}

// Stack
typedef struct
{
	ElemType data[MAXSIZE];
	int top;
} SeqStack;

void initStack(SeqStack *&s)
{
	s = (SeqStack *)malloc(sizeof(SeqStack));
	s->top = -1;
}

int isFull(SeqStack *s)
{
	return s->top == MAXSIZE - 1;
}
int isEmpty(SeqStack *s)
{
	return s->top == -1;
}
int push(SeqStack *s, int x)
{
	if (isFull(s))
	{
		std::cout << "栈满，无法入栈！" << std::endl;
		return 0;
	}
	s->data[++s->top] = x;
	return 1;
}
int pop(SeqStack *x, int &y)
{
	if (isEmpty(x))
	{
		std::cout << "栈空，无法出栈！" << std::endl;
		return 0; // failure
	}
	y = x->data[x->top--];
	return 1; // success — 改这里
}
void printStack(SeqStack *s)
{
	if (isEmpty(s))
	{
		std::cout << "栈空！" << std::endl;
		return;
	}
	std::cout << "栈元素: ";
	for (int i = s->top; i >= 0; i--)
	{
		std::cout << s->data[i] << ' ';
	}
	std::cout << std::endl;
}
struct LinkStackNode
{
	ElemType data;
	LinkStackNode *next;
};
void initLinkStack(LinkStackNode *&s)
{
	s = nullptr;
}
int isLinkStackEmpty(LinkStackNode *s)
{
	return s == nullptr;
}
int pushLinkStack(LinkStackNode *&s, ElemType e)
{
	LinkStackNode *newNode = new LinkStackNode;
	if (!newNode)
	{
		std::cout << "内存分配失败，无法入栈！" << std::endl;
		return 0;
	}
	newNode->data = e;
	newNode->next = s;
	s = newNode;
	return 1;
}
int popLinkStack(LinkStackNode *&s, ElemType &e)
{
	if (isLinkStackEmpty(s))
	{
		std::cout << "栈空，无法出栈！" << std::endl;
		return 0; // failure
	}
	LinkStackNode *temp = s;
	e = s->data;
	s = s->next;
	delete temp;
	return 1; // success
}
int printLinkStack(LinkStackNode *s)
{
	if (isLinkStackEmpty(s))
	{
		std::cout << "栈空！" << std::endl;
		return 0;
	}
	std::cout << "栈元素: ";
	LinkStackNode *p = s;
	while (p)
	{
		std::cout << p->data << ' ';
		p = p->next;
	}
	std::cout << std::endl;
	return 1;
}

void PostfixExpression()
{
	SeqStack *s;
	initStack(s);
	char buff[100];
	std::cout << "请输入后缀表达式，以#结束：" << std::endl;
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
		; // 清理 stdin
	fgets(buff, 100, stdin);
	int i = 0;
	while (buff[i] && buff[i] != '#') // 读到 '#' 或 '\0' 结束
	{
		if (isspace(buff[i])) // 跳过空格、回车、制表
		{
			++i;
			continue;
		}

		if (isdigit(buff[i])) // 读数字
		{
			int num = 0;
			while (isdigit(buff[i]))
				num = num * 10 + (buff[i++] - '0');
			push(s, num);
		}
		else if (buff[i] == '+' || buff[i] == '-' ||
				 buff[i] == '*' || buff[i] == '/') // 读运算符
		{
			int a, b;
			if (!pop(s, b) || !pop(s, a))
			{
				std::cout << "表达式错误：操作数不足" << std::endl;
				return;
			}
			int res;
			switch (buff[i])
			{
			case '+':
				res = a + b;
				break;
			case '-':
				res = a - b;
				break;
			case '*':
				res = a * b;
				break;
			case '/':
				if (b == 0)
				{
					std::cout << "除零错误" << std::endl;
					return;
				}
				res = a / b;
				break;
			}
			push(s, res);
			++i;
		}
		else // 非法字符
		{
			++i;
		}
	}
	int final;
	if (!pop(s, final) || s->top != -1)
	{
		std::cout << "表达式错误：结果不唯一或栈未清空" << std::endl;
	}
	else
	{
		std::cout << "计算结果为：" << final << std::endl;
	}
	std::cout << "按回车键退出...";
	std::cin.get();
}

void transferExpression()
{
	SeqStack *s;
	initStack(s);
	char buff[100];
	std::cout << "请输入中缀表达式，以#结束：" << std::endl;
	fgets(buff, 100, stdin);
	int i = 0;
	std::cout << "后缀表达式为：";
	while (buff[i] != '#')
	{
		if (buff[i] >= '0' && buff[i] <= '9')
		{
			while (buff[i] >= '0' && buff[i] <= '9')
			{
				std::cout << buff[i];
				i++;
			}
			std::cout << ' ';
		}
		else if (buff[i] == '+' || buff[i] == '-' || buff[i] == '*' || buff[i] == '/')
		{
			while (!isEmpty(s) && ((buff[i] == '+' || buff[i] == '-') || (s->data[s->top] == '*' || s->data[s->top] == '/')))
			{
				int op;
				pop(s, op);
				std::cout << (char)op << ' ';
			}
			push(s, buff[i]);
			i++;
		}
		else if (buff[i] == '(')
		{
			push(s, buff[i]);
			i++;
		}
		else if (buff[i] == ')')
		{
			int op;
			pop(s, op);
			while (op != '(')
			{
				std::cout << (char)op << ' ';
				pop(s, op);
			}
			i++;
		}
		else
		{
			i++;
		}
	}
	while (!isEmpty(s))
	{
		int op;
		pop(s, op);
		std::cout << (char)op << ' ';
	}
	std::cout << std::endl;
	pause();
}
// Queue
struct SqQueue
{
	ElemType data[MAXSIZE];
	int front;
	int rear;
};
void initQueue(SqQueue &q)
{
	q.front = 0;
	q.rear = 0;
}
void enqueue(SqQueue &q, ElemType e)
{
	if ((q.rear + 1) % MAXSIZE == q.front)
	{
		std::cout << "队列满，无法入队！" << std::endl;
		return;
	}
	q.data[q.rear] = e;
	q.rear = (q.rear + 1) % MAXSIZE;
}
ElemType dequeue(SqQueue &q)
{
	if (q.front == q.rear)
	{
		std::cout << "队列空，无法出队！" << std::endl;
		return -1; // assuming -1 is not a valid ElemType
	}
	ElemType e = q.data[q.front];
	q.front = (q.front + 1) % MAXSIZE;
	return e;
}
void printQueue(SqQueue q)
{
	if (q.front == q.rear)
	{
		std::cout << "队列空！" << std::endl;
		return;
	}
	std::cout << "队列元素: ";
	int i = q.front;
	while (i != q.rear)
	{
		std::cout << q.data[i] << ' ';
		i = (i + 1) % MAXSIZE;
	}
	std::cout << std::endl;
}
struct LinkQueueNode
{
	ElemType data;
	LinkQueueNode *next;
};
void initLinkQueue(LinkQueueNode *&front, LinkQueueNode *&rear)
{
	front = rear = nullptr;
}
void enLinkQueue(LinkQueueNode *&front, LinkQueueNode *&rear, ElemType e)
{
	LinkQueueNode *newNode = new LinkQueueNode;
	newNode->data = e;
	newNode->next = nullptr;
	if (rear == nullptr)
	{
		front = rear = newNode;
	}
	else
	{
		rear->next = newNode;
		rear = newNode;
	}
}
void deLinkQueue(LinkQueueNode *&front, LinkQueueNode *&rear)
{
	if (front == nullptr)
	{
		std::cout << "队列空，无法出队！" << std::endl;
		return;
	}
	LinkQueueNode *temp = front;
	front = front->next;
	if (front == nullptr)
	{
		rear = nullptr;
	}
	delete temp;
}
void printLinkQueue(LinkQueueNode *front)
{
	if (front == nullptr)
	{
		std::cout << "队列空！" << std::endl;
		return;
	}
	std::cout << "队列元素: ";
	LinkQueueNode *p = front;
	while (p != nullptr)
	{
		std::cout << p->data << ' ';
		p = p->next;
	}
	std::cout << std::endl;
}
typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
} BiTNode, *BiTree;
BiTree CreateBiTreeFromPre(const char *str, int *idx)
{
	char ch = str[(*idx)++];

	if (ch == '\0')
		return NULL; // 安全保护
	if (ch == '*')
		return NULL; // 空结点

	BiTree node = (BiTree)malloc(sizeof(BiTNode));
	if (!node)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	node->data = ch;
	node->lchild = CreateBiTreeFromPre(str, idx);
	node->rchild = CreateBiTreeFromPre(str, idx);
	return node;
}

void PreOrderRec(BiTree T)
{
	if (T == NULL)
		return;
	printf("%c ", T->data);
	PreOrderRec(T->lchild);
	PreOrderRec(T->rchild);
}

void InOrderRec(BiTree T)
{
	if (T == NULL)
		return;
	InOrderRec(T->lchild);
	printf("%c ", T->data);
	InOrderRec(T->rchild);
}

void PostOrderRec(BiTree T)
{
	if (T == NULL)
		return;
	PostOrderRec(T->lchild);
	PostOrderRec(T->rchild);
	printf("%c ", T->data);
}

typedef struct
{
	BiTree data[MAXSIZE];
	int top;
} Stack;

void InitStack(Stack *S)
{
	S->top = -1;
}

int StackEmpty(Stack *S)
{
	return S->top == -1;
}

int Push(Stack *S, BiTree x)
{
	if (S->top == MAXSIZE - 1)
		return 0;
	S->data[++S->top] = x;
	return 1;
}

int Pop(Stack *S, BiTree *x)
{
	if (S->top == -1)
		return 0;
	*x = S->data[S->top--];
	return 1;
}

BiTree GetTop(Stack *S)
{
	if (S->top == -1)
		return NULL;
	return S->data[S->top];
}

void PreOrderNonRec(BiTree T)
{
	Stack S;
	InitStack(&S);
	BiTree p = T;

	while (p != NULL || !StackEmpty(&S))
	{
		while (p != NULL)
		{
			printf("%c ", p->data); // 访问
			Push(&S, p);
			p = p->lchild;
		}
		if (!StackEmpty(&S))
		{
			Pop(&S, &p);
			p = p->rchild;
		}
	}
}

void InOrderNonRec(BiTree T)
{
	Stack S;
	InitStack(&S);
	BiTree p = T;

	while (p != NULL || !StackEmpty(&S))
	{
		while (p != NULL)
		{
			Push(&S, p);
			p = p->lchild;
		}
		if (!StackEmpty(&S))
		{
			Pop(&S, &p);
			printf("%c ", p->data); // 访问
			p = p->rchild;
		}
	}
}

void PostOrderNonRec(BiTree T)
{
	Stack S;
	InitStack(&S);
	BiTree p = T;
	BiTree lastVisited = NULL; // 记录上一次访问的结点

	while (p != NULL || !StackEmpty(&S))
	{
		if (p != NULL)
		{
			Push(&S, p);
			p = p->lchild;
		}
		else
		{
			BiTree top = GetTop(&S);
			if (top->rchild != NULL && lastVisited != top->rchild)
			{
				// 先去右子树
				p = top->rchild;
			}
			else
			{
				printf("%c ", top->data); // 访问根
				lastVisited = top;
				Pop(&S, &top);
			}
		}
	}
}

int CountLeaves(BiTree T)
{
	if (T == NULL)
		return 0;
	if (T->lchild == NULL && T->rchild == NULL)
		return 1;
	return CountLeaves(T->lchild) + CountLeaves(T->rchild);
}

/* 打印所有叶子结点（递归） */
void PrintLeaves(BiTree T)
{
	if (T == NULL)
		return;
	if (T->lchild == NULL && T->rchild == NULL)
	{
		printf("%c ", T->data);
	}
	PrintLeaves(T->lchild);
	PrintLeaves(T->rchild);
}

/* 求二叉树深度 */
int TreeDepth(BiTree T)
{
	if (T == NULL)
		return 0;
	int ld = TreeDepth(T->lchild);
	int rd = TreeDepth(T->rchild);
	return (ld > rd ? ld : rd) + 1;
}

/*====================  释放内存  ====================*/

void DestroyTree(BiTree T)
{
	if (T == NULL)
		return;
	DestroyTree(T->lchild);
	DestroyTree(T->rchild);
	free(T);
}
// 串
void index(const char *s, const char *t)
{
	int i = 0, j = 0;
	while (s[i] != '\0' && t[j] != '\0')
	{
		if (s[i] == t[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (t[j] == '\0')
	{
		std::cout << "子串位置：" << i - j << std::endl;
	}
	else
	{
		std::cout << "未找到子串" << std::endl;
	}
}

void pattern_index(const char *s, const char *t)
{
	int slen = strlen(s);
	int tlen = strlen(t);
	int *next = new int[tlen];
	// 计算next数组
	next[0] = -1;
	int j = 0;
	int k = -1;
	while (j < tlen - 1)
	{
		if (k == -1 || t[j] == t[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
	// KMP匹配
	int i = 0;
	j = 0;
	while (i < slen && j < tlen)
	{
		if (j == -1 || s[i] == t[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j == tlen)
	{
		std::cout << "子串位置：" << i - j << std::endl;
	}
	else
	{
		std::cout << "未找到子串" << std::endl;
	}
	delete[] next;
}

// 全局哈夫曼树数组，最多 2 * 27 - 1 = 53 个节点
HuffmanNode HFTree[2 * MAX_CHARS];
// 全局编码表，MAX_CHARS 个字符的编码
CodeItem HFCodes[MAX_CHARS];
// 字符数组，方便索引
char CHAR_MAP[MAX_CHARS];
int node_count; // 记录哈夫曼树中实际使用的节点数

void select_min_two(int n, int *s1, int *s2)
{
	int min1 = 9999;
	int min2 = 9999;
	*s1 = -1;
	*s2 = -1;

	for (int i = 0; i < n; i++)
	{
		// 必须是未选择的节点 (parent == 0)
		if (HFTree[i].parent == 0)
		{
			int freq = HFTree[i].frequency;

			if (freq < min1)
			{
				// 发现新的最小频率
				min2 = min1;
				*s2 = *s1;
				min1 = freq;
				*s1 = i;
			}
			else if (freq < min2)
			{
				// 发现新的次小频率
				min2 = freq;
				*s2 = i;
			}
		}
	}
}
void create_huffman_tree(const char *chars, const int *freqs, int initial_n)
{
	if (initial_n <= 1)
		return;

	// 初始化前 initial_n 个叶节点
	node_count = initial_n;
	for (int i = 0; i < initial_n; i++)
	{
		HFTree[i].data = chars[i];
		HFTree[i].frequency = freqs[i];
		HFTree[i].parent = 0;
		HFTree[i].left = 0;
		HFTree[i].right = 0;
		CHAR_MAP[i] = chars[i]; // 建立字符索引映射
	}

	// 初始化其余非叶节点
	for (int i = initial_n; i < 2 * initial_n - 1; i++)
	{
		HFTree[i].frequency = 0;
		HFTree[i].parent = 0;
		HFTree[i].left = 0;
		HFTree[i].right = 0;
		HFTree[i].data = '\0';
	}

	// 构建哈夫曼树主体
	for (int i = initial_n; i < 2 * initial_n - 1; i++)
	{
		int s1, s2;
		select_min_two(i, &s1, &s2); // 在 [0, i-1] 范围内选择最小的两个未处理节点

		// 合并 s1 和 s2
		HFTree[s1].parent = i + 1;
		HFTree[s2].parent = i + 1;
		HFTree[i].left = s1;
		HFTree[i].right = s2;
		HFTree[i].frequency = HFTree[s1].frequency + HFTree[s2].frequency;

		node_count++; // 记录实际节点数
	}
}

void generate_codes(int initial_n)
{
	int i;
	for (i = 0; i < initial_n; i++)
	{
		int c = i;
		int p = HFTree[c].parent - 1; // 实际父节点索引

		// 编码串存储在临时数组中
		char temp_code[MAX_CODE_LENGTH];
		temp_code[0] = '\0';

		// 从叶节点向根节点回溯
		while (p != -1 && p < 2 * initial_n - 1)
		{
			// 左子节点为 '0'
			if (HFTree[p].left == c)
			{
				// 每次追加到最前面 (回溯顺序)
				memmove(temp_code + 1, temp_code, strlen(temp_code) + 1);
				temp_code[0] = '0';
			}
			// 右子节点为 '1'
			else if (HFTree[p].right == c)
			{
				memmove(temp_code + 1, temp_code, strlen(temp_code) + 1);
				temp_code[0] = '1';
			}

			// 移动到父节点
			c = p;
			p = HFTree[p].parent - 1;
		}

		// 将生成的编码复制到全局编码表
		strcpy(HFCodes[i].code, temp_code);
	}
}

/**
 * (2) 打印所有字符的频率及哈夫曼编码
 * @param initial_n 字符总数
 */
void print_code_table(const char *chars, const int *freqs, int initial_n)
{
	printf("--- 字符频率及哈夫曼编码表 ---\n");
	printf("字符\t频率\t编码\n");
	printf("----------------------------\n");

	for (int i = 0; i < initial_n; i++)
	{
		// 替换空格字符显示
		char display_char = chars[i];
		if (display_char == ' ')
		{
			printf("[SPC]\t%d\t%s\n", freqs[i], HFCodes[i].code);
		}
		else
		{
			printf("%c\t%d\t%s\n", display_char, freqs[i], HFCodes[i].code);
		}
	}
	printf("----------------------------\n");
}

/**
 * (3) 编码系统：将字符串编码为哈夫曼编码串
 * @param inputString 待编码的字符串
 * @param initial_n 字符总数
 * @return 动态分配的哈夫曼编码串
 */
char *encode(const char *inputString, int initial_n)
{
	if (inputString == NULL || HFCodes[0].code[0] == '\0')
	{
		return strdup("错误：编码表未建立或输入为空。");
	}

	// 假设编码后的长度不会超过原长度的 MAX_CODE_LENGTH 倍
	size_t input_len = strlen(inputString);
	char *encodedString = (char *)malloc(input_len * MAX_CODE_LENGTH + 1);
	if (encodedString == NULL)
	{
		perror("内存分配失败");
		exit(EXIT_FAILURE);
	}
	encodedString[0] = '\0';

	for (int i = 0; i < input_len; i++)
	{
		// 查找字符对应的编码
		char c = inputString[i];

		// 实验数据要求忽略大小写，这里将小写转为大写处理
		if (c >= 'a' && c <= 'z')
		{
			c = c - 'a' + 'A';
		}

		int found_index = -1;
		for (int j = 0; j < initial_n; j++)
		{
			if (CHAR_MAP[j] == c)
			{
				found_index = j;
				break;
			}
		}

		if (found_index != -1)
		{
			strcat(encodedString, HFCodes[found_index].code);
		}
		else if (c == ' ')
		{
			// 处理空格 (如果空格不是实验数据中的字符)
			// 再次查找空格的编码
			for (int j = 0; j < initial_n; j++)
			{
				if (CHAR_MAP[j] == ' ')
				{
					strcat(encodedString, HFCodes[j].code);
					found_index = j;
					break;
				}
			}
			if (found_index == -1)
			{
				fprintf(stderr, "警告：字符 ' ' 不在编码表中，已跳过。\n");
			}
		}
		else
		{
			fprintf(stderr, "警告：字符 '%c' 不在编码表中，已跳过。\n", inputString[i]);
		}
	}
	return encodedString;
}

/**
 * (4) 译码系统：将哈夫曼编码串译码为字符串
 * @param encodedString 待译码的哈夫曼编码串
 * @param initial_n 字符总数
 * @return 动态分配的译码后原始字符串
 */
char *decode(const char *encodedString, int initial_n)
{
	if (encodedString == NULL || HFTree[0].frequency == 0)
	{
		return strdup("错误：哈夫曼树未建立或输入为空。");
	}

	// 译码后的字符串长度不会超过编码串的长度
	size_t encoded_len = strlen(encodedString);
	char *decodedString = (char *)malloc(encoded_len + 1);
	if (decodedString == NULL)
	{
		perror("内存分配失败");
		exit(EXIT_FAILURE);
	}
	decodedString[0] = '\0';
	int decoded_index = 0;

	int root_index = 2 * initial_n - 2; // 根节点的索引

	int current_node = root_index;

	for (int i = 0; i < encoded_len; i++)
	{
		char bit = encodedString[i];

		if (bit == '0')
		{
			// 移向左子节点
			current_node = HFTree[current_node].left;
		}
		else if (bit == '1')
		{
			// 移向右子节点
			current_node = HFTree[current_node].right;
		}
		else
		{
			free(decodedString);
			return strdup("错误：编码串中包含无效字符。");
		}

		// 判断是否是叶节点（没有子节点）
		if (HFTree[current_node].left == 0 && HFTree[current_node].right == 0)
		{
			decodedString[decoded_index++] = HFTree[current_node].data;
			decodedString[decoded_index] = '\0'; // 保持字符串终止

			// 重置到根节点，开始下一个字符的译码
			current_node = root_index;
		}
	}

	// 检查最后一个字符是否完整译码
	if (current_node != root_index)
	{
		fprintf(stderr, "警告：编码串可能不完整，未能译码最后一个字符。\n");
	}

	// 重新分配内存以适应实际译码长度
	decodedString = (char *)realloc(decodedString, decoded_index + 1);

	return decodedString;
}

void huffmanMain()
{
	const char SYMBOLS[NUM_SYMBOLS] = {
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
		'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};

	// 实验数据：频率表 (对应上面的字符顺序)
	const int FREQUENCIES[NUM_SYMBOLS] = {
		186, 64, 13, 22, 32, 103, 21, 15, 47, 57, 1, 5,
		57, 63, 15, 1, 48, 51, 80, 23, 8, 18, 1, 16, 1, 57};
	// --- (1) 构建哈夫曼树和编码表 ---
	printf("======== 哈夫曼编码译码系统 ========\n");
	printf("\n[1] 正在构建哈夫曼树和编码表...\n");

	// 假设您的频率数据已经通过 loadFrequencyData() 或类似方式加载到 SYMBOLS 和 FREQUENCIES 数组中
	create_huffman_tree(SYMBOLS, FREQUENCIES, NUM_SYMBOLS);
	generate_codes(NUM_SYMBOLS);

	printf("    哈夫曼树和编码表构建完成。\n");

	// --- (2) 打印所有字符的频率及哈夫曼编码 ---
	printf("\n[2] 打印编码表：\n");
	print_code_table(SYMBOLS, FREQUENCIES, NUM_SYMBOLS);

	// --- (3) 编码系统实验 ---
	const char *experiment_string = "how are you";

	// 由于实验数据中只有大写字母，我们先将输入字符串转化为大写进行编码
	// 注意：实验要求是键盘输入，这里我们直接使用实验数据

	char input_buffer[100];
	strcpy(input_buffer, experiment_string);
	for (int i = 0; input_buffer[i]; i++)
	{
		if (input_buffer[i] != ' ')
		{
			input_buffer[i] = toupper(input_buffer[i]);
		}
	}

	printf("\n[3] 编码实验：\n");
	printf("    待编码字符串: \"%s\" (已转换为大写和空格)\n", input_buffer);

	char *encoded_result = encode(input_buffer, NUM_SYMBOLS);
	printf("    哈夫曼编码串: %s\n", encoded_result);

	// 释放编码结果的内存
	free(encoded_result);

	// --- (4) 译码系统实验 ---
	const char *experiment_code = "1101000110100111111000011111100011100100001";
	printf("\n[4] 译码实验：\n");
	printf("    待译码编码串: %s\n", experiment_code);

	char *decoded_result = decode(experiment_code, NUM_SYMBOLS);
	printf("    译码后的字符串: %s\n", decoded_result);

	// 释放译码结果的内存
	free(decoded_result);

	printf("\n======== 实验结束 ========\n");
	pause();
}

// --- 常量定义 ---
#define MAX_VERTICES 100 // 最大顶点数
#define INF 999999		 // 队列/栈大小，可以根据 MAX_VERTICES 调整
#define MAX_QUEUE_SIZE MAX_VERTICES

// --- 结构体定义 ---

// 邻接表中的边节点
typedef struct EdgeNode
{
	int adjvex;			   // 邻接点域
	struct EdgeNode *next; // 指向下一个邻接点的指针
} EdgeNode;

// 邻接表中的头节点 (顶点)
typedef struct VexNode
{
	int data;			 // 顶点信息 (在本题中可以作为顶点的编号)
	EdgeNode *firstedge; // 指向第一条邻接边的指针
} VexNode, AdjList[MAX_VERTICES];

// 图的结构体
typedef struct
{
	AdjList adjlist;	 // 邻接表
	int vexnum, edgenum; // 图的当前顶点数和边数
} Graph;

// 队列 (用于 BFS)
typedef struct
{
	int data[MAX_QUEUE_SIZE];
	int front, rear;
} Queue;

// --- 全局变量 ---
int visited[MAX_VERTICES]; // 访问标记数组

// --- 队列操作函数 (用于 BFS) ---
void InitQueue(Queue *Q)
{
	Q->front = Q->rear = 0;
}

int IsEmpty(Queue *Q)
{
	return Q->front == Q->rear;
}

void EnQueue(Queue *Q, int e)
{
	if ((Q->rear + 1) % MAX_QUEUE_SIZE != Q->front)
	{
		Q->data[Q->rear] = e;
		Q->rear = (Q->rear + 1) % MAX_QUEUE_SIZE;
	}
	// 实际竞赛中，通常假设不会溢出或直接使用动态数组/STL
}

int DeQueue(Queue *Q)
{
	int e = -1;
	if (!IsEmpty(Q))
	{
		e = Q->data[Q->front];
		Q->front = (Q->front + 1) % MAX_QUEUE_SIZE;
	}
	return e;
}

// --- 图的操作函数 ---

/**
 * @brief 查找顶点在邻接表中的索引位置
 * @param G 图结构体指针
 * @param v 顶点编号 (从 1 开始)
 * @return 顶点在邻接表数组中的索引 (从 0 开始), 找不到返回 -1
 */
int LocateVex(Graph *G, int v)
{
	// 假设顶点编号就是 1 到 G->vexnum
	if (v >= 1 && v <= G->vexnum)
	{
		return v - 1; // 顶点 v 的索引是 v-1
	}
	return -1;
}

/**
 * @brief 创建无向图 (邻接表)
 * @param G 图结构体指针
 */
void CreateGraph(Graph *G)
{
	int i, j, k;
	int v1, v2;

	// 1. 输入顶点数和边数
	printf("请输入图的顶点数和边数 (V E): ");
	if (scanf("%d %d", &G->vexnum, &G->edgenum) != 2)
		return;

	if (G->vexnum > MAX_VERTICES)
	{
		printf("顶点数超过最大限制！\n");
		return;
	}

	// 2. 初始化顶点信息 (假设顶点编号为 1 到 vexnum)
	for (i = 0; i < G->vexnum; i++)
	{
		G->adjlist[i].data = i + 1; // 顶点编号
		G->adjlist[i].firstedge = NULL;
	}

	// 3. 建立邻接表 (无向图)
	printf("请依次输入 %d 条边的两个端点 (例如: v1 v2):\n", G->edgenum);
	for (k = 0; k < G->edgenum; k++)
	{
		if (scanf("%d %d", &v1, &v2) != 2)
			return;

		i = LocateVex(G, v1); // v1 的索引
		j = LocateVex(G, v2); // v2 的索引

		if (i == -1 || j == -1)
		{
			printf("无效的顶点编号！\n");
			k--; // 重新输入
			continue;
		}

		// 插入边节点 j 到 i 的邻接表头
		EdgeNode *newNode1 = (EdgeNode *)malloc(sizeof(EdgeNode));
		if (newNode1 == NULL)
		{ /* 错误处理 */
			return;
		}
		newNode1->adjvex = j;
		newNode1->next = G->adjlist[i].firstedge;
		G->adjlist[i].firstedge = newNode1;

		// 插入边节点 i 到 j 的邻接表头 (无向图)
		EdgeNode *newNode2 = (EdgeNode *)malloc(sizeof(EdgeNode));
		if (newNode2 == NULL)
		{ /* 错误处理 */
			return;
		}
		newNode2->adjvex = i;
		newNode2->next = G->adjlist[j].firstedge;
		G->adjlist[j].firstedge = newNode2;
	}
}

/**
 * @brief 深度优先遍历 (DFS)
 * @param G 图结构体指针
 * @param i 访问的起始顶点在邻接表中的索引 (0 到 vexnum-1)
 */
void DFS(Graph *G, int i)
{
	EdgeNode *p;

	// 1. 标记当前顶点已访问并输出
	visited[i] = 1;
	printf("%d ", G->adjlist[i].data);

	// 2. 遍历其所有邻接点
	p = G->adjlist[i].firstedge;
	while (p)
	{
		int w = p->adjvex; // w 是邻接点的索引
		if (!visited[w])
		{
			DFS(G, w); // 对未访问的邻接点递归调用 DFS
		}
		p = p->next;
	}
}

void BFS(Graph *G, int i)
{
	Queue Q;
	EdgeNode *p;
	int u;
	InitQueue(&Q);
	EnQueue(&Q, i);

	visited[i] = 1;
	printf("%d ", G->adjlist[i].data);

	while (!IsEmpty(&Q))
	{
		u = DeQueue(&Q); // 队头元素出队 (u 是顶点的索引)

		p = G->adjlist[u].firstedge;
		while (p)
		{
			int w = p->adjvex; // w 是邻接点的索引
			if (!visited[w])
			{
				visited[w] = 1;					   // 标记已访问
				printf("%d ", G->adjlist[w].data); // 输出
				EnQueue(&Q, w);					   // 入队
			}
			p = p->next;
		}
	}
}

void ResetVisited(int vexnum)
{
	for (int i = 0; i < vexnum; i++)
	{
		visited[i] = 0;
	}
}

int graphMain()
{
	Graph G;
	int startVexNum; // 用户指定的起始顶点编号
	int startIdx;	 // 起始顶点在邻接表中的索引

	CreateGraph(&G);

	printf("\n请输入遍历的起始节点编号 (1 到 %d): ", G.vexnum);
	if (scanf("%d", &startVexNum) != 1)
		return 0;

	startIdx = LocateVex(&G, startVexNum);
	if (startIdx == -1)
	{
		printf("起始节点编号无效！\n");
		return 0;
	}

	printf("\n--- 深度优先遍历 (DFS) 结果 ---\n");
	ResetVisited(G.vexnum); // 重置访问标记
	printf("节点访问序列: ");
	DFS(&G, startIdx);
	printf("\n");

	printf("\n--- 广度优先遍历 (BFS) 结果 ---\n");
	ResetVisited(G.vexnum); // 重置访问标记
	printf("节点访问序列: ");
	BFS(&G, startIdx);
	printf("\n");

	pause();
	return 0;
}
void menu1_1()
{
	int code;
	int a = 0, b = 0;
	while (true)
	{
		clearScreen();
		std::cout << "\n\t\t\t\t=======三种交换=======\n"
				  << "\t\t\t\t1. 假交换\n"
				  << "\t\t\t\t2. 真交换（指针）\n"
				  << "\t\t\t\t3. 真交换（别名）\n"
				  << "\t\t\t\t0. 返回\n"
				  << "\t\t\t\t==============================\n";
		std::cout << "\n请输入命令序号: ";
		if (!(std::cin >> code))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "无效输入，请输入数字。" << std::endl;
			pause();
			continue;
		}
		switch (code)
		{
		case 1:
			promptTwoInts("请输入 a b: ", a, b);
			std::cout << "before fakeSwitch a=" << a << " b=" << b << '\n';
			fakeSwitch(a, b);
			std::cout << "after fakeSwitch a=" << a << " b=" << b << '\n';
			break;
		case 2:
			promptTwoInts("请输入 a b: ", a, b);
			std::cout << "before realSwitchByPointer a=" << a << " b=" << b << '\n';
			realSwitchByPointer(&a, &b);
			std::cout << "after realSwitchByPointer a=" << a << " b=" << b << '\n';
			break;
		case 3:
			promptTwoInts("请输入 a b: ", a, b);
			std::cout << "before realSwitchByAlias a=" << a << " b=" << b << '\n';
			realSwitchByAlias(a, b);
			std::cout << "after realSwitchByAlias a=" << a << " b=" << b << '\n';
			break;
		case 0:
			return;
		default:
			std::cout << "未知命令！" << std::endl;
		}
		// pause();
	}
}

void menu2_1()
{
	SqList L;
	L.length = 0; // initialize to empty
	int i;
	int code;
	ElemType a;
	while (true)
	{
		clearScreen();
		std::cout << "\n\t\t\t\t=======顺序表=======\n"
				  << "\t\t\t\t1. create\n"
				  << "\t\t\t\t2. insertpre\n"
				  << "\t\t\t\t3. insertpost\n"
				  << "\t\t\t\t4. deleteV\n"
				  << "\t\t\t\t5. deleteP\n"
				  << "\t\t\t\t6. locate\n"
				  << "\t\t\t\t7. printList\n"
				  << "\t\t\t\t0. 返回\n"
				  << "\t\t\t\t===================================\n";

		std::cout << "\n请输入命令序号: ";
		if (!(std::cin >> code))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "无效输入，请输入数字。" << std::endl;
			pause();
			continue;
		}

		switch (code)
		{
		case 1:
			createSeq(L);
			break;
		case 2:
			std::cout << "请输入插入位置和元素值: ";
			std::cin >> i;
			std::cin >> a;
			insertPre(L, i, a);
			break;
		case 3:
			std::cout << "请输入插入位置和元素值: ";
			std::cin >> i;
			std::cin >> a;
			insertPost(L, i, a);
			break;
		case 4:
			std::cout << "请输入要删除的元素值: ";
			std::cin >> a;
			deleteV(L, a);
			break;
		case 5:
			std::cout << "请输入要删除的位置: ";
			std::cin >> i;
			deleteP(L, i);
			break;
		case 6:
			std::cout << "请输入要查找的元素值: ";
			std::cin >> a;
			locate(L, a);
			break;
		case 7:
			printList(L);
			pause();
			break;
		case 0:
			std::cout << "感谢您的使用！" << std::endl;
			return;
		default:
			std::cout << "未知命令！" << std::endl;
		}

		// pause();
	}
}
void menu2_2()
{
	LinkList L = nullptr;
	int i;
	int code;
	ElemType a;
	while (true)
	{
		clearScreen();
		std::cout << "\n\t\t\t\t=======单链表=======\n"
				  << "\t\t\t\t1. create\n"
				  << "\t\t\t\t2. insertpre\n"
				  << "\t\t\t\t3. insertpost\n"
				  << "\t\t\t\t4. deleteV\n"
				  << "\t\t\t\t5. deleteP\n"
				  << "\t\t\t\t6. locate\n"
				  << "\t\t\t\t7. printList\n"
				  << "\t\t\t\t0. 返回\n"
				  << "\t\t\t\t===================================\n";

		std::cout << "\n请输入命令序号: ";
		if (!(std::cin >> code))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "无效输入，请输入数字。" << std::endl;
			pause();
			continue;
		}

		switch (code)
		{
		case 1:
			createLinkList(L);
			break;
		case 2:
			std::cout << "请输入插入位置和元素值: ";
			std::cin >> i;
			std::cin >> a;
			insertPreNode(L, i, a);
			break;
		case 3:
			std::cout << "请输入插入位置和元素值: ";
			std::cin >> i;
			std::cin >> a;
			insertAfterLinkNode(L, i, a);
			break;
		case 4:
			std::cout << "请输入要删除的元素值: ";
			std::cin >> a;
			deleteLinkValue(L, a);
			break;
		case 5:
			std::cout << "请输入要删除的位置: ";
			std::cin >> i;
			deleteLinkPosition(L, i);
			break;
		case 6:
			std::cout << "请输入要查找的元素值: ";
			std::cin >> a;
			locateLinkValue(L, a);
			break;
		case 7:
			printLinkList(L);
			pause();
			break;
		case 0:
			std::cout << "感谢您的使用！" << std::endl;
			return;
		default:
			std::cout << "未知命令！" << std::endl;
		}

		// pause();
	}
}

void menu2_3()
{
	CLinkList L = nullptr;
	int i;
	int code;
	ElemType a;
	while (true)
	{
		clearScreen();
		std::cout << "\n\t\t\t\t=======双链表=======\n"
				  << "\t\t\t\t1. create\n"
				  << "\t\t\t\t2. insertpre\n"
				  << "\t\t\t\t3. insertpost\n"
				  << "\t\t\t\t4. deleteV\n"
				  << "\t\t\t\t5. deleteP\n"
				  << "\t\t\t\t6. locate\n"
				  << "\t\t\t\t7. printList\n"
				  << "\t\t\t\t0. 返回\n"
				  << "\t\t\t\t===================================\n";

		std::cout << "\n请输入命令序号: ";
		if (!(std::cin >> code))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "无效输入，请输入数字。" << std::endl;
			pause();
			continue;
		}

		switch ((int)code)
		{
		case 1:
			createCLinkList(L);
			break;
		case 2:
			std::cout << "请输入插入位置和元素值: ";
			std::cin >> i;
			std::cin >> a;
			insertPreCLinkNode(L, i, a);
			break;
		case 3:
			std::cout << "请输入插入位置和元素值: ";
			std::cin >> i;
			std::cin >> a;
			insertAfterCLinkNode(L, i, a);
			break;
		case 4:
			std::cout << "请输入要删除的元素值: ";
			std::cin >> a;
			deleteCLinkValue(L, a);
			break;
		case 5:
			std::cout << "请输入要删除的位置: ";
			std::cin >> i;
			deleteCLinkPosition(L, i);
			break;
		case 6:
			std::cout << "请输入要查找的元素值: ";
			std::cin >> a;
			locateCLinkValue(L, a);
			break;
		case 7:
			std::cout << "正在打印：" << std::endl;
			printCLinkList(L);
			pause();
			break;
		case 0:
			std::cout << "感谢您的使用！" << std::endl;
			return;
		default:
			std::cout << "未知命令！" << std::endl;
		}

		// pause();
	}
}

void menu2_4()
{
	CLinkList L = nullptr;
	int i;
	int code;
	ElemType a;
	while (true)
	{
		clearScreen();
		std::cout << "\n\t\t\t\t=======循环单链表=======\n"
				  << "\t\t\t\t1. create\n"
				  << "\t\t\t\t2. insertpre\n"
				  << "\t\t\t\t3. insertpost\n"
				  << "\t\t\t\t4. deleteV\n"
				  << "\t\t\t\t5. deleteP\n"
				  << "\t\t\t\t6. locate\n"
				  << "\t\t\t\t7. printList\n"
				  << "\t\t\t\t0. 返回\n"
				  << "\t\t\t\t===================================\n";

		std::cout << "\n请输入命令序号: ";
		if (!(std::cin >> code))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "无效输入，请输入数字。" << std::endl;
			pause();
			continue;
		}

		switch ((int)code)
		{
		case 1:
			createCLinkList(L);
			break;
		case 2:
			std::cout << "请输入插入位置和元素值: ";
			std::cin >> i;
			std::cin >> a;
			insertPreCLinkNode(L, i, a);
			break;
		case 3:
			std::cout << "请输入插入位置和元素值: ";
			std::cin >> i;
			std::cin >> a;
			insertAfterCLinkNode(L, i, a);
			break;
		case 4:
			std::cout << "请输入要删除的元素值: ";
			std::cin >> a;
			deleteCLinkValue(L, a);
			break;
		case 5:
			std::cout << "请输入要删除的位置: ";
			std::cin >> i;
			deleteCLinkPosition(L, i);
			break;
		case 6:
			std::cout << "请输入要查找的元素值: ";
			std::cin >> a;
			locateCLinkValue(L, a);
			break;
		case 7:
			std::cout << "正在打印：" << std::endl;
			printCLinkList(L);
			pause();
			break;
		case 0:
			std::cout << "感谢您的使用！" << std::endl;
			return;
		default:
			std::cout << "未知命令！" << std::endl;
		}

		// pause();
	}
}

void menu2_5()
{
	int code;
	while (true)
	{
		clearScreen();
		std::cout << "\n\t\t\t\t=======约瑟夫环=======\n"
				  << "\t\t\t\t1. 以顺序表解决约瑟夫环\n"
				  << "\t\t\t\t2. 以循环单链表解决约瑟夫环\n"
				  << "\t\t\t\t0. 返回\n"
				  << "\t\t\t\t===================================\n";

		std::cout << "\n请输入命令序号: ";
		if (!(std::cin >> code))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "无效输入，请输入数字。" << std::endl;
			pause();
			continue;
		}

		switch ((int)code)
		{
		case 1:
			JosSeq();
			break;
		case 2:
			JosLink();
			break;
		case 0:
			std::cout << "感谢您的使用！" << std::endl;
			return;
		default:
			std::cout << "未知命令！" << std::endl;
		}

		// pause();
	}
}
void menu3_1()
{
	SeqStack *s = nullptr;
	initStack(s);
	int code;
	while (true)
	{
		clearScreen();
		std::cout << "\n\t\t\t\t=======顺序栈=======\n"
				  << "\t\t\t\t1. 初始化栈\n"
				  << "\t\t\t\t2. 判空\n"
				  << "\t\t\t\t3. 入栈\n"
				  << "\t\t\t\t4. 出栈\n"
				  << "\t\t\t\t5. 打印栈\n"
				  << "\t\t\t\t0. 返回\n"
				  << "\t\t\t\t===================================\n";

		std::cout << "\n请输入命令序号: ";
		if (!(std::cin >> code))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "无效输入，请输入数字。" << std::endl;
			pause();
			continue;
		}

		switch ((int)code)
		{
		case 1:
			initStack(s);
			std::cout << "初始化栈成功！" << std::endl;
			pause();
			break;
		case 2:
			if (isEmpty(s))
				std::cout << "栈空！" << std::endl;
			else
				std::cout << "栈非空！" << std::endl;
			pause();
			break;
		case 3:
			int val;
			std::cout << "请输入入栈元素值: ";
			std::cin >> val;
			push(s, val);
			std::cout << "入栈成功！" << std::endl;
			pause();
			break;
		case 4:
			int popped;
			pop(s, popped);
			std::cout << "出栈成功，出栈元素值为: " << popped << std::endl;
			pause();
			break;
		case 5:
			printStack(s);
			pause();
			break;
		case 0:
			std::cout << "感谢您的使用！" << std::endl;
			return;
		default:
			std::cout << "未知命令！" << std::endl;
		}

		// pause();
	}
}

void menu3_2()
{
	int code;
	LinkStackNode *s = nullptr;
	ElemType val;
	ElemType popped;
	while (true)
	{
		clearScreen();
		std::cout << "\n\t\t\t\t=======链式栈=======\n"
				  << "\t\t\t\t1. 初始化栈\n"
				  << "\t\t\t\t2. 判空\n"
				  << "\t\t\t\t3. 入栈\n"
				  << "\t\t\t\t4. 出栈\n"
				  << "\t\t\t\t5. 打印栈\n"
				  << "\t\t\t\t0. 返回\n"
				  << "\t\t\t\t===================================\n";

		std::cout << "\n请输入命令序号: ";
		if (!(std::cin >> code))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "无效输入，请输入数字。" << std::endl;
			pause();
			continue;
		}

		switch ((int)code)
		{
		case 1:
			initLinkStack(s);
			std::cout << "初始化栈成功！" << std::endl;
			pause();
			break;
		case 2:
			if (isLinkStackEmpty(s))
				std::cout << "栈空！" << std::endl;
			else
				std::cout << "栈非空！" << std::endl;
			pause();
			break;
		case 3:
			std::cout << "请输入入栈元素值: ";
			std::cin >> val;
			pushLinkStack(s, val);
			std::cout << "入栈成功！" << std::endl;
			pause();
			break;
		case 4:
			popLinkStack(s, popped);
			std::cout << "出栈成功，出栈元素值为: " << popped << std::endl;
			pause();
			break;
		case 0:
			std::cout << "感谢您的使用！" << std::endl;
			return;
		default:
			std::cout << "未知命令！" << std::endl;
		}

		// pause();
	}
}

void menu3_3()
{
	int code;
	while (true)
	{
		clearScreen();
		std::cout << "\n\t\t\t\t=======后缀表达式求值=======\n"
				  << "\t\t\t\t1. 计算\n"
				  << "\t\t\t\t0. 返回\n"
				  << "\t\t\t\t===================================\n";

		std::cout << "\n请输入命令序号: ";
		if (!(std::cin >> code))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "无效输入，请输入数字。" << std::endl;
			pause();
			continue;
		}

		switch ((int)code)
		{
		case 1:
			PostfixExpression();
			break;
		case 0:
			std::cout << "感谢您的使用！" << std::endl;
			return;
		default:
			std::cout << "未知命令！" << std::endl;
		}

		// pause();
	}
}
void menu3_4()
{
	int code;
	SqQueue q; // Move queue declaration outside
	ElemType val;
	ElemType dequeued;
	bool isInitialized = false;
	while (true)
	{
		clearScreen();
		std::cout << "\n\t\t\t\t=======顺序队列=======\n"
				  << "\t\t\t\t1. 初始化队列\n"
				  << "\t\t\t\t2. 入队\n"
				  << "\t\t\t\t3. 出队\n"
				  << "\t\t\t\t4. 打印队列\n"
				  << "\t\t\t\t0. 返回\n"
				  << "\t\t\t\t===================================\n";

		std::cout << "\n请输入命令序号: ";
		if (!(std::cin >> code))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "无效输入，请输入数字。" << std::endl;
			pause();
			continue;
		}

		switch ((int)code)
		{
		case 1:
			initQueue(q);
			pause();
			break;
		case 2:
			std::cout << "请输入入队元素值: ";
			std::cin >> val;
			enqueue(q, val);
			std::cout << "入队成功！" << std::endl;
			pause();
			break;
		case 3:
			dequeued = dequeue(q);
			if (dequeued != -1)
				std::cout << "出队成功，出队元素值为: " << dequeued << std::endl;
			pause();
			break;
		case 4:
			printQueue(q);
			pause();
			break;
		case 0:
			std::cout << "感谢您的使用！" << std::endl;
			return;
		default:
			std::cout << "未知命令！" << std::endl;
		}

		// pause();
	}
}

void menu3_5()
{
	int code;
	LinkQueueNode *front = nullptr, *rear = nullptr;
	ElemType val;
	ElemType dequeued;
	bool isInitialized = false;
	while (true)
	{
		clearScreen();
		std::cout << "\n\t\t\t\t=======链式队列=======\n"
				  << "\t\t\t\t1. 初始化队列\n"
				  << "\t\t\t\t2. 入队\n"
				  << "\t\t\t\t3. 出队\n"
				  << "\t\t\t\t4. 打印队列\n"
				  << "\t\t\t\t0. 返回\n"
				  << "\t\t\t\t===================================\n";

		std::cout << "\n请输入命令序号: ";
		if (!(std::cin >> code))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "无效输入，请输入数字。" << std::endl;
			pause();
			continue;
		}

		switch ((int)code)
		{
		case 1:
			initLinkQueue(front, rear);
			break;
		case 2:
			std::cout << "请输入入队元素值: ";
			std::cin >> val;
			enLinkQueue(front, rear, val);
			std::cout << "入队成功！" << std::endl;
			break;
		case 3:
			dequeued = -1;
			if (front != nullptr)
			{
				dequeued = front->data;
				deLinkQueue(front, rear);
			}
			if (dequeued != -1)
				std::cout << "出队成功，出队元素值为: " << dequeued << std::endl;
			pause();
			break;
		case 4:
			printLinkQueue(front);
			pause();
			break;
		case 0:
			std::cout << "感谢您的使用！" << std::endl;
			return;
		default:
			std::cout << "未知命令！" << std::endl;
		}
		// pause();
	}
}
// binary tree
int menu4(void)
{
	/* 题目给出的先序序列，* 表示空指针 */
	const char *preStr = "ABD*G***CE**FH***";

	int idx = 0;
	BiTree T = CreateBiTreeFromPre(preStr, &idx);

	printf("递归先序遍历:   ");
	PreOrderRec(T);
	printf("\n");

	printf("递归中序遍历:   ");
	InOrderRec(T);
	printf("\n");

	printf("递归后序遍历:   ");
	PostOrderRec(T);
	printf("\n\n");

	printf("非递归先序遍历: ");
	PreOrderNonRec(T);
	printf("\n");

	printf("非递归中序遍历: ");
	InOrderNonRec(T);
	printf("\n");

	printf("非递归后序遍历: ");
	PostOrderNonRec(T);
	printf("\n\n");

	int leafCount = CountLeaves(T);
	printf("叶子结点个数: %d\n", leafCount);

	printf("所有叶子结点: ");
	PrintLeaves(T);
	printf("\n");

	printf("二叉树深度: %d\n", TreeDepth(T));

	DestroyTree(T);
	return 0;
}

void menu5()
{
	char s[100], t[100];
	std::cout << "请输入子串: ";
	std::cin >> t;
	std::cout << "请输入主串: ";
	std::cin >> s;
	std::cout << "-----朴素模式匹配-----" << std::endl;
	index(s, t);
	std::cout << "-----KMP模式匹配-----" << std::endl;
	pattern_index(s, t);
	pause();
}

int seq_find(int randomNumbers[], int size, int target)
{
	for (int i = 0; i < size; i++)
	{
		if (randomNumbers[i] == target)
		{
			return i; // 返回目标元素的索引
		}
	}
	return -1; // 未找到目标元素
}

int half_find(int randomNumbers[], int size, int target)
{
	int low, high, mid;
	low = 0;
	high = size - 1;
	while (1)
	{
		mid = (low + high) / 2;
		if (randomNumbers[mid] == target)
			return mid;
		else if (low > high)
		{
			return -1;
		}
		else if (randomNumbers[mid] < target)
		{
			low = mid + 1;
		}
		else if (randomNumbers[mid] > target)
		{
			high = mid - 1;
		}
	}
}
int half_find_recursion(int randomNumbers[], int low, int high, int target)
{
	int mid;
	mid = (low + high) / 2;
	if (randomNumbers[mid] == target)
		return mid;
	else if (low > high)
	{
		return -1;
	}
	else if (randomNumbers[mid] < target)
	{
		return half_find_recursion(randomNumbers, mid + 1, high, target);
	}
	else if (randomNumbers[mid] > target)
	{
		return half_find_recursion(randomNumbers, low, mid - 1, target);
	}
}

void find_menu()
{

	int randomNumbers[30] = {
		845, 129, 678, 933, 401,
		257, 712, 580, 194, 356,
		991, 523, 75, 488, 620,
		315, 876, 11, 749, 902,
		555, 230, 807, 442, 173,
		695, 30, 960, 501, 284};
	int target = 173;
	int size = 30;
	std::cout << "当前数组：";
	for (int i = 0; i < size; i++)
	{
		std::cout << randomNumbers[i] << " ";
	}
	std::cout << "请输入目标数字：" << std::endl;
	std::cin >> target;
	std::cout << "-----顺序查找-----" << std::endl;
	int index1 = seq_find(randomNumbers, size, target);
	if (index1 != -1)
		std::cout << "目标数字 " << target << " 在数组中的索引为: " << index1 << std::endl;
	else
		std::cout << "目标数字 " << target << " 不在数组中。" << std::endl;
	std::cout << "-----折半查找（非递归）-----" << std::endl;
	// 先对数组进行排序
	std::sort(randomNumbers, randomNumbers + size);
	std::cout << "排序后的数组：";
	for (int i = 0; i < size; i++)
	{
		std::cout << randomNumbers[i] << " ";
	}
	std::cout << std::endl;
	int index2 = half_find(randomNumbers, size, target);
	if (index2 != -1)
		std::cout << "目标数字 " << target << " 在数组中的索引为: " << index2 << std::endl;
	else
		std::cout << "目标数字 " << target << " 不在数组中。" << std::endl;
	std::cout << "-----折半查找（递归）-----" << std::endl;
	int index3 = half_find_recursion(randomNumbers, 0, size - 1, target);
	if (index3 != -1)
		std::cout << "目标数字 " << target << " 在数组中的索引为: " << index3 << std::endl;
	else
		std::cout << "目标数字 " << target << " 不在数组中。" << std::endl;
	pause();
}

void bubble_sort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
void insert_sort(int a[], int n)
{
	int i, j, key;
	for (i = 1; i < n; i++)
	{
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}
void select_sort(int a[], int n)
{
	int temp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
void shell_sort(int a[], int n)
{
	int gap, i, j, temp;
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < n; i++)
		{
			temp = a[i];
			for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
			{
				a[j] = a[j - gap];
			}
			a[j] = temp;
		}
	}
}
void quick_sort(int a[], int left, int right)
{
	if (left < right)
	{
		int i = left;
		int j = right;
		int pivot = a[left];
		while (i < j)
		{
			while (i < j && a[j] >= pivot)
				j--;
			if (i < j)
				a[i++] = a[j];
			while (i < j && a[i] <= pivot)
				i++;
			if (i < j)
				a[j--] = a[i];
		}
		a[i] = pivot;
		quick_sort(a, left, i - 1);
		quick_sort(a, i + 1, right);
	}
}
void print_arr(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}
void sort_menu()
{
	clearScreen();
	clock_t start, end;
	double cpu_time_used;
	std::cout << "排序算法演示程序" << std::endl;
	int rand_numbers[30];
	srand((unsigned)time(NULL));
	for (int i = 0; i < 30; i++)
	{
		rand_numbers[i] = rand() % 1000;
	}
	std::cout << "原始数组：" << std::endl;
	print_arr(rand_numbers, 30);
	int sort_numbers[30] = {};

	std::copy(rand_numbers, rand_numbers + 30, sort_numbers);
	start = clock();
	bubble_sort(sort_numbers, 30);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	std::cout << "冒泡排序结果：" << std::endl;
	printf("算法运行时间: %f 秒\n", cpu_time_used);
	print_arr(sort_numbers, 30);
	memset(sort_numbers, 0, sizeof(sort_numbers));

	std::copy(rand_numbers, rand_numbers + 30, sort_numbers);
	start = clock();
	insert_sort(sort_numbers, 30);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	std::cout << "插入排序结果：" << std::endl;
	printf("算法运行时间: %f 秒\n", cpu_time_used);
	print_arr(sort_numbers, 30);
	memset(sort_numbers, 0, sizeof(sort_numbers));

	std::copy(rand_numbers, rand_numbers + 30, sort_numbers);
	start = clock();
	select_sort(sort_numbers, 30);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	std::cout << "选择排序结果：" << std::endl;
	printf("算法运行时间: %f 秒\n", cpu_time_used);
	print_arr(sort_numbers, 30);
	memset(sort_numbers, 0, sizeof(sort_numbers));

	std::copy(rand_numbers, rand_numbers + 30, sort_numbers);
	start = clock();
	shell_sort(sort_numbers, 30);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	std::cout << "希尔排序结果：" << std::endl;
	printf("算法运行时间: %f 秒\n", cpu_time_used);
	print_arr(sort_numbers, 30);
	memset(sort_numbers, 0, sizeof(sort_numbers));

	std::copy(rand_numbers, rand_numbers + 30, sort_numbers);
	start = clock();
	quick_sort(sort_numbers, 0, 29);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	std::cout << "快速排序结果：" << std::endl;
	printf("算法运行时间: %f 秒\n", cpu_time_used);
	print_arr(sort_numbers, 30);
	memset(sort_numbers, 0, sizeof(sort_numbers));

	pause();
}

void menu1()
{
	int code;
	int i;
	int a[10] = {12, 2, 34, 3, 78, 5, 36, 7, 98, 10};
	while (true)
	{
		clearScreen();
		std::cout << "\n\t\t\t\t===========C程序===========\n"
				  << "\t\t\t\t1. 冒泡排序\n"
				  << "\t\t\t\t2. 选择排序\n"
				  << "\t\t\t\t3. 三种交换\n"
				  << "\t\t\t\t0. 返回\n"
				  << "\t\t\t\t==============================\n";

		std::cout << "\n请输入命令序号: ";
		if (!(std::cin >> code))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "无效输入，请输入数字。" << std::endl;
			pause();
			continue;
		}

		switch (code)
		{
		case 1:
			// bubble(a, 10);
			std::cout << "The sorted:";
			for (i = 0; i < 10; i++)
				std::cout << std::setw(5) << a[i];
			std::cout << '\n';
			break;
		case 2:
			break;
		case 3:
			menu1_1();
			break;
		case 4:
			break;
		case 0:
			std::cout << "感谢您的使用！" << std::endl;
			return;
		default:
			std::cout << "未知命令！" << std::endl;
		}

		// pause();
	}
}

void menu2()
{
	int ch1;
	char ch2 = '\0';
	struct tm *pt; /*定义时间结构体*/
	time_t t = time(NULL);
	pt = localtime(&t); /*读取系统日期并把它放到结构体中*/
	do
	{
		clearScreen();
		std::cout << "\t\t当前系统日期:" << (pt->tm_year + 1900) << '-' << (pt->tm_mon + 1) << '-' << pt->tm_mday << '\n';
		std::cout << "===================第二章线性表==================\n";
		std::cout << "\t1. 顺序表\n";
		std::cout << "\t2. 单链表\n";
		std::cout << "\t3. 双链表\n";
		std::cout << "\t4. 循环单链表\n";
		std::cout << "\t5. 应用一 约瑟夫环\n";
		std::cout << "\t6. 应用二\n";
		std::cout << "\t0. 退出\n";
		std::cout << "============================================\n";
		std::cout << "请输入命令序号: ";

		if (!(std::cin >> ch1))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "无效输入，请输入数字。" << std::endl;
			// pause();
			continue;
		}

		switch (ch1)
		{
		case 1:
			menu2_1();
			break;
		case 2:

			menu2_2();
			break;
		case 3:
			menu2_3();
			break;
		case 4:
			menu2_4();
			break;
		case 5:
			menu2_5();
			break;
		case 6:

			break;
		case 0:
			return;
		default:
			std::cout << "未进行任何操作!" << std::endl;
		}
	} while (ch2 == 'y'); // 条件判断
}
void menu3()
{
	int ch1;
	char ch2 = '\0';
	struct tm *pt; /*定义时间结构体*/
	time_t t = time(NULL);
	pt = localtime(&t); /*读取系统日期并把它放到结构体中*/

	do
	{
		clearScreen();
		std::cout << "\t\t当前系统日期:" << (pt->tm_year + 1900) << '-' << (pt->tm_mon + 1) << '-' << pt->tm_mday << '\n';
		std::cout << "===================第三章栈与队列==================\n";
		std::cout << "\t1. 顺序栈\n";
		std::cout << "\t2. 链栈\n";
		std::cout << "\t3. 后缀表达式求值\n";
		std::cout << "\t4. 中缀表达式求值\n";
		std::cout << "\t5. 顺序队列\n";
		std::cout << "\t6. 链队列\n";
		std::cout << "\t0. 退出\n";
		std::cout << "============================================\n";
		std::cout << "请输入命令序号: ";

		if (!(std::cin >> ch1))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "无效输入，请输入数字。" << std::endl;
			// pause();
			continue;
		}

		switch (ch1)
		{
		case 1:
			menu3_1();
			break;
		case 2:
			menu3_2();
			break;
		case 3:
			menu3_3();
			break;
		case 4:
			break;
		case 5:
			menu3_4();
			break;
		case 6:
			menu3_5();
			break;
		case 0:
			return;
		default:
			std::cout << "未进行任何操作!" << std::endl;
		}
	} while (ch2 == 'y'); // 条件判断
}

void main_menu()
{
	int code;
	while (true)
	{
		clearScreen();
		std::cout << "\n\t\t\t\t===========数据结构============\n"
				  << "\t\t\t\t1. 绪论\n"
				  << "\t\t\t\t2. 线性表\n"
				  << "\t\t\t\t3. 栈和队列\n"
				  << "\t\t\t\t4. 树和二叉树\n"
				  << "\t\t\t\t5. 串\n"
				  << "\t\t\t\t6. 图\n"
				  << "\t\t\t\t7. 哈夫曼树\n"
				  << "\t\t\t\t8. 查找\n"
				  << "\t\t\t\t9. 排序\n"
				  << "\t\t\t\t0. 退出系统\n"
				  << "\t\t\t\t==========================================" << std::endl;

		std::cout << "\n请输入命令序号: ";
		if (!(std::cin >> code))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "无效输入，请输入数字。" << std::endl;
			// pause();
			continue;
		}

		switch (code)
		{
		case 1:
			menu1();
			break;
		case 2:
			menu2();
			break;
		case 3:
			menu3();
			break;
		case 4:
			menu4();
			break;
		case 5:
			menu5();
			break;
		case 6:
			graphMain();
			break;
		case 7:
			huffmanMain();
			break;
		case 8: // for testing
			find_menu();
			break;
		case 9:
			sort_menu();
			break;
		case 0:
			std::cout << "欢迎使用本系统！" << std::endl;
			return;
		default:
			std::cout << "未知命令！" << std::endl;
		}

		// pause();
	}
}

int main()
{
	// improve i/o performance slightly
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	main_menu();
	return 0;
}

// --- Helper functions for nicer I/O ---
// Cross-platform clear screen (uses ANSI escape as default; falls back to system call on Windows)
void clearScreen()
{
#ifdef _WIN32
	system("cls");
#else
	// ANSI escape sequence to clear screen and move cursor to home
	std::cout << "\x1B[2J\x1B[H";
#endif
}

void pause()
{
#ifdef _WIN32
	system("pause");
#else
	std::cout << "按回车继续...";
	// flush output and consume leftover newline then wait for Enter
	std::cout.flush();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
#endif
}

// Prompt helper: read two ints with a prompt and basic validation
void promptTwoInts(const std::string &prompt, int &x, int &y)
{
	while (true)
	{
		std::cout << prompt;
		if (std::cin >> x >> y)
			break;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "输入无效，请输入两个整数。" << std::endl;
	}
}
