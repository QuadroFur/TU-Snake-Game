#pragma once

template <typename T>
class ListNode
{
public:
	T Data;
	ListNode* Next;

	ListNode() {
		Data;
		Next;
	}
	ListNode(T Obj) {
		Data = Obj;
		Next;
	}
	ListNode(T Obj, ListNode<T>* NextNode) {
		Data = Obj;
		Next = NextNode;
	}
};

template <typename T>
class LinkedList
{
private:

	ListNode<T> Head;

public:

	LinkedList() { Head; };

	LinkedList(T Obj[]) {
		for (int i = sizeof(Obj); i >= 0; i--)
		{
			Head = new ListNode<T>(Obj[i], Head);
		}
	};

	T front() { return Head.Data; };
	void PushBack(T Obj);
	void PushFront(T Obj);
	void PopBack();
	T GetAt(int Pos);
	int Size();

};