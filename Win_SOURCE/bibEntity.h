#pragma once
#include "CommonInclude.h"

namespace bib {
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();
		void SetName(const std::wstring& sceneName) { mSceneName = sceneName; }
		std::wstring GetName() const { return mSceneName; }
	private:
		std::wstring mSceneName;
	};

}

