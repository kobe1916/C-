#define _CRT_SECURE_NO_WARNINGS 1

#include "test.h"

void welcome()
{

	system("cls");						//清屏操作
	printf("\n\n\n\n\n\n\n");
	//printf("\t\t1.\n");
	Sleep(400);                        //等待
	system("cls");
	system("color 40");
	printf("\n\n\n\n\n\n\n");
	printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\t\t~********************************************************************************~\n");
	printf("\t\t~  *      *      *  * * * *  *        * * *    * * *       *     *     * * * *   ~\n");
	printf("\t\t~  *      *      *  *        *       *       *       *    * *   * *    *         ~\n");
	printf("\t\t~   *     *     *   * * * *  *      *       *         *  *   * *   *   * * * *   ~\n");
	printf("\t\t~    *  *   *  *    *        *       *       *       *  *     *     *  *         ~\n");
	printf("\t\t~     *       *     * * * *  * * * *  * * *    * * *    *     *     *  * * * *   ~\n");
	printf("\t\t~********************************************************************************~\n");
	printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	Sleep(1200);
	printf("\n\n\n\n\n\n\n");
	system("cls");

	system("cls");						//清屏操作
	printf("\n\n\n\n\n\n\n");
	//printf("\t\t1.\n");
	Sleep(400);                        //等待
	system("cls");

	system("color 70");
	printf("\n\n\n\n\n\n\n");
	printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\t\t~********************************************************************************~\n");
	printf("\t\t~  *      *      *  * * * *  *        * * *    * * *       *     *     * * * *   ~\n");
	printf("\t\t~  *      *      *  *        *       *       *       *    * *   * *    *         ~\n");
	printf("\t\t~   *     *     *   * * * *  *      *       *         *  *   * *   *   * * * *   ~\n");
	printf("\t\t~    *  *   *  *    *        *       *       *       *  *     *     *  *         ~\n");
	printf("\t\t~     *       *     * * * *  * * * *  * * *    * * *    *     *     *  * * * *   ~\n");
	printf("\t\t~********************************************************************************~\n");
	printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	Sleep(1200);
	printf("\n\n\n\n\n\n\n");
	system("cls");
	system("color 07");
	system("cls");						//清屏操作
	printf("\n\n\n\n\n\n\n");
	//printf("\t\t1.\n");
	Sleep(400);                        //等待
	system("cls");

	
	printf("\n\n\n\n\n\n\n");
	printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\t\t~********************************************************************************~\n");
	printf("\t\t~  *      *      *  * * * *  *        * * *    * * *       *     *     * * * *   ~\n");
	printf("\t\t~  *      *      *  *        *       *       *       *    * *   * *    *         ~\n");
	printf("\t\t~   *     *     *   * * * *  *      *       *         *  *   * *   *   * * * *   ~\n");
	printf("\t\t~    *  *   *  *    *        *       *       *       *  *     *     *  *         ~\n");
	printf("\t\t~     *       *     * * * *  * * * *  * * *    * * *    *     *     *  * * * *   ~\n");
	printf("\t\t~********************************************************************************~\n");
	printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	Sleep(1200);
	printf("\n\n\n\n\n\n\n");
	system("cls");
	
}

void menu()
{
	nba *head = NULL;
	welcome();
	int choose = 0;
	do
	{
		system("cls");
		printf("\n\n");
		printf("\t┌****************************************************************┐\n");
		printf("\t│                欢迎来到NBA球员管理系统！！                     │\n");
		printf("\t│-------------------This is why we play! ----------------------  │\n");
		printf("\t│                    1-  录入球员信息                            │\n");
		printf("\t│                    2-  修改球员信息                            │\n");
		printf("\t│                    3-  删除球员信息                            │\n");
		printf("\t│                    4-  查询球员信息                            │\n");
		printf("\t│                    5-  展示所有球员信息                        │\n");
		printf("\t│                    6-  得分排名                                │\n");
		printf("\t│                    7-  篮板排行                                │\n");
		printf("\t│                    8-  助攻排行                                │\n");
		printf("\t│                    9-  查看已存入文件的球员信息                │\n");
		printf("\t│                   10-  保存文件                                │\n");
		printf("\t│                    0-  退出程序                                │\n");
		printf("\t└****************************************************************┘\n");
		printf("\t注意:在未输入任何信息前,只能查看已存信息\n");
		printf("\t欢迎使用NBA球星管理系统，请选择功能0-10：  ");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			head = input(); //接收头结点
			break;    //录入信息
		case 2:
			head = mod(head);  
			//将头结点传入，进行信息的修改，接收修改后新的头结点
			break;      //修改
		case 3:
			del(head);   //删除不需要接收
			break;	  //删除
		case 4:
			search(head);
			break;	  //查找
		case 5:
			show(head);
			break;	  //展示
		case 6:
			score(head);
			break;    //得分
		case 7:
			block(head);
			break;    //篮板
		case 8:
			assist(head);
			break;   //助攻
		case 9:
			DisFil();
			break;     //查看已存入文件的球员信息
		case 10:
			save(head);
			break;    //保存信息到文件
		//case 0:printf("退出程序，再见！\n"); break;
		//default:
			//printf("输入错误，请重新输入！\n"); 
			//因为有清屏操作所以default闪过
		}
		if (choose == 0)    //跳回主界面
			menu;
	} while (choose);
}

int main()
{
	nba *head = NULL;
	sys_menu();

	system("pause");

	return 0;
}

