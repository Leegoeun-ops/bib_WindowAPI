#pragma once
#include "..\\Win_SOURCE\\bibResources.h"
#include "..\\Win_SOURCE\\bibTexture.h"

namespace bib
{
	//void LoadResources();
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Map", L"D:\\GitHub\\Test\\Window_Editor\\Window_Test\\map\\map_pure.png");
		Resources::Load<graphics::Texture>(L"PackMan", L"D:\\GitHub\\Test\\Window_Editor\\Window_Test\\pacman\\0.png");
	}
}
