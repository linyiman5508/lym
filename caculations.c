#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include<math.h>

float Calculate(int i,float num1,float num2)  //计算四则运算式，并返回给函数Judge()系统标准计算结果
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

char Operator(int i)   //根据系统随机产生的数字确定四则运算式运算符，返回给函数Judge()运算符号
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

int Judge() //随机生成一条四则运算式，并判断参与四则运算的运算符的运算次序，且运算结果必须大于0
{
	int num1,num2,num3,m,n,j=0;//num1,num2,num3是随机变量；m为第一个运算符随机性服务,n为第二个运算符随机性服务,j为用户答对题目正确条数
	float a,b, res,cor;//中间变量a,b为num1,num2,num3进行运算服务；用户输入运算结果为res，系统运算结果为cor
	char op1,op2; //运算符优先级判断
	do{
		srand(time(NULL));//使num1,num2,num3,c,f输出的是随机数，也就是由系统的自动生成四则运算式
		num1=rand()%100+1;//num1,num2,num3操作数为1-100之间的整数
		num2=rand()%100+1;
		num3=rand()%100+1;
		m=rand()%4+1;// +,-,*,/ 运算符分别用数字1-4表示
		n=rand()%4+1;
		if(m>2)//首先判断第一个运算符是否乘或除
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
			if(n>2)//其次再判断第二个运算符是否乘或除
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
	}while(cor<0);//系统随机生成的四则运算式运算结果必须大于0，否则循环重新产生一条四则运算式
	op1=Operator(m);//对随机产生的运算符进行判断
	op2=Operator(n);
	printf("%d %c %d %c %d = ",num1,op1,num2,op2,num3);//屏幕显示四则运算式，用户输入运算结果
	scanf("%f",&res);
	if(((int)(100.0*res+0.5)/100.0)==((int)(100.0*cor+0.5)/100.0)) //用(int)(100.0*cor+0.5)/100.0)使系统运算结果至少精确到小数点后2位
	{
		j=1;//对用户输入的运算结果与系统运算结果比较，判断对错；错误j的值为0，正确j的值为1
		printf("恭喜你!你答对了!\n\n",j); 
	}
	else
	{
		printf("你答错了!正确答案为:%.2f\n\n",cor);	
	}   
	return j;  //用来判断用户输入的运算值是否正确，若正确，则向主函数返回数字1，错误则返回0					
}

int main()  //主函数
{
	int counter,n,yes,i,j;
	float por;
	char word,pr[20],ch;
	while(1)//系统界面
	{
		printf("\n\n");
		printf("\t\t|————————————————————|\n");
		printf("\t\t|                                        |\n");
		printf("\t\t|      【 欢迎使用四则运算系统 】        |\n");
		printf("\t\t|                                        |\n");
        printf("\t\t|    【 注意运算结果至少精确2位小数 】   |\n");
		printf("\t\t|                                        |\n");
		printf("\t\t|           制作人：林溢漫               |\n");
		printf("\t\t|                                        |\n");
		printf("\t\t|————————————————————|\n");
		printf("\t\t 请输入系统密码:");  //设置密码保证系统的安全性
		i=0;
		while((word=getch())!='\r') 
		{
            if(word=='\b' && i>0) 
			{
                printf("\b \b"); //'\b'后面跟了一个空格' '来替换了最后一个字符
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
			printf("\n\t\t 【密码正确!】\n");
			Sleep(500);
			system("CLS");
			break;
		}
		else
		{
			printf("\n\t\t 【密码有误!】\n");
			printf("\n\t\t 还有2秒可以重新输入密码...");
			Sleep(1000);
			printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b1秒可以重新输入密码...");
			Sleep(1000);
			system("CLS");
		}
	}
lab1:yes=0;
	printf("请输入题目数量: ");
	scanf("%d",&n);
	printf("\n");
    for(counter=0;counter<n;counter++)	//对计算条数不断+1
	{	
		j=Judge();
		if(j==1)
			yes++; //统计用户总共答对的运算结果条数
	}
	//不断循环随机产生n条四则运算式
	por=(float)yes/(float)n*100;
	printf("\t\t你总共答对了%d题!\t\t你答题的准确率为:%.2f％!\n\n",yes,por);//处理用户的输入，并判断对错，打分统计
	do
	{
		printf("请问需要继续进行四则运算吗?<y/n>: ");
		getchar();
		scanf("%c",&ch);
		printf("\n");
		if(ch=='y' || ch=='Y')
			goto lab1;   //继续让用户输入四则运算题目数，程序重新产生n条四则运算式
		else if(ch=='n' || ch=='N')
			return 0;    //退出程序，程序运行结束
		else
			printf("【您的输入有误!请重新输入!】\n");
	}while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
	return 0;
}

