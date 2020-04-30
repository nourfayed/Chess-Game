#pragma once
#include "PositionStruct.h"
#include "Pieces.h"
#include "Feel.h"
#include <vector>

Feel::Feel(Position CurP) : Pieces(CurP){};

void Feel::Route(Position CurPosition)
{

	Position Cells;
	AvailableMoves.clear();
	int JPositive = (CurPosition.Y + 1), JNegative = (CurPosition.Y - 1);
	for (int i = (CurPosition.X + 1); i < 8; i++)
	{
		Cells.X = i;
		if (JPositive < 8)
		{
			Cells.Y = JPositive;
			AvailableMoves.push_back(Cells);
			JPositive++;
		}
	}

	Cells.X = -1, Cells.Y = -1;
	AvailableMoves.push_back(Cells);

	for (int i = (CurPosition.X + 1); i < 8; i++)
	{
		Cells.X = i;

		if (JNegative >= 0)
		{
			Cells.Y = JNegative;
			AvailableMoves.push_back(Cells);
			JNegative--;
		}
	}

	Cells.X = -1, Cells.Y = -1;
	AvailableMoves.push_back(Cells);

	JPositive = (CurPosition.Y + 1), JNegative = (CurPosition.Y - 1);
	for (int i = (CurPosition.X - 1); i >= 0; i--)
	{
		Cells.X = i;
		if (JPositive < 8)
		{
			Cells.Y = JPositive;
			AvailableMoves.push_back(Cells);
			JPositive++;
		}
	}
	Cells.X = -1, Cells.Y = -1;
	AvailableMoves.push_back(Cells);

	for (int i = (CurPosition.X - 1); i >= 0; i--)
	{
		Cells.X = i;

		if (JNegative >= 0)
		{
			Cells.Y = JNegative;
			AvailableMoves.push_back(Cells);
			JNegative--;
		}
	}
}