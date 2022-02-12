#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <algorithm>
using namespace std;


/*���������ַ����ֱ��Ϊ���������ѧ��*/
const char *name = "�������";
const char *ID = "E01914004";

/*�����������Ĵ���
���������ʵ�ִ��붼д���·�*/
namespace Numeric
{
    class Rational 
    {
    private:
        int num;//����
        int den;//��ĸ

    public:
        /*��дĬ�Ϲ��캯��*/
        Rational() 
            {
           num=0;
           den=1;
            }
        /*���캯��*/
        Rational(int n,int d):num(n),den(d){}
        
        /*���·���д�������캯��*/
        Rational(const Rational &r):num(r.num),den(r.den){}//���

            /*���·���д������ֵ����operator=*/
        Rational& operator=(const Rational &r)//��ֵ
            {  
            if(this!=&r){//��r�����
            this->den=r.den;
            this->num=r.num; 
            }   
            return *this;
            }

            /*��������*/
        ~Rational() {}

            /*���·���д������Ա����*/
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
        
        //����Ĭ�Ϲ��캯��
        Numeric::Rational text;
        cout<<"���Ĭ�Ϲ���ȡֵ"<<endl;
        cout<<text.getValue()<<endl;
        //���ô������б�Ĺ��캯��
        Numeric::Rational text1(9,2),text2(3,2);
        cout<<"�������������ȡֵ"<<endl;
        cout<<text1.getValue()<<endl<<text2.getValue()<<endl;
        //���ƹ���
        Numeric::Rational text3(text1);
        cout<<"������ƹ���ȡֵ"<<endl;
        cout<<text3.getValue()<<endl;
        text3=Numeric::Rational(text2);
        cout<<"�����ֵ�������ƹ���ȡֵ"<<endl;
        cout<<text3.getValue()<<endl;
        //������֮��Ӽ��˳�
        Numeric::Rational z=add(text1,text2);
        cout<<"���9/2+3/2"<<endl;
        cout<<z.getValue()<<endl;
        z=sub(text1,text2);
        cout<<"���9/2-3/2"<<endl;
        cout<<z.getValue()<<endl;
        z=mul(text1,text2);
        cout<<"�����9/2��*��3/2��"<<endl;
        cout<<z.getValue()<<endl;
         z=div(text1,text2);
        cout<<"�����9/2��/��3/2��"<<endl;
        cout<<z.getValue()<<endl;
        //������������֮��Ӽ��˳�
        int i=2;
        z=add(text1,i);
         cout<<"���9/2+2"<<endl;
        cout<<z.getValue()<<endl;
        z=sub(text1,i);
        cout<<"���9/2-2"<<endl;
        cout<<z.getValue()<<endl;
         z=mul(text1,i);
         cout<<"���(9/2)*2"<<endl;
        cout<<z.getValue()<<endl;
         z=div(text1,i);
         cout<<"���(9/2)/2"<<endl;
        cout<<z.getValue()<<endl;
        //--------
        z=add(i,text2);
        cout<<"���2+3/2"<<endl;
        cout<<z.getValue()<<endl;
        z=sub(i,text2);
        cout<<"���2-3/2"<<endl;
        cout<<z.getValue()<<endl;
        z=mul(i,text2);
        cout<<"���2*3/2"<<endl;
        cout<<z.getValue()<<endl;
        z=div(i,text2);
        cout<<"���2/(3/2)"<<endl;
        cout<<z.getValue()<<endl;
        //���������
        std::srand(time(0));
        Rational arr[10];
        for(int i=0;i<10;++i){
            arr[i]=Rational(rand(),rand());
        }
        cout << endl;
        cout << "δ�����������:" << endl;
	for (int i = 0; i < 10; i++)//���δ�����������
	{
		cout << arr[i].getValue() << endl;
	}
    cout << endl;
        sort(arr,arr+10,lessThan);
        cout << "������������:" << endl;
        for (int i = 0; i < 10; i++)//���δ�����������
	{
		cout << arr[i].getValue() << endl;
	}
        return 0;
    }