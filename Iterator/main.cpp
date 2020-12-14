#include <iostream>

typedef struct _Node {
	int data;
	_Node * next;
}Node;


// 一般情况下创建的链表类会定义对链表的操作函数，使用迭代器后就可以把这些工作交给迭代器做
// 这样就可以将数据操作与数据存储进行解耦合
class MyList {
public:
	MyList() :m_pHead(NULL), m_pTail(NULL) {}
	MyList(const MyList & ele);
	~MyList();
	MyList &operator=(const MyList& ele);

	long GetCount() const;
	Node* Get(const long index) const;
	Node* First() const;
	Node* Last() const;

	bool Includes(const int &value);
	void Append(const int &value);
	void Remove(Node* pNode);
	void RemoveAll();
private:
	Node* m_pHead;
	Node* m_pTail;
	long m_lCount;
};

MyList::~MyList() {
	Node* pCurrent = m_pHead;
	Node* pNextNode = NULL;
	while (pCurrent) {
		pNextNode = pCurrent->next;
		delete pCurrent;
		pCurrent = NULL;
	}
}


MyList::MyList(const MyList & ele) {

}

MyList& MyList::operator=(const MyList& ele) {

	// add your code
	return MyList();
}

long MyList::GetCount() const {
	return m_lCount;
}

Node* MyList::Get(const long index) const {
	if (index > m_lCount - 1 || index < 0) {
		return NULL;
	}
	long lPosIndex = 0;
	Node * pNodeTemp = m_pHead;
	while (pNodeTemp)
	{
		if (index == lPosIndex) {
			return pNodeTemp;
		}
		pNodeTemp = pNodeTemp->next;
		lPosIndex++;
	}
	return NULL;
}

Node* MyList::First() const {
	return m_pHead;
}

Node* MyList::Last() const {
	return m_pTail;
}

bool MyList::Includes(const int &value) {
	Node *pNodeTemp = m_pHead;
	while (pNodeTemp)
	{
		if (value == pNodeTemp->data) {
			return true;
		}
		pNodeTemp = pNodeTemp->next;
	}
	return false;
}

void MyList::Append(const int &value) {
	Node* pInsertNode = new Node;
	pInsertNode->data = value;
	pInsertNode->next = NULL;

	if (m_pHead == NULL) {
		m_pHead = m_pTail = pInsertNode;
	}
	else
	{
		m_pTail->next = pInsertNode;
		m_pTail = pInsertNode;
	}
	++m_lCount;
}

void MyList::Remove(Node* pNode) {
	if (pNode == NULL || m_pHead == NULL || m_pTail == NULL) {
		return;
	}
	
	if (pNode == m_pHead) {
		Node *pNewHead = m_pHead->next;
		m_pHead = pNewHead;
	}
	else
	{
		Node* pPreviousNode = NULL;
		Node* pCurrentNode = m_pHead;
		while (pCurrentNode) {
			pPreviousNode = pCurrentNode;
			pCurrentNode = pCurrentNode->next;
			if (pCurrentNode == pNode) {
				break;
			}
		}

		Node* pNextNode = pNode->next;

		if (pNextNode == NULL) {
			m_pTail = pPreviousNode;
		}
		pPreviousNode->next = pNextNode;
	}

	delete pNode;
	pNode = NULL;
	--m_lCount;
}

void MyList::RemoveAll() {
	
	// add your code
	delete this;
}

class Iterator {
public:
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() const = 0;
	virtual Node* CurrentItem() const = 0;
};

class ListIterator :public Iterator {
public:
	ListIterator(MyList * pList) :m_pMyList(pList),m_pCurrent(NULL){}
	virtual void First();
	virtual void Next();
	virtual bool IsDone() const;
	virtual Node* CurrentItem() const;

private:
	MyList *m_pMyList;
	Node *m_pCurrent;
};

void ListIterator::First() {
	m_pCurrent = m_pMyList->First();
}

void ListIterator::Next() {
	m_pCurrent = m_pCurrent->next;
}

bool ListIterator::IsDone() const {
	return m_pCurrent == m_pMyList->Last()->next;
}

Node* ListIterator::CurrentItem() const {
	return m_pCurrent;
}
int main()
{
	MyList* my_list = new MyList();
	my_list->Append(1);
	my_list->Append(2);
	my_list->Append(3);
	my_list->Append(4);
	my_list->Append(5);
	my_list->Append(6);
	my_list->Append(7);
	my_list->Append(8);
	my_list->Append(9);

	Iterator* it = new ListIterator(my_list);

	for (it->First(); !it->IsDone(); it->Next())
	{
		std::cout << it->CurrentItem()->data << std::endl;
	}

	system("pause");

	return 0;
}