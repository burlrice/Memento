#include "pch.h"

#include <string>
#include <map>
#include <functional>

#include "Memento.h"

using namespace System;

using namespace Pertinax;

Memento::Memento(Int32% rhs)
{
	pin_ptr<Int32> pin = &rhs;
	void* ptr = pin;

	ref = ptr;
	int32Value = rhs;
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

void Pertinax::Memento::Get(Int32% result)
{
	int* p = (int*)ref;

	result = *p;
}