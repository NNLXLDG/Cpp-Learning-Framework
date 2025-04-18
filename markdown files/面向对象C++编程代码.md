# 面向对象C++编程代码

##  一.定义一个Dog类，包含了age,weight等属性，以及对这些属性操作的方法（如setAge, setWeight, getAge, getWeight）。实现并测试这个类。 
```cpp
#include <iostream>
using namespace std;

class Dog
{
public:
    void setAge(int a);
    void setWeight(float w);
    int getAge();
    float getWeight();
private:
    int age;
    float weight;
};

void Dog::setAge(int a)
{
    age = a;
}

void Dog::setWeight(float w)
{
    weight = w;
}

int Dog::getAge()
{
    return age;
}

float Dog::getWeight()
{
    return weight;
}

int main()
{
    Dog dog; 
    dog.setAge(5);
    dog.setWeight(20.5);
    cout << dog.getAge() << dog.getWeight() << endl;
    return 0;
}
```

## 二.编程实现一个Circle类，允许以半径或面积或周长来构造该类对象，写出构造函数和拷贝构造函数，并写出设置和获取周长、半径、面积的函数。在主函数中测试。 

```cpp
#include <iostream>
#include <cmath>
using namespace std;
const float PI = 3.1415926;


class Circle
{
public: 
	Circle(float a, int type);
    Circle(const Circle& c);
	float getR() { return r; }
	float getArea() { return PI*r*r; }
	float getPeri() { return 2 * PI*r; }
	void setPara(float a, int type);
private:
	float r;
};


Circle::Circle(float a, int type)
{
	switch (type)
	{
    	case 0:	// a为半径
    		r = a;
    		break;
    	case 1:	// a为周长
    		r = a / 2 / PI;
    		break;
    	case 2:	// a为面积
    		r = sqrt(a / PI);
    		break;
	}
}

Circle::Circle(const Circle& c)
{
	r = c.r;
}

void Circle::setPara(float a, int type)
{
	switch (type)
	{
    	case 0:	// a为半径
    		r = a;
    		break;
    	case 1:	// a为周长
    		r = a / 2 / PI;
    		break;
    	case 2:	// a为面积
    		r = sqrt(a / PI);
    		break;
	}
}

int main()
{
	Circle c1(2.0, 0);
	cout << c1.getArea() << c1.getPeri() << c1.getR() << endl;
	Circle c2(2.0, 1);
	cout << c2.getArea() << c2.getPeri() << c2.getR() << endl;
	Circle c3(2.0, 2);
	cout << c3.getArea() << c3.getPeri() << c3.getR() << endl;
	return 0;
}
```

## 三. 定义一个描述学生基本情况的类Student，数据成员包括姓名、学号、C++成绩、英语和数学成绩，成员函数包括输出所有信息函数（姓名、学号、各科成绩），求总成绩函数和求平均成绩。要求写出构造函数、拷贝构造函数，所有成员函数实现不要写在class大括号内。编写主函数测试该类。 

```cpp
#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    Student(const char n[], int i, int s[]);
    Student(const Student &stu);
    void outputInfo();
    int calcSum();
    float calcAve();
private:
    char name[20];
    int id;
    int score[3];
};

Student::Student(const char n[], int i, int s[])
{
    int k;
    strcpy(name, n);
    id = i;
    for (k = 0; k < 3; k++)
        score[k] = s[k];
}

Student::Student(const Student &stu)
{
    int k;
    strcpy(name, stu.name);
    id = stu.id;
    for (k = 0; k < 3; k++)
        score[k] = stu.score[k];
}

void Student::outputInfo()
{
    cout << "name: " << name << endl;
    cout << "id: " << id << endl;
    cout << "c++ score: " << score[0] << endl;
    cout << "eng score: " << score[1] << endl;
    cout << "math score: " << score[2] << endl;
}

int Student::calcSum()
{
    int i, sum=0;
    for (i = 0; i < 3; i++)
        sum += score[i];
    return sum;
}

float Student::calcAve()
{
    return calcSum() / 3.0;
}

int main()
{
    int score[3] = { 90,90,80 };
    Student stu1("ZhangSan", 1, score);
    stu1.outputInfo();
    cout << "sum: " << stu1.calcSum() << endl;
    cout << "ave: " << stu1.calcAve() << endl;
    return 0;
}
```

## 四.编写一个矩形类Rect，包含数据成员len和width，包含成员函数calculateArea，函数返回类型和参数类型自己考虑，包含普通构造函数（个数不限）。测试这个类，创建一个矩形对象并计算其面积，输出到控制台。 

```cpp
#include <iostream>
using namespace std;
class Rect
{
public:
	Rect(double l, double w);
	void calculateArea();
private:
	double len;
	double width;
};

Rect::Rect(double l, double w)
{
	len = l;
	width = w;
}

void Rect::calculateArea()
{
	cout << "面积为：" << len * width << endl;
}

int main()
{
	Rect r(3, 4);
	r.calculateArea();
	return 0;
}
```

