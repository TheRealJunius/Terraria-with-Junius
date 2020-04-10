#pragma once

#include "Graphics.h"

class Grid
{
private:
	static constexpr int nCells = 50;
	static constexpr int cellWidth = Graphics::ScreenWidth / nCells;
	static constexpr int cellHeight = Graphics::ScreenHeight / nCells;
public:
	void DrawCell(Graphics& gfx, int x, int y, int r, int g, int b)
	{
		for (int j = y * cellHeight; j < (y + 1) * cellHeight; j++)
		{
			for (int i = x * cellWidth; i < (x + 1) * cellWidth; i++)
			{
				gfx.PutPixel(i, j, r, g, b);
			}
		}
	}
};