#pragma once
#include "Pieces.h"
#include "PositionStruct.h"
#include <vector>
using namespace std;

class TabiaParent :
	public Pieces
{
public:

	TabiaParent(Position);

	virtual void Route(Position);

};

