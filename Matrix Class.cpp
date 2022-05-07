#include <iostream>

using namespace std;

class matrix
{
		int a[50][50];
	public:
		int r,c;
		void putdata();
		void getdata();
		friend void operator+(matrix a,matrix b);
		friend void operator-(matrix a,matrix b);
		friend void operator==(matrix a,matrix b);
};

void matrix :: putdata()
{
	cout<<"Enter number of row and column: ";
	cin>>r>>c;
	cout<<"\nEnter matrix element:\n";
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>a[i][j];
		}
	}
}

void matrix :: getdata()
{
	for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

void operator+(matrix x,matrix y)
{
	if((x.c==y.c)&&(x.r==y.r))
	{
		cout<<"\nAddition:\n";
		for(int i=0;i<y.r;i++)
		{
        	for(int j=0;j<y.c;j++)
        	{
        		cout<<"\t"<<x.a[i][j]+y.a[i][j];
        	}
        	cout<<"\n";
		}
	}
	else
		cout<<"\nAddition not possible!!\n";
}

void operator-(matrix x,matrix y)
{
	int d[50][50];
	if((x.c==y.r))
	{
		cout<<"\nMultiplication:\n";
		for(int i=0;i<x.r;i++)
        {
            for(int j=0;j<y.c;j++)
            {
                d[i][j]=0;
                for(int k=0;k<y.r;k++)
                {
                    d[i][j]+=x.a[i][k] * y.a[k][j];
                }
                cout<<"\t"<<d[i][j];
            }
            cout<<"\n";
        }
	}
	else
		cout<<"\nMultiplication not possible!!\n";
}

void operator==(matrix x,matrix y)
{
	int flag=1;
	if((x.c==y.c)&&(x.r==y.r))
	{
		for(int i=0;i<y.r;i++)
		{
        	for(int j=0;j<y.c;j++)
        	{
        		if(x.a[i][j]!=y.a[i][j])
        			flag=0;
        	}
		}
		if(flag)
			cout<<"\nMatrices are equal.\n";
		else
			cout<<"\nMatrices are not equal.\n";
	}
	else
		cout<<"\nMatrices are not equal.\n";
}

int main() 
{
	matrix M1,M2;
	M1.putdata();
	M2.putdata();
	M1+M2;
	M1-M2;
	M1==M2;
	return 0;
}