## 五.试建立一个实现该功能的类ARRAY，具有如下功能：可由一个已知数组经处理生成一个新数组，规则如下：新数组每个元素的值等于原数组对应元素与其左右相邻元素的平均值。

其中，第0个元素的左邻元素为最后一个元素。最后一个元素的右邻元素为第0个元素。例如：假设原数组为a[10]，新数组为b[10]，则b[1] = (a[0]+a[1]+a[2])/3，b[0]=(a[9]+a[0]+a[1])/3，b[9]=(a[8]+a[9]+a[0])/3。  

具体要求如下：   

私有数据成员  
float a[10], b[10]（数组大小固定为10）  
公有成员函数  
    构造函数  
    void process()，实现上述处理  
    void print()，在屏幕上打印数组a和b  

在主程序中测试上述功能。

```cpp
#include<iostream>
using namespace std;

class ARRAY {
    float a[10], b[10];
public:
    ARRAY(float t[]) 
    { 
        for (int i = 0; i<10; i++)
            a[i] = t[i]; 
    }
    void process();
    void print() 
    {
        int i;
        for (i = 0; i<10; i++) 
        {
            if (i % 10 == 5)
                cout << endl;
            cout << a[i] << '\t';
        }
        cout << endl;
        for (i = 0; i<10; i++) {
            if (i % 10 == 5)   
                cout << endl;
            cout << b[i] << '\t';
        }
        cout << endl;
    }
};

void ARRAY::process() 
{
    int i, j, k;
    for (i = 0; i<10; i++) 
    {
        j = i - 1;
        k = i + 1;
        if (j<0)
            j = 10 + j;
        if (k>9)
            k = 10 - k;
        b[i] = (a[j] + a[i] + a[k]) / 3;  
    }
}

int main() {
    float aa[10];
    for (int k = 0; k<10; k++)
        aa[k] = (float)k * 3;
    ARRAY arr(aa);
    arr.process();
    arr.print();
}
```


## 六.设计一个Point类，包含数据成员x,y，写出构造函数、拷贝构造函数.再设计一个Rect类（矩形），包含代表左上角顶点的Point类型的数据成员p1，长double len，宽double width及其它必要的数据成员（自己考虑）。写出构造函数、拷贝构造函数，计算矩形面积的函数，计算矩形周长的函数，返回矩形其它顶点的函数（返回类型为Point）。在主函数中创建Rect对象，测试相关功能。 
```cpp
#include<iostream>
using namespace std;

class Point
{
public:
	Point()
	{
		m_x = 0;
		m_y = 0;
	}
	Point(double x, double y)
	{
		m_x = x;
		m_y = y;
		cout << "Constructor1 was called." << endl;
	}
	Point(Point &);
	double getX()
	{
		return m_x;
	}
	double getY()
	{
		return m_y;
	}
private:
	double m_x, m_y;
};

Point::Point(Point &p)
{
	m_x = p.m_x;
	m_y = p.m_y;
	cout << "Copy Constructor1 was called." << endl;
}

class Rect
{
public:
	Rect(Point a, double l, double w);
	Rect(Rect &);
	double getm_S();
	double getm_L();
private:
	Point p1;
	double len, width;
	double m_S, m_L;
};

Rect::Rect(Point a, double l, double w) :p1(a)
{
	len = l;
	width = w;
	cout << "右上角顶点坐标为：" << "(" << (p1.getX() - len) << "," << p1.getY() << ")" << endl;
	cout << "右下角顶点坐标为：" << "(" << (p1.getX() - len) << "," << (p1.getY() - width) << ")" << endl;
	cout << "左上角顶点坐标为：" << "(" << p1.getX() << "," << (p1.getY() - width) << ")" << endl;
}

Rect::Rect(Rect &p) :p1(p.p1)
{
	len = p.len;
	width = p.width;
	cout << "Copy Constructor2 was called." << endl;
}

double Rect::getm_L()
{
	return len * 2 + width * 2;
}

double Rect::getm_S()
{
	return len*width;
}

int main()
{
	Point s(3, 4);
	Rect ss(s, 1, 2);
	cout << "矩形的面积为：" << ss.getm_S() << endl;
	cout << "矩形的周长为：" << ss.getm_L() << endl;
	return 0;
}
```


## 七.设计一个Ear类，描述狗的耳朵，包含属性color（int型）。再设计一个Dog类，包含两个Ear成员，leftEar和rightEar，并包含狗的体重weight（double型）和年龄age（int型）。编写Ear类和Dog类的构造函数、拷贝构造函数和析构函数以及其它必要的函数。在构造函数、拷贝构造函数和析构函数中输出“调用XX类的XX函数”。

