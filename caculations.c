#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include<math.h>

float Calculate(int i,float num1,float num2)  //������������ʽ�������ظ�����Judge()ϵͳ��׼������
{
	float result;
	switch(i)
	{
	case 1:
	    result=num1+num2;
		break;
	case 2:
		result=num1-num2;
		break;
	case 3:
		result=num1*num2;
		break;
	case 4:
		result=num1/num2;
		break;
	}
	return result;
}

char Operator(int i)   //����ϵͳ�������������ȷ����������ʽ����������ظ�����Judge()�������
{
	char sign;
	switch(i)
	{
	case 1:
		sign='+';
		break;
	case 2:
		sign='-';
		break;
	case 3:
		sign='*';
		break;
	case 4:
		sign='/';
		break;
	default: 
		return 0;
	}
	return sign;
}

int Judge() //�������һ����������ʽ�����жϲ�����������������������������������������0
{
	int num1,num2,num3,m,n,j=0;//num1,num2,num3�����������mΪ��һ�����������Է���,nΪ�ڶ������������Է���,jΪ�û������Ŀ��ȷ����
	float a,b, res,cor;//�м����a,bΪnum1,num2,num3������������û�����������Ϊres��ϵͳ������Ϊcor
	char op1,op2; //��������ȼ��ж�
	do{
		srand(time(NULL));//ʹnum1,num2,num3,c,f��������������Ҳ������ϵͳ���Զ�������������ʽ
		num1=rand()%100+1;//num1,num2,num3������Ϊ1-100֮�������
		num2=rand()%100+1;
		num3=rand()%100+1;
		m=rand()%4+1;// +,-,*,/ ������ֱ�������1-4��ʾ
		n=rand()%4+1;
		if(m>2)//�����жϵ�һ��������Ƿ�˻��
		{
			a=(float)num1;
			b=(float)num2;
			cor=Calculate(m,a,b);
			a=cor;
			b=(float)num3;
			cor=Calculate(n,a,b);
		}
		else
		{
			if(n>2)//������жϵڶ���������Ƿ�˻��
			{
				a=(float)num2;
				b=(float)num3;
				cor=Calculate(n,a,b);
				a=(float)num1;
				b=cor;
				cor=Calculate(m,a,b);	
			}
			else
			{
				a=(float)num1;
				b=(float)num2;
				cor=Calculate(m,a,b);
				a=cor;
				b=(float)num3;
				cor=Calculate(n,a,b);
			}
		}
	}while(cor<0);//ϵͳ������ɵ���������ʽ�������������0������ѭ�����²���һ����������ʽ
	op1=Operator(m);//���������������������ж�
	op2=Operator(n);
	printf("%d %c %d %c %d = ",num1,op1,num2,op2,num3);//��Ļ��ʾ��������ʽ���û�����������
	scanf("%f",&res);
	if(((int)(100.0*res+0.5)/100.0)==((int)(100.0*cor+0.5)/100.0)) //��(int)(100.0*cor+0.5)/100.0)ʹϵͳ���������پ�ȷ��С�����2λ
	{
		j=1;//���û��������������ϵͳ�������Ƚϣ��ж϶Դ�����j��ֵΪ0����ȷj��ֵΪ1
		printf("��ϲ��!������!\n\n",j); 
	}
	else
	{
		printf("������!��ȷ��Ϊ:%.2f\n\n",cor);	
	}   
	return j;  //�����ж��û����������ֵ�Ƿ���ȷ������ȷ��������������������1�������򷵻�0					
}

int main()  //������
{
	int counter,n,yes,i,j;
	float por;
	char word,pr[20],ch;
	while(1)//ϵͳ����
	{
		printf("\n\n");
		printf("\t\t|����������������������������������������|\n");
		printf("\t\t|                                        |\n");
		printf("\t\t|      �� ��ӭʹ����������ϵͳ ��        |\n");
		printf("\t\t|                                        |\n");
        printf("\t\t|    �� ע�����������پ�ȷ2λС�� ��   |\n");
		printf("\t\t|                                        |\n");
		printf("\t\t|           �����ˣ�������               |\n");
		printf("\t\t|                                        |\n");
		printf("\t\t|����������������������������������������|\n");
		printf("\t\t ������ϵͳ����:");  //�������뱣֤ϵͳ�İ�ȫ��
		i=0;
		while((word=getch())!='\r') 
		{
            if(word=='\b' && i>0) 
			{
                printf("\b \b"); //'\b'�������һ���ո�' '���滻�����һ���ַ�
                --i;
            }
            else if(word!='\b') 
			{
                pr[i++]=word;
                printf("*");
            }
		}
        pr[i]='\0';
		if(strcmp(pr,"123456")==0)
		{
			printf("\n\t\t ��������ȷ!��\n");
			Sleep(500);
			system("CLS");
			break;
		}
		else
		{
			printf("\n\t\t ����������!��\n");
			printf("\n\t\t ����2�����������������...");
			Sleep(1000);
			printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b1�����������������...");
			Sleep(1000);
			system("CLS");
		}
	}
lab1:yes=0;
	printf("��������Ŀ����: ");
	scanf("%d",&n);
	printf("\n");
    for(counter=0;counter<n;counter++)	//�Լ�����������+1
	{	
		j=Judge();
		if(j==1)
			yes++; //ͳ���û��ܹ���Ե�����������
	}
	//����ѭ���������n����������ʽ
	por=(float)yes/(float)n*100;
	printf("\t\t���ܹ������%d��!\t\t������׼ȷ��Ϊ:%.2f��!\n\n",yes,por);//�����û������룬���ж϶Դ����ͳ��
	do
	{
		printf("������Ҫ������������������?<y/n>: ");
		getchar();
		scanf("%c",&ch);
		printf("\n");
		if(ch=='y' || ch=='Y')
			goto lab1;   //�������û���������������Ŀ�����������²���n����������ʽ
		else if(ch=='n' || ch=='N')
			return 0;    //�˳����򣬳������н���
		else
			printf("��������������!����������!��\n");
	}while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
	return 0;
}

