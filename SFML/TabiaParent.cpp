#pragma once
#include "Pieces.h"
#include <vector>
#include "TabiaParent.h"
#include "PositionStruct.h"
using namespace std;


TabiaParent::TabiaParent(Position CurP) : Pieces(CurP){};

void TabiaParent::Route(Position CurPosition)
{
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
}
