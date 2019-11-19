 1 #include<stdio.h>
 2 #include<malloc.h>
 3 #include<stdlib.h>
 4 #include<string.h>
 5 #include<iostream>
 6 using namespace std;
 7 #define OVERFLOW -2
 8 typedef struct Node{
 9     int data;
10     struct Node *next;
11 }Node,*LinkList;
12 
13 int InitList(LinkList &L){
14     L = (LinkList)malloc(sizeof(Node));
15     if(!L)
16         exit(OVERFLOW);
17     L->next = NULL;
18     return 1;
19 }
20 
21 
22 
23 void CreatList(LinkList &L, int n){
24     LinkList p,r;
25     r = L;
26     int a;
27     for(int i = 0; i < n; i++){
28         p = (LinkList)malloc(sizeof(Node));
29         scanf("%d",&a);
30         p->data = a;
31         r->next = p;
32         r = p;
33     }
34     r->next = NULL;
35 }
36 
37 void PrintList(LinkList &L){//输出单链表 
38     LinkList q;
39     q = L->next;
40     while(q){ 
41         printf("%d ",q->data);
42         q = q->next;
43     }  
44 }
45 
46 void Combine(LinkList La, LinkList Lb, LinkList Lc){
47     LinkList pa,pb,pc;
48     pa = La->next;
49     pb = Lb->next;
50     Lc = pc = La;
51     while(pa && pb){
52         if(pa->data <= pb->data){
53             pc->next = pa;
54             pc = pa;
55             pa = pa->next;
56         }
57         else{
58             pc->next = pb;
59             pc = pb;
60             pb = pb->next;
61         }
62     }
63     pc->next = pa? pa:pb;
64     free(Lb);
65     PrintList(Lc);
66 }
67 
68 int main(){
69        int m,n;
70     LinkList LA,LB;
71     InitList(LA);
72     InitList(LB);
73     cout<<"请输入创建单链表LA的元素个数：";
74     cin>>m;
75     CreatList(LA,m);
76     cout<<"请输入创建单链表LB的元素个数：";
77     cin>>n;
78     CreatList(LB,n);
79     cout<<endl; 
80     cout<<"     链表LA中的元素"<<endl;
81     cout<<"-----------------------\n";
82     PrintList(LA);
83     cout<<endl; 
84     cout<<"\n\n     链表LB中的元素"<<endl;
85     cout<<"-----------------------\n";
86     PrintList(LB);
87     cout<<"\n\nLA、LB合并后的输出结果："<<endl;
88     LinkList Lc;
89     InitList(Lc);
90     Combine(LA,LB,Lc); 
91     return 0; 
92 }
