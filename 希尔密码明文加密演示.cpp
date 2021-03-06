#include<iostream>
#include<cstring>
#include<cmath> 
#include<iomanip>
using namespace std;
const int N=20,L=60;
int det(int a[N][N],int n);
void mod_26(int arr[N][N],int mm,int nn);
void matrix(int mat1[N][N],int mat2[N][N],int product[N][N],int m,int n,int p,int q); 
int main()
{
	cout<<"希尔密码的加密过程演示。许智超制作。Enjoy it!"<<endl<<"----------------------------------------------\n";
	int n;
	cout<<"请输入密钥矩阵（方阵）的阶数n:"<<endl;
	while(cin>>n)
	{
	    int key[N][N]={0},cryp[L]={0};
	    char ch[L];
	    
	    cout<<"请输入明文："<<endl;
		cin>>ch;
		
		cout<<"请输入密钥矩阵（方阵）:("<<n<<"*"<<n<<")"<<endl;
		for(int i=0;i<n;i++)
		{
		   for(int j=0;j<n;j++)
		      cin>>key[i][j];
		}
		
		int leng=strlen(ch);
		cout<<"明文长度为"<<leng<<endl; 
		for(int i=0;i<leng;i++)
		{
		  if(ch[i]=='A')cryp[i]=1; if(ch[i]=='B')cryp[i]=2; if(ch[i]=='C')cryp[i]=3;
		  if(ch[i]=='D')cryp[i]=4; if(ch[i]=='E')cryp[i]=5; if(ch[i]=='F')cryp[i]=6;
		  if(ch[i]=='G')cryp[i]=7; if(ch[i]=='H')cryp[i]=8; if(ch[i]=='I')cryp[i]=9;
		  if(ch[i]=='J')cryp[i]=10;if(ch[i]=='K')cryp[i]=11;if(ch[i]=='L')cryp[i]=12;
		  if(ch[i]=='M')cryp[i]=13;if(ch[i]=='N')cryp[i]=14;if(ch[i]=='O')cryp[i]=15;
		  if(ch[i]=='P')cryp[i]=16;if(ch[i]=='Q')cryp[i]=17;if(ch[i]=='R')cryp[i]=18;
		  if(ch[i]=='S')cryp[i]=19;if(ch[i]=='T')cryp[i]=20;if(ch[i]=='U')cryp[i]=21;
		  if(ch[i]=='V')cryp[i]=22;if(ch[i]=='W')cryp[i]=23;if(ch[i]=='X')cryp[i]=24;
		  if(ch[i]=='Y')cryp[i]=25;if(ch[i]=='Z')cryp[i]=0; 
		 } 
		 cout<<"明文对应的数字串为：";
		 for(int i=0;i<leng;i++)
		 {
		    cout<<cryp[i]<<" ";
		  } 
		 cout<<endl;
		 int q = (leng+n-1)/n;
		 int crm[N][N]={0};
		 int k1=0;
		 for(int j=0;j<q;j++)
		 {
		 	for(int i=0;i<n;i++)
		 	{
		 		crm[i][j] = cryp[k1];
				 k1++;	
			}
		 }
		 cout<<"对应的"<<n<<"*"<<q<<"矩阵为："<<endl; 
		 for(int i=0;i<n;i++)
		 {
		 	for(int j=0;j<q;j++)
		 	{
		 		cout<<setw(2)<<crm[i][j]<<"   "; 
				 	
			}
			cout<<endl;
		 }
		 int product[N][N]={0};
		 matrix(key,crm,product,n,n,n,q);
		 cout<<"用密钥矩阵左乘这个矩阵得：\n";
		 for(int i=0;i<n;i++)
		 {
		 	for(int j=0;j<q;j++)
		 	{
		 		cout<<setw(3)<<product[i][j]<<"   ";
			 }
			 cout<<endl;
		 }
		 mod_26(product,n,q);
		 cout<<"除以26取模得：\n";
		 for(int i=0;i<n;i++)
		 {
		 	for(int j=0;j<q;j++)
		 	{
		 		cout<<setw(2)<<product[i][j]<<"   ";
			 }
			 cout<<endl;
		 }
		 int k2=0;
		 char ch2[L];
		 for(int j=0;j<q;j++)
		 {
		 	for(int i=0;i<n;i++)
		 	{
			 if(product[i][j]==1)ch2[k2] ='A';  if(product[i][j]==2)ch2[k2] ='B';
			 
			 if(product[i][j]==3)ch2[k2] ='C';  if(product[i][j]==4)ch2[k2] ='D';
			 
			 if(product[i][j]==5)ch2[k2] ='E';  if(product[i][j]==6)ch2[k2] ='F';
			 
			 if(product[i][j]==7)ch2[k2] ='G';  if(product[i][j]==8)ch2[k2] ='H';
			 
			 if(product[i][j]==9)ch2[k2] ='I';  if(product[i][j]==10)ch2[k2]='J';
			 
			 if(product[i][j]==11)ch2[k2]='K';  if(product[i][j]==12)ch2[k2]='L';
			 
			 if(product[i][j]==13)ch2[k2]='M';  if(product[i][j]==14)ch2[k2]='N';
			 
			 if(product[i][j]==15)ch2[k2]='O';  if(product[i][j]==16)ch2[k2]='P';
			 
			 if(product[i][j]==17)ch2[k2]='Q';  if(product[i][j]==18)ch2[k2]='R';
			 
			 if(product[i][j]==19)ch2[k2]='S';  if(product[i][j]==20)ch2[k2]='T';
			 
			 if(product[i][j]==21)ch2[k2]='U';  if(product[i][j]==22)ch2[k2]='V';
			 
			 if(product[i][j]==23)ch2[k2]='W';  if(product[i][j]==24)ch2[k2]='X';
			 
			 if(product[i][j]==25)ch2[k2]='Y';  if(product[i][j]==0)ch2[k2] ='Z';
			 
			 k2++;	
			 }
			 
		 }
		 cout<<"加密后对应的密文为："; 
		 for(int i=0;i<leng;i++)
			cout<<ch2[i];cout<<endl<<"--------------------------------"<<endl<<endl;
		cout<<"请继续输入密钥矩阵（方阵）的阶数n:(* to quit)"<<endl;
		 	   
	} 
cout<<"Bye-bye!"<<endl;
return 0;	
}

