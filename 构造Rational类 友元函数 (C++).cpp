#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<math.h>
#include<time.h>
#include<cstdlib>
using namespace std;
namespace Numeric {//	定义一个命名空间Numeric，在该空间中定义类Rational;
	class Rational
	{
	public:
		//	编写默认构造函数，构造一个有理数0
		Rational() {
			numerator = 0; denominator = 1;
		}
		//	编写带参数列表的构造函数Rational (int, int )，要求使用初始化列表
		Rational(int _x, int _y) :numerator(_x), denominator(_y) {
		}
		//复制构造函数
		Rational(const Rational& a) :numerator(a.numerator), denominator(a.denominator) {}
		//赋值操作=
		Rational& operator=(const Rational& a) {
			if (this != &a) {
				this->numerator = a.numerator;
				this->denominator = a.denominator;
			}
			return *this;
		}
		//四个友元函数add、sub、mul、div，对两个Rational对象表示的有理数分别进行相加、相减、相乘、相除运算，并重载
		friend Rational add(const Rational& a, const Rational& b) {
			Rational c(a.numerator * b.denominator + a.denominator * b.numerator, b.denominator * a.denominator);
			return c;
		}
		friend Rational add(const Rational& a, const int b) {
			Rational c(a.numerator + a.denominator * b, a.denominator);
			return c;
		}
		friend Rational add(const int a, const Rational& b) {
			Rational c(a * b.denominator + b.numerator, b.denominator * a);
			return c;
		}
		friend Rational sub(const Rational& a, const Rational& b) {
			Rational c(a.numerator * b.denominator - a.denominator * b.numerator, b.denominator * a.denominator);
			return c;
		}
		friend Rational sub(const int a, const Rational& b) {
			Rational c(b.denominator - a * b.numerator, b.denominator);
			return c;
		}
		friend Rational sub(const Rational& a, const int b) {
			Rational c(a.numerator - a.denominator * b, a.denominator);
			return c;
		}
		friend Rational mul(const Rational& a, const Rational& b) {
			Rational c(a.numerator * b.numerator, b.denominator * a.denominator);
			return c;
		}
		friend Rational mul(const int a, const Rational& b) {
			Rational c(a * b.numerator, b.denominator);
			return c;
		}
		friend Rational mul(const Rational& a, const int b) {
			Rational c(a.numerator * b, a.denominator);
			return c;
		}
		friend Rational div(const Rational& a, const Rational& b) {
			Rational c(a.numerator * b.denominator, b.numerator * a.denominator);
			return c;
		}
		friend Rational div(const int a, const Rational& b) {
			Rational c(a * b.denominator, b.numerator);
			return c;
		}
		friend Rational div(const Rational& a, const int b) {
			Rational c(a.numerator, b * a.denominator);
			return c;
		}
		//成员函数getValue()，返回用浮点数表示的有理数
		float getValue()const {
			if (denominator == 0) { cout << "error"; return 0; }
			return (float)numerator / (float)denominator;
		}
		//友元函数lessThan，比较两个有理数的大小，返回bool类型
		friend bool lessThan(const Rational& a, const Rational& b) {
			if (a.numerator * b.denominator - a.denominator * b.numerator > 0)return 1;
			else return 0;
		}
		//析构函数
		~Rational() {};

	private:
		int numerator;//分子
		int denominator;//分母
	};
	bool cmp(Rational& a, Rational& b)//排序算法所调用的函数
	{
		if (lessThan(a, b)) return 0;
		else return 1;
	}
}
using namespace Numeric;
int main() {
	srand(time(0));
	Rational x[10];
	for (int i = 0; i < 10; i++)//随机生成有理数
	{
		x[i] = Rational(rand(), rand());
	}
	cout << "未排序的有理数:" << endl;
	for (int i = 0; i < 10; i++)//输出未排序的有理数
	{
		cout << x[i].getValue() << endl;
	}
	cout << endl << endl;
	sort(x, x + 10, lessThan);//有理数排序
	cout << "排序后的有理数:" << endl;
	for (int i = 0; i < 10; i++)//有理数排序后输出
	{
		cout << x[i].getValue() << endl;
	}
	cout << endl << endl;
	cout << "有理数加减乘除检验" << endl;
	//有理数加减乘除检验
	cout << add(x[0], x[1]).getValue() << endl;
	cout << add(x[0], 1).getValue() << endl;
	cout << add(1, x[0]).getValue() << endl;
	cout << sub(x[0], x[1]).getValue() << endl;
	cout << sub(x[0], 1).getValue() << endl;
	cout << sub(1, x[0]).getValue() << endl;
	cout << mul(x[0], x[1]).getValue() << endl;
	cout << mul(x[0], 1).getValue() << endl;
	cout << mul(1, x[0]).getValue() << endl;
	cout << div(x[0], x[1]).getValue() << endl;
	cout << div(x[0], 1).getValue() << endl;
	cout << div(1, x[0]).getValue() << endl;
	return 0;
}
