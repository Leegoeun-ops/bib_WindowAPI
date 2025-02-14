#pragma once
#include "..\\Win_SOURCE\\bibResources.h"
#include "..\\Win_SOURCE\\bibTexture.h"

namespace bib
{
	//void LoadResources();
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"BG", L"D:\\GitHub\\Test\\Window_Editor\\Window_Test\\CloudOcean.png");
	}
}
