#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#define N 7

// 1.introduction_switches
void fakeSwitch(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void realSwitchByPointer(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void realSwitchByAlias(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void menu1_1()
{
    int code;
    int a, b;
    while (1)
    {
        system("cls");
        printf("\n\t\t\t\t=======三种交换=======\n");
        printf("\t\t\t\t1. 假交换\n");
        printf("\t\t\t\t2. 真交换（指针）\n");
        printf("\t\t\t\t3. 真交换（别名）\n");
        printf("\t\t\t\t0. 返回\n");
        printf("\t\t\t\t==============================\n");
        printf("\n请输入命令序号:");
        scanf("%d", &code);
        switch (code)
        {
        case 1:
            std::cout << "input a b:";
            std::cin >> a >> b;
            std::cout << "before fakeSwitch a=" << a << " b=" << b << std::endl;
            fakeSwitch(a, b);
            std::cout << "after fakeSwitch a=" << a << " b=" << b << std::endl;
            break;
        case 2:
            std::cout << "input a b:";
            std::cin >> a >> b;
            std::cout << "before realSwitchByPointer a=" << a << " b=" << b << std::endl;
            realSwitchByPointer(&a, &b);
            std::cout << "after realSwitchByPointer a=" << a << " b=" << b << std::endl;
            break;
        case 3:
            std::cout << "input a b:";
            std::cin >> a >> b;
            std::cout << "before realSwitchByAlias a=" << a << " b=" << b << std::endl;
            realSwitchByAlias(a, b);
            std::cout << "after realSwitchByAlias a=" << a << " b=" << b << std::endl;
            break;
        case 0:
            return;
        }
    }
}

void menu2_1()
{
    int code;
    while (true)
    {
        system("cls");
        printf("\n\t\t\t\t=======线性表的顺序存储结构=======\n");
        printf("\t\t\t\t1. create\n");
        printf("\t\t\t\t2. insertpre\n");
        printf("\t\t\t\t3. insertpost\n");
        printf("\t\t\t\t4. deleteV\n");
        printf("\t\t\t\t5. deleteP\n");
        printf("\t\t\t\t6. locate\n");
        printf("\t\t\t\t0. 返回\n");
        printf("\t\t\t\t===================================\n");
        printf("\n请输入命令序号:");
        scanf("%d", &code);

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
            printf("感谢您的使用！");
            return;
        default:
            printf("未知命令！");
        }

        system("pause");
    }
}

void menu1()
{
    int code;
    int i;
    int a[10] = {12, 2, 34, 3, 78, 5, 36, 7, 98, 10};
    while (true)
    {
        system("cls");
        printf("\n\t\t\t\t===========C程序===========\n");
        printf("\t\t\t\t1. 冒泡排序\n");
        printf("\t\t\t\t2. 选择排序\n");
        printf("\t\t\t\t3. 三种交换\n");
        printf("\t\t\t\t0. 返回\n");
        printf("\t\t\t\t==============================\n");
        printf("\n请输入命令序号:");
        scanf("%d", &code);
        switch (code)
        {
        case 1:
            // bubble(a, 10);
            printf("\nThe sorted:");
            for (i = 0; i < 10; i++)
                printf("   %d", a[i]);
            break;
        case 2:
            break;
        case 3:
            menu1_1();
            break;
        case 4:
            break;
        case 0:
            printf("感谢您的使用！");
            return;
        default:
            printf("未知命令！");
        }

        system("pause");
    }
}

void menu2()
{
    int ch1;
    char ch2;
    struct tm *pt; /*定义时间结构体*/
    time_t t;
    t = time(NULL);
    pt = localtime(&t); /*读取系统日期并把它放到结构体中*/
    system("cls");
    do
    {
        printf("\t\t当前系统日期:%d-%d-%d\n", pt->tm_year + 1900, pt->tm_mon + 1, pt->tm_mday); /*显示当前系统日期*/
        printf("===================第二章线性表==================\n");
        printf("	1.顺序表                          		\n");
        printf("	2.单链表                          		\n");
        printf("	3.双链表                 	        	\n");
        printf("	4.循环单链表                        	\n");
        printf("	5.应用一约瑟夫环                       	\n");
        printf("	6.应用二                            	\n");
        printf("	0.退出                                  \n");
        printf("============================================\n");
        printf("请选择功能<0-6>:[ ]\b\b");
        // getchar();
        scanf("%d", &ch1);
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
            printf("未进行任何操作!");
        }
        printf("\n");
        printf("想要继续操作请按y\n");
        getchar();
        scanf("%2c", &ch2);
    } while (ch2 == 'y'); // 条件判断
}

void main_menu()
{
    int code;
    while (true)
    {
        system("cls");
        printf("\n\t\t\t\t===========数据结构============\n");
        printf("\t\t\t\t1. 绪论\n");
        printf("\t\t\t\t2. 线性表\n");
        printf("\t\t\t\t3. 串\n");
        printf("\t\t\t\t0. 退出系统\n");
        printf("\t\t\t\t==========================================");
        printf("\n请输入命令序号:");
        scanf("%d", &code);
        switch (code)
        {
        case 1:
            menu1();
            break;
        case 2:
            menu2();
            break;
        case 0:
            printf("欢迎使用本系统！");
            return;
        default:
            printf("未知命令！");
        }

        system("pause");
    }
}

int main()
{
    main_menu();
    return 0;
}
