/*
*	C++11 and higher
*	Successfully compiles using:
*		- clang 7.0.0
*		- gcc 8.2
*		- msvc v1916
*
*	This is the example of explicit template instantiation ignoring access specifiers.
*	USE AT YOUR OWN DISCRETION
*/

#include <iostream>

template <class T>
struct IgnoreAccess
{
	static typename T::member Get;
};

template <class T>
typename T::member IgnoreAccess<T>::Get;

template <class T, typename T::member value>
struct InitAccess
{
	InitAccess()
	{
		IgnoreAccess<T>::Get = value;
	}
	static InitAccess instance;
};

template <class T, typename T::member value>
InitAccess<T, value> InitAccess<T, value>::instance;

class A
{
	int Secret;

public:

	A() : Secret(0) {}
	A(int InSecret) : Secret(InSecret) {}

	void print()
	{
		std::cout << "A's secret: " << Secret << '\n';
	}
};

struct A_Secret { using member = int A::*; };
template struct InitAccess<A_Secret, &A::Secret>;

int main()
{
	A a(198);
	a.print();

	int &PrivateMember = a.*IgnoreAccess<A_Secret>::Get;
	std::cout << "Ignore access: " << PrivateMember << '\n';

	PrivateMember = 3898;
	a.print();

	return 0;
}