#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

// Simple data structure demo program (refactored I/O)

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

        pause();
    }
}

void menu2_1()
{
    int code;
    while (true)
    {
        clearScreen();
        std::cout << "\n\t\t\t\t=======线性表的顺序存储结构=======\n"
                  << "\t\t\t\t1. create\n"
                  << "\t\t\t\t2. insertpre\n"
                  << "\t\t\t\t3. insertpost\n"
                  << "\t\t\t\t4. deleteV\n"
                  << "\t\t\t\t5. deleteP\n"
                  << "\t\t\t\t6. locate\n"
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
            // create_seq();
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 0:
            std::cout << "感谢您的使用！" << std::endl;
            return;
        default:
            std::cout << "未知命令！" << std::endl;
        }

        pause();
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

        pause();
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
        std::cout << "请选择功能<0-6>: ";

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

            break;
        case 3:

            break;
        case 4:

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

        std::cout << "\n想要继续操作请按 y (否则任意键退出): ";
        std::string yn;
        std::cin >> yn;
        ch2 = yn.empty() ? '\0' : yn[0];
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
                  << "\t\t\t\t3. 串\n"
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
        case 0:
            std::cout << "欢迎使用本系统！" << std::endl;
            return;
        default:
            std::cout << "未知命令！" << std::endl;
        }

        pause();
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
