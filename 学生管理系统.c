#include<stdio.h> 
#include<stdlib.h>
#include<string.h> 
#include<conio.h>
#include<malloc.h>

#define LEN sizeof(struct Student)

#define width 78
//���� 
int n=0;
//�ṹ�� 
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
}*h=NULL; 			//ͷָ�룬ȫ��ʹ�� 

//************************************************************// 
//****************                           ******************// 
//****************       ��������            *****************//
//****************                           ******************// 
//************************************************************// 

/*---------------   ��Ҫģ�麯��   -----------------*/
void put(char str[]);
void print(char str[]);
void start_page_return(void);
void start_page_show(void);
char kb_hit(void);
int none_information_warning(int m);
void pause(void);

char find_student(char str[]);
/*---------------   1�����±�   -----------------*/
struct Student *creat_new_table(void); 
float sum_score(struct Student *head);
float average(struct Student *head);
void if_new(void);
int warning_1(void);
int warning_2(void);
int num_input_check(char str[]);
/*---------------   2���ѧ��  -----------------*/
struct Student *input(struct Student *head,char str[]);
void add_student(struct Student *head);
/*---------------   3ɾ��ѧ��   -----------------*/
void delet_student(void);
struct Student *look_by_num(void);
struct Student *look_by_name(void);
/*---------------   4�༭ѧ��   -----------------*/
void change_student(void);
void change_num(struct Student *p);
void change_name(struct Student *p);
void change_score_M(struct Student *p);
void change_score_E(struct Student *p);
void change_score_C(struct Student *p);
float input_float();
void head_print(struct Student *p);
void re_change(struct Student *p);
/*---------------   5�������   -----------------*/
void show_all(struct Student *head);
void head_txt(void);
void print_middle_information(struct Student *head);
void shadow_txt(void);
/*---------------   6����    -----------------*/
void look_up(struct Student *head);
char look_up_choise(void);
void look_up_num(struct Student *head);
void look_up_name(struct Student *head);
void look_up_rank(struct Student *head);
void look_up_show(struct Student *head);
/*---------------   7ͳ��  -----------------*/
void statistic(void); 
float aver_M(struct Student *head);
float aver_E(struct Student *head);
float aver_C(struct Student *head);
/*---------------   8�汾��Ϣ   -----------------*/
void version_information(void); 
/*---------------  0�˳�   -----------------*/
void exit_system(void);

//************************************************************// 
//****************                           ******************// 
//****************       ������              *****************//
//****************                           ******************// 
//************************************************************// 		

int main(int argc, char* argv[])
{
	//����ѭ�������� 
	start_page_return();
	return 0;
}

//************************************************************// 
//****************                           ******************// 
//****************       ģ�麯��            *****************//
//****************                           ******************// 
//************************************************************// 

////////////      ��ʼҳչʾ ��ֻ����ҳ��      /////////////
void start_page_show(void)
{
	system("cls");
	put("\n");
	put("*    ѧ������ϵͳ   *");
	put("*--------------------------------------*");
	put("*-----------------------------*");
	put("*    1  �����±�        *");
	put("*    2  ���ѧ��        *");
	put("*    3  ɾ��ѧ��        *");
	put("*    4  �༭ѧ��        *");
	put("*    5  ���������Ϣ    *");
	put("*    6  ����            *");
	put("*    7  ͳ��            *");
	put("*    8  �汾��Ϣ        *");
	put("*    0  �˳�            *");
	put("*-----------------------------*");
	put("*--------------------------------------*");
	printf("��ǰѧ������ %d",n);
	put("\n");
} 
////////////     �������������л���      ///////////// 
void put(char str[])
{
	print(str);//�����޻��о���������� 
	printf("\n");
}

////////////     �������������޻���      ///////////// 
void print(char str[])
{
	int i;
	int blank = (width - strlen(str))/2;//ǰ��Ŀո����� 
	for(i = 0;i < width;i++)
	{
		if(i==blank)
		{
			printf("%s",str);
			break;
		} else printf(" ");
	}
}
////////////     ����Ϣ����      /////////////
int none_information_warning(int m)
{
	if(m==0)
	{
		system("cls");
		printf("\n\n");
		put("��ϢΪ�գ�");
		printf("\n\n") ;
		put("��¼����Ϣ��");
		printf("\n\n\n");
		pause();
		return 0;//����Ϣ����0 
	}
	else return 1;//����Ϣ����1 
}
////////////     ��������      ///////////// 
char kb_hit(void)
{
	char ch;
	if(kbhit())//��������һ��������ִ���ڲ����� 
	{
		ch = getch();//��ȡ����ֵ 
	}
	return (ch);//����һ��������ֵ 
 } 
