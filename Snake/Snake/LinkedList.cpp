#include "LinkedList.h"

template <typename T>
void LinkedList<T>::PushBack(T Obj)
{
	ListNode Node = front;
	ListNode NextNode = Node.Next;
	while (NextNode != nullptr)
	{
		Node = Node.Next;
		NextNode = Node.Next;
	}
	ListNode NewNode = new ListNode(Obj);
	Node.Next = NewNode;
}