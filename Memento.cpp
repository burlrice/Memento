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
	if (T::typeid == SByte::typeid)			*((signed char*)ref) = (signed char)value;
	else if (T::typeid == Byte::typeid)		*((unsigned char*)ref) = (unsigned char)value;
	else if (T::typeid == Int16::typeid)	*((short*)ref) = (short)value;
	else if (T::typeid == UInt16::typeid)	*((unsigned short*)ref) = (unsigned short)value;
	else if (T::typeid == Int32::typeid)	*((int*)ref) = (int)value;
	else if (T::typeid == UInt32::typeid)	*((unsigned int*)ref) = (unsigned int)value;
	else if (T::typeid == Int64::typeid)	*((__int64*)ref) = (__int64)value;
	else if (T::typeid == UInt64::typeid)	*((unsigned __int64*)ref) = (unsigned __int64)value;
	else if (T::typeid == Char::typeid)		*((wchar_t*)ref) = (wchar_t)value;
	else if (T::typeid == Single::typeid)	*((float*)ref) = (float)value;
	else if (T::typeid == Double::typeid)	*((double*)ref) = (double)value;
	else if (T::typeid == Boolean::typeid)	*((bool*)ref) = (bool)value;
	else if (T::typeid == Decimal::typeid)	*((Decimal*)ref) = (Decimal)value;
}

generic <class T>
void Memento<T>::Get(T% result)
{
	if (T::typeid == SByte::typeid)			result = (T)*((signed char*)ref);
	else if (T::typeid == Byte::typeid)		result = (T)*((unsigned char*)ref);
	else if (T::typeid == Int16::typeid)	result = (T)*((short*)ref);
	else if (T::typeid == UInt16::typeid)	result = (T)*((unsigned short*)ref);
	else if (T::typeid == Int32::typeid)	result = (T)*((int*)ref);
	else if (T::typeid == UInt32::typeid)	result = (T)*((unsigned int*)ref);
	else if (T::typeid == Int64::typeid)	result = (T)*((__int64*)ref);
	else if (T::typeid == UInt64::typeid)	result = (T)*((unsigned __int64*)ref);
	else if (T::typeid == Char::typeid)		result = (T)*((wchar_t*)ref);
	else if (T::typeid == Single::typeid)	result = (T)*((float*)ref);
	else if (T::typeid == Double::typeid)	result = (T)*((double*)ref);
	else if (T::typeid == Boolean::typeid)	result = (T)*((bool*)ref);
	else if (T::typeid == Decimal::typeid)	result = (T)*((Decimal*)ref);
}

generic <class T>
void Memento<T>::Set(T rhs)
{
	if (T::typeid == SByte::typeid)			*((signed char*)ref) = (signed char)rhs;
	else if (T::typeid == Byte::typeid)		*((unsigned char*)ref) = (unsigned char)rhs;
	else if (T::typeid == Int16::typeid)	*((short*)ref) = (short)rhs;
	else if (T::typeid == UInt16::typeid)	*((unsigned short*)ref) = (unsigned short)rhs;
	else if (T::typeid == Int32::typeid)	*((int*)ref) = (int)rhs;
	else if (T::typeid == UInt32::typeid)	*((unsigned int*)ref) = (unsigned int)rhs;
	else if (T::typeid == Int64::typeid)	*((__int64*)ref) = (__int64)rhs;
	else if (T::typeid == UInt64::typeid)	*((unsigned __int64*)ref) = (unsigned __int64)rhs;
	else if (T::typeid == Char::typeid)		*((wchar_t*)ref) = (wchar_t)rhs;
	else if (T::typeid == Single::typeid)	*((float*)ref) = (float)rhs;
	else if (T::typeid == Double::typeid)	*((double*)ref) = (double)rhs;
	else if (T::typeid == Boolean::typeid)	*((bool*)ref) = (bool)rhs;
	else if (T::typeid == Decimal::typeid)	*((Decimal*)ref) = (Decimal)rhs;
}
