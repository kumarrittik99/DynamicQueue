#include<iostream>
using namespace std;
class QueueInfo
{
	public:
	int capacity;
	int rearIndex;
	int frontIndex;
	int *queue;
};
QueueInfo *queuePointer=NULL;
QueueInfo* createQueue(int cap)
{
	QueueInfo *temp=new QueueInfo;
	temp->capacity=cap;
	temp->rearIndex=-1;
	temp->frontIndex=0;
	temp->queue=new int[temp->capacity];
	return temp;
}
bool isFull(QueueInfo *p)
{
	if(p->rearIndex==p->capacity-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool isEmpty(QueueInfo *p)
{
	if(p->rearIndex==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void insert(QueueInfo *p)
{
	if(isFull(queuePointer))
	{
		cout<<"Queue is full!!\n";
	}
	else
	{
		int element;
		cout<<"Enter an element.\n";
		cin>>element;
		p->rearIndex++;
		p->queue[p->rearIndex]=element;
	}
}
void extract(QueueInfo *p)
{
	if(isEmpty(queuePointer))
	{
		cout<<"Queue is empty!!\n";
	}
	else
	{
		int element;
		element=p->queue[p->frontIndex];
		cout<<element<<" is deleted from the queue!!\n";
		for(int i=0;i<=p->rearIndex;i++)
		{
			p->queue[i]=p->queue[i+1];
		}
		p->rearIndex--;
	}
}
void traverse(QueueInfo *p)
{
	if(isEmpty(queuePointer))
	{
		cout<<"Queue is empty!!\n";
	}
	else
	{
		for(int i=0;i<=p->rearIndex;i++)
		{
			cout<<p->queue[i]<<endl;
		}
	}
}
int main()
{
	int choice,capacity;
	cout<<"Enter the capacity of the queue.\n";
	cin>>capacity;
	queuePointer=createQueue(capacity);
	cout<<"1 Insert an element in the queue.\n";
	cout<<"2 Delete an element from the queue.\n";
	cout<<"3 Traverse all the elements.\n";
	cout<<"4 Exit.\n";
	while(true)
	{
		cout<<"Enter your choice.\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				insert(queuePointer);
				break;
			case 2:
				extract(queuePointer);
				break;
			case 3:
				traverse(queuePointer);
				break;
			case 4:
				exit(false);
				break;
			default:
				cout<<"Invalid Choice!!!\n";
				break;
		}
	}
	return 0;
}
