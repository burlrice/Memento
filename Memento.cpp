#include "pch.h"

#include <string>
#include <map>
#include <functional>

#include "Memento.h"

using namespace System;

using namespace Pertinax;

Memento::Memento(SByte% rhs)
{
	throw gcnew System::NotImplementedException();
}

Memento::Memento(Byte% rhs)
{
	throw gcnew System::NotImplementedException();
}

Memento::Memento(Int16% rhs)
{
	throw gcnew System::NotImplementedException();
}

Memento::Memento(UInt16% rhs)
{
	throw gcnew System::NotImplementedException();
}

Memento::Memento(Int32% rhs)
{
	// TODO: rem // pin_ptr<Int32> pin = &rhs;
	// TODO: rem // void* ptr = pin;
	// TODO: rem // 
	// TODO: rem // ref = ptr;

	pin_ptr<Int32> pin = &rhs;

	ref = (void*)pin;
	int32Value = rhs;
}

Memento::Memento(UInt32% rhs)
{
	throw gcnew System::NotImplementedException();
}

Memento::Memento(Int64% rhs)
{
	throw gcnew System::NotImplementedException();
}

Memento::Memento(UInt64% rhs)
{
	throw gcnew System::NotImplementedException();
}

Memento::Memento(Char% rhs)
{
	throw gcnew System::NotImplementedException();
}

Memento::Memento(Single% rhs)
{
	throw gcnew System::NotImplementedException();
}

Memento::Memento(Double% rhs)
{
	throw gcnew System::NotImplementedException();
}

Memento::Memento(Boolean% rhs)
{
	throw gcnew System::NotImplementedException();
}

Memento::Memento(Decimal% rhs)
{
	throw gcnew System::NotImplementedException();
}

Memento::~Memento()
{
	this->!Memento();
}

Memento::!Memento()
{
	int* p = (int*)ref;

	*p = int32Value;
}

void Memento::Set(Int32 rhs)
{
	int* p = (int*)ref;

	*p = rhs;
}

void Memento::Set(Boolean rhs)
{
}

void Memento::Get(Int32% result)
{
	// TODO: rem // int* p = (int*)ref;
	// TODO: rem // 
	// TODO: rem // result = *p;

	result = *((int*)ref);
}