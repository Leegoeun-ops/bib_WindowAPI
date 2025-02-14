#pragma once
#include "bibEntity.h"

namespace bib
{
	class Resource abstract : public Entity // 추상 클래스 메모리 할당 X 상속받아서만 사용해야한다.
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0; // 순수가상함수 실제메모리 할당이 불가능해지는 문법이다.

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}


