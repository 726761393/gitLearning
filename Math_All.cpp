#include<iostream>
#include<ctime>
using namespace std;

double count(double x,double y,int sign);
double result(double random1,double random2,double random3,double random4,int sign1,int sign2,int sign3);
double writecount(double random1,double random2,double random3,double random4,int sign1,int sign2,int sign3,bool *ifgo,int a,bool *rewrite);
char sign(int a);
bool Chinese;
int main(){
	double random1,random2,random3,random4;
	int sign1,sign2,sign3,bingo_number=0;
	char ifstart,language;
	bool start=false,ifgo=true,rewrite=false;
	cout<<"####����С������ʹ�����Ļ���Ӣ���أ�(���İ�C��Ӣ�İ�E)####"<<endl;
	cout<<"####Does the child use Chinese or English?��Chinese click C,else click E��####"<<endl;
	cin>>language;
	if(language=='C')  Chinese=true;
	if(language=='E')  Chinese=false;
	if(Chinese){cout<<"####��ӭС���ѵĵ���####"<<endl;
	cout<<"####�Ƿ�ʼѵ����Y/N��####"<<endl;
}
	else {	cout<<"####Welcome the arrival of you####"<<endl;
	cout<<"####Whether to start training��Y/N��####"<<endl; }
	cin>>ifstart;
	if(ifstart=='Y'){
	  start=true;
	}else {if(Chinese) cout<<"####С�����ټ�####"<<endl;else cout<<"####Bye bye####"<<endl; }
	if(start){
	while(ifgo){
		srand(time(0)); 
		random1=rand()%10;
		random2=rand()%10;
		random3=rand()%10;
		random4=rand()%10;
		sign1=rand()%6;
		sign2=rand()%6;
		sign3=rand()%6;
		ifgo=false;
		writecount(random1,random2,random3,random4,sign1,sign2,sign3,&ifgo,bingo_number,&rewrite);
		if(ifgo==true)bingo_number++;
		if(rewrite==true) {ifgo=true;rewrite=false;}
	 }
	}
	return 0;
}
double writecount(double random1,double random2,double random3,double random4,int sign1,int sign2,int sign3,bool *ifgo,int a,bool *rewrite){
	bool ifinteger;
	char ifstart;
	double answer;
	double ifneed=result(random1,random2,random3,random4,sign1,sign2,sign3);

	if(ifneed>10000||ifneed<0){*rewrite=true;return 0;}
	int temp=ifneed*1000;

	if(sign1>3&&sign2<=3&&sign3<=3)
		cout<<"("<<random1 <<sign(sign1) <<random2<<")"<<sign(sign2) <<random3 <<sign(sign3)<<random4<<"=?"<<endl;
	else if(sign1>3&&sign2>3&&sign3<=3)
		cout<<"("<<random1 <<sign(sign1) <<random2 <<sign(sign2) <<random3 <<")"<<sign(sign3)<<random4<<"=?"<<endl;
	else if(sign1>3&&sign2<=3&&sign3>3)
		cout<<"("<<random1 <<sign(sign1) <<random2<<")" <<sign(sign2) <<"("<<random3 <<sign(sign3)<<random4<<")"<<"=?"<<endl;
	else if(sign1<=3&&sign2>3&&sign3<=3)
		cout<<random1 <<sign(sign1) <<"("<<random2 <<sign(sign2) <<random3<<")" <<sign(sign3)<<random4<<"=?"<<endl;
	else if(sign1<=3&&sign2>3&&sign3>3)
		cout<<random1 <<sign(sign1) <<"("<<random2 <<sign(sign2) <<random3 <<sign(sign3)<<random4<<")"<<"=?"<<endl;
	else if(sign1<=3&&sign2<=3&&sign3>3)
		cout<<random1 <<sign(sign1) <<random2 <<sign(sign2) <<"("<<random3 <<sign(sign3)<<random4<<")"<<"=?"<<endl;
	else
		cout<<random1 <<sign(sign1) <<random2 <<sign(sign2) <<random3 <<sign(sign3)<<random4<<"=?"<<endl;
	if(temp%1000==0)cin>>answer;
	else {double a,b;char c;
	cin>>a;cin>>c;cin>>b;
	answer=a/b;
	}
	if(answer==ifneed) {
		if(Chinese)
		cout<<"####С�������,�ش���ȷ,�Ƿ�������⣨Y/N��####"<<endl;
		else cout<<"####You are very good, the answer is correct, whether to continue the answer��Y/N��####"<<endl;
		cin>>ifstart;
		if(ifstart=='Y') {*ifgo=true;}
		else{if(Chinese) cout<<"####С����һ�������"<<a+1<<"��,��ӭ����ѵ�����ټ���####"<<endl;
		else cout<<"####You have "<<a+1<< " Answer to this question is correct,Welcome to train again####"<<endl;}
	}else {if(Chinese){cout<<"####�ÿ�ϧ������ˣ���Ҫ���ģ�����Ŭ������ȷ���� "<<ifneed<<"��####"<<endl;
					 cout<<"��������С����һ�������"<<a<<"�⡣�ټ���"<<endl;
	}
	else {cout<<"####Unfortunately, all wrong, don't be sad, continue to work hard! The correct answer is"<<ifneed<<"��####"<<endl;
			 cout<<"Great��You have "<<a<<" Answer to this question are correct��Bye��"<<endl;}
	         }
	return 0;
}