```cpp
#include<iostream>
using namespace std;

class Ear
{
public:
	Ear(int c)
	{
		color = c;
		cout << "调用Ear类的构造函数." << endl;
	}
	Ear(Ear &E);
	~Ear()
	{
		cout << "调用Ear类的析构函数." << endl;
	}
	int getear()
	{
		return color;
	}
private:
	int color;
};

Ear::Ear(Ear &E)
{
	color = E.color;
	cout << "调用Ear类的复制构造函数." << endl;
}

class Dog
{
public:
	Dog(Ear, Ear, double, int);
	Dog(Dog &D);
	~Dog()
	{
		cout << "调用Dog类的析构函数." << endl;
	}

	int getleftear()
	{
		return m_leftear.getear();
	}

	int getrightear()
	{
		return m_rightear.getear();
	}

	double getweight()
	{
		return m_weight;
	}

	int getage()
	{
		return m_age;
	}

private:
	Ear m_leftear, m_rightear;
	double m_weight;
	int m_age;
};

Dog::Dog(Ear leftear, Ear rightear, double weight, int age) :m_leftear(leftear), m_rightear(rightear)
{
	m_weight = weight;
	m_age = age;
	cout << "调用Dog类的构造函数." << endl;
}

Dog::Dog(Dog &D) :m_leftear(D.m_leftear), m_rightear(D.m_rightear)
{
	cout << "调用Dog类的复制构造函数." << endl;
}

int main()
{
	Ear c1(1);
	Ear c2(2);
	Dog dog(c1, c2, 15, 7);
	cout << "狗的左耳的颜色:" << dog.getleftear() << endl;
	cout << "狗的右耳的颜色:" << dog.getrightear() << endl;
	cout << "狗的体重:" << dog.getweight() << endl;
	cout << "狗的年龄:" << dog.getage() << endl;
	return 0;
}
```

## 八.创建一个Book类，数据成员价格(double price)和书目编号(int bookid)，成员函数包含构造函数、拷贝构造函数，析构函数和其它相关函数。包含静态数据成员int countBook，静态成员函数showCount()。创建若干个对象测试上述功能。其中，以对象调用和类名调用的方式调用静态成员函数。

```cpp
#include<iostream>
using namespace std;

class Book
{
public:
    Book(double p, int n);
    Book(Book &co);
    ~Book() { Bookcount--; cout << "the destructor was called." << endl; }
    static void showcount();
    
private:
    double price;
    int bookid;
    static int Bookcount;
};

Book::Book(double p, int n)
{
    price = p;
    bookid = n;
    Bookcount++;
    cout << "the constructor was called." << endl;
}

Book::Book(Book &co)
{
    price = co.price;
    bookid = co.bookid;
    Bookcount++;
    cout << "the copy constructor was called." << endl;
}

void Book::showcount()
{
    cout << "书本的总数：" << Bookcount << "本" << endl;
}

int Book::Bookcount = 0;

int main()
{
    Book::showcount();
    Book b1(45.0, 001);
    Book b2(53.0, 002);
    Book b3(52.0, 003);
    Book b4(b3);
    b3.showcount();
    Book::showcount();
    return 0;
}
```

## 九.定义一个三角形类Triangle。数据成员有：三个点Point的对象，即Point p1,p2,p3。还有一个三角形的周长len。Triangle类具有计算周长（海伦公式）和面积的函数。请完整定义Point和Triangle类，并实现main函数。

