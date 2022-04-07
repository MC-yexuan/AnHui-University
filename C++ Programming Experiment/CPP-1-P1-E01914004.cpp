#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const char *name = "马崔烨暄";
const char *ID = "E01914004";
class Matrix{
    public:
    Matrix();
    Matrix(int r,int l);
    Matrix(const Matrix &r); //拷贝构造函数
    ~Matrix();
    void SetValue(int i,int j,double value);
    double GetValue(int i,int j);
    int GetRowCount(){
        return rows;
    }
    int GetColCount(){
        return cols;
    }
    Matrix Multiply(Matrix &r);
    Matrix& operator=(const Matrix &r);
    Matrix Transpose();
    void Display() const {
        if (0 == rows || 0 == cols || nullptr == pValue) {
            cout << "Empty Matrix" << endl;
        }
        else {
            int i = 0;
            for (int r = 0; r < rows; ++r) {
                for (int c = 0; c < cols; ++c) {
                    cout << pValue[i++] << ' ';
                }
                cout << endl;
            }
        }
    }

   private:
    int rows;
    int cols;
    double *pValue;
    };

Matrix::Matrix(){
    rows=0;
    cols=0;
    pValue=nullptr;
}
Matrix::Matrix(int r,int l){
    rows=r;
    cols=l;
    pValue=new double[r*l];
     memset(pValue,0,r*l*sizeof(double));
}

Matrix::~Matrix(){
        if(pValue)
        delete []pValue;  //是数组加[]
    }

Matrix::Matrix(const Matrix &r):rows(r.rows),cols(r.cols){ //深拷贝
    pValue=new double[rows*cols];
    for(int i=0;i<rows*cols;++i)
        pValue[i] = r.pValue[i];
    }

Matrix& Matrix::operator=(const Matrix &r){  //赋值
    if(this!=&r){//与r不相等
        rows = r.rows; cols = r.cols;
        delete []pValue;
        pValue = new double [rows*cols];
        for(int i = 0;i<rows*cols;++i) 
            pValue[i] = r.pValue[i];
    }   
    return *this;
}

void Matrix::SetValue(int i,int j,double value){
    int num=i*cols+j;
    pValue[num]=value;
}

double Matrix::GetValue(int i,int j){
    int num=i*cols+j;
    return pValue[num];
}

Matrix Matrix::Multiply(Matrix &r){
        if(cols!=r.rows){
           Matrix newMarix;//调用默认构造函数，返回空矩阵
           return newMarix; 
        }
        else{
            Matrix newMarix(rows,r.cols);   //新矩阵，行为左乘行数，列为右乘列数
            int flag1=0;int flag2=0;        //两个计数指针，flag2为左乘矩阵某行元素的列数，flag1为右乘矩阵的列数
            for(int i=0;i<rows*r.cols;i++){
                for(int j=0;j<cols;j++){    //相加得一个新矩阵得元素（加原矩阵列数次）
                    newMarix.pValue[i]=newMarix.pValue[i]+pValue[flag2]*r.pValue[j*r.cols+flag1];//累加过程
                    flag2++;
                    }
                flag1++;
                if(flag1>=r.cols){          //新矩阵的一整行已得出。flag1置零求下一行,flag2指向左乘矩阵下一行。
                    flag1=0;
                    flag2=flag2+cols;
                    }
                else flag2=0;               //求该行的下一个元素
            }           
        return newMarix;
        }
    }

Matrix Matrix::Transpose(){
    Matrix newMarix(cols,rows);
    int flag=0;
    for(int i=0;i<rows*cols;i++){
         for(int j=0;j<cols;j++){
             newMarix.pValue[i]=pValue[j*cols+flag];
         }
        flag++;
    }
    return newMarix;
}   
 
#define TEST  1
#define PI  3.1415926

int main(void) {
    
    cout << name<<" "<<ID << endl;
        
#if TEST
    Matrix Non;
    cout << "Non rows = " << Non.GetRowCount() << ", cols=" << Non.GetColCount() << endl;

    Matrix R(2, 2);
    double theta = PI / 4;
    R.SetValue(0, 0, cos(theta));
    R.SetValue(1, 0, -sin(theta));
    R.SetValue(0, 1, -R.GetValue(1,0));
    R.SetValue(1, 1, R.GetValue(0,0));
    R.Display();

    Matrix v(2, 1);
    v.SetValue(0, 0, sqrt(2.0)/2);
    v.SetValue(1, 0, sqrt(2.0)/2);

    Matrix w = R.Multiply(v);
    w.Display();

    Matrix vt = v.Transpose();
    Matrix wn = R.Multiply(vt);
    wn.Display();

#endif // TEST

    return 0;
}

