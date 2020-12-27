#include<stdio.h> 
#include<stdlib.h>
#include<string.h> 
#include<conio.h>
#include<malloc.h>

#define LEN sizeof(struct Student)

#define width 78
//人数 
int n=0;
//结构体 
struct Student
{
	char num[12];
	char name[10];
	float score_M;
	float score_E;
	float score_C;
	float aver;
	float sum;
	struct Student *next;
}*h=NULL; 			//头指针，全局使用 

//************************************************************// 
//****************                           ******************// 
//****************       函数声明            *****************//
//****************                           ******************// 
//************************************************************// 

/*---------------   主要模块函数   -----------------*/
void put(char str[]);
void print(char str[]);
void start_page_return(void);
void start_page_show(void);
char kb_hit(void);
int none_information_warning(int m);
void pause(void);

char find_student(char str[]);
/*---------------   1创建新表   -----------------*/
struct Student *creat_new_table(void); 
float sum_score(struct Student *head);
float average(struct Student *head);
void if_new(void);
int warning_1(void);
int warning_2(void);
int num_input_check(char str[]);
/*---------------   2添加学生  -----------------*/
struct Student *input(struct Student *head,char str[]);
void add_student(struct Student *head);
/*---------------   3删除学生   -----------------*/
void delet_student(void);
struct Student *look_by_num(void);
struct Student *look_by_name(void);
/*---------------   4编辑学生   -----------------*/
void change_student(void);
void change_num(struct Student *p);
void change_name(struct Student *p);
void change_score_M(struct Student *p);
void change_score_E(struct Student *p);
void change_score_C(struct Student *p);
float input_float();
void head_print(struct Student *p);
void re_change(struct Student *p);
/*---------------   5输出所有   -----------------*/
void show_all(struct Student *head);
void head_txt(void);
void print_middle_information(struct Student *head);
void shadow_txt(void);
/*---------------   6查找    -----------------*/
void look_up(struct Student *head);
char look_up_choise(void);
void look_up_num(struct Student *head);
void look_up_name(struct Student *head);
void look_up_rank(struct Student *head);
void look_up_show(struct Student *head);
/*---------------   7统计  -----------------*/
void statistic(void); 
float aver_M(struct Student *head);
float aver_E(struct Student *head);
float aver_C(struct Student *head);
/*---------------   8版本信息   -----------------*/
void version_information(void); 
/*---------------  0退出   -----------------*/
void exit_system(void);

//************************************************************// 
//****************                           ******************// 
//****************       主函数              *****************//
//****************                           ******************// 
//************************************************************// 		

int main(int argc, char* argv[])
{
	//不断循环主功能 
	start_page_return();
	return 0;
}

//************************************************************// 
//****************                           ******************// 
//****************       模块函数            *****************//
//****************                           ******************// 
//************************************************************// 

////////////      开始页展示 ，只负责页面      /////////////
void start_page_show(void)
{
	system("cls");
	put("\n");
	put("*    学生管理系统   *");
	put("*--------------------------------------*");
	put("*-----------------------------*");
	put("*    1  创建新表        *");
	put("*    2  添加学生        *");
	put("*    3  删除学生        *");
	put("*    4  编辑学生        *");
	put("*    5  输出所有信息    *");
	put("*    6  查找            *");
	put("*    7  统计            *");
	put("*    8  版本信息        *");
	put("*    0  退出            *");
	put("*-----------------------------*");
	put("*--------------------------------------*");
	printf("当前学生数： %d",n);
	put("\n");
} 
////////////     居中输出，最后有换行      ///////////// 
void put(char str[])
{
	print(str);//调用无换行居中输出函数 
	printf("\n");
}

////////////     居中输出，最后无换行      ///////////// 
void print(char str[])
{
	int i;
	int blank = (width - strlen(str))/2;//前面的空格数量 
	for(i = 0;i < width;i++)
	{
		if(i==blank)
		{
			printf("%s",str);
			break;
		} else printf(" ");
	}
}
////////////     无信息警告      /////////////
int none_information_warning(int m)
{
	if(m==0)
	{
		system("cls");
		printf("\n\n");
		put("信息为空！");
		printf("\n\n") ;
		put("请录入信息！");
		printf("\n\n\n");
		pause();
		return 0;//无信息返回0 
	}
	else return 1;//有信息返回1 
}
////////////     按键函数      ///////////// 
char kb_hit(void)
{
	char ch;
	if(kbhit())//按下任意一个按键后执行内部操作 
	{
		ch = getch();//获取按键值 
	}
	return (ch);//返回一个按键的值 
 } 
