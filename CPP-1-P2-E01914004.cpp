#include<stdio.h>
#include<math.h>

double calculate(double a,double b,double c){
    
}

int main()
{
int i,n;double a[100],b[100],c[100],p,q;double x1[100],x2[100];
	scanf("%d",&n);
	getchar();
	for(i=1;i<=n;i++)
	
	{scanf("%lf %lf %lf",&a[i],&b[i],&c[i]);}

	
	for(i=1;i<=n;i++)
	{
    if( b[i]*b[i]==4*a[i]*c[i])

	{
		x1[i]=x2[i]=(-b[i]+sqrt(b[i]*b[i]-4*a[i]*c[i]))/(2*a[i]);
		printf("x1=x2=%.5lf\n",x2[i]);
	}

	else if(b[i]*b[i]>4*a[i]*c[i])
	{x1[i]=(-b[i]+sqrt(b[i]*b[i]-4*a[i]*c[i]))/(2*a[i]);
	x2[i]=(-b[i]-sqrt(b[i]*b[i]-4*a[i]*c[i]))/(2*a[i]);
	printf("x1=%.5lf;",x1[i]);printf("x2=%.5lf\n",x2[i]);}
	
	
	else
	{
	p=-b[i]/(2*a[i]);     q=sqrt(4*a[i]*c[i]-b[i]*b[i])/(a[i]*2);
	if(b[i]!=0.0)
	{printf("x1=%.5lf+%.5fi;",p,q);printf("x2=%.5lf-%.5fi\n",p,q);}
	else	
    { p=0.0; printf("x1=%.5f+%.5fi;",p,q);printf("x2=%.5f-%.5fi\n",p,q);}
	}
    }
	return 0;}