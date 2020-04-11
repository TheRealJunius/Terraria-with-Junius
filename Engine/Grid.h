#pragma once

#include "Graphics.h"
#include "Block.h"

class Grid
{
public:
	//Variables
	static constexpr int nCells = 100;
	static constexpr int cellWidth = Graphics::ScreenWidth / nCells;
	static constexpr int cellHeight = Graphics::ScreenHeight / nCells;

	Block blocks[nCells * nCells];
public:
	//Functions
	Grid()
	{
		for (int j = 0; j < nCells; j++)
		{
			for (int i = 0; i < nCells; i++)
			{
				blocks[GetId(i, j)].Constructor(i, j, Block::Type::Stone);
			}
		}
	}
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
	void DrawCell(Graphics& gfx, int x, int y, Block::Type type)
	{
		switch (type)
		{
		case Block::Type::Air:
		{
			DrawCell(gfx, x, y, 230, 255, 255);
			break;
		}
		case Block::Type::Dirt:
		{
			DrawCell(gfx, x, y, 191, 128, 64);
			break;
		}
		case Block::Type::Grass:
		{
			DrawCell(gfx, x, y, 0, 102, 34);
			break;
		}
		case Block::Type::Stone:
		{
			DrawCell(gfx, x, y, 163, 163, 117);
			break;
		}
		}
	}
	void DrawBlocks(Graphics& gfx)
	{
		for (int j = 0; j < nCells; j++)
		{
			for (int i = 0; i < nCells; i++)
			{
				DrawCell(gfx, i, j, blocks[GetId(i, j)].type);
			}
		}
	}
private:
	//Variables
private:
	//Functions
	int GetPosX(int id)
	{
		return id - int(id / nCells);
	}
	int GetPosY(int id)
	{
		return int(id / nCells);
	}
	int GetId(int x, int y)
	{
		return y * nCells + x;
	}
};