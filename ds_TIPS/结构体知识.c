#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#define MAXTITL  100
#define MAXAUTL  100
//�ȶ���һ���ṹ��
typedef struct
{
	char name[20];
	float maxscore;
	float midscore;
}stu;
struct book
{
	char name[20];
	char author[20];
	float price;
}
void Average(stu *s)//��������Ϊ�ṹ�� 
{
	s->maxscore=50;
	s->midscore=50;
}
int main()
{
	stu s1={"duqirong",100,98};
	printf("%f\n",(s1.maxscore+s1.midscore)/2);
	Average(&s1);
	printf("%f\n",(s1.maxscore+s1.midscore)/2);
	return 0;
}
/*
ѡ��������г��ֵ�֪ʶ�����ṹ��
�ṹ�彫��ͬ���͵����ݴ����һ����Ϊһ�����崦��
�����ڴ���һ��ѧ������Ϣ��ѧ��(�ַ���)������(�ַ���)������(����)�ȵ�
�ṹ�������һ����ǿ�˱�ʾ���ݵ�����
һ.�ṹ������
 struct book
{
	char title [MAXTITL];//�ַ�����ʾ��Ŀ 
	char author[MAXAUTL];//�ַ�����ʾ���� 
	flaot value;//�����ͱ�ʾ�۸� 
};      //ע��ֺŲ����٣��ṹ��Ҳ�൱��һ����� 
����������һ���������ַ������һ��float������ɵĽṹ��
ע�⣺����û�д���һ��ʵ�ʵ����ݶ��󣬶���������һ�������������Ԫ��
struct book library ������Ż�Ϊ������ڴ�ռ� 
�ṹ��������
1.����ʹ�ùؼ��֣�struct��,��ʾ��������һ���ṹ��
2.������һ����ѡ�ı�־(book)�������������øýṹ��Ŀ��ٱ��
�����Ժ���������������ݶ���
struct book library;//��library��Ϊһ������ʹ��book�ṹ��Ľṹ����� 
��library�Ͱ�����book�ṹ���е�����Ԫ��
3.�������нṹ���Ա�б�
��Ա����ʹ���κ�һ���������������������Ľṹ��
4.�����ź�ķֺű�ʾ�ṹ����ƶ���Ľ���
  
  
��.�ṹ���������
�ṹ���������κκ��������� �����ѡ��ǿ����ڱ��ļ���
������֮������к���������ʹ�ã�������ĳ�������ڲ�����ֻ�����ڲ�ʹ�ã�����������֮��
 struct book
{
	char title [MAXTITL];//�ַ�����ʾ��Ŀ 
	char author[MAXAUTL];//�ַ�����ʾ���� 
	float value;//�����ͱ�ʾ�۸� 
};//ע��ֺŲ����٣��ṹ��Ҳ�൱��һ����� 
int main()
{
	struct book s1={//�ṹ���ʼ�� s1����book�ṹ�� 
		"yuwen",
		"guojiajiaoyu",
		22.5
	};
	printf("%s",s1.title);//���ʽṹ�����Ԫ�� 
   return 0;
}
ע�⣺�ṹ�����������и�����������֮���ԷֺŸ������ṹ���ʼ�����������Զ��Ÿ���
 ���ʽṹ�����Ԫ�أ��ṹ������� . �������� 
struct book�����þ��� int ,������һ����������
struct s1,s2,*ss;
����������struct book���͵Ľṹ���������������һ��ָ��ýṹ���ָ��
�ṹ�嶨��
struct book library ;
��Ч��
struct book{
char ...
...
...
}library;

��.��ѡ��־������ʡ�Ե����
1.ֱ�Ӵ����ṹ������������������ṹ������
 struct
{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
}library;
��������ȱ����ֻ��ʹ��һ�Σ����ɸ���
2.typedef(��ʱ�ӹ�)
 ��
 
��.�ṹ��ĳ�ʼ��
�û��������������ö��ŷָ���ʼ����Ŀ�б�
��ʼ����Ŀ���ʼ���Ľṹ���Ա������ƥ��
�ڶ���ṹ�������ʱ��û�г�ʼ��������Ͳ���һ���ʼ�� 
//�ڶ���ʱ��ʼ�� 
struct book s1={//�ṹ���ʼ�� 
		"yuwen",
		"guojiajiaoyu",
		22.5
	};
//����ʱδ��ʼ��
	struct book s2;
	 s2={
	"shuxue",
	"jilinjiaoyu",
	199.0
	};
���ָ�ֵ��ʽ�Ǵ���ģ�����ʱδ��ʼ��
����ֻ�ܶԵ���������ֵ
��  s2.value=22.5;	
     strcpy(s2.title,"shuxue");
     ע����ַ���������ֵ����ʹ��=
	 s2.title="shuxue"����
	 Ҫʹ��strcpy���� 
	 
���ڽṹ���ָ����ʼ��(ֻ������c99������)
 struct book s1={//�ṹ���ʼ�� 
	  .value=16.9
	  .title="yuwen",
	  .author="guojiajiaoyu",
		22.5
	};
���Բ��ϸ��ճ�Ա�б�˳���ʼ��
���ֵΪ22.5�������ĸ�ֵΪ׼	
ʵ��֤�������ݽṹҪ���.c�ļ����޷�ʵ�� 

���ʽṹ���Ա
�ṹ�������.��Ա��   .��Ϊ��Ա����� 
 .����������ȼ�����&(.��������ȼ�����ߵ�)
 scanf("%d",&s1.age); �������Ŀ�����   ����д��scanf("%d",&(s1.age));
  
  ���ṹ��ĳ�Ա�������ǽṹ��
  ����ͨ�����ʹ�ó�Ա�����.ʵ�����ݷ���
  ������.�ӳ�Ա.��һ���ӳ�Ա.����һ��...... 
  struct date
{
    int year;
    int month;
    int day;
};
struct student
{
    char name[10];
    struct date birthday;
}student1;
//��������student�ĳ��������գ��ɱ�ʾΪ��student.brithday.year��
brithday��student�ĳ�Ա��year��brithday�ĳ�Ա��

��.������ֿ�
1.���Խ�һ���ṹ�������Ϊһ�����帳ֵ����һ��ͬ���͵Ľṹ�����
ÿ����Ա������ֵ����ȫ�����帳ֵ������һ������
2.���ܽ��ṹ�������Ϊһ�������������������
����������ṹ������ʱ������ָ���ṹ������ĸ���Ա
 struct date
{
	int year;
	int month;
	int day;
};
struct student
{
	char name[10];
	struct date birthday;//�ṹ���Ƕ�� 
};
int main()
{
	struct student student1={
		"dqremperor",
		2004,
		9,  //��Ƕ�׵Ľṹ�帳ֵ 
		3,
	};
	struct student student2;
	student2 = student1;//�ṹ������帳ֵ 
	printf("%s %d %d %d\n",student1.name,student1.birthday.year,student1.birthday.month,student1.birthday.day);
	printf("%s %d %d %d\n",student2.name,student2.birthday.year,student2.birthday.month,student2.birthday.day);
	return 0;
}
���Կ���1.Ƕ�׽ṹ���У��ڲ�ṹ�������ṹ��һͬ��ֵ
���Ǳ�дǶ�׽ṹ���ʱ��һ��Ҫע�⣺�ṹ���ڶ����Ż���Ч
��ĸ�ṹ���������ӽṹ��ʱ��һ��Ҫȷ���ӽṹ���Ѿ���ĸ�ṹ��֮ǰ����
    2.�������ʱָ���ṹ�������Ա

��.�ṹ������
֮ǰbook���͵Ľṹ��
struct book book1
{
   char name[10];
   char author[10];
   int price;
}
struct book���Ϊbook���͵�struct(�ṹ��)
���Ҫ��¼�ܶ౾���أ�
�ṹ�����飡
 
 6.1�����ṹ������
 struct book library[10];
 struct bookΪ����Ԫ�����ͣ�libraryΪ������
 [10]Ϊ������10��struct book ��Ԫ���ڴ�
 libraryΪһ������10��Ԫ�ص����飬ÿ��Ԫ�ض���
 book���͵Ľṹ��library[0],library[1]...���ǵ���������book�ṹ
 
 6.2�ṹ�������ʼ��
 struct student 
{
	char name[10];
	int age;
	int num;
};
int main()
{
	struct student array[3]={
		{
			"duqirong",
			18,
			18,
		},
		{
			"fengyuqing",
			18,
			19,
		},
		{
			"guomiao",
			18,
			20,
		}
			};
	int i;
	for(i=0;i<3;i++)
	{
		printf("��%d��ѧ������Ϣ��������%s�����䣺%d,ѧ�ţ�%d\n",i+1,array[i].name,array[i].age,array[i].num);
	}
	return 0;
} 
���ʽṹ������ĳ�Ա
library[2].title[5],�������ṹ��ĵ������ַ� 
array[0].age;

��.ָ��ṹ���ָ��
struct +�ṹ����+*+ָ����
struct student *dqr;  //ָ��student���ͽṹ���ָ�����dqr;
dqr= &student1[0];//ָ��ṹ������ĵ�һ��Ԫ��
ʹ��ָ���ýṹ������Ԫ���еĳ�Ա
//����1������һ�������  ->
->���ڽṹ��ָ����ʳ�Ա
. ���ڽṹ�������ʳ�Ա
��Ϊָ���Ѿ�ָ����һ���ṹ��Ԫ�أ�����Ҫ���ʸýṹ���е�ĳ��Ԫ��
д�� ptr->name���� Ҳ����д��  dqr[0].name;
//������������&��*�ǻ���������
 (*ptr).name ��Ϊ.�����ȼ���ߣ�ע�������
  
 
��.�������ݽṹ����Ϣ
8.1���ݽṹ���Ա
�ṹ���Ա�Ǿ��е�ֵ���������ͣ��Ϳ��԰�����Ϊ�������ݸ�һ����������ض��������͵ĺ���
���ֻ��ʵ�ַ��ʣ������޸�
8.2ʹ�ýṹ���ַ
typedef struct 
{
	char name[20];
	float maxscore;
	float midscore;
}stu;//�ѽṹ����������Ϊstu
int Average(const stu * s)//ʹ��ָ�����
{
	return (s->maxscore + s->midscore)/2;
 } 
int main()
{
	stu s1={"duqirong",100,95};
	int average=Average(&s1);
	printf("%d",average);
	return 0;
}
3.ʹ�ýṹ����Ϊ�������� 
int Average(stu  s)//ʹ�ýṹ�����
{
	return (s.maxscore + s.midscore)/2;
 } 
int main()
{
	stu s1={"duqirong",100,95};
	int average=Average(s1);
	printf("%d",average);
	return 0;
}
�ýṹ����Ϊ��������ֻ��ԭ���ṹ��ĸ���
Ҫ����ú����޸�ʵ�νṹ�������ֵ��ֻ�ܴ��ݵ�ַ��ͨ��ָ���޸�

�� int Average(const stu * s)//ʹ��ָ�����,����ʹ��const���������޸ģ�����ı�ṹ�������ݵ�ֵ 
{
	return (s->maxscore + s->midscore)/2;
 } 
 int Average(stu  s)//ʹ�ýṹ�����
{
	return (s.maxscore + s.midscore)/2;
 } 
 ԭ���ϣ��ڵ������������ʱ�򣬻����stuģ�崴��һ���Զ�����s��
 �ú�ԭ��s1��ֵ��ֵ�������൱��s��s1�ĸ���
 ���ֻ�ܷ����޷��޸ģ���Ϊ�޸�ֻ�����޸��βε�ֵ
 ����ʵ����Ӱ�죬Ҫ���޸�ʵ�ε�ֵ��ֻ�ܴ��ݵ�ַ������ָ�벻�ܱ�const����
 4.�ṹ��Ϊ�������޸Ľṹ�岢�ҷ�������ҲΪ�ṹ��
 ���Դﵽ�޸ĵ�Ŀ��
stu Average(stu s)//��������Ϊ�ṹ�� 
{
	printf("%f\n",(s.maxscore+s.midscore)/2);
	s.maxscore=50;
	s.midscore=0;
	return s;
}
int main()
{
	stu s1={"duqirong",100,98};
	stu s2=Average(s1);
	printf("%f\n",(s2.maxscore+s2.midscore)/2);
	printf("%f\n",(s1.maxscore+s1.midscore)/2);
	return 0;
}
4.���ݵ�ַ��ʹ�ýṹ��ָ����ܣ������޸ģ�������const��������
 void Average(stu *s)//��������Ϊ�ṹ�� 
{
	s->maxscore=50;
	s->midscore=50;
}


��.����ʹ���ַ�����洢�ַ���
 struct book
{
	char name[20];
	char author[20];
	float price;
}

����
struct tag
{
 member-list 
}variavble-list;

struct �ǽṹ��ؼ��� 
tag�ǽṹ�����������ֳ�Ϊ�ṹ��ı�־
struct tag Ϊ�û�����Ľṹ���� 
member-list Ϊ�ṹ���Ա�б�
variable-list Ϊ�ṹ��ı�����
 
*/

