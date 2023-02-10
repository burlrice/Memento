#pragma once

using namespace System;

namespace Pertinax
{
	generic <class T>
	//where T : SByte, Byte, Int16, UInt16, Int32, UInt32, Int64, UInt64, Char, Single, Double, Boolean, Decimal
	public ref class Memento : IDisposable
	{
	public:
		Memento(T% rhs);
		virtual ~Memento();

		void Get(T% result);
		void Set(T rhs);

	private:
		!Memento();

		void* ref;
		T value;
	};
}
