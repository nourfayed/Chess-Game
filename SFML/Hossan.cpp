#pragma once
#include "PositionStruct.h"
#include "Pieces.h"
#include "Hossan.h"
#include <vector>
using namespace std;

Hossan::Hossan(Position CurP) :Pieces(CurP){};

void Hossan::Route(Position CurPosition)
{
	Position Cells;
	AvailableMoves.clear();
	if ((CurPosition.X - 2) >= 0 && (CurPosition.Y - 1) >= 0)
	{
		Cells.X = CurPosition.X - 2;
		Cells.Y = CurPosition.Y - 1;
		AvailableMoves.push_back(Cells);

		Cells.X = -1, Cells.Y = -1;
		AvailableMoves.push_back(Cells);
	}

	if ((CurPosition.X - 2) >= 0 && (CurPosition.Y + 1) < 8)
	{
		Cells.X = CurPosition.X - 2;
		Cells.Y = CurPosition.Y + 1;
		AvailableMoves.push_back(Cells);
		Cells.X = -1, Cells.Y = -1;
		AvailableMoves.push_back(Cells);
	}
	if ((CurPosition.X - 1) >= 0 && (CurPosition.Y - 2) >= 0)
	{
		Cells.X = CurPosition.X - 1;
		Cells.Y = CurPosition.Y - 2;
		AvailableMoves.push_back(Cells);

		Cells.X = -1, Cells.Y = -1;
		AvailableMoves.push_back(Cells);
	}


	if ((CurPosition.X + 1) < 8 && (CurPosition.Y - 2) >= 0)
	{

		Cells.X = CurPosition.X + 1;
		Cells.Y = CurPosition.Y - 2;
		AvailableMoves.push_back(Cells);
		Cells.X = -1, Cells.Y = -1;
		AvailableMoves.push_back(Cells);
	}


	if ((CurPosition.X + 2) < 8 && (CurPosition.Y - 1) >= 0)
	{
		Cells.X = CurPosition.X + 2;
		Cells.Y = CurPosition.Y - 1;
		AvailableMoves.push_back(Cells);
		Cells.X = -1, Cells.Y = -1;
		AvailableMoves.push_back(Cells);
	}


	if ((CurPosition.X + 2) < 8 && (CurPosition.Y + 1) < 8)
	{
		Cells.X = CurPosition.X + 2;
		Cells.Y = CurPosition.Y + 1;
		AvailableMoves.push_back(Cells);

		Cells.X = -1, Cells.Y = -1;
		AvailableMoves.push_back(Cells);
	}

	if ((CurPosition.X + 1) < 8 && (CurPosition.Y + 2) < 8)
	{
		Cells.X = CurPosition.X + 1;
		Cells.Y = CurPosition.Y + 2;
		AvailableMoves.push_back(Cells);

		Cells.X = -1, Cells.Y = -1;
		AvailableMoves.push_back(Cells);
	}
	if ((CurPosition.X - 1) >= 0 && (CurPosition.Y + 2) < 8)
	{
		Cells.X = CurPosition.X - 1;
		Cells.Y = CurPosition.Y + 2;
		AvailableMoves.push_back(Cells);
		Cells.X = -1, Cells.Y = -1;
		AvailableMoves.push_back(Cells);
	}

}