```cpp
#include <cmath>
#include <iostream>

using namespace std;
class Point{
public:
    Point(){}
    Point(double x, double y);
    Point(const Point &p);
    ~Point(){}
    double getX();
    double getY();
    void printpoint();
private:
    double x;
    double y;
};

Point::Point(double x , double y )
{
    this->x = x;
    this->y = y;
    //cout<<"creat point"<<endl;
}

Point::Point(const Point &p)
{
    this->x = p.x;
    this->y = p.y;    
    //cout<<"copy point"<<endl
}

double Point::getX()
{
    return x;
}

double Point::getY()
{
    return y;
}

void Point::printpoint()
{
    cout<<"("<<x<<" , "<<y<<")";
}

class Triangle{
public:
    Triangle(Point p1, Point p2, Point p3);
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3);
    Triangle(const Triangle &t);
    ~Triangle(){}
    double callen(Point p1, Point p2);
    double getArea();
    double getperimeter();
    void printperimeter();
    void printlength();

private:
    Point p1, p2, p3;
    double perimeter;
    void calperimeter();
};


Triangle::Triangle(Point np1, Point np2, Point np3):p1(np1),p2(np2),p3(np3)
{
    calperimeter();
}


Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3):p1(x1,y1),p2(x2,y2),p3(x3,y3)
{
    calperimeter();
}


Triangle::Triangle(const Triangle &t):p1(t.p1),p2(t.p2),p3(t.p3),perimeter(t.perimeter){}


double Triangle::getperimeter()
{
    return perimeter;
}


double Triangle::callen(Point p1, Point p2)
{
    double len;
    double x = p1.getX() - p2.getX();
    double y = p1.getY() - p2.getY();
    len = sqrt(x*x + y*y);
    return len;
}


void Triangle::calperimeter()
{
    if((callen(p1,p2) + callen(p2,p3)) > callen(p1,p3) && abs(callen(p1,p2)-callen(p2,p3)) < callen(p1,p3))
        perimeter = callen(p1,p2) + callen(p2,p3) + callen(p1,p3);
    else
    {
        cout<<"this is not a triangle!"<<endl;
        perimeter = 0;
    }
}


double Triangle::getArea()
{
    double p = perimeter/2;
    return sqrt(p*(p - callen(p1,p2))*(p - callen(p2,p3)) * (p - callen(p1,p3)));
}


void Triangle::printperimeter()
{
    cout<<"perimeter: "<<perimeter<<endl;
}


void Triangle::printlength()
{
    cout<<"length of three side of the triangle: "<<callen(p1,p2)<<" "<<callen(p2,p3)<<" "<<callen(p1,p3)<<endl;
}


void test(double x1, double y1, double x2, double y2, double x3, double y3)
{
    Point p1(x1,y1),p2(x2,y2),p3(x3,y3);
    Triangle t(p1,p2,p3);
    t.printlength();
    t.printperimeter();
    cout<<"area: "<<t.getArea()<<endl;
}


int main()
{
    test(1,1,5,2,8,0);
    test(1,1,5,2,9,3);
    test(0,0,1,0,0,1);
}
```


## 十.设计一个程序，其中有三个类CBank,BBank和GBank，分别为中行，工行和农行类。每个类都包含一个私有数据balance用于存放储户在该行的存款数。储户在每家银行开一个账户，并存入一定金额的钱。使用两种方法计算储户在这三家银行的总存款数。

1. 用友元函数totalBalanceFriend(CBank &c, BBank &b, GBank &g)
2. 不用友元函数

两个功能写在同一个程序中。 
```cpp
#include <iostream>
using namespace std;
class GBank;
class BBank;

class CBank
{
public:
	CBank(float b) { balance = b; }
	friend float totalBalanceFriend(CBank &c, BBank &b, GBank &g);
	float getBalance() { return balance; }
private:
	float balance;
};

class BBank
{
public:
	BBank(float b) { balance = b; }
	friend float totalBalanceFriend(CBank &c, BBank &b, GBank &g);
	float getBalance() { return balance; }
private:
	float balance;
};

class GBank
{
public:
	GBank(float b) { balance = b; }
	friend float totalBalanceFriend(CBank &c, BBank &b, GBank &g);
	float getBalance() { return balance; }
private:
	float balance;
};

float totalBalanceFriend(CBank &c, BBank &b, GBank &g)
{
	return c.balance + b.balance + g.balance;
}

int main()
{
	CBank c(10);
	BBank b(20);
	GBank g(30);
	cout << totalBalanceFriend(c, b, g) << endl;
	cout << c.getBalance() + b.getBalance() + g.getBalance() << endl;
	return 0;
}
```

## 十一.设计一个“日期”类，包含：数据成员：年、月、日 ,成员函数：构造函数，拷贝构造函数，以及其他必要的函数,再设计一个“项目”类（Project），包含：数据成员：1、项目开始日期、结束日期（“日期”类的对象）；2、项目是否完成标识符（int型，0表示未完成，1表示完成）；成员函数：构造函数，拷贝构造函数，以及其他必要的函数（如设置/查看项目是否完成的函数） .完成上述类的建立后，创建多个项目（大于1个），并输出所创建项目的个数（用静态成员统计）. 

```cpp
#include <iostream>
using namespace std;

class Date
{
public:
	Date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
	Date(Date &date)
	{
		year = date.year;
		month = date.month;
		day = date.day;
	}

private:
	int year, month, day;
};

class Project
{
public:
	Project(Date &date1, Date &date2, string &c, int i);
	Project(Project &project);
	~Project() { count--; }
	static void showCount() { cout << count << endl; }

private:
	Date startDate, endDate;
	string content;
	int isFinished;
	static int count;
};

int Project::count = 0;



Project::Project(Date &date1, Date &date2, string &c, int i): startDate(date1), endDate(date2), content(c)
{
	isFinished = i;
    count++;
}

Project::Project(Project &project): startDate(project.startDate), endDate(project.endDate), content(project.content)
{
	isFinished = project.isFinished;
	count++;
}

int main()
{
	string str = "tiyuguan";
	Date date1(2000, 1, 1), date2(2000, 12, 30);
	Project p1(date1, date2, str, 0);
	Project p2(p1);
	Project::showCount();
	return 0;
}
```


