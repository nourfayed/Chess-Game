#pragma once
#include "PositionStruct.h"
#include "Pieces.h"
#include "Wazer.h"
#include <vector>

Wazer::Wazer(Position CurP) : Pieces(CurP){};

void Wazer::Route(Position CurPosition)
{
	//Route El Tabia
	Position Cells;
	AvailableMoves.clear();
	for (int i = (CurPosition.X - 1); i >= 0; i--)
	{
		Cells.X = i;
		Cells.Y = CurPosition.Y;
		AvailableMoves.push_back(Cells);
	}
	Cells.X = -1, Cells.Y = -1;
	AvailableMoves.push_back(Cells);

	for (int i = (CurPosition.X + 1); i < 8; i++)
	{
		Cells.X = i;
		Cells.Y = CurPosition.Y;
		AvailableMoves.push_back(Cells);
	}
	Cells.X = -1, Cells.Y = -1;
	AvailableMoves.push_back(Cells);

	for (int j = (CurPosition.Y - 1); j >= 0; j--)
	{
		Cells.X = CurPosition.X;
		Cells.Y = j;
		AvailableMoves.push_back(Cells);
	}
	Cells.X = -1, Cells.Y = -1;
	AvailableMoves.push_back(Cells);

	for (int j = (CurPosition.Y + 1); j < 8; j++)
	{
		Cells.X = CurPosition.X;
		Cells.Y = j;
		AvailableMoves.push_back(Cells);
	}
	Cells.X = -1, Cells.Y = -1;
	AvailableMoves.push_back(Cells);

	//Feel Route

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