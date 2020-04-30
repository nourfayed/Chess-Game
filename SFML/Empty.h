#pragma once
#include "Pieces.h"
class Empty :
	public Pieces
{
public:
	Empty(Position);
	virtual void Route(Position);
};