## 十二.设计一个Point类，有横纵坐标x,y以及相应的函数（如构造函数和get, set之类的函数）。另有一个类Test中有一个成员函数void showPoint(Point &p); 在函数中要输出x, y坐标到屏幕上。请利用友元类实现该功能。 



## 十三.创建一个Monitor类,它能知道成员函数incident()被调用了几次。incident不必完成具体的功能。增加一个成员函数print()，显示incident()被调用的次数，并能在没有定义任何Monitor类的对象时，就显示次数的初始值。主函数中以3种方式创建Monitor类的对象和对象数组：（1）普通对象数组marr，大小为3；（2）动态创建Monitor对象数组pmarr；（3）动态创建Monitor对象pm。调用incident和print函数。 

```cpp
#include <iostream>
using namespace std;

class Monitor
{
public:
	void incident();
	static void print();
private:
	static int count;
};

int Monitor::count = 0;

void Monitor::incident()
{
	count++;
}

void Monitor::print()
{
	cout << count << endl;
}

int main()
{
	Monitor marr[3];
	marr[0].incident();
	marr[1].incident();
	Monitor::print();、
	Monitor *pmarr = new Monitor[3];
	pmarr[0].incident();
	pmarr[1].incident();
	Monitor::print();
	Monitor *pm = new Monitor;
	pm->incident();
	Monitor::print();
	delete []pmarr;
	delete pm;
	return 0;
}
```

## 十四.声明一个Point类，用new语句为其分配包含10个元素的地址空间，每个Point的坐标设置为(i,i)，如：第0个元素的坐标为(0,0)，……。将其坐标打印为：第0个元素坐标为(0,0)，第1个元素坐标为(1,1)……

```cpp
#include <iostream>
using namespace std;

class Point
{
public:
    Point(int x=0, int y=0)
    {
        this->x = x;
        this->y = y;
    }

    void Move(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    int getX() { return x; }
    int getY() { return y; }

private:
    int x, y;
};



int main()
{
    int i;
    Point *p = new Point[10];
    for (i = 0; i < 10; i++)
        p[i].Move(i, i)l
    for (i = 0; i < 10; i++)
        cout << "第" << i << "个元素坐标为(" << p[i].getX(
        << "," << p[i].getY() << ")" << endl;
    return 0;
}
```

## 十五.设计一个Date类，包括年月日和基本的成员函数。在主函数中以动态、非动态方式创建单个对象和对象数组。对所有对象和数组中的元素设置2000年1月1日。最后，删除以动态方式创建的对象。要求，所有成员函数中均使用this指针。 

```cpp
#include <iostream>
using namespace std;

class Date
{
private:
	int year, month, day;
public:
	Date(int y = 2000, int m = 1, int d = 1);
	void showDate()
	{
		cout << "The date is " << this->year << "." << this->month << "." << this->day << ".\n";
	}
};

Date::Date(int y, int m, int d)
{
	this->year = y;
	this->month = m;
	this->day = d;
}

int main()
{
	Date d1(2000, 1, 1);
	Date da1[2];
	Date *da = new Date;
	Date *Da = new Date[3];
	d1.showDate();
	da->showDate();
	for (int i = 0; i<2; i++) {
		da1[i].showDate();
	}
	for (int i = 0; i<3; i++) {
		Da[i].showDate();
	}

	if (da != NULL) {
		delete da;
	}

	if (Da != NULL) {
		delete[]Da;
	}
}
```

## 十六.创建学生类Student，包含姓名（string或char数组都可）、学号（int）、三门课考试成绩（用float数组表示）。编写构造函数及其它必要函数。创建班级类Banji，可根据学生人数动态创建班级。编写构造函数、拷贝构造函数和析构函数，并提供获取指定学生对象的成员函数。编写主函数测试上述类，包括创建Banji对象，设置/修改某班某同学成绩等。 

