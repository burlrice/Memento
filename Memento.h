#pragma once

using namespace System;

namespace Pertinax
{
	generic <class T>
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
