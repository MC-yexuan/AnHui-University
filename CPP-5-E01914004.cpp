#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <algorithm>
using namespace std;


/*请把下面的字符串分别改为你的姓名和学号*/
const char *name = "马崔烨暄";
const char *ID = "E01914004";

/*在下面添加你的代码
类的声明和实现代码都写在下方*/
namespace Numeric
{
    class Rational 
    {
    private:
        int num;//分子
        int den;//分母

    public:
        /*改写默认构造函数*/
        Rational() 
            {
           num=0;
           den=1;
            }
        /*构造函数*/
        Rational(int n,int d):num(n),den(d){}
        
        /*在下方编写拷贝构造函数*/
        Rational(const Rational &r):num(r.num),den(r.den){}//深拷贝

            /*在下方编写拷贝赋值运算operator=*/
        Rational& operator=(const Rational &r)//赋值
            {  
            if(this!=&r){//与r不相等
            this->den=r.den;
            this->num=r.num; 
            }   
            return *this;
            }

            /*析构函数*/
        ~Rational() {}

            /*在下方编写其它成员函数*/
        friend Rational add(const Rational a,const Rational b);
          
        friend Rational sub(const Rational a,const Rational b);
           
        friend Rational mul(const Rational a,const Rational b);
          
        friend Rational div(const Rational a,const Rational b);
         
        //--------
        friend Rational add(const Rational a,const int b);
          
        friend Rational add(const int a,const Rational b);
           
        friend Rational sub(const Rational a,const int b);
         
        friend Rational sub(const int a,const Rational b);
         
        friend Rational mul(const Rational a,const int b);
          
        friend Rational mul(const int a,const Rational b);
          
        friend Rational div(const Rational a,const int b);
         
        friend Rational div(const int a,const Rational b);
          
        float getValue() const
            {
                return (float)num/(float)den;
            }
        friend bool lessThan(const Rational &x,const Rational &y);
    
};
        Rational add(const Rational a,const Rational b)
            {
            int a1,b1;
            Rational _new;
            a1=a.num*b.den;
            b1=b.num*a.den;
            _new.num=a1+b1;
            _new.den=a.den*b.den;
             return _new;
            }
        Rational sub(const Rational a,const Rational b)
            {
                int a1,b1;
                Rational _new;
                a1=a.num*b.den;
                b1=b.num*a.den;
                _new.num=a1-b1;
                _new.den=a.den*b.den;
                return _new;
            }
        Rational mul(const Rational a,const Rational b)
            {
                Rational _new;
                _new.num=a.num*b.num;
                _new.den=a.den*b.den;
                return _new;
            }
        Rational div(const Rational a,const Rational b)
            {
                Rational _new;
                _new.num=a.num*b.den;
                _new.den=a.den*b.num;
                return _new;
            }
        //--------
        Rational add(const Rational a,const int b)
            {
                Rational _new;
                int a1=b*a.den;
                _new.num=a1+a.num;
                _new.den=a.den;
                return _new;
            }
        Rational add(const int a,const Rational b)
            {
                Rational _new;
                int a1=a*b.den;
                _new.num=a1+b.num;
                _new.den=b.den;
                return _new;
            }
        Rational sub(const Rational a,const int b)
            {
                Rational _new;
                int a1=b*a.den;
                _new.num=a.num-a1;
                _new.den=a.den;
                return _new;
            }
        Rational sub(const int a,const Rational b)
            {
                Rational _new;
                int a1=a*b.den;
                _new.num=b.num-a1;
                _new.den=b.den;
                return _new;
            }
        Rational mul(const Rational a,const int b)
            {
                Rational _new;
                int a1=a.num*b;
                _new.num=a1;
                _new.den=a.den;
                return _new;
            }
        Rational mul(const int a,const Rational b)
            {
                Rational _new;
                int a1=b.num*a;
                _new.num=a1;
                _new.den=b.den;
                return _new;
            }
        Rational div(const Rational a,const int b)
            {
                Rational _new;
                int a1=b*a.den;
                _new.num=a.num;
                _new.den=a1;
                return _new;
            }
        Rational div(const int a,const Rational b)
            {
                Rational _new;
                int a1=b.den*a;
                _new.num=a1;
                _new.den=b.num;
                return _new;
            }
        bool lessThan(const Rational &x,const Rational &y)
            {
                return x.getValue()<y.getValue();
            }
}

int main() 
    {
        using namespace Numeric;
        
        //调用默认构造函数
        Numeric::Rational text;
        cout<<"输出默认构造取值"<<endl;
        cout<<text.getValue()<<endl;
        //调用带参数列表的构造函数
        Numeric::Rational text1(9,2),text2(3,2);
        cout<<"输出带参数构造取值"<<endl;
        cout<<text1.getValue()<<endl<<text2.getValue()<<endl;
        //复制构造
        Numeric::Rational text3(text1);
        cout<<"输出复制构造取值"<<endl;
        cout<<text3.getValue()<<endl;
        text3=Numeric::Rational(text2);
        cout<<"输出赋值操作复制构造取值"<<endl;
        cout<<text3.getValue()<<endl;
        //有理数之间加减乘除
        Numeric::Rational z=add(text1,text2);
        cout<<"输出9/2+3/2"<<endl;
        cout<<z.getValue()<<endl;
        z=sub(text1,text2);
        cout<<"输出9/2-3/2"<<endl;
        cout<<z.getValue()<<endl;
        z=mul(text1,text2);
        cout<<"输出（9/2）*（3/2）"<<endl;
        cout<<z.getValue()<<endl;
         z=div(text1,text2);
        cout<<"输出（9/2）/（3/2）"<<endl;
        cout<<z.getValue()<<endl;
        //有理数与整数之间加减乘除
        int i=2;
        z=add(text1,i);
         cout<<"输出9/2+2"<<endl;
        cout<<z.getValue()<<endl;
        z=sub(text1,i);
        cout<<"输出9/2-2"<<endl;
        cout<<z.getValue()<<endl;
         z=mul(text1,i);
         cout<<"输出(9/2)*2"<<endl;
        cout<<z.getValue()<<endl;
         z=div(text1,i);
         cout<<"输出(9/2)/2"<<endl;
        cout<<z.getValue()<<endl;
        //--------
        z=add(i,text2);
        cout<<"输出2+3/2"<<endl;
        cout<<z.getValue()<<endl;
        z=sub(i,text2);
        cout<<"输出2-3/2"<<endl;
        cout<<z.getValue()<<endl;
        z=mul(i,text2);
        cout<<"输出2*3/2"<<endl;
        cout<<z.getValue()<<endl;
        z=div(i,text2);
        cout<<"输出2/(3/2)"<<endl;
        cout<<z.getValue()<<endl;
        //随机数排序
        std::srand(time(0));
        Rational arr[10];
        for(int i=0;i<10;++i){
            arr[i]=Rational(rand(),rand());
        }
        cout << endl;
        cout << "未排序的有理数:" << endl;
	for (int i = 0; i < 10; i++)//输出未排序的有理数
	{
		cout << arr[i].getValue() << endl;
	}
    cout << endl;
        sort(arr,arr+10,lessThan);
        cout << "排序后的有理数:" << endl;
        for (int i = 0; i < 10; i++)//输出未排序的有理数
	{
		cout << arr[i].getValue() << endl;
	}
        return 0;
    }