```cpp
#include <iostream>
using namespace std;

class Student
{
public:
    Student(char n[] = NULL, int i = 0, float s[] = NULL);
    void setName(const char n[]) { strcpy(name,n); }
    void setID(int i) { id = i; };
    void setScores(float s[]);
    void showScores()
    {
        cout << "score1=" << scores[0] << endl
            << "score2=" << scores[1] << endl
            << "score3=" << scores[2] << endl;
    }
private:
    char name[20];
    int id;
    float scores[3];
};


Student::Student(char n[], int i, float s[])
{
    if (n != NULL)
        strcpy(name, n);
    id = i;
    int k;
    if(s!= NULL)
        for (k = 0; k < 3; k++)
            scores[k] = s[k];
}


void Student::setScores(float s[])
{
    int k;
    for (k = 0; k < 3; k++)
        scores[k] = s[k];
}


class Banji
{
public:
    Banji(int n);
    Banji(const Banji &b);
    ~Banji();
    Student &callStudent(int i);
private:
    Student *pstu;
    int numberOfStudent;
};

Banji::Banji(int n)
{
    pstu = new Student[n];
    numberOfStudent = n;
}

Banji::Banji(const Banji &b)
{
    int i;
    numberOfStudent = b.numberOfStudent;
    pstu = new Student[numberOfStudent];
    for (i = 0; i < numberOfStudent; i++)
        pstu[i] = b.pstu[i];
}

Banji::~Banji()
{
    delete[]pstu;
}

Student &Banji::callStudent(int i)
{
    return pstu[i];
}

int main()
{
    Banji b1(50);
    Banji b2(b1);
    float score[3] = { 100,90,80 };
    b1.callStudent(10).setName("Zhangsan");
    b1.callStudent(10).setID(1);
    b1.callStudent(10).setScores(score);
    b1.callStudent(10).showScores();
    return 0;
}

```


## 十七.创建学生类Student，包含姓名（string或char数组都可）、学号（int）、三门课考试成绩（用float数组表示）。编写构造函数及其它必要函数。创建班级类Banji，可根据学生人数动态创建班级。编写构造函数、拷贝构造函数和析构函数，并提供获取指定学生对象的成员函数。编写主函数测试上述类，包括创建Banji对象，设置/修改某班某同学成绩等。 但不定义Banji类，完成动态创建Student数组，设置指定同学的姓名、学号、成绩，并输出显示。 

```cpp
#include <iostream>
using namespace std;

class Student
{
public:
    Student(char n[] = NULL, int i = 0, float s[] = NULL);
    void setName(const char n[]) { strcpy(name, n); }
    void setID(int i) { id = i; };
    void setScores(float s[]);
    void showScores()
    {
        cout << "score1=" << scores[0] << endl
            << "score2=" << scores[1] << endl
            << "score3=" << scores[2] << endl;
    }
private:
    char name[20];
    int id;
    float scores[3];
};

Student::Student(char n[], int i, float s[])
{
    if (n != NULL)
        strcpy(name, n);
    id = i;
    int k;
    if (s != NULL)
        for (k = 0; k < 3; k++)
            scores[k] = s[k];
}

void Student::setScores(float s[])
{
    int k;
    for (k = 0; k < 3; k++)
        scores[k] = s[k];
}

int main()
{
    float score[3] = { 100,90,80 };
    Student *pstu = new Student[10];
    pstu[5].setName("Test");
    pstu[5].setID(5);
    pstu[5].setScores(score);
    pstu[5].showScores();
    delete[]pstu;
    return 0;
}
```


## 十八.声明一个Object类，有数据成员weight和相应的操作函数，由此派生出的Box类，增加数据成员height和width及相应的操作函数，声明一个Box对象，观察构造函数和析构函数的调用顺序（写出构造函数、拷贝构造函数、析构函数，并在其中输出一句话，从而观察调用顺序）。 

```cpp
#include<iostream>
using namespace std;

class Object
{
public:
	Object();
	Object(int weight);
	Object(Object &obj);
	~Object();
	int getweight() { return weight; }

private:
	int weight;
};

Object::Object()
{
	weight = 0;
	cout << "O. initialization is calling" << endl;
}

Object::Object(int weight)
{
	this->weight = weight;
	cout << "O. constructed is calling" << endl;\
}

Object::Object(Object &obj)
{
	weight = obj.weight;
	cout << "O. copy constructed is calling" << endl;
}

Object::~Object()
{
	cout << "O. destructed is calling" << endl;
}

class Box : public Object
{
public:
	Box();
	Box(int height, int weight, int);
	Box(Box &box);
	~Box();
	void showbox();

private:
	int height;
	int weight;
};

Box::Box()
{
	height = 0;
	weight = 0;
	cout << "B. initialization is calling" << endl;
}

Box::Box(int height, int weight, int Oweight) :Object(Oweight)
{
	this->weight = weight;
	this->height = height;
	cout << "B. constructed is calling" << endl;
}

Box::Box(Box &box) :Object(box)
{
	weight = box.weight;
	height = box.height;
	cout << "B. copy constructed is calling" << endl;
}

Box::~Box()
{
	cout << "B. destructed is calling" << endl;
}

void Box::showbox()
{
	cout << "the object's weight:" << getweight() << endl;
	cout << "the box's height:" << height << endl;
	cout << "the box's weight:" << weight << endl;
}

int main()
{
	Box box(12, 13, 11);
	box.showbox();
	return 0;
}
```

## 十九.定义一个类Mammal（哺乳动物），包含名字、年龄等属性，包含成员函数Speak，在函数中输出“动物叫”。再由此派生出狗Dog类和猫Cat类，用一个成员函数Speak()分别输出Dog类和Cat类的叫声（分别在函数中输出“狗叫”和“猫叫”）。编程实现并创建Dog类和Cat类的对象进行测试。

