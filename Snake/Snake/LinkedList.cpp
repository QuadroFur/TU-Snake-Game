#include "LinkedList.h"

template <typename T>
void LinkedList<T>::PushBack(T Obj)
{
	ListNode Node = Head;
	ListNode NextNode = Node.Next;
	while (NextNode != nullptr)
	{
		Node = Node.Next;
		NextNode = Node.Next;
	}
	ListNode NewNode = new ListNode<T>(Obj);
	Node.Next = NewNode;
}
template <typename T>
void LinkedList<T>::PushFront(T Obj)
{
	ListNode<T> Node = new ListNode<T>(Obj);
	if (Head == nullptr)
	{
		Head = Node;
	}
	else
	{
		Node.Next = Head;
		Head = Node;
	}
}
template <typename T>
void LinkedList<T>::PopBack()
{
	ListNode NextNode = Head.Next;
	ListNode Node = Head;
	while (NextNode != nullptr)
	{
		Node = NextNode;
		NextNode = Node.Next;
	}
	if (Node)
	{
		Node == nullptr;
	}
}
template <typename T>
int LinkedList<T>::Size()
{
	ListNode Node = Head;
	int Count = 0;
	while (Node != nullptr)
	{
		Count++;
		Node = Node.Next;
	}
	return Count;
}
template <typename T>
T LinkedList<T>::GetAt(int Pos)
{
	int Count = 0;
	ListNode Node = Head;
	while (Count != Pos && Node != nullptr)
	{
		Count++;
		Node = Node.Next;
	}
	if (Node == nullptr) return nullptr;
	return Node;
}