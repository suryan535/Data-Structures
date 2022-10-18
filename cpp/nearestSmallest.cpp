#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];

	vector<int> leftSmall(n,-1);
	stack< pair<int,int> > st;
    
	for(int i=n-1;i>=0;i--)
    {
      while(st.empty()==false && arr[i]<st.top().first)
      {  
      	leftSmall[st.top().second]=arr[i];
         st.pop();
      }
      st.push(make_pair(arr[i],i));
    }

    for(int i=0;i<n;i++) cout<<leftSmall[i]<<" ";

	return 0;
}