////////////     开始页功能      ///////////// 
void start_page_return(void)
{
	char ch;
	start_page_show(); //开始页打印目录 
	while(1)
	{
		ch=kb_hit();
		if(ch>='0'&&ch<='8')//得到合法按键跳出循环 
			break;
	}
	switch(ch)
	{
		//合法按键执行相应函数 
	case '1':	if_new();	h=creat_new_table();	break;
	case '2':	add_student(h);			break;
	case '3':	delet_student();		break;
	case '4':	change_student();		break;
	case '5':	show_all(h);			break;
	case '6':	look_up(h);				break;
	case '7':	statistic();			break;
	case '8':	version_information();	break;
	case '0':	exit_system();break;
	}
	system("cls");
		//循环调用主要函数，功能功能循环，方便简洁 
	start_page_return();
}
////////////     暂停函数     ///////////// 
void pause(void)
{
	char ch;
	put("\n\n");
	print("*--按回车继续--*");
	while(1)
	{
		ch=kb_hit();
		if(ch==13)
			return;	//只有按下回车才能继续 
	}
	
}




//************************************************************// 
//****************                           ******************// 
//****************       功能块函数          *****************//
//****************                           ******************// 
//************************************************************// 


//**************************   添加新表     **********************************//
////////////     新表警告函数      /////////////  
void if_new(void)
{
	//如果库中有信息，提醒是否创建新表，删除旧信息 
	if(n>0)
	{
		if(warning_1())start_page_return(); 
		if(warning_2())start_page_return(); 	
	}
 } 
 ////////////     创建新表      ///////////// 
struct Student *creat_new_table(void)
{
	struct Student *head;
	head;
	n=0;
	head=NULL; 
	return (input(head,"录入学生信息"));//学生信息录入函数 
}
 ////////////     新表警告函数      ///////////// 
int warning_1(void)
{
	system("cls");
	put("\n\n");
	print("**   创建新表会删除已有的信息！  **");
	put("\n\n");
	put("您确定要执行此操作吗？(Y / N)");
	while(1)
	{
			//按y继续创建新表，按n放弃创建新表 
		if(kb_hit()=='N'||kb_hit()=='n')
			return 1;
		else if(kbhit()=='Y'||kb_hit()=='y')
			return 0;
	}
}
 ////////////     新表最终警告函数  ///////////// 
int warning_2(void)
{
	system("cls"); 
	put("\n\n");
	print("**   创建新表会删除已有的信息！  **");
	put("\n\n");
	print("您确定要删除已有的所有信息吗？(Y / N)") ;
	while(1)
	{
		//按y继续创建新表，按n放弃创建新表 
		if(kb_hit()=='N'||kb_hit()=='n')
			return 1;
		else if(kbhit()=='Y'||kb_hit()=='y')
			return 0;
	}
}
 ////////////    个人平均成绩计算函数    ///////////// 
float average(struct Student *head)
{
	return (sum_score(head)/3);
}
 ////////////    个人总分计算函数    ///////////// 
float sum_score(struct Student *head)
{
	return (head->score_M+head->score_E+head->score_C);
}
 ////////////    信息输入函数    ///////////// 
 //参数为所给的第一个指针
 
struct Student *input(struct Student *head,char str[])
{
	char ch;
	struct Student *p1,*p2;
	p2=head;
	// 可以用于从任一个指针开始创建新数据
 	//添加到所给指针后边 
	p1=( struct Student *)malloc(LEN);//创建新空间 
	while(1)
	{
		system("cls");
		put("\n\n");
		put(str);
		put("\n\n");
		print("您要继续输入信息吗？(Y/N)");
		//每一次都判断是否输入信息 
		while(1)
		{
			ch=kb_hit();
			if(ch=='Y'||ch=='y'||ch=='N'||ch=='n')
				break;
		}
		print("\n\n");
		if(ch=='n'||ch=='N')return (head); 
		else if(ch=='y'||ch=='Y')
		{
			n++;//人数增加 
			print("学号:  ");
			scanf("%s",p1->num);
			if(num_input_check(p1->num))
			input(p1,"添加学生信息");
			print("姓名:  ");
			scanf("%s",p1->name);
			print("数学成绩:  ");
			scanf("%f",&p1->score_M);
			print("英语成绩:  ");
			scanf("%f",&p1->score_E);
			print("C语言成绩:  ");
			scanf("%f",&p1->score_C);
			p1->sum=sum_score(p1);
			p1->aver=average(p1);	
			if(n==1)head=p1;			
			else p2->next=p1;
			p2=p1;
			p1=(struct Student *)malloc(LEN);
			p2->next=NULL;
		}
	}
	return (head);//返回所给的头指针 
}

