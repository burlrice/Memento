#include "pch.h"

#include <string>
#include <map>
#include <functional>

#include "Memento.h"

using namespace System;

using namespace Pertinax;

generic <class T>
Memento<T>::Memento(T% rhs)
{
	pin_ptr<T> pin = &rhs;

	ref = (void*)pin;
	value = rhs;
}

generic <class T>
Memento<T>::~Memento()
{
	this->!Memento();
}

generic <class T>
Memento<T>::!Memento()
{
	if (T::typeid == Int32::typeid)
	{
		*((int*)ref) = (int)value;
	}
}

generic <class T>
void Memento<T>::Get(T% result)
{
	if (T::typeid == Int32::typeid)
	{
		result = (T)*((int*)ref);
	}
}

generic <class T>
void Memento<T>::Set(T rhs)
{
	if (T::typeid == Int32::typeid)
	{
		*((int*)ref) = (int)rhs;
	}
}
