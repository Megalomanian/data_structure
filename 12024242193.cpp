#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <sstream>
#define MAXSIZE 100
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
    L->next = L;      // Initialize circular link
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
        tail = newNode;    // Move tail to the new node
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
// --- Menus ---
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
            std::cout << "\nThe sorted:";
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
            // menu3_4();
            break;
        case 5:
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