int num_input_check(char str[])
{
	struct Student *p=h;
	while(p)
	{
		if(strcmp(str,p->num)==0)
		{
			put("已有此学号！");
			put("\n\n\n");
			pause(); 
			return 1;
		}
		else p=p->next;
	} 
	return 0;
}
//**************************     2添加学生      **********************************//
void add_student(struct Student *head)
{
	//若无信息则不进行此操作 
	if(none_information_warning(n)==0)return;
	int m=n-1;
	struct Student *p;
	p=head;
	while(m)
	{
		p=p->next;
		m--;
	}
	//添加学生 
	input(p,"添加学生信息");
} 
//**************************    3删除学生     **********************************//
void delet_student(void)
{
	struct Student *p,*p1;
	p1=h;
	if(none_information_warning(n)==0)return;
	//寻找学生
	switch(find_student("**   你可以通过以下方式找到学生   **"))
	{
		//得到要删除的学生的位置指针 p 
		case '1':	p=look_by_num();		break;//通过学号寻找 
		case '2':	p=look_by_name();		break;//通过姓名寻找 
	}
	if(p==NULL)return;//未找到则不进行任何操作 
	look_up_show(p);//展示查询结果 
	put("\n\n");
	//做最后的询问 
	put("您确定要删除所选信息吗？(Y / N)");
	while(1)
	{
		if(kb_hit()=='N'||kb_hit()=='n')
		{
			start_page_return();
			break;
		}
		else if(kb_hit()=='Y'||kb_hit()=='y')
			break;
	}
	//如果库中有信息 
	if(p!=NULL)
	{
		if(p!=h)//学生位于链表中间或尾部 
		{
			while(p1!=p)
			{
				//找到删除学生的前一个指针 
				p1=p1->next;
			}
			if(p->next!=NULL)
				p1->next=p->next;//将前一个指针指向后面的指针 
			else p1->next = NULL;
			//free(p);//释放此学生的空间
		}
		else if(p==h)//学生位于链表头 
		{
			h=p->next;//让头指针指向后面的指针 
			free(p);//释放空间 
		}
	}
	n--;//人数信息减 1 
	put("\n\n");
	put("**  删除成功  **");
	pause();
} 
 ////////////    通过学号寻找学生    ///////////// 
struct Student *look_by_num(void)
{	struct Student *p;
	char number[12];
	p=h;
	
	system("cls");
	put("\n\n\n"); 
	print("请输入学生的学号：  ");
	scanf("%s",number);
	while(p)
	{
		//如果找到学生，返回学生的指针位置 
		if(strcmp(number,p->num)==0)	
			return (p);
		else
			p=p->next;
	}
	put("\n\n\n");
	//否则显示未查询到信息的结果，并返回NULL 
	print("未查询到此学生");
	pause();
	return NULL;
}
 ////////////    通过姓名查找    ///////////// 
struct Student *look_by_name(void)
{
	struct Student *p;
	char name[10];
	p=h;
	system("cls");
	put("\n\n\n"); 
	print("请输入学生的姓名：  ");
	scanf("%s",name);
	while(p)
	{
		//如果查找到学生，返回学生的指针位置 
		if(strcmp(name,p->name)==0)	
			return (p);
		else
			p=p->next;
	}
	put("\n\n\n");
	//未查找到则返回NULL，显示未查询到结果的信息 
	print("未查询到此学生");
	pause();
	return NULL;
}


//**************************    4编辑学生     **********************************//
void change_student(void)
{
	char ch;
	struct Student *p;
	//如果库中没有信息，则不进行此操作 
	if(none_information_warning(n)==0)return;
	switch(find_student("**   你可以通过以下方式找到学生   **"))
	{
		case '1':	p=look_by_num();		break;
		case '2':	p=look_by_name();		break;
	}
	if(p==NULL)return;
	look_up_show(p);
	//不断进行修改函数 
	re_change(p);
}
 ////////////    不断修改函数     ///////////// 
