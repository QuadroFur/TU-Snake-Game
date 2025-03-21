#pragma once

template <typename T>
class ListNode
{
public:
	T Data;
	ListNode* Next;

	ListNode() {
		Data = nullptr;
		Next = nullptr;
	}
	ListNode(T Obj) {
		Data = Obj;
		Next = nullptr;
	}
	ListNode(T Obj, ListNode* NextNode) {
		Data = Obj;
		Next = NextNode;
	}
};

template <typename T>
class LinkedList
{

public:

	ListNode<T> front;

	LinkedList() { front = nullptr; }

	LinkedList(T Obj) {
		for (int i = sizeof(Obj); i >= 0; i--)
		{
			front = ListNode<T> NewNode(Obj, front);
		}
	}
};