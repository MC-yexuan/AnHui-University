#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<math.h>
#include<time.h>
#include<cstdlib>
using namespace std;
namespace Numeric {//	����һ�������ռ�Numeric���ڸÿռ��ж�����Rational;
	class Rational
	{
	public:
		//	��дĬ�Ϲ��캯��������һ��������0
		Rational() {
			numerator = 0; denominator = 1;
		}
		//	��д�������б�Ĺ��캯��Rational (int, int )��Ҫ��ʹ�ó�ʼ���б�
		Rational(int _x, int _y) :numerator(_x), denominator(_y) {
		}
		//���ƹ��캯��
		Rational(const Rational& a) :numerator(a.numerator), denominator(a.denominator) {}
		//��ֵ����=
		Rational& operator=(const Rational& a) {
			if (this != &a) {
				this->numerator = a.numerator;
				this->denominator = a.denominator;
			}
			return *this;
		}
		//�ĸ���Ԫ����add��sub��mul��div��������Rational�����ʾ���������ֱ������ӡ��������ˡ�������㣬������
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
		//��Ա����getValue()�������ø�������ʾ��������
		float getValue()const {
			if (denominator == 0) { cout << "error"; return 0; }
			return (float)numerator / (float)denominator;
		}
		//��Ԫ����lessThan���Ƚ������������Ĵ�С������bool����
		friend bool lessThan(const Rational& a, const Rational& b) {
			if (a.numerator * b.denominator - a.denominator * b.numerator > 0)return 1;
			else return 0;
		}
		//��������
		~Rational() {};

	private:
		int numerator;//����
		int denominator;//��ĸ
	};
	bool cmp(Rational& a, Rational& b)//�����㷨�����õĺ���
	{
		if (lessThan(a, b)) return 0;
		else return 1;
	}
}
using namespace Numeric;
int main() {
	srand(time(0));
	Rational x[10];
	for (int i = 0; i < 10; i++)//�������������
	{
		x[i] = Rational(rand(), rand());
	}
	cout << "δ�����������:" << endl;
	for (int i = 0; i < 10; i++)//���δ�����������
	{
		cout << x[i].getValue() << endl;
	}
	cout << endl << endl;
	sort(x, x + 10, lessThan);//����������
	cout << "������������:" << endl;
	for (int i = 0; i < 10; i++)//��������������
	{
		cout << x[i].getValue() << endl;
	}
	cout << endl << endl;
	cout << "�������Ӽ��˳�����" << endl;
	//�������Ӽ��˳�����
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