char sign(int a){
	char sign;
	if(a==0)
		return sign='+';
	else if(a==1)
		return sign='-';
	else if(a==2)
		return sign='*';
	else if(a==3)
		return sign='/';
	else if(a==4)
		return sign='+';
	else if(a==5)
		return sign='-';
	return 0;
}
//���㷽����
double result(double random1,double random2,double random3,double random4,int sign1,int sign2,int sign3){
	double count1,count2,count3,result;
	if(sign1>3){count1=::count(random1,random2,sign1);
		if(sign2>3){count2=::count(count1,random3,sign2);result=::count(count2,random4,sign3);}
		else{if(sign3>3){result=::count(count1,::count(random3,random4,sign3),sign2);}
			else{if(sign2>1){result=::count(::count(count1,random3,sign2),random4,sign3);}
				else{if(sign3>1){result=::count(count1,::count(random3,random4,sign3),sign2);}
					else{result=::count(::count(count1,random3,sign2),random4,sign3);}}}}
	}else{if(sign2>3){count2=::count(random2,random3,sign2);
		      if(sign3>3){result=::count(random1,::count(count2,random4,sign3),sign1);}
			  else{if(sign1>1){result=::count(::count(random1,count2,sign1),random4,sign3);}
					else{if(sign3>1){result=::count(random1,::count(count2,random4,sign3),sign1);}
						else{result=::count(::count(random1,count2,sign1),random4,sign3);}}}
	}else{if(sign3>3){count3=::count(random3,random4,sign3);
						if(sign1>1){result=::count(::count(random1,random2,sign1),count3,sign2);}
						else{if(sign2>1){result=::count(random1,::count(random2,count3,sign2),sign1);}
							else{result=::count(::count(random1,random2,sign1),count3,sign2);}}
			}else{
				//���������㣨����������������ŵ����㣩
		if(sign1>1){
		count1=::count(random1,random2,sign1);
		if(sign2>1)result=::count(::count(count1,random3,sign2),random4,sign3);
		else{
		if(sign3>1) {
		count3=::count(random3,random4,sign3);
		result=::count(count1,count3,sign2);
		}else {
		result=::count(::count(count1,random3,sign2),random4,sign3);
		}}
	}else{
		if(sign2>1){count2=::count(random2,random3,sign2);
			if(sign3>1){
			result=::count(random1,::count(count2,random4,sign3),sign1);}
			else{result=::count(::count(random1,count2,sign1),random4,sign3);}}
		else{if(sign3>1){count3=::count(random3,random4,sign3);result=::count(::count(random1,random2,sign1),count3,sign2);
		}
		else{count1=::count(random1,random2,sign1);result=::count(::count(count1,random3,sign2),random4,sign3);}}
	}
	}
	}
	}
	return result;
	
}
double count(double x,double y,int sign){
	switch (sign)
	{
	case 0:return x+y;
		break;
	case 1:return x-y;
		break;
	case 2:return x*y;
		break;
	case 3:return x/y;
		break;
	case 4:return x+y;//( + )
		break;
	case 5:return x-y;//( - )
		break;
	default:
		break;
	}
	return 0;
}