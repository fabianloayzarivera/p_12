// 10_Practica10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TList.h"

TList GetReverseList(TList lstSrc);
int main()
{
	TList List;

	List.Push("Hello");
	List.Push("World");
	List.Push("My");
	List.Push("Name");
	List.Push("Is");
	List.Push("Fabian");

	cout << "List Size: " << List.Size() << endl;
	cout << "List First: " << List.First() << endl;
	cout << "Printing list using next() " << endl;
	cout << List.Next() << endl;
	cout << List.Next() << endl;
	cout << List.Next() << endl;
	cout << List.Next() << endl;
	cout << List.Next() << endl;
	cout << List.Next() << endl;

	TList List2 = List;

	cout << "Printing Copied list using next() " << endl;
	cout << List2.Next() << endl;
	cout << List2.Next() << endl;
	cout << List2.Next() << endl;
	cout << List2.Next() << endl;
	cout << List2.Next() << endl;
	cout << List2.Next() << endl;

	TList List3 = GetReverseList(List);

	cout << "Printing Reversed list using next() " << endl;
	cout << List3.Next() << endl;
	cout << List3.Next() << endl;
	cout << List3.Next() << endl;
	cout << List3.Next() << endl;
	cout << List3.Next() << endl;
	cout << List3.Next() << endl;

	getchar();

	return 0;
}

TList GetReverseList(TList lstSrc) {
	TList revList;
	int size = lstSrc.Size() - 1;
	Node *actual = lstSrc.getFirst();
	while (size > 0) {
		revList.Push(lstSrc.getLast()->getValue());
		while (actual->getNextPtr() != lstSrc.getLast()) {
			actual = actual->getNextPtr();
		}
		lstSrc.setLast(actual);
		actual = lstSrc.getFirst();
		size--;
	}
	revList.Push(actual->getValue());
	return revList;

}
