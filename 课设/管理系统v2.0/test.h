#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

//多文件下结构体必须定义在头文件中


//球员信息
typedef struct nba      //球员信息
{
	char name[20];      //姓名
	int num;			//号码
	char team[20];		//球队
	float score;		//得分
	float block;		//篮板
	float assist;       //助攻
	struct nba *next;
}nba;


//管理员信息
typedef struct name
{
	char name[20];
	char pwd[20];
}name;

int pd(name signin);
//void sign();
void login();
void sys_menu();
void guanli();
void zhuce();
void shanchu();
void Admin();

nba *input();
nba *mod(head);
nba *del(head);

nba *search(head);
nba *show(head);
nba *score(head);
nba *block(head);
nba *assist(head);
nba *DisFil();
nba *save(head);
