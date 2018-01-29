#include<iostream>
using namespace std;
class Smterm
{
	int row,col,val;
	
	friend class SMatrix;
};
class SMatrix
{
	int rows,cols,terms,ms;
	Smterm *sma;
	void attachsum(int,int,int);
	public:
		SMatrix();
		SMatrix(int,int,int);
		void read();
		void show();
		SMatrix Ftranspose();
		SMatrix add(SMatrix);
		SMatrix multiply(SMatrix);
};
SMatrix::SMatrix()
{
	rows=cols=terms=ms=0;
	sma=NULL;
}
SMatrix::SMatrix(int p,int q,int r)
{
	rows=p;
	cols=q;
	terms=r;
	ms=10;
	if(terms>ms)
	throw "maximum no of the terms reached....";
	sma=new Smterm[ms];
}
void SMatrix::read()
{
	for(int i=0;i<terms;i++)
	{
		cout<<"\nenter the row , column and the value : ";
		cin>>sma[i].row>>sma[i].col>>sma[i].val;
	}
}
void SMatrix::show()
{
	cout<<"\nthe information in the matrix is : \n";
	cout<<"\trow\tcolumn\tvalue\n";
	for(int i=0;i<terms;i++)
	cout<<"\t"<<sma[i].row<<"\t"<<sma[i].col<<"\t"<<sma[i].val<<endl;
}
SMatrix SMatrix::Ftranspose()
{
	int rowsize[cols];
	for(int i=0;i<cols;rowsize[i++]=0);
	for(int i=0;i<cols ;i++)
	rowsize[sma[i].col]++;
	int rowstart[cols];
	rowstart[0]=0;
	for(int i=1;i<cols;i++)
	rowstart[i]=rowstart[i-1]+rowsize[i-1];
	SMatrix temp(rows,cols,terms);
	for(int i=0;i<terms;i++)
	{
		int j=rowstart[sma[i].col];
		temp.sma[j].row=sma[i].col;
		temp.sma[j].col=sma[i].row;
		temp.sma[j].val=sma[i].val;
		rowstart[sma[i].col]++;
	}
return temp;
}
SMatrix SMatrix::add(SMatrix s)
{
	if(cols!=s.cols||rows!=s.rows)
	throw "invalid order for addition ...";
	SMatrix temp(rows,cols,0);
	int ca,cb,inda,inds;ca=cb=0;
	while(ca<terms&&cb<s.terms)
	{
		inda=sma[ca].row*cols+sma[ca].col;
		inds=s.sma[cb].row*s.cols+s.sma[cb].col;
		if(inda==inds)
		{
			int t=sma[ca].val+s.sma[cb].val;
			if(t)
			temp.attachsum(sma[ca].row,sma[ca].col,t);
			ca++;cb++;
		}
		else if(inda<inds)
		{
			temp.attachsum(sma[ca].row,sma[ca].col,sma[ca].val);
			ca++;
		}
		else
		{
			temp.attachsum(s.sma[cb].row,s.sma[cb].col,s.sma[cb].val);
			cb++;
		}
	}
	for(;ca<terms;ca++)
	temp.attachsum(sma[ca].row,sma[ca].col,sma[ca].val);
	for(;cb<s.terms;cb++)
	temp.attachsum(s.sma[cb].row,s.sma[cb].row,s.sma[cb].val);
return temp;
}
void SMatrix::attachsum(int p,int q,int r)
{
	sma[terms].row=p;
	sma[terms].col=q;
	sma[terms++].val=r;
}
SMatrix SMatrix::multiply(SMatrix s)
{
	if(cols!=s.rows)
	throw "invalid order of matrices for multiplication ...";
	SMatrix st=s.Ftranspose();
	SMatrix temp(rows,s.cols,0);
	int currRowIndex=0,currRowBegin=0;
	int currRowA=sma[0].row;int sum=0;
	st.sma[st.terms].row=s.cols;
	st.sma[st.terms].col=-1;
	while(currRowIndex<terms)
	{
		int currColB=st.sma[0].row;
		int currColIndex=0;
		while(currColIndex<=s.terms)
		{
			if(sma[currRowIndex].row!=currRowA)
			{
				temp.attachsum(currRowA,currColB,sum);
				sum=0;
				currRowIndex=currRowBegin;
			while(st.sma[currColIndex].row==currColB)
			currColIndex++;
			currColB=st.sma[currColIndex].row;
			}
		else if(st.sma[currColIndex].row!=currColB)
		{
			temp.attachsum(currRowA,currColB,sum);
			sum=0;
			currRowIndex=currRowBegin;
			currColB=st.sma[currColIndex].row;
		}
		else
		{
			if(sma[currRowIndex].col<st.sma[currColIndex].col)
			currRowIndex++;
			else if(sma[currRowIndex].col==st.sma[currColIndex].col)
			{
				sum+=sma[currRowIndex].val*st.sma[currColIndex].val;
				currRowIndex++;currColIndex++;
			}
			else
			currColIndex++;
		}
		}
		while(sma[currRowIndex].row==currRowA)
		currRowIndex++;
		currRowBegin=currRowIndex;
		currRowA=sma[currRowIndex].row;
	}
return temp;
}
