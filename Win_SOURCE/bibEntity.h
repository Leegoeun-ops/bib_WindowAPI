#pragma once
#include "CommonInclude.h"

namespace bib {
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();
		void SetName(const std::wstring& Name) { mName = Name; }
		std::wstring GetName() const { return mName; }
	private:
		std::wstring mName;
	};

}

