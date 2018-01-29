template<class T>
void TBTree<T>::preorder(TBTnode<T> *p)
{
	TBTnode<T> *temp=p;
	while(1)
	{
		temp=preSucc(temp);
		if(temp==p)
		break;
		cout<<"\t"<<temp->data;
	}
}
template<class T>
TBTnode<T> * TBTree<T>::preSucc(TBTnode<T> *p)
{
	if(p->lth==false)
	return p->lch;
	else
	{
		while(p->rth==true)
		p=p->rch;
		return p->rch;
	}
}
