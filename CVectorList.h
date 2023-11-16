#pragma once
#include <iostream>
using std::cout;
class CVector1
{
private:
	double x1;
public:
	CVector1() { x1 = 0; }
	CVector1(double x1_) { x1 = x1_; }

	virtual double getLength() { return fabs(x1); }

	double getX1() { return x1; }
	void setX1(double x1_) { x1 = x1_; }

	~CVector1() { };
};

class CVector2 : public CVector1
{
private:
	double x2;
public:
	CVector2() { x2 = 0; }
	CVector2(double x1_, double x2_) : CVector1(x1_) { x2 = x2_; }

	virtual double getLength() override { return sqrt(getX1() * getX1() + x2 * x2); }

	double getX2() { return x2; };
	void setX2(double x2_) { x2 = x2_; }

	~CVector2() { };
};

class Node
{
private:
	CVector1* vect;
	Node* next;
public:
	Node() { vect = NULL; next = nullptr; }
	Node(CVector1* vect_, Node* next_) { vect = vect_; next = next_; }

	CVector1* getVect() { return vect; }
	void setVect(CVector1* vect_) { vect = vect_; }
	Node* getNext() { return next; }
	void setNext(Node* next_) { next = next_; }

	~Node() { cout << "\nnode destructor\n" << vect->getX1() << '\t' << ((CVector2*)vect)->getX2(); };
};

class CVectorList
{
private:
	Node* begin;
	Node* tail;
public:
	CVectorList() { begin = nullptr; tail = nullptr; }
	CVectorList(Node* begin_, Node* tail_) { begin = begin_; tail = tail_; }

	void Add(CVector1* vect_)
	{
		Node* n = new Node(vect_, nullptr);
		if (begin == nullptr)
		{
			begin = n;
			tail = n;
		}
		else
		{
			tail->setNext(n);
			tail = n;
		}
	}
	void Print()
	{
		if (begin == nullptr)
		{
			return;
		}
		Node* buff = begin;
		while (buff != nullptr)
		{
			cout << '\n' << buff->getVect()->getLength();
			buff = buff->getNext();
		}
	}

	Node* getBegin() { return begin; }
	void setBegin(Node* begin_) { begin = begin_; }
	Node* getTail() { return tail; }
	void setTail(Node* tail_) { tail = tail_; }

	~CVectorList()
	{
		cout << "\nlist destuctor";
		if (begin == nullptr)
		{
			return;
		}
		Node* buff = begin;
		Node* next = begin->getNext();
		do
		{
			delete buff;
			buff = next;
			next = next->getNext();
		} while (next != nullptr);
		delete buff;
	}
};