void re_change(struct Student *p)
{
	char ch;
	system("cls");
	look_up_show(p);
	put("\n\n");
	put("**   请选择编辑项   **");
	put("\n");
	put("*  1. 学号       *"); 
	put("*  2. 姓名       *");
	put("*  3. 数学成绩   *");
	put("*  4. 英语成绩   *");
	put("*  5. C语言成绩  *");
	put("\n\n");
	while(1)
	{
		ch=kb_hit();
		if(ch>='1'&&ch<='5')
			break;
	}
	switch(ch)
	{
		case '1':	change_num(p);		break;
		case '2':	change_name(p);		break;
		case '3':	change_score_M(p);	break;
		case '4':	change_score_E(p);	break;
		case '5':	change_score_C(p);	break;
	}
	head_print(p);
	put("\n\n\n"); 
	print("是否继续对此学生编辑?(Y / N)");
	//是否继续编辑询问 
	while(1)
	{
		ch=kb_hit();
		if(ch=='Y'||ch=='y')
			re_change(p);//继续修改，递归调用函数 
		else if(ch=='N'||ch=='n')
			return ;
	}
}
 ////////////        ///////////// 
void head_print(struct Student *p)
{
	system("cls");
	put("\n");
	look_up_show(p);
	put("\n\n");
} 
 ////////////    改变学生学号    ///////////// 
void change_num(struct Student *p)
{
	head_print(p);
	print("将学号改为:  ");
	scanf("%s",p->num);
}
 ////////////    改变学生姓名    ///////////// 
void change_name(struct Student *p)
{
	head_print(p);
	print("将名字改为:  ");
	scanf("%s",p->name);
}
 ////////////   改变学生数学成绩     ///////////// 
void change_score_M(struct Student *p)
{
	head_print(p);
	print("将数学成绩改为:  ");
	p->score_M=input_float();
}
////////////   改变学生英语成绩     ///////////// 
void change_score_E(struct Student *p)
{
	head_print(p);
	print("将名英语成绩改为:  ");
	p->score_E=input_float();
}	
////////////   改变学生C语言成绩     ///////////// 
void change_score_C(struct Student *p)
{
	head_print(p);
	print("将C语言成绩改为:  ");
	p->score_C=input_float();
}
////////////   返回输入的float型信息     ///////////// 
float input_float()
{
	float n;
	scanf("%f",&n);
	return n;
}
//**************************    5输出所有信息     **********************************//
////////////   表头     ///////////// 
void head_txt(void)
{
	printf("*--------------------------------------------------------------------*\n");
	printf("|   number   |   name   |  Math  | English|    C   | aver |    sum   |\n");
} 
////////////   表的中间信息     ///////////// 
void print_middle_information(struct Student *head)
{
	struct Student *p=head; 
		printf("|------------|----------|--------|--------|--------|------|----------|\n");
		printf("|%12s|%10s|%8.1f|%8.1f|%8.1f|%6.1f|%10.1f|\n",p->num,p->name,p->score_M,p->score_E,p->score_C,p->aver,p->sum);
}
////////////   表尾     ///////////// 
void shadow_txt(void)
{
	printf("*--------------------------------------------------------------------*\n");
}
////////////   学生所有信息输出函数     ///////////// 
void show_all(struct Student *head)
{
	//如果库中没有信息，则不进行此操作 
	if(none_information_warning(n)==0)return;
	system("cls");
	struct Student *p;
	p=h;
	put("\n\n\n");
	put("**   学生信息表   **"); 
	head_txt(); //打印表头 
	if(head!=NULL)
	{
		//打印表中信息 
		do
		{
			print_middle_information(p);
			p=p->next;
		}while(p!=NULL);
		shadow_txt();//打印表尾 
	}
	pause();
}