```cpp
#include<iostream>
#include<string>
using namespace std;

class Mammal
{
public:
	Mammal();
	Mammal(string name, int age);
	void speak()
	{
		cout << "动物叫。" << endl;、
	}

protected:
	string m_name;
	int m_age;
};

Mammal::Mammal(string name, int age) :m_name(name)
{
	m_age = age;
}

Mammal::Mammal() : m_name()
{
	m_age = 0;
}

class Dog :public Mammal
{
public:
	Dog(string name, int age);
	void speak()
	{
		cout << "狗叫。" << endl;
	}
};

Dog::Dog(string name, int age) :Mammal(name, age){}

class Cat :public Mammal
{
public:
	Cat(string name, int age);
	void speak()
	{
		cout << "猫叫。" << endl;
	}
};

Cat::Cat(string name, int age) :Mammal(name, age){}

int main()
{
	Dog dog("Dog", 12);
	dog.speak();
	Cat cat("Cat", 10);
	cat.speak();
	dog.Mammal::speak();
	cat.Mammal::speak();
	return 0;
}
```


## 二十.设计基类Person（人），包含私有数据成员：姓名，年龄，性别 设计派生类Teacher（老师），Student（学生），两者均公有继承Person     –Teacher派生出title数据成员，表示职称     –Student派生出score数据成员，表示成绩。编写各个类的构造函数及输出相关信息的函数（派生类中要能够输出姓名、年龄和性别）。
```cpp
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	Person(string n, int a, int g)
	{
		name = n;
		age = a;
		gender = g;
	}
	void display()
	{
		cout << "name:" << name << endl
			<< "age:" << age << endl
			<< "gender:" << gender << endl;
	}
	string getName() { return name; }
	int getAge() { return age; }
	int getGender() { return gender; }

private:
	string name;
	int age;
	int gender;
};

class Teacher : public Person
{
public:
	Teacher(string n, int a, int g, string t);
	void display() 
	{ 
		cout << "name:" << getName() << endl
			<< "age:" << getAge() << endl
			<< "gender:" << getGender() << endl
			<< "title:" << title << endl;
	}
private:
	string title;
};

Teacher::Teacher(string n, int a, int g, string t):Person(n, a, g), title(t){}

// Student略

int main()
{
	Person p("PQ", 35, 0);
	p.display();
	Teacher t("PQ", 35, 0, "AP");
	t.display();
	return 0;
}
```

## 二十一.编写一个汽车类Vehicle，有无参数构造函数，类中的数据成员：车轮个数wheels为私有成员，车重weight为保护成员，获取和设置轮胎个数和车重的函数为公有成员；Car类私有继承Vehicle，增加数据成员排量displacement； Truck类保护继承Vehicle，增加数据成员载重量payload；Van类公有继承Vehicle，增加数据成员载人数passager_load。每个类都有相关数据的输入输出方法。编写主函数测试，并尝试在各派生类中访问基类各访问权限的成员，尝试通过派生类对象访问基类各访问权限的成员 


```cpp
#include<iostream>
using namespace std;
 
class Vehicle//声明汽车类
{
private:
    int wheels;//车轮
protected:
    double weight;//车重
public:
    int getWheels()
    {
        return wheels;
    }
    void setWheels(int wh)
    {
        wheels = wh;
    }
    int getWeight()
    {
        return weight;
    }
    void setWeight(int w)
    {
        weight = w;
    }
};


class Car:private Vehicle//声明小车类，私有继承汽车类
{
private:
    int displacement;
public:
    void set(int dis, int w, int wh)
    {
        displacement = 100;
        weight = w;
        setWheels(wh);
    }

    void show()
    {
        cout<<"I'm car, I have "<<getWheels()<<" wheels :"<<weight<<" "<<displacement<<endl;        
    }
};

class Truck:protected Vehicle//声明卡车类，私有继承汽车类
{
private:
    int payload;
public:
    void set(int pay, int w, int wh)
    {
        payload = pay;
        weight = w;
        setWheels(wh);
    }

    void show()
    {
        cout<<"I'm truck, I have "<<getWheels()<<" wheels :"<<weight<<" "<<payload<<endl;
    }
};
 
class Van:public Vehicle//声明卡车类，私有继承汽车类
{
private:
    int passager_load;
public:
    void set(int pass, int w, int wh)
    {
        passager_load = pass;
        weight = w;
        setWheels(wh);
    }

    void show()
    {
        cout<<"I'm van, I have "<<getWheels()<<" wheels :"<<weight<<" "<<passager_load<<endl;
    }
};
 
int main()
{
    Car C;
    Truck T;
    Van V;
    C.set(100,100,4);
    C.show();
    T.set(200,200,6);
    T.show();
    V.set(6,300,6);
    V.show();
    return 0;
}
```


