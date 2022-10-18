#include<bits/stdc++.h>
using namespace std;

class Disjoint
{
  private:
  	int len;
  	int *arr;
  public:
  Disjoint(int n)	
  {
  	len=n;
  	arr=new int [len];
  	for(int i=0;i<len;i++) arr[i]=-1;
  }
  
  int getRoot(int i)
  {
  	while(arr[i]>0)
  	{
  		i=arr[i];
  	}

  	return i;
  }

  void join(int x,int y)
  {
  	int rootX=getRoot(x);
  	int rootY=getRoot(y);

  	if(arr[rootX]<arr[rootY])
  	{
  		arr[rootX]+=arr[rootY];
  		arr[rootY]=rootX;
  	}
  	else
  	{
  		arr[rootY]+=arr[rootX];
  		arr[rootX]=rootY;
  	}
  }

  void display()
  {
  	int check[len];
  	for(int i=0;i<len;i++) check[i]=arr[i]*(-1);

  	sort(check,check+len);
  	for(int i=0;i<len;i++)
  	{
  		if(check[i]>0)
  		cout<<check[i]<<" ";
  	}	
  }

};
int main()
{
	int n,m;
	cin>>n>>m;
	Disjoint set(n);

	while(m--)
	{
		int x,y;
		cin>>x>>y;
		set.join(x-1,y-1);
		set.display();
		cout<<"\n";
	}

	return 0;
}