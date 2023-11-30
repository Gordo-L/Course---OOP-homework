/*

学期结束，班主任决定表彰一批学生，已知该班学生数在6至50人之间，有三类学生：普通生，特招运动员，学科专长生，其中学科专长生不超过5人。

主函数根据输入的信息，相应建立GroupA, GroupB, GroupC类对象。

GroupA类是普通生，有2门课程的成绩（均为不超过100的非负整数）；

GroupB类是特招运动员，有2门课程的成绩（均为不超过100的非负整数），1次运动会的表现分，表现分有：A、B、C、D共4等。

GroupC类是学科专长生，有5门课程的成绩（均为不超过100的非负整数）。

表彰人员至少符合以下3个条件中的一个：

（1）2门课程平均分在普通生和特招运动员中，名列第一者。

a.该平均分称为获奖线。

b.存在成绩并列时，则全部表彰，例如某次考试有2人并列第1，则他们全部表彰。

（2）5门课程平均分达到或超过获奖线90%的学科专长生，给予表彰。

（3）2门课程平均分达到或超过获奖线70%的特招运动员，如果其运动会表现分为A，给予表彰。

输入格式：每个测试用例占一行，第一项为类型，1为普通生，2为特招运动员，3为学科专长生, 输入0表示输入的结束。第二项是学号，第三项是姓名。对于普通生来说，共输入5项，第4、5项是课程成绩。对于特招运动员来说，共输入6项，第4、5项是课程成绩，第6项是运动会表现。对于学科专长生来说，共输入8项，第4、5、6、7、8项是课程成绩。

输出时，打印要表彰的学生的学号和姓名。(输出顺序与要表彰学生的输入前后次序一致)

函数接口定义：
以Student为基类，构建GroupA, GroupB和GroupC三个类
裁判测试程序样例：
#include<iostream>
#include <string>
using namespace std;



int main()
{
    const int Size=50;
    string num, name;
    int i,ty,s1,s2,s3,s4,s5;
    char gs;
    Student *pS[Size];
    int count=0;
    for(i=0;i<Size;i++){
        cin>>ty;
        if(ty==0) break;
        cin>>num>>name>>s1>>s2;
        switch(ty){
             case 1:pS[count++]=new GroupA(num, name, s1, s2); break;
             case 2:cin>>gs; pS[count++]=new GroupB(num, name, s1,s2, gs); break;
             case 3:cin>>s3>>s4>>s5; pS[count++]=new GroupC(num, name, s1,s2,s3,s4,s5); break;
        }            
    }
    for(i=0;i<count;i++) {
        pS[i]->display();
        delete pS[i];
    }
    return 0;
}

输入样例：
1 001 AAAA 96 80
2 009 BBB 82 75 A
1 007 CC 100 99
3 012 CCCC 97 95 90 99 93
1 003 DDD 62 50
1 022 ABCE 78 92
2 010 FFF 45 40 A
3 019 AAA 93 97 94 82 80
0
输出样例：
009 BBB
007 CC
012 CCCC

*/

#include <iostream>
#include <string>
using namespace std;


class Student {
protected:
	static double s0;
	int s1, s2;
	string num,name;
public:
	Student(string num, string name, int s1, int s2) {
		this->num = num;
		this->name = name;
		this->s1 = s1;
		this->s2 = s2;
	}
	virtual void display(){}
};

double Student::s0 = 0;
class GroupA :public Student {
public:
	GroupA(string num, string name, int s1, int s2) :Student(num, name, s1, s2) {
		if ((double(s1) + double(s2)) / 2.0 > s0) s0 = (double(s1) + double(s2)) / 2.0;
	}
	virtual void display() {
		if ((double(s1) + double(s2)) / 2.0 == s0) cout << num << ' ' << name << endl;
	}
};

class GroupB :public Student {
	char gs;
public:
	GroupB(string num, string name, int s1, int s2, char gs) :Student(num, name, s1, s2) {
		this->gs = gs;
		if ((double(s1) + double(s2)) / 2.0 > s0) s0 = (double(s1) + double(s2)) / 2.0;
	}
	virtual void display() {
		if ((double(s1) + double(s2)) / 2.0 == s0) cout << num << ' ' << name << endl;
		else if ((double(s1) + double(s2)) / 2.0 >= 0.7 * s0 && gs == 'A')cout << num << ' ' << name << endl;
	}
};

class GroupC :public Student {
	int s3, s4, s5;
public:
	GroupC(string num, string name, int s1, int s2, int s3, int s4, int s5) :Student(num, name, s1, s2) {
		this->s3 = s3;
		this->s4 = s4;
		this->s5 = s5;
	}
	virtual void display() {
		if ((double(s1) + double(s2) + double(s3) + double(s4) + double(s5)) / 5.0 >= 0.9 * s0) cout << num << ' ' << name << endl;
	}
};
