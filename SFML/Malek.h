#pragma once
#include "Pieces.h"
#include "PositionStruct.h"

class Malek :
	public Pieces
{
public:
	Malek(Position);

	virtual void Route(Position);

};