////////////     ��ʼҳ����      ///////////// 
void start_page_return(void)
{
	char ch;
	start_page_show(); //��ʼҳ��ӡĿ¼ 
	while(1)
	{
		ch=kb_hit();
		if(ch>='0'&&ch<='8')//�õ��Ϸ���������ѭ�� 
			break;
	}
	switch(ch)
	{
		//�Ϸ�����ִ����Ӧ���� 
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
		//ѭ��������Ҫ���������ܹ���ѭ���������� 
	start_page_return();
}
////////////     ��ͣ����     ///////////// 
void pause(void)
{
	char ch;
	put("\n\n");
	print("*--���س�����--*");
	while(1)
	{
		ch=kb_hit();
		if(ch==13)
			return;	//ֻ�а��»س����ܼ��� 
	}
	
}




//************************************************************// 
//****************                           ******************// 
//****************       ���ܿ麯��          *****************//
//****************                           ******************// 
//************************************************************// 


//**************************   ����±�     **********************************//
////////////     �±��溯��      /////////////  
void if_new(void)
{
	//�����������Ϣ�������Ƿ񴴽��±�ɾ������Ϣ 
	if(n>0)
	{
		if(warning_1())start_page_return(); 
		if(warning_2())start_page_return(); 	
	}
 } 
 ////////////     �����±�      ///////////// 
struct Student *creat_new_table(void)
{
	struct Student *head;
	head;
	n=0;
	head=NULL; 
	return (input(head,"¼��ѧ����Ϣ"));//ѧ����Ϣ¼�뺯�� 
}
 ////////////     �±��溯��      ///////////// 
int warning_1(void)
{
	system("cls");
	put("\n\n");
	print("**   �����±��ɾ�����е���Ϣ��  **");
	put("\n\n");
	put("��ȷ��Ҫִ�д˲�����(Y / N)");
	while(1)
	{
			//��y���������±���n���������±� 
		if(kb_hit()=='N'||kb_hit()=='n')
			return 1;
		else if(kbhit()=='Y'||kb_hit()=='y')
			return 0;
	}
}
 ////////////     �±����վ��溯��  ///////////// 
int warning_2(void)
{
	system("cls"); 
	put("\n\n");
	print("**   �����±��ɾ�����е���Ϣ��  **");
	put("\n\n");
	print("��ȷ��Ҫɾ�����е�������Ϣ��(Y / N)") ;
	while(1)
	{
		//��y���������±���n���������±� 
		if(kb_hit()=='N'||kb_hit()=='n')
			return 1;
		else if(kbhit()=='Y'||kb_hit()=='y')
			return 0;
	}
}
 ////////////    ����ƽ���ɼ����㺯��    ///////////// 
float average(struct Student *head)
{
	return (sum_score(head)/3);
}
 ////////////    �����ּܷ��㺯��    ///////////// 
float sum_score(struct Student *head)
{
	return (head->score_M+head->score_E+head->score_C);
}
 ////////////    ��Ϣ���뺯��    ///////////// 
 //����Ϊ�����ĵ�һ��ָ��
 
struct Student *input(struct Student *head,char str[])
{
	char ch;
	struct Student *p1,*p2;
	p2=head;
	// �������ڴ���һ��ָ�뿪ʼ����������
 	//��ӵ�����ָ���� 
	p1=( struct Student *)malloc(LEN);//�����¿ռ� 
	while(1)
	{
		system("cls");
		put("\n\n");
		put(str);
		put("\n\n");
		print("��Ҫ����������Ϣ��(Y/N)");
		//ÿһ�ζ��ж��Ƿ�������Ϣ 
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
			n++;//�������� 
			print("ѧ��:  ");
			scanf("%s",p1->num);
			if(num_input_check(p1->num))
			input(p1,"���ѧ����Ϣ");
			print("����:  ");
			scanf("%s",p1->name);
			print("��ѧ�ɼ�:  ");
			scanf("%f",&p1->score_M);
			print("Ӣ��ɼ�:  ");
			scanf("%f",&p1->score_E);
			print("C���Գɼ�:  ");
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
	return (head);//����������ͷָ�� 
}

int num_input_check(char str[])
{
	struct Student *p=h;
	while(p)
	{
		if(strcmp(str,p->num)==0)
		{
			put("���д�ѧ�ţ�");
			put("\n\n\n");
			pause(); 
			return 1;
		}
		else p=p->next;
	} 
	return 0;
}
//**************************     2���ѧ��      **********************************//
void add_student(struct Student *head)
{
	//������Ϣ�򲻽��д˲��� 
	if(none_information_warning(n)==0)return;
	int m=n-1;
	struct Student *p;
	p=head;
	while(m)
	{
		p=p->next;
		m--;
	}
	//���ѧ�� 
	input(p,"���ѧ����Ϣ");
} 
//**************************    3ɾ��ѧ��     **********************************//
void delet_student(void)
{
	struct Student *p,*p1;
	p1=h;
	if(none_information_warning(n)==0)return;
	//Ѱ��ѧ��
	switch(find_student("**   �����ͨ�����·�ʽ�ҵ�ѧ��   **"))
	{
		//�õ�Ҫɾ����ѧ����λ��ָ�� p 
		case '1':	p=look_by_num();		break;//ͨ��ѧ��Ѱ�� 
		case '2':	p=look_by_name();		break;//ͨ������Ѱ�� 
	}
	if(p==NULL)return;//δ�ҵ��򲻽����κβ��� 
	look_up_show(p);//չʾ��ѯ��� 
	put("\n\n");
	//������ѯ�� 
	put("��ȷ��Ҫɾ����ѡ��Ϣ��(Y / N)");
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
	//�����������Ϣ 
	if(p!=NULL)
	{
		if(p!=h)//ѧ��λ�������м��β�� 
		{
			while(p1!=p)
			{
				//�ҵ�ɾ��ѧ����ǰһ��ָ�� 
				p1=p1->next;
			}
			if(p->next!=NULL)
				p1->next=p->next;//��ǰһ��ָ��ָ������ָ�� 
			else p1->next = NULL;
			//free(p);//�ͷŴ�ѧ���Ŀռ�
		}
		else if(p==h)//ѧ��λ������ͷ 
		{
			h=p->next;//��ͷָ��ָ������ָ�� 
			free(p);//�ͷſռ� 
		}
	}
	n--;//������Ϣ�� 1 
	put("\n\n");
	put("**  ɾ���ɹ�  **");
	pause();
} 
 ////////////    ͨ��ѧ��Ѱ��ѧ��    ///////////// 
struct Student *look_by_num(void)
{	struct Student *p;
	char number[12];
	p=h;
	
	system("cls");
	put("\n\n\n"); 
	print("������ѧ����ѧ�ţ�  ");
	scanf("%s",number);
	while(p)
	{
		//����ҵ�ѧ��������ѧ����ָ��λ�� 
		if(strcmp(number,p->num)==0)	
			return (p);
		else
			p=p->next;
	}
	put("\n\n\n");
	//������ʾδ��ѯ����Ϣ�Ľ����������NULL 
	print("δ��ѯ����ѧ��");
	pause();
	return NULL;
}
 ////////////    ͨ����������    ///////////// 
struct Student *look_by_name(void)
{
	struct Student *p;
	char name[10];
	p=h;
	system("cls");
	put("\n\n\n"); 
	print("������ѧ����������  ");
	scanf("%s",name);
	while(p)
	{
		//������ҵ�ѧ��������ѧ����ָ��λ�� 
		if(strcmp(name,p->name)==0)	
			return (p);
		else
			p=p->next;
	}
	put("\n\n\n");
	//δ���ҵ��򷵻�NULL����ʾδ��ѯ���������Ϣ 
	print("δ��ѯ����ѧ��");
	pause();
	return NULL;
}


//**************************    4�༭ѧ��     **********************************//
void change_student(void)
{
	char ch;
	struct Student *p;
	//�������û����Ϣ���򲻽��д˲��� 
	if(none_information_warning(n)==0)return;
	switch(find_student("**   �����ͨ�����·�ʽ�ҵ�ѧ��   **"))
	{
		case '1':	p=look_by_num();		break;
		case '2':	p=look_by_name();		break;
	}
	if(p==NULL)return;
	look_up_show(p);
	//���Ͻ����޸ĺ��� 
	re_change(p);
}
 ////////////    �����޸ĺ���     ///////////// 
void re_change(struct Student *p)
{
	char ch;
	system("cls");
	look_up_show(p);
	put("\n\n");
	put("**   ��ѡ��༭��   **");
	put("\n");
	put("*  1. ѧ��       *"); 
	put("*  2. ����       *");
	put("*  3. ��ѧ�ɼ�   *");
	put("*  4. Ӣ��ɼ�   *");
	put("*  5. C���Գɼ�  *");
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
	print("�Ƿ�����Դ�ѧ���༭?(Y / N)");
	//�Ƿ�����༭ѯ�� 
	while(1)
	{
		ch=kb_hit();
		if(ch=='Y'||ch=='y')
			re_change(p);//�����޸ģ��ݹ���ú��� 
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
 ////////////    �ı�ѧ��ѧ��    ///////////// 
void change_num(struct Student *p)
{
	head_print(p);
	print("��ѧ�Ÿ�Ϊ:  ");
	scanf("%s",p->num);
}
 ////////////    �ı�ѧ������    ///////////// 
void change_name(struct Student *p)
{
	head_print(p);
	print("�����ָ�Ϊ:  ");
	scanf("%s",p->name);
}
 ////////////   �ı�ѧ����ѧ�ɼ�     ///////////// 
void change_score_M(struct Student *p)
{
	head_print(p);
	print("����ѧ�ɼ���Ϊ:  ");
	p->score_M=input_float();
}
////////////   �ı�ѧ��Ӣ��ɼ�     ///////////// 
void change_score_E(struct Student *p)
{
	head_print(p);
	print("����Ӣ��ɼ���Ϊ:  ");
	p->score_E=input_float();
}	
////////////   �ı�ѧ��C���Գɼ�     ///////////// 
void change_score_C(struct Student *p)
{
	head_print(p);
	print("��C���Գɼ���Ϊ:  ");
	p->score_C=input_float();
}
////////////   ���������float����Ϣ     ///////////// 
float input_float()
{
	float n;
	scanf("%f",&n);
	return n;
}
//**************************    5���������Ϣ     **********************************//
////////////   ��ͷ     ///////////// 
void head_txt(void)
{
	printf("*--------------------------------------------------------------------*\n");
	printf("|   number   |   name   |  Math  | English|    C   | aver |    sum   |\n");
} 
////////////   ����м���Ϣ     ///////////// 
void print_middle_information(struct Student *head)
{
	struct Student *p=head; 
		printf("|------------|----------|--------|--------|--------|------|----------|\n");
		printf("|%12s|%10s|%8.1f|%8.1f|%8.1f|%6.1f|%10.1f|\n",p->num,p->name,p->score_M,p->score_E,p->score_C,p->aver,p->sum);
}
////////////   ��β     ///////////// 
void shadow_txt(void)
{
	printf("*--------------------------------------------------------------------*\n");
}
////////////   ѧ��������Ϣ�������     ///////////// 
void show_all(struct Student *head)
{
	//�������û����Ϣ���򲻽��д˲��� 
	if(none_information_warning(n)==0)return;
	system("cls");
	struct Student *p;
	p=h;
	put("\n\n\n");
	put("**   ѧ����Ϣ��   **"); 
	head_txt(); //��ӡ��ͷ 
	if(head!=NULL)
	{
		//��ӡ������Ϣ 
		do
		{
			print_middle_information(p);
			p=p->next;
		}while(p!=NULL);
		shadow_txt();//��ӡ��β 
	}
	pause();
}

//**************************    6����     **********************************//
////////////   ���Һ���    ///////////// 
void look_up(struct Student *head)
{
	//��������Ϣ�����в��� 
	if(none_information_warning(n)==0)return;
 	system("cls");
	put("\n\n"); 
	put("**      ��ѡ���ѯ��ʽ      **");
	//ѡ���ѯ��ʽ 
	switch(find_student("**   ��Ϣ��ѯ   **"))
	{
		case '1':look_up_num(head);			break;
		case '2':look_up_name(head);		break;
	}
}
////////////   ��ѯ��ʽѡ����    ///////////// 
char find_student(char str[])
{
	system("cls");
	char ch;
	put(str);
 	put("\n\n\n\n"); 
 	put("1.ѧ��");
 	printf("\n");
	put("2.����");
	while(1)
	{
		//ѡ��ѧ�Ų�ѯ����������ѯ 
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
	return (ch);//����1��2�İ���ֵ 
}
////////////    ͨ��ѧ��Ѱ��     ///////////// 
void look_up_num(struct Student *head)
{
	system("cls");
	char number[12];
	struct Student *p=head;
	p->next;
	put("\n\n\n");
	print("�������ѯ��ѧ�ţ�");
	scanf("%s",number); 
	do
	{
		if(strcmp(number,p->num)==0)
		{
			//�ҵ��������ѧ����Ϣ 
			look_up_show(p);
			pause();
			return ;
		}
		else 
			p=p->next;
	}while(p!=NULL);
	put("\n\n\n");
	//δ�ҵ����δ��ѯ��� 
	print("δ��ѯ����ѧ��");
	pause();
}
////////////     ͨ����������    ///////////// 
void look_up_name(struct Student *head)
{
	system("cls");
	char Name[10];
	struct Student *p=head;
	p->next;
	put("\n\n\n");
	print("�������ѯ��������");
	scanf("%s",Name); 
	do
	{
		if(strcmp(Name,p->name)==0)
		{
			//��ѯ��ѧ���������ѯ��� 
			look_up_show(p);
			pause();
			return ;
		}
		else 
			p=p->next;
	}while(p!=NULL);
	put("\n\n\n");
	print("δ��ѯ����ѧ��");
	pause();
}
////////////    ��ѯ���չʾ     ///////////// 
void look_up_show(struct Student *head)
{ 
	put("\n\n\n");
	put("**  ��ѯ���  **");
	head_txt();//��ͷ 
	print_middle_information(head);//������Ϣ 
	shadow_txt();//��β 
}
//**************************    7ͳ��    **********************************// 
void statistic(void)//ͳ�� 
{
	//��������Ϣ�򲻽��в��� 
	if(none_information_warning(n)==0)return;
	system("cls");
	put("\n\n\n\n\n");
	//�������ѧ��������Ŀ��ƽ���ɼ� 
	put("**  ����ѧ������ƽ���ɼ�  **");
	put("**--------------------------------**");
	put("|  Math  | English|    C   |");
	put("|--------|--------|--------|");
	printf("                         ");
	printf("|%8.1f|%8.1f|%8.1f|\n",aver_M(h),aver_E(h),aver_C(h));
	put("**--------------------------------**");
	put("\n\n");
	pause();
}
////////////    ��������ѧƽ���ɼ�     ///////////// 
float aver_M(struct Student *head)
{
	float aver=0;
	struct Student *p=head;
	while(p)
	{
		aver+=p->score_M;
		p=p->next;
	}
	return (aver/n);//����ƽ���ɼ� 
}
////////////    ������Ӣ��ƽ���ɼ�     ///////////// 
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
////////////    ������C����ƽ���ɼ�     ///////////// 
float aver_C(struct Student *head)
{
	float aver=0;
	struct Student *p=head;
	while(p)
	{
		aver+=p->score_C;
		p=p->next;
	}
	return (aver/n);//����ƽ���ɼ� 
}

//**************************    8�汾��Ϣ     **********************************//
void version_information(void)
{
	system("cls");
	put("\n\n\n\n\n");
	put("**-----------------------------**");
	put("*          �汾��Ϣ         *");
	put("*                           *");
	put("*    ������Ա:FaithBook-_-  *");
	put("*    �汾���ڣ�2017.1.4     *"); 
	put("*   ��������UID 279353518   *");
	put("**-----------------------------**");
	put("\n\n\n\n\n");
	pause();
}
//**************************    0 �˳�     **********************************//
void exit_system(void)
{
	system("cls");//���� 
	//��ӡ���� 
	printf("\n\n\n\n");
	printf(" ������������������������)\n");
	printf("  �ף���׵������Ŷ��    )\n");
	printf(" �����ţ�����������������\n\n");
	printf("     ( O - O ) balalala~\n");
	printf("�� ��������    '\'\n");
	printf("  /������  ��  ��'\'\n");
	printf("/�� /  ����   '\'   '\' \n");
	printf("|��/�� ������  '\'��|\n");
	printf(" '\'?��������     ?/\n");
	printf("  ��?����    �D��\n");
	printf("�� '\'����/'\'��  /\n");
	printf("��   �ᡡ   ��\n");
	exit(0);//�������� 
}