//**************************    6查找     **********************************//
////////////   查找函数    ///////////// 
void look_up(struct Student *head)
{
	//库中无信息不进行操作 
	if(none_information_warning(n)==0)return;
 	system("cls");
	put("\n\n"); 
	put("**      请选择查询方式      **");
	//选择查询方式 
	switch(find_student("**   信息查询   **"))
	{
		case '1':look_up_num(head);			break;
		case '2':look_up_name(head);		break;
	}
}
////////////   查询方式选择函数    ///////////// 
char find_student(char str[])
{
	system("cls");
	char ch;
	put(str);
 	put("\n\n\n\n"); 
 	put("1.学号");
 	printf("\n");
	put("2.姓名");
	while(1)
	{
		//选择学号查询或者姓名查询 
		ch=kb_hit();
		if(ch>='1'&&ch<='2')
		{
			system("cls");
			put("\n\n"); 
			put(str);
			put("\n\n");
			break;
		}
	}
	return (ch);//返回1或2的按键值 
}
////////////    通过学号寻找     ///////////// 
void look_up_num(struct Student *head)
{
	system("cls");
	char number[12];
	struct Student *p=head;
	p->next;
	put("\n\n\n");
	print("请输入查询的学号：");
	scanf("%s",number); 
	do
	{
		if(strcmp(number,p->num)==0)
		{
			//找到后输出此学生信息 
			look_up_show(p);
			pause();
			return ;
		}
		else 
			p=p->next;
	}while(p!=NULL);
	put("\n\n\n");
	//未找到输出未查询结果 
	print("未查询到此学生");
	pause();
}
////////////     通过姓名查找    ///////////// 
void look_up_name(struct Student *head)
{
	system("cls");
	char Name[10];
	struct Student *p=head;
	p->next;
	put("\n\n\n");
	print("请输入查询的姓名：");
	scanf("%s",Name); 
	do
	{
		if(strcmp(Name,p->name)==0)
		{
			//查询到学生后输出查询结果 
			look_up_show(p);
			pause();
			return ;
		}
		else 
			p=p->next;
	}while(p!=NULL);
	put("\n\n\n");
	print("未查询到此学生");
	pause();
}
////////////    查询结果展示     ///////////// 
void look_up_show(struct Student *head)
{ 
	put("\n\n\n");
	put("**  查询结果  **");
	head_txt();//表头 
	print_middle_information(head);//表中信息 
	shadow_txt();//表尾 
}
//**************************    7统计    **********************************// 
void statistic(void)//统计 
{
	//库中无信息则不进行操作 
	if(none_information_warning(n)==0)return;
	system("cls");
	put("\n\n\n\n\n");
	//输出所有学生三个科目的平均成绩 
	put("**  所有学生各科平均成绩  **");
	put("**--------------------------------**");
	put("|  Math  | English|    C   |");
	put("|--------|--------|--------|");
	printf("                         ");
	printf("|%8.1f|%8.1f|%8.1f|\n",aver_M(h),aver_E(h),aver_C(h));
	put("**--------------------------------**");
	put("\n\n");
	pause();
}
////////////    所有人数学平均成绩     ///////////// 
float aver_M(struct Student *head)
{
	float aver=0;
	struct Student *p=head;
	while(p)
	{
		aver+=p->score_M;
		p=p->next;
	}
	return (aver/n);//返回平均成绩 
}
////////////    所有人英语平均成绩     ///////////// 
float aver_E(struct Student *head)
{
	float aver=0;
	struct Student *p=head;
	while(p)
	{
		aver+=p->score_E;
		p=p->next;
	}
	return (aver/n);
}
////////////    所有人C语言平均成绩     ///////////// 
float aver_C(struct Student *head)
{
	float aver=0;
	struct Student *p=head;
	while(p)
	{
		aver+=p->score_C;
		p=p->next;
	}
	return (aver/n);//返回平均成绩 
}

//**************************    8版本信息     **********************************//
void version_information(void)
{
	system("cls");
	put("\n\n\n\n\n");
	put("**-----------------------------**");
	put("*          版本信息         *");
	put("*                           *");
	put("*    开发人员:FaithBook-_-  *");
	put("*    版本日期：2017.1.4     *"); 
	put("*   哔哩哔哩UID 279353518   *");
	put("**-----------------------------**");
	put("\n\n\n\n\n");
	pause();
}
//**************************    0 退出     **********************************//
void exit_system(void)
{
	system("cls");//清屏 
	//打印表情 
	printf("\n\n\n\n");
	printf(" ￣￣￣￣￣￣￣￣￣￣￣￣)\n");
	printf("  亲！大白等你回来哦！    )\n");
	printf(" ￣￣∨￣￣￣￣￣￣￣￣￣\n\n");
	printf("     ( O - O ) balalala~\n");
	printf("　 ／　　　    '\'\n");
	printf("  /　　　  ○  　'\'\n");
	printf("/　 /  　　   '\'   '\' \n");
	printf("|　/　 　　　  '\'　|\n");
	printf(" '\'?　　　　     ?/\n");
	printf("  卜?　　    ―イ\n");
	printf("　 '\'　　/'\'　  /\n");
	printf("　   ︶　   ︶\n");
	exit(0);//结束程序 
}