void mod_26(int arr[N][N],int mm,int nn)
{
	for(int i=0;i<mm;i++)
		for(int j=0;j<nn;j++)
		  arr[i][j]=arr[i][j]%26;
	
}

void matrix(int mat1[N][N],int mat2[N][N],int product[N][N],int m,int n,int p,int q)
{
	for(int i=0;i<m;i++)
	{
       for(int j=0;j<q;j++)
	   {
           for(int k=0;k<n;k++)
		   {
               product[i][j]+=mat1[i][k]*mat2[k][j];
           }
       }
    }
}

/*int det(int a[N][N],int n)
{
    int D;
    if(n==1){D=a[0][0];return D;}
    if(n==2){D=a[0][0]*a[1][1]-a[0][1]*a[1][0];return D;}
    if(n>=3)
    {
        D=0.0;
        int line1[N];
        int temp[N][N];
        for(int i=0;i<n;i++)
            {line1[i]=a[i][0]*pow(-1,i+2);}
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                temp[i][j]=a[i][j+1];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int r=i;r<n-1;r++)
            {
                for(int c=0;c<n;c++)
                {
                    a[r][c]=temp[r+1][c];
                }
            }
            D+=line1[i]*det(a,n-1);
            for(int i=0;i<n-1;i++)
            {
                for(int j=0;j<n;j++)
                    a[i][j]=temp[i][j];
            }
        }
        return D;
    }
}*/
