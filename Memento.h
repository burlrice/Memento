#pragma once

using namespace System;

namespace Pertinax
{
	public ref class Memento : IDisposable
	{
	public:
		Memento(Int32% rhs);
		virtual ~Memento();

		void Set(Int32 rhs);
		void Set(Boolean rhs);

		void Get(Int32% result);

	private:
		!Memento();

		void* ref;
		Int32 int32Value;
	};
}
