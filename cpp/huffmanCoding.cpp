#include<bits/stdc++.h>
using namespace std;

struct Node
{
  char ch;
  int freq;
  Node *left;
  Node *right;
  Node(){}
  Node(char a,int b)
  {
  	ch=a;
  	freq=b;
  	left=NULL;
    right=NULL;
  }
};

struct cmp
{
	bool operator()(Node * const &a,Node * const &b)
	{
      return a->freq>b->freq;
	}
};

void printTree(Node *root)
{
	if(root==NULL) return;

	if(root->left==NULL && root->right==NULL)
	{
		cout<<root->ch<<" ";
	}

	printTree(root->left);
	printTree(root->right);

}

void printCodes(Node *root,string code)
{
	if(root==NULL) return;

	if(root->left==NULL && root->right==NULL)
	{
		cout<<root->ch<<" "<<code<<"\n";
		return;
	}
    
    string passLeft=code+"0";
    string passRight=code+"1";
	printCodes(root->left,passLeft);
	printCodes(root->right,passRight);

}
void HuffmanCodes(char arr[],int freq[],int size)
{
    priority_queue<Node *,vector<Node *>,cmp> pq;

    for(int i=0;i<size;i++)
    {
    	pq.push(new Node(arr[i],freq[i]));
    }
    
    Node *temp1;
    Node *temp2;
    while(pq.size()>1)
    {
       temp1=pq.top();
       pq.pop();
       temp2=pq.top();
       pq.pop();

       Node *added=new Node('\0',temp1->freq+temp2->freq);
       added->left=temp1;
       added->right=temp2;

       pq.push(added);
    }

    Node *root=pq.top();
    pq.pop();

    printTree(root);
    cout<<"\n";
    string code="";
    printCodes(root,code);
}
int main()
{
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
    int freq[] = { 5, 9, 12, 13, 16, 45 }; 
  
    int size = sizeof(arr) / sizeof(arr[0]); 
  
    HuffmanCodes(arr, freq, size); 
	return 0;
}