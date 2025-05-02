#pragma once

template <typename T>
class ListNode
{
public:
	T Data;
	ListNode<T>* Next = nullptr;

	ListNode(T Obj) {
		Data = Obj;
		Next = nullptr;
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

	ListNode<T>* Head = nullptr;

public:

	LinkedList(T Obj[]) {
		for (int i = sizeof(Obj); i >= 0; i--)
		{
			Head = new ListNode<T>(Obj[i], Head);
		}
	};
	LinkedList() {}

	T front() { return Head->Data; };

	void PushBack(T Obj)
	{
		if (Head != nullptr) 
		{
			ListNode<T>* Node = Head;
			ListNode<T>* NextNode = Node->Next;
			while (NextNode != nullptr)
			{
				Node = Node->Next;
				NextNode = Node->Next;
			}
			ListNode<T>* NewNode = new ListNode<T>(Obj);
			Node->Next = NewNode;
		}
		else
		{
			ListNode<T>* Node = new ListNode<T>(Obj);
			Head = Node;
		}
	}
	void PushFront(T Obj)
	{
		ListNode<T>* Node = new ListNode<T>(Obj);
		if (Head == nullptr)
		{
			Head = Node;
		}
		else
		{
			Node->Next = Head;
			Head = Node;
		}
	}
	void PopBack()
	{
		if (Head != nullptr)
		{
			ListNode<T>* NextNode = Head->Next;
			ListNode<T>* Node = Head;
			ListNode<T>* PrevNode = Head;
			while (NextNode != nullptr)
			{
				PrevNode = Node;
				Node = NextNode;
				NextNode = Node->Next;
			}
			PrevNode->Next = nullptr;
		}
	}
	int Size()
	{
		ListNode<T>* Node = Head;
		int Count = 0;
		while (Node != nullptr)
		{
			Count++;
			Node = Node->Next;
		}
		return Count;
	}
	T GetAt(int Pos)
	{
		int Count = 0;
		ListNode<T>* Node = Head;
		while (Count != Pos && Node != nullptr)
		{
			Count++;
			Node = Node->Next;
		}
		if (Node == nullptr) return T();
		return Node->Data;
	}
	void PopFront()
	{
		ListNode<T>* Node = Head;
		if (Node != nullptr && Node->Next != nullptr)
			Head = Node->Next;
		else
			Head = nullptr;
		Node = nullptr;
	}
};