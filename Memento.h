#pragma once

using namespace System;

namespace Pertinax
{
	public ref class Memento : IDisposable
	{
	public:
		Memento(SByte% rhs);
		Memento(Byte% rhs);
		Memento(Int16% rhs);
		Memento(UInt16% rhs);
		Memento(Int32% rhs);
		Memento(UInt32% rhs);
		Memento(Int64% rhs);
		Memento(UInt64% rhs);
		Memento(Char% rhs);
		Memento(Single% rhs);
		Memento(Double% rhs);
		Memento(Boolean% rhs);
		Memento(Decimal% rhs);

		virtual ~Memento();

		void Get(SByte% result);
		void Get(Byte% result);
		void Get(Int16% result);
		void Get(UInt16% result);
		void Get(Int32% result);
		void Get(UInt32% result);
		void Get(Int64% result);
		void Get(UInt64% result);
		void Get(Char% result);
		void Get(Single% result);
		void Get(Double% result);
		void Get(Boolean% result);
		void Get(Decimal% result);

		void Set(SByte rhs);
		void Set(Byte rhs);
		void Set(Int16 rhs);
		void Set(UInt16 rhs);
		void Set(Int32 rhs);
		void Set(UInt32 rhs);
		void Set(Int64 rhs);
		void Set(UInt64 rhs);
		void Set(Char rhs);
		void Set(Single rhs);
		void Set(Double rhs);
		void Set(Boolean rhs);
		void Set(Decimal rhs);

	private:
		!Memento();

		void* ref;

		SByte sbyteValue;
		Byte byteValue;
		Int16 int16Value;
		UInt16 uint16Value;
		Int32 int32Value;
		UInt32 uint32Value;
		Int64 int64Value;
		UInt64 uint64Value;
		Char charValue;
		Single singleValue;
		Double doubleValue;
		Boolean booleanValue;
		Decimal decimalValue;
	};
}