## 二十二.请以点类Point为基类派生出一个圆类Circle。圆类Circle的数据成员为r（私有属性，存储圆的半径，圆心的点坐标通过继承点类Point加以实现），成员函数有构造函数Circle、计算圆的面积函数Area、计算圆的周长函数Perimeter和输出函数Display，其中构造函数实现基类和圆类的数据成员的初始化，Display函数实现圆心坐标（利用基类Point的Display实现）、圆的半径、圆的面积（利用Area函数实现）和圆的周长（利用Perimeter函数实现）的输出。请编写圆类的定义及成员函数实现，并在主函数中定义圆类对象，验证各个函数的正确性。 

```cpp
#include<iostream>

using namespace std;

const double PI = 3.14;

class Point

{

public:

	Point(double xx, double yy); //constructor

	void Display();        //display point

private:

	double x, y;    //平面的点坐标x，y

};

Point::Point(double xx, double yy) //constructor

{

	x = xx;

	y = yy;

}

void Point::Display()

{

	cout << "Point(" << x << "," << y << ")" << endl;

}

class Circle :public Point

{

public:

	Circle(double xx, double yy, double rr);

	double Area();

	double Perimeter();

	void Display();

private:

	double r;

};

Circle::Circle(double xx, double yy, double rr) :Point(xx, yy)

{

	r = rr;

}

double Circle::Area()

{

	return PI*r*r;

}

double Circle::Perimeter()

{

	return 2 * PI*r;

}

void Circle::Display()

{

	cout << "Center:";

	Point::Display();

	cout << "Radius:" << r << endl;

	cout << "Area:" << Area() << endl;

	cout << "Perimeter:" << Perimeter() << endl;

}

int main()

{

	double x, y, r;

	cin >> x >> y >> r; //圆心的点坐标及圆的半径

	Circle C(x, y, r);

	C.Display(); //输出圆心点坐标，圆的半径，圆的面积，圆的周长

	return 0;

}
```

## 二十三.实现一个Clock类，包含时分秒属性及其它必要的成员函数。重载“+”，“-”，“+=”，“-=”运算符。 
```cpp
#include<iostream>

#include<cmath>

using namespace std;

class Clock

{

public:

	Clock(int hour = 0, int minute = 0, int second = 0)

	{

		this->hour = hour;

		this->minute = minute;

		this->second = second;

	}

	Clock operator+(Clock &c1);

	Clock operator-(Clock &c1);

	Clock &operator+=(Clock &c1);

	Clock &operator-=(Clock &c1);

	friend ostream &operator << (ostream &out, Clock &c)

	{

		out << c.hour << "时" << c.minute << "分" << c.second << "秒";

		return out;

	}

private:

	int hour;

	int minute;

	int second;

};

Clock Clock::operator+(Clock &c1)

{

	int s = this->second + c1.second;

	int h = this->hour + c1.hour;

	int m = this->minute + c1.minute;

	if (s>60)

	{

		s = s % 60;

		m++;

	}

	if (m>60)

	{

		m = m % 60;

		h++;

	}

	return Clock(h, m, s);

}

Clock Clock::operator-(Clock &c1)

{

	int h = this->hour - c1.hour;

	int m = this->minute - c1.minute;

	int s = this->second - c1.second;

	if (s<0)

	{

		s = s + 60;

		m--;

	}

	if (m<0)

	{

		m = m + 60;

		h--;

	}

	return Clock(h, m, s);

}

Clock &Clock::operator+=(Clock &c1)

{

	this->hour += c1.hour;

	this->minute += c1.minute;

	this->second += c1.second;

	if ((this->second)>60)

	{

		(this->second) %= 60;

		(this->minute)++;

	}

	if ((this->minute)>60)

	{

		(this->minute) %= 60;

		(this->hour)++;

	}

	return *this;

}

Clock &Clock::operator-=(Clock &c1)

{

	this->hour -= c1.hour;

	this->minute -= c1.minute;

	this->second -= c1.second;

	if ((this->second)<0)

	{

		(this->second) += 60;

		(this->minute)--;

	}

	if ((this->minute)<0)

	{

		(this->minute) += 60;

		(this->hour)--;

	}

	return *this;

}

int main()

{

	Clock c1(21, 50, 25), c2(23, 23, 50), c3, c4;

	cout << c1 << endl;

	cout << c2 << endl;

	c3 = c1 + c2;

	c4 = c2 - c1;

	cout << c1 << " + " << c2 << " = " << c3 << endl;

	cout << c2 << " - " << c1 << " = " << c4 << endl;

	c2 += c1;

	cout << c1 << endl;

	cout << c2 << endl;

	c2 -= c1;

	cout << c1 << endl;

	cout << c2 << endl;

	return 0;

}
```















































