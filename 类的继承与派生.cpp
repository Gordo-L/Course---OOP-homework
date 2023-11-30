/*

定义平面二维点类CPoint，有数据成员x坐标，y坐标，函数成员(构造函数复制构造函数、虚函数求面积GetArea,虚函数求体积函数GetVolume、输出点信息函数print。由CPoint类派生出圆类Cirle类（新增数据成员半径radius），函数成员(构造函数、复制构造函数、求面积GetArea,虚函数求体积函数GetVolume、输出圆信息函数print。
再由Ccirle类派生出圆柱体Ccylinder类（新增数据成员高度height），函数成员(构造函数、复制构造函数、求表面积GetArea,求体积函数GetVolume、输出圆柱体信息函数print。在主函数测试这个这三个类。

输入格式:
0 0 例如：第一行读入圆心坐标。
1 2 第二行读入半径与高度。

输出格式:
分四行输出，分别代表圆心、底面积、表面积、体积。

输入样例:
在这里给出一组输入。例如：
0 0
1 2

输出样例:
在这里给出相应的输出。例如：
Center:(0,0)
radius=1
height:2
BasalArea:3.14159
SupfaceArea:18.8496
Volume:6.28319

*/

#include <iostream>
#include <string>
const double PI = 3.1415926;
using namespace std;

class CPoint {
protected:
	double x, y;
public:
	CPoint(double x = 0, double y = 0) {
		this->x = x;
		this->y = y;
	}
	virtual double GetArea() { return 0; }
	virtual double GetVolume() { return 0; }
	virtual void print() {}
};
class Circle :public CPoint {
protected:
	double radius;
public:
	Circle(double x, double y, double radius) :CPoint(x, y) {
		this->radius = radius;
	}
	double GetArea() {
		return PI * radius * radius;
	}
	virtual double GetVolume() { return 0; }
	virtual void print() {}
};
class Cylinder :public Circle {
	double height;
public:
	Cylinder(double x, double y, double radius, double height) :Circle(x, y, radius) {
		this->height = height;
	}
	double GetArea() {
		return 2.0 * PI * radius * height + 2.0 * Circle::GetArea();
	}
	double GetVolume() {
		return Circle::GetArea() * height;
	}
	void print() {
		cout << "Center:(" << x << "," << y << ")" << endl;
		cout << "radius=" << radius << endl;
		cout << "height:" << height << endl;
		cout << "BasalArea:" << Circle::GetArea() << endl;
		cout << "SupfaceArea:" << GetArea() << endl;
		cout << "Volume:" << GetVolume() << endl;
	}
};

int main() {
	double x, y, radius, height;
	cin >> x >> y >> radius >> height;
	Cylinder cylinder(x, y, radius, height);
	cylinder.print();
